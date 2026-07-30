#pragma once

// GUI utils
#include "../GUIUtilities.h"
#include "../../SOP/TranshumanForces/TFSOPLookupTables.h"

// ImGui dependencies
#include <../imgui/imgui.h>

// Lambda functions
#include <functional>

namespace FattyMenu {
	namespace TFSOP {

		void DisplayTFLogo();

		void DisplayTFProtocols(const std::vector<CProtocol>& a_protocols_list);
		void DisplayTFCodes(const std::vector<CTerm>& a_codes_list);
		void DisplayTFTerms(const std::vector<CTerm>& a_terms_list);
		void DisplayTFDuties(const std::vector<CAssignment>& a_duties_list);

		void RenderTranshumanForcesSOP();

	}
}