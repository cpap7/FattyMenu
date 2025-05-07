#pragma once

// ImGui dependencies
#include "../../../../ext_dependencies/imgui/imgui.h"

#include "../../distribution_permit/definitions/PermitTypes.h"

// Contains function prototypes for displaying the distribution permit info
namespace PermitMenu {
	// Displays permit info after clicking a collapsible header
	void RenderPermitInfo(CPermit&);

	// Renders the collapsible headers
	void RenderPermitMenu();
}