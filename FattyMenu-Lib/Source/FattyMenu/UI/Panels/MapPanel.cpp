#include "MapPanel.h"


namespace FattyMenu {

	CMapPanel::CMapPanel(float* a_image_scale) 
		: m_image_scale(a_image_scale) {
		m_map_texture = std::make_unique<CTexture2D>(c_map_image_file_path);
	}

	CMapPanel::~CMapPanel() {
		m_map_texture.reset();
	}
	
	void CMapPanel::OnRender(bool* a_p_open) {
		if (!a_p_open || !*a_p_open) { return; } // Check if it's nullptr or false 

		if (ImGui::Begin("Location Readout", a_p_open)) {
			LoadMapTexture();
			DisplayMapTexture();
		}
		ImGui::End();
	}

	void CMapPanel::LoadMapTexture() {
		if (!m_map_texture->HasLoadedOK()) {
			m_map_texture->Invalidate();
		}
	}

	void CMapPanel::DisplayMapTexture() {
		if (ImGui::BeginChild("##Map", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), ImGuiChildFlags_Borders)) {
			if (!GUI::Helpers::DrawCenteredTexture(*m_map_texture, m_image_scale)) {
				// Fallback for if it won't resolve the file path right away - i.e., loading via manual map injection 
				ImGui::Text("Texture File Path: %s", m_map_texture->GetFilePath().c_str());
				ImGui::Text("Expected File Path: %s", c_map_image_file_path.c_str());
				if (ImGui::Button("Refresh")) {
					m_map_texture->UpdatePathAndReload(c_map_image_file_path);
				}
			}
			ImGui::EndChild();
		}

	}

	

}