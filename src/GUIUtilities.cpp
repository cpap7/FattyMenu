#include "GUIUtilities.h"

// Citizen-related collapsible headers will use ImGUI's default blue color schema
void GUIUtils::SetHeaderColorBlue() {
	ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.26f, 0.59f, 0.98f, 0.31f));
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.26f, 0.59f, 0.98f, 0.80f));
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.26f, 0.59f, 0.98f, 1.00f));
}

// Red for Airwatch-related collapsible headers
void GUIUtils::SetHeaderColorRed() {
	// Change the color of the header to a custom red color
	ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.50f, 0.00f, 0.00f, 1.00f));			// Dark Red
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.70f, 0.10f, 0.10f, 1.00f));  // Lighter Red when hovered
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.90f, 0.00f, 0.00f, 1.00f));	// Even lighter red when active
}

// Green for Vortigaunt-related collapsible headers
void GUIUtils::SetHeaderColorGreen() {
	// Change the color of the header to a custom green color
	ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.00f, 0.50f, 0.00f, 1.00f));			// Dark Green
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.10f, 0.70f, 0.10f, 1.00f));  // Lighter Green when hovered
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.00f, 0.90f, 0.00f, 1.00f));	// Bright Green when active
}

// Cyan for Civil Protection-related collapsible headers 
void GUIUtils::SetHeaderColorCyan() {
	// Change the color of the header to a custom cyan color
	ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.00f, 1.00f, 1.00f, 0.33f));			// Cyan
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.00f, 1.00f, 1.00f, 0.42f));  // Lighter Cyan when hovered
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.00f, 1.00f, 1.00f, 0.54f));	// Bright Cyan when active
}

// Yellow for Transhuman Forces-related collapsible headers
void GUIUtils::SetHeaderColorYellow() {
	// Change the color of the Transhuman Forces header to a custom yellow color
	ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.50f, 0.50f, 0.00f, 1.00f));			// Bright Yellow
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.50f, 0.50f, 0.30f, 1.00f));  // Lighter Yellow when hovered
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.50f, 0.50f, 0.50f, 1.00f));	// Pale Yellow when active
}

// For collapsible sub-headers
void GUIUtils::SetHeaderTransparent() {
	// Set header background to transparent 
	ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));			// Normal state
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));	// Hovered state
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));	// Active state
}

// For resetting the colors back to default style
void GUIUtils::PopColorStack() {
	ImGui::PopStyleColor(3);
}

// Configuration for a ImGui theme similar to the Civil Protection color schema
void GUIUtils::SetThemeCivilProtection() {
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha = 1.0;
	//style.WindowFillAlphaDefault = 0.83;
	// style.ChildWindowRounding = 3;
	style.ChildRounding = 3;
	style.WindowRounding = 3;
	style.GrabRounding = 1;
	style.GrabMinSize = 20;
	style.FrameRounding = 3;
	

	style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);

	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.44f, 0.81f, 0.86f, 0.66f);
	
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	
	//style.Colors[ImGuiCol_ComboBg] = ImVec4(0.16f, 0.24f, 0.22f, 0.60f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
	
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
	
	style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
	
	style.Colors[ImGuiCol_Header] = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	
	//style.Colors[ImGuiCol_Column] = ImVec4(0.00f, 0.50f, 0.50f, 0.33f);
	//style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.00f, 0.50f, 0.50f, 0.47f);
	//style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.00f, 0.70f, 0.70f, 1.00f);
	
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	
	//style.Colors[ImGuiCol_CloseButton] = ImVec4(0.00f, 0.78f, 0.78f, 0.35f);
	//style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.00f, 0.78f, 0.78f, 0.47f);
	//style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.00f, 0.78f, 0.78f, 1.00f);
	
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);
	//style.Colors[ImGuiCol_TooltipBg] = ImVec4(0.00f, 0.13f, 0.13f, 0.90f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.04f, 0.10f, 0.09f, 0.51f);

	// Tab colors
	style.Colors[ImGuiCol_Tab] = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);

	//  For unfocused windows (slightly dimmer)
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 1.00f, 1.00f, 0.16f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);

}