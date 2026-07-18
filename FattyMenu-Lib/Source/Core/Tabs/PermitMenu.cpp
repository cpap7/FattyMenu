#include "PermitMenu.h"

#include "../../GUIUtilities.h" // For wrapped cell text helper function

namespace FattyMenu {
	void PermitMenu::RenderPermitInfo(const CPermit& a_permit) {
		// Enable text wrapping at the window edge
		ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x);

		// Display requirements
		ImGui::BulletText("Requirements to purchase %s Permit:\n%d Civic Points, %d Credits", a_permit.GetPermitName(), a_permit.GetCivicPointRequirement(), a_permit.GetPermitCost());
		ImGui::Separator();	

		// Display purchasable packages from the WIH-3 dispenser
		ImGui::Text("Packages available to purchase from the dispenser:");
		RenderPackagesTable(a_permit);
		ImGui::Separator();

		// Display items authorized for sale
		ImGui::Text("Items authorized for sale (per SOP):");
		for (const auto& item : a_permit.GetAuthorizedItems()) {
			GUI::Helpers::WrappedBulletText(item);
		}
		ImGui::Separator();

		// Restore previous wrapping
		ImGui::PopTextWrapPos();
	}

	void PermitMenu::RenderPackagesTable(const CPermit& a_permit) {
		int column_count = 4;
		ImGui::BeginTable(a_permit.GetPermitName(), column_count, ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp);
		
		ImGui::TableSetupColumn("PACKAGE");
		ImGui::TableSetupColumn("ITEM QUANTITY");
		ImGui::TableSetupColumn("PACKAGE COST (in credits)");
		ImGui::TableSetupColumn("COST PER ITEM (in credits)");
		ImGui::TableHeadersRow();

		for (const auto& package : a_permit.GetPackages()) {
			ImGui::TableNextRow();

			ImGui::TableSetColumnIndex(0);
			GUI::Helpers::WrappedTableCellText(package.GetName());

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

		ImGui::EndTable();
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