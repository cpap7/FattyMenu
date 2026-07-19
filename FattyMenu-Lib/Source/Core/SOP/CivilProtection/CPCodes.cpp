#include "CPCodes.h"

namespace FattyMenu {
	namespace CPCodes {
		/* CCode declaration format (most codes):
		CCode code_name = {
			"Title or Name",
			"Description",
			 ECodeType::Type // See CCode.cpp for enum class definition
		};
		*/
		namespace Abbreviation {
			CCode adw = { 
				"ADW", 
				"Assault with a deadly weapon",
				ECodeType::Abbreviation
			};
			
			CCode bol = { 
				"BOL", 
				"Be on lookout",
				ECodeType::Abbreviation
			};
			
			CCode cpt = { 
				"CPT", 
				"Civil Protection Team",
				ECodeType::Abbreviation
			};
			
			CCode db = { 
				"DB", 
				"Dead body", 
				ECodeType::Abbreviation
			};
			
			CCode goa = { 
				"GOA", 
				"Gone on arrival", 
				ECodeType::Abbreviation
			};

			CCode oc = {
				"OC",
				"Off course (direction)",
				ECodeType::Abbreviation
			};
			
			CCode upi = {
				"UPI", 
				"Unidentified person of interest", 
				ECodeType::Abbreviation
			};
			
			CCode utl = { 
				"UTL", 
				"Unable to locate",
				ECodeType::Abbreviation
			};
			
			CCode _34s = { 
				"34s", 
				"Shooting", 
				ECodeType::Abbreviation
			};
			
			CCode _187 = { 
				"187", 
				"Homicide (murder)", 
				ECodeType::Abbreviation
			};
			
			CCode _415b = { 
				"415b",
				"Investigating disturbance",
				ECodeType::Abbreviation
			};
			
			CCode _505 = { 
				"505",
				"Reckless driving",
				ECodeType::Abbreviation
			};
		}

		namespace Response {
			CCode code_1 = { 
				"Code 1", 
				"Non-urgent - respond at your convenience", 
				ECodeType::ResponseCode
			};

			CCode code_2 = { 
				"Code 2", 
				"Urgent - respond if not under assignment", 
				ECodeType::ResponseCode
			};
			
			CCode code_3 = { 
				"Code 3", 
				"Emergency - respond immediately", 
				ECodeType::ResponseCode
			};
			
			CCode code_4 = { 
				"Code 4", 
				"No further assistance required", 
				ECodeType::ResponseCode
			};
			
			CCode code_7 = { 
				"Code 7", 
				"Out of service to eat or resupply ammunition", 
				ECodeType::ResponseCode
			};
			
			CCode code_12 = { 
				"Code 12", 
				"Patrol your district and report the extent of damage",
				ECodeType::ResponseCode
			};

			CCode code_100 = { 
				"Code 100", 
				"In position to intercept suspect", 
				ECodeType::ResponseCode
			};
		}

		namespace Eleven {
			CCode _116	= { 
				"11-6", 
				"Illegal discharge of firearms", 
				ECodeType::ElevenCode
			};
			
			CCode _1142	= {
				"11-42", 
				"Medical team not required", 
				ECodeType::ElevenCode
			};

			CCode _1143	= {
				"11-43",
				"Medical team required",
				ECodeType::ElevenCode
			};

			CCode _1144	= {
				"11-44", 
				"Cleanup team required",
				ECodeType::ElevenCode
			};

			CCode _1194	= {
				"11-94", 
				"Pedestrian stop",
				ECodeType::ElevenCode
			};
			
			CCode _1199	= {
				"11-99",
				"Officer needs immediate help",
				ECodeType::ElevenCode
			};
		}

		namespace Ten {
			CCode _100 = { 
				"10-0", 
				"Use caution", 
				ECodeType::TenCode
			};

			CCode _101 = { 
				"10-1", 
				"You are being received poorly",
				ECodeType::TenCode
			};

			CCode _102 = {
				"10-2",
				"You are being received clearly",
				ECodeType::TenCode
			};
			
			CCode _103 = {
				"10-3",
				"Stop transmitting",
				ECodeType::TenCode
			};
			
			CCode _104 = {
				"10-4",
				"Affirmative / Message received",
				ECodeType::TenCode
			};
			
