#include "GUIUtilities.h"

namespace FattyMenu {
	// Citizen-related collapsible headers will use ImGUI's default blue color schema
	void GUI::Themes::SetHeaderColorBlue() {
		ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.26f, 0.59f, 0.98f, 0.31f));			// Normal
		ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.26f, 0.59f, 0.98f, 0.80f));	// Hovered
		ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.26f, 0.59f, 0.98f, 1.00f));	// Active
	}

	// Red for Airwatch-related collapsible headers
	void GUI::Themes::SetHeaderColorRed() {
		// Change the color of the header to a custom red color
		ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.50f, 0.00f, 0.00f, 1.00f));			// Dark Red
		ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.70f, 0.10f, 0.10f, 1.00f));  // Lighter Red when hovered
		ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.90f, 0.00f, 0.00f, 1.00f));	// Even lighter red when active
	}

	// Green for Vortigaunt-related collapsible headers
	void GUI::Themes::SetHeaderColorGreen() {
		// Change the color of the header to a custom green color
		ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.00f, 0.50f, 0.00f, 1.00f));			// Dark Green
		ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.10f, 0.70f, 0.10f, 1.00f));  // Lighter Green when hovered
		ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.00f, 0.90f, 0.00f, 1.00f));	// Bright Green when active
	}

	// Cyan for Civil Protection-related collapsible headers 
	void GUI::Themes::SetHeaderColorCyan() {
		// Change the color of the header to a custom cyan color
		ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.00f, 1.00f, 1.00f, 0.33f));			// Cyan
		ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.00f, 1.00f, 1.00f, 0.42f));  // Lighter Cyan when hovered
		ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.00f, 1.00f, 1.00f, 0.54f));	// Bright Cyan when active
	}

	// Yellow for Transhuman Forces-related collapsible headers
	void GUI::Themes::SetHeaderColorYellow() {
		// Change the color of the Transhuman Forces header to a custom yellow color
		ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.50f, 0.50f, 0.00f, 1.00f));			// Bright Yellow
		ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.50f, 0.50f, 0.30f, 1.00f));  // Lighter Yellow when hovered
		ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.50f, 0.50f, 0.50f, 1.00f));	// Pale Yellow when active
	}

	// For collapsible sub-headers
	void GUI::Themes::SetHeaderColorDimTeal() {
		// Dim teal tint
		ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.00f, 0.45f, 0.45f, 0.22f));			// Normal
		ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.00f, 0.65f, 0.65f, 0.35f));	// Hovered
		ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.00f, 0.80f, 0.80f, 0.45f));	// Active
	}

	// For transparent headers
	void GUI::Themes::SetHeaderTransparent() {
		// Set header background to transparent 
		ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));			// Normal
		ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));	// Hovered
		ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));	// Active
	}

	// For resetting the colors back to default style
	void GUI::Themes::PopColorStack(int a_stack_size) {
		ImGui::PopStyleColor(a_stack_size);
	}

	// Configuration for a ImGui theme similar to the Civil Protection color schema
	void GUI::Themes::SetThemeCivilProtection() {
		ImGuiStyle& style = ImGui::GetStyle();

		style.Alpha						= 1.0;
		//style.WindowFillAlphaDefault	= 0.83;
		//style.ChildWindowRounding		= 3;
		style.ChildRounding				= 3;
		style.WindowRounding			= 3;
		style.GrabRounding				= 1;
		style.GrabMinSize				= 20;
		style.FrameRounding				= 3;
		
		ImVec4* colors = style.Colors;

		colors[ImGuiCol_Text]						= ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled]				= ImVec4(0.00f, 0.40f, 0.41f, 1.00f);

		colors[ImGuiCol_WindowBg]					= ImVec4(0.00f, 0.00f, 0.00f, 0.80f);
		colors[ImGuiCol_ChildBg]					= ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_PopupBg]					= ImVec4(0.08f, 0.08f, 0.08f, 0.94f);

		colors[ImGuiCol_Border]						= ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
		colors[ImGuiCol_BorderShadow]				= ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		
		colors[ImGuiCol_FrameBg]					= ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
		colors[ImGuiCol_FrameBgHovered]				= ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
		colors[ImGuiCol_FrameBgActive]				= ImVec4(0.44f, 0.81f, 0.86f, 0.66f);

		colors[ImGuiCol_TitleBg]					= ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
		colors[ImGuiCol_TitleBgActive]				= ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
		colors[ImGuiCol_TitleBgCollapsed]			= ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
		
		colors[ImGuiCol_MenuBarBg]					= ImVec4(0.00f, 0.00f, 0.00f, 0.54f);

		colors[ImGuiCol_ScrollbarBg]				= ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
		colors[ImGuiCol_ScrollbarGrab]				= ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
		colors[ImGuiCol_ScrollbarGrabHovered]		= ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
		colors[ImGuiCol_ScrollbarGrabActive]		= ImVec4(0.00f, 1.00f, 1.00f, 1.00f);

		colors[ImGuiCol_CheckMark]					= ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
		colors[ImGuiCol_CheckboxSelectedBg]			= ImVec4(0.22f, 1.00f, 1.00f, 0.45f);

		colors[ImGuiCol_SliderGrab]					= ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
		colors[ImGuiCol_SliderGrabActive]			= ImVec4(0.00f, 1.00f, 1.00f, 0.76f);

		colors[ImGuiCol_Button]						= ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
		colors[ImGuiCol_ButtonHovered]				= ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
		colors[ImGuiCol_ButtonActive]				= ImVec4(0.00f, 1.00f, 1.00f, 0.62f);

		colors[ImGuiCol_Header]						= ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
		colors[ImGuiCol_HeaderHovered]				= ImVec4(0.00f, 0.65f, 0.65f, 0.42f);
		colors[ImGuiCol_HeaderActive]				= ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
		
		colors[ImGuiCol_Separator]					= ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		colors[ImGuiCol_SeparatorHovered]			= ImVec4(0.10f, 0.65f, 0.65f, 0.78f);
		colors[ImGuiCol_SeparatorActive]			= ImVec4(0.10f, 1.00f, 1.00f, 1.00f);

		colors[ImGuiCol_ResizeGrip]					= ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
		colors[ImGuiCol_ResizeGripHovered]			= ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
		colors[ImGuiCol_ResizeGripActive]			= ImVec4(0.00f, 1.00f, 1.00f, 1.00f);

		colors[ImGuiCol_InputTextCursor]			= ImVec4(1.00f, 1.00f, 1.00f, 1.00f);

		colors[ImGuiCol_TabHovered]					= ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
		colors[ImGuiCol_Tab]						= ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
		colors[ImGuiCol_TabSelected]				= ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
		colors[ImGuiCol_TabSelectedOverline]		= ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		
		// Unfocused tabs
		colors[ImGuiCol_TabDimmed]					= ImVec4(0.00f, 1.00f, 1.00f, 0.16f);
		colors[ImGuiCol_TabDimmedSelected]			= ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
		colors[ImGuiCol_TabDimmedSelectedOverline]	= ImVec4(0.50f, 0.50f, 0.50f, 0.00f);

		colors[ImGuiCol_DockingPreview]				= ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
		colors[ImGuiCol_DockingEmptyBg]				= ImVec4(0.20f, 0.20f, 0.20f, 1.00f);

		colors[ImGuiCol_PlotLines]					= ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered]			= ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_PlotHistogram]				= ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered]		= ImVec4(0.00f, 1.00f, 1.00f, 1.00f);

		colors[ImGuiCol_TableHeaderBg]				= ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
		colors[ImGuiCol_TableBorderStrong]			= ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
		colors[ImGuiCol_TableBorderLight]			= ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
		colors[ImGuiCol_TableRowBg]					= ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_TableRowBgAlt]				= ImVec4(1.00f, 1.00f, 1.00f, 0.06f);

		colors[ImGuiCol_TextLink]					= ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_TextSelectedBg]				= ImVec4(0.00f, 1.00f, 1.00f, 0.22f);
		
		colors[ImGuiCol_TreeLines]					= ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		
		colors[ImGuiCol_DragDropTarget]				= ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_DragDropTargetBg]			= ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		
		colors[ImGuiCol_UnsavedMarker]				= ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		
		colors[ImGuiCol_NavCursor]					= ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight]		= ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg]			= ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		
		colors[ImGuiCol_ModalWindowDimBg]			= ImVec4(0.04f, 0.10f, 0.09f, 0.51f);
	}
}