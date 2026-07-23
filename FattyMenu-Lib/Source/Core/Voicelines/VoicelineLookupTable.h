#pragma once

#include "../Serialization/ContentSerializer.h"
#include "VoicelineScraper.h"
#include "Voiceline.h"

#include <vector>
#include <string>
#include <functional>

namespace FattyMenu {
	/* Look-up Tables */

	const std::string c_voicelines_file_path = "FattyMenu_Voicelines.json"; // Relative to gmod.exe

	// Returns a mutable list of voicelines that are loaded from a JSON file
	inline std::vector<CVoiceline>& GetVoicelines() {
		static std::vector<CVoiceline> voiceline_list = 
			[] {
				CContentSerializer serializer;
				return serializer.DeserializeVoicelines(c_voicelines_file_path);	
			}();

		return voiceline_list;
	}

	// Scrapes data from local HTML file, then writes to a JSON and reloads the in-memory voicelines vector
	inline void RefreshVoicelines(const std::string& a_html_path) {
		CVoicelineScraper scraper;
		scraper.ScrapeFromHTMLFile(a_html_path, c_voicelines_file_path);
		
		// Update mutable lookup table
		CContentSerializer serializer;
		GetVoicelines() = serializer.DeserializeVoicelines(c_voicelines_file_path);
	}
}