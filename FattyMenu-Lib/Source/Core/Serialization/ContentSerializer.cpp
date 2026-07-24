#include "ContentSerializer.h"

#include "../Voicelines/Voiceline.h"
#include "../DistributionPermit/Permit.h"

#include <../json/json.hpp>

#include <fstream>
#include <utility>
#include <filesystem>

namespace FattyMenu {
	void CContentSerializer::SerializeVoicelines(const std::vector<CVoiceline>& a_voiceline_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& voicelines_node = json_output["Voicelines"];
		for (const auto& voiceline : a_voiceline_list) {
			nlohmann::ordered_json voiceline_entry;

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

	void CContentSerializer::SerializePermitInfo(const std::vector<CPermit>& a_permit_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& permits_node = json_output["Permits"];

		for (const auto& permit : a_permit_list) {
			nlohmann::ordered_json permit_entry;

			permit_entry["Name"]					= permit.GetPermitName();
			permit_entry["CivicPointRequirement"]	= permit.GetCivicPointRequirement();
			permit_entry["Cost"]					= permit.GetPermitCost();

			// Serialize package info
			auto& packages_node = permit_entry["Packages"];
			for (const auto& package : permit.GetPackages()) {
				nlohmann::ordered_json package_entry;

				package_entry["Name"] = package.GetName();
				package_entry["Cost"] = package.GetCost();
				package_entry["ItemQuantity"] = package.GetQuantity();

				packages_node.push_back(std::move(package_entry));
			}
			permit_entry["AuthorizedItems"]			= permit.GetAuthorizedItems();

			permits_node.push_back(std::move(permit_entry));
		}

		const std::filesystem::path output_path = a_file_path; 

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
	
	std::vector<CPermit> CContentSerializer::DeserializePermitInfo(const std::string& a_file_path) {
		std::vector<CPermit> permit_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return permit_list; // Empty on missing file
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("Permits")) {
			for (const auto& permit_entry : json_input["Permits"]) {
				// NOTE: .value(key, fallback) - won' throw if key is absent
				CPermit permit;
				permit.SetPermitName(permit_entry["Name"].get<std::string>());
				permit.SetCivicPointRequirement(permit_entry["CivicPointRequirement"].get<int>());
				permit.SetPermitCost(permit_entry["Cost"].get<int>());

				// Populate packages
				std::vector<CPackage> packages{};
				if (permit_entry.contains("Packages")) {
					for (const auto& package_entry : permit_entry["Packages"]) {
						CPackage package;
						package.SetName(package_entry["Name"].get<std::string>());
						package.SetCost(package_entry["Cost"].get<int>());
						package.SetQuantity(package_entry["ItemQuantity"].get<int>()); // Default = 5 on construction

						packages.push_back(std::move(package));
					}
				}
				permit.SetPackages(packages);

				if (permit_entry.contains("AuthorizedItems")) {
					permit.SetAuthorizedItems(permit_entry["AuthorizedItems"].get<std::vector<std::string>>());
				}

				permit_list.push_back(std::move(permit));
			}
		}
		
		return permit_list;
	}
}