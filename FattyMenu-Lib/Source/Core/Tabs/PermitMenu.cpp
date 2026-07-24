#include "PermitMenu.h"

#include "../Serialization/ContentSerializer.h"

#include "../../GUIUtilities.h" // For wrapped cell text helper function

namespace FattyMenu {
	void PermitMenu::DisplayPermitInfo(const CPermit& a_permit) {
		// Enable text wrapping at the window edge
		ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x);

		// Display requirements
		ImGui::BulletText("Requirements to purchase %s Permit:\n%d Civic Points, %d Credits", 
			a_permit.GetPermitName().c_str(), a_permit.GetCivicPointRequirement(), a_permit.GetPermitCost());
		ImGui::Separator();	

		// Display purchasable packages from the WIH-3 dispenser
		ImGui::Text("Packages available to purchase from the dispenser:");
		DisplayPackagesTable(a_permit);
		ImGui::Separator();

		// Display items authorized for sale
		ImGui::Text("Items authorized for sale (per SOP):");
		for (const auto& item : a_permit.GetAuthorizedItems()) {
			GUI::Helpers::WrappedBulletText(item.c_str());
		}
		ImGui::Separator();

		// Restore previous wrapping
		ImGui::PopTextWrapPos();
	}

	void PermitMenu::DisplayPackagesTable(const CPermit& a_permit) {
		GUI::Helpers::RenderTable(
			a_permit.GetPermitName().c_str(), 
			{ "PACKAGE", "ITEM QUANTITY", "PACKAGE COST (in credits)", "COST PER ITEM (in credits)" },
			[&] {
				for (const auto& package : a_permit.GetPackages()) {
					ImGui::TableNextRow();

					ImGui::TableSetColumnIndex(0);
					GUI::Helpers::WrappedTableCellText(package.GetName().c_str());

					ImGui::TableSetColumnIndex(1);
					int quantity = package.GetQuantity();
					ImGui::TextWrapped("%d", quantity);

					ImGui::TableSetColumnIndex(2);
					ImGui::TextWrapped("%d", package.GetCost());

					ImGui::TableSetColumnIndex(3);
					if (quantity > 0) {
						ImGui::TextWrapped("%.2f", static_cast<float>(package.GetCost()) / quantity);
					}
					else {
						ImGui::TextWrapped("N/A");
					}
				}
			}
		);
	}

	void PermitMenu::RenderPermitMenu() {
		// Refresh button
		if (ImGui::Button("Refresh Permit Entries")) {
			RefreshPermitInfo();
		}
		ImGui::SameLine();
		ImGui::TextDisabled("(%zu loaded)", GetPermitList().size());

		ImGui::Separator();
		
		if (!GetPermitList().empty()) {
			for (const auto& permit : GetPermitList()) {
				std::string header_label = "View " + permit.GetPermitName() + " Permit Info";

				if (ImGui::CollapsingHeader(header_label.c_str())) {
					DisplayPermitInfo(permit);
				}
			}
		}
		
	}
}