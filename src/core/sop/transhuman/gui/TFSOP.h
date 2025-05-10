#pragma once
// Lambda functions
#include <functional>

// GUI utils
#include "../../../../GUIUtilities.h"

// ImGui dependencies
#include "../../../../../ext_dependencies/imgui/imgui.h"

// Vector lists
#include "TFSOPLookupTables.h"


namespace TFSOP {

	void DisplayTFLogo();

	void DisplayTFCodes(std::vector<CTerm>);
	void DisplayTFTerms(std::vector<CTerm>);
	void DisplayTFDuties(std::vector<CAssignment>);

	void RenderTranshumanForcesSOP();

}