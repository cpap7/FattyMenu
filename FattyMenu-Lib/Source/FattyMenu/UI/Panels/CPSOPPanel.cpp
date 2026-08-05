#include "CPSOPPanel.h"

/* TODO:
* Streamline all of this and reduce spaghetti as much as possible
* - Replace pre-existing bullet-list-like functions with tables to more closely mirror the SOP doc in terms of design
* - Consider changing the display table function bodies to loop through the row indices dynamically rather than going through them individually
*/
namespace FattyMenu {
	
	CCPSOPPanel::CCPSOPPanel() {
		m_logo_texture = std::make_unique<CTexture2D>(c_civil_protection_logo_image_file_path);
	}
	
	CCPSOPPanel::~CCPSOPPanel() {
		m_logo_texture.reset();
	}

	void CCPSOPPanel::OnRender(bool* a_p_open) {
		if (!a_p_open || !*a_p_open) { return; } // Check if it's nullptr or false 

		if (ImGui::Begin("Civil Protection SOP", a_p_open)) {
			LoadCPLogoTexture();
			DisplayCPLogoTexture();

			ImGui::Separator();
			DisplayCivilProtectionSOPContent();
		}
		ImGui::End();
	}

	void CCPSOPPanel::LoadCPLogoTexture() {
		if (!m_logo_texture->HasLoadedOK()) {
			m_logo_texture->Invalidate();
		}
	}
	
	void CCPSOPPanel::DisplayCPLogoTexture() {
		// Fallback for loading via manual map injection (might not resolve the file path right away)
		if (!GUI::Helpers::DrawCenteredTexture(*m_logo_texture, &m_image_scale)) {
			ImGui::Text("File path in memory = %s", m_logo_texture->GetFilePath().c_str());
			ImGui::Text("Expected file path = %s", c_civil_protection_logo_image_file_path);

			if (ImGui::Button("Refresh")) {
				m_logo_texture->UpdatePathAndReload(c_civil_protection_logo_image_file_path);
			}
		}
	}

