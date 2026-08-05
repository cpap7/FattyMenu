#pragma once
#include "../GUIUtilities.h"								// GUI utils
#include "../Panel.h"

#include "../../SOP/CivilProtection/CPSOPTableRowData.h"	// Table row data
#include "../../Serialization/CPSOPLookupTables.h"			// Lookup tables

#include <functional>
#include <string>
#include <vector>
#include <memory>

namespace FattyMenu {
	// Civil Protection SOP panel

	class CCPSOPPanel : public IPanel {
	private:
		std::unique_ptr<CTexture2D> m_logo_texture = nullptr;
		float m_image_scale{ 0.5f };

	public:
		CCPSOPPanel();
		~CCPSOPPanel();

		virtual void OnRender(bool* a_p_open) override;

	private:
		void LoadCPLogoTexture();																							// For displaying Civil Protection's logo image
		void DisplayCPLogoTexture();
		
		void DisplayCivilProtectionSOPContent();																			// For displaying the SOP collapsing headers

		void DisplayCodeInfo(const std::vector<CCode>& a_codes); 															// For displaying code information based on code type

		void DisplayCivicRewardInfo(const std::vector<CCivicReward>& a_civic_rewards); 										// For displaying citizen rewards
		void DisplayCivilStatusInfo(const std::vector<CCivilStatus>& a_civil_statuses_list);								// For displaying civil status types and engagement directives

		void DisplayPolitiSchedule(); 																						// For displaying politi-schedule

		void DisplayOverrideCodeTable(); 																					// For displaying override code table

		void DisplayViolationCodesTable(const std::string& a_table_label, const std::vector<CCode>& a_violation_codes); 	// For displaying violation codes
		void DisplayViolationLevelsTable(); 																				// For displaying violation levels table
		void DisplayContrabandIndex(const std::vector<CContraband>& a_contraband_index_categories); 						// For displaying the contraband index categories
		void DisplayResidentialBlockTable();																				// For displaying communal punishments

		void DisplayPatrolRegions();																						// For displaying patrol regions
		void DisplayNonPatrolRegions();																						// For displaying non-patrol regions

	};
}