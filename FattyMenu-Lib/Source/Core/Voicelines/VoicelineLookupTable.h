#pragma once

#include "../Serialization/ContentSerializer.h"
#include "VoicelineScraper.h"
#include "Voiceline.h"

#include <vector>
#include <string>

namespace FattyMenu {
	/* Look-up Table */

	const std::string c_voicelines_file_path = "FattyMenu/FattyMenu_Voicelines.json"; // Relative to gmod.exe
	const std::string c_html_output_path = "Project_ Synapse Voicelines.htm";

	// Returns a mutable list of voicelines that are loaded from a JSON file
	inline std::vector<CVoiceline>& GetVoicelines() {
		static std::vector<CVoiceline> voiceline_list = 
			[] {
				CContentSerializer serializer;
				return serializer.DeserializeVoicelines(c_voicelines_file_path);	
			}();

		return voiceline_list;
	}

	// Downloads an html file, scrapes data from the local HTML file, then writes to a JSON and reloads the in-memory voicelines vector
	inline void RefreshVoicelines() {
		CVoicelineScraper scraper;
		if (!std::filesystem::exists(c_html_output_path)) {
			scraper.DownloadHTMLToFile(c_html_output_path);
		}
		scraper.ScrapeFromHTMLFile(c_html_output_path, c_voicelines_file_path);
		
		// Update mutable lookup table
		CContentSerializer serializer;
		GetVoicelines() = serializer.DeserializeVoicelines(c_voicelines_file_path);
	}
}