#pragma once
#include "../../GUIUtilities.h"							// GUI utils

#include "../SOP/CivilProtection/CPSOPTableRowData.h"	// Table row data
#include "../SOP/CivilProtection/CPSOPLookupTables.h"	// Lookup tables

#include <../imgui/imgui.h>								// ImGui

#include <functional>
#include <string>
#include <vector>

namespace FattyMenu {

	namespace CPSOP {
		/* Function Prototypes */

		void DisplayCPLogo();																								// For displaying Civil Protection's logo (ASCII)
		
		void DisplayCodeInfo(const std::vector<CCode>& a_codes); 															// For displaying code information based on code type

		void DisplayCivicRewardInfo(const std::vector<CCivicReward>& a_civic_rewards); 										// For displaying citizen rewards
		void DisplayCivilStatusInfo();																						// For displaying civil status types and engagement directives
		
		void DisplayPolitiSchedule(); 																						// For displaying politi-schedule
		
		void DisplayOverrideCodeTable(); 																					// For displaying override code table
		
		void DisplayViolationCodesTable(const std::string& a_table_label, const std::vector<CCode>& a_violation_codes); 	// For displaying violation codes
		void DisplayViolationLevelsTable(); 																				// For displaying violation levels table
		void DisplayContrabandIndex(const std::vector<CContraband>& a_contraband_index); 									// For displaying the contraband index
		void DisplayResidentialBlockTable();																				// For displaying communal punishments
		
		void DisplayPatrolRegions();																						// For displaying patrol regions
		void DisplayNonPatrolRegions();																						// For displaying non-patrol regions

		// Main render function for this tab
		void RenderCivilProtectionSOP(); 																					// For displaying the SOP collapsing headers + logo


	}
}