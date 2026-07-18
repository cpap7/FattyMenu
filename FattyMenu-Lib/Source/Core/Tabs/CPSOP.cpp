#include "CPSOP.h"

namespace FattyMenu {
	/* Displays ASCII art of the Civil Protection symbol */
	void CPSOP::DisplayCPLogo() {
		// Could probably format this better, but too lazy to bother 
		ImGui::Text("							----   -----");
		ImGui::Text("							----   -----");
		ImGui::Text("							----   -----");
		ImGui::Text("							----   -----");
		ImGui::Text("							----   -----");
		ImGui::Text("							----   -----");
		ImGui::Text("");
		ImGui::Text("					   ---  ------------  --------------------");
		ImGui::Text("				  --------  ------------  ------------------------");
		ImGui::Text("			  ------------  ------------  ---------------------------");
		ImGui::Text("			--------------  ------------  -----------------------------");
		ImGui::Text("		  ----------------  ------------  ------------------------------");
		ImGui::Text("		------------------  ------------  -------------------------------");
		ImGui::Text("	  --------------------  ------------  --------------------------------");
		ImGui::Text("	 ---------------------  ------------  ---------------------------------");
		ImGui::Text("	----------------------  ------------                   ----------------");
		ImGui::Text("   -----------------------  ------------                     --------------");
		ImGui::Text("  -----------------------   ------------                     --------------");
		ImGui::Text(" -------------------        ------------                  -----------------");
		ImGui::Text(" -----------------          ------------  --------------------------------");
		ImGui::Text(" ----------------           ------------  --------------------------------");
		ImGui::Text("----------------            ------------  -------------------------------");
		ImGui::Text("---------------             ------------  -----------------------------");
		ImGui::Text("---------------             ------------  ----------------------------");
		ImGui::Text("---------------             ------------  -------------------------");
		ImGui::Text("---------------             ------------  ----------------------");
		ImGui::Text("----------------            ------------");
		ImGui::Text(" ---------------            ------------    ---   ---   ---");
		ImGui::Text(" ----------------           ------------    ----  ---- ----");
		ImGui::Text("  -----------------         ------------    ----  ---- ----");
		ImGui::Text("   -------------------      ------------    ----  ----  ---");
		ImGui::Text("	----------------------  ------------    ----  ----");
		ImGui::Text("	 ---------------------  ------------    ----  ----");
		ImGui::Text("	  --------------------  ------------    ----  ----");
		ImGui::Text("	   -------------------  ------------    ----  ----");
		ImGui::Text("		 -----------------  ------------    ----");
		ImGui::Text("		   ---------------  ------------    ----");
		ImGui::Text("			  ------------  ------------    ----");
		ImGui::Text("				 ---------  ------------    ----");
		ImGui::Text("					  ----  ------------    ----");
		ImGui::Text("											----");

	}

	/* TODO: fix lambda functions and streamline everything to use template structure outlined in GUIUtilities.h
		CPSOP::DisplayCPList(codes_list, [] (const CCode& code) {
			ImGui::TextWrapped("%s: %s", code.GetCodeName(), code.GetCodeDescription());

			if (code.IsViolationCode()) {
				GUI::Helpers::WrappedBulletText("Violation Reason: %s", code.GetViolationDescription());
			}

			if (code.IsOverrideCode()) {
				if (!code.GetOverrideDescription().empty()) {
					if (ImGui::TreeNode("Override Description")) {
						for (const auto& line : code.GetOverrideDescription()) {
							GUI::Helpers::WrappedBulletText("%s", line);
						}
						ImGui::TreePop();
					}
				}

				if (!code.GetOverrideDirectives().empty()) {
					if (ImGui::TreeNode("Override Directives")) {
						for (const auto& directive : code.GetOverrideDirectives()) {
							GUI::Helpers::WrappedBulletText("%s", directive);
						}
						ImGui::TreePop();
					}
				}
			}
		});
		*/

	// Globals
	// Colors used for highlighting special cases
	static ImVec4 s_red_color		= ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	static ImVec4 s_yellow_color	= ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

