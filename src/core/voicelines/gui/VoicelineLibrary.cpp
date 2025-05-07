#include "VoicelineLibrary.h"


/* Function for displaying a list of voicelines,
* alongside buttons to save the trigger text
* to the user's clipboard
* 
* @param vl_list -> vector containing Voicelines to be looped through; each trigger text is displayed in a button with the description next to it
*/
void VoicelineLibrary::DisplayVoicelines(std::vector<CVoiceline> vl_list) {
	// Display necessary instructions to the user
	ImGui::TextWrapped("Click a button to save the voiceline's trigger text to your clipboard.\n\n");

	ImGui::TextWrapped("\n\t\tTRIGGER TEXT\t\t\tFull Voiceline Description");
	ImGui::Separator();
	// Loop through all of the lines in a vector list
	for (const auto& voiceline : vl_list) {
		// Create a button displaying the trigger text, using the predefined button width (200.0f)
		if (ImGui::Button(voiceline.GetTriggerText(), ImVec2(button_width, 0))) {
			ImGui::SetClipboardText(voiceline.GetTriggerText());  // Set clipboard to the trigger text if button is clicked
		}

		//  Ensure the description and button are on the same line
		ImGui::SameLine(); 

		// Adjust position for description and make sure it fits the remaining space
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.0f);	  // Add a small padding between the button and the text

		// Display the description
		ImGui::TextWrapped("%s", voiceline.GetVoicelineDescription());
	}
}

/* Helper function for rendering colored headers 
* @param header_label -> string for labelling the collapsing header
* @param VL_LIST -> address of the vector of voicelines being displayed
* @param SetHeaderColor() -> placeholder for function call to change the color of the collapsing header 
*/
void VoicelineLibrary::RenderColoredHeader(const char* header_label, const std::vector<CVoiceline>& VL_LIST, std::function<void()> SetHeaderColor) {
	SetHeaderColor(); // Push style color

	if (ImGui::CollapsingHeader(header_label)) {
		GUIUtils::PopColorStack();  // Pop style if header opened
		VoicelineLibrary::DisplayVoicelines(VL_LIST);
	}
	else {
		GUIUtils::PopColorStack();  // Pop style if header NOT opened
	}
}

/* Function for rendering the menu in the tab */
void VoicelineLibrary::RenderVoicelineLibraryMenu() {
	RenderColoredHeader("View Male Citizen Voicelines", male_citizen_vl_list, GUIUtils::SetHeaderColorBlue);
	RenderColoredHeader("View Female Citizen Voicelines", female_citizen_vl_list, GUIUtils::SetHeaderColorBlue);
	RenderColoredHeader("View Civil Protection Voicelines", cp_vl_list, GUIUtils::SetHeaderColorCyan);
	RenderColoredHeader("View Transhuman Grunt Voicelines", tf_grunt_vl_list, GUIUtils::SetHeaderColorYellow);
	RenderColoredHeader("View Airwatch Voicelines", airwatch_vl_list, GUIUtils::SetHeaderColorRed);
	RenderColoredHeader("View Vortigaunt Voicelines", vortigaunt_vl_list, GUIUtils::SetHeaderColorGreen);
}