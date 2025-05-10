#pragma once
#include "GUI.h"

/* For GUI utility functions, like for changing ImGUI header colors, text formatting, etc. */
namespace GUIUtils {
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

	void SetHeaderColorBlue();										// Citizen-related collapsible headers will use ImGUI's default blue color scheme
	void SetHeaderColorRed();										// For Airwatch-related collapsible headers
	void SetHeaderColorGreen();										// For Vortigaunt-related collapsible headers
	void SetHeaderColorCyan();										// For Civil Protection-related collapsible headers
	void SetHeaderColorYellow();									// For Transhuman Forces-related collapsible headers

	void SetHeaderTransparent();									// For collapsible sub-headers

	void PopColorStack();											// For resetting the colors to default color for current style theme

	void SetThemeCivilProtection();									// Config for a Civil Protection-like theme
}



