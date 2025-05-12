#pragma once
#include "GUI.h"
#include "kiero.h"

namespace Hooks {
	/* Function prototypes for hooks */
	void InitializeHooks();
	void DestroyHooks() noexcept;

	// Inline function that returns virtual functions via a virtual function pointer (the d3d9 device)
	constexpr void* GetVirtualFunctions(void* thisptr, size_t index) noexcept {
		// Return an array of ptrs of a given index size
		return (*static_cast<void***>(thisptr))[index];
	}

	// For EndSceneFn hook
	using EndSceneFn = long(__thiscall*)(void*, IDirect3DDevice9*) noexcept; 							// Typedef of EndScene function that takes a void ptr and a D3D9 device ptr
	inline EndSceneFn OriginalEndScene = nullptr;														// Variable to store the original end scene function
	long __stdcall EndScene(IDirect3DDevice9* d3d9_device) noexcept; 									// Hook function definition

	// For ResetFn hook
	using ResetFn = HRESULT(__thiscall*)(void*, IDirect3DDevice9*, D3DPRESENT_PARAMETERS*) noexcept; 	// Hook for resetting ImGui's menu data when it's resized, alt-tabbed etc.
	inline ResetFn OriginalReset = nullptr; 															// Variable to store the original reset function
	HRESULT __stdcall Reset(IDirect3DDevice9* d3d9_device, D3DPRESENT_PARAMETERS* d3d_params) noexcept; // Hook function definition


}

