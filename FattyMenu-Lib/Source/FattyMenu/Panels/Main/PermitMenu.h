#pragma once

// ImGui dependencies
#include <../imgui/imgui.h>

#include "../../DistributionPermit/PermitLookupTable.h"

namespace FattyMenu {
	// Contains function prototypes for displaying the distribution permit info
	namespace PermitMenu {
		void DisplayPermitInfo(const CPermit& a_permit); 		// Displays permit info after clicking a collapsible header
		void DisplayPackagesTable(const CPermit& a_permit); 	// Displays package info for each permit 

		void RenderPermitMenu(); 								// Renders the collapsible headers

	}
}