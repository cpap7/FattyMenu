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
	inline HWND window = nullptr;										// Window handle
	inline WNDCLASSEX window_class = { };
	inline WNDPROC o_window_proc = nullptr;								// For restoring the original window process

	// DirectX9 related variables
	inline LPDIRECT3DDEVICE9 d3d9_device = nullptr;
	inline LPDIRECT3D9 d3d9 = nullptr;

	/* Function Prototypes */
	// Window class
	bool InitializeWindowClass(const char* window_class_name) noexcept; // Registers the window class
	void DestroyWindowClass() noexcept;									// Unregisters the window class
	
	// Window
	bool InitializeWindow(const char* window_name) noexcept;			// Registers the Window
	void DestroyWindow();												// Unregisters the window

	// DirectX9
	bool InitializeDirectX9() noexcept;									// Sets up DirectX
	void DestroyDirectX9() noexcept;									// Unregisters DirectX
	

	// Device 
	void InitializeDevice();											// Sets up/registers the device

	// ImGUI
	void InitializeMenu(LPDIRECT3DDEVICE9 d3d9_device) noexcept;		// Sets up the ImGUI menu
	void Destroy() noexcept;											// Unregisters everything

	void Render() noexcept;												// Renders the menu

}