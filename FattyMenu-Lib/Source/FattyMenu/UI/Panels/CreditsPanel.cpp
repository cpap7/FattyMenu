#include "CreditsPanel.h"

namespace FattyMenu {

	void CCreditsPanel::OnRender(bool* a_p_open) {
		if (!a_p_open || !*a_p_open) { return; } // Check if it's nullptr or false 

		if (ImGui::Begin("Credits", a_p_open)) {
			DisplayCredits();
		}
		ImGui::End();
	}

	void CCreditsPanel::DisplayCredits() {
		ImGui::TextWrapped("Internal menu created by:");
		GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, "JoeRogaine on Discord aka cpap7 on Github");

		ImGui::Separator();

		if (ImGui::BeginChild("##Credits", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), ImGuiChildFlags_Borders)) {
			ImGui::TextWrapped("Special thanks to the following people for their help:");
			
			ImGui::TextWrapped("General Assistance");
			GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "MajoraPLZ: for helping me find the right people to ask for info, and answering any questions I had");
			GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "Cazzette: for providing feedback, and also helping me find people to ask for info");
			GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "voprositelnii: for providing TAC usage etiquette and duty expectations");

			ImGui::Separator();

			ImGui::TextWrapped("SOP Files");
			GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "Rommel & Cazzette for sending me the SOP PDF files");

			ImGui::Separator();

			ImGui::TextWrapped("Voiceline Data");
			GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "-Broken-");
			GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "Recker");

			ImGui::Separator();

			ImGui::TextWrapped("Frontend Programming Assistance");
			GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "@fblawyer on Discord");

			ImGui::EndChild();
		}
	}

	
}