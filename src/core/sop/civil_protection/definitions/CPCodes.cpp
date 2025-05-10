#include "CPCodes.h"

namespace CPCodes {
	/* CCode declaration format (most codes):
	CCode code_name = { 
		"Title or Name", 
		"Description", 
		 bool new_abbreviation_code_flag, 
		 bool new_airwatch_code_flag, 
		 bool new_response_code_flag, 
		 bool new_eleven_code_flag,	
		 bool new_ten_code_flag 
	}; 
	*/
	namespace Abbreviation {
		CCode adw = { "ADW", "Assault with a deadly weapon", true, false, false, false };
		CCode bol = { "BOL", "Be on lookout", true, false, false, false };
		CCode cpt = { "CPT", "Civil Protection Team", true, false, false, false };
		CCode db = { "DB", "Dead body", true, false, false, false };
		CCode goa = { "GOA", "Gone on arrival", true, false, false, false };
		CCode upi = { "UPI", "Unidentified person of interest", true, false, false, false };
		CCode utl = { "UTL", "Unable to locate", true, false, false, false };
		CCode _34s = { "34s", "Shooting", true, false, false, false };
		CCode _187 = { "187", "Homicide", true, false, false, false };
		CCode _415b = { "415b", "Investigating disturbance", true, false, false, false };
		CCode _505 = { "505", "Reckless driving", true, false, false, false };
	}

	namespace Response {
		CCode code_1 = { "Code 1", "Non-urgent-response at your convenience", false, true, false, false };
		CCode code_2 = { "Code 2", "Urgent-response if not under assignment", false, true, false, false };
		CCode code_3 = { "Code 3", "Emergency, respond immediately", false, true, false, false };
		CCode code_4 = { "Code 4", "No further assistance required", false, true, false, false };
		CCode code_7 = { "Code 7", "Out of service to eat or resupply ammunition", false, true, false, false };
		CCode code_12 = { "Code 12", "Patrol your district and report the extent of damage", false, true, false, false };
		CCode code_100 = { "Code 100", "In position to intercept suspect", false, true, false, false };
	}

	namespace Eleven {
		CCode _116 = { "11-6", "Illegal discharge of firearms", false, false, true, false };
		CCode _1142 = { "11-42", "Medical team not required", false, false, true, false };
		CCode _1143 = { "11-43", "Medical team required", false, false, true, false };
		CCode _1144 = { "11-44", "Cleanup team required", false, false, true, false };
		CCode _1194 = { "11-94", "Pedestrian stop", false, false, true, false };
		CCode _1199 = { "11-99", "Officer needs immediate help", false, false, true, false };
	}

