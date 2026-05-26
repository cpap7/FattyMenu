#pragma once

// For making lists
#include <vector>
#include <functional>

#include "../Voicelines/VoicelineLookupTable.h"

// ImGui dependencies
#include <../imgui/imgui.h>

#include "../../GUIUtilities.h" // ImGui utilities


namespace FattyMenu {
	namespace VoicelineLibrary {
		/* GUI Variables */
		const float button_width = 200.00f;	// A fixed width for buttons

		/* Function prototypes */
		void DisplayVoicelines(const std::vector<CVoiceline>& a_voiceline_list);
		void RenderColoredHeader(const char* a_header_label, const std::vector<CVoiceline>& a_voiceline_list, const std::function<void()>& a_set_header_color_callback);
		void RenderVoicelineLibraryMenu();
	}	
}