#pragma once

// Lambda functions
#include <functional>

// GUI utils
#include "../../../../GUIUtilities.h"

// ImGui dependencies
#include "../../../../../ext_dependencies/imgui/imgui.h"

// Class definitions
#include "../../global_classes/CCode.h"
#include "../../global_classes/CTerm.h"

// Vector lists
#include "CPSOPLookupTables.h"

/* TODO:
	- Fix shitty jank code I made for prototyping, replace it with lambda function calls to the template function, which is easier to maintain
*/
namespace CPSOP {
	/* Template helper function for displaying items in a static vector list
	* @param &item_list -> address of vector containing items to be displayed
	* @param Render(const T&) -> placeholder function for displaying the item from a list stored in memory
	*/
	template<typename T>
	inline void DisplayList(const std::vector<T>& item_list, std::function<void(const T&)> RenderItem) {
		// Loop through the list
		for (const auto& item : item_list) {
			// Display the item
			RenderItem(item);

			// Add a line separator
			ImGui::Separator();
		}
	}

	// Helper function for rendering each section of the SOP
	/* @param header_label -> string for the header's label
	*  @param RenderContent -> void function to be called for displaying specific parts of the SOP (i.e., DisplayCodes(), DisplayRewardInfo(), etc.)
	*/
	inline void RenderSOPSection(const char* header_label, std::function<void()> RenderContent) {
		if (ImGui::CollapsingHeader(header_label)) {
			GUIUtils::SetHeaderTransparent(); // Set the subheaders to transparent
			RenderContent();				  // Call provided render function
			GUIUtils::PopColorStack();		  // Pop the color stack
		}
	}

	/* Function Prototypes */
	// For displaying civil protection's logo
	void DisplayLogo();

	// For displaying 10-, 11-, and response codes
	void DisplayCodes(const std::vector<CCode>);

	// For displaying citizen rewards
	void DisplayRewardInfo(const std::vector<CCivicReward>);
	
	// For displaying citizen types and interaction directives
	void DisplayInteractionDirectives(const std::vector<CCivilStatus>);

	// For displaying terminology index
	void DisplayTerms(const std::vector<CTerm>);

	// For displaying politi-schedule
	void DisplayPolitiSchedule(const std::vector<CPolitiSchedule>);

	// For displaying mandate and assignment duties, alongside relevant misc info
	void DisplayDuties(const std::vector<CAssignment>);

	// For displaying the contraband index
	void DisplayContrabandIndex(const std::vector<CContraband>);

	// For displaying the SOP tabs and logo
	void RenderCivilProtectionSOP();
	
}