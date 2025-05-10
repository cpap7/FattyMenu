#pragma once

// Lambda functions
#include <functional>

// GUI utils
#include "../../../../GUIUtilities.h"

// ImGui dependencies
#include "../../../../../ext_dependencies/imgui/imgui.h"

// Vector lists
#include "CPSOPLookupTables.h"

/* TODO:
	- Fix shitty jank code I made for prototyping, replace it with lambda function calls to the template function in GUIUtilities.h, which is easier to maintain
*/
namespace CPSOP {
	/* Function Prototypes */
	// For displaying Civil Protection's logo (ASCII)
	void DisplayCPLogo();

	// For displaying 10-, 11-, and response codes
	void DisplayCPCodes(const std::vector<CCode>);

	// For displaying citizen rewards
	void DisplayCPRewardInfo(const std::vector<CCivicReward>);
	
	// For displaying citizen types and interaction directives
	void DisplayCPInteractionDirectives(const std::vector<CCivilStatus>);

	// For displaying terminology index
	void DisplayCPTerms(const std::vector<CTerm>);

	// For displaying politi-schedule
	void DisplayCPPolitiSchedule(const std::vector<CPolitiSchedule>);

	// For displaying mandate and assignment duties, alongside relevant misc info
	void DisplayCPDuties(const std::vector<CAssignment>);

	// For displaying the contraband index
	void DisplayCPContrabandIndex(const std::vector<CContraband>);

	// For displaying the SOP tabs and logo
	void RenderCivilProtectionSOP();
	
}