#pragma once
#include "GUI.h"
#include <functional>			// For passing functions as parameters
#include <vector>				// For lists


/* For GUI utility functions, like for changing ImGUI header colors, text formatting, etc. */
namespace GUI {

	namespace Themes {
		// Function prototypes for header colors / themes
		void SetHeaderColorBlue();										// Citizen-related collapsible headers will use ImGUI's default blue color scheme
		void SetHeaderColorRed();										// For Airwatch-related collapsible headers
		void SetHeaderColorGreen();										// For Vortigaunt-related collapsible headers
		void SetHeaderColorCyan();										// For Civil Protection-related collapsible headers
		void SetHeaderColorYellow();									// For Transhuman Forces-related collapsible headers

		void SetHeaderTransparent();									// For collapsible sub-headers

		void PopColorStack();											// For resetting the colors to default color for current style theme

		void SetThemeCivilProtection();									// Config for a Civil Protection-like theme
	}


	namespace Helpers {
		// Helper function for wrapped text in a bullet format
		inline void WrappedBulletText(const char* fmt, ...) {
			ImGui::Bullet();											  // Draw bullet point
			ImGui::SameLine();											  // Stay on same line for text
			ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x); // Enable wrapping to window width

			va_list args;
			va_start(args, fmt);
			ImGui::TextWrappedV(fmt, args);								  // Wrapped text (printf-style)
			va_end(args);

			ImGui::PopTextWrapPos();									  // Restore wrap position
		}

		/* Template helper function for displaying items in a static vector list
		* Should with either CTerms, or CCodes in a vector list
		* @param &item_list -> address of vector containing items to be displayed
		* @param Render(const T&) -> placeholder function for displaying the item from a list stored in memory
		*/
		template<typename T>
		inline void DisplayList(const std::vector<T>& item_list) {
			// Loop through the list
			for (const auto& item : item_list) {
				// Check if the item is an override code, which contains lists of strings
				if (item.IsOverrideCode()) {
					// Display the override code, descriptions, and directives
					ImGui::TextWrapped("%s\n", item.GetCodeName());

					// Loop through the descriptions and display them
					for (const auto& description : item.GetOverrideDescription()) {
						GUI::Helpers::WrappedBulletText("%s\n", description);
					}

					// Loop through the directives and display them
					for (const auto& directive : item.GetOverrideDirectives()) {
						ImGui::TextWrapped("-> %s\n", directive);
					}
				}

				// Check if the item is a code violation, which has 3 strings
				else if (item.IsViolationCode()) {
					// Display 3 strings as wrapped text
					GUI::Helpers::WrappedBulletText("%s: %s\n -> %s", item.GetCodeName(), item.GetCodeDescription(), item.GetViolationDescription());
				}

				else {
					// Display them as bullet text
					GUIUtils::WrappedBulletText("%s: %s", item.GetName(), item.GetDescription());
				}

				// Add a line separator
				ImGui::Separator();
			}
		}

		template <typename T>
		inline void DisplayAssignment(const std::vector<T>& assignment_list) {
			for (const auto& duty : assignment_list) {
				if (duty.IsForCP()) {
					// Display assignment name and the # of required units
					ImGui::TextWrapped("%s\n%s", duty.GetAssignmentName(), duty.GetCPUnitsRequired());

					// Display each string description
					for (const auto& description : duty.GetAssignmentDescription()) {
						GUI::Helpers::WrappedBulletText("%s", description);
					}

					// Separate each duty with a line separator
					ImGui::Separator();
				}
			}
		}

		// Helper function for rendering each section of the SOP
		/* @param header_label -> string for the header's label
		*  @param RenderContent -> void function to be called for displaying specific parts of the SOP (i.e., DisplayCodes(), DisplayRewardInfo(), etc.)
		*/
		inline void RenderSOPSection(const char* header_label, std::function<void()> RenderContent) {
			if (ImGui::CollapsingHeader(header_label)) {
				GUI::Themes::SetHeaderTransparent();				// Set the subheaders to transparent
				RenderContent();									// Call provided render function
				GUI::Themes::PopColorStack();						// Pop the color stack
			}
		}
	}

}



/*


// Function for displaying Combine terminology
// @param terms_list -> vector containing a list of terms to be looped through and displayed
void CPSOP::DisplayCPTerms(const std::vector<CTerm> terms_list) {
	// Loop through the terms in the vector list
	for (const auto& term : terms_list) {
		// Display them as bullet text
		GUIUtils::WrappedBulletText("%s: %s", term.GetName(), term.GetDescription());

		// Separate each with a line separator
		ImGui::Separator();
	}
}


*/