#pragma once
#include "Base.h"
#include <d3d9.h>

// Function address indices
#define ENDSCENE_FN_ADDRESS_INDEX 42
#define RESET_FN_ADDRESS_INDEX 16

// Function aliases
using EndSceneFn = long(__thiscall*)(void*, IDirect3DDevice9*) noexcept; 								// EndScene function
using ResetFn = HRESULT(__thiscall*)(void*, IDirect3DDevice9*, D3DPRESENT_PARAMETERS*) noexcept; 		// Reset function - hooked for resetting ImGui's menu data when it's resized, alt-tabbed etc.

namespace FattyMenu {
	// Forward declarations
	class CImGuiOverlay;

	class CD3D9Hooks {
	private:
		static EndSceneFn s_original_end_scene_fn;
		static ResetFn s_original_reset_fn;

		// Target addresses
		void* m_endscene_fn_target{ nullptr };
		void* m_reset_fn_target{ nullptr };

		LPDIRECT3DDEVICE9 m_game_device;

	public:
		CD3D9Hooks(LPDIRECT3DDEVICE9 a_throwaway_d3d9_device);
		~CD3D9Hooks();

		// Inline function that returns virtual functions via a virtual function pointer (the d3d9 device)
		static inline void* GetVTableEntry(void* a_this_ptr, size_t a_index) noexcept {
			return (*static_cast<void***>(a_this_ptr))[a_index];
		}

		static long __stdcall EndSceneHook(IDirect3DDevice9* a_d3d9_device) noexcept;
		static HRESULT __stdcall ResetHook(IDirect3DDevice9* a_d3d9_device, D3DPRESENT_PARAMETERS* a_d3d_params) noexcept;
	};
}

