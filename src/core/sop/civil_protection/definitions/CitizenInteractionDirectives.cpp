#include "CitizenInteractionDirectives.h"

/* Definitions of each type of CCivilStatus object 
   Format:
   CCivilStatus name = {
		"Name",
		"Civic Point range",
		"Status definition",
		{
			"Interaction Directive 1",
			"Interaction Directive 2",
			...
			"Interaction Directive 3"
		}

   };
*/
namespace StatusTypes {
	CCivilStatus non_citizen = {
		"Non-citizen",
		"0 - 24 Civic Points",
		"Unregistered individuals or those designated as outside the civic framework due to disobedience or other factors",
		{
			"Maximum enforcement",
			"Immediate corrective measures for any infractions",
			"No access to Combine provisions or support"
		}
	};
	CCivilStatus standard_citizen = {
		"Standard Citizen",
		"25 - 249 Civic Points",
		"Standard participants in the civic framework under Combine jurisdiction",
		{
			"Apply standard compliance procedures",
			"Issue warnings for minor deviations",
			"Regular monitoring required"
		}
	};
	CCivilStatus priority_3_citizen = {
		"Priority 3 Citizen",
		"250 - 499 Civic Points",
		"Individuals demonstrating initial progress in civic alignment and adherence to Combine directives",
		{
			"Moderate enforcement; prioritize verbal corrections",
			"Allow limited benefits (e.g., enhanced rations or reduced labor tasks)"
		}

	};
	CCivilStatus priority_2_citizen = {
		"Priority 2 Citizen",
		"500 - 999 Civic Points",
		"Fully integrated participants showing consistent civic reliability and adherence",
		{
			"Apply professional respect",
			"Provide access to upgraded provisions and accommodations"
		}

	};
	CCivilStatus priority_1_citizen = {
		"Priority 1 Citizen",
		"1000 Civic Points",
		"Exemplars of civic compliance and optimal integration within the Combine system",
		{
			"May display formal courtesy",
			"Provide assistance or protection when necessary",
			"Prioritize their concerns and requests"
		}

	};
}