#include "BootstrapWindow.h"
#include "Application.h"

#include <Windows.h>
#include <stdexcept>

namespace FattyMenu {
	CBootstrapWindow::CBootstrapWindow() {
		/* Create window class */
		// Populate the window class' attributes
		m_window_class.cbSize			= sizeof(WNDCLASSEX);			
		m_window_class.style			= CS_HREDRAW | CS_VREDRAW;		// Style
		m_window_class.lpfnWndProc		= DefWindowProc;				// Set to be the default window proc
		m_window_class.cbClsExtra		= 0;
		m_window_class.cbWndExtra		= 0;
		m_window_class.hInstance		= GetModuleHandle(NULL);		// Instance handle to NULL
		m_window_class.hIcon			= NULL;
		m_window_class.hCursor			= NULL;
		m_window_class.hbrBackground	= NULL;
		m_window_class.lpszMenuName		= NULL;
		m_window_class.lpszClassName	= s_window_class_name;
		m_window_class.hIconSm			= NULL;

		// Ensure the window class is properly registered
		if (!(RegisterClassEx(&m_window_class))) {
			throw std::runtime_error("[FattyMenu Error] Window class could not be created.");
		}

		// Window class setup successful
		
		/* Create temporary window */
		m_window_handle = CreateWindow(
			m_window_class.lpszClassName,					// Window class name
			s_window_name,									// Window name
			WS_OVERLAPPEDWINDOW,							// Style
			0,												// X = 0
			0,												// Y = 0
			100,											// 100 width
			100,											// 100 height
			0,												// No parent
			0,												// No menu
			m_window_class.hInstance,						// Window class' instance handle
			0
		);

		if (!m_window_handle) {
			ReleaseWindowClass();
			throw std::runtime_error("[FattyMenu Error] Window could not be created.");
		}

		// Window setup successful
	}
	
	CBootstrapWindow::~CBootstrapWindow() {
		// LIFO
		ReleaseWindowHandle();
		ReleaseWindowClass();
	}

	void CBootstrapWindow::ReleaseWindowHandle() {
		if (m_window_handle) {
			::DestroyWindow(m_window_handle);
			m_window_handle = nullptr;
		}
	}

	void CBootstrapWindow::ReleaseWindowClass() {
		UnregisterClass(m_window_class.lpszClassName, m_window_class.hInstance);
	}

}