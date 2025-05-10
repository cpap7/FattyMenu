#include "TFDuties.h"

// Definitions of different Transhuman assignments
/* FORMAT:
	CAssignment assignment_name = { 
		"Assignment Name", 
		int units_required, int duration,
		"Recommended Class", 
		{
			"Assignment description point 1",
			"Assignment description point 2",
			"Assignment description point 3"
		}
	};
*/

// Definitions of different Transhuman assignments
namespace TFAssignments {
	/* Definitions for assignments */
	namespace StabilizationDuties {
		CAssignment outland_sector_sweep = {
			"Outland Sector Sweep",
			3, 2,
			"Soldier",
			{
				"Conduct routine patrols within outland regions and sterilize any hostiles",
				"Ensure perimeter sterilizers and containment fields are not compromised"
			}
		};
		CAssignment stalker_supervisory_detail = {
			"Stalker Supervisory Detail",
			1, 1,
			"Grunt",
			{
				"Oversee transfer and conversion of selected dissociated individuals into stalkers",
				"Monitor labor details and ensure unwavering compliance from stalker units, guaranteeing their efficient contribution to the Combine's objectives"
			}
		};
		CAssignment surveillance_network_maintenance = {
			"Surveillance Network Maintenance",
			1, 1,
			"Grunt",
			{
				"Inspect security cameras, automated turrets, and protective containment fields, alerting Overwatch and local technician teams in the event of compromised assets",
				"Utilize interfaces to monitor all active security feeds within the given sector",
				"Relay database information to Overwatch and local stabilization teams upon request"
			}
		};
		CAssignment hazmat_scientist_security_oversight = {
			"Hazmat / Scientist Security Oversight",
			2, 1,
			"Grunt",
			{
				"Provide security and ensure unwavering compliance from hazmat units or Combine scientists, guaranteeing their efficient contribution to the Combine's objectives"
			}
		};
		CAssignment asset_security_oversight = {
			"Asset Security Oversight",
			2, 1,
			"Grunt",
			{
				"Provide security and supervision over the intake and distribution of Combine resources",
				"Ensure the security and socio-stability of Combine logistical centers"
			}
		};
		CAssignment breach_containment_protocol = {
			"Breach Containment Protocol",
			2, 1,
			"Grunt",
			{
				"Lockdown and provide immediate security to any external breaches into Combine controlled city-centers or logistical hubs",
				"Ensure that no unauthorized personnel exit or enter through any external breaches"
			}
		};

	}
}