			CCode _106 = { 
				"10-6", 
				"Busy (In some cases, it could be used to mean 'going AFK' in OOC terms)", 
				ECodeType::TenCode
			};
			
			CCode _107 = { 
				"10-7",
				"Out of service",
				ECodeType::TenCode
			};
			
			CCode _108 = {
				"10-8", 
				"In service", 
				ECodeType::TenCode
			};
			
			CCode _109 = { 
				"10-9", 
				"Repeat message",
				ECodeType::TenCode
			};
			
			CCode _1012	= {
				"10-12", 
				"Standby",
				ECodeType::TenCode
			};
			
			CCode _1014	= { 
				"10-14", 
				"Convoy or escort detail",
				ECodeType::TenCode
			};
			
			CCode _1015	= {
				"10-15", 
				"Prisoner in custody",
				ECodeType::TenCode
			};
			
			CCode _1019	= {
				"10-19", 
				"Returning to station",
				ECodeType::TenCode
			};
			
			CCode _1020	= {
				"10-20", 
				"Your location", 
				ECodeType::TenCode
			};
			
			CCode _1022	= { 
				"10-22", 
				"Disregard",
				ECodeType::TenCode
			};
			
			CCode _1025	= { 
				"10-25", 
				"Contact with (suspect)", 
				ECodeType::TenCode
			};
			
			CCode _1026	= { 
				"10-26",
				"Detaining suspect",
				ECodeType::TenCode
			};
			
			CCode _1027	= { 
				"10-27", 
				"Check if person is of interest", 
				ECodeType::TenCode
			};
			
			CCode _1030	= { 
				"10-30", 
				"Non-conformance / Danger",
				ECodeType::TenCode
			};
			
			CCode _1031	= { 
				"10-31", 
				"In pursuit", 
				ECodeType::TenCode
			};
			
			CCode _1032	= { 
				"10-32", 
				"Armed suspect", 
				ECodeType::TenCode
			};
			
			CCode _1033	= { 
				"10-33", 
				"Alarm", 
				ECodeType::TenCode
			};
			
			CCode _1038	= { 
				"10-38", 
				"Your destination", 
				ECodeType::TenCode
			};
			
			CCode _1041	= { 
				"10-41", 
				"Begin duty", 
				ECodeType::TenCode
			};
			
			CCode _1042	= { 
				"10-42", 
				"End duty", 
				ECodeType::TenCode
			};
			
			CCode _1054d = { 
				"10-54d", 
				"Possible dead body", 
				ECodeType::TenCode
			};
			
			CCode _1065	= { 
				"10-65", 
				"Clear for assignment", 
				ECodeType::TenCode
			};
			
			CCode _1078	= { 
				"10-78", 
				"Medical assistance", 
				ECodeType::TenCode
			};
			
			CCode _1091d = { 
				"10-91", 
				"Dead animal / creature", 
				ECodeType::TenCode
			};
			
			CCode _1093 = {
				"10-93", 
				"Blockade (in the road)", 
				ECodeType::TenCode
			};
			
			CCode _1096	= { 
				"10-96",
				"Mentally unfit",
				ECodeType::TenCode
			};
			
			CCode _1097	= {
				"10-97",
				"Arrived at scene", 
				ECodeType::TenCode
			};
			
			CCode _1099	= { 
				"10-99", 
				"Officer in trouble (last in squad)", 
				ECodeType::TenCode
			};
			
			CCode _10103 = {
				"10-103",
				"Disturbance",
				ECodeType::TenCode
			};
			
			CCode _10103m = { 
				"10-103m", 
				"Disturbance by mentally unfit", 
				ECodeType::TenCode
			};
			
			CCode _10107 = { 
				"10-107", 
				"Suspicious person",
				ECodeType::TenCode
			};
			
			CCode _10108 = { 
				"10-108", 
				"Officer down", 
				ECodeType::TenCode
			};
			
			CCode _10109 = { 
				"10-109", 
				"Suicide",
				ECodeType::TenCode
			};
		}

		// CCode violation definitions
		// Format: CCode _number = { "number as string", "code description", "violation description", ECodeType::ViolationCode }; 
		namespace Violation {
			// Violation Category: Violation of civic trust
			// Category Description: Actions that undermine civic responsibility, authorized resource allocation, workforce obligations or public trust
			CCode _27 = {
				"27",
				"Attempted crime",
				"Attempting a violation w/o successful completion",
				ECodeType::ViolationCode
			};