	namespace Ten {
		CCode _100 = { "10-0", "Use caution", false, false, false, true };
		CCode _101 = { "10-1", "You are being received poorly", false, false, false, true };
		CCode _102 = { "10-2", "You are being received clearly", false, false, false, true };
		CCode _103 = { "10-3", "Stop transmitting", false, false, false, true };
		CCode _104 = { "10-4", "Affirmative", false, false, false, true };
		CCode _106 = { "10-6", "Busy", false, false, false, true };
		CCode _107 = { "10-7", "Out of service", false, false, false, true };
		CCode _108 = { "10-8", "In service", false, false, false, true };
		CCode _109 = { "10-9", "Repeat message", false, false, false, true };
		CCode _1012 = { "10-12", "Standby", false, false, false, true };
		CCode _1014 = { "10-14", "Convoy or escort detail", false, false, false, true };
		CCode _1015 = { "10-15", "Prisoner in custody", false, false, false, true };
		CCode _1019 = { "10-19", "Returning to station", false, false, false, true };
		CCode _1020 = { "10-20", "Your location", false, false, false, true };
		CCode _1022 = { "10-22", "Disregard", false, false, false, true };
		CCode _1025 = { "10-25", "Contact with [Suspect]", false, false, false, true };
		CCode _1026 = { "10-26", "Detaining suspect", false, false, false, true };
		CCode _1027 = { "10-27", "Check if person is of interest", false, false, false, true };
		CCode _1030 = { "10-30", "Non-conformance/danger", false, false, false, true };
		CCode _1031 = { "10-31", "In pursuit", false, false, false, true };
		CCode _1032 = { "10-32", "Armed suspect", false, false, false, true };
		CCode _1033 = { "10-33", "Alarm", false, false, false, true };
		CCode _1038 = { "10-38", "Your destination", false, false, false, true };
		CCode _1041 = { "10-41", "Begin duty", false, false, false, true };
		CCode _1042 = { "10-42", "End duty", false, false, false, true };
		CCode _1054d = { "10-54d", "Possible dead body", false, false, false, true };
		CCode _1065 = { "10-65", "Clear for assignment", false, false, false, true };
		CCode _1078 = { "10-78", "Medical assistance", false, false, false, true };
		CCode _1091d = { "10-91", "Dead animal", false, false, false, true };
		CCode _1093 = { "10-93", "Blockade [in the road]", false, false, false, true };
		CCode _1096 = { "10-96", "Mentally unfit", false, false, false, true };
		CCode _1097 = { "10-97", "Arrived at scene", false, false, false, true };
		CCode _1099 = { "10-99", "Officer in trouble [Last in squad]", false, false, false, true };
		CCode _10103 = { "10-103", "Disturbance", false, false, false, true };
		CCode _10103m = { "10-103m", "Disturbance by mentally unfit", false, false, false, true };
		CCode _10107 = { "10-107", "Suspicious person", false, false, false, true };
		CCode _10108 = { "10-108", "Officer down", false, false, false, true };
		CCode _10109 = { "10-109", "Suicide", false, false, false, true };
	}

	// CCode violation definitions
	// Format: CCode _number = { "number as string", "code description", "violation description" }; 
	// -> bool flag for violation = true by default
	namespace Violation {
		// Anti-civil level 5 - verbal warning and/or citation
		CCode _28 = { "28", "Felony incite", "Encouraging or instructing others to commit violations" };
		CCode _35 = { "35", "Civil privacy violation", "Harassment or invasion of personal space" };
		CCode _54 = { "54", "Possession of materials", "Possession of minor articles of contraband [LEVEL 3]" };
		CCode _59 = { "59", "Movement transgression", "Excessive running, jumping or climbing" };
		CCode _91 = { "91", "Non-sanctioned distribution", "Distributing items outside of a distribution block" };
		CCode _311 = { "311", "Verbal indiscretion", "Vulgar language or yelling [if excessive charge 415]" };
		CCode _374b = { "374b", "Illegal disposal", "Littering or defecating [if excessive charge 415]" };
		CCode _407 = { "407", "Unlawful assembly", "Unauthorized gathering that poses a stability risk" };
		CCode _488 = { "488", "Theft", "Illegal acquisition of items [stealing or scavenging]" };
		CCode _647f = { "647f", "Improper function", "Public intoxication [if excessive charge 415]" };

		// Anti-civil level 1 - prosecution (sentencing discretionary) -> -10 civic points, 4 min sentence time
		CCode _27 = { "27", "Attempted crime", "Attempting to commit any violation but failing to do so" };
		CCode _62 = { "62", "Alarms", "Falsely reporting or alerting Civil Protection" };
		CCode _63 = { "63", "Criminal trespass", "Entering into a prohibited area without authorization" };
		CCode _69 = { "69", "Possession of resources", "Possession of moderate articles of contraband [LEVEL 2]" };
		CCode _99 = { "99", "Reckless operation", "Operating equipment in a negligent or criminal manner" };
		CCode _415 = { "415", "Civic disunity", "Disturbing the peace, assaulting non-CMB personnel" };
		CCode _507 = { "507", "Public non-compliance", "Repeated or severe displays of uncooperative behavior" };
		CCode _647e = { "647e", "Disengaged from workforce", "Loitering place to place, unregistered, abandoning work" };

