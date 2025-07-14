#include "CPCodes.h"



namespace CPCodes {
	/* CCode declaration format (most codes):
	CCode code_name = { 
		"Title or Name", 
		"Description", 
		 CodeType::Type // See CCode.cpp for enum class definition
	}; 
	*/
	namespace Abbreviation {
		CCode adw = { "ADW", "Assault with a deadly weapon", CodeType::Abbreviation };
		CCode bol = { "BOL", "Be on lookout", CodeType::Abbreviation };
		CCode cpt = { "CPT", "Civil Protection Team", CodeType::Abbreviation };
		CCode db = { "DB", "Dead body", CodeType::Abbreviation };
		CCode goa = { "GOA", "Gone on arrival", CodeType::Abbreviation };
		CCode upi = { "UPI", "Unidentified person of interest", CodeType::Abbreviation };
		CCode utl = { "UTL", "Unable to locate", CodeType::Abbreviation };
		CCode _34s = { "34s", "Shooting", CodeType::Abbreviation };
		CCode _187 = { "187", "Homicide", CodeType::Abbreviation };
		CCode _415b = { "415b", "Investigating disturbance", CodeType::Abbreviation };
		CCode _505 = { "505", "Reckless driving", CodeType::Abbreviation };
	}

	namespace Response {
		CCode code_1 = { "Code 1", "Non-urgent-response at your convenience", CodeType::ResponseCode };
		CCode code_2 = { "Code 2", "Urgent-response if not under assignment", CodeType::ResponseCode };
		CCode code_3 = { "Code 3", "Emergency, respond immediately", CodeType::ResponseCode };
		CCode code_4 = { "Code 4", "No further assistance required", CodeType::ResponseCode };
		CCode code_7 = { "Code 7", "Out of service to eat or resupply ammunition", CodeType::ResponseCode };
		CCode code_12 = { "Code 12", "Patrol your district and report the extent of damage", CodeType::ResponseCode };
		CCode code_100 = { "Code 100", "In position to intercept suspect", CodeType::ResponseCode };
	}

	namespace Eleven {
		CCode _116 = { "11-6", "Illegal discharge of firearms", CodeType::ElevenCode };
		CCode _1142 = { "11-42", "Medical team not required", CodeType::ElevenCode };
		CCode _1143 = { "11-43", "Medical team required", CodeType::ElevenCode };
		CCode _1144 = { "11-44", "Cleanup team required", CodeType::ElevenCode };
		CCode _1194 = { "11-94", "Pedestrian stop", CodeType::ElevenCode };
		CCode _1199 = { "11-99", "Officer needs immediate help", CodeType::ElevenCode };
	}

	namespace Ten {
		CCode _100 = { "10-0", "Use caution", CodeType::TenCode };
		CCode _101 = { "10-1", "You are being received poorly", CodeType::TenCode };
		CCode _102 = { "10-2", "You are being received clearly", CodeType::TenCode };
		CCode _103 = { "10-3", "Stop transmitting", CodeType::TenCode };
		CCode _104 = { "10-4", "Affirmative", CodeType::TenCode };
		CCode _106 = { "10-6", "Busy", CodeType::TenCode };
		CCode _107 = { "10-7", "Out of service", CodeType::TenCode };
		CCode _108 = { "10-8", "In service", CodeType::TenCode };
		CCode _109 = { "10-9", "Repeat message", CodeType::TenCode };
		CCode _1012 = { "10-12", "Standby", CodeType::TenCode };
		CCode _1014 = { "10-14", "Convoy or escort detail", CodeType::TenCode };
		CCode _1015 = { "10-15", "Prisoner in custody", CodeType::TenCode };
		CCode _1019 = { "10-19", "Returning to station", CodeType::TenCode };
		CCode _1020 = { "10-20", "Your location", CodeType::TenCode };
		CCode _1022 = { "10-22", "Disregard", CodeType::TenCode };
		CCode _1025 = { "10-25", "Contact with [Suspect]", CodeType::TenCode };
		CCode _1026 = { "10-26", "Detaining suspect", CodeType::TenCode };
		CCode _1027 = { "10-27", "Check if person is of interest", CodeType::TenCode };
		CCode _1030 = { "10-30", "Non-conformance/danger", CodeType::TenCode };
		CCode _1031 = { "10-31", "In pursuit", CodeType::TenCode };
		CCode _1032 = { "10-32", "Armed suspect", CodeType::TenCode };
		CCode _1033 = { "10-33", "Alarm", CodeType::TenCode };
		CCode _1038 = { "10-38", "Your destination", CodeType::TenCode };
		CCode _1041 = { "10-41", "Begin duty", CodeType::TenCode };
		CCode _1042 = { "10-42", "End duty", CodeType::TenCode };
		CCode _1054d = { "10-54d", "Possible dead body", CodeType::TenCode };
		CCode _1065 = { "10-65", "Clear for assignment", CodeType::TenCode };
		CCode _1078 = { "10-78", "Medical assistance", CodeType::TenCode };
		CCode _1091d = { "10-91", "Dead animal", CodeType::TenCode };
		CCode _1093 = { "10-93", "Blockade [in the road]", CodeType::TenCode };
		CCode _1096 = { "10-96", "Mentally unfit", CodeType::TenCode };
		CCode _1097 = { "10-97", "Arrived at scene", CodeType::TenCode };
		CCode _1099 = { "10-99", "Officer in trouble [Last in squad]", CodeType::TenCode };
		CCode _10103 = { "10-103", "Disturbance", CodeType::TenCode };
		CCode _10103m = { "10-103m", "Disturbance by mentally unfit", CodeType::TenCode };
		CCode _10107 = { "10-107", "Suspicious person", CodeType::TenCode };
		CCode _10108 = { "10-108", "Officer down", CodeType::TenCode };
		CCode _10109 = { "10-109", "Suicide", CodeType::TenCode };
	}

