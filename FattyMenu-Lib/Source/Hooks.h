#pragma once
#include "GUI.h"

namespace FattyMenu {
	namespace Hooks {
		/* Function prototypes for hooks */
		void InitializeHooks();
		void DestroyHooks() noexcept;

		// Inline function that returns virtual functions via a virtual function pointer (the d3d9 device)
		constexpr void* GetVirtualFunctions(void* a_this_ptr, size_t a_index) noexcept {
			return (*static_cast<void***>(a_this_ptr))[a_index];
		}

		// For EndSceneFn hook
		using EndSceneFn = long(__thiscall*)(void*, IDirect3DDevice9*) noexcept; 								// Alias of EndScene function - takes a void ptr and a D3D9 device ptr
		inline EndSceneFn g_original_end_scene_fn = nullptr;															// Variable to store the original end scene function
		long __stdcall EndScene(IDirect3DDevice9* a_d3d9_device) noexcept; 

		// For ResetFn hook
		using ResetFn = HRESULT(__thiscall*)(void*, IDirect3DDevice9*, D3DPRESENT_PARAMETERS*) noexcept; 		// Alias of Reset function - hook for resetting ImGui's menu data when it's resized, alt-tabbed etc.
		inline ResetFn g_original_reset_fn = nullptr; 																// Variable to store the original reset function
		HRESULT __stdcall Reset(IDirect3DDevice9* a_d3d9_device, D3DPRESENT_PARAMETERS* a_d3d_params) noexcept;


	}
}