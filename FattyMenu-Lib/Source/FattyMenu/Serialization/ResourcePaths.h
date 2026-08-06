#pragma once

#include <string>
#include <filesystem>

// For file I/O
// Contains all resource file paths

// TODO: Consider replacing these with std::filesystem::path

namespace FattyMenu {
	/* Root - Relative to gmod.exe */
	inline const std::string c_root														= "garrysmod/lua/bin/FattyMenu/";

	/* User config */
	inline const std::string c_user_config_file_path									= c_root + "UserConfig.ini";

	/* Images - Loaded as Textures */
	inline const std::string c_civil_protection_logo_image_file_path					= c_root + "Resources/CivilProtection_SOP_Logo.png";
	inline const std::string c_map_image_file_path										= c_root + "Resources/CivilProtection_SOP_Map.png";

	/* Distribution Permit Info */
	inline const std::string c_permit_info_file_path									= c_root + "DistributionPermit/DistributionPermitInfo.json";

	/* Voiceline Data */
	inline const std::string c_voicelines_file_path										= c_root + "Voicelines/Voicelines.json"; 
	inline const std::string c_html_output_file_path									= c_root + "Voicelines/Project_ Synapse Voicelines.htm";										// TODO: It wouldn't be best practice to hardcode this, but it'll work for now

	/* CPSOP */
	// Radio codes
	inline const std::string c_abbreviation_codes_file_path								= c_root + "CPSOP/Codes_Abbreviation.json";
	inline const std::string c_response_codes_file_path									= c_root + "CPSOP/Codes_Response.json";
	inline const std::string c_eleven_codes_file_path									= c_root + "CPSOP/Codes_Eleven.json";
	inline const std::string c_ten_codes_file_path										= c_root + "CPSOP/Codes_Ten.json";
	inline const std::string c_verdict_codes_file_path									= c_root + "CPSOP/Codes_Verdict.json";
	inline const std::string c_category1_violation_codes_file_path						= c_root + "CPSOP/Codes_Violation_Category1_ViolationOfCivicTrust.json"; 						// Category 1 = Violation of civic trust
	inline const std::string c_category2_violation_codes_file_path						= c_root + "CPSOP/Codes_Violation_Category2_FailureToComplyWithTheCivilWill.json"; 				// Category 2 = Failure to comply with the civil will
	inline const std::string c_category3_violation_codes_file_path						= c_root + "CPSOP/Codes_Violation_Category3_PromotingCommunalUnrest.json"; 						// Category 3 = Promoting communal unrest
	inline const std::string c_category4_violation_codes_file_path						= c_root + "CPSOP/Codes_Violation_Category4_DivisiveSociocidalCounterObeyance.json"; 			// Category 4 = Divisive sociocidal counter-obeyance
	inline const std::string c_category5_violation_codes_file_path						= c_root + "CPSOP/Codes_Violation_Category5_DestructionOfCorporalSocialProtectionUnits.json";	// Category 5 = Destruction of corporal social protection units
	inline const std::string c_violation_codes_category_metadata_file_path				= c_root + "CPSOP/Codes_Violation_Category_Metadata.json";										// Category metadata
	inline const std::string c_override_codes_file_path									= c_root + "CPSOP/Codes_Override.json";

	// Civic rewards
	inline const std::string c_general_public_service_details_rewards_file_path			= c_root + "CPSOP/CivicRewards_GeneralPublicServiceDetails.json";
	inline const std::string c_civic_deeds_rewards_file_path							= c_root + "CPSOP/CivicRewards_CivicDeeds.json";

	// Civil statuses
	inline const std::string c_civil_status_file_path									= c_root + "CPSOP/CivilStatus.json";

	// Terms
	inline const std::string c_protocol_terms_file_path									= c_root + "CPSOP/Terms_Protocol.json";
	inline const std::string c_action_terms_file_path									= c_root + "CPSOP/Terms_Action.json";
	inline const std::string c_action_condition_terms_file_path							= c_root + "CPSOP/Terms_ActionCondition.json";
	inline const std::string c_hostile_entity_terms_file_path							= c_root + "CPSOP/Terms_HostileEntity.json";
	inline const std::string c_equipment_asset_terms_file_path							= c_root + "CPSOP/Terms_EquipmentAsset.json";
	inline const std::string c_organization_terms_file_path								= c_root + "CPSOP/Terms_Organizations.json";
	inline const std::string c_sociostability_terms_file_path							= c_root + "CPSOP/Terms_Sociostability.json";
	inline const std::string c_area_terms_file_path										= c_root + "CPSOP/Terms_Areas.json";

	// Assignments
	inline const std::string c_mandate_duty_assignments_file_path						= c_root + "CPSOP/Assignment_MandateDuties.json";
	inline const std::string c_protection_duty_assignments_file_path					= c_root + "CPSOP/Assignment_ProtectionDuties.json";
	inline const std::string c_assignment_expectations_file_path						= c_root + "CPSOP/Assignment_Expectations.json";

	// Contraband
	inline const std::string c_contraband_file_path										= c_root + "CPSOP/Contraband.json";

}