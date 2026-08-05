#include "D3DX9Loader.h"

#include <d3dx9.h>
#pragma comment(lib, "d3dx9")

#include <stdexcept>

namespace FattyMenu {
	CD3DX9Loader::CD3DX9Loader() {
		const HMODULE d3dx9_module_handle = LoadLibraryA("d3dx9_43.dll"); // Load (may not be mapped yet)
		if (!d3dx9_module_handle) {
			throw std::runtime_error("[FattyMenu Error] d3dx9_43.dll could not be loaded, possibly due to missing Microsoft DirectX SDK (June 2010) installation");
		}

		const auto create_texture_fn = (CreateTextureFn)(GetProcAddress(d3dx9_module_handle, "D3DXCreateTextureFromFileA"));
		if (!create_texture_fn) {
			throw std::runtime_error("[FattyMenu Error] Failed to find function: D3DXCreateTextureFromFileA");
		}

		m_module			= d3dx9_module_handle;			// Cache the handle
		m_create_texture_fn = create_texture_fn;			// Cache function ptr

		// Setup successful
	}
	
	CD3DX9Loader::~CD3DX9Loader() {
		if (m_module) {
			FreeLibrary(m_module);
			m_module = nullptr;
		}

		if (m_create_texture_fn) {
			m_create_texture_fn = nullptr;
		}
	}
}