#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <thread>
#include <cstdint>

#include "Hooks.h"

/* Setup function for initializing the pointer device and hooks 
* @param instance -> handle for the instance
*/
void Setup(const HMODULE instance) {
	// Try to set up everything
	try {
		GUI::InitializeDevice();
		Hooks::InitializeHooks();
	}
	// Catch any errors and display them
	catch (const std::exception& ex) {
		MessageBeep(MB_ICONERROR);
		MessageBox(0, ex.what(), "Error:", MB_OK | MB_ICONEXCLAMATION);
		
		// Jump to label
		goto UNLOAD;	// Label for removing all hooks
	}

	// Infinite while loop for the menu to function until the End key is pressed
	while (!GetAsyncKeyState(VK_END))
		// Sleep the thread
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

UNLOAD:
	// Teardown the GUI and hooks
	Hooks::DestroyHooks();
	GUI::Destroy();

	FreeLibraryAndExitThread(instance, 0);
}


/* Main function: dll entry point for manual map injection
* @param instance -> instance of the process
* @param reason -> determines why DllMain is being called
* @param reserved -> reserved keyword
* @return -> TRUE or FALSE depending on the entry's success
*/
BOOL WINAPI DllMain(const HMODULE instance, const std::uintptr_t reason, const void* reserved) {
	
	// Check the reason why DllMain is being called
	if (reason == DLL_PROCESS_ATTACH) {
		// Reason involves attachment to a given process
		
		// Stop library calls in the process
		DisableThreadLibraryCalls(instance);

		// Create the thread
		const HANDLE thread = CreateThread(
			nullptr,
			0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(Setup),
			instance, // Pass the instance parameter to Setup
			0,
			nullptr
		);

		// Check if the thread is not null
		if (thread) {
			CloseHandle(thread);
		}
	}

	return TRUE;
}
