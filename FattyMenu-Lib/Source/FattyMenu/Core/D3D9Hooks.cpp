#include "D3D9Hooks.h"
#include "Application.h"
#include "ImGuiOverlay.h"

// Minhook
#include <minhook.h>

// ImGui functions
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx9.h>

#include <stdexcept>
#include <intrin.h>				// _ReturnAddress()

namespace FattyMenu {
	EndSceneFn CD3D9Hooks::s_original_end_scene_fn	= nullptr;
	ResetFn CD3D9Hooks::s_original_reset_fn			= nullptr;

	CD3D9Hooks::CD3D9Hooks(LPDIRECT3DDEVICE9 a_throwaway_d3d9_device) {
		// Throwaway device must already exist (created by GUI::Initialize())
		if (!a_throwaway_d3d9_device) {
			throw std::runtime_error("[FattyMenu Error] No D3D9 device available to read the vtable.");
		}

		// Ensure minhook is initialized properly
		if (MH_Initialize() != MH_OK) {
			// NOTE: MH_OK == 0, so if it returns 1, that means it didn't initialize
			throw std::runtime_error("[FattyMenu Error] Minhook could not be initialized.");
		}

		m_endscene_fn_target	= GetVTableEntry(a_throwaway_d3d9_device, ENDSCENE_FN_ADDRESS_INDEX);		// EndScene
		m_reset_fn_target		= GetVTableEntry(a_throwaway_d3d9_device, RESET_FN_ADDRESS_INDEX);		// Reset

		if (MH_CreateHook(m_endscene_fn_target,		&EndSceneHook,		reinterpret_cast<void**>(&s_original_end_scene_fn)) != MH_OK ||
			MH_CreateHook(m_reset_fn_target,		&ResetHook,			reinterpret_cast<void**>(&s_original_reset_fn)) != MH_OK) {
			throw std::runtime_error("[FattyMenu Error] Failed to create D3D9 hooks");
		}


		// Ensure hooks are enabled
		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
			MH_DisableHook(MH_ALL_HOOKS);	// Disable all hooks
			MH_Uninitialize();

			throw std::runtime_error("[FattyMenu Error] Hooks could not be enabled.");
		}

		//a_throwaway_d3d9_device->Release();
		//a_throwaway_d3d9_device = nullptr;
	}

	CD3D9Hooks::~CD3D9Hooks() {
		MH_DisableHook(MH_ALL_HOOKS);	// Disable all hooks
		MH_RemoveHook(MH_ALL_HOOKS);	// Remove all detours
		MH_Uninitialize();				// Uninitialize Minhook
	}


	long __stdcall CD3D9Hooks::EndSceneHook(IDirect3DDevice9* a_d3d9_device) noexcept {
		static const auto return_address = _ReturnAddress();

		const auto result = s_original_end_scene_fn(a_d3d9_device, a_d3d9_device);
		if (_ReturnAddress() == return_address) { 	// Prevent EndScene from being called twice in game
			return result;
		}

		auto& overlay = CApplication::GetInstance().GetOverlay();

		// Check if the menu is set up
		if (!overlay.IsInitialized()) {
			overlay.Init(a_d3d9_device);
			// TODO: Consider updating the d3d9 device here for the d3d9 context, so we can use it for texture loading instead of hacking a solution via imgui
		}

		// Check if the menubar is open
		// TODO: Consider deferring this to CApplication, with a function there called "OnRender()" to handle this
		if (overlay.IsOpen()) {
			overlay.OnRender();
		}

		return result;
	}
	
	HRESULT __stdcall CD3D9Hooks::ResetHook(IDirect3DDevice9* a_d3d9_device, D3DPRESENT_PARAMETERS* a_d3d_params) noexcept {
		// Invalidate objects then recreate them
		auto& overlay = CApplication::GetInstance().GetOverlay();
		overlay.InvalidateDeviceObjects();

		const auto hres = s_original_reset_fn(a_d3d9_device, a_d3d9_device, a_d3d_params);

		overlay.CreateDeviceObjects();

		return hres;
	}
}