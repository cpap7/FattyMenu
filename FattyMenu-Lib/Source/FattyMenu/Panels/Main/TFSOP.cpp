#include "TFSOP.h"

namespace FattyMenu {
	
	void TFSOP::DisplayTFLogo() {
		ImGui::Text("                                          :");
		ImGui::Text("                                         :::");
		ImGui::Text("                                        :::::");
		ImGui::Text("                                       :::::::");
		ImGui::Text("                                      :::::::::");
		ImGui::Text("                                     :::::::::::");
		ImGui::Text("                                    :::::::::::::");
		ImGui::Text("                                   :::::::::::::::");
		ImGui::Text("                                  :::::::::::::::::");
		ImGui::Text("                                 ::::::::: :::::::::");
		ImGui::Text("                                :::::::::   :::::::::");
		ImGui::Text("                               :::::::::     :::::::::");
		ImGui::Text("                              :::::::::       :::::::::");
		ImGui::Text("                             :::::::::         :::::::::");
		ImGui::Text("                            :::::::::           :::::::::");
		ImGui::Text("                           :::::::::             :::::::::");
		ImGui::Text("                          :::::::::     :::::     :::::::::");
		ImGui::Text("                         :::::::::     :::::::     :::::::::");
		ImGui::Text("                        :::::::::      :::::::      :::::::::");
		ImGui::Text("                       :::::::::        :::::        :::::::::");
		ImGui::Text("                      :::::::::                       :::::::::");
		ImGui::Text("                     :::::::::                         :::::::::");
		ImGui::Text("                    :::::::::  :::::::::::::::::::::::  :::::::::");
		ImGui::Text("                   :::::::::   :::::::::::::::::::::::   :::::::::");
		ImGui::Text("                  :::::::::    :::::::::::::::::::::::    :::::::::");
		ImGui::Text("                 :::::::::                       :::::     :::::::::");
		ImGui::Text("                :::::::::              :::::::::::::::      :::::::::");
		ImGui::Text("               :::::::::            ::::::::::::::::::       :::::::::");
		ImGui::Text("              :::::::::           ::::::::::::::::::::        :::::::::");
		ImGui::Text("             :::::::::          ::::::::                       :::::::::");
		ImGui::Text("            :::::::::          :::::::                          :::::::::");
		ImGui::Text("           :::::::::          ::::::     :::::::::::::::::::     :::::::::");
		ImGui::Text("          :::::::::          ::::::      :::::::::::::::::::      :::::::::");
		ImGui::Text("         :::::::::           ::::::      :::::::::::::::::::       :::::::::");
		ImGui::Text("        :::::::::            :::::              :::::               :::::::::");
		ImGui::Text("       :::::::::             :::::              :::::                :::::::::");
		ImGui::Text("      :::::::::                                                       :::::::::");
		ImGui::Text("     :::::::::                                                         :::::::::");
		ImGui::Text("    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
		ImGui::Text("  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
		ImGui::Text(" ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
		ImGui::Text("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	}

	void TFSOP::DisplayTFProtocols(const std::vector<CProtocol>& a_protocols_list) {
		// TODO
	}

	void TFSOP::DisplayTFCodes(const std::vector<CTerm>& a_codes_list) {
		// TODO
	}
	
	void TFSOP::DisplayTFTerms(const std::vector<CTerm>& a_terms_list) {
		// TODO
	}
	
	void TFSOP::DisplayTFDuties(const std::vector<CAssignment>& a_duties_list) {
		// TODO
	}


	void TFSOP::RenderTranshumanForcesSOP() {
		// Collapsing headers render info once the user clicks on them
		if (ImGui::CollapsingHeader("<:: DISPLAY TRANSHUMAN FORCES LOGO ::>")) {
			// Print the ASCII art logo
			DisplayTFLogo();
		}

		// Display the duty index, render the subheaders via the helper functions in GUIUtilities.h
		GUI::Helpers::RenderSOPSection("<:: CODE INDEX ::>", [] {
			// Relegate rendering and formatting to template function
			if (ImGui::CollapsingHeader("<:: View Phonetic Alphabet Codes ::>")) {
				GUI::Helpers::DisplayList(TFSOPLookupTables::tf_radio_codes_list);
			}
		});

		// Display the terminology index
		GUI::Helpers::RenderSOPSection("<:: TERMINOLOGY INDEX ::>", [] {
			if (ImGui::CollapsingHeader("<:: View Action/Condition Terms ::>")) {
				GUI::Helpers::DisplayList(TFSOPLookupTables::tf_action_condition_list);
			}
			if (ImGui::CollapsingHeader("<:: View Hostile Entity Terms ::>")) {
				GUI::Helpers::DisplayList(TFSOPLookupTables::tf_hostile_entity_list);
			}
			if (ImGui::CollapsingHeader("<:: View Equipment Asset Terms ::>")) {
				GUI::Helpers::DisplayList(TFSOPLookupTables::tf_equipment_asset_list);
			}
		});

		// Display the duty index
		/*
		GUI::Helpers::RenderSOPSection("<:: DUTY INDEX ::>", [] {
			if (ImGui::CollapsingHeader("<:: View Stabilization Duties ::>")) {
				GUI::Helpers::DisplayAssignment(TFSOPLookupTables::tf_duties_list); // TODO: Update the duties list
			}
		});
		*/


	}
}