			CCode _54 = {
				"54",
				"Possession of materials",
				"Possession of minor contraband articles",
				ECodeType::ViolationCode
			};
			
			CCode _62 = {
				"62",
				"Alarms",
				"Knowingly making false reports to Civil Protection",
				ECodeType::ViolationCode
			};

			CCode _69 = {
				"69",
				"Possession of resources",
				"Possession of moderate contraband articles",
				ECodeType::ViolationCode
			};

			CCode _91 = {
				"91",
				"Non-sanctioned distribution",
				"Distributing items outside authorized distribution zones",
				ECodeType::ViolationCode
			};
			
			CCode _99 = {
				"99",
				"Reckless operation",
				"Unsafe or negligent operation of equipment",
				ECodeType::ViolationCode
			};

			CCode _311 = {
				"311",
				"Verbal indiscretion",
				"Loitering or excessive conversation w/o civic purpose",
				ECodeType::ViolationCode
			};

			CCode _374b = {
				"374b",
				"Illegal disposal",
				"Littering, defacement or unsanitary waste disposal",
				ECodeType::ViolationCode
			};

			CCode _488 = {
				"488",
				"Theft",
				"Unlawful taking or scavenging of property",
				ECodeType::ViolationCode
			};

			CCode _647f = {
				"647f",
				"Civic dysfunction",
				"Public intoxication or impairment",
				ECodeType::ViolationCode
			};

			// Violation Category: Failure to comply with the civil will
			// Category Description: Failure to obey, respect, or cooperate w/ lawful directives issued by Civil Protection
			CCode _35 = {
				"35",
				"Civil privacy violation",
				"Unauthorized intrusion, observation or harassment",
				ECodeType::ViolationCode
			};

			CCode _59 = {
				"59",
				"Movement transgression",
				"Excessive running, jumping or unauthorized movement",
				ECodeType::ViolationCode
			};

			CCode _63 = {
				"63",
				"Criminal trespass",
				"Entering a restricted area w/o authorization",
				ECodeType::ViolationCode
			};
			
			CCode _148 = {
				"148",
				"Resisting arrest",
				"Resisting, evading or fleeing from prosecution",
				ECodeType::ViolationCode
			};

			CCode _507 = {
				"507",
				"Public non-compliance",
				"Failure to comply w/ lawful directives",
				ECodeType::ViolationCode
			};

			CCode _647e = {
				"647e",
				"Disengaged from workforce",
				"Deviating from assigned duties or non-corplex status",
				ECodeType::ViolationCode
			};

			// Violation Category: Promoting communal unrest
			// Category Description: Actions intented to disrupt civic harmony, encourage disorder or undermine public stability
			CCode _28 = {
				"28",
				"Felony incite",
				"Encouraging or directing others to commit violations",
				ECodeType::ViolationCode
			};
			
			CCode _404 = {
				"404",
				"Riot",
				"Participating in or promoting communal unrest",
				ECodeType::ViolationCode
			};

			CCode _407 = {
				"407",
				"Unlawful assembly",
				"Unauthorized gathering posing a stability risk",
				ECodeType::ViolationCode
			};

			CCode _415 = {
				"415",
				"Civic disunity",
				"Disturbing public order or assaulting civilians",
				ECodeType::ViolationCode
			};

			// Violation Category: Divisive sociocidal counter-obeyance
			// Category Description: Organized resistance to authority, interference with operations, or support of anti-civil elements
			CCode _17f = {
				"17f",
				"Fugitive detachment",
				"Harboring or concealing wanted individuals",
				ECodeType::ViolationCode
			};

			CCode _51 = {
				"51",
				"Non-sanctioned arson",
				"Starting or spreading fire w/o authorization",
				ECodeType::ViolationCode
			};

			CCode _63s = {
				"63s",
				"Illegal in operation",
				"Obstruction of authorized civic operations",
				ECodeType::ViolationCode
			};
			
			CCode _94 = {
				"94",
				"Weapon",
				"Possession or use of any form of a firearm",
				ECodeType::ViolationCode
			};

			CCode _95 = {
				"95",
				"Illegal carrying",
				"Possession of major contraband articles",
				ECodeType::ViolationCode
			};

