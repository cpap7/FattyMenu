#include "Map.h"


namespace FattyMenu {
	// Colors used for highlighting text in some cases
	static ImVec4 s_red_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

	void Map::LoadAndDisplayMapTexture() {
		static float image_scale{ 0.75f };
		static CTexture2D map(c_map_image_file_path);

		if (ImGui::CollapsingHeader("Image Settings")) {
			ImGui::SliderFloat("Image Scale", &image_scale, 0.1f, 1.0f);
		}

		ImGui::Separator();

		if (ImGui::BeginChild("Map", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), ImGuiChildFlags_Border)) {
			// Fallback for loading via manual map injection (it won't resolve the file path right away)
			if (!GUI::Helpers::DrawCenteredTexture(map, &image_scale)) {
				ImGui::Text("Texture File Path: %s", map.GetFilePath().c_str());
				ImGui::Text("Expected File Path: %s", c_map_image_file_path);
				if (ImGui::Button("Refresh")) {
					map.UpdatePathAndReload(c_map_image_file_path);
				}
			}
			ImGui::EndChild();
		}
	}

	void Map::RenderMap() {
		LoadAndDisplayMapTexture();
	}

}