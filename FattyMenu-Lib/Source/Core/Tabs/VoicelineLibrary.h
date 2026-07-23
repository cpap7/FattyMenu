#pragma once

#include "../Voicelines/VoicelineLookupTable.h"
#include "../../GUIUtilities.h"

#include <../imgui/imgui.h>

#include <vector>
#include <functional>

namespace FattyMenu {
	namespace VoicelineLibrary {
		/* Function prototypes */

		void DisplaySearchFilterControls();
		void DisplayVoicelines();
		
		void RenderVoicelineLibraryMenu();
	}	
}