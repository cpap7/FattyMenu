#pragma once

// Lambda functions
#include <functional>
#include <string>

// GUI utils
#include "../../GUIUtilities.h"

// ImGui dependencies
#include <../imgui/imgui.h>

// Lookup tables
#include "../SOP/CivilProtection/CPSOPLookupTables.h"

/* TODO:
	- Fix jank code I made for prototyping, replace it with lambda function calls to the template function in GUIUtilities.h, which is easier to maintain
*/
namespace FattyMenu {
	namespace CPSOP {
		/* Function Prototypes */
		// For displaying Civil Protection's logo (ASCII)
		void DisplayCPLogo();

		// For displaying 10-, 11-, and response codes
		void DisplayCPCodes(const std::vector<CCode>& a_codes);

		// For displaying citizen rewards
		void DisplayCPRewardInfo(const std::vector<CCivicReward>& a_civic_rewards);

		// For displaying citizen types and interaction directives
		void DisplayCPInteractionDirectives(const std::vector<CCivilStatus>& a_civil_status_list);

		// For displaying terminology index
		//void DisplayCPTerms(const std::vector<CTerm>& a_terms);

		// For displaying politi-schedule
		void DisplayCPPolitiSchedule(const std::vector<CPolitiSchedule>& a_politi_schedule);
<<<<<<< HEAD
=======
		
		// For the override code table
		struct SOverrideCodeRow {
			// Columns = Status | Sociostable | Unrest | Containment | Lockdown
			// Each member contains row data to be displayed under each column 
			const char* m_status_index		= "";
			const char* m_sociostable_index = "";
			const char* m_unrest_index		= "";
			const char* m_containment_index = "";
			const char* m_lockdown_index	= "";
		};
>>>>>>> ecef8188b09284b7cf37e1795ef91ef75fbfe27e

		// For displaying override code table
		void DisplayOverrideCodeTable();

<<<<<<< HEAD
=======
		struct SViolationLevelRow {
			int m_level					= 0;
			const char* m_description	= "";
			std::vector<const char*> m_recommended_verdicts{};
		};

		// For displaying violation levels table
		void DisplayViolationLevelsTable();
>>>>>>> ecef8188b09284b7cf37e1795ef91ef75fbfe27e

		// For displaying mandate and assignment duties, alongside relevant misc info
		//void DisplayCPDuties(const std::vector<CAssignment>& a_assignments);

		// For displaying the contraband index
		void DisplayCPContrabandIndex(const std::vector<CContraband>& a_contraband_index);

		// For the location authorization tables
		struct SLocationAuthorizationEntry {
			std::string m_index = "";
			bool m_requires_civil_protection_supervision = false; // For infestation and engineer core non/patrol regions
			bool m_requires_special_authorization = false;       // For civil protection non-patrol regions
		};

		struct SLocationAuthorizationRow {
			SLocationAuthorizationEntry m_location;
			SLocationAuthorizationEntry m_civic_populace;
			SLocationAuthorizationEntry m_engineer_core;
			SLocationAuthorizationEntry m_infestation_control;
			SLocationAuthorizationEntry m_civil_protection;
		};

		struct SViolationLevelRow {
			int m_level = 0;
			const char* m_description = "";
			std::vector<const char*> m_recommended_verdicts{};
		};

		struct SViolationCivicTrustCodeRow {
			const char* m_code = "";
			const char* m_violation = "";
			const char* m_description = "";
			bool m_sanctioned_distribution = false; // Mark it with an asterisk to indicate that it's only sanctioned in certain areas

		};
		struct SViolationCivilWillRow {
			const char* m_code = "";
			const char* m_violation = "";
			const char* m_description = "";
		};

		struct SViolationCommunalUnrestRow {
			const char* m_code = "";
			const char* m_violation = "";
			const char* m_description = "";
		};

		struct SViolationDisiveSociocidalRow {
			const char* m_code = "";
			const char* m_violation = "";
			const char* m_description = "";
		};

		// For displaying violation code, name and description
		void DisplayViolationCivicTrustTable();
		void DisplayViolationCivilWillTable();
		void DisplayViolationCommunalUnrestTable();
		void DisplayViolationDisiveSociocidalTable();
		// For displaying violation levels table
		void DisplayViolationLevelsTable();

		void DisplayPatrolRegions();
		void DisplayNonPatrolRegions();

		// For displaying the SOP tabs and logo
		void RenderCivilProtectionSOP();

	}
}