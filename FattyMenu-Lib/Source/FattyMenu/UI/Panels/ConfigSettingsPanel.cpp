#include "ConfigSettingsPanel.h"

namespace FattyMenu {
    CConfigSettingsPanel::CConfigSettingsPanel(SUserConfig& a_user_config)
		: m_user_config(a_user_config) {

	}

	void CConfigSettingsPanel::OnRender(bool* a_p_open) {
        if (!a_p_open || !*a_p_open) { return; } // Nullptr or false

        if (ImGui::Begin("Settings", a_p_open)) {
            auto& panels = m_user_config.m_panel_state_config;
            auto& images = m_user_config.m_image_config;

            if (ImGui::CollapsingHeader("Panel & Overlay Settings", ImGuiTreeNodeFlags_DefaultOpen)) {
                ImGui::Checkbox("Show Civil Protection SOP",        &panels.m_open_cpsop_panel);
                ImGui::Checkbox("Show Location Readout",            &panels.m_open_location_readout_panel);
                ImGui::Checkbox("Show Notepad",                     &panels.m_open_notepad_panel);
                ImGui::Checkbox("Show Distribution Permit Info",    &panels.m_open_permit_panel);
                ImGui::Checkbox("Show Voiceline Library",           &panels.m_open_voiceline_library_panel);
                
                ImGui::Separator();

                ImGui::Checkbox("Show Version Overlay",             &panels.m_open_version_overlay);
                ImGui::Checkbox("Show Credits",                     &panels.m_open_credits_panel);
            }

            if (ImGui::CollapsingHeader("Image Settings", ImGuiTreeNodeFlags_DefaultOpen)) {
                ImGui::SliderFloat("CPSOP Logo Scale",              &images.m_cpsop_image_scale,            0.1f, 1.0f);
                ImGui::SliderFloat("Location Readout Scale",        &images.m_location_readout_image_scale, 0.1f, 1.0f);
            }
        }
        ImGui::End();
	}
}