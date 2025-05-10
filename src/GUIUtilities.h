#pragma once
#include "GUI.h"
#include <functional>			// For passing functions as parameters
#include <vector>				// For lists


/* For GUI utility functions, like for changing ImGUI header colors, text formatting, etc. */
namespace GUIUtils {

	// Function prototypes for header colors / themes
	void SetHeaderColorBlue();										// Citizen-related collapsible headers will use ImGUI's default blue color scheme
	void SetHeaderColorRed();										// For Airwatch-related collapsible headers
	void SetHeaderColorGreen();										// For Vortigaunt-related collapsible headers
	void SetHeaderColorCyan();										// For Civil Protection-related collapsible headers
	void SetHeaderColorYellow();									// For Transhuman Forces-related collapsible headers

	void SetHeaderTransparent();									// For collapsible sub-headers

	void PopColorStack();											// For resetting the colors to default color for current style theme

	void SetThemeCivilProtection();									// Config for a Civil Protection-like theme


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
			SetHeaderTransparent();			  // Set the subheaders to transparent
			RenderContent();				  // Call provided render function
			PopColorStack();				  // Pop the color stack
		}
	}

}



