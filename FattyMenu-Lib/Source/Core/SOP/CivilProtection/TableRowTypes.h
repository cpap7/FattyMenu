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
		int m_level					= 0;
		const char* m_description	= "";
		std::vector<const char*> m_recommended_verdicts{};
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