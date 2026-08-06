#include "Core/Application.h"
#include "Core/PlatformDetection.h"

#include <../garrysmod_common/include/GarrysMod/Lua/Interface.h>				// Garry's Mod module functions

bool g_application_running = true;												// Controlled via CApplication

DWORD WINAPI SetupMainThread(LPVOID a_instance) {
	if (g_application_running) {
		try { // NOTE: The only reason for the heap allocation here is to clearly define the app's lifetime
			FattyMenu::CApplication* app = new FattyMenu::CApplication();		// Init
			app->Run();															// Main loop
			delete app;															// Application ends
		}
		catch (const std::exception& ex) {
			MessageBox(nullptr, ex.what(), "Error", MB_ICONERROR);				// Display the error
			FreeLibraryAndExitThread(static_cast<HMODULE>(a_instance), 1);		// Exit code 1 (error)
		}
	}
	
	FreeLibraryAndExitThread(static_cast<HMODULE>(a_instance), 0);				// Exit code 0
	return 0;
}

// Entry point for GMOD
// Allows direct interfacing w/ GMOD's lua API with custom C++ code
GMOD_MODULE_OPEN() {
	return 0;
}

// GMOD garbage collection 
GMOD_MODULE_CLOSE() {
	return 0;
}

/* Main function / dll entry point */
BOOL WINAPI DllMain(const HMODULE a_instance, const std::uintptr_t a_reason, const void* a_reserved) {
	switch (a_reason) {
		case DLL_PROCESS_ATTACH: {
			// Stop library calls in the process
			DisableThreadLibraryCalls(a_instance);

			const HANDLE thread = CreateThread(
				nullptr,
				0,
				SetupMainThread,		// We get out of the main function here via a separate thread
				a_instance,
				0,
				nullptr
			);

			if (thread) {
				CloseHandle(thread);	// Close the handle to prevent resource leaks
			}

			break;
		}

		case DLL_PROCESS_DETACH: {
			break;
		}

	}
	return TRUE;
}