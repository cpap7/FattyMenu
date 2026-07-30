#pragma once

// DirectX9 dependencies
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9")

// ImGUI headers
#include <../imgui/imgui.h>
#include <../imgui/imgui_impl_win32.h>
#include <../imgui/imgui_impl_dx9.h>

// ImGUI utilities
#include "GUIUtilities.h"

#include <stdexcept>	// For exceptions
#include <cstdint>

namespace FattyMenu {
	// TODO: Refactor to use classes
	// CApplication class (main coordinator w/ static singleton for accessing)
	// CFunctionDetourManager, CWindow, CImGuiOverlay, IPanel etc.
	namespace GUI {
		// ImGui controls
		inline bool g_open_panels											= true;								// For controlling when the panels are shown

		// Setup tracking
		inline bool g_initialized												= false;						// For determining whether the ImGui menu/context finished setup & ready (or not)
		inline bool g_setup_complete											= false;						// For determining whether the module thread + hooks setup is finished

		// WinAPI related variables
		inline HWND g_window													= nullptr;						// Window handle used for manual map injection
		inline WNDCLASSEX g_window_class										= { };
		inline WNDPROC g_original_window_proc									= nullptr;						// For restoring the original window process
		static HMODULE g_module													= nullptr;

		// DirectX9 related variables
		inline LPDIRECT3DDEVICE9 g_d3d9_device									= nullptr;
		inline LPDIRECT3D9 g_d3d9												= nullptr;		

		// D3DX9 related variables
		// Alias for D3DXCreateTextureFromFileA function signature
		using CreateTextureFn = HRESULT(__stdcall*)(
			LPDIRECT3DDEVICE9,		// pDevice
			LPCSTR,					// pSrcFile
			LPDIRECT3DTEXTURE9*		// ppTexture
		);

		inline CreateTextureFn g_create_texture_fn								= nullptr;						// Function pointer to D3DX's create texture method
		static HMODULE g_d3dx9_module_handle									= nullptr;


		/* Function Prototypes */

		// Window class functions
		bool InitializeWindowClass(const char* a_window_class_name) noexcept;	// Registers the window class
		void DestroyWindowClass() noexcept;										// Unregisters the window class

		// Window functions
		bool InitializeWindow(const char* a_window_name) noexcept;				// Registers the window
		void DestroyWindow();													// Unregisters the window

		// DirectX9 setup and cleanup
		bool InitializeDirectX9() noexcept;										// Sets up Direct3D9 resources
		void DestroyDirectX9() noexcept;										// Unloads Direct3D9 resources

		bool InitializeD3DX9() noexcept;										// Checks if the user has DXD9 runtime dlls installed on their machine (for texture loading) and caches the function pointer
		void DestroyD3DX9() noexcept;

		// Application setup
		void Initialize();														// Sets up/registers everything

		// ImGUI setup
		void InitializeMenu(LPDIRECT3DDEVICE9 a_d3d9_device) noexcept;			// Sets up the ImGUI menu

		void Destroy() noexcept;												// Unregisters everything
		void Render() noexcept;													// Renders the menu

	}
}