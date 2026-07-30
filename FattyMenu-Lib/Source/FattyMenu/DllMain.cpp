#include "Core/Hooks.h"

#include <../garrysmod_common/include/GarrysMod/Lua/Interface.h> // Garry's Mod module functions

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <thread>

DWORD WINAPI SetupMainThread(LPVOID a_instance) {
	try {
		// Initialize the GUI
		FattyMenu::GUI::Initialize();

		// Initialize all of the game render-hooks (EndScene/Reset)
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
	}
	catch (const std::exception& ex) {
		MessageBox(nullptr, ex.what(), "Error", MB_ICONERROR);				// Display the error
	}

	FreeLibraryAndExitThread(static_cast<HMODULE>(a_instance), 0);

	return 0;
}


// Entry point for GMOD
// Allows direct interfacing w/ GMOD's LUA API
GMOD_MODULE_OPEN() {
	
	return 0;
}

// GMOD's garbage collection method for when the module closes
GMOD_MODULE_CLOSE() {
	
	return 0;
}

/* Main function / dll entry point
* @param instance -> instance of the process
* @param reason -> determines why DllMain is being called
* @param reserved -> lp void pointer 
* @return -> TRUE or FALSE 
*/
BOOL WINAPI DllMain(const HMODULE instance, const std::uintptr_t reason, const void* reserved) {

	switch (reason) {
		case DLL_PROCESS_ATTACH: {
			// Stop library calls in the process
			DisableThreadLibraryCalls(instance);

			// Store the instance handle for manual unloading
			FattyMenu::GUI::g_module = instance;

			const HANDLE thread = CreateThread(
				nullptr,
				0,
				SetupMainThread,
				instance,			// Pass the instance parameter to setup
				0,
				nullptr
			);

			if (thread) {
				CloseHandle(thread); // Close the handle to prevent resource leaks
			}

			break;
		}

		case DLL_PROCESS_DETACH: {
			if (FattyMenu::GUI::g_setup_complete) {
				// Teardown hooks and GUI
				FattyMenu::Hooks::DestroyHooks();
				FattyMenu::GUI::Destroy();

				FattyMenu::GUI::g_setup_complete = false;
				FattyMenu::GUI::g_initialized = false;
			}
			break;
		}
			
	}
	

	return TRUE;
}