	// Function for displaying code violations and override codes
	// @param codes_list -> vector containing a list of radio codes to be looped through and displayed
	void CPSOP::DisplayCPCodes(const std::vector<CCode>& a_codes_list) {
		// Loop through the radio codes
		for (const auto& code : a_codes_list) {
			// Check if the code is an override code, which contains lists of strings
			if (code.IsOverrideCode()) {
				// Display the override code, descriptions, and directives
				ImGui::TextWrapped("%s\n", code.GetName());

				// Loop through the descriptions and display them
				for (const auto& description : code.GetOverrideDescription()) {
					GUI::Helpers::WrappedBulletText("%s\n", description);
				}

				// Loop through the directives and display them
				for (const auto& directive : code.GetOverrideDirectives()) {
					ImGui::TextWrapped("-> %s\n", directive);
				}
			}

			// Check if the code is a violation, which has 3 strings
			else if (code.IsViolationCode()) {
				// Display 3 strings as wrapped text
				GUI::Helpers::WrappedBulletText("%s: %s\n -> %s", code.GetName(), code.GetDescription(), code.GetViolationDescription());
			}

			// Separate each with a line separator
			ImGui::Separator();
		}
	}

	// Function for displaying civic point and ration rewards for public service details and civic deeds
	// @param reward_list -> vector containing each type of civic duty that a unit can issue a reward for, which is looped through and displayed
	void CPSOP::DisplayCivicRewardInfo(const std::vector<CCivicReward>& a_reward_list) {
		// Loop through the rewards
		for (const auto& reward : a_reward_list) {
			// Display them as bullet text
			ImGui::TextWrapped("%s: %s\n", reward.GetNumber(), reward.GetDescription());

			// Separate each with a line separator
			ImGui::Separator();
		}
	}

	void CPSOP::DisplayCitizenInteractionDirectives(const std::vector<CCivilStatus>& a_civil_status_list) {
		// Loop through the different status types
		for (const auto& civil_status : a_civil_status_list) {
			// Display the name of the status type, and the civic point range
			ImGui::TextWrapped("%s (%s)\n", civil_status.GetStatusType(), civil_status.GetCivicPointRange());
			GUI::Helpers::WrappedBulletText("%s\n", civil_status.GetStatusDefinition());

			// Loop through interaction directives
			for (const auto& directive : civil_status.GetInteractionDirectives()) {
				GUI::Helpers::WrappedBulletText("%s\n", directive);
			}

			// Separate each status type with a line separator
			ImGui::Separator();
		}
	}

	// Function for displaying Politi-Schedule
	// @param politi_schedule_list -> vector containing a list of events to be looped through and displayed

	void CPSOP::DisplayPolitiSchedule() {
		static const SPolitiScheduleRow rows[] = {
			// Columns:
			// Start time		End time		Event					Time length (start time - end time)
			{ "00:00",			"03:00",		"Curfew Procedure",		"3 hours"							},
			{ "04:15",			"05:45",		"Workforce Intake",		"1 hour, 30 minutes"				},
			{ "06:00",			"07:00",		"Ration Intake",		"1 hour"							},
			{ "07:15",			"11:45",		"Workforce Intake",		"4 hours, 30 minutes"				},
			{ "12:00",			"13:00",		"N/A",					"1 hour"							},
			{ "13:15",			"17:45",		"Workforce Intake",		"4 hours, 30 minutes"				},
			{ "18:00",			"19:00",		"Ration Intake",		"1 hour"							},
			{ "19:15",			"23:00",		"Workforce Intake",		"3 hours, 45 minutes"				},
		};


		// Create the table for the override code directives
		int column_count = 4;
		ImGui::BeginTable("PolitiSchedule", column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("TIME START");
		ImGui::TableSetupColumn("TIME END");
		ImGui::TableSetupColumn("MANDATE");
		ImGui::TableSetupColumn("LENGTH");

		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& schedule : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);

			ImGui::Text("%s", schedule.m_time_started.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::Text("%s", schedule.m_time_end.c_str());

			ImGui::TableSetColumnIndex(2);
			if (schedule.m_mandate == "Ration Intake") {
				ImGui::TextColored(s_yellow_color, "%s", schedule.m_mandate.c_str());
			}

			if (schedule.m_mandate == "Curfew Procedure") {
				ImGui::TextColored(s_red_color, "%s", schedule.m_mandate.c_str());
			}

			else if (schedule.m_mandate == "Workforce Intake" || schedule.m_mandate == "N/A") {
				ImGui::TextWrapped("%s", schedule.m_mandate.c_str());
			}

			ImGui::TableSetColumnIndex(3);
			ImGui::Text("%s", schedule.m_length.c_str());
		}

		ImGui::EndTable();
	}

