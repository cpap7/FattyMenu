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

	struct SViolationLevelRow {
		// NOTE: The SOP doc displays them in order of level, description and verdicts 
		// Column members here are ordered largest-to-smallest to minimize padding
		// 24 + 8 + 4 = 36 bytes, padded to 40 bytes on 64-bit architecture, using MSVC & its standard release settings
		
		// The alternative is to have a constructor to force instantiation in the "correct" order for convenience, 
		// but that could open the door for a SIOF if this changes to depend on other globals after being placed in a vector

		std::vector<std::string> m_recommended_verdicts{};				// NOTE: Using std::string over const char* for frontend string comparison operations
		const char* m_description	= "";
		int m_level					= 0;
	};

	struct SResidentialBlockRow {
		std::string m_area		= "";
		std::string m_capacity	= "";
	};
	
	// For the location authorization tables
	struct SLocationAuthorizationEntry {
		std::string m_index								= "";

		// TODO: Add enum class to replace these bools - they're not exactly expressive during instantiation
		bool m_requires_civil_protection_supervision	= false;		// For infestation and engineer core non-patrol regions
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
	};

}