#pragma once

namespace FattyMenu {
	// ImGui visibility flags
	struct SPanelStateConfig {
		// "View" section of menubar
		bool m_open_cpsop_panel{ false };
		bool m_open_location_readout_panel{ false };
		bool m_open_notepad_panel{ false };
		bool m_open_permit_panel{ false };
		bool m_open_tfsop_panel{ false };
		bool m_open_voiceline_library_panel{ false };

		// "About" section of menubar
		bool m_open_credits_panel{ false };
		bool m_open_version_overlay{ true }; // Turned on by default

		// "Settings" section of menubar
		bool m_open_settings_panel{ false };
	};

	struct SImageConfig {
		float m_cpsop_image_scale{ 0.5f };
		float m_location_readout_image_scale{ 0.45f };
	};

	struct SUserConfig {
		SPanelStateConfig m_panel_state_config;
		SImageConfig m_image_config;
	};
}

