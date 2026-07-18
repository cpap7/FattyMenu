#pragma once

// ImGui dependencies
#include <../imgui/imgui.h>

#include "../DistributionPermit/PermitTypes.h"

namespace FattyMenu {
	// Contains function prototypes for displaying the distribution permit info
	namespace PermitMenu {
		// Displays permit info after clicking a collapsible header
		void RenderPermitInfo(const CPermit& a_permit);

		// Table render functions
		void RenderPackagesTable(const CPermit& a_permit);

		// Renders the collapsible headers
		void RenderPermitMenu();
	}
}