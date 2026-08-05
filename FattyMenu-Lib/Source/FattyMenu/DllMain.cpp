//#include "Core/Hooks.h"
#include "Core/Application.h"

#include <../garrysmod_common/include/GarrysMod/Lua/Interface.h> // Garry's Mod module functions

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <thread>

bool g_application_running = true;

DWORD WINAPI SetupMainThread(LPVOID a_instance) {
	if (g_application_running) {
		try {
			FattyMenu::CApplication* app = new FattyMenu::CApplication();		// Init
			app->Run();															// Main loop
			delete app;															// Application ends
		}
		catch (const std::exception& ex) {
			MessageBox(nullptr, ex.what(), "Error", MB_ICONERROR);				// Display the error
			FreeLibraryAndExitThread(static_cast<HMODULE>(a_instance), 1);		// Exit 1
		}
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

/* Main function / dll entry point */
BOOL WINAPI DllMain(const HMODULE instance, const std::uintptr_t reason, const void* reserved) {

	switch (reason) {
		case DLL_PROCESS_ATTACH: {
			// Stop library calls in the process
			DisableThreadLibraryCalls(instance);

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
			break;
		}

	}
	return TRUE;
}