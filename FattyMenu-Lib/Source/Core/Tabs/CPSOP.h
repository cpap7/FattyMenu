#pragma once

// Lambda functions
#include <functional>

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
		void DisplayCPTerms(const std::vector<CTerm>& a_terms);

		// For displaying politi-schedule
		void DisplayCPPolitiSchedule(const std::vector<CPolitiSchedule>& a_politi_schedule);
		
		// For displaying override code table
		void DisplayOverrideCodeTable();

		// For displaying mandate and assignment duties, alongside relevant misc info
		void DisplayCPDuties(const std::vector<CAssignment>& a_assignments);

		// For displaying the contraband index
		void DisplayCPContrabandIndex(const std::vector<CContraband>& a_contraband_index);

		// For displaying the SOP tabs and logo
		void RenderCivilProtectionSOP();

	}
}