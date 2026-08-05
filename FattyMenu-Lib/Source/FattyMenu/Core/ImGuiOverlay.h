#pragma once
#include "Base.h"
#include "PlatformDetection.h"

// Panels
#include "../UI/Panels/CPSOPPanel.h"
#include "../UI/Panels/CreditsPanel.h"
#include "../UI/Panels/MapPanel.h"
#include "../UI/Panels/NotepadPanel.h"
#include "../UI/Panels/PermitPanel.h"
#include "../UI/Panels/TFSOPPanel.h"
#include "../UI/Panels/VoicelineLibraryPanel.h"


#include <vector>
#include <memory>

// Forward declarations
typedef struct IDirect3DDevice9* LPDIRECT3DDEVICE9, * PDIRECT3DDEVICE9;
typedef struct HWND__* HWND;

namespace FattyMenu {
	// ImGui panel visibility flags
	struct SPanelStateController {
		bool m_open_cpsop_panel{ false };
		bool m_open_credits_panel{ false };
		bool m_open_map_panel{ false };
		bool m_open_notepad_panel{ false };
		bool m_open_permit_panel{ false };
		bool m_open_tfsop_panel{ false };
		bool m_open_voiceline_library_panel{ false };

		bool m_open_version_overlay{ true }; // Turned on by default
	};

	// Sets up ImGui, displays a main menu bar for managing panel visibility
	class CImGuiOverlay {
	private:
		// Panels
		std::unique_ptr<CCPSOPPanel> m_cpsop_panel								= nullptr;
		std::unique_ptr<CCreditsPanel> m_credits_panel							= nullptr;
		std::unique_ptr<CMapPanel> m_map_panel									= nullptr;
		std::unique_ptr<CNotepadPanel> m_notepad_panel							= nullptr;
		std::unique_ptr<CPermitPanel> m_permit_panel							= nullptr;
		//std::unique_ptr<CTFSOPPanel> m_tfsop_panel							= nullptr;
		std::unique_ptr<CVoicelineLibraryPanel> m_voiceline_library_panel		= nullptr;

		SPanelStateController m_panel_state_controller;

		// Win32 - TODO: move to bootstrap window class
		HWND m_game_window_handle												= nullptr;
		WNDPROC m_original_window_proc											= nullptr;				// For restoring the original window proc

		// Flags
		bool m_is_open{ true };																			// For toggling. Main menubar is open by default
		bool m_is_initialized{ false };																	// For tracking imgui initialization

	public:
		CImGuiOverlay() = default;
		~CImGuiOverlay();
		
		FM_UNCOPYABLE_CLASS(CImGuiOverlay);

		void Init(LPDIRECT3DDEVICE9 a_game_d3d9_device);												// Initialized once we have the game's pdevice on the first EndScene call
		void RegisterPanels();
		
		void Shutdown() noexcept;
		void UnregisterPanels();

		void OnRender();
		void RenderMenuBar();
		void RenderVersionWindow(bool* a_p_open);
		
		void InvalidateDeviceObjects();
		void CreateDeviceObjects();

		LRESULT HandleWndProcMessages(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param);

		inline void Toggle() noexcept										{ m_is_open = !m_is_open;			}		// press key -> open -> press key -> close etc.

		// Accessors
		inline bool IsOpen() const noexcept									{ return m_is_open;					}
		inline bool IsInitialized() const noexcept							{ return m_is_initialized;			}
		inline const SPanelStateController& GetPanelStates() const noexcept	{ return m_panel_state_controller;	}

	};

}
