#include "CPSOP.h"

/* TODO:
* Streamline all of this and reduce spaghetti as much as possible
* - Replace pre-existing bullet-list-like functions with tables to more closely mirror the SOP doc in terms of design
* - Consider changing the display table function bodies to loop through the row indices dynamically rather than going through them individually
*/

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

	// Globals
	// Colors used for highlighting text in some cases
	static ImVec4 s_red_color		= ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	static ImVec4 s_yellow_color	= ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

	void CPSOP::DisplayCodeInfo(const std::vector<CCode>& a_codes_list) {
		// Loop through the radio codes
		for (const auto& code : a_codes_list) {
			std::string name = code.GetName();

			switch (code.GetCodeType()) {
				case ECodeType::None:
					break;
				
				case ECodeType::Abbreviation:
				case ECodeType::ResponseCode:
				case ECodeType::ElevenCode:
				case ECodeType::TenCode:
					GUI::Helpers::DisplayListItem(code);
					break;

				case ECodeType::ViolationCode: // Handled in other functions
					break;
				
				case ECodeType::OverrideCode:
					// Display the override code, descriptions, and directives

					// Override code procedure name color is displayed different based on type
					if (name == "Unrest Procedure") {
						GUI::Helpers::WrappedColoredText(s_yellow_color, name.c_str());
					}
					else if (name == "Containment Procedure" || name == "Lockdown Procedure") {
						GUI::Helpers::WrappedColoredText(s_red_color, name.c_str());
					}
					else { // Sociostable
						ImGui::TextWrapped("%s\n", name.c_str());
					}

					// Loop through the descriptions and display them
					for (const auto& description : code.GetOverrideDescription()) {
						GUI::Helpers::WrappedBulletText("%s\n", description);
					}

					// Loop through the directives and display them
					for (const auto& directive : code.GetOverrideDirectives()) {
						ImGui::TextWrapped("-> %s\n", directive);
					}
					break;
				
				case ECodeType::VerdictCode:
					if (name == "PROSECUTION") {
						GUI::Helpers::WrappedColoredText(s_yellow_color, name.c_str());
					}
					else if (name == "TERMINAL PROSECUTION" || name == "DISASSOCIATION" || name == "AMPUTATION" || name == "IMMEDIATE AMPUTATION") {
						GUI::Helpers::WrappedColoredText(s_red_color, name.c_str());
					}
					else { // Verbal Warning / Citation headers get displayed with default text color
						ImGui::TextWrapped("%s\n", name.c_str());
					}
					GUI::Helpers::WrappedBulletText("%s", code.GetDescription());
					ImGui::Separator();
					break;
				
				default:
					break;
			}
		}
	}

	void CPSOP::DisplayCivicRewardInfo(const std::vector<CCivicReward>& a_reward_list) {
		for (const auto& reward : a_reward_list) {
			ImGui::TextWrapped("%s: %s\n", reward.GetNumber(), reward.GetDescription());
			ImGui::Separator();
		}
	}

	void CPSOP::DisplayCivilStatusInfo() {
		GUI::Helpers::RenderTable(
			"CivilStatusTable",
			{ "CIVIL STATUS", "DEFINITION", "ADMINISTRATIVE DIRECTIVES" },
			[] {
				for (const auto& civil_status : CPSOPLookupTables::civil_status_info_list) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0); // Status type + civic point range beneath
					std::string type = civil_status.GetStatusType();
					std::string type_and_range = type + "\n(" + civil_status.GetCivicPointRange() + ")";
					GUI::Helpers::WrappedTableCellText(type_and_range.c_str());

					ImGui::TableSetColumnIndex(1); 	// Definition
					GUI::Helpers::WrappedTableCellText(civil_status.GetStatusDefinition());

					ImGui::TableSetColumnIndex(2);	// Directives in bullet form
					// Loop through interaction directives
					for (const auto& directive : civil_status.GetAdministrativeDirectives()) {
						GUI::Helpers::WrappedBulletText(directive);
					}
				}
			}
		);
	}

	void CPSOP::DisplayPolitiSchedule() {
		GUI::Helpers::RenderTable(
			"PolitiScheduleTable",
			{ "TIME START", "TIME END", "MANDATE", "LENGTH" },
			[] {
				for (const auto& schedule : CPSOPTableData::politi_schedule_table_data) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					GUI::Helpers::WrappedTableCellText(schedule.m_time_started.c_str());

					ImGui::TableSetColumnIndex(1);
					GUI::Helpers::WrappedTableCellText(schedule.m_time_end.c_str());

					ImGui::TableSetColumnIndex(2);
					if (schedule.m_mandate == "Ration Intake") {
						GUI::Helpers::WrappedColoredText(s_yellow_color, "%s", schedule.m_mandate.c_str());
					}
					else if (schedule.m_mandate == "Curfew Procedure") {
						GUI::Helpers::WrappedColoredText(s_red_color, "%s", schedule.m_mandate.c_str());
					}
					GUI::Helpers::WrappedTableCellText(schedule.m_mandate.c_str());

					ImGui::TableSetColumnIndex(3);
					GUI::Helpers::WrappedTableCellText(schedule.m_length.c_str());
				}
			}

		);
		
	}

	void CPSOP::DisplayOverrideCodeTable() {
		GUI::Helpers::RenderTable(
			"OverrideCodesTable", 
			{ "STATUS", "SOCIOSTABLE", "UNREST", "CONTAINMENT", "LOCKDOWN" },
			[] {
				for (const auto& override_code : CPSOPTableData::override_code_table_data) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);

					ImGui::Text("%s", override_code.m_status_index.c_str());

					ImGui::TableSetColumnIndex(1);
					ImGui::Text("%s", override_code.m_sociostable_index.c_str());

					ImGui::TableSetColumnIndex(2);
					GUI::Helpers::WrappedColoredText(s_yellow_color, override_code.m_unrest_index.c_str());

					ImGui::TableSetColumnIndex(3);
					GUI::Helpers::WrappedColoredText(s_red_color, override_code.m_containment_index.c_str());

					ImGui::TableSetColumnIndex(4);
					GUI::Helpers::WrappedColoredText(s_red_color, override_code.m_lockdown_index.c_str());
				}
			}
		);
	}

	void CPSOP::DisplayViolationCodesTable(const std::string& a_table_label, const std::vector<CCode>& a_violation_codes) {
		GUI::Helpers::RenderTable(
			a_table_label.c_str(),
			{ "CODE", "VIOLATION", "DESCRIPTION" },
			[&] {
				// Iterate over rows 
				for (const auto& violation : a_violation_codes) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					ImGui::TextWrapped("%s", violation.GetName());

					ImGui::TableSetColumnIndex(1);
					ImGui::TextWrapped("%s", violation.GetDescription());

					ImGui::TableSetColumnIndex(2);
					ImGui::TextWrapped("%s", violation.GetViolationDescription());

					switch (violation.GetViolationCodeNote()) {
					case EViolationCodeNote::None:
						break;

					case EViolationCodeNote::SanctionedDistribution:
						ImGui::SameLine();
						ImGui::TextColored(s_yellow_color, "*");
						break;

					case EViolationCodeNote::FirearmsCharge:
						ImGui::Text("(charge ");
						ImGui::SameLine(0.0f, 0.0f);
						ImGui::TextColored(s_red_color, "all firearms");
						ImGui::SameLine(0.0f, 0.0f);
						ImGui::Text(" with 94 weapon instead)");
						break;

					default:
						break;
					}
				}
			}
		);
	}

	void CPSOP::DisplayViolationLevelsTable() {
		GUI::Helpers::RenderTable(
			"ViolationLevelsTable", 
			{ "LEVEL", "DESCRIPTION", "VERDICT (RECOMMENDED)" },
			[] {
				for (const auto& row : CPSOPTableData::violation_level_table_data) {
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
							GUI::Helpers::WrappedBulletColoredText(s_yellow_color, "%s", verdict);
						}

						// TODO: Refactor this portion a bit - don't exactly love how this was done lol
						if (verdict == "Amputation\n(if necessary to display authority amongst populace)" || verdict == "Disassociation\n(if labor required)" || verdict == "Terminal prosecution") {
							GUI::Helpers::WrappedBulletColoredText(s_red_color, "%s", verdict);
						}
					}
				}
			}
		);
	}

	void CPSOP::DisplayContrabandIndex(const std::vector<CContraband>& a_contraband_list) {
		for (const auto& category : a_contraband_list) {
			// Display the violation code's name, description
			ImGui::TextWrapped("%s: %s\n", category.GetViolationCode().GetName(), category.GetViolationCode().GetDescription());

			// Loop through each example for each category
			for (const auto& example : category.GetExamples()) {
				GUI::Helpers::WrappedBulletText("%s", example);
			}

			// Separate each contraband type with a line separator
			ImGui::Separator();
		}
	}

	void CPSOP::DisplayPatrolRegions() {
		GUI::Helpers::RenderTable(
			"PatrolRegionTable",
			{ "Location", "Civic Populace *", "Engineer Core", "Infestation Control", "Civil Protection" },
			[] {
				// Iterate over rows 
				for (const auto& row : CPSOPTableData::patrol_region_table_data) {
					ImGui::TableNextRow();

					// Location column 
					// - Doesn't contain conditionals
					ImGui::TableSetColumnIndex(0);
					GUI::Helpers::WrappedTableCellText(row.m_location.m_index.c_str());

					// Civic Populace column
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

					// Engineer Core column
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

					// Infestation Control column
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

					// Civil Protection column
					ImGui::TableSetColumnIndex(4);
					ImGui::TextWrapped("%s", row.m_civil_protection.m_index.c_str());

				}
			}
		);
	}

	void CPSOP::DisplayNonPatrolRegions() {
		GUI::Helpers::RenderTable(
			"NonPatrolRegionTable",
			{ "Location", "Civic Populace *", "Engineer Core", "Infestation Control", "Civil Protection" },
			[] {
				for (const auto& row : CPSOPTableData::non_patrol_region_table_data) {
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
						GUI::Helpers::WrappedColoredText(s_red_color, "%s", row.m_engineer_core.m_index.c_str());
					}

					ImGui::TableSetColumnIndex(3);
					if (row.m_infestation_control.m_requires_civil_protection_supervision) {
						ImGui::TextColored(s_red_color, "%s", row.m_infestation_control.m_index.c_str());
						ImGui::SameLine();
						ImGui::TextColored(s_yellow_color, "*");
					}
					else {
						GUI::Helpers::WrappedColoredText(s_red_color, "%s", row.m_infestation_control.m_index.c_str());
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
			}
		);
	}

	void CPSOP::DisplayResidentialBlockTable() {
		GUI::Helpers::RenderTable(
			"ResidentialBlockTable", 
			{ "LOCATION", "CAPACITY" }, 
			[] {
				for (const auto& row : CPSOPTableData::residential_block_table_data) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					ImGui::TextWrapped("%s", row.m_area.c_str());

					ImGui::TableSetColumnIndex(1);
					ImGui::TextWrapped("%s", row.m_capacity.c_str());
				}
			}
		);

	}

	void CPSOP::RenderCivilProtectionSOP() {
		// Collapsing headers render info once the user clicks on them
		if (ImGui::CollapsingHeader("<:: DISPLAY CIVIL PROTECTION LOGO ::>")) {
			// Print the ASCII art logo
			DisplayCPLogo();
		}

		// Display the code index, render the subheaders via the inline helper function
		GUI::Helpers::RenderSOPSection("<:: CODE INDEX ::>", 
			[] {
				// Clicking the first header displays these options

				// The display function for abbreviations, 10-, 11- and response codes is templated (see GUIUtilities.h)
				if (ImGui::CollapsingHeader("<:: View Abbreviations ::>")) {
					DisplayCodeInfo(CPSOPLookupTables::abbreviation_list);
				}
				if (ImGui::CollapsingHeader("<:: View Response Codes ::>")) {
					DisplayCodeInfo(CPSOPLookupTables::response_code_list);
				}
				if (ImGui::CollapsingHeader("<:: View 11- Codes ::>")) {
					DisplayCodeInfo(CPSOPLookupTables::eleven_code_list);
				}
				if (ImGui::CollapsingHeader("<:: View 10- Codes ::>")) {
					DisplayCodeInfo(CPSOPLookupTables::ten_code_list);
				}
				if (ImGui::CollapsingHeader("<:: View Violation Codes ::>")) {
					for (const auto& category : CPSOPLookupTables::violation_code_categories) {
						ImGui::TextColored(s_yellow_color, "%s", category.GetName());				// Display category header
						GUI::Helpers::WrappedBulletText("%s", category.GetDescription());			// Display the category description
						DisplayViolationCodesTable(category.GetTableID(), *category.GetCodes());	// Display the codes in a table 

						if (!category.GetFootnote().empty()) {
							ImGui::TextColored(s_yellow_color, "*");
							ImGui::SameLine();
							ImGui::TextWrapped("%s", category.GetFootnote().c_str());
						}

						ImGui::Separator();
					}
				}
				if (ImGui::CollapsingHeader("<:: View Violation Levels ::>")) {
					ImGui::TextWrapped("Violation levels determine the seriousness of a violation & the appropriate verdict code.");
					ImGui::TextWrapped("Protection units shall assess severity based upon intent, harm caused, degree of resistance, repetition of misconduct and threat posed to sociostability.");
					ImGui::TextWrapped("When multiple violations are committed simultaneously, units shall prosecute according to the highest applicable severity level.");
					ImGui::TextWrapped("Additional violations may be used to increase severity at unit discretion.");

					ImGui::Separator();

					DisplayViolationLevelsTable();
				}
				if (ImGui::CollapsingHeader("<:: View Verdict Codes ::>")) {
					ImGui::TextWrapped("Verdicts highlighted in");
					ImGui::SameLine();
					ImGui::TextColored(s_red_color, "red");
					ImGui::SameLine();
					ImGui::TextWrapped("may only be authorized by rank leaders or dispatch.");

					ImGui::Separator();

					DisplayCodeInfo(CPSOPLookupTables::verdict_code_list);
				}
				if (ImGui::CollapsingHeader("<:: View Communal Punishments ::>")) {
					ImGui::TextWrapped("Communal punishments are strategic measures used by the Combine to assert control and instill fear among the civic populace.");
					ImGui::TextWrapped("They function as instruments of intimidation intended to guarantee compliance.");
					ImGui::TextWrapped("Such actions are sanctioned exclusively by dispatch and rank leaders.");

					ImGui::Separator();

					// TODO: Add CTerms for UNLAWFUL ASSEMBLY, RATION UNIT DEDUCTION etc. and clean this up
					ImGui::TextColored(s_yellow_color, "UNLAWFUL ASSEMBLY");
					GUI::Helpers::WrappedBulletText("Refers to the penal code that addresses gatherings of individuals who either exceed the allowed capacity for an area or intend to commit a crime.");

					DisplayResidentialBlockTable(); // Called here to mimic the format of the SOP
					GUI::Helpers::WrappedBulletColoredText(s_yellow_color, "Individuals who are unable to be assigned a residence are to find occupancy in Residental Block 8. All individuals found in violation of crowding an area are to be charged with 407 unlawful assembly");

					ImGui::Separator();

					ImGui::TextColored(s_yellow_color, "RATION UNIT DEDUCTION");
					GUI::Helpers::WrappedBulletText("Refers to the punitive measure of reducing or withholding a local block's allocated ration units as a disciplinary action for various offenses or breaches of Combine regulations. This deduction should only last for a maximum of 2 intake periods.");

					ImGui::Separator();

					ImGui::TextColored(s_yellow_color, "IDENTIFICATION CHECK");
					GUI::Helpers::WrappedBulletText("Entails organizing all citizens within their local residential block into designated inspection positions, typically their apartment rooms. During this process, units rigorously search and verify all occupants' identities while conducting thorough inspections to identify & remove contraband items from the premises. If a resident is located outside of their designated room, they are failing to comply with the civil will.");

					ImGui::Separator();

					ImGui::TextColored(s_red_color, "LOCKDOWN PROCEDURE");
					GUI::Helpers::WrappedBulletText("Involves relocating citizens to their residential blocks, conducting thorough sweeps, restricting containment field access to ground units only, deploying stabilization teams for additional reinforcement, and executing swift security measures to suppress threats to Combine authority effectively");
				}
				if (ImGui::CollapsingHeader("<:: View Override Codes ::>")) {
					DisplayOverrideCodeTable();
					DisplayCodeInfo(CPSOPLookupTables::override_code_list);
				}
			}
		);

		// Display civic point reward sections
		GUI::Helpers::RenderSOPSection("<:: CIVIC REWARD & CIVIL STATUS INDEX ::>", 
			[] {
				if (ImGui::CollapsingHeader("<:: View General Public Service Details ::>")) {
					ImGui::TextWrapped("Any member of the civic populace can be summoned into voluntary conscription at any time by a protection unit to perform a public service.");
					ImGui::TextWrapped("Successful completion of service may warrant a reward in the form of civic points or ration coupons at the discretion of a PTL");

					ImGui::Separator();

					DisplayCivicRewardInfo(CPSOPLookupTables::public_service_detail_list);
				}
				if (ImGui::CollapsingHeader("<:: View Civic Deeds ::>")) {
					ImGui::TextWrapped("Members of the civic populace may also perform civic deeds of their own accord.");
					ImGui::TextWrapped("These may warrant a reward in the form of civic points or ration coupons at the discretion of a PTL");

					ImGui::Separator();

					DisplayCivicRewardInfo(CPSOPLookupTables::civic_deed_list);
				}
				if (ImGui::CollapsingHeader("<:: View Civil Status Info ::>")) {
					ImGui::TextWrapped("Civil status is the Combine's administrative classification system used to assess a citizen's compliance, productivity, civic utility & level of administrative suspicion.");
					ImGui::TextWrapped("It determines an individual's eligibility for provisions, labor assignments, accommodations & other civic privileges.");
					ImGui::TextColored(s_yellow_color, "Officers shall enforce protocols appropriate to each status classification in order to maintain sociostability and workforce efficiency within Combine-controlled cities");

					ImGui::Separator();

					DisplayCivilStatusInfo();
				}
			}
		);

		GUI::Helpers::RenderSOPSection("<:: TERMINOLOGY INDEX ::>", 
			[] {
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

			}
		);

		// Render politi schedule index
		GUI::Helpers::RenderSOPSection("<:: POLITI-SCHEDULE INDEX ::>", 
			[] {
				DisplayPolitiSchedule();
			}
		);

		// Render duty index
		GUI::Helpers::RenderSOPSection("<:: DUTY INDEX ::> ", 
			[] {
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
					ImGui::TextWrapped("Protection teams have many daily responsibilities, with team leaders coordinating assignments to cover all duties.");
					ImGui::TextWrapped("At least one team should serve as well-armed reinforcement near key areas.");
					ImGui::TextWrapped("Dispatch & rank leaders are authorized to assign or reassign teams as necessary.");

					ImGui::Separator();

					GUI::Helpers::DisplayAssignment(CPSOPLookupTables::protection_duties_list);
				}

				// Display duty expectations + TAC etiquette
				if (ImGui::CollapsingHeader("<:: View Duty Expectations and TAC Etiquette ::>")) {
					GUI::Helpers::DisplayAssignment(CPSOPLookupTables::miscellaneous_duties_list);
				}

				GUI::Helpers::WrappedColoredText(s_yellow_color, "The beginning and end of a duty must be communicated into TAC.");
				GUI::Helpers::WrappedColoredText(s_yellow_color, "Authorization is not required for a duty unless containment or lockdown procedure is in effect.");
			}
		);

		// Render contraband index
		GUI::Helpers::RenderSOPSection("<:: CONTRABAND INDEX ::> ", 
			[] {
				DisplayContrabandIndex(CPSOPLookupTables::contraband_list);
			}
		);

		// Render location authorization index
		GUI::Helpers::RenderSOPSection("<:: LOCATION AUTHORIZATION INDEX ::>", 
			[] {
				// Patrol regions
				GUI::Helpers::WrappedColoredText(s_yellow_color, "PATROL REGIONS");
				DisplayPatrolRegions();

				// Non-patrol regions
				GUI::Helpers::WrappedColoredText(s_yellow_color, "NON-PATROL REGIONS");
				DisplayNonPatrolRegions();

				// Legend
				ImGui::TextWrapped("* Includes members of the Industrial and Medical Workforces");

				ImGui::TextColored(s_yellow_color, "*");
				ImGui::SameLine();
				ImGui::TextWrapped("Unless directly escorted & supervised by protection units");

				ImGui::TextColored(s_yellow_color, "**");
				ImGui::SameLine();
				ImGui::TextWrapped("Unless authorized or during an active situation");
			
			}
		);
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