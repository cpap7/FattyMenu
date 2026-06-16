#include "Hooks.h"									// For function prototypes

#include <stdexcept>								// For error handling
#include <intrin.h>									// For a check to prevent the game calling EndScene twice

#include <../minhook/minhook.h>						// For hooking functions

// ImGui functions
#include <../imgui/imgui.h>
#include <../imgui/imgui_impl_win32.h>
#include <../imgui/imgui_impl_dx9.h>


namespace FattyMenu {
	void Hooks::InitializeHooks() {
		// Throwaway device must already exist (created by GUI::InitializeDevice)
		if (!GUI::g_d3d9_device) {
			throw std::runtime_error("No D3D9 device available to read the vtable.");
		}
		
		// Ensure minhook is initialized properly
		if (MH_Initialize() != MH_OK) {
			// MH_OK == 0, so if it returns 1, that means it didn't initialize
			throw std::runtime_error("Minhook could not be initialized.");
		}

		void* endscene_fn_address = GetVirtualFunctions(GUI::g_d3d9_device, 42); // EndScene
		void* reset_fn_address = GetVirtualFunctions(GUI::g_d3d9_device, 16); // Reset

		if (MH_CreateHook(endscene_fn_address,	&EndScene,	reinterpret_cast<void**>(&OriginalEndScene)) != MH_OK ||
			MH_CreateHook(reset_fn_address,		&Reset,		reinterpret_cast<void**>(&OriginalReset)) != MH_OK) {
			throw std::runtime_error("Failed to create D3D9 hooks");
		}


		// Ensure hooks are enabled
		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) { 
			MH_DisableHook(MH_ALL_HOOKS);	// Disable all hooks
			MH_Uninitialize();

			throw std::runtime_error("Hooks could not be enabled.");
		}
		
		GUI::DestroyDirectX9(); // Destroy temporary DX objects that were needed previously
	}

	void Hooks::DestroyHooks() noexcept {
		MH_DisableHook(MH_ALL_HOOKS);	// Disable all hooks
		MH_RemoveHook(MH_ALL_HOOKS);	// Remove all detours
		MH_Uninitialize();				// Uninitialize Minhook
	}

	long __stdcall Hooks::EndScene(IDirect3DDevice9* a_d3d9_device) noexcept {
		// Store the first return address of the EndScene function
		static const auto return_address = _ReturnAddress();

		// Call the original end scene function and store its resulting value
		const auto result = OriginalEndScene(a_d3d9_device, a_d3d9_device);

		// Prevent EndScene from being called twice in game
		if (_ReturnAddress() == return_address) { // Check if the current hooks address is equal to the first address of the function
			// Return the result out of the function
			return result;
		}

		// Check if the menu is set up
		if (!GUI::g_initialized) {
			// If it isn't, call the set up function
			GUI::InitializeMenu(a_d3d9_device);
		}

		// Check if the menu is open
		if (GUI::g_open_menu) {
			GUI::Render(); 		// Render menu data if true
		}

		return result;
	}

	HRESULT __stdcall Hooks::Reset(IDirect3DDevice9* a_d3d9_device, D3DPRESENT_PARAMETERS* a_d3d_params) noexcept {
		// Call the methods that reset the ImGUI device objects
		ImGui_ImplDX9_InvalidateDeviceObjects();

		// Call the original reset function and store its HRESULT value
		const auto hres = OriginalReset(a_d3d9_device, a_d3d9_device, a_d3d_params);

		// Create the ImGui device objects
		ImGui_ImplDX9_CreateDeviceObjects();

		return hres;

	}
}