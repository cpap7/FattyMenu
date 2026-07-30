#pragma once

#include <string>
#include <mutex>
#include <future>
#include <chrono>
#include <filesystem>

namespace FattyMenu {
	
	// Helper class to scrape data from Broken's website
	// https://synapse-voicelines.brokenlab.live/
	class CVoicelineScraper {
	private: // TODO: Async + rate limiting
		//mutable std::mutex m_mutex;
		
		//std::chrono::steady_clock::time_point m_last_fetch{};

		//static constexpr auto k_min_fetch_interval	= std::chrono::seconds(60);
		//static constexpr auto k_cache_max_age		= std::chrono::hours(6);

	public:
		CVoicelineScraper()		= default;
		~CVoicelineScraper()	= default;

		std::string FetchHTML();
		bool DownloadHTMLToFile(const std::string& a_out_html_path);
		//std::future<bool> DownloadHTMLToFileAsync(const std::string& a_out_html_path);

		// Parses a locally-saved HTML dump of the site, then writes to a JSON
		void ScrapeFromHTMLFile(const std::string& a_html_path, const std::string& a_out_path);	

	};
}

