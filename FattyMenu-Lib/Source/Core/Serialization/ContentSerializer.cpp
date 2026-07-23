#include "ContentSerializer.h"
#include "../Voicelines/Voiceline.h"

#include <../json/json.hpp>

#include <fstream>
#include <utility>
#include <filesystem>

namespace FattyMenu {
	void CContentSerializer::SerializeVoicelines(const std::vector<CVoiceline>& a_voiceline_list, const std::string& a_file_path) {
		nlohmann::json json_output;
		auto& voicelines_node = json_output["Voicelines"];
		for (const auto& voiceline : a_voiceline_list) {
			nlohmann::json voiceline_entry;

			voiceline_entry["Command"]			= voiceline.GetCommand();
			voiceline_entry["FullVoiceline"]	= voiceline.GetFullVoiceline();
			voiceline_entry["Factions"]			= FactionMaskToStrings(voiceline.GetFactions());

			voicelines_node.push_back(std::move(voiceline_entry));
		}

		const std::filesystem::path output_path = a_file_path; // Written relative to the process working directory where gmod.exe lives
		
		int indent_spacing = 4;

		std::ofstream json_filestream(output_path);
		json_filestream << json_output.dump(indent_spacing);
	}

	std::vector<CVoiceline> CContentSerializer::DeserializeVoicelines(const std::string& a_file_path) {
		std::vector<CVoiceline> voiceline_list{};
		
		const std::filesystem::path input_path = a_file_path;

		std::ifstream input_file(input_path);
		if (!input_file.is_open()) {
			return voiceline_list;
		}

		nlohmann::json json_input;
		input_file >> json_input;

		if (json_input.contains("Voicelines")) {
			for (const auto& voiceline_entry : json_input["Voicelines"]) {
				CVoiceline voiceline;
				
				voiceline.SetCommand(voiceline_entry["Command"].get<std::string>());
				voiceline.SetFullVoiceline(voiceline_entry["FullVoiceline"].get<std::string>());

				// NOTE: JSON arrays can convert directly to std::vector<std::string>
				const auto faction_names = voiceline_entry["Factions"].get<std::vector<std::string>>();
				voiceline.SetFactions(FactionMaskFromStrings(faction_names));

				voiceline_list.push_back(std::move(voiceline));
			}
		}

		return voiceline_list;
	}
}