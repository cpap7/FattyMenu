#include "VoicelineScraper.h"
#include "Voiceline.h"

#include <html_parser.hpp>
#include <json.hpp>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace FattyMenu {
	// Broken's site URL
	constexpr const char* c_voicelines_site = "https://synapse-voicelines.brokenlab.live";

	// String variables representing html classes on Broken's site
	constexpr const char* c_list_item_class		= "list-item";	// Repeating container
	constexpr const char* c_command_class		= "command";	// <div class="command">	- contains input text to trigger voiceline
	constexpr const char* c_voiceline_class		= "voiceline";	// <div class="voiceline">	- contains the full voiceline
	constexpr const char* c_faction_class		= "faction";	// <div class="faction">	- contains the factions that the voiceline belongs to

	// HTML file I/O & string parsing utilities
	namespace Utilities {
		std::string ReadFile(const std::string& a_file_path) {
			std::ifstream input(a_file_path, std::ios::binary);
			std::ostringstream string_stream;
			string_stream << input.rdbuf();

			return string_stream.str();
		}

		std::string Trim(const std::string& a_string) {
			const size_t first = a_string.find_first_not_of(" \t\r\n"); // Handle trailing \r on windows
			const size_t last = a_string.find_last_not_of(" \t\r\n");
			return (first == std::string::npos) ? "" : a_string.substr(first, last - first + 1);
		}

		// Used for trimming white space between faction names
		// This is important for the EFaction's string functions
		std::string StripWhiteSpace(const std::string& a_string) {
			std::string result{};
			for (char character : a_string) {
				if (character != '\t' && character != '\r' && character != '\n') {
					result += character;
				}
			}

			return result;
		}

		std::string ChildText(const std::shared_ptr<HtmlElement>& a_list_item, const char* a_class) {
			auto matches = a_list_item->GetElementByClassName(a_class);
			if (matches.empty()) {
				return "";
			}
			return Trim(matches.front()->GetValue());
		}

		EFaction ParseFactionList(const std::string& a_list) {
			EFaction faction = EFaction::None;

			size_t start = 0;
			while (start < a_list.size()) {
				size_t comma = a_list.find(',', start);
				if (comma == std::string::npos) {
					comma = a_list.size();
				}

				const std::string token = StripWhiteSpace(a_list.substr(start, comma - start));
				if (!token.empty()) {
					faction |= FactionFromString(token);
				}
				start = comma + 1;
			}

			return faction;
		}

	}

	std::string CVoicelineScraper::FetchHTML() {
		httplib::Client client(c_voicelines_site);
		client.set_follow_location(true);
		
		auto result = client.Get("/");

		return (result && result->status == 200) ? result->body : std::string{};
	}

	bool CVoicelineScraper::DownloadHTMLToFile(const std::string& a_out_html_path) {
		std::error_code error_code;
		if (std::filesystem::exists(a_out_html_path, error_code) && !error_code) {
			return true; // Already exists, nothing to do
		}

		const std::string html = FetchHTML();
		if (html.empty()) {
			return false;
		}

		std::ofstream output(a_out_html_path, std::ios::binary);
		if (!output) {
			return false;
		}

		output.write(html.data(), static_cast<std::streamsize>(html.size()));
		return output.good();		
	}

	void CVoicelineScraper::ScrapeFromHTMLFile(const std::string& a_html_path, const std::string& a_out_path) {
		const std::string html_file = Utilities::ReadFile(a_html_path);
		if (html_file.empty()) {
			return;
		}

		HtmlParser parser;
		std::shared_ptr<HtmlDocument> doc = parser.Parse(html_file);
		if (!doc) {
			return;
		}

		// Grab every voiceline list item
		auto list_items = doc->GetElementByClassName(c_list_item_class);

		nlohmann::json root;
		auto& voicelines_node = root["Voicelines"];
		for (const auto& list_item : list_items) {
			const std::string command	= Utilities::ChildText(list_item, c_command_class);
			const std::string voiceline = Utilities::ChildText(list_item, c_voiceline_class);
			const std::string factions	= Utilities::ChildText(list_item, c_faction_class);

			if (command.empty()) {
				continue;
			}

			const EFaction faction_mask = Utilities::ParseFactionList(factions);

			nlohmann::json entry;
			entry["Command"]		= command;
			entry["FullVoiceline"]	= voiceline;
			entry["Factions"]		= FactionMaskToStrings(faction_mask); // Stored as vector of strings
			voicelines_node.push_back(std::move(entry));
		}
		
		int indent_spacing = 4;
		std::ofstream output(a_out_path);
		output << root.dump(indent_spacing);
	}
}