	// CCode violation definitions
	// Format: CCode _number = { "number as string", "code description", "violation description", CodeType::ViolationCode }; 
	namespace Violation {
		// Anti-civil level 5 - verbal warning and/or citation
		CCode _28 = { "28", "Felony incite", "Encouraging or instructing others to commit violations", CodeType::ViolationCode };
		CCode _35 = { "35", "Civil privacy violation", "Harassment or invasion of personal space", CodeType::ViolationCode };
		CCode _54 = { "54", "Possession of materials", "Possession of minor articles of contraband [LEVEL 3]", CodeType::ViolationCode };
		CCode _59 = { "59", "Movement transgression", "Excessive running, jumping or climbing", CodeType::ViolationCode };
		CCode _91 = { "91", "Non-sanctioned distribution", "Distributing items outside of a distribution block", CodeType::ViolationCode };
		CCode _311 = { "311", "Verbal indiscretion", "Vulgar language or yelling [if excessive charge 415]", CodeType::ViolationCode };
		CCode _374b = { "374b", "Illegal disposal", "Littering or defecating [if excessive charge 415]", CodeType::ViolationCode };
		CCode _407 = { "407", "Unlawful assembly", "Unauthorized gathering that poses a stability risk", CodeType::ViolationCode };
		CCode _488 = { "488", "Theft", "Illegal acquisition of items [stealing or scavenging]", CodeType::ViolationCode };
		CCode _647f = { "647f", "Improper function", "Public intoxication [if excessive charge 415]", CodeType::ViolationCode };

		// Anti-civil level 1 - prosecution (sentencing discretionary) -> -10 civic points, 4 min sentence time
		CCode _27 = { "27", "Attempted crime", "Attempting to commit any violation but failing to do so", CodeType::ViolationCode };
		CCode _62 = { "62", "Alarms", "Falsely reporting or alerting Civil Protection", CodeType::ViolationCode };
		CCode _63 = { "63", "Criminal trespass", "Entering into a prohibited area without authorization", CodeType::ViolationCode };
		CCode _69 = { "69", "Possession of resources", "Possession of moderate articles of contraband [LEVEL 2]", CodeType::ViolationCode };
		CCode _99 = { "99", "Reckless operation", "Operating equipment in a negligent or criminal manner", CodeType::ViolationCode };
		CCode _415 = { "415", "Civic disunity", "Disturbing the peace, assaulting non-CMB personnel", CodeType::ViolationCode };
		CCode _507 = { "507", "Public non-compliance", "Repeated or severe displays of uncooperative behavior", CodeType::ViolationCode };
		CCode _647e = { "647e", "Disengaged from workforce", "Loitering place to place, unregistered, abandoning work", CodeType::ViolationCode };

		// Socio-endangerment level 5 - dispatch required -> -15 civic points, 6 min sentence time
		CCode _51 = { "51", "Non-sanctioned arson", "Intentional or negligent starting of any form of fire", CodeType::ViolationCode };
		CCode _51b = { "51b", "Threat to property", "Damage to CMB equipment or infrastructure", CodeType::ViolationCode };
		CCode _63s = { "63s", "Illegal in operation", "An accomplice to a socio-endangerment level 1 crime", CodeType::ViolationCode };
		CCode _95 = { "95", "Illegal carrying", "Possession of major articles of contraband level 1 [ALL FIREARMS -> charge w/ 94 weapon instead]", CodeType::ViolationCode };
		CCode _148 = { "148", "Resisting arrest", "Resisting or fleeing from prosecution [minor instances: charge w/ 507 public non-compliance]", CodeType::ViolationCode };
		CCode _603 = { "603", "Unlawful entry", "Fraudulent or forceful means of entry into a premises", CodeType::ViolationCode };

		// Socio-endangerment level 1 - dispatch required -> -15 civic points, 8 min sentence time
		CCode _17f = { "17f", "Fugitive detachment", "Concealing these wanted by Overwatch forces", CodeType::ViolationCode };
		CCode _94 = { "94", "Weapon", "Possession or use of any form of a firearm", CodeType::ViolationCode };
		CCode _243 = { "243", "Assault on protection team", "Direct, violent attack(s) on Overwatch forces w/ intent to cause great bodily harm or death", CodeType::ViolationCode };
		CCode _404 = { "404", "Riot", "Actively engaging or promoting communal unrest", CodeType::ViolationCode };
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
			},
			CodeType::OverrideCode
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
			},
			CodeType::OverrideCode
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
			},
			CodeType::OverrideCode
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
			},
			CodeType::OverrideCode
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
			},
			CodeType::OverrideCode
		};
	}	
}

