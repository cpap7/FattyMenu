#pragma once

#include "../../Serialization/VoicelineLookupTable.h"
#include "../GUIUtilities.h"
#include "../Panel.h"

#include <../imgui/imgui.h>

#include <vector>
#include <functional>

namespace FattyMenu {
	class CVoicelineLibraryPanel : public IPanel {
	public:
		CVoicelineLibraryPanel()	= default;
		~CVoicelineLibraryPanel()	= default;

		virtual void OnRender(bool* a_p_open) override;

	private:
		void DisplayVoicelineLibraryHeader();
		void DisplaySearchFilterControls();
		void DisplayVoicelines();

	};
}