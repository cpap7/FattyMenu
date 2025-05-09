#pragma once

// DirectX9 dependencies
#include <d3d9.h>

// ImGUI headers
#include "../ext_dependencies/imgui/imgui.h"
#include "../ext_dependencies/imgui/imgui_impl_win32.h"
#include "../ext_dependencies/imgui/imgui_impl_dx9.h"

// ImGUI utilities
#include "GUIUtilities.h"

#include <stdexcept>	// To be able to throw exceptions

namespace GUI {
	inline bool open_menu = true;										// For controlling when the menu should be shown
	inline bool initialized = false;									// For determining whether the menu is set up or not

	// WinAPI related variables
	inline HWND window = nullptr;										// Window handle used for manual map injection
	inline WNDCLASSEX window_class = { };
	inline WNDPROC OriginalWindowProc = nullptr;						// For restoring the original window process

	static HWND gm_window = NULL;										// Window handle for Garry's Mod direct loading

	// DirectX9 related variables
	inline LPDIRECT3DDEVICE9 d3d9_device = nullptr;
	inline LPDIRECT3D9 d3d9 = nullptr;

	// Flags for managing initialization state for Garry's Mod module functions
	static bool g_initialized = false;
	static HMODULE g_module = nullptr;

	// Enums for determining load method (either manual map or direct load via Garry's Mod)
	enum class LoadMethod {
		Unknown,
		ManualMap,
		GarrysModLoad
	};

	// Initial load method is set to unknown
	inline LoadMethod g_load_method = LoadMethod::Unknown;

	/* Function Prototypes */
	// Window class functions
	bool InitializeWindowClass(const char* window_class_name) noexcept; // Registers the window class
	void DestroyWindowClass() noexcept;									// Unregisters the window class
	
	// Window functions
	bool InitializeWindow(const char* window_name) noexcept;			// Registers the Window
	void DestroyWindow();												// Unregisters the window

	BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lparam);
	HWND FindGameWindow();
	void HookWindowProc();

	// DirectX9 setup and cleanup
	bool InitializeDirectX9() noexcept;									// Sets up DirectX
	void DestroyDirectX9() noexcept;									// Unregisters DirectX
	
	// Device setup
	void InitializeDevice();											// Sets up/registers the device

	// ImGUI setup
	void InitializeMenu(LPDIRECT3DDEVICE9 d3d9_device) noexcept;		// Sets up the ImGUI menu
	
	void Destroy() noexcept;											// Unregisters everything
	void Render() noexcept;												// Renders the menu

}