#pragma once
#include "Base.h"
#include "PlatformDetection.h"

#include "../Serialization/UserConfig.h"

// Panels
// "View" section of menubar
#include "../UI/Panels/CPSOPPanel.h"
#include "../UI/Panels/MapPanel.h"
#include "../UI/Panels/NotepadPanel.h"
#include "../UI/Panels/PermitPanel.h"
#include "../UI/Panels/TFSOPPanel.h"
#include "../UI/Panels/VoicelineLibraryPanel.h"

// "About" section of menubar
#include "../UI/Panels/CreditsPanel.h"

// "Settings" section of menubar
#include "../UI/Panels/ConfigSettingsPanel.h"


#include <vector>
#include <memory>

// Forward declarations
typedef struct IDirect3DDevice9* LPDIRECT3DDEVICE9, * PDIRECT3DDEVICE9;
typedef struct HWND__* HWND;

namespace FattyMenu {
	
	// Sets up ImGui, displays a main menu bar for managing panel visibility
	class CImGuiOverlay {
	private:
		// Config
		SUserConfig m_user_config;

		/* Panels */
		// "View" section
		std::unique_ptr<CCPSOPPanel> m_cpsop_panel								= nullptr;
		std::unique_ptr<CMapPanel> m_map_panel									= nullptr;
		std::unique_ptr<CNotepadPanel> m_notepad_panel							= nullptr;
		std::unique_ptr<CPermitPanel> m_permit_panel							= nullptr;
		//std::unique_ptr<CTFSOPPanel> m_tfsop_panel							= nullptr;
		std::unique_ptr<CVoicelineLibraryPanel> m_voiceline_library_panel		= nullptr;
		
		// "About" section
		std::unique_ptr<CCreditsPanel> m_credits_panel							= nullptr;

		// "Settings" section
		std::unique_ptr<CConfigSettingsPanel> m_config_settings_panel			= nullptr;

		// Win32
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

		void Toggle() noexcept;

		LRESULT HandleWndProcMessages(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param);

		// Accessors
		inline bool IsOpen() const noexcept									{ return m_is_open;					}
		inline bool IsInitialized() const noexcept							{ return m_is_initialized;			}
		inline const SUserConfig& GetUserConfig() const noexcept			{ return m_user_config;				}

	};

}