			CCode _603 = {
				"603",
				"Unlawful entry",
				"Gaining entry through force, fraud or deception",
				ECodeType::ViolationCode
			};

			// Violation Category: Destruction of corporal social protection units
			// Category Description: Acts resulting in damage to Civil Protection personnel, assets or operational capability 
			CCode _51b = {
				"51b",
				"Threat to property",
				"Damage to Combine equipment, assets or infrastructure",
				ECodeType::ViolationCode
			};

			CCode _243 = {
				"243",
				"Assault on protection team",
				"Any threat, physical contact or use of force directed against Overwatch forces",
				ECodeType::ViolationCode
			};
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
					"Directive 1",
					"Directive 2",
					...
					"Directive N"
				},
				ECodeType::OverrideCode
			};

		*/
		namespace Override {
			CCode sociostable = {
				"Sociostable",
				{
					"Applicable to isolated, limited anti-civil actions that do not affect the wider populace",
					"Maintained during minimal disruptions when civil order remains intact"
				},
				{
					"No additional directives"
				},
				ECodeType::OverrideCode
			};

			CCode unrest_procedure = {
				"Unrest Procedure",
				{
					"Mandatory when communal unrest or riots are detected",
					"This procedure requires a broader response and escalation of force to address widespread threats and restore order",
				},
				{
					"Form response teams and converge on reported areas of communal unrest or active riots",
					"Use additional lethal force to pacify or neutralize individuals participating in riots",
					"Establish checkpoints and conductr mandated searches"
				},
				ECodeType::OverrideCode
			};
			
			CCode containment_procedure = {
				"Containment Procedure",
				{
					"Signifies a significant breach by a foreign entity in a Combine-controlled area",
					"Authorizes deployment of protection and stabilization teams to quell the incursion",
				},
				{
					"Prioritize efforts on containing incursion within the compromised Combine installation",
					"Form containment teams and converge on reported areas of infection",
					"Use lethal force to sterilize all reported threats",
				},
				ECodeType::OverrideCode
			};
			
			CCode lockdown_procedure = {
				"Lockdown Procedure",
				{
					"Enacted when restricting civic movement is necessary to achieve operational objectives",
					"This procedure enforces compliance and serves as a communal punishment to maintain order",
				},
				{
					"Ensure all civilians relocate to their designated tenement buildings immediately",
					"Conduct surface sector sweeps of all areas under Civil Protection jurisdiction",
					"Perform routine perimeter patrols to maintain security and prevent unauthorized access",
				},
				ECodeType::OverrideCode
			};
		}

		// CCode declarations for verdict codes
		namespace Verdict {
			CCode verbal_warning = {
				"VERBAL WARNING",
				"A response to minor infractions, typically delivering up to 2 verbal warnings. If the misconduct persists, more severe penalties may be warranted.",
				ECodeType::VerdictCode
			};
			
			CCode citation = {
				"CITATION",
				"A stern, final warning issued before considering prosecution, involving the use of 1 - 3 non-lethal strikes w/ a stun baton to subdue the suspect. It's employed when prosecution is deemed unnecessary and verbal warnings have been proven to be ineffective.",
				ECodeType::VerdictCode
			};
			
			CCode prosecution = {
				"PROSECUTION",
				"Involves processing the suspect at the nearest Combine interface and inputting their committed violations & verdict code in the civic registrar before imprisoning them.",
				ECodeType::VerdictCode
			};
			
			CCode terminal_prosecution = {
				"TERMINAL PROSECUTION",
				"Refers to the execution of the suspect, which takes place in a concealed location after they've been processed.",
				ECodeType::VerdictCode
			};
			
			CCode disassociation = {
				"DISASSOCIATION",
				"Involves removing the suspect from the civic populace and holding them until they are transferred into the custody of available stabilization delegates for processing.",
				ECodeType::VerdictCode
			};
			
			CCode amputation = {
				"AMPUTATION",
				"Signifies summary execution of the suspect, conducted w/o processing them and away from the civic populace.",
				ECodeType::VerdictCode
			};
			
			CCode immediate_amputation = {
				"IMMEDIATE AMPUTATION",
				"Distinguishes the immediate execution of the suspect at the scene, conducted w/o processing them or within view of the civic populace.",
				ECodeType::VerdictCode
			};
		}
	}
}

