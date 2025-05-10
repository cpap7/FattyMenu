#include "Hooks.h"									// For function prototypes

#include <stdexcept>								// For error handling
#include <intrin.h>									// For a check to prevent the game calling EndScene twice

#include "../ext_dependencies/minhook/minhook.h"	// For hooking functions

// ImGui functions
#include "../ext_dependencies/imgui/imgui.h"
#include "../ext_dependencies/imgui/imgui_impl_win32.h"
#include "../ext_dependencies/imgui/imgui_impl_dx9.h"

// TODO: fix this jank
void Hooks::InitializeHooks() {
	// Ensure minhook is initialized properly
	if (MH_Initialize()) {	// When Minhook returns successfully, it returns 0 == false
		// For Garry's Mod direct load, there's at startup delay, so the game window will need to be found before hooking properly
		if (GUI::g_load_method == GUI::LoadMethod::GarrysModLoad) {
			do { // Perform for at least one iteration
				GUI::FindGameWindow();
			} while (GUI::gm_window == NULL);
		}
		// So if it returns 1 == true, that means it didn't initialize
		throw std::runtime_error("Minhook could not be initialized.");
	}

	// Check if Kiero was able to initialize based on the render type (D3D9)
	if (kiero::init(kiero::RenderType::D3D9) != kiero::Status::Success) {
		throw std::runtime_error("Kiero initialization failed.");
	}

	// Check bindings for EndScene and Reset hooks via Kiero
	if (kiero::bind(42, (void**)&OriginalEndScene, EndScene)) { // Bind for EndScene
		throw std::runtime_error("Failed to hook EndScene function."); 
	}

	if (kiero::bind(16, (void**)&OriginalReset, Reset)) {	// Bind for Reset
		throw std::runtime_error("Failed to hook Reset function.");
	}

	// Ensure hooks are enabled
	if (MH_EnableHook(MH_ALL_HOOKS)) {  // Same deal here as the first if-check, true == failed to enable
		kiero::shutdown();
		MH_Uninitialize();
		
		throw std::runtime_error("Hooks could not be enabled.");
	}
	// Destroy temporary DX objects needed to be created for manual map
	if (GUI::g_load_method == GUI::LoadMethod::ManualMap) { // Check for manual map
		GUI::DestroyDirectX9();
	}
}

void Hooks::DestroyHooks() noexcept {
	kiero::shutdown();				// Shut down kiero, disable all hooks
	//MH_DisableHook(MH_ALL_HOOKS);	// Disable all hooks
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