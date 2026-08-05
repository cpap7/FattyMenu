#pragma once
#include "Base.h"
#include "PlatformDetection.h"

#include <d3d9.h>

namespace FattyMenu {
	// Initialized as a temp window & window class - these are then used to obtain the game's D3D9 device pointer
	class CBootstrapWindow {
	private:
		WNDCLASSEX m_window_class{};
		HWND m_window_handle{ nullptr };

		static constexpr const char* s_window_class_name	= "FattyMenuWndClass";
		static constexpr const char* s_window_name			= "FattyMenuWnd";

	public:
		CBootstrapWindow();
		~CBootstrapWindow();

		FM_UNCOPYABLE_CLASS(CBootstrapWindow);
		FM_UNMOVABLE_CLASS(CBootstrapWindow);

		inline HWND GetWindowHandle() const noexcept		{ return m_window_handle; }

	private:
		void ReleaseWindowHandle();
		void ReleaseWindowClass();
	};
}

