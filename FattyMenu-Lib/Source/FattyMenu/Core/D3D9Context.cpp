#include "D3D9Context.h"

#include <stdexcept>


namespace FattyMenu {
	CD3D9Context::CD3D9Context(HWND a_window) {
		const HMODULE d3d9_handle = GetModuleHandle("d3d9.dll");
		if (!d3d9_handle) {
			throw std::runtime_error("[FattyMenu Error] d3d9.dll is not mapped into the process");
		}

		// TODO: Remove C-style cast 
		const auto create_fn = (CreateFn)(GetProcAddress(d3d9_handle, "Direct3DCreate9"));	// GetProcAddress to retrieve dll exports		
		if (!create_fn) {
			throw std::runtime_error("[FattyMenu Error] Could not resolve Direct3DCreate9");
		}

		m_p_d3d9 = create_fn(D3D_SDK_VERSION);
		if (!m_p_d3d9) {
			throw std::runtime_error("[FattyMenu Error] Direct3DCreate9 returned null");
		}

		D3DPRESENT_PARAMETERS d3d_params = { };
		d3d_params.BackBufferWidth				= 0;
		d3d_params.BackBufferHeight				= 0;
		d3d_params.BackBufferFormat				= D3DFMT_UNKNOWN;
		d3d_params.BackBufferCount				= 0;
		d3d_params.MultiSampleType				= D3DMULTISAMPLE_NONE;
		d3d_params.MultiSampleQuality			= NULL;
		d3d_params.SwapEffect					= D3DSWAPEFFECT_DISCARD;
		d3d_params.hDeviceWindow				= a_window;				// Set the device window so it can retrieve the device from the window being created
		d3d_params.Windowed						= 1;
		d3d_params.EnableAutoDepthStencil		= 0;
		d3d_params.AutoDepthStencilFormat		= D3DFMT_UNKNOWN;
		d3d_params.Flags						= NULL;
		d3d_params.FullScreen_RefreshRateInHz	= 0;
		d3d_params.PresentationInterval			= 0;

		// Set up d3d9 device pointer
		const HRESULT result = m_p_d3d9->CreateDevice(
			D3DADAPTER_DEFAULT, 
			D3DDEVTYPE_NULLREF,
			a_window, 
			D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT,
			&d3d_params, 
			&m_p_d3d9_device
		);

		if (result < 0) {
			ReleaseD3D9();

			// Initialization failed (< 0)
			throw std::runtime_error("[FattyMenu Error] D3D9 device could not be created");
		}

		// Initialization was successful

	}
	
	CD3D9Context::~CD3D9Context() {
		// LIFO
		ReleaseD3D9Device();
		ReleaseD3D9();
	}

	void CD3D9Context::UpdateDevice(LPDIRECT3DDEVICE9 a_p_device) noexcept {
		ReleaseD3D9Device();
		m_p_d3d9_device = a_p_device;
	}

	void CD3D9Context::ReleaseD3D9Device() {
		if (m_p_d3d9_device) {
			m_p_d3d9_device->Release();
			m_p_d3d9_device = nullptr;
		}
	}

	void CD3D9Context::ReleaseD3D9() {
		if (m_p_d3d9) {
			m_p_d3d9->Release();
			m_p_d3d9 = nullptr;
		}
	}
	
	
}