#include "UserConfigSerializer.h"

#include <inicpp.h>

#include <filesystem>
#include <stdexcept>

namespace FattyMenu {

	bool CUserConfigSerializer::SaveUserConfig(const SUserConfig& a_config, const std::string& a_file_path) {
		ini::IniFile ini;
		
		auto& panel_state_config							= a_config.m_panel_state_config;
		ini["Panels"]["ShowCPSOP"]							= panel_state_config.m_open_cpsop_panel;
		ini["Panels"]["ShowLocationReadout"]				= panel_state_config.m_open_location_readout_panel;
		ini["Panels"]["ShowNotepad"]						= panel_state_config.m_open_notepad_panel;
		ini["Panels"]["ShowPermit"]							= panel_state_config.m_open_permit_panel;
		ini["Panels"]["ShowTFSOP"]							= panel_state_config.m_open_tfsop_panel;
		ini["Panels"]["ShowVoicelineLibrary"]				= panel_state_config.m_open_voiceline_library_panel;

		ini["Panels"]["ShowCredits"]						= panel_state_config.m_open_credits_panel;
		ini["Panels"]["ShowSettings"]						= panel_state_config.m_open_settings_panel;

		ini["Overlays"]["ShowVersionInfo"]					= panel_state_config.m_open_version_overlay;
		

		auto& image_config									= a_config.m_image_config;
		ini["ImageSettings"]["CPSOPLogoScale"]				= image_config.m_cpsop_image_scale;
		ini["ImageSettings"]["LocationReadoutMapScale"]		= image_config.m_location_readout_image_scale;

		ini.save(a_file_path);

		return true;
	}

	bool CUserConfigSerializer::LoadUserConfig(SUserConfig& a_config, const std::string& a_file_path) {
		if (!std::filesystem::exists(a_file_path)) {
			std::string error = "[FattyMenu Error] Failed to retrieve user config from file path: " + a_file_path;
			throw std::runtime_error(error);

			return false;
		}
		try {
			ini::IniFile ini;
			ini.load(a_file_path);

			a_config.m_panel_state_config.m_open_cpsop_panel				= ini["Panels"]["ShowCPSOP"].as<bool>();
			a_config.m_panel_state_config.m_open_location_readout_panel		= ini["Panels"]["ShowLocationReadout"].as<bool>();
			a_config.m_panel_state_config.m_open_notepad_panel				= ini["Panels"]["ShowNotepad"].as<bool>();
			a_config.m_panel_state_config.m_open_permit_panel				= ini["Panels"]["ShowPermit"].as<bool>();
			a_config.m_panel_state_config.m_open_tfsop_panel				= ini["Panels"]["ShowTFSOP"].as<bool>();
			a_config.m_panel_state_config.m_open_voiceline_library_panel	= ini["Panels"]["ShowVoicelineLibrary"].as<bool>();

			a_config.m_panel_state_config.m_open_credits_panel				= ini["Panels"]["ShowCredits"].as<bool>();
			a_config.m_panel_state_config.m_open_settings_panel				= ini["Panels"]["ShowSettings"].as<bool>();

			a_config.m_panel_state_config.m_open_version_overlay			= ini["Overlays"]["ShowVersionInfo"].as<bool>();

			a_config.m_image_config.m_cpsop_image_scale						= ini["ImageSettings"]["CPSOPLogoScale"].as<float>();
			a_config.m_image_config.m_location_readout_image_scale			= ini["ImageSettings"]["LocationReadoutMapScale"].as<float>();
		}
		catch (const std::exception& e) {
			throw std::runtime_error(e.what());
			return false;
		}

		

		return true;
	}
}