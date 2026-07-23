#include "VoicelineLibrary.h"

#include <algorithm>
#include <cctype>

namespace FattyMenu {

	static char g_search_buffer[256] = "";
	static EFaction g_faction_filter = EFaction::None; // None = 'Show all'

	namespace SearchUtilities {
		// For checking if input text is case insensitive
		static bool ContainsCI(const std::string& a_haystack, const std::string& a_needle) {
			if (a_needle.empty()) {
				return true;
			}

			auto iter = std::search(
				a_haystack.begin(), a_haystack.end(),
				a_needle.begin(), a_needle.end(),
				[](char a_char1, char a_char2) {
					return std::tolower(static_cast<unsigned char>(a_char1)) == std::tolower(static_cast<unsigned char>(a_char2));
				}
			);

			return iter != a_haystack.end();
		}

		// Returns true if voiceline passes current search + faction filters
		static bool PassesFilter(const CVoiceline& a_voiceline) {
			// Faction filter
			// No checkboxes ticked = show all, otherwise match ANY selected bit
			if (g_faction_filter != EFaction::None) {
				if ((a_voiceline.GetFactions() & g_faction_filter) == EFaction::None) {
					return false;
				}
			}
			const std::string needle = g_search_buffer;
			return ContainsCI(a_voiceline.GetCommand(), needle) || ContainsCI(a_voiceline.GetFullVoiceline(), needle);
		}
	}

	void VoicelineLibrary::DisplaySearchFilterControls() {
		// Search box
		ImGui::SetNextItemWidth(-1.0f); // Stretch to available width
		ImGui::InputTextWithHint("##voiceline_search", "Search command or voiceline...", g_search_buffer, IM_ARRAYSIZE(g_search_buffer));

		// Per-faction checkboxes (3 per row)
		if (ImGui::TreeNodeEx("Filter By Faction", ImGuiTreeNodeFlags_DefaultOpen)) {
			//int drawn = 0;
			
			if (ImGui::SmallButton("Clear Filters")) {
				g_faction_filter	= EFaction::None;
				g_search_buffer[0]	= '\0';
			}

			int column_count = 3;
			if (ImGui::BeginTable("FactionsFilterTable", column_count, ImGuiTableFlags_SizingStretchSame)) {
				for (EFaction flag : c_voiceline_faction_flags) {
					ImGui::TableNextColumn();

					bool checked = HasFaction(g_faction_filter, flag);
					if (ImGui::Checkbox(FactionToString(flag).c_str(), &checked)) {
						// Update global mask
						if (checked)	{ g_faction_filter |=  flag; } 
						else			{ g_faction_filter &= ~flag; } // Clear bit
					}

				}
				ImGui::EndTable();
			}
			
			
			ImGui::TreePop();

		}
		ImGui::Separator();
	}
	
	void VoicelineLibrary::DisplayVoicelines() {
		// Display only when populated
		const std::vector<CVoiceline>& voicelines = GetVoicelines();
		if (voicelines.empty()) {
			return;
		}

		size_t match_count = 0;
		for (const auto& v : voicelines) {
			if (SearchUtilities::PassesFilter(v)) { ++match_count; }
		}
		ImGui::TextDisabled("%zu search match(es)", match_count);
		if (match_count == 0) {
			ImGui::TextDisabled("No voicelines match your filter.");
			return;
		}

		if (ImGui::CollapsingHeader("View Voicelines")) {
			// Render rows
			GUI::Helpers::RenderTable(
				"VoicelineTable",
				{ "Command", "Voiceline", "Faction(s)" },
				[&voicelines]() {
					for (size_t i{}; i < voicelines.size(); ++i) {
						const CVoiceline& voiceline = voicelines[i];

						if (!SearchUtilities::PassesFilter(voiceline)) {
							continue;
						}

						ImGui::TableNextRow();
						ImGui::PushID(static_cast<int>(i)); // Unique ID per row

						// Column 0 = command
						ImGui::TableSetColumnIndex(0);
						if (ImGui::Selectable(voiceline.GetCommand().c_str(), false, ImGuiSelectableFlags_SpanAllColumns)) {
							ImGui::SetClipboardText(voiceline.GetCommand().c_str());
						}
						if (ImGui::IsItemHovered()) {
							ImGui::SetTooltip("Click to copy '%s'", voiceline.GetCommand().c_str());
						}

						// Column 1 = full voiceline string
						ImGui::TableSetColumnIndex(1);
						GUI::Helpers::WrappedTableCellText(voiceline.GetFullVoiceline().c_str());


						// Column 2 = factions as bullet
						ImGui::TableSetColumnIndex(2);
						// Display faction tags as bullet
						const auto factions = FactionMaskToStrings(voiceline.GetFactions());
						if (!factions.empty()) {
							std::string joined;
							for (size_t j{}; j < factions.size(); ++j) {
								joined += factions[j];
								if (j + 1 < factions.size()) {
									joined += ", "; // I.e., Male Citizen, Female Citizen
								}
							}
							GUI::Helpers::WrappedBulletText("%s", joined.c_str());
						}

						ImGui::PopID();
					}
				}
			);
		}
	}

	/* Function for rendering the menu in the tab */
	void VoicelineLibrary::RenderVoicelineLibraryMenu() {
		// Refresh button
		if (ImGui::Button("Refresh Voicelines")) {
			// TEMP
			RefreshVoicelines("Project_ Synapse Voicelines.htm");
		}
		ImGui::SameLine();
		ImGui::TextDisabled("(%zu loaded)", GetVoicelines().size());

		ImGui::Separator();

		VoicelineLibrary::DisplaySearchFilterControls();

		VoicelineLibrary::DisplayVoicelines();
	}
}