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
	void CPSOP::DisplayCPRewardInfo(const std::vector<CCivicReward>& a_reward_list) {
		// Loop through the rewards
		for (const auto& reward : a_reward_list) {
			// Display them as bullet text
			ImGui::TextWrapped("%s: %s\n", reward.GetNumber(), reward.GetDescription());

			// Separate each with a line separator
			ImGui::Separator();
		}
	}

	void CPSOP::DisplayCPInteractionDirectives(const std::vector<CCivilStatus>& a_civil_status_list) {
		// Loop through the different status types
		for (const auto& civil_status : a_civil_status_list) {
			// Display the name of the status type, and the civic point range
			ImGui::TextWrapped("%s (%s)\n", civil_status.GetStatusType(), civil_status.GetCivicPointRange());

			// Display the definition of the civic status type as wrapped bullet text
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
	void CPSOP::DisplayCPPolitiSchedule(const std::vector<CPolitiSchedule>& a_politi_schedule_list) {
		// Create the table for the schedule
		ImGui::BeginTable("PolitiSchedule", 4, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("TIME START");
		ImGui::TableSetupColumn("TIME END");
		ImGui::TableSetupColumn("MANDATE");
		ImGui::TableSetupColumn("LENGTH");
		ImGui::TableHeadersRow();

		// Loop through each event
		for (const auto& event : a_politi_schedule_list) {
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
	}

	void CPSOP::DisplayOverrideCodeTable() {
		ImVec4 red_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red color for "Not permitted" entries
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries

		static const SOverrideCodeRow rows[] = {
			// Columns:
			// Status 				 Sociostable			Unrest			 Containment	  Lockdown
			{ "Ration Intake",		"Active",			"Discretionary",	"Suspended",	"Suspended"		},
			{ "Workforce Status",	"Active",			"Discretionary",	"Suspended",	"Suspended"		},
			{ "Shield Access",		"Civic Populace",	"Workforce",		"Ground Units", "Ground Units"	},
			{ "Weapon Protocol",	"Holstered",		"Unholstered",		"Raised",		"Raised"		}
		};

		
		// Create the table for the override code directives
		ImGui::BeginTable("OverrideCodes", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

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
			
			ImGui::Text("%s", status.m_status_index);

			ImGui::TableSetColumnIndex(1);
			ImGui::Text("%s", status.m_sociostable_index);

			ImGui::TableSetColumnIndex(2);
			ImGui::Text("%s", status.m_unrest_index);

			ImGui::TableSetColumnIndex(3);
			ImGui::Text("%s", status.m_containment_index);

			ImGui::TableSetColumnIndex(4);
			ImGui::Text("%s", status.m_lockdown_index);
		}

		ImGui::EndTable();
	}

	// For displaying violation levels table
	void CPSOP::DisplayViolationLevelsTable() {
		ImVec4 red_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red color for "Not permitted" entries
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries

		static const SViolationLevelRow rows[] = {
			// Columns:
			{ 
				// Level
				1,

				// Description
				"Minor, isolated, accidental or first-time violation with negligable impact on sociostability. Little or no harm, disruption, interference or resistance is present",
				
				// Verdict (Recommended) 	
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
		ImGui::BeginTable("ViolationLevels", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("LEVEL");
		ImGui::TableSetupColumn("DESCRIPTION");
		ImGui::TableSetupColumn("VERDICT (RECOMMENDED)");
		

		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& row : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			if (row.m_level == 1) {
				ImGui::TextWrapped("1", row.m_level);
			}

			if (row.m_level == 2) {
				ImGui::TextWrapped("2", row.m_level);
			}

			if (row.m_level == 3) {
				ImGui::TextColored(yellow_color, "%i", row.m_level);
			}

			if (row.m_level == 4 || row.m_level == 5) {
				ImGui::TextColored(red_color, "%i", row.m_level);
			}
	


			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", row.m_description);

			ImGui::TableSetColumnIndex(2);
			for (const auto& verdict : row.m_recommended_verdicts) {
				if (verdict == "Verbal Warning" || verdict == "Citation") {
					GUI::Helpers::WrappedBulletText("%s", verdict);
			}
				if (verdict == "Prosecution") {
					GUI::Helpers::WrappedBulletTextColored(yellow_color, "%s", verdict);
			}
				if (verdict == "Amputation\n(if necessary to display authority amongst populace)" || verdict == "Disassociation\n(if labor required)" | verdict == "Terminal prosecution")
					GUI::Helpers::WrappedBulletTextColored(red_color, "%s", verdict);
	  }
	}

		ImGui::EndTable();
	}

	// Function for displaying contraband index
	// @param contraband_list -> vector containing a list of contraband, their verdict codes, and examples to be looped through and displayed
	void CPSOP::DisplayCPContrabandIndex(const std::vector<CContraband>& a_contraband_list) {
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
		ImVec4 red_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red color for "Not permitted" entries
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries

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
		ImGui::BeginTable("LocationAuthorization", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

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

			// Location & civil protection don't have their own conditionals
			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", row.m_location.m_index.c_str());

			ImGui::TableSetColumnIndex(1);
			if (row.m_civic_populace.m_requires_civil_protection_supervision) {
				ImGui::TextColored(red_color, "%s", row.m_civic_populace.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(yellow_color, "*");
			}
			else if (row.m_civic_populace.m_index == "Access Protocol") {
				ImGui::TextColored(yellow_color, row.m_civic_populace.m_index.c_str());
			}
			else {
				ImGui::TextWrapped("%s", row.m_civic_populace.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(2);
			if (row.m_engineer_core.m_requires_civil_protection_supervision) {
				ImGui::TextColored(red_color, "%s", row.m_engineer_core.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(yellow_color, "*");
			}
			else if (row.m_engineer_core.m_index == "Access Protocol") {
				ImGui::TextColored(yellow_color, row.m_engineer_core.m_index.c_str());
			}
			else {
				ImGui::TextWrapped("%s", row.m_engineer_core.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(3);
			if (row.m_infestation_control.m_requires_civil_protection_supervision) {
				ImGui::TextColored(red_color, "%s", row.m_infestation_control.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(yellow_color, "*");
			}
			else if (row.m_infestation_control.m_index == "Access Protocol") {
				ImGui::TextColored(yellow_color, row.m_infestation_control.m_index.c_str());
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
		ImVec4 red_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red color for "Not permitted" entries
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries

		static const SLocationAuthorizationRow rows[] = {
			// Columns:
			// Location 									Civic Populace					Engineer Core						Infestation Control					Civil Protection
			{ { "Restricted Block", false },			{ "Not Permitted", false },			{ "Not Permitted", true },			{ "Not Permitted", true },			{ "Not Permitted", false, true } },
			{ { "Storm System", false },				{ "Not Permitted", false },			{ "Not Permitted", true },			{ "Not Permitted", true },			{ "Not Permitted", false, true } },
			{ { "Outland Zone",	false },				{ "Not Permitted", false },			{ "Not Permitted", true },			{ "Not Permitted", false },         { "Not Permitted", false, true } },
			{ { "Terminal Restriction Zone", false },	{ "Not Permitted", false },			{ "Not Permitted", false },			{ "Not Permitted", false },			{ "Not Permitted", false, true } },

		};


		// Create the table for the override code directives
		ImGui::BeginTable("LocationAuthorization", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

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

			// Location & civic populace don't have their own conditionals
			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", row.m_location.m_index.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextColored(red_color, "%s", row.m_civic_populace.m_index.c_str());


			ImGui::TableSetColumnIndex(2);
			if (row.m_engineer_core.m_requires_civil_protection_supervision) {
				ImGui::TextColored(red_color, "%s", row.m_engineer_core.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(yellow_color, "*");
			}
			else {
				GUI::Helpers::WrappedTextColored(red_color, "%s", row.m_engineer_core.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(3);
			if (row.m_infestation_control.m_requires_civil_protection_supervision) {
				ImGui::TextColored(red_color, "%s", row.m_infestation_control.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(yellow_color, "*");
			}
			else {
				GUI::Helpers::WrappedTextColored(red_color, "%s", row.m_infestation_control.m_index.c_str());
			}

			ImGui::TableSetColumnIndex(4);
			if (row.m_civil_protection.m_requires_special_authorization) {
				ImGui::TextColored(red_color, "%s", row.m_civil_protection.m_index.c_str());
				ImGui::SameLine();
				ImGui::TextColored(yellow_color, "**");
			}
			else {
				ImGui::TextWrapped("%s", row.m_civil_protection.m_index.c_str());
			}
		}

		ImGui::EndTable();
	}

	void CPSOP::DisplayCommunalPunishmentsTable() {
	ImVec4 red_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	   ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries */
		static const SCommunalRow rows[] = {
			// Columns:
			// Code			Violation						Description
		   { "Residental Block 1", "4 residents per room"          },
		   { "Residental Block 3", "10 residents per room"         },
		   { "Residental Block 4", "6 residents per room"          },
		   { "Residental Block 5", "4 residents per room"          },
		   { "Residental Block 8", "Unlimited capacity (overflow)" },

		};

		// Create the table for the violation levels
		ImGui::BeginTable("CommunalPunishments", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

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


	// For displaying violation code, name and description
	void CPSOP::DisplayViolationCivicTrustTable() {
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries
		static const SViolationRow rows[] = {
			// Columns:
			// Code				Violation							Description
			{ "27",				"Attempted Crime",					"Attempting a violation without successful completion",			false	},
			{ "54",				"Possession of materials",			"Possession of minor contraband articles",						false	},
			{ "62",				"Alarms",							"Knowingly making false reports to Civil Protection",			false	},
			{ "69",				"Possession of resources",			"Possession of moderate contraband articles",					false	},
			{ "91",		        "Non-sanctioned distribution",      "Distributing items outside authorized distribution zones",		true	},
			{ "99",				"Reckless Operation",		        "Unsafe or negligent operation of equipment",					false	},
			{ "311",			"Verbal Indescretion",	            "Loitering or excessive conversation without civic purpose",	false	},
			{ "374b",			"Illegal disposal",		            "Littering, defacement, or unsanitary waste disposal",			false	},
			{ "488",			"Theft",	                        "Unlawful taking or scavenging of property",					false	},
			{ "647e",           "Disengaged from Workforce",        "Deviating from assigned duties or non-corplex status",			false	},
			{ "647f",           "Civic dysfunction",                "Public intoxication or impairment",							false	},

		};

		// Create the table for the violation levels
		ImGui::BeginTable("CivicTrustCodeViolations", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		//ImGui::TableHeader("VIOLATION OF CIVIC TRUST");
		ImGui::TableSetupColumn("CODE");
		ImGui::TableSetupColumn("VIOLATION");
		ImGui::TableSetupColumn("DESCRIPTION");


		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& violation : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", violation.m_code.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", violation.m_violation.c_str());

			ImGui::TableSetColumnIndex(2);
			if (violation.m_description == "Distributing items outside authorized distribution zones") {
				ImGui::TextWrapped("%s", violation.m_description.c_str());
				ImGui::SameLine();
				ImGui::TextColored(yellow_color, "*");
			}
			else {
				ImGui::TextWrapped("%s", violation.m_description.c_str());
			}
		}

		ImGui::EndTable();
	}

	// For displaying violation code, name and description
	void CPSOP::DisplayViolationCivilWillTable() {
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries
		static const SViolationRow rows[] = {
			// Columns:
			// Code				Violation							Description
			{ "35",				"Civil privacy violation",			"Unauthorized intrusion, observation or harassment",		false },
			{ "59",				"Movement trangression",			"Excessive running, climbing, or unauthorized movement",	false },
			{ "63",				"Criminal trespass",				"Entering a restricted area without authorization",			false },
			{ "148",			"Resisting Arrest",					"Resisting, evading or fleeing from prosecution",			false },
			{ "507",		    "Public non-compliance",			"Failure to comply with lawful directives",					false },

		};

		// Create the table for the violation levels
		ImGui::BeginTable("CivilWillCodeViolations", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		//ImGui::TableHeader("FAILURE TO COMPLY WITH THE CIVIL WILL");
		ImGui::TableSetupColumn("CODE");
		ImGui::TableSetupColumn("VIOLATION");
		ImGui::TableSetupColumn("DESCRIPTION");


		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& violation : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", violation.m_code.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", violation.m_violation.c_str());

			ImGui::TableSetColumnIndex(2);
			ImGui::TextWrapped("%s", violation.m_description.c_str());
		}

		ImGui::EndTable();

	}

	// For displaying violation code, name and description
	void CPSOP::DisplayViolationCommunalUnrestTable() {
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries
		static const SViolationRow rows[] = {
			// Columns:
			// Code				Violation				Description
			{ "28",				"Felony incite",		"Encouraging or directing others to commit violations", false },
			{ "404",		    "Riot",	                "Participating in or promoting communal unrest",		false },
			{ "407",			"Unlawful Assembly",	"Unauthorized gathering posing a stability risk",		false },
			{ "415",			"Civic disunity",	    "Disturbing public order assaulting civilians",			false },

		};

		// Create the table for the violation levels
		ImGui::BeginTable("CommunalUnrestCodeViolations", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("CODE");
		ImGui::TableSetupColumn("VIOLATION");
		ImGui::TableSetupColumn("DESCRIPTION");


		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& violation : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", violation.m_code.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", violation.m_violation.c_str());

			ImGui::TableSetColumnIndex(2);
			ImGui::TextWrapped("%s", violation.m_description.c_str());
		}

		ImGui::EndTable();

	}

	// For displaying violation code, name and description
	void CPSOP::DisplayViolationDivisiveSociocidalTable() {
		ImVec4 red_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries
		static const SViolationRow rows[] = {
			// Columns:
			// Code			Violation						Description
			{ "17f",		"Fugitive Detachment",		"Haboring or concealing wanted individuals",		false },
			{ "51",		    "Non-sanctioned arson",		"Starting or spreading fire without authorization", false },
			{ "63s",		"Illegal in operation",		"Obstruction of authorized civic operations",		false },
			{ "94",			"Weapon",					"Possession or use of any firearm",					false },
			{ "95",			"Illegal Carrying",			"Possession of major contraband articles",			false },
			{ "603",        "Unlawful entry",			"Gaining entry through force, fraud, or deception", false },

		};

		// Create the table for the violation levels
		ImGui::BeginTable("DivisiveSociocidalCodeViolations", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		ImGui::TableSetupColumn("CODE");
		ImGui::TableSetupColumn("VIOLATION");
		ImGui::TableSetupColumn("DESCRIPTION");


		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& violation : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", violation.m_code.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", violation.m_violation.c_str());

			ImGui::TableSetColumnIndex(2);
			if (violation.m_description == "Possession of major contraband articles") {
				ImGui::TextWrapped("\n%s", violation.m_description.c_str());
				ImGui::TextWrapped("(charge");
				ImGui::SameLine();
				ImGui::TextColored(red_color, "all firearms");
				ImGui::SameLine();
				ImGui::TextWrapped("with 94 weapon instead)");
			}
			else {
				ImGui::TextWrapped("%s", violation.m_description.c_str());
			}
		}

		ImGui::EndTable();

	}

	void CPSOP::DisplayViolationDestructionTable() {
		ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for "*" entries
		static const SViolationRow rows[] = {
			// Columns:
			// Code				Violation							Description
			{ "51b",			"Threat to property",				"Damage to CMB equipment or infrastructure",													false },
			{ "243",			"Assault on protection team",		"Direct, violent attack(s) on Overwatch forces w/ intent to cause great bodily harm or death",	false },
		};


		// Create the table for the violation levels
		ImGui::BeginTable("DestructionCodeViolations", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);

		// Set up columns
		//ImGui::TableHeader("FAILURE TO COMPLY WITH THE CIVIL WILL");
		ImGui::TableSetupColumn("CODE");
		ImGui::TableSetupColumn("VIOLATION");
		ImGui::TableSetupColumn("DESCRIPTION");


		ImGui::TableHeadersRow();

		// Iterate over rows 
		for (const auto& violation : rows) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			ImGui::TextWrapped("%s", violation.m_code.c_str());

			ImGui::TableSetColumnIndex(1);
			ImGui::TextWrapped("%s", violation.m_violation.c_str());

			ImGui::TableSetColumnIndex(2);
			ImGui::TextWrapped("%s", violation.m_description.c_str());
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
				ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for titles

				ImGui::TextColored(yellow_color, "\nVIOLATION OF CIVIC TRUST");
				GUI::Helpers::WrappedBulletText("Actions that undermine civic responsibility, authorized resource allocation, workforce obligations or public trust\n");
				//DisplayCPCodes(CPSOPLookupTables::violation_of_civic_trust_codes);
				DisplayViolationCivicTrustTable();
				ImGui::TextColored(yellow_color, "*");
				ImGui::SameLine();
				ImGui::TextWrapped("Sanctioned distribution requires the permit holder to distribute only items corresponding to their permit inside their assigned distribution block. Units with at least 40 rank points may authorize distribution outside of their assigned block. Combine anti-fatigue rations may not be distributed whatsoever");

				ImGui::TextColored(yellow_color, "\nFAILURE TO COMPLY WITH THE CIVIL WILL");
				GUI::Helpers::WrappedBulletText("Failure to obey, respect, or cooperate w/ lawful directives issued by Civil Protection\n");
				//DisplayCPCodes(CPSOPLookupTables::failure_to_comply_with_the_civil_will);
				DisplayViolationCivilWillTable();

				ImGui::TextColored(yellow_color, "\nPROMOTING COMMUNAL UNREST");
				GUI::Helpers::WrappedBulletText("Actions intended to disrupt civic harmony, encourage disorder or undermine public stability\n");
				//DisplayCPCodes(CPSOPLookupTables::promoting_communal_unrest);
				DisplayViolationCommunalUnrestTable();

				ImGui::TextColored(yellow_color, "\nDIVISIVE SOCIOCIDAL COUNTER-OBEYANCE");
				GUI::Helpers::WrappedBulletText("Organized resistance to authority, interference with operations, or support of anti - civil elements\n");
				//DisplayCPCodes(CPSOPLookupTables::divisive_sociocidal_counter_obeyance);
				DisplayViolationDivisiveSociocidalTable();

				ImGui::TextColored(yellow_color, "\nDESTRUCTION OF CORPORAL SOCIAL PROTECTION UNITS");
				GUI::Helpers::WrappedBulletText("Acts resulting in damage to Civil Protection personnel, assets or operational capability\n");
				//DisplayCPCodes(CPSOPLookupTables::destruction_of_corporal_social_protection_units);
				DisplayViolationDestructionTable();
			}
			if (ImGui::CollapsingHeader("<:: View Communal Punishments ::>")) {
				ImVec4 yellow_color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow color for titles

				GUI::Helpers::WrappedBulletText("Communal punishments are strategic measures used by the Combine to assert control and instill fear among the civic populace. They function as instruments of intimidation intended to guarantee compliance. Such action are sanctioned exclusively by dispatch and rank leaderrs.");
				DisplayCommunalPunishmentsTable();
				GUI::Helpers::WrappedBulletTextColored(yellow_color, "Individuals who are unable to be assigned a residence are to find occpancy in Residental Block 8. All individuals found\nin violation of crowding an area are to be charged with 407 unlawful assembly");
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

				DisplayCPRewardInfo(CPSOPLookupTables::public_service_detail_list);
			}
			if (ImGui::CollapsingHeader("<:: View Civic Deeds ::>")) {
				ImGui::TextWrapped("Members of the civic populace may also perform civic deeds of their own accord.");
				ImGui::TextWrapped("These may warrant a reward in the form of civic points or ration coupons at the discretion of a PTL");

				DisplayCPRewardInfo(CPSOPLookupTables::civic_deed_list);
			}
			if (ImGui::CollapsingHeader("<:: View Interaction Directives ::>")) {
				DisplayCPInteractionDirectives(CPSOPLookupTables::citizen_interaction_directive_list);
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
			DisplayCPPolitiSchedule(CPSOPLookupTables::politi_schedule_event_list);
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
			DisplayCPContrabandIndex(CPSOPLookupTables::contraband_list);
		});

		// Render location authorization index
		GUI::Helpers::RenderSOPSection("<:: LOCATION AUTHORIZATION INDEX ::>", [] {
			if (ImGui::CollapsingHeader("<:: View Patrol Regions ::>")) {
				DisplayPatrolRegions();
			}
			if (ImGui::CollapsingHeader("<:: View Non-Patrol Regions ::>")) {
				DisplayNonPatrolRegions();
			}
			if (ImGui::CollapsingHeader("<:: View Legend ::>")) {
				ImGui::Text("* Includes members of the Industrial and Medical Workforces");
				
				ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "*");
				ImGui::SameLine();
				ImGui::Text("Unless directly escorted & supervised by protection units");

				ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "**");
				ImGui::SameLine();
				ImGui::Text(" Unless authorized or during an active situation");
			}
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
}