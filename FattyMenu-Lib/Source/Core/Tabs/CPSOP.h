#pragma once

// Lambda functions
#include <functional>
#include <string>
#include <vector>

// GUI utils
#include "../../GUIUtilities.h"

// ImGui dependencies
#include <../imgui/imgui.h>

// Lookup tables
#include "../SOP/CivilProtection/TableRowTypes.h"
#include "../SOP/CivilProtection/CPSOPLookupTables.h"

/* TODO:
	- Fix jank code I made for prototyping, replace it with lambda function calls to the template function in GUIUtilities.h, which is easier to maintain
*/
namespace FattyMenu {
	namespace CPSOP {
		/* Function Prototypes */

		void DisplayCPLogo(); 																							// For displaying Civil Protection's logo (ASCII)
		void DisplayCPCodes(const std::vector<CCode>& a_codes); 														// For displaying 10-, 11-, and response codes
		void DisplayCivicRewardInfo(const std::vector<CCivicReward>& a_civic_rewards); 									// For displaying citizen rewards
		void DisplayCitizenInteractionDirectives(const std::vector<CCivilStatus>& a_civil_status_list);					// For displaying citizen types and interaction directives
		//void DisplayCPTerms(const std::vector<CTerm>& a_terms); 														// For displaying terminology index
		void DisplayPolitiSchedule(); 																					// For displaying politi-schedule
		void DisplayOverrideCodeTable(); 																				// For displaying override code table
		void DisplayViolationLevelsTable(); 																			// For displaying violation levels table
		//void DisplayCPDuties(const std::vector<CAssignment>& a_assignments); 											// For displaying mandate and assignment duties, alongside relevant misc info
		void DisplayContrabandIndex(const std::vector<CContraband>& a_contraband_index); 								// For displaying the contraband index
		void DisplayViolationTable(const std::string& a_table_label, const std::vector<SViolationRow>& a_rows); 		// For displaying violation codes
		void DisplayCommunalPunishmentsTable();																			// For displaying communal punishments
		void DisplayPatrolRegions();																					// For displaying patrol regions
		void DisplayNonPatrolRegions();																					// For displaying patrol regions

		// Main render function for this tab
		void RenderCivilProtectionSOP(); 																				// For displaying the SOP collapsing headers + logo


	}
}