		// Socio-endangerment level 5 - dispatch required -> -15 civic points, 6 min sentence time
		CCode _51 = { "51", "Non-sanctioned arson", "Intentional or negligent starting of any form of fire" };
		CCode _51b = { "51b", "Threat to property", "Damage to CMB equipment or infrastructure" };
		CCode _63s = { "63s", "Illegal in operation", "An accomplice to a socio-endangerment level 1 crime" };
		CCode _95 = { "95", "Illegal carrying", "Possession of major articles of contraband level 1 [ALL FIREARMS -> charge w/ 94 weapon instead]" };
		CCode _148 = { "148", "Resisting arrest", "Resisting or fleeing from prosecution [minor instances: charge w/ 507 public non-compliance]" };
		CCode _603 = { "603", "Unlawful entry", "Fraudulent or forceful means of entry into a premises" };

		// Socio-endangerment level 1 - dispatch required -> -15 civic points, 8 min sentence time
		CCode _17f = { "17f", "Fugitive detachment", "Concealing these wanted by Overwatch forces" };
		CCode _94 = { "94", "Weapon", "Possession or use of any form of a firearm" };
		CCode _243 = { "243", "Assault on protection team", "Direct, violent attack(s) on Overwatch forces w/ intent to cause great bodily harm or death" };
		CCode _404 = { "404", "Riot", "Actively engaging or promoting communal unrest" };
	}

	// CCode definitions for override codes
	/* Format:
		CCode name = {
			"Name"
			{
				"Description 1",
				"Description 2",
				...
				"Description N"
			},
			{
				"Ration intake:",
				"Workforce status:",
				"Shield access:",
				"Weapon protocol:"
			}
		};
	
	*/
	namespace Override {
		CCode sociostable = {
			"Sociostable",
			{
				"Applicable to isolated, limited anti-civil actions that do not affect the wider populace.",
				"Maintained during minimal disruptions when civil order remains intact." 
			},
			{
				"Ration intake: active",
				"Workforce status: active",
				"Shield access: civic populace",
				"Weapon protocol: holstered"
			}
		};
		CCode unrest_procedure = {
			"Unrest Procedure",
			{
				"Mandatory when communal unrest or riots are detected.",
				"This procedure requires a broader response and escalation of force to address widespread threats and restore order",
			},
			{
				"Form response teams and converge on reported areas of communal unrest or active riots",
				"Use additional lethal force to pacify or neutralize individuals participating in riots",
				"Ration intake: discretionary",
				"Workforce status: discretionary",
				"Shield access: workforce",
				"Weapon protocol: unholstered"
			}
		};
		CCode containment_procedure = {
			"Containment Procedure",
			{
				"Signifies a significant breach by a foreign entity in a Combine-controlled area.",
				"Authorizes deployment of protection and stabilization teams to quell the incursion.",
				
			},
			{
				"Prioritize efforts on containing incursion within the compromised Combine installation",
				"Form containment teams and converge on reported areas of infection",
				"Use lethal force to sterilize all reported threats",
				"Ration intake: suspended",
				"Workforce status: suspended",
				"Shield access: ground units",
				"Weapon protocol: raised"
			}

		};
		CCode lockdown_procedure = {
			"Lockdown Procedure",
			{
				"Enacted when restricting civic movement is necessary to achieve operational objectives.",
				"This procedure enforces compliance and serves as a communal punishment to maintain order.",
			},
			{
				"Ensure all civilians relocate to their designated tenement buildings immediately",
				"Conduct surface sector sweeps of all areas under Civil Protection jurisdiction",
				"Perform routine perimeter patrols to maintain security and prevent unauthorized access",
				"Ration intake: suspended",
				"Workforce status: suspended",
				"Shield access: ground units",
				"Weapon protocol: raised"
			}
		};
	}
	
}

