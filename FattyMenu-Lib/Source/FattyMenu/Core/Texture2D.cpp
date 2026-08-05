#include "Texture2D.h"

#include "Application.h"

// ImGUI headers
#include <../imgui/imgui.h>
#include <../imgui/imgui_impl_win32.h>
#include <../imgui/imgui_impl_dx9.h>

// D3D9
#include <d3d9.h>
#include <d3dx9tex.h>

#include <filesystem>
#include <stdexcept>

namespace FattyMenu {
	CTexture2D::CTexture2D(const std::string& a_file_path) 
		: m_file_path(a_file_path), m_texture_handle(nullptr), 
		m_width(0), m_height(0),
		m_load_attempted(false), m_load_ok(false) {

		Invalidate();
	}

	CTexture2D::CTexture2D(CTexture2D&& a_other) noexcept
		: m_file_path(std::move(a_other.m_file_path)),
		m_texture_handle(a_other.m_texture_handle),
		m_width(a_other.m_width), m_height(a_other.m_height),
		m_load_attempted(a_other.m_load_attempted), m_load_ok(a_other.m_load_ok) {

		a_other.m_texture_handle	= nullptr; // Prevent possible double release
		a_other.m_load_ok			= false;

	}

	CTexture2D& CTexture2D::operator=(CTexture2D&& a_other) noexcept {
		if (this != &a_other) {
			Release(); // Free what's currently being held

			m_file_path					= std::move(a_other.m_file_path);
			m_texture_handle			= a_other.m_texture_handle;
			m_width						= a_other.m_width;
			m_height					= a_other.m_height;
			m_load_attempted			= a_other.m_load_attempted;
			m_load_ok					= a_other.m_load_ok;

			a_other.m_texture_handle	= nullptr; // Prevent possible double release
			a_other.m_load_ok			= false;
		}

		return *this;
	}
	
	CTexture2D::~CTexture2D() {
		Release();
	}

	// (Re)loads texture from file path - releases previously held texture first
	void CTexture2D::Invalidate() {
		Release();
		
		m_load_attempted = true;

		if (!std::filesystem::exists(m_file_path)) {
			return;
		}

		LoadFromFilePath();
	}

	void CTexture2D::Release() {
		if (m_texture_handle) {
			m_texture_handle->Release();
			m_texture_handle = nullptr;
		}

		m_width				= 0;
		m_height			= 0;
		m_load_attempted	= false;
		m_load_ok			= false;
	}

	void CTexture2D::LoadFromFilePath() {
		LPDIRECT3DDEVICE9 device = ImGui_ImplDX9_GetDevice(); // This is not shipped with ImGui - it'll need to be reimplemented if ImGui is updated later
		//LPDIRECT3DDEVICE9 device = GUI::g_d3d9_device; 

		if (!device) {
			return; // Should never reach this point
		}

		auto& app = CApplication::GetInstance();
		
		// Load texture from disk
		HRESULT hr = app.GetD3DX9Loader().CreateTexture()(device, m_file_path.c_str(), &m_texture_handle);
		if (hr != S_OK) {
			return;
		}

		// Retrieve description of texture surface so we can get its size
		D3DSURFACE_DESC image_desc;
		m_texture_handle->GetLevelDesc(0, &image_desc);

		m_width		= static_cast<int>(image_desc.Width);
		m_height	= static_cast<int>(image_desc.Height);

		m_load_ok	= true;
	}

}