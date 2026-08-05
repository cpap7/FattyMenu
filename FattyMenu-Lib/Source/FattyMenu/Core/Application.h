#pragma once
#include "Base.h"
#include "PlatformDetection.h"

#include "BootstrapWindow.h"
#include "D3D9Context.h"
#include "D3DX9Loader.h"
#include "D3D9Hooks.h"
#include "ImGuiOverlay.h"

#include <memory>

namespace FattyMenu {
	class CApplication {
	private:
		std::unique_ptr<CBootstrapWindow> m_bootstrap_window	= nullptr; // Temp window
		std::unique_ptr<CD3D9Context> m_d3d9_context			= nullptr;
		std::unique_ptr<CD3DX9Loader> m_d3dx9_loader			= nullptr;
		std::unique_ptr<CImGuiOverlay> m_overlay				= nullptr;
		std::unique_ptr<CD3D9Hooks> m_d3d9_hooks				= nullptr;

		static CApplication* s_instance;

		bool m_is_initialized = false;
	
	public:
		CApplication();
		~CApplication();

		void Init();
		void Shutdown();

		void Run();		// Main loop
		void Unload();	// Signal for uninjecting the DLL


		// Callbacks
		static LRESULT CALLBACK WndProc(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param); // Thunk

		// Accessors
		static CApplication& GetInstance();

		CImGuiOverlay& GetOverlay() const		{ return *m_overlay;		}
		CD3DX9Loader& GetD3DX9Loader() const	{ return *m_d3dx9_loader;	}
		CD3D9Context& GetContext() const		{ return *m_d3d9_context;	}

		//void SetContextDevice(LPDIRECT3DDEVICE9 a_device) const { m_d3d9_context->UpdateDevice(a_device); }
	};
}

