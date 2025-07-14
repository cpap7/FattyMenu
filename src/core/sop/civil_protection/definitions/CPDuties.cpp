#include "CPDuties.h"

// Definitions of different Civil Protection assignments
/* FORMAT:
	CAssignment assignment_name = {
		"Assignment Name",
		"REQUIRED: Team description",
		{
			"Assignment description point 1",
			"Assignment description point 2",
			"Assignment description point 3"
		}
	};
*/
namespace CPAssignments {
	/* Definitions for assignments that are conducted exclusively during their designated times (see politi-schedule) */
	namespace MandateDuties {
		CAssignment curfew_procedure = { 
			"Curfew Procedure",
			"REQUIRED: At least 3 units (team) per residential block",
			{ 
				"Conduct thorough block inspections", 
				"Ensure unemployed citizens are inside their assigned tenement building",
				"Ensure employed citizens are inside their workstations",
				"Direct new arrivals at WIH-3 to their assigned tenement building",
				"Ensure new arrivals do not leave WIH-3 without a protection unit to escort them\n"
				"NOTE: Residential block inspections can be performed at any time and is not mandatory during curfews",
				"NOTE: 40+ units (and above) may modify containment field access modes at their discretion to better enforce curfew"
			}
		};
		CAssignment ration_intake_detail = {
			"Ration Intake Detail",
			"REQUIRED: At least 3 units (team)",
			{
				"Execute strict oversight during communal ration distribution",
				"Ensure citizens are:\n -> Facing forward\n -> Maintaining civil privacy\n -> Remaining silent while waiting in line",
				"Remove citizens who do not follow directives, or who are not assigned to a housing block"
			}
		};
	}

	/* Definitions for assignments that are standard daily responsibilities */
	namespace ProtectionDuties {
		CAssignment restricted_patrol_protocol = { 
			"Restricted Patrol Protocol",
			"REQUIRED: At least 3 units WITH FIREARMS (team)",
			{
				"Escort technicians to repair any compromised containment fields or sterilizers",
				"Respond to anti-citizen or necrotic activity\n -> Cauterize any threats to sociostability"
			}
		};
		CAssignment workforce_supervisory_detail = {
			"Workforce Supervisory Detail",
			"REQUIRED: At least 3 units (team)",
			{
				"Oversee labor detail and ensure efficient contribution from the Industrial Workforce",
				"Ensure assets are appropriately distributed to their designated supply stock locations",
				"Prosecute Industrial Workforce management and/or labor detail for failing to allocate available assets properly",
				"If all shipments are depleted and all packages are delivered before the end of the shift:\n -> Perform inspections on all of the workers \n -> Issue rewards to 2 or 3 of the best workers",
				"OPTIONAL: If needed, establish a secure package pipeline with available CPTs",
				"OPTIONAL: Establish a resin quota to be met by the end of the shift\n -> i.e., 3:1 resin to rations package delivery ratio until resin reaches 50% for example",
				"OPTIONAL: Have a unit standing by at SB-7 for expediting resin deliveries",
				"NOTE: Do not inform Industrial Workforce management of exact resin figures.\n -> Only inform them if additional resin packages are needed or not",
			}
		
		};
		CAssignment precinct_patrol_protocol = {
			"Precinct Patrol Protocol",
			"REQUIRED: At least 2 units (team)",
			{
				"Conduct routine patrols throughout assigned precincts",
				"Deter unauthorized activities",
				"Disperse any public gatherings",
				"Investigate any nearby alarms of suspicious individuals",
				"NOTE: Checkpoints between Precincts should be manned by at least one officer to search for POI and prevent minges from going any further",
				"NOTE: 2 units needed MINIMUM to patrol P13-N"
			}
		
		};
		CAssignment security_checkpoint_oversight = {
			"Security Checkpoint Oversight",
			"REQUIRED: At least 1 unit",
			{
				"Maintain vigilance and control at security checkpoints",
				"Conduct rigorous searches",
				"Question any suspicious individuals about their intent to pass",
				"Process recent and returning transfers to the city in WIH-3",
				"Ensure citizens who possess contraband are appropriately prosecuted",
				"NOTE: Active cities (per world-map) are: 8, 11, 12, 13, 14, 15, 16, 17, 24 & 27",
				"NOTE: People saying they're from City 8 are a red-flag. It's a Combine-specific city, no residents"
			}
		
		};
		CAssignment biotic_supervisory_detail = {
			"Biotic Supervisory Detail",
			"REQUIRED: At least 1 unit per 2 biotics",
			{
				"Release biotic conscripts from their designated holding area to begin an assignment",
				"Oversee labor detail, ensuring efficient contribution from all biotic conscripts",
				"Ensure biotic conscripts are returned to their holding area upon completion"
			}
		};
		CAssignment workforce_intake_processing = {
			"Workforce Intake Processing",
			"REQUIRED: At least 1 unit",
			{
				"Process new arrivals at TB-1 or WIH-3 and ensure they:\n -> Have validated their transfer with a relocation coupon\n -> Received their new ID card\n -> Do not possess contraband\n"
				"NOTE: Checkpoint at TB-1 (bus station) must be manned at all times by at least 2 units. It's strongly recommended that one them be a PTL."
			}
		};
		CAssignment conscript_custody_oversight = {
			"Conscript Custody Oversight",
			"REQUIRED: At least 1 unit",
			{
				"Oversee the custody & well-being of biotic conscripts and prisoners within SB-6",
				"Provide sustenance via dispensaries to compliant biotic conscripts and prisoners",
				"Restrict access to areas within SB-6 by ensuring all doors are closed and locked"
			}
		};
		CAssignment surveillance_network_maintenance = {
			"Surveillance Network Maintenance",
			"REQUIRED: At least 1 unit",
			{
				"Utilize interfaces to monitor all active security feeds and report any criminal activity",
				"Relay database information to local ground teams and units upon their request"
			}
		
		};
	}
	namespace Miscellaneous {
		CAssignment expectations = {
			"Duty / Mandate Expectations",
			"These are what's expected of you as a unit across basically all assignments and mandates",
			{
				"Loyalty checks must be common\n -> Even a regular pedestrian stop and questioning do fall under this category",
				"Status reports must be common as well\n -> Whenever something significant happens to your PT, you will report it to others",
				"Never leave probationaries alone, and without a partner with a gun",
				"Always stick close as a team unless you absolutely have to split up",
				"When Airwatch tags a suspect, do not run over to the person unless they are fleeing or posing a threat (Officers are not exempt from 59)"
				"When a citizen approaches you to turn in contraband, never allow them to drop it in public. Have them face the wall and confiscate it from them ther"
			}
		};
		CAssignment tac_usage = {
			"TAC Usage / Etiquette",
			"Refer to these guidelines when you're unsure whether to radio in TAC or not\nTAC should be used in the following scenarios:",
			{
				"Requests directed towards other teams, team leaders, officers or Dispatch\n -> Literally any request, whether it's a call for help, info on somebody from Civic Database or lockdown of a certain region\n -> Asking other team leads for status report does not require you to be a Rank Leader\n -> Feel free to request status updates from anyone at any time",
				"Sharing important intel you've obtained\n -> Like info on an armed person in the city, rebel group, possible sabotage or theft of PB packages, etc.",
				"Requesting status of certain blocks or regions\n -> If your team lead doesn't do that, he sucks.",
				"Notifying others of something urgent that wasn't declared by a team leader.\n -> Like changing an assignment, responding to something or requesting backup"
			}
		};
	}
}