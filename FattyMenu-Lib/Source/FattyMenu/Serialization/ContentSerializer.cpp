#include "ContentSerializer.h"

#include "../Voicelines/Voiceline.h"
#include "../DistributionPermit/Permit.h"

// SOP
#include "../SOP/Code.h"
#include "../SOP/Term.h"
#include "../SOP/Assignment.h"
#include "../SOP/CivicReward.h"
#include "../SOP/CivilStatus.h"
#include "../SOP/Contraband.h"

#include <../json/json.hpp>

#include <fstream>
#include <utility>
#include <filesystem>

namespace FattyMenu {
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
				// TODO: consider using .value(key, fallback) - won't throw if key is absent
				CPermit permit{};
				permit.SetPermitName(permit_entry["Name"].get<std::string>());
				permit.SetCivicPointRequirement(permit_entry["CivicPointRequirement"].get<uint16_t>());
				permit.SetPermitCost(permit_entry["Cost"].get<uint16_t>());

				// Populate packages
				std::vector<CPackage> packages{};
				if (permit_entry.contains("Packages")) {
					for (const auto& package_entry : permit_entry["Packages"]) {
						CPackage package;
						package.SetName(package_entry["Name"].get<std::string>());
						package.SetCost(package_entry["Cost"].get<uint16_t>());
						package.SetQuantity(package_entry["ItemQuantity"].get<uint16_t>()); // Default = 5 on construction

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

	std::vector<CCode> CContentSerializer::DeserializeCodes(const std::string& a_file_path) {
		std::vector<CCode> codes_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return codes_list; // Empty on missing file
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("Codes")) {
			for (const auto& code_entry : json_input["Codes"]) {
				CCode code;

				code.SetName(code_entry["Name"].get<std::string>());
				code.SetDescription(code_entry["Description"].get<std::string>());
				code.SetCodeType(CodeTypeFromString(code_entry["CodeType"].get<std::string>()));

				if (code.IsViolationCode()) {
					code.SetViolationDescription(code_entry["ViolationCodeDescription"].get<std::string>());
					code.SetViolationCodeNote(ViolationCodeNoteFromString(code_entry["ViolationCodeNote"].get<std::string>()));
				}
				else if (code.IsOverrideCode()) {
					code.SetOverrideDescription(code_entry["OverrideCodeDescription"].get<std::vector<std::string>>());
					code.SetOverrideDirectives(code_entry["OverrideCodeDirectives"].get<std::vector<std::string>>());
				}

				codes_list.push_back(std::move(code));
			}
		}

		return codes_list;
	}

	std::vector<CViolationCodeCategory> CContentSerializer::DeserializeViolationCodeCategories(const std::string& a_file_path) {
		std::vector<CViolationCodeCategory> violation_code_categories_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return violation_code_categories_list;
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("ViolationCodeCategories")) {
			for (const auto& category_entry : json_input["ViolationCodeCategories"]) {
				CViolationCodeCategory category;

				category.SetName(category_entry["Name"].get<std::string>());
				category.SetDescription(category_entry["Description"].get<std::string>());
				category.SetTableID(category_entry["TableID"].get<std::string>());
				category.SetFootnote(category_entry["Footnote"].get<std::string>());

				// NOTE: Violation codes come from a per-category code file that's loaded on refresh (See RefreshViolationCategories() in CPSOPLookupTables.h)

				violation_code_categories_list.push_back(std::move(category));
			}
		}

		return violation_code_categories_list;
	}

	std::vector<CTerm> CContentSerializer::DeserializeTerms(const std::string& a_file_path) {
		std::vector<CTerm> terms_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return terms_list; // Empty on missing file
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("Terms")) {
			for (const auto& term_entry : json_input["Terms"]) {
				CTerm term;

				term.SetName(term_entry["Name"].get<std::string>());
				term.SetDescription(term_entry["Description"].get<std::string>());

				terms_list.push_back(std::move(term));
			}
		}