	void CCPSOPPanel::DisplayCivilProtectionSOPContent() {
		// Collapsing headers render info once the user clicks on them

		// Display the code index, render the subheaders via the inline helper function
		GUI::Helpers::RenderSOPSection("<:: CODE INDEX ::>",
			[this] {
				// Clicking the first header displays these options

				// The display functions (i.e., for abbreviations, 10-, 11- and response codes) is templated (see GUIUtilities.h)
				if (ImGui::CollapsingHeader("<:: View Abbreviations ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"Abbreviations", "abbreviations",
						&LookupTables::RefreshAbbreviationCodesList,
						&LookupTables::GetAbbreviationCodesList,
						[this](const std::vector<CCode>& a_list) { DisplayCodeInfo(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Response Codes ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"ResponseCodes", "response codes",
						&LookupTables::RefreshResponseCodesList,
						&LookupTables::GetResponseCodesList,
						[this](const std::vector<CCode>& a_list) { DisplayCodeInfo(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View 11- Codes ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"ElevenCodes", "11- codes",
						&LookupTables::RefreshElevenCodesList,
						&LookupTables::GetElevenCodesList,
						[this](const std::vector<CCode>& a_list) { DisplayCodeInfo(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View 10- Codes ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"TenCodes", "10- codes",
						&LookupTables::RefreshTenCodesList,
						&LookupTables::GetTenCodesList,
						[this](const std::vector<CCode>& a_list) { DisplayCodeInfo(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Violation Codes ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"ViolationCodeCategories", "violation code categories",
						&LookupTables::RefreshViolationCodeCategories,
						&LookupTables::GetViolationCodeCategories,
						[this](const std::vector<CViolationCodeCategory>& a_category_list) {
							for (const auto& category : a_category_list) {
								ImGui::TextColored(GUI::g_yellow_color, "%s", category.GetName().c_str());			// Display category header
								GUI::Helpers::WrappedBulletText("%s", category.GetDescription().c_str());			// Display the category description
								DisplayViolationCodesTable(category.GetTableID(), *category.GetCodes());			// Display the codes in a table 

								if (!category.GetFootnote().empty()) {
									ImGui::TextColored(GUI::g_yellow_color, "*");
									ImGui::SameLine();
									ImGui::TextWrapped("%s", category.GetFootnote().c_str());
								}

								ImGui::Separator();
							}
						}
					);
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
					GUI::Helpers::RenderRefreshableList(
						"VerdictCodes", "verdict codes",
						&LookupTables::RefreshVerdictCodesList,
						&LookupTables::GetVerdictCodesList,
						[this](const std::vector<CCode>& a_list) { DisplayCodeInfo(a_list); },
						[]() {
							ImGui::TextWrapped("Verdicts highlighted in");
							ImGui::SameLine();
							ImGui::TextColored(GUI::g_red_color, "red");
							ImGui::SameLine();
							ImGui::TextWrapped("may only be authorized by rank leaders or dispatch.");
						}
					);
				}
				if (ImGui::CollapsingHeader("<:: View Communal Punishments ::>")) {
					ImGui::TextWrapped("Communal punishments are strategic measures used by the Combine to assert control and instill fear among the civic populace.");
					ImGui::TextWrapped("They function as instruments of intimidation intended to guarantee compliance.");
					ImGui::TextWrapped("Such actions are sanctioned exclusively by dispatch and rank leaders.");

					ImGui::Separator();

					// TODO: Add CTerms for UNLAWFUL ASSEMBLY, RATION UNIT DEDUCTION etc. and clean this up
					ImGui::TextColored(GUI::g_yellow_color, "UNLAWFUL ASSEMBLY");
					GUI::Helpers::WrappedBulletText("Refers to the penal code that addresses gatherings of individuals who either exceed the allowed capacity for an area or intend to commit a crime.");

					DisplayResidentialBlockTable(); // Called here to mimic the format of the SOP
					GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "Individuals who are unable to be assigned a residence are to find occupancy in Residental Block 8. All individuals found in violation of crowding an area are to be charged with 407 unlawful assembly");

					ImGui::Separator();

					ImGui::TextColored(GUI::g_yellow_color, "RATION UNIT DEDUCTION");
					GUI::Helpers::WrappedBulletText("Refers to the punitive measure of reducing or withholding a local block's allocated ration units as a disciplinary action for various offenses or breaches of Combine regulations. This deduction should only last for a maximum of 2 intake periods.");

					ImGui::Separator();

					ImGui::TextColored(GUI::g_yellow_color, "IDENTIFICATION CHECK");
					GUI::Helpers::WrappedBulletText("Entails organizing all citizens within their local residential block into designated inspection positions, typically their apartment rooms. During this process, units rigorously search and verify all occupants' identities while conducting thorough inspections to identify & remove contraband items from the premises. If a resident is located outside of their designated room, they are failing to comply with the civil will.");

					ImGui::Separator();

					ImGui::TextColored(GUI::g_red_color, "LOCKDOWN PROCEDURE");
					GUI::Helpers::WrappedBulletText("Involves relocating citizens to their residential blocks, conducting thorough sweeps, restricting containment field access to ground units only, deploying stabilization teams for additional reinforcement, and executing swift security measures to suppress threats to Combine authority effectively");
				}
				if (ImGui::CollapsingHeader("<:: View Override Codes ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"OverrideCodes", "override codes",
						&LookupTables::RefreshOverrideCodesList,
						&LookupTables::GetOverrideCodesList,
						[this](const std::vector<CCode>& a_list) {
							DisplayOverrideCodeTable();
							DisplayCodeInfo(a_list);
						}
					);
				}
			}
		);

		// Display civic point reward sections
		GUI::Helpers::RenderSOPSection("<:: CIVIC REWARD & CIVIL STATUS INDEX ::>",
			[this] {
				if (ImGui::CollapsingHeader("<:: View General Public Service Details ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"GeneralPublicServiceDetails", "general public service details",
						&LookupTables::RefreshGeneralPublicServiceDetailRewardsList,
						&LookupTables::GetGeneralPublicServiceDetailRewardsList,
						[this](const std::vector<CCivicReward>& a_list) { DisplayCivicRewardInfo(a_list); },
						[]() {
							ImGui::TextWrapped("Any member of the civic populace can be summoned into voluntary conscription at any time by a protection unit to perform a public service.");
							ImGui::TextWrapped("Successful completion of service may warrant a reward in the form of civic points or ration coupons at the discretion of a PTL");
						}
					);
				}
				if (ImGui::CollapsingHeader("<:: View Civic Deeds ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"CivicDeeds", "civic deeds",
						&LookupTables::RefreshCivicDeedRewardsList,
						&LookupTables::GetCivicDeedRewardsList,
						[this](const std::vector<CCivicReward>& a_list) { DisplayCivicRewardInfo(a_list); },
						[]() {
							ImGui::TextWrapped("Members of the civic populace may also perform civic deeds of their own accord.");
							ImGui::TextWrapped("These may warrant a reward in the form of civic points or ration coupons at the discretion of a PTL");
						}
					);
				}
				if (ImGui::CollapsingHeader("<:: View Civil Status Info ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"CivilStatuses", "civil statuses",
						&LookupTables::RefreshCivilStatusList,
						&LookupTables::GetCivilStatusList,
						[this](const std::vector<CCivilStatus>& a_list) { DisplayCivilStatusInfo(a_list); },
						[]() {

							ImGui::TextWrapped("Civil status is the Combine's administrative classification system used to assess a citizen's compliance, productivity, civic utility & level of administrative suspicion.");
							ImGui::TextWrapped("It determines an individual's eligibility for provisions, labor assignments, accommodations & other civic privileges.");
							ImGui::TextColored(GUI::g_yellow_color, "Officers shall enforce protocols appropriate to each status classification in order to maintain sociostability and workforce efficiency within Combine-controlled cities");
						}
					);
				}
			}
		);

		GUI::Helpers::RenderSOPSection("<:: TERMINOLOGY INDEX ::>",
			[] {
				if (ImGui::CollapsingHeader("<:: View Protocol Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"ProtocolTerms", "protocol terms",
						&LookupTables::RefreshProtocolTermsList,
						&LookupTables::GetProtocolTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Action Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"ActionTerms", "action terms",
						&LookupTables::RefreshActionTermsList,
						&LookupTables::GetActionTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Action/Condition Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"ActionConditionTerms", "action/condition terms",
						&LookupTables::RefreshActionConditionTermsList,
						&LookupTables::GetActionConditionTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Hostile Entity Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"HostileEntityTerms", "hostile entity terms",
						&LookupTables::RefreshHostileEntityTermsList,
						&LookupTables::GetHostileEntityTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Equipment/Asset Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"EquipmentAssetTerms", "equipment/asset terms",
						&LookupTables::RefreshEquipmentAssetTermsList,
						&LookupTables::GetEquipmentAssetTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Organization Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"OrganizationTerms", "organization terms",
						&LookupTables::RefreshOrganizationTermsList,
						&LookupTables::GetOrganizationTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Sociostability Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"SociostabilityTerms", "sociostability terms",
						&LookupTables::RefreshSociostabilityTermsList,
						&LookupTables::GetSociostabilityTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}
				if (ImGui::CollapsingHeader("<:: View Area Terms ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"AreaTerms", "area terms",
						&LookupTables::RefreshAreaTermsList,
						&LookupTables::GetAreaTermsList,
						[](const std::vector<CTerm>& a_list) { GUI::Helpers::DisplayList(a_list); }
					);
				}

			}
		);

		// Render politi schedule index
		GUI::Helpers::RenderSOPSection("<:: POLITI-SCHEDULE INDEX ::>",
			[&] {
				DisplayPolitiSchedule();
			}
		);

		// Render duty index
		GUI::Helpers::RenderSOPSection("<:: DUTY INDEX ::> ",
			[] {
				// Display mandate duties
				if (ImGui::CollapsingHeader("<:: View Mandate Duties ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"MandateDuties", "mandate duties",
						LookupTables::RefreshMandateDutyAssignmentsList,
						LookupTables::GetMandateDutyAssignmentsList,
						[](const std::vector<CAssignment>& a_list) { GUI::Helpers::DisplayAssignment(a_list); },
						[]() {
							ImGui::TextWrapped("These duties deviate from those under the assignments section as they are conducted exclusively during their designated times.");
						}
					);
				}

				// Display protection duties
				if (ImGui::CollapsingHeader("<:: View Protection Duties ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"ProtectionDuties", "protection duties",
						LookupTables::RefreshProtectionDutyAssignmentsList,
						LookupTables::GetProtectionDutyAssignmentsList,
						[](const std::vector<CAssignment>& a_list) { GUI::Helpers::DisplayAssignment(a_list); },
						[]() {
							ImGui::TextWrapped("Protection teams have many daily responsibilities, with team leaders coordinating assignments to cover all duties.");
							ImGui::TextWrapped("At least one team should serve as well-armed reinforcement near key areas.");
							ImGui::TextWrapped("Dispatch & rank leaders are authorized to assign or reassign teams as necessary.");
						}
					);
				}

				// Display duty expectations + TAC etiquette
				if (ImGui::CollapsingHeader("<:: View Duty Expectations and TAC Etiquette ::>")) {
					GUI::Helpers::RenderRefreshableList(
						"DutyExpectationsTacEtiquette", "entries",		// Can't think of a better noun than "entries" lol
						LookupTables::RefreshAssignmentExpectationsList,
						LookupTables::GetAssignmentExpectationsList,
						[](const std::vector<CAssignment>& a_list) { GUI::Helpers::DisplayAssignment(a_list); }
					);
				}

				GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, "The beginning and end of a duty must be communicated into TAC.");
				GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, "Authorization is not required for a duty unless containment or lockdown procedure is in effect.");
			}
		);

		// Render contraband index
		GUI::Helpers::RenderSOPSection("<:: CONTRABAND INDEX ::> ",
			[this] {
				GUI::Helpers::RenderRefreshableList(
					"ContrabandCategories", "contraband categories",
					&LookupTables::RefreshContrabandList,
					&LookupTables::GetContrabandList,
					[this](const std::vector<CContraband>& a_list) { DisplayContrabandIndex(a_list); }
				);
			}
		);

		// Render location authorization index
		GUI::Helpers::RenderSOPSection("<:: LOCATION AUTHORIZATION INDEX ::>",
			[this] {
				// Patrol regions
				GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, "PATROL REGIONS");
				DisplayPatrolRegions();

				// Non-patrol regions
				GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, "NON-PATROL REGIONS");
				DisplayNonPatrolRegions();

				// Legend
				ImGui::TextWrapped("* Includes members of the Industrial and Medical Workforces");

				ImGui::TextColored(GUI::g_yellow_color, "*");
				ImGui::SameLine();
				ImGui::TextWrapped("Unless directly escorted & supervised by protection units");

				ImGui::TextColored(GUI::g_yellow_color, "**");
				ImGui::SameLine();
				ImGui::TextWrapped("Unless authorized or during an active situation");

			}
		);
	}

	void CCPSOPPanel::DisplayCodeInfo(const std::vector<CCode>& a_codes_list) {
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
						GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, name.c_str());
					}
					else if (name == "Containment Procedure" || name == "Lockdown Procedure") {
						GUI::Helpers::WrappedColoredText(GUI::g_red_color, name.c_str());
					}
					else { // Sociostable
						ImGui::TextWrapped("%s\n", name.c_str());
					}

					// Loop through the descriptions and display them
					for (const auto& description : code.GetOverrideDescription()) {
						GUI::Helpers::WrappedBulletText("%s\n", description.c_str());
					}

					// Loop through the directives and display them
					for (const auto& directive : code.GetOverrideDirectives()) {
						ImGui::TextWrapped("-> %s\n", directive.c_str());
					}

					ImGui::Separator();
					break;
				
				case ECodeType::VerdictCode:
					if (name == "PROSECUTION") {
						GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, name.c_str());
					}
					else if (name == "TERMINAL PROSECUTION" || name == "DISASSOCIATION" || name == "AMPUTATION" || name == "IMMEDIATE AMPUTATION") {
						GUI::Helpers::WrappedColoredText(GUI::g_red_color, name.c_str());
					}
					else { // Verbal Warning / Citation headers get displayed with default text color
						ImGui::TextWrapped("%s\n", name.c_str());
					}
					GUI::Helpers::WrappedBulletText("%s", code.GetDescription().c_str());
					ImGui::Separator();
					break;
				
				default:
					break;
			}
		}
	}

	void CCPSOPPanel::DisplayCivicRewardInfo(const std::vector<CCivicReward>& a_reward_list) {
		for (const auto& reward : a_reward_list) {
			ImGui::TextWrapped("%s: %s\n", reward.GetNumber().c_str(), reward.GetDescription().c_str());
			ImGui::Separator();
		}
	}

	void CCPSOPPanel::DisplayCivilStatusInfo(const std::vector<CCivilStatus>& a_civil_statuses_list) {
		GUI::Helpers::RenderTable(
			"CivilStatusTable",
			{ "CIVIL STATUS", "DEFINITION", "ADMINISTRATIVE DIRECTIVES" },
			[&] { // NOTE: Do not change the lambda capture clause here
				for (const auto& civil_status : a_civil_statuses_list) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0); // Status type + civic point range beneath
					std::string type = civil_status.GetStatusType();
					std::string type_and_range = type + "\n(" + civil_status.GetCivicPointRange() + ")";
					if (type_and_range.find("Non-citizen") != std::string::npos) { // Highlighted in the SOP doc
						GUI::Helpers::WrappedTableCellColoredText(GUI::g_yellow_color, type_and_range.c_str());
					}
					else {
						GUI::Helpers::WrappedTableCellText(type_and_range.c_str());
					}

					ImGui::TableSetColumnIndex(1); 	// Definition
					GUI::Helpers::WrappedTableCellText(civil_status.GetStatusDefinition().c_str());

					ImGui::TableSetColumnIndex(2);	// Directives in bullet form
					// Loop through interaction directives
					for (const auto& directive : civil_status.GetAdministrativeDirectives()) {
						GUI::Helpers::WrappedBulletText(directive.c_str());
					}
				}
			}
		);
	}

	void CCPSOPPanel::DisplayPolitiSchedule() {
		GUI::Helpers::RenderTable(
			"PolitiScheduleTable",
			{ "TIME START", "TIME END", "MANDATE", "LENGTH" },
			[] {
				for (const auto& schedule : CPSOP::TableData::politi_schedule_table_data) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					GUI::Helpers::WrappedTableCellText(schedule.m_time_started.c_str());

					ImGui::TableSetColumnIndex(1);
					GUI::Helpers::WrappedTableCellText(schedule.m_time_end.c_str());

					ImGui::TableSetColumnIndex(2);
					if (schedule.m_mandate == "Ration Intake") {
						GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, "%s", schedule.m_mandate.c_str());
					}
					else if (schedule.m_mandate == "Curfew Procedure") {
						GUI::Helpers::WrappedColoredText(GUI::g_red_color, "%s", schedule.m_mandate.c_str());
					}
					else {
						GUI::Helpers::WrappedTableCellText(schedule.m_mandate.c_str());
					}

					ImGui::TableSetColumnIndex(3);
					GUI::Helpers::WrappedTableCellText(schedule.m_length.c_str());
				}
			}

		);
		
	}

	void CCPSOPPanel::DisplayOverrideCodeTable() {
		GUI::Helpers::RenderTable(
			"OverrideCodesTable", 
			{ "STATUS", "SOCIOSTABLE", "UNREST", "CONTAINMENT", "LOCKDOWN" },
			[] {
				for (const auto& override_code : CPSOP::TableData::override_code_table_data) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);

					ImGui::Text("%s", override_code.m_status_index.c_str());

					ImGui::TableSetColumnIndex(1);
					ImGui::Text("%s", override_code.m_sociostable_index.c_str());

					ImGui::TableSetColumnIndex(2);
					GUI::Helpers::WrappedColoredText(GUI::g_yellow_color, override_code.m_unrest_index.c_str());

					ImGui::TableSetColumnIndex(3);
					GUI::Helpers::WrappedColoredText(GUI::g_red_color, override_code.m_containment_index.c_str());

					ImGui::TableSetColumnIndex(4);
					GUI::Helpers::WrappedColoredText(GUI::g_red_color, override_code.m_lockdown_index.c_str());
				}
			}
		);
	}

	void CCPSOPPanel::DisplayViolationCodesTable(const std::string& a_table_label, const std::vector<CCode>& a_violation_codes) {
		GUI::Helpers::RenderTable(
			a_table_label.c_str(),
			{ "CODE", "VIOLATION", "DESCRIPTION" },
			[&] {
				// Iterate over rows 
				for (const auto& violation : a_violation_codes) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					ImGui::TextWrapped("%s", violation.GetName().c_str());

					ImGui::TableSetColumnIndex(1);
					ImGui::TextWrapped("%s", violation.GetDescription().c_str());

					ImGui::TableSetColumnIndex(2);
					ImGui::TextWrapped("%s", violation.GetViolationDescription().c_str());

					switch (violation.GetViolationCodeNote()) {
						case EViolationCodeNote::None:
							break;

						case EViolationCodeNote::SanctionedDistribution:
							ImGui::SameLine();
							ImGui::TextColored(GUI::g_yellow_color, "*");
							break;

						case EViolationCodeNote::FirearmsCharge:
							ImGui::Text("(charge ");
							ImGui::SameLine(0.0f, 0.0f);
							ImGui::TextColored(GUI::g_red_color, "all firearms");
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

	void CCPSOPPanel::DisplayViolationLevelsTable() {
		GUI::Helpers::RenderTable(
			"ViolationLevelsTable", 
			{ "LEVEL", "DESCRIPTION", "VERDICT (RECOMMENDED)" },
			[] {
				for (const auto& row : CPSOP::TableData::violation_level_table_data) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);

					switch (row.m_level) {
						case 3:
							// Moderate severity = yellow color text
							ImGui::TextColored(GUI::g_yellow_color, "%i", row.m_level);
							break;

						case 4:
						case 5:
							// High severity = red color text
							ImGui::TextColored(GUI::g_red_color, "%i", row.m_level);
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
						// Render string based on substring contained within verdict
						if (verdict.find("Prosecution") != std::string::npos) {
							GUI::Helpers::WrappedBulletColoredText(GUI::g_yellow_color, "%s", verdict.c_str());
						}
						else if ((verdict.find("Amputation")			!= std::string::npos)
							|| (verdict.find("Immediate amputation")	!= std::string::npos)
							|| (verdict.find("Disassociation")			!= std::string::npos) 
							|| (verdict.find("Terminal prosecution")	!= std::string::npos)) {

							GUI::Helpers::WrappedBulletColoredText(GUI::g_red_color, "%s", verdict.c_str());
						}
						else {
							GUI::Helpers::WrappedBulletText("%s", verdict.c_str()); // Verbal Warning & Citation
						}
						
					}
				}
			}
		);
	}

	void CCPSOPPanel::DisplayContrabandIndex(const std::vector<CContraband>& a_contraband_list) {
		for (const auto& category : a_contraband_list) {
			// Display the violation code's name, description
			ImGui::TextWrapped("%s: %s\n", category.GetViolationCode().GetName().c_str(), category.GetViolationCode().GetDescription().c_str());

			// Loop through each example for each category
			for (const auto& example : category.GetExamples()) {
				GUI::Helpers::WrappedBulletText("%s", example.c_str());
			}

			// Separate each contraband type with a line separator
			ImGui::Separator();
		}
	}

	void CCPSOPPanel::DisplayPatrolRegions() {
		GUI::Helpers::RenderTable(
			"PatrolRegionTable",
			{ "Location", "Civic Populace *", "Engineer Core", "Infestation Control", "Civil Protection" },
			[] {
				// Iterate over rows 
				for (const auto& row : CPSOP::TableData::patrol_region_table_data) {
					ImGui::TableNextRow();

					// Location column 
					// - Doesn't contain conditionals
					ImGui::TableSetColumnIndex(0);
					GUI::Helpers::WrappedTableCellText(row.m_location.m_index.c_str());

					// Civic Populace column
					ImGui::TableSetColumnIndex(1);
					if (row.m_civic_populace.m_requires_civil_protection_supervision) {
						ImGui::TextColored(GUI::g_red_color, "%s", row.m_civic_populace.m_index.c_str());
						ImGui::SameLine();
						ImGui::TextColored(GUI::g_yellow_color, "*");
					}
					else if (row.m_civic_populace.m_index == "Access Protocol") {
						ImGui::TextColored(GUI::g_yellow_color, row.m_civic_populace.m_index.c_str());
					}
					else {
						ImGui::TextWrapped("%s", row.m_civic_populace.m_index.c_str());
					}

					// Engineer Core column
					ImGui::TableSetColumnIndex(2);
					if (row.m_engineer_core.m_requires_civil_protection_supervision) {
						ImGui::TextColored(GUI::g_red_color, "%s", row.m_engineer_core.m_index.c_str());
						ImGui::SameLine();
						ImGui::TextColored(GUI::g_yellow_color, "*");
					}
					else if (row.m_engineer_core.m_index == "Access Protocol") {
						ImGui::TextColored(GUI::g_yellow_color, row.m_engineer_core.m_index.c_str());
					}
					else {
						ImGui::TextWrapped("%s", row.m_engineer_core.m_index.c_str());
					}

					// Infestation Control column
					ImGui::TableSetColumnIndex(3);
					if (row.m_infestation_control.m_requires_civil_protection_supervision) {
						ImGui::TextColored(GUI::g_red_color, "%s", row.m_infestation_control.m_index.c_str());
						ImGui::SameLine();
						ImGui::TextColored(GUI::g_yellow_color, "*");
					}
					else if (row.m_infestation_control.m_index == "Access Protocol") {
						ImGui::TextColored(GUI::g_yellow_color, row.m_infestation_control.m_index.c_str());
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

	void CCPSOPPanel::DisplayNonPatrolRegions() {
		GUI::Helpers::RenderTable(
			"NonPatrolRegionTable",
			{ "Location", "Civic Populace *", "Engineer Core", "Infestation Control", "Civil Protection" },
			[] {
				for (const auto& row : CPSOP::TableData::non_patrol_region_table_data) {
					ImGui::TableNextRow();

					// NOTE: Location & civic populace don't have their own special cases like with engineer core & infestation control
					ImGui::TableSetColumnIndex(0);
					GUI::Helpers::WrappedTableCellText(row.m_location.m_index.c_str());

					ImGui::TableSetColumnIndex(1);
					ImGui::TextColored(GUI::g_red_color, "%s", row.m_civic_populace.m_index.c_str());


					ImGui::TableSetColumnIndex(2);
					if (row.m_engineer_core.m_requires_civil_protection_supervision) {
						ImGui::TextColored(GUI::g_red_color, "%s", row.m_engineer_core.m_index.c_str());
						ImGui::SameLine();
						ImGui::TextColored(GUI::g_yellow_color, "*");
					}
					else {
						GUI::Helpers::WrappedColoredText(GUI::g_red_color, "%s", row.m_engineer_core.m_index.c_str());
					}

					ImGui::TableSetColumnIndex(3);
					if (row.m_infestation_control.m_requires_civil_protection_supervision) {
						ImGui::TextColored(GUI::g_red_color, "%s", row.m_infestation_control.m_index.c_str());
						ImGui::SameLine();
						ImGui::TextColored(GUI::g_yellow_color, "*");
					}
					else {
						GUI::Helpers::WrappedColoredText(GUI::g_red_color, "%s", row.m_infestation_control.m_index.c_str());
					}

					ImGui::TableSetColumnIndex(4);
					if (row.m_civil_protection.m_requires_special_authorization) {
						ImGui::TextColored(GUI::g_red_color, "%s", row.m_civil_protection.m_index.c_str());
						ImGui::SameLine();
						ImGui::TextColored(GUI::g_yellow_color, "**");
					}
					else {
						ImGui::TextWrapped("%s", row.m_civil_protection.m_index.c_str());
					}
				}
			}
		);
	}

	void CCPSOPPanel::DisplayResidentialBlockTable() {
		GUI::Helpers::RenderTable(
			"ResidentialBlockTable", 
			{ "LOCATION", "CAPACITY" }, 
			[] {
				for (const auto& row : CPSOP::TableData::residential_block_table_data) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					ImGui::TextWrapped("%s", row.m_area.c_str());

					ImGui::TableSetColumnIndex(1);
					ImGui::TextWrapped("%s", row.m_capacity.c_str());
				}
			}
		);

	}


}