#include "Application.h"

#include <imgui.h>

#include <thread>

extern bool g_application_running;

namespace FattyMenu {
	CApplication* CApplication::s_instance = nullptr;
	
	CApplication::CApplication() {
		s_instance				= this;
		g_application_running	= true;

		Init();
	}
	
	CApplication::~CApplication() {
		Shutdown();

		g_application_running	= false;
		s_instance				= nullptr;
	}

	void CApplication::Init() {
		// RAII
		m_bootstrap_window	= std::make_unique<CBootstrapWindow>();
		m_d3d9_context		= std::make_unique<CD3D9Context>(m_bootstrap_window->GetWindowHandle());
		m_d3dx9_loader		= std::make_unique<CD3DX9Loader>();

		// TODO: Consider folding RAII members above into d3d9 renderer class or the hooks class, then moving overlay & hooks setup logic to Run()
		// since after setting hooks up, the main render logic begins
		
		// NOTE: Overlay must exist before the hooks are set up
		m_overlay			= std::make_unique<CImGuiOverlay>(); 								// Initialization occurs after hooks are set up
		m_d3d9_hooks		= std::make_unique<CD3D9Hooks>(m_d3d9_context->GetDevice());		// NOTE: This sets up overlay after 1st frame. Context device has a dummy device for reading vtable function ptrs

		m_bootstrap_window.reset(); // No longer needed
		m_is_initialized	= true;
	}

	void CApplication::Shutdown() {
		if (!m_is_initialized) {
			return; // To prevent double teardown 
		}
		m_d3d9_hooks.reset();
		m_overlay.reset();

		m_d3dx9_loader.reset();
		m_d3d9_context.reset();
		
		m_bootstrap_window.reset();

		m_is_initialized = false;
	}

	void CApplication::Run() {
		// Additional preliminary setup can go here, before the loop
		// TODO: Consider moving m_overlay and m_d3d9_hooks setup here, then the hooks can call an OnRender function here
		
		while (!GetAsyncKeyState(VK_END) && g_application_running) {
			// Sleep thread to save on resources
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}

		Unload();
	}
	
	void CApplication::Unload() {
		g_application_running = false;
	}

	LRESULT CALLBACK CApplication::WndProc(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param) {
		if (s_instance && s_instance->m_overlay) {
			return s_instance->GetOverlay().HandleWndProcMessages(a_window, a_message, a_wide_param, a_long_param);
		}
		return DefWindowProc(a_window, a_message, a_wide_param, a_long_param);
	}

	CApplication& CApplication::GetInstance() {
		return *s_instance;
	}
}