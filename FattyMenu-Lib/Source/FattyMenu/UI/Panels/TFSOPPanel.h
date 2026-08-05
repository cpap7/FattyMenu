#pragma once

// GUI utils
#include "../GUIUtilities.h"
#include "../Panel.h"

#include "../../SOP/TranshumanForces/TFSOPLookupTables.h"

// ImGui dependencies
#include <../imgui/imgui.h>

// Lambda functions
#include <functional>

namespace FattyMenu {
	// TODO: Revisit this later
	class CTFSOPPanel : public IPanel {
	private:
		// TODO: TF logo texture + image scale members

	public:
		CTFSOPPanel();
		~CTFSOPPanel();

		virtual void OnRender(bool* a_p_open) override;

	private:
		void DisplayTFLogo();
		void DisplayTranshumanForcesSOPContent();

		void DisplayTFProtocols(const std::vector<CProtocol>& a_protocols_list);
		void DisplayTFCodes(const std::vector<CTerm>& a_codes_list);
		void DisplayTFTerms(const std::vector<CTerm>& a_terms_list);
		void DisplayTFDuties(const std::vector<CAssignment>& a_duties_list);
	};
}