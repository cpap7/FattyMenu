#include "CPSOP.h"

/* Displays ASCII art of the Civil Protection symbol */
void CPSOP::DisplayLogo() {
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

/* TODO: fix lambda functions and streamline everything to use template structure outlined in CPSOP.h
	CPSOP::DisplayList(codes_list, [] (const CCode& code) {
		ImGui::TextWrapped("%s: %s", code.GetCodeName(), code.GetCodeDescription());

		if (code.IsViolationCode()) {
			GUIUtils::WrappedBulletText("Violation Reason: %s", code.GetViolationDescription());
		}

		if (code.IsOverrideCode()) {
			if (!code.GetOverrideDescription().empty()) {
				if (ImGui::TreeNode("Override Description")) {
					for (const auto& line : code.GetOverrideDescription()) {
						GUIUtils::WrappedBulletText("%s", line);
					}
					ImGui::TreePop();
				}
			}

			if (!code.GetOverrideDirectives().empty()) {
				if (ImGui::TreeNode("Override Directives")) {
					for (const auto& directive : code.GetOverrideDirectives()) {
						GUIUtils::WrappedBulletText("%s", directive);
					}
					ImGui::TreePop();
				}
			}
		}
	});
	*/

// Function for displaying radio codes
// @param codes_list -> vector containing a list of radio codes to be looped through and displayed
void CPSOP::DisplayCodes(const std::vector<CCode> codes_list) {
	// Loop through the radio codes
	for (const auto& code : codes_list) {
		// Check if the code is an override code, which contains lists of strings
		if (code.IsOverrideCode()) {
			// Display the override code, descriptions, and directives
			ImGui::TextWrapped("%s\n", code.GetCodeName());

			// Loop through the descriptions and display them
			for (const auto& description : code.GetOverrideDescription()) {
				GUIUtils::WrappedBulletText("%s\n", description);
			}
			
			// Loop through the directives and display them
			for (const auto& directive : code.GetOverrideDirectives()) {
				ImGui::TextWrapped("-> %s\n", directive);
			}
		}

		// Check if the code is a violation, which has 3 strings
		else if (code.IsViolationCode()) {
			// Display 3 strings as wrapped text
			GUIUtils::WrappedBulletText("%s: %s\n -> %s", code.GetCodeName(), code.GetCodeDescription(), code.GetViolationDescription());
		}

		else { // Display other codes (10-, 11-, etc.)
			// Display 2 strings as wrapped bullet text
			GUIUtils::WrappedBulletText("%s: %s", code.GetCodeName(), code.GetCodeDescription());
		}
		// Separate each with a line separator
		ImGui::Separator();
	}
}

// Function for displaying civic point and ration rewards for public service details and civic deeds
// @param reward_list -> vector containing each type of civic duty that a unit can issue a reward for, which is looped through and displayed
void CPSOP::DisplayRewardInfo(const std::vector<CCivicReward> reward_list) {
	// Loop through the rewards
	for (const auto& reward : reward_list) {
		// Display them as bullet text
		ImGui::TextWrapped("%s: %s\n", reward.GetNumber(), reward.GetDescription());
		GUIUtils::WrappedBulletText("+%d Civic Points\n", reward.GetCivicPoints());
		GUIUtils::WrappedBulletText("Ration Reward: %s\n", reward.GetRationRewardDescription());
		
		// Separate each with a line separator
		ImGui::Separator();
	}
}

void CPSOP::DisplayInteractionDirectives(const std::vector<CCivilStatus> civil_status_list) {
	// Loop through the different status types
	for (const auto& civil_status : civil_status_list) {
		// Display the name of the status type, and the civic point range
		ImGui::TextWrapped("%s (%s)\n", civil_status.GetStatusType(), civil_status.GetCivicPointRange());
		
		// Display the definition of the civic status type
		GUIUtils::WrappedBulletText("%s\n", civil_status.GetStatusDefinition());
		
		// Loop through interaction directives
		for (const auto& directive : civil_status.GetInteractionDirectives()) {
			GUIUtils::WrappedBulletText("%s\n", directive);
		}

		// Separate each status type with a line separator
		ImGui::Separator();
	}
}

// Function for displaying Combine terminology
// @param terms_list -> vector containing a list of terms to be looped through and displayed
void CPSOP::DisplayTerms(const std::vector<CTerm> terms_list) {
	// Loop through the terms in the vector list
	for (const auto& term : terms_list) {
		// Display them as bullet text
		GUIUtils::WrappedBulletText("%s: %s", term.GetName(), term.GetDescription());

		// Separate each with a line separator
		ImGui::Separator();
	}
}

// Function for displaying Politi-Schedule
// @param politi_schedule_list -> vector containing a list of events to be looped through and displayed
void CPSOP::DisplayPolitiSchedule(const std::vector<CPolitiSchedule> politi_schedule_list) {
	// Create the table for the schedule
	ImGui::BeginTable("PolitiSchedule", 4, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg);
	
	// Set up columns
	ImGui::TableSetupColumn("TIME START");
	ImGui::TableSetupColumn("TIME END");
	ImGui::TableSetupColumn("MANDATE"); 
	ImGui::TableSetupColumn("LENGTH");
	ImGui::TableHeadersRow();

	// Loop through each event
	for (const auto& event : politi_schedule_list) {
		ImGui::TableNextRow();

		// Display the time the event starts
		ImGui::TableSetColumnIndex(0);
		ImGui::Text("%s", event.GetTimeStart());

		// Display the time the event ends
		ImGui::TableSetColumnIndex(1);
		ImGui::Text("%s", event.GetTimeEnd());

		// Display the mandate
		ImGui::TableSetColumnIndex(2);
		ImGui::Text("%s", event.GetMandate());

		// Display the time length
		ImGui::TableSetColumnIndex(3);
		ImGui::Text("%s", event.GetTimeLength());
	}

	ImGui::EndTable();
	
	/* Old janky version
	ImGui::Text("%-15s %-15s %-30s %-15s", "TIME START", "TIME END", "MANDATE", "LENGTH");
    ImGui::Separator();

    // Loop through the Politi-Schedule events
    for (const auto& event : politi_schedule_list) {
        // Display start time, end time, mandate, and time length and align them
        ImGui::Text("%-15s %-15s %-30s %-15s", event.GetTimeStart(), event.GetTimeEnd(), event.GetMandate(), event.GetTimeLength());
    }
	*/
}


// Function for displaying mandate and assignment duties
// @param duties_list -> vector containing a list of duties to be looped through and displayed
void CPSOP::DisplayDuties(const std::vector<CAssignment> duties_list) {
	// Loop through the duties in the vector list
	for (const auto& duty : duties_list) {
		// Display assignment name and the # of required units
		ImGui::TextWrapped("%s\n%s", duty.GetAssignmentName(), duty.GetUnitsRequired());

		// Display each string description
		for (const auto& description : duty.GetAssignmentDescription()) {
			GUIUtils::WrappedBulletText("%s", description);
		}

		// Separate each duty with a line separator
		ImGui::Separator();
	}
}

// Function for displaying contraband index
// @param contraband_list -> vector containing a list of contraband, their verdict codes, and examples to be looped through and displayed
void CPSOP::DisplayContrabandIndex(const std::vector<CContraband> contraband_list) {
	// Loop through the contraband categories
	for (const auto& category : contraband_list) {
		// Display the violation code's name, description
		ImGui::TextWrapped("%s: %s\n%s\n", category.GetViolationCode().GetCodeName(), category.GetViolationCode().GetCodeDescription(), category.GetVerdict());

		// Loop through each example for each category
		for (const auto& example : category.GetExamples()) {
			GUIUtils::WrappedBulletText("%s", example);
		}

		// Separate each contraband type with a line separator
		ImGui::Separator();
	}
}



void CPSOP::RenderCivilProtectionSOP() {
	// Print the ASCII art logo
	DisplayLogo();

	// Collapsing headers render info once the user clicks on them

	// Display the code index, render the subheaders via the inline helper function
	RenderSOPSection("<:: CODE INDEX ::>", [] {
		// Clicking the first header displays these options
		if (ImGui::CollapsingHeader("<:: View Abbreviations ::>")) {
			DisplayCodes(CPSOPLookupTables::abbreviation_list);
		}
		if (ImGui::CollapsingHeader("<:: View Response Codes ::>")) {
			DisplayCodes(CPSOPLookupTables::response_code_list);
		}
		if (ImGui::CollapsingHeader("<:: View 11- Codes ::>")) {
			DisplayCodes(CPSOPLookupTables::eleven_code_list);
		}
		if (ImGui::CollapsingHeader("<:: View 10- Codes ::>")) {
			DisplayCodes(CPSOPLookupTables::ten_code_list);
		}
		if (ImGui::CollapsingHeader("<:: View Code Violations ::>")) {
			ImGui::Text("Anti-Civil Level 5\n -> Verbal warning and/or citation\n");
			DisplayCodes(CPSOPLookupTables::anti_civil_level_5_violations);

			ImGui::Text("\nAnti-Civil Level 1\n -> Prosecution: Sentencing is discretionary\n -> -10 civic points, 4 min sentence time\n");
			DisplayCodes(CPSOPLookupTables::anti_civil_level_1_violations);

			ImGui::Text("\nSocio-Endangerment Level 5\n -> Prosecution: Dispatch approval required before proceeding\n -> -25 civic points, 6 min sentence time\n");
			DisplayCodes(CPSOPLookupTables::socio_endangerment_level_5_violations);

			ImGui::Text("\nSocio-Endangerment Level 1\n -> Prosecution: Dispatch approval required before proceeding\n -> -25 civic points, 8 min sentence time\n");
			DisplayCodes(CPSOPLookupTables::socio_endangerment_level_1_violations);
		}
		if (ImGui::CollapsingHeader("<:: View Override Codes ::>")) {
			DisplayCodes(CPSOPLookupTables::override_code_list);
		}
	});
	
	// Display civic point reward sections
	RenderSOPSection("<:: CIVIC REWARD & INTERACTION INDEX ::>", [] {
		if (ImGui::CollapsingHeader("<:: View Public Service Details ::>")) {
			DisplayRewardInfo(CPSOPLookupTables::public_service_detail_list);
		}
		if (ImGui::CollapsingHeader("<:: View Civic Deeds ::>")) {
			DisplayRewardInfo(CPSOPLookupTables::civic_deed_list);
		}
		if (ImGui::CollapsingHeader("<:: View Interaction Directives ::>")) {
			DisplayInteractionDirectives(CPSOPLookupTables::citizen_interaction_directive_list);
		}
	});

	// Display terminology index sections
	RenderSOPSection("<:: TERMINOLOGY INDEX ::>", [] {
		if (ImGui::CollapsingHeader("<:: View Protocol Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::protocol_list);
		}
		if (ImGui::CollapsingHeader("<:: View Action Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::action_list);
		}
		if (ImGui::CollapsingHeader("<:: View Action-Condition Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::action_condition_list);
		}
		if (ImGui::CollapsingHeader("<:: View Hostile Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::hostile_list);
		}
		if (ImGui::CollapsingHeader("<:: View Equipment/Asset Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::equipment_asset_list);
		}
		if (ImGui::CollapsingHeader("<:: View Organization Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::organization_list);
		}
		if (ImGui::CollapsingHeader("<:: View Sociostability Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::sociostability_list);
		}
		if (ImGui::CollapsingHeader("<:: View Area Terms ::>")) {
			DisplayTerms(CPSOPLookupTables::area_list);
		}

	});

	// Render politi schedule index
	RenderSOPSection("<:: POLITI-SCHEDULE INDEX ::>", [] {
		// Display politi schedule
		DisplayPolitiSchedule(CPSOPLookupTables::politi_schedule_event_list);
	});

	// Render duty index
	RenderSOPSection("<:: DUTY INDEX ::> ", [] {
		// Display mandate duties
		if (ImGui::CollapsingHeader("<:: View Mandate Duties ::>")) {
			DisplayDuties(CPSOPLookupTables::mandate_duties_list);
		}

		// Display protection duties
		if (ImGui::CollapsingHeader("<:: View Protection Duties ::>")) {
			DisplayDuties(CPSOPLookupTables::protection_duties_list);
		}

		// Display duty expectations + TAC etiquette
		if (ImGui::CollapsingHeader("<:: View Duty Expectations and TAC Etiquette ::>")) {
			DisplayDuties(CPSOPLookupTables::miscellaneous_duties_list);
		}
	});

	// Render contraband index
	RenderSOPSection("<:: CONTRABAND INDEX ::> ", [] {
		DisplayContrabandIndex(CPSOPLookupTables::contraband_list);
	});

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