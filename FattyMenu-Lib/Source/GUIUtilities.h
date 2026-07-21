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
			void SetHeaderColorGreen();										// For Vortigaunt-themed collapsible headers
			void SetHeaderColorCyan();										// For Civil Protection-themed collapsible headers
			void SetHeaderColorYellow();									// For Transhuman Forces-themed collapsible headers
			void SetHeaderColorDimTeal();									// Default color-scheme for collapsible sub-headers
			void SetHeaderTransparent();									// For transparent headers

			void PopColorStack(int a_stack_size);							// For resetting the colors back to default color

			void SetThemeCivilProtection();									// Config for a Civil Protection-like UI/color-scheme
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
				//char* formatted_string = (char*)alloca(buffer_size);
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
				//char* formatted_string = (char*)alloca(buffer_size);

				{
					ImGui::TextWrappedV(a_fmt, args);

					ImGui::PopStyleColor();
					va_end(args);
				}
			} 

			/* Template helper functions for displaying larger data structures stored within a vector
			*  In practice, these are used for vectors containing CTerms & CCodes
			*/
			template<typename T>
			inline void DisplayListItem(const T& a_item) {
				GUI::Helpers::WrappedBulletText("%s: %s", a_item.GetName(), a_item.GetDescription());
				ImGui::Separator();
			}

			template<typename T>
			inline void DisplayList(const std::vector<T>& a_item_list) {
				for (const auto& item : a_item_list) {
					DisplayListItem(item);
				}
			}

			template <typename T>
			inline void DisplayAssignment(const std::vector<T>& a_assignment_list) {
				for (const auto& duty : a_assignment_list) {
					if (duty.IsForCP()) {
						// Display assignment name and the # of required units
						ImGui::TextWrapped("%s\n%s", duty.GetAssignmentName(), duty.GetCPUnitsRequired());

						// Display each description
						for (const auto& description : duty.GetAssignmentDescription()) {
							GUI::Helpers::WrappedBulletText("%s", description);
						}

					}
					else if (duty.IsForTF()) {
						// Display assignment name and the # of required units
						ImGui::TextWrapped("%s\nREQUIRED:%d+ units\nLENGTH IN SHIFTS:%d\nRecommended Class:%s", duty.GetAssignmentName(), duty.GetTFUnitsRequired(), duty.GetTFShiftDuration(), duty.GetTFRecommendedClass());

						// Display each description
						for (const auto& description : duty.GetAssignmentDescription()) {
							GUI::Helpers::WrappedBulletText("%s", description);
						}
					}

					ImGui::Separator();

				}
			}

			// Helper function for setting up ImGui tables
			/* @param a_table_id				-> unique ImGui table identifier
			*  @param a_column_headers			-> column header labels; size determines the column count
			*  @param a_render_rows_function	-> callable function for display the table's body / cells (per-row)
			*  @param a_flags					-> table flags (default = Resizable/Borders/RowBg/SizingStretchProp)
			*/
			inline void RenderTable(const char* a_table_id, const std::vector<const char*>& a_column_headers, const std::function<void()>& a_render_rows_function, 
				ImGuiTableFlags a_flags = ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp) {

				ImGui::BeginTable(a_table_id, static_cast<int>(a_column_headers.size()), a_flags);

				// Set up each column header
				for (const char* header : a_column_headers) {
					ImGui::TableSetupColumn(header);
				}

				ImGui::TableHeadersRow();
				
				a_render_rows_function();

				ImGui::EndTable();
			}

			// Helper function for rendering each section of the SOP
			/* @param a_header_label -> string for the header's label
			*  @param a_render_function -> void function to be called for displaying specific parts of the SOP (i.e., DisplayCodes(), DisplayRewardInfo(), etc.)
			*/
			inline void RenderSOPSection(const char* a_header_label, const std::function<void()>& a_render_function) {
				if (ImGui::CollapsingHeader(a_header_label)) {
					// Set the subheaders' color
					//GUI::Themes::SetHeaderTransparent();
					GUI::Themes::SetHeaderColorDimTeal();
					a_render_function();								// Call provided render function
					GUI::Themes::PopColorStack(3);						// Pop the color stack
				}
			}
		}

	}
}
