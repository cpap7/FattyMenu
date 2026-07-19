#include "CivilStatusTypes.h"

namespace FattyMenu {
	/* Definitions of each type of CCivilStatus object
		Format:
		CCivilStatus name = {
			"Name",
			"Civic point range",
			"Status definition",
			{
				"Administrative Directive 1",
				"Administrative Directive 2",
				...
				"Administrative Directive n"
			}

		};
	*/
	namespace CivilStatusTypes {
		CCivilStatus non_citizen = {
			"Non-citizen",
			"0 - 24 Civic Points",
			"Individuals not recognized within the civic framework or whose status has been revoked due to severe malcompliance, criminality, or other administrative factors.",
			{
				"Maximum suspicion",
				"Immediate enforcement of violations",
				"No civic privileges or support"
			}
		};

		CCivilStatus standard_citizen = {
			"Standard Citizen",
			"25 - 249 Civic Points",
			"Registered participants within the civic framework under Combine jurisdiction.",
			{
				"Standard enforcement procedures",
				"Warnings for minor violations",
				"Access to standard provisions & accommodations"
			}
		};

		CCivilStatus priority_3_citizen = {
			"Priority 3 Citizen",
			"250 - 499 Civic Points",
			"Citizens demonstrating reliable compliance, productivity & participation within the civic framework.",
			{
				"Reduced suspicion",
				"Verbal correction preferred for minor violations",
				"Eligible for limited civic benefits"
			}

		};
		
		CCivilStatus priority_2_citizen = {
			"Priority 2 Citizen",
			"500 - 999 Civic Points",
			"Citizens demonstrating sustained compliance, productivity & civic reliability.",
			{
				"Low suspicion",
				"Preserve civic utility when practical",
				"Eligible for enhanced provisions & accommodations"
			}

		};
		
		CCivilStatus priority_1_citizen = {
			"Priority 1 Citizen",
			"1000 Civic Points",
			"Citizens designated as exceptionally valuable civic assets due to their utility, productivity, or contribution to sociostability.",
			{
				"Minimal suspicion",
				"Preservation prioritized when practical",
				"Eligible for highest authorized civic privileges"
			}

		};
	}
}