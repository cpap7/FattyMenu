#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <thread>
#include <cstdint>
#include <atomic>

#include "Hooks.h"

#include <../garrysmod_common/include/GarrysMod/Lua/Interface.h> // Garry's Mod module functions

static std::atomic<bool> g_setup_claimed{ false };

DWORD WINAPI SetupMainThread(LPVOID a_instance) {
	try {
		// For Garry's Mod direct load, at startup there's a delay, so the game window will need to be found before hooking properly
		if (FattyMenu::GUI::g_load_method == FattyMenu::GUI::ELoadMethod::GarrysModLoad) {
			constexpr auto startup_delay = std::chrono::seconds(10);
			constexpr auto poll_interval = std::chrono::milliseconds(250);
			constexpr auto give_up_after = std::chrono::seconds(30); // Safety net

			std::this_thread::sleep_for(startup_delay);

			const auto deadline = std::chrono::steady_clock::now() + give_up_after;
			while (FattyMenu::GUI::FindGameWindow() == nullptr) {
				if (std::chrono::steady_clock::now() >= deadline) {
					throw std::runtime_error("Error: Could not load FattyMenu. Timed out while waiting for GMod's game window.");
				}
				//FattyMenu::GUI::HookWindowProc();

				std::this_thread::sleep_for(poll_interval);
			}
		}

		// Initialize null ref device 
		FattyMenu::GUI::InitializeDevice();


		// Initialize all game-hooks (EndScene/Reset) -> frees throwaway device after
		FattyMenu::Hooks::InitializeHooks();

		FattyMenu::GUI::g_setup_complete = true;

		// Main loop
		while (!GetAsyncKeyState(VK_END)) {
			// Sleep thread to save on resources
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}

		// Cleanup
		FattyMenu::Hooks::DestroyHooks();
		FattyMenu::GUI::Destroy();
		FattyMenu::GUI::g_setup_complete = false;
		g_setup_claimed.store(false); // Allow future reload


		// If it's injected, free library and exit thread as well
		if (FattyMenu::GUI::g_load_method == FattyMenu::GUI::ELoadMethod::ManualMap) {
			FreeLibraryAndExitThread(static_cast<HMODULE>(a_instance), 0);
		}
	}
	catch (const std::exception& ex) {
		MessageBox(nullptr, ex.what(), "Error", MB_ICONERROR);	// Display the error
		if (FattyMenu::GUI::g_load_method == FattyMenu::GUI::ELoadMethod::ManualMap) { // Cleanup
			FreeLibraryAndExitThread(static_cast<HMODULE>(a_instance), 0);
		}
	}
	return 0;
}

static bool TryClaimSetup() {
	bool expected = false;
	return g_setup_claimed.compare_exchange_strong(expected, true);
}

static DWORD WINAPI ManualMapEntry(LPVOID a_instance) {
	std::this_thread::sleep_for(std::chrono::seconds(2)); // Let GMod claim if this is a direct load

	if (TryClaimSetup()) {
		FattyMenu::GUI::g_load_method = FattyMenu::GUI::ELoadMethod::ManualMap;
		FattyMenu::GUI::g_module = static_cast<HMODULE>(a_instance);
		return SetupMainThread(a_instance);
	}
	return 0; // GMod already owns setup
}

// Entry point for Garry's Mod directly loading binaries
GMOD_MODULE_OPEN() {
	if (TryClaimSetup()) {
		FattyMenu::GUI::g_load_method	= FattyMenu::GUI::ELoadMethod::GarrysModLoad;	 // Set the load method
		FattyMenu::GUI::g_module		= nullptr;										 // Garry's Mod will handle the lifecycle for the menu, no FreeLibrary calls needed
		std::thread(SetupMainThread, nullptr).detach();									 
		//CreateThread(nullptr, 0, SetupMainThread, nullptr, 0, nullptr);
	}
	return 0;
}

// Garbage collection method for when the module closes
GMOD_MODULE_CLOSE() {
	if (FattyMenu::GUI::g_setup_complete) {
		FattyMenu::Hooks::DestroyHooks();
		FattyMenu::GUI::Destroy();

		FattyMenu::GUI::g_setup_complete	= false;
		FattyMenu::GUI::g_initialized		= false;

		g_setup_claimed.store(false); // Allow for future reloads
	}
	return 0;
}

/* Main function: dll entry point for manual map injection
* @param instance -> instance of the process
* @param reason -> determines why DllMain is being called
* @param reserved -> lp void pointer 
* @return -> TRUE or FALSE depending on the entry's success
*/
BOOL WINAPI DllMain(const HMODULE instance, const std::uintptr_t reason, const void* reserved) {
	// Check if the reason is specifically for manual map injection (not directly loading via Garry's Mod)
	if (reason == DLL_PROCESS_ATTACH) {
		// Stop library calls in the process
		DisableThreadLibraryCalls(instance);

		// Determine and store the load method
		FattyMenu::GUI::g_load_method = (reserved == nullptr) ? FattyMenu::GUI::ELoadMethod::ManualMap : FattyMenu::GUI::ELoadMethod::GarrysModLoad;

		// Store the instance handle for manual unloading
		FattyMenu::GUI::g_module = instance;

		// Create the thread for manual map
		if (FattyMenu::GUI::g_load_method == FattyMenu::GUI::ELoadMethod::ManualMap) {
			const HANDLE thread = CreateThread(
				nullptr,
				0,
				ManualMapEntry,
				instance,			// Pass the instance parameter to Setup
				0,
				nullptr
			);
			
			// Check if the thread is not null
			if (thread) {
				// Close the handle to prevent resource leaks
				CloseHandle(thread);
			}
		}
		
	}
	// Check if the reason was for detachment
	else if (reason == DLL_PROCESS_DETACH && FattyMenu::GUI::g_setup_complete) {
		// Teardown hooks and GUI
		FattyMenu::Hooks::DestroyHooks();
		FattyMenu::GUI::Destroy();

		FattyMenu::GUI::g_setup_complete	= false;
		FattyMenu::GUI::g_initialized		= false;
	}

	return TRUE;
}
