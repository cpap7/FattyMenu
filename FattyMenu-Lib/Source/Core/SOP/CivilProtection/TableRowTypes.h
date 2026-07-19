#pragma once
#include <string>
#include <vector>

// For SOP tables
namespace FattyMenu {

	struct SPolitiScheduleRow {
		std::string m_time_started	= "";
		std::string m_time_end		= "";
		std::string m_mandate		= "";
		std::string m_length		= "";
	};

	// Optional note for violation rows
	enum class EViolationNote : uint16_t {
		None,						// Plain description
		SanctionedDistribution,		// Append yellow "*"
		FirearmsCharge				// Append red "*"
	};

	struct SViolationRow { // TODO: Considering using CCode definitions from CPSOPLookupTables.h
		std::string m_code			= "";
		std::string m_violation		= "";
		std::string m_description	= "";
		EViolationNote m_note		= EViolationNote::None;
	};

	struct SViolationLevelRow {
		// NOTE: Column members here are ordered largest-to-smallest to minimize padding 
		// 24 + 8 + 4 = 36 bytes, padded to 40 bytes on 64-bit architecture, using MSVC & its standard release settings
		std::vector<const char*> m_recommended_verdicts{};
		const char* m_description	= "";
		int m_level					= 0;

		// The constructor only exists here so each row can be instantiated in SOP order (level -> description -> verdicts) independent of the physical member layout above
		// NOTE: members are initialized in DECLARATION order, so the init-list below matches it (avoids MSVC C5038)
		SViolationLevelRow(int a_level, const char* a_description, const std::vector<const char*>& a_recommended_verdicts) 
			: m_recommended_verdicts(a_recommended_verdicts), m_description(a_description), m_level(a_level) {


			// Alternatively, the constructor could be removed altogether, and the struct's members could be listed as:
			// int, const char* and std::vector<const char*> without breaking how they're already being initialized
			// It would still be 40 bytes either way on a 64-bit architecture using standard MSVC release settings 
			// but I'd consider this to be a better practice
		}
	};

	struct SCommunalRow {
		std::string m_area = "";
		std::string m_capacity = "";
	};
	
	// For the location authorization tables
	struct SLocationAuthorizationEntry {
		std::string m_index								= "";
		bool m_requires_civil_protection_supervision	= false;		// For infestation and engineer core non/patrol regions
		bool m_requires_special_authorization			= false;		// For civil protection non-patrol regions
	};

	struct SLocationAuthorizationRow {
		SLocationAuthorizationEntry m_location{};
		SLocationAuthorizationEntry m_civic_populace{};
		SLocationAuthorizationEntry m_engineer_core{};
		SLocationAuthorizationEntry m_infestation_control{};
		SLocationAuthorizationEntry m_civil_protection{};
	};

	// For the override code table
	struct SOverrideCodeRow {
		// Columns = Status | Sociostable | Unrest | Containment | Lockdown
		// Each member contains row data to be displayed under each column 
		std::string m_status_index		= "";
		std::string m_sociostable_index = "";
		std::string m_unrest_index		= "";
		std::string m_containment_index = "";
		std::string m_lockdown_index	= "";

		bool m_is_unrest				= false;
		bool m_weapon_raised			= false;
	};

}