#include "PermitMenu.h"

namespace FattyMenu {
	void PermitMenu::RenderPermitInfo(const CPermit& a_permit) {
		// Enable text wrapping at the window edge
		ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x);

		// Display requirements to purchase the permit
		ImGui::BulletText("Requirements to purchase %s Permit: %d Civic Points, %d Credits", a_permit.GetPermitName(), a_permit.GetCivicPointRequirement(), a_permit.GetPermitCost());
		ImGui::Separator();	// Add a separator for aesthetics

		// Display purchasable packages from the WIH-3 dispenser
		ImGui::Text("Packages available to purchase from the dispenser:");
		for (const auto& packages : a_permit.GetPackages()) {
			ImGui::BulletText("%s\n -> %d Credits", packages.GetPackageName(), packages.GetPackageCost());
		}

		// Display items authorized for sale
		ImGui::Text("Items authorized for sale (per SOP):");
		for (const auto& item : a_permit.GetAuthorizedItems()) {
			ImGui::BulletText("%s", item);
		}
		ImGui::Separator();

		// Restore previous wrapping
		ImGui::PopTextWrapPos();
	}

	void PermitMenu::RenderPermitMenu() {
		// Display collapsing headers for each permit, 
		// then render the info for the permit after it's clicked on
		if (ImGui::CollapsingHeader("View Hydration Permit Info")) {
			RenderPermitInfo(PermitTypes::hydration);
		}

		if (ImGui::CollapsingHeader("View Nourishment Permit Info")) {
			RenderPermitInfo(PermitTypes::nourishment);
		}

		if (ImGui::CollapsingHeader("View Garment Permit Info")) {
			RenderPermitInfo(PermitTypes::garment);
		}

		if (ImGui::CollapsingHeader("View Luxury Permit Info")) {
			RenderPermitInfo(PermitTypes::luxury);
		}
	}
}