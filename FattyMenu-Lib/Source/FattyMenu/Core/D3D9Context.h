#pragma once
#include "Base.h"
#include <d3d9.h>

// Create function signature alias
using CreateFn = LPDIRECT3D9(__stdcall*)(UINT);	

namespace FattyMenu {
	// Owns throwaway device pointer, which is used for getting the vtable that the render hooks read from
	class CD3D9Context {
	private:
		LPDIRECT3D9 m_p_d3d9{ nullptr };
		LPDIRECT3DDEVICE9 m_p_d3d9_device{ nullptr };
	
	public:
		explicit CD3D9Context(HWND a_window);	// Creates object + device
		~CD3D9Context();						// LIFO release of resources

		FM_UNCOPYABLE_CLASS(CD3D9Context);
		FM_UNMOVABLE_CLASS(CD3D9Context);

		inline LPDIRECT3DDEVICE9 GetDevice() const noexcept { return m_p_d3d9_device; }
		void UpdateDevice(LPDIRECT3DDEVICE9 a_p_device) noexcept;

	private:
		void ReleaseD3D9();
		void ReleaseD3D9Device();
	};
}

