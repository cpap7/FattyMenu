#pragma once
#include "Base.h"
#include <d3d9.h>

// Aliases for D3DX9 function signatures
using CreateTextureFn = HRESULT(__stdcall*)(LPDIRECT3DDEVICE9, LPCSTR, LPDIRECT3DTEXTURE9*);	// D3DXCreateTextureFromFileA(pDevice, pSrcFile, ppTexture)

namespace FattyMenu {
	// Probes for d3dx9_43.dll on construction
	// It also caches the D3DXCreateTextureFromFileA function pointer for loading custom textures from disk
	class CD3DX9Loader {
	private:
		HMODULE m_module{ nullptr };
		CreateTextureFn m_create_texture_fn{ nullptr };

	public:
		CD3DX9Loader();		// Calls LoadLibrary & resolves dll exports for d3dx9_43.dll
		~CD3DX9Loader();

		FM_UNCOPYABLE_CLASS(CD3DX9Loader);

		CreateTextureFn CreateTexture() const noexcept { return m_create_texture_fn; }
	};
}

