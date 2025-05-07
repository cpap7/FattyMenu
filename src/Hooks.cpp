#include "Hooks.h"									// For function prototypes

#include <stdexcept>								// For error handling
#include <intrin.h>									// For a check to prevent the game calling EndScene twice

#include "../ext_dependencies/minhook/minhook.h"	// For hooking functions

// ImGui functions
#include "../ext_dependencies/imgui/imgui.h"
#include "../ext_dependencies/imgui/imgui_impl_win32.h"
#include "../ext_dependencies/imgui/imgui_impl_dx9.h"

void Hooks::InitializeHooks() {
	// Ensure minhook is initialized properly
	if (MH_Initialize()) {	// When Minhook returns successfully, it returns 0 == false
		// So if it returns 1 == true, that means it didn't initialize
		throw std::runtime_error("Minhook could not be initialized.");
	}

	// Check to see if the EndScene function hook can be created
	if (MH_CreateHook(
		GetVirtualFunctions(GUI::d3d9_device, 42), // Might need to change the index
		&EndScene,
		(void**)(&OriginalEndScene))
	   ) 
	{
		// Throw an error if it fails
		throw std::runtime_error("Failed to hook EndScene function.");
	}

	// Check to see if the Reset function hook can be created
	if (MH_CreateHook(
		GetVirtualFunctions(GUI::d3d9_device, 16), // Might need to change the index
		&Reset,
		(void**)(&OriginalReset))
		)
	{
		throw std::runtime_error("Failed to hook Reset function.");
	}

	// Ensure hooks are enabled
	if (MH_EnableHook(MH_ALL_HOOKS)) { // Same deal here as the first if-check
		throw std::runtime_error("Hooks could not be enabled.");
	}

	// D3D9 device is no longer needed at this point, so time to destroy it
	GUI::DestroyDirectX9();
}

void Hooks::DestroyHooks() noexcept {
	MH_DisableHook(MH_ALL_HOOKS);	// Disable all hooks
	MH_RemoveHook(MH_ALL_HOOKS);	// Remove all hooks
	MH_Uninitialize();				// Uninitialize Minhook

}

long __stdcall Hooks::EndScene(IDirect3DDevice9* d3d9_device) noexcept {
	// Store the first return address of the EndScene function
	static const auto return_address = _ReturnAddress();

	// Call the original end scene function and store its resulting value
	const auto result = OriginalEndScene(d3d9_device, d3d9_device);

	// Prevent EndScene from being called twice in game
	if (_ReturnAddress() == return_address) { // Check if the current hooks address is equal to the first address of the function
		// Return the result out of the function
		return result;
	}

	// Check if the menu is set up
	if (!GUI::initialized) {
		// If it isn't, call the set up function
		GUI::InitializeMenu(d3d9_device);
	}

	// Check if the menu is open
	if (GUI::open_menu) {
		GUI::Render(); 		// Render menu data if true
	}

	return result;
}

HRESULT __stdcall Hooks::Reset(IDirect3DDevice9* d3d9_device, D3DPRESENT_PARAMETERS* d3d_params) noexcept {
	// Call the methods that reset the ImGUI device objects
	ImGui_ImplDX9_InvalidateDeviceObjects();
	
	// Call the original reset function and store its HRESULT value
	const auto hres = OriginalReset(d3d9_device, d3d9_device, d3d_params);

	// Create the ImGui device objects
	ImGui_ImplDX9_CreateDeviceObjects();

	return hres;

}