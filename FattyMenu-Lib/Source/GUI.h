#pragma once

// DirectX9 dependencies
#include <d3d9.h>

// ImGUI headers
#include <../imgui/imgui.h>
#include <../imgui/imgui_impl_win32.h>
#include <../imgui/imgui_impl_dx9.h>

// ImGUI utilities
#include "GUIUtilities.h"

#include <stdexcept>	// For exceptions

namespace FattyMenu {
	namespace GUI {
		inline bool g_open_menu					= true;							// For controlling when the menu should be shown
		inline bool g_initialized				= false;						// For determining whether the ImGui menu/context finished setup & ready (or not)
		inline bool g_setup_complete			= false;						// For determining whether the module thread + hooks setup is finished

		// WinAPI related variables
		inline HWND g_window					= nullptr;						// Window handle used for manual map injection
		inline WNDCLASSEX g_window_class		= { };
		inline WNDPROC OriginalWindowProc		= nullptr;						// For restoring the original window process


		// DirectX9 related variables
		inline LPDIRECT3DDEVICE9 g_d3d9_device	= nullptr;
		inline LPDIRECT3D9 g_d3d9				= nullptr;


		// Flags for managing initialization state for Garry's Mod module functions
		static bool g_gmod_initialized			= false;
		static HMODULE g_module					= nullptr;
		static HWND g_gmod_window				= nullptr;						// Window handle for Garry's Mod direct loading


		// Enums for determining load method (either manual map or direct load via Garry's Mod)
		enum class ELoadMethod {
			Unknown,
			ManualMap,
			GarrysModLoad
		};

		// Initial load method is set to unknown
		inline ELoadMethod g_load_method = ELoadMethod::Unknown;

		/* Function Prototypes */

		// Window class functions
		bool InitializeWindowClass(const char* a_window_class_name) noexcept;	// Registers the window class
		void DestroyWindowClass() noexcept;										// Unregisters the window class

		// Window functions
		bool InitializeWindow(const char* a_window_name) noexcept;				// Registers the window
		void DestroyWindow();													// Unregisters the window

		// Function prototypes for direct via Garry's Mod
		BOOL CALLBACK EnumWindowsCallback(HWND a_handle, LPARAM a_lparam);
		HWND FindGameWindow();
		void HookWindowProc();

		// DirectX9 setup and cleanup
		bool InitializeDirectX9() noexcept;										// Sets up DirectX
		void DestroyDirectX9() noexcept;										// Unregisters DirectX

		// Device setup
		void InitializeDevice();												// Sets up/registers the device

		// ImGUI setup
		void InitializeMenu(LPDIRECT3DDEVICE9 a_d3d9_device) noexcept;			// Sets up the ImGUI menu

		void Destroy() noexcept;												// Unregisters everything
		void Render() noexcept;													// Renders the menu

	}
}