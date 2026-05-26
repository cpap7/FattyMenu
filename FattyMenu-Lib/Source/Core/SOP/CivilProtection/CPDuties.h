#pragma once
#include "../Assignment.h" // For class definition

#include <vector> // For resizable arrays

namespace FattyMenu {

	// Declarations of different Civil Protection assignments
	namespace CPAssignments {
		namespace MandateDuties {
			extern CAssignment curfew_procedure;
			extern CAssignment ration_intake_detail;
		}

		namespace ProtectionDuties {
			extern CAssignment restricted_patrol_protocol;
			extern CAssignment workforce_supervisory_detail;
			extern CAssignment precinct_patrol_protocol;
			extern CAssignment security_checkpoint_oversight;
			extern CAssignment biotic_supervisory_detail;
			extern CAssignment workforce_intake_processing;
			extern CAssignment conscript_custody_oversight;
			extern CAssignment surveillance_network_maintenance;
		}

		namespace Miscellaneous {
			extern CAssignment expectations;
			extern CAssignment tac_usage;
		}
	}
}