	void CPSOP::DisplayOverrideCodeTable() {
		static const SOverrideCodeRow rows[] = {
			// Columns:
			// Status					Sociostable			Unrest				Containment			Lockdown
			{ "Ration Intake",			"Active",			"Discretionary",	"Suspended",		"Suspended"		},
			{ "Workforce Status",		"Active",			"Discretionary",	"Suspended",		"Suspended"		},
			{ "Shield Access",			"Civic Populace",	"Workforce",		"Ground Units",		"Ground Units"	},
		};


		// Create the table for the override code directives
		int column_count = 5;
		ImGui::BeginTable("OverrideCodes", column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("STATUS");
		ImGui::TableSetupColumn("SOCIOSTABLE");
		ImGui::TableSetupColumn("UNREST");
		ImGui::TableSetupColumn("CONTAINMENT");
		ImGui::TableSetupColumn("LOCKDOWN");

		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& status : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);

			ImGui::Text("%s", status.m_status_index.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::Text("%s", status.m_sociostable_index.c_str());

			ImGui::TableSetColumnIndex(2);
			if (status.m_unrest_index == "Discretionary" || status.m_unrest_index == "Workforce") {
				GUI::Helpers::WrappedTextColored(s_yellow_color, status.m_unrest_index.c_str());
			}

			ImGui::TableSetColumnIndex(3);
			if (status.m_containment_index == "Suspended" || status.m_containment_index == "Ground Units") {
				GUI::Helpers::WrappedTextColored(s_red_color, status.m_containment_index.c_str());
			}

			ImGui::TableSetColumnIndex(4);
			if (status.m_lockdown_index == "Suspended" || status.m_lockdown_index == "Ground Units") {
				GUI::Helpers::WrappedTextColored(s_red_color, status.m_lockdown_index.c_str());
			}
		}

		ImGui::EndTable();
	}

	// For displaying violation levels table
	void CPSOP::DisplayViolationLevelsTable() {
		static const SViolationLevelRow rows[] = {
			// Columns:
			{
				// Level
				1,

				// Description
				"Minor, isolated, accidental or first-time violation with negligable impact on sociostability. Little or no harm, disruption, interference or resistance is present",

				// Recommended verdict(s)
				{ "Verbal Warning", "Citation", "Prosecution" }
			},
			{
				2,
				"Deliberated, repeated or disruptive violation with limited impact on sociostability. The violation demonstrates disregard for civic expectations but results in only minor harm, interference, disruption or disorder",
				{ "Citation", "Prosecution" }
			},
			{
				3,
				"Serious violation resulting in measurable loss, interference, public disruption or operational burden. The violation produces measurable consequences affecting individuals, property, civic functions, or protection team operations",
				{ "Prosecution" }
			},
			{
				4,
				"Severe violation involving substantial harm, dangerous conduct, significant resistance, organized misconduct or serious interference with Combine operations. The violation presents a clear threat to sociostability, civic order or operations",
				{ "Terminal prosecution", "Amputation\n(if necessary to display authority amongst populace)" }
			},
			{
				5,
				"Critical violation involving extreme harm, armed conduct, violent intent, organized resistance, direct attacks upon Combine authority or actions causing widespread instability. The violation presents an immediate and significant threat to sociostability",
				{ "Terminal prosecution", "Immediate amputation\n(if unable to apprehend)", "Disassociation\n(if labor required)" }
			}
		};


		// Create the table for the violation levels
		int column_count = 3;
		ImGui::BeginTable("ViolationLevels", column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("LEVEL");
		ImGui::TableSetupColumn("DESCRIPTION");
		ImGui::TableSetupColumn("VERDICT (RECOMMENDED)");


		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& row : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);

			switch (row.m_level) {
				case 3:
					// Moderate severity = yellow color text
					ImGui::TextColored(s_yellow_color, "%i", row.m_level);
					break;

				case 4:
				case 5:
					// High severity = red color text
					ImGui::TextColored(s_red_color, "%i", row.m_level);
					break;

				default:
					// Low severity (i.e., level 1 & 2) = default color text
					ImGui::TextWrapped("%i", row.m_level);
					break;
			}
			
			ImGui::TableSetColumnIndex(1);
			GUI::Helpers::WrappedTableCellText(row.m_description);

			ImGui::TableSetColumnIndex(2);
			for (const auto& verdict : row.m_recommended_verdicts) {
				if (verdict == "Verbal Warning" || verdict == "Citation") {
					GUI::Helpers::WrappedBulletText("%s", verdict);
				}
				if (verdict == "Prosecution") {
					GUI::Helpers::WrappedBulletTextColored(s_yellow_color, "%s", verdict);
				}

				// TODO: Refactor this portion a bit
				if (verdict == "Amputation\n(if necessary to display authority amongst populace)" || verdict == "Disassociation\n(if labor required)" || verdict == "Terminal prosecution") {
					GUI::Helpers::WrappedBulletTextColored(s_red_color, "%s", verdict);
				}
			}
		}

		ImGui::EndTable();
	}

	// Function for displaying contraband index
	// @param contraband_list -> vector containing a list of contraband, their verdict codes, and examples to be looped through and displayed
	void CPSOP::DisplayContrabandIndex(const std::vector<CContraband>& a_contraband_list) {
		// Loop through the contraband categories
		for (const auto& category : a_contraband_list) {
			// Display the violation code's name, description
			ImGui::TextWrapped("%s: %s\n%s\n", category.GetViolationCode().GetName(), category.GetViolationCode().GetDescription(), category.GetVerdict());

			// Loop through each example for each category
			for (const auto& example : category.GetExamples()) {
				GUI::Helpers::WrappedBulletText("%s", example);
			}

			// Separate each contraband type with a line separator
			ImGui::Separator();
		}
	}

	void CPSOP::DisplayPatrolRegions() {
		static const SLocationAuthorizationRow rows[] = {
			// Columns:
			// Location 							Civic Populace					Engineer Core								Infestation Control					Civil Protection
			{ { "Workforce Intake Hub" },			{ "Permitted" },				{ "Permitted" },							{ "Permitted" },					{ "Permitted" } },
			{ { "Residental Block (priority)" },    { "Access Protocol" },			{ "Access Protocol" },						{ "Access Protocol" },				{ "Permitted" } },
			{ { "Residental Block" },				{ "Permitted" },				{ "Permitted" },							{ "Permitted" },					{ "Permitted" } },
			{ { "Distribution Block" },		        { "Access Protocol" },			{ "Access Protocol" },						{ "Access Protocol" },				{ "Permitted" } },
			{ { "Production Block" },				{ "Access Protocol" },			{ "Permitted" },							{ "Permitted" },					{ "Permitted" } },
			{ { "Station Block" },					{ "Not Permitted", true },		{ "Not Permitted", true },					{ "Not Permitted", true },			{ "Permitted" } }
		};


		// Create the table for the override code directives
		int column_count = 5;
		ImGui::BeginTable("LocationAuthorization", column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableHeader("PATROL REGTIONS");
		ImGui::TableSetupColumn("Location");
		ImGui::TableSetupColumn("Civic Populace *");
		ImGui::TableSetupColumn("Engineer Core");
		ImGui::TableSetupColumn("Infestation Control");
		ImGui::TableSetupColumn("Civil Protection");

		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& row : rows) {
			ImGui::TableNextRow();

			// Location & civil protection columns don't contain conditionals
			ImGui::TableSetColumnIndex(0);
			GUI::Helpers::WrappedTableCellText(row.m_location.m_index.c_str());

			ImGui::TableSetColumnIndex(1);
			if (row.m_civic_populace.m_requires_civil_protection_supervision) {
				ImGui::TextColored(s_red_color, "%s", row.m_civic_populace.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(s_yellow_color, "*");
			}
			else if (row.m_civic_populace.m_index == "Access Protocol") {
				ImGui::TextColored(s_yellow_color, row.m_civic_populace.m_index.c_str());
			}
			else {
				ImGui::TextWrapped("%s", row.m_civic_populace.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(2);
			if (row.m_engineer_core.m_requires_civil_protection_supervision) {
				ImGui::TextColored(s_red_color, "%s", row.m_engineer_core.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(s_yellow_color, "*");
			}
			else if (row.m_engineer_core.m_index == "Access Protocol") {
				ImGui::TextColored(s_yellow_color, row.m_engineer_core.m_index.c_str());
			}
			else {
				ImGui::TextWrapped("%s", row.m_engineer_core.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(3);
			if (row.m_infestation_control.m_requires_civil_protection_supervision) {
				ImGui::TextColored(s_red_color, "%s", row.m_infestation_control.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(s_yellow_color, "*");
			}
			else if (row.m_infestation_control.m_index == "Access Protocol") {
				ImGui::TextColored(s_yellow_color, row.m_infestation_control.m_index.c_str());
			}
			else {
				ImGui::TextWrapped("%s", row.m_infestation_control.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(4);
			ImGui::TextWrapped("%s", row.m_civil_protection.m_index.c_str());

		}

		ImGui::EndTable();
	}

	void CPSOP::DisplayNonPatrolRegions() {
		static const SLocationAuthorizationRow rows[] = {
			// Columns:
			// Location 								Civic Populace						Engineer Core						Infestation Control					Civil Protection
			{ { "Restricted Block", false },			{ "Not Permitted", false },			{ "Not Permitted", true },			{ "Not Permitted", true },			{ "Not Permitted", false, true } },
			{ { "Storm System", false },				{ "Not Permitted", false },			{ "Not Permitted", true },			{ "Not Permitted", true },			{ "Not Permitted", false, true } },
			{ { "Outland Zone",	false },				{ "Not Permitted", false },			{ "Not Permitted", true },			{ "Not Permitted", false },         { "Not Permitted", false, true } },
			{ { "Terminal Restriction Zone", false },	{ "Not Permitted", false },			{ "Not Permitted", false },			{ "Not Permitted", false },			{ "Not Permitted", false, true } },

		};

		// Create the table for the override code directives
		int column_count = 5;
		ImGui::BeginTable("LocationAuthorization", column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableHeader("PATROL REGTIONS");
		ImGui::TableSetupColumn("Location");
		ImGui::TableSetupColumn("Civic Populace *");
		ImGui::TableSetupColumn("Engineer Core");
		ImGui::TableSetupColumn("Infestation Control");
		ImGui::TableSetupColumn("Civil Protection");

		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& row : rows) {
			ImGui::TableNextRow();

			// NOTE: Location & civic populace don't have their own special cases like with engineer core & infestation control
			ImGui::TableSetColumnIndex(0);
			GUI::Helpers::WrappedTableCellText(row.m_location.m_index.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextColored(s_red_color, "%s", row.m_civic_populace.m_index.c_str());


			ImGui::TableSetColumnIndex(2);
			if (row.m_engineer_core.m_requires_civil_protection_supervision) {
				ImGui::TextColored(s_red_color, "%s", row.m_engineer_core.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(s_yellow_color, "*");
			}
			else {
				GUI::Helpers::WrappedTextColored(s_red_color, "%s", row.m_engineer_core.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(3);
			if (row.m_infestation_control.m_requires_civil_protection_supervision) {
				ImGui::TextColored(s_red_color, "%s", row.m_infestation_control.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(s_yellow_color, "*");
			}
			else {
				GUI::Helpers::WrappedTextColored(s_red_color, "%s", row.m_infestation_control.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(4);
			if (row.m_civil_protection.m_requires_special_authorization) {
				ImGui::TextColored(s_red_color, "%s", row.m_civil_protection.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(s_yellow_color, "**");
			}
			else {
				ImGui::TextWrapped("%s", row.m_civil_protection.m_index.c_str());
			}
		}

		ImGui::EndTable();
	}

	void CPSOP::DisplayCommunalPunishmentsTable() {
		static const SCommunalRow rows[] = {
			// Columns:
			// Residential Block		Capacity
			{ "Residental Block 1",		"4 residents per room"          },
			{ "Residental Block 3",		"10 residents per room"         },
			{ "Residental Block 4",		"6 residents per room"          },
			{ "Residental Block 5",		"4 residents per room"          },
			{ "Residental Block 8",		"Unlimited capacity (overflow)" },

		};

		// Create the table for the violation levels
		int column_count = 2;
		ImGui::BeginTable("CommunalPunishments", column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("LOCATION");
		ImGui::TableSetupColumn("CAPACITY");


		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& communal : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", communal.m_area.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", communal.m_capacity.c_str());
		}
		ImGui::EndTable();

	}

	void CPSOP::DisplayViolationTable(const std::string& a_table_label, const std::vector<SViolationRow>& a_rows) {
		// Create the table for the violation levels
		int column_count = 3;
		ImGui::BeginTable(a_table_label.c_str(), column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		//ImGui::TableHeader("FAILURE TO COMPLY WITH THE CIVIL WILL");
		ImGui::TableSetupColumn("CODE");
		ImGui::TableSetupColumn("VIOLATION");
		ImGui::TableSetupColumn("DESCRIPTION");

		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& violation : a_rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", violation.m_code.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", violation.m_violation.c_str());

			ImGui::TableSetColumnIndex(2);
			ImGui::TextWrapped("%s", violation.m_description.c_str());

			switch (violation.m_note) {
				case EViolationNote::None: 
					break;

				case EViolationNote::SanctionedDistribution:
					ImGui::SameLine();
					ImGui::TextColored(s_yellow_color, "*");
					break;

				case EViolationNote::FirearmsCharge:
					ImGui::TextWrapped("(charge");
					ImGui::SameLine();
					ImGui::TextColored(s_red_color, "all firearms");
					ImGui::SameLine();
					ImGui::TextWrapped("with 94 weapon instead)");
					break;

				default:
					break;
			}
		}

		ImGui::EndTable();
	}

	void CPSOP::RenderCivilProtectionSOP() {
		// Collapsing headers render info once the user clicks on them
		if (ImGui::CollapsingHeader("<:: DISPLAY CIVIL PROTECTION LOGO ::>")) {
			// Print the ASCII art logo
			DisplayCPLogo();
		}

		// Display the code index, render the subheaders via the inline helper function
		GUI::Helpers::RenderSOPSection("<:: CODE INDEX ::>", [] {
			// Clicking the first header displays these options
			// Relegate abbreviations, 10-, 11- and response codes to the template function in GUIUtilities.h 
			if (ImGui::CollapsingHeader("<:: View Abbreviations ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::abbreviation_list);
			}
			if (ImGui::CollapsingHeader("<:: View Response Codes ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::response_code_list);
			}
			if (ImGui::CollapsingHeader("<:: View 11- Codes ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::eleven_code_list);
			}
			if (ImGui::CollapsingHeader("<:: View 10- Codes ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::ten_code_list);
			}
			if (ImGui::CollapsingHeader("<:: View Violation Codes ::>")) {
				ImGui::TextColored(s_yellow_color, "\nVIOLATION OF CIVIC TRUST");
				GUI::Helpers::WrappedBulletText("Actions that undermine civic responsibility, authorized resource allocation, workforce obligations or public trust\n");
				//DisplayCPCodes(CPSOPLookupTables::violation_of_civic_trust_codes);
				DisplayViolationTable("CivicTrustCodeViolations", CPSOPLookupTables::civic_trust_violations);
				ImGui::TextColored(s_yellow_color, "*");
				ImGui::SameLine();
				ImGui::TextWrapped("Sanctioned distribution requires the permit holder to distribute only items corresponding to their permit inside their assigned distribution block. Units with at least 40 rank points may authorize distribution outside of their assigned block. Combine anti-fatigue rations may not be distributed whatsoever");

				ImGui::TextColored(s_yellow_color, "\nFAILURE TO COMPLY WITH THE CIVIL WILL");
				GUI::Helpers::WrappedBulletText("Failure to obey, respect, or cooperate w/ lawful directives issued by Civil Protection\n");
				//DisplayCPCodes(CPSOPLookupTables::failure_to_comply_with_the_civil_will);
				DisplayViolationTable("CivilWillCodeViolations", CPSOPLookupTables::civil_will_violations);

				ImGui::TextColored(s_yellow_color, "\nPROMOTING COMMUNAL UNREST");
				GUI::Helpers::WrappedBulletText("Actions intended to disrupt civic harmony, encourage disorder or undermine public stability\n");
				//DisplayCPCodes(CPSOPLookupTables::promoting_communal_unrest);
				DisplayViolationTable("CommunalUnrestCodeViolations", CPSOPLookupTables::communal_unrest_violations);


				ImGui::TextColored(s_yellow_color, "\nDIVISIVE SOCIOCIDAL COUNTER-OBEYANCE");
				GUI::Helpers::WrappedBulletText("Organized resistance to authority, interference with operations, or support of anti - civil elements\n");
				//DisplayCPCodes(CPSOPLookupTables::divisive_sociocidal_counter_obeyance);
				DisplayViolationTable("DivisiveSociocidalCodeViolations", CPSOPLookupTables::divisive_sociocidal_violations);


				ImGui::TextColored(s_yellow_color, "\nDESTRUCTION OF CORPORAL SOCIAL PROTECTION UNITS");
				GUI::Helpers::WrappedBulletText("Acts resulting in damage to Civil Protection personnel, assets or operational capability\n");
				//DisplayCPCodes(CPSOPLookupTables::destruction_of_corporal_social_protection_units);
				DisplayViolationTable("DestructionCodeViolations", CPSOPLookupTables::destruction_violations);
			}
			if (ImGui::CollapsingHeader("<:: View Communal Punishments ::>")) {
				GUI::Helpers::WrappedBulletText("Communal punishments are strategic measures used by the Combine to assert control and instill fear among the civic populace. They function as instruments of intimidation intended to guarantee compliance. Such action are sanctioned exclusively by dispatch and rank leaderrs.");
				DisplayCommunalPunishmentsTable();
				GUI::Helpers::WrappedBulletTextColored(s_yellow_color, "Individuals who are unable to be assigned a residence are to find occpancy in Residental Block 8. All individuals found\nin violation of crowding an area are to be charged with 407 unlawful assembly");
			}
			if (ImGui::CollapsingHeader("<:: View Violation Levels ::>")) {
				ImGui::TextWrapped("Violation levels determine the seriousness of a violation & the appropriate verdict code.");
				ImGui::TextWrapped("Protection units shall assess severity based upon intent, harm caused, degree of resistance, repitition of misconduct and threat posed to sociostability");
				ImGui::TextWrapped("When multiple violations are committed simultaneously, units shall prosecute according to the highest applicable severity level.");
				ImGui::TextWrapped("Additional violations may be used to increase severity at unit discretion.");

				DisplayViolationLevelsTable();
			}
			if (ImGui::CollapsingHeader("<:: View Override Codes ::>")) {
				DisplayOverrideCodeTable();
				DisplayCPCodes(CPSOPLookupTables::override_code_list);
			}
		});

		// Display civic point reward sections
		GUI::Helpers::RenderSOPSection("<:: CIVIC REWARD & INTERACTION INDEX ::>", [] {
			if (ImGui::CollapsingHeader("<:: View General Public Service Details ::>")) {
				ImGui::TextWrapped("Any member of the civic populace can be summoned into voluntary conscription at any time by a protection unit to perform a public service.");
				ImGui::TextWrapped("Successful completion of service may warrant a reward in the form of civic points or ration coupons at the discretion of a PTL");

				DisplayCivicRewardInfo(CPSOPLookupTables::public_service_detail_list);
			}
			if (ImGui::CollapsingHeader("<:: View Civic Deeds ::>")) {
				ImGui::TextWrapped("Members of the civic populace may also perform civic deeds of their own accord.");
				ImGui::TextWrapped("These may warrant a reward in the form of civic points or ration coupons at the discretion of a PTL");

				DisplayCivicRewardInfo(CPSOPLookupTables::civic_deed_list);
			}
			if (ImGui::CollapsingHeader("<:: View Interaction Directives ::>")) {
				DisplayCitizenInteractionDirectives(CPSOPLookupTables::citizen_interaction_directive_list);
			}
		});

		// Display terminology index sections via helper functions (2 strings per bullet point)
		GUI::Helpers::RenderSOPSection("<:: TERMINOLOGY INDEX ::>", [] {
			if (ImGui::CollapsingHeader("<:: View Protocol Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::protocol_list);
			}
			if (ImGui::CollapsingHeader("<:: View Action Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::action_list);
			}
			if (ImGui::CollapsingHeader("<:: View Action/Condition Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::action_condition_list);
			}
			if (ImGui::CollapsingHeader("<:: View Hostile Entity Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::hostile_list);
			}
			if (ImGui::CollapsingHeader("<:: View Equipment/Asset Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::equipment_asset_list);
			}
			if (ImGui::CollapsingHeader("<:: View Organization Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::organization_list);
			}
			if (ImGui::CollapsingHeader("<:: View Sociostability Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::sociostability_list);
			}
			if (ImGui::CollapsingHeader("<:: View Area Terms ::>")) {
				GUI::Helpers::DisplayList(CPSOPLookupTables::area_list);
			}

		});

		// Render politi schedule index
		GUI::Helpers::RenderSOPSection("<:: POLITI-SCHEDULE INDEX ::>", [] {
			// Display politi schedule
			DisplayPolitiSchedule();
		});

		// Render duty index
		GUI::Helpers::RenderSOPSection("<:: DUTY INDEX ::> ", [] {
			// Display mandate duties
			if (ImGui::CollapsingHeader("<:: View Mandate Duties ::>")) {
				// Display prelude
				ImGui::TextWrapped("These duties deviate from those under the assignments section as they are conducted exclusively during their designated times.");
				ImGui::Separator();

				GUI::Helpers::DisplayAssignment(CPSOPLookupTables::mandate_duties_list);
			}

			// Display protection duties
			if (ImGui::CollapsingHeader("<:: View Protection Duties ::>")) {
				// Display prelude
				ImGui::TextWrapped("Protection teams have many daily responsibilities, with team leaders coordinating assignmentsd to cover all duties.");
				ImGui::TextWrapped("At least one team should serve as well-armed reinforcement near key areas.");
				ImGui::TextWrapped("Dispatch & rank leaders are authorized to assign or reassign teams as necessary.");
				ImGui::Separator();

				GUI::Helpers::DisplayAssignment(CPSOPLookupTables::protection_duties_list);
			}

			// Display duty expectations + TAC etiquette
			if (ImGui::CollapsingHeader("<:: View Duty Expectations and TAC Etiquette ::>")) {
				GUI::Helpers::DisplayAssignment(CPSOPLookupTables::miscellaneous_duties_list);
			}
		});

		// Render contraband index
		GUI::Helpers::RenderSOPSection("<:: CONTRABAND INDEX ::> ", [] {
			DisplayContrabandIndex(CPSOPLookupTables::contraband_list);
		});

		// Render location authorization index
		GUI::Helpers::RenderSOPSection("<:: LOCATION AUTHORIZATION INDEX ::>", [] {
			// Patrol regions
			ImGui::TextColored(s_yellow_color, "\nPATROL REGIONS");
			DisplayPatrolRegions();
			
			// Non-patrol regions
			ImGui::TextColored(s_yellow_color, "\nNON-PATROL REGIONS");
			DisplayNonPatrolRegions();
			
			// Legend
			ImGui::TextColored(s_yellow_color, "\nLegend");
			ImGui::Text("* Includes members of the Industrial and Medical Workforces");

			ImGui::TextColored(s_yellow_color, "*");
			ImGui::SameLine();
			ImGui::Text("Unless directly escorted & supervised by protection units");

			ImGui::TextColored(s_yellow_color, "**");
			ImGui::SameLine();
			ImGui::Text(" Unless authorized or during an active situation");
			
		});
	}
}


	/* Larger logo -- too big for the menu lol
		ImGui::Text("									 ------    ------");
		ImGui::Text("									 ------    ------");
		ImGui::Text("									 ------    ------");
		ImGui::Text("									 ------    ------");
		ImGui::Text("									 ------    ------");
		ImGui::Text("									 ------    ------");
		ImGui::Text("									 ------    ------");
		ImGui::Text("									 ------    ------");
		ImGui::Text("");
		ImGui::Text("									 ----------------");
		ImGui::Text("							------   ----------------   -----------------------------");
		ImGui::Text("					   -----------   ----------------   ---------------------------------");
		ImGui::Text("					--------------   ----------------   -----------------------------------");
		ImGui::Text("				 -----------------   ----------------   --------------------------------------");
		ImGui::Text("			   -------------------   ----------------   ---------------------------------------");
		ImGui::Text("			 ---------------------   ----------------   ----------------------------------------");
		ImGui::Text("		   -----------------------   ----------------   -----------------------------------------");
		ImGui::Text("		 -------------------------   ----------------   ------------------------------------------");
		ImGui::Text("		--------------------------   ----------------   -------------------------------------------");
		ImGui::Text("	   ---------------------------   ----------------   -------------------------------------------");
		ImGui::Text("	 -----------------------------   ----------------                         ----------------------");
		ImGui::Text("	------------------------------   ----------------                            -------------------");
		ImGui::Text("	------------------------------   ----------------                             ------------------");
		ImGui::Text("   -------------------------------   ----------------                            -------------------");
		ImGui::Text("  --------------------------         ----------------                          ---------------------");
		ImGui::Text("  -----------------------            ----------------   -------------------------------------------");
		ImGui::Text(" -----------------------             ----------------   -------------------------------------------");
		ImGui::Text(" ----------------------              ----------------   ------------------------------------------");
		ImGui::Text("----------------------               ----------------   -----------------------------------------");
		ImGui::Text("---------------------                ----------------   ----------------------------------------");
		ImGui::Text("--------------------                 ----------------   ---------------------------------------");
		ImGui::Text("--------------------                 ----------------   -------------------------------------");
		ImGui::Text("--------------------                 ----------------   ----------------------------------");
		ImGui::Text("--------------------                 ----------------   --------------------------------");
		ImGui::Text("--------------------                 ----------------   ---------------------------");
		ImGui::Text(" --------------------                ----------------");
		ImGui::Text(" ---------------------               ----------------");
		ImGui::Text(" ---------------------               ----------------      -----  -----   -----");
		ImGui::Text("  ----------------------             ----------------      -----  -----   -----");
		ImGui::Text("   ----------------------            ----------------      -----  -----   -----");
		ImGui::Text("   -------------------------         ----------------      -----  -----   -----");
		ImGui::Text("	------------------------------   ----------------      -----  -----");
		ImGui::Text("	 -----------------------------   ----------------      -----  -----");
		ImGui::Text("	  ----------------------------   ----------------      -----  -----");
		ImGui::Text("	   ---------------------------   ----------------      -----  -----");
		ImGui::Text("		 -------------------------   ----------------      -----  -----");
		ImGui::Text("		  ------------------------   ----------------      -----  -----");
		ImGui::Text("			----------------------   ----------------      -----   ----");
		ImGui::Text("			  --------------------   ----------------      -----");
		ImGui::Text("				------------------   ----------------      -----");
		ImGui::Text("				   ---------------   ----------------      -----");
		ImGui::Text("					  ------------   ----------------      -----");
		ImGui::Text("						  --------   ----------------      -----");
		ImGui::Text("								 -   ----------------      -----");
		ImGui::Text("														   -----");


	*/