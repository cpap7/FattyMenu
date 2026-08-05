#pragma once
#include "../Panel.h"

#include "../../Serialization/PermitLookupTable.h"

// ImGui dependencies
#include <../imgui/imgui.h>

namespace FattyMenu {
	// Contains function prototypes for displaying the distribution permit info
	class CPermitPanel : public IPanel {
	public:
		CPermitPanel()	= default;
		~CPermitPanel() = default;

		virtual void OnRender(bool* a_p_open) override;

	private:
		void DisplayPermitInfo(const CPermit& a_permit); 		// Displays permit info after clicking a collapsible header
		void DisplayPackagesTable(const CPermit& a_permit); 	// Displays package info for each permit 

		void DisplayDistributionPermitHeaders(); 				// Renders the collapsible headers
	};
}