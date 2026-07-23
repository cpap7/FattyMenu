#pragma once
#include <string>

namespace FattyMenu {
	
	// Helper class to scrape data from Broken's website
	// https://synapse-voicelines.brokenlab.live/
	class CVoicelineScraper {
	public:
		CVoicelineScraper()		= default;
		~CVoicelineScraper()	= default;

		std::string FetchHTML();

		// Parses a locally-saved HTML dump of the site, then writes to a JSON
		void ScrapeFromHTMLFile(const std::string& a_html_path, const std::string& a_out_path);
	};
}

