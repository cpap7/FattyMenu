#pragma once
#include "GUI.h"

#include <functional>
#include <vector>
#include <stdarg.h>

namespace FattyMenu {
	/* For GUI utility functions, like for changing ImGUI header colors, text formatting, etc. */
	namespace GUI {

		namespace Themes {
			// Function prototypes for header colors / themes
			void SetHeaderColorBlue();										// Citizen-related collapsible headers will use ImGUI's default blue color scheme
			void SetHeaderColorRed();										// For Airwatch-related collapsible headers
			void SetHeaderColorGreen();										// For Vortigaunt-related collapsible headers
			void SetHeaderColorCyan();										// For Civil Protection-related collapsible headers
			void SetHeaderColorYellow();									// For Transhuman Forces-related collapsible headers

			void SetHeaderTransparent();									// (OLD) For collapsible sub-headers
			void SetSubheaderColorDefault();								// For collapsible sub-headers

			void PopColorStack(int a_stack_size);							// For resetting the colors to default color for current style theme

			void SetThemeCivilProtection();									// Config for a Civil Protection-like theme
		}

		namespace Helpers {
			// TODO: Add color/fmt version of this
			// Helper function for wrapped text within a table that respects the current table column's right edge
			inline void WrappedTableCellText(const char* a_text) {
				ImGui::PushTextWrapPos(ImGui::GetCursorPosX() + ImGui::GetColumnWidth());
				ImGui::TextUnformatted(a_text);
				ImGui::PopTextWrapPos();
			}

			// Helper function for wrapped colored text in a bullet format
			inline void WrappedBulletColoredText(const ImVec4& a_color, const char* a_fmt, ...) {
				ImGui::Bullet();
				ImGui::SameLine();
				ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x);
				
				// Apply selected color
				ImGui::PushStyleColor(ImGuiCol_Text, a_color);

				const int buffer_size = static_cast<int>(ImGui::CalcTextSize(a_fmt, nullptr, false, -1.0f).x) + 256;
				char* formatted_string = (char*)alloca(buffer_size);
				{
					va_list args;
					va_start(args, a_fmt);
					ImGui::TextWrappedV(a_fmt, args);


					ImGui::PopStyleColor();
					va_end(args);
				}
			}

			// Helper function for wrapped text in a bullet format
			inline void WrappedBulletText(const char* a_fmt, ...) {
				ImGui::Bullet();												// Draw bullet point
				ImGui::SameLine();												// Stay on same line for text
				ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x);	// Enable wrapping to window width

				va_list args;
				va_start(args, a_fmt);
				ImGui::TextWrappedV(a_fmt, args);								// Wrapped text (printf-style)
				va_end(args);

				ImGui::PopTextWrapPos();										// Restore wrap position
			}

			// Helper function for wrapped text colored format
			inline void WrappedColoredText(const ImVec4& a_color, const char* a_fmt, ...) {
				ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x);
				va_list args;
				va_start(args, a_fmt);

				// Apply selected color
				ImGui::PushStyleColor(ImGuiCol_Text, a_color);

				const int buffer_size = static_cast<int>(ImGui::CalcTextSize(a_fmt, nullptr, false, -1.0f).x) + 256;
				char* formatted_string = (char*)alloca(buffer_size);

				{
					ImGui::TextWrappedV(a_fmt, args);

					ImGui::PopStyleColor();
					va_end(args);
				}
			} 

			/* Template helper function for displaying items in a static vector
			* Is compatible with either CTerms, or CCodes in a vector container
			*/
			template<typename T>
			inline void DisplayList(const std::vector<T>& a_item_list) {
				// Loop through the list
				for (const auto& item : a_item_list) {
					// Display them as bullet text
					GUI::Helpers::WrappedBulletText("%s: %s", item.GetName(), item.GetDescription());

					// Add a line separator
					ImGui::Separator();
				}
			}

			template <typename T>
			inline void DisplayAssignment(const std::vector<T>& a_assignment_list) {
				for (const auto& duty : a_assignment_list) {
					if (duty.IsForCP()) {
						// Display assignment name and the # of required units
						ImGui::TextWrapped("%s\n%s", duty.GetAssignmentName(), duty.GetCPUnitsRequired());

						// Display each string description
						for (const auto& description : duty.GetAssignmentDescription()) {
							GUI::Helpers::WrappedBulletText("%s", description);
						}

					}
					else if (duty.IsForTF()) {
						// Display assignment name and the # of required units
						ImGui::TextWrapped("%s\nREQUIRED:%d+ units\nLENGTH IN SHIFTS:%d\nRecommended Class:%s", duty.GetAssignmentName(), duty.GetTFUnitsRequired(), duty.GetTFShiftDuration(), duty.GetTFRecommendedClass());

						// Display each string description
						for (const auto& description : duty.GetAssignmentDescription()) {
							GUI::Helpers::WrappedBulletText("%s", description);
						}
					}

					// Separate each duty with a line separator
					ImGui::Separator();

				}
			}

			// Helper function for rendering each section of the SOP
			/* @param a_header_label -> string for the header's label
			*  @param a_render_function -> void function to be called for displaying specific parts of the SOP (i.e., DisplayCodes(), DisplayRewardInfo(), etc.)
			*/
			inline void RenderSOPSection(const char* a_header_label, const std::function<void()>& a_render_function) {
				if (ImGui::CollapsingHeader(a_header_label)) {
					//GUI::Themes::SetHeaderTransparent();				// Set the subheaders' color
					GUI::Themes::SetSubheaderColorDefault();
					a_render_function();								// Call provided render function
					GUI::Themes::PopColorStack(3);						// Pop the color stack
				}
			}
		}

	}
}