		return terms_list;
	}

	std::vector<CCivicReward> CContentSerializer::DeserializeCivicRewardInfo(const std::string& a_file_path) {
		std::vector<CCivicReward> civic_rewards_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return civic_rewards_list; // Empty on missing file
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("CivicRewards")) {
			for (const auto& civic_reward_entry : json_input["CivicRewards"]) {
				CCivicReward civic_reward;

				civic_reward.SetNumber(civic_reward_entry["Number"].get<std::string>());
				civic_reward.SetDescription(civic_reward_entry["Description"].get<std::string>());

				civic_rewards_list.push_back(std::move(civic_reward));
			}
		}

		return civic_rewards_list;
	}

	std::vector<CCivilStatus> CContentSerializer::DeserializeCivilStatusInfo(const std::string& a_file_path) {
		std::vector<CCivilStatus> civil_status_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return civil_status_list; // Empty on missing file
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("CivilStatuses")) {
			for (const auto& civil_status_entry : json_input["CivilStatuses"]) {
				CCivilStatus civil_status;

				civil_status.SetStatusType(civil_status_entry["StatusType"].get<std::string>());
				civil_status.SetCivicPointRange(civil_status_entry["CivicPointRange"].get<std::string>());
				civil_status.SetStatusDefinition(civil_status_entry["StatusDefinition"].get<std::string>());
				civil_status.SetAdministrativeDirectives(civil_status_entry["AdministrativeDirectives"].get<std::vector<std::string>>());

				civil_status_list.push_back(std::move(civil_status));
			}
		}

		return civil_status_list;
	}

	std::vector<CContraband> CContentSerializer::DeserializeContrabandInfo(const std::string& a_file_path) {
		std::vector<CContraband> contraband_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return contraband_list; // Empty on missing file
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("ContrabandTypes")) {
			for (const auto& contraband_entry : json_input["ContrabandTypes"]) {
				CContraband contraband;

				// Populate nested violation code
				const auto& code_entry = contraband_entry["ViolationCode"];
				CCode code;
				code.SetName(code_entry["Name"].get<std::string>());
				code.SetDescription(code_entry["Description"].get<std::string>());
				code.SetViolationDescription(code_entry["ViolationCodeDescription"].get<std::string>());
				code.SetViolationCodeNote(ViolationCodeNoteFromString(code_entry["ViolationCodeNote"].get<std::string>()));
				code.SetCodeType(CodeTypeFromString(code_entry["CodeType"].get<std::string>()));

				contraband.SetViolationCode(code);
				contraband.SetExamples(contraband_entry["Examples"].get<std::vector<std::string>>());

				contraband_list.push_back(std::move(contraband));
			}

		}

		return contraband_list;
	}

	std::vector<CAssignment> CContentSerializer::DeserializeAssignmentInfo(const std::string& a_file_path) {
		std::vector<CAssignment> assignment_list{};

		std::ifstream json_filestream(a_file_path);
		if (!json_filestream.is_open()) {
			return assignment_list; // Empty on missing file
		}

		nlohmann::json json_input;
		json_filestream >> json_input;

		if (json_input.contains("Assignments")) {
			for (const auto& assignment_entry : json_input["Assignments"]) {
				CAssignment assignment{};
				assignment.SetAssignmentName(assignment_entry["Name"].get<std::string>());
				assignment.SetAssignmentType(AssignmentTypeFromString(assignment_entry["Type"].get<std::string>()));

				if (assignment.IsForCP()) { // Based on assignment type
					assignment.SetCPUnitsRequired(assignment_entry["CPUnitsRequired"].get<std::string>());
				}
				else if (assignment.IsForTF()) {
					assignment.SetTFUnitsRequired(assignment_entry["TFUnitsRequired"].get<uint16_t>());
					assignment.SetTFShiftDuration(assignment_entry["TFShiftDuration"].get<uint16_t>());
					assignment.SetTFRecommendedClass(assignment_entry["TFRecommendedClass"].get<std::string>());
				}
				assignment.SetAssignmentDescription(assignment_entry["Description"].get<std::vector<std::string>>());

				assignment_list.push_back(std::move(assignment));
			}
		}

		return assignment_list;
	}

#ifdef FM_DEBUG
	// Constants
	const int c_indent_spacing{ 4 }; // Used for making the JSON output "prettier"

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
		
		std::ofstream json_filestream(std::filesystem::path{ a_file_path }); // Written relative to the process working directory where gmod.exe lives
		json_filestream << json_output.dump(c_indent_spacing);
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

		std::ofstream json_filestream(std::filesystem::path{a_file_path});
		json_filestream << json_output.dump(c_indent_spacing);
	}

	void CContentSerializer::SerializeCodes(const std::vector<CCode>& a_codes_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& codes_node = json_output["Codes"];

		for (const auto& code : a_codes_list) {
			nlohmann::ordered_json code_entry;

			code_entry["Name"]							= code.GetName();
			code_entry["Description"]					= code.GetDescription();
			code_entry["CodeType"]						= CodeTypeToString(code.GetCodeType());

			if (code.IsViolationCode()) {
				code_entry["ViolationCodeDescription"]	= code.GetViolationDescription();
				code_entry["ViolationCodeNote"]			= ViolationCodeNoteToString(code.GetViolationCodeNote());
			}
			else if (code.IsOverrideCode()) {
				code_entry["OverrideCodeDescription"]	= code.GetOverrideDescription();
				code_entry["OverrideCodeDirectives"]	= code.GetOverrideDirectives();
			}

			codes_node.push_back(std::move(code_entry));
		}
		
		std::ofstream json_filestream(std::filesystem::path{ a_file_path });
		json_filestream << json_output.dump(c_indent_spacing);
	}

	void CContentSerializer::SerializeViolationCategories(const std::vector<CViolationCodeCategory>& a_categories_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& violation_categories_node = json_output["ViolationCodeCategories"];

		for (const auto& category : a_categories_list) {
			nlohmann::ordered_json category_entry;

			// Serialize metadata
			category_entry["Name"]			= category.GetName();
			category_entry["Description"]	= category.GetDescription();
			category_entry["TableID"]		= category.GetTableID();
			category_entry["Footnote"]		= category.GetFootnote();

			// NOTE: Violation codes are NOT serialized or stored here
			// They come from a per-category code file that's loaded on refresh (See RefreshViolationCategories() in CPSOPLookupTables.h)

			violation_categories_node.push_back(std::move(category_entry));
		}

		std::ofstream json_filestream(std::filesystem::path{ a_file_path });
		json_filestream << json_output.dump(c_indent_spacing);
	}
	
	void CContentSerializer::SerializeTerms(const std::vector<CTerm>& a_terms_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& terms_node = json_output["Terms"];

		for (const auto& term : a_terms_list) {
			nlohmann::ordered_json term_entry;

			term_entry["Name"]			= term.GetName();
			term_entry["Description"]	= term.GetDescription();

			terms_node.push_back(std::move(term_entry));
		}

		std::ofstream json_filestream(std::filesystem::path{ a_file_path });
		json_filestream << json_output.dump(c_indent_spacing);
	}

	void CContentSerializer::SerializeCivicRewardInfo(const std::vector<CCivicReward>& a_civic_rewards_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& civic_rewards_node = json_output["CivicRewards"];

		for (const auto& civic_reward : a_civic_rewards_list) {
			nlohmann::ordered_json civic_reward_entry;

			civic_reward_entry["Number"]		= civic_reward.GetNumber(); // "Number" is just a string designation
			civic_reward_entry["Description"]	= civic_reward.GetDescription();

			civic_rewards_node.push_back(std::move(civic_reward_entry));
		}

		std::ofstream json_filestream(std::filesystem::path{ a_file_path });
		json_filestream << json_output.dump(c_indent_spacing);
	}
	
	void CContentSerializer::SerializeCivilStatusInfo(const std::vector<CCivilStatus>& a_civil_status_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& civil_statuses_node = json_output["CivilStatuses"];

		for (const auto& civil_status : a_civil_status_list) {
			nlohmann::ordered_json civil_status_entry;

			civil_status_entry["StatusType"]				= civil_status.GetStatusType();
			civil_status_entry["CivicPointRange"]			= civil_status.GetCivicPointRange();
			civil_status_entry["StatusDefinition"]			= civil_status.GetStatusDefinition();
			civil_status_entry["AdministrativeDirectives"]	= civil_status.GetAdministrativeDirectives();

			civil_statuses_node.push_back(std::move(civil_status_entry));
		}

		std::ofstream json_filestream(std::filesystem::path{ a_file_path });
		json_filestream << json_output.dump(c_indent_spacing);
	}
	
	void CContentSerializer::SerializeContrabandInfo(const std::vector<CContraband>& a_contraband_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& contraband_node = json_output["ContrabandTypes"];

		for (const auto& contraband : a_contraband_list) {
			nlohmann::ordered_json contraband_entry;

			// Nested violation code
			const CCode& code = contraband.GetViolationCode();
			nlohmann::ordered_json code_entry;
			code_entry["Name"]						= code.GetName();
			code_entry["Description"]				= code.GetDescription();
			code_entry["ViolationCodeDescription"]	= code.GetViolationDescription();
			code_entry["ViolationCodeNote"]			= ViolationCodeNoteToString(code.GetViolationCodeNote());
			code_entry["CodeType"]					= CodeTypeToString(code.GetCodeType());

			contraband_entry["ViolationCode"]		= std::move(code_entry);
			contraband_entry["Examples"]			= contraband.GetExamples();   // vector<string>

			contraband_node.push_back(std::move(contraband_entry));
		}

		std::ofstream json_filestream(std::filesystem::path{ a_file_path });
		json_filestream << json_output.dump(c_indent_spacing);
	}
	
	void CContentSerializer::SerializeAssignmentInfo(const std::vector<CAssignment>& a_assignments_list, const std::string& a_file_path) {
		nlohmann::ordered_json json_output;
		auto& assignment_node = json_output["Assignments"];

		for (const auto& assignment : a_assignments_list) {
			nlohmann::ordered_json assignment_entry;

			assignment_entry["Name"]					= assignment.GetAssignmentName();
			assignment_entry["Type"]					= AssignmentTypeToString(assignment.GetAssignmentType());
			
			if (assignment.IsForCP()) {
				assignment_entry["CPUnitsRequired"]		= assignment.GetCPUnitsRequired();
			}
			else if (assignment.IsForTF()) {
				assignment_entry["TFUnitsRequired"]		= assignment.GetTFUnitsRequired();
				assignment_entry["TFShiftDuration"]		= assignment.GetTFShiftDuration();
				assignment_entry["TFRecommendedClass"]	= assignment.GetTFRecommendedClass();
			}

			assignment_entry["Description"]				= assignment.GetAssignmentDescription();

			assignment_node.push_back(std::move(assignment_entry));
		}

		std::ofstream json_filestream(std::filesystem::path{ a_file_path });
		json_filestream << json_output.dump(c_indent_spacing);
	}

#endif

	
}