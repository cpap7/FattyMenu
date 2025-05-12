#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <thread>
#include <cstdint>

#include "Hooks.h"

#include "../ext_dependencies/garrysmod_common/include/GarrysMod/Lua/Interface.h" // Garry's Mod module functions

DWORD WINAPI SetupMainThread(LPVOID instance) {
	try {
		// Initialize d3d9 device if manual map load method is used
		if (GUI::g_load_method == GUI::LoadMethod::ManualMap) {
			GUI::InitializeDevice();
		}

		// Initialize all game-hooks
		Hooks::InitializeHooks();

		// Find game window if Garry's Mod loaded the .dll file
		if (GUI::g_load_method == GUI::LoadMethod::GarrysModLoad) {
			if (!GUI::FindGameWindow()) {
				throw std::runtime_error("Could not find game window.");
			}
			GUI::HookWindowProc();
		}

		GUI::g_initialized = true;

		// Main loop
		while (!GetAsyncKeyState(VK_END)) {
			// Doesn't need use up crazy amount of resources to run, so we'll compromise here
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}

		// Cleanup
		Hooks::DestroyHooks();
		GUI::Destroy();

		// If it's injected, free library and exit thread as well
		if (GUI::g_load_method == GUI::LoadMethod::ManualMap) {
			FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
		}
	}
	catch (const std::exception& ex) {
		MessageBox(nullptr, ex.what(), "Error", MB_ICONERROR);	// Display the error
		if (GUI::g_load_method == GUI::LoadMethod::ManualMap) { // Cleanup
			FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
		}
	}
	return 0;
}

// Entry point for Garry's Mod directly loading binaries
GMOD_MODULE_OPEN() {
	// Check if it's not initialized
	if (!GUI::g_initialized) {
		GUI::g_load_method = GUI::LoadMethod::GarrysModLoad;	 // Set the load method
		GUI::g_module = nullptr;								 // Garry's Mod will handle the lifecycle for the menu, no FreeLibrary calls needed
		std::thread(SetupMainThread, nullptr).detach();		     // nullptr to indicate direct load by Garry's Mod
		//CreateThread(nullptr, 0, SetupMainThread, nullptr, 0, nullptr);
	}
	return 0;
}

// Garbage collection method for when the module closes
GMOD_MODULE_CLOSE() {
	// Check if it's initialized
	if (GUI::g_initialized) {
		// If true, tear down hooks and GUI
		Hooks::DestroyHooks();
		GUI::Destroy();
		GUI::g_initialized = false; 
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
		GUI::g_load_method = (reserved == nullptr) ? GUI::LoadMethod::ManualMap : GUI::LoadMethod::GarrysModLoad;

		// Store the instance handle for manual unloading
		GUI::g_module = instance;

		// Create the thread
		const HANDLE thread = CreateThread(
			nullptr,
			0,
			SetupMainThread,			// reinterpret_cast<LPTHREAD_START_ROUTINE>() OLD
			instance,					// Pass the instance parameter to Setup
			0,
			nullptr
		);

		// Check if the thread is not null
		if (thread) {
			// Close the handle to prevent resource leaks
			CloseHandle(thread);
		}
		
	}
	// Check if the reason was for detachment
	else if (reason == DLL_PROCESS_DETACH && GUI::g_initialized) {
		// Teardown hooks and GUI
		Hooks::DestroyHooks();
		GUI::Destroy();
		GUI::g_initialized = false;
	}

	return TRUE;
}
