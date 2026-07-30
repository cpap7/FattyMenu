#pragma once
#include "../../Serialization/ContentSerializer.h"
#include "../../Serialization/ResourcePaths.h"

// Class definitions (Civil Protection)
#include "../Code.h"
#include "../Contraband.h"
#include "../CivilStatus.h"
#include "../CivicReward.h"
#include "../Term.h"
#include "../Assignment.h"


#include <vector>	


namespace FattyMenu {
	namespace CPSOP::LookupTables {
		// ABBREVIATIONS

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetAbbreviationCodesList() {
			static std::vector<CCode> abbreviation_codes_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_abbreviation_codes_file_path);
				}();

			return abbreviation_codes_list;
		}

		// Reloads in-memory codes
		inline void RefreshAbbreviationCodesList() {
			CContentSerializer serializer;
			GetAbbreviationCodesList() = serializer.DeserializeCodes(c_abbreviation_codes_file_path);
		}

		// RESPONSE CODES

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetResponseCodesList() {
			static std::vector<CCode> response_codes_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_response_codes_file_path);
				}();

			return response_codes_list;
		}

		// Reloads in-memory codes
		inline void RefreshResponseCodesList() {
			CContentSerializer serializer;
			GetResponseCodesList() = serializer.DeserializeCodes(c_response_codes_file_path);
		}

		// ELEVEN CODES
		
		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetElevenCodesList() {
			static std::vector<CCode> eleven_codes_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_eleven_codes_file_path);
				}();

			return eleven_codes_list;
		}

		// Reloads in-memory codes
		inline void RefreshElevenCodesList() {
			CContentSerializer serializer;
			GetElevenCodesList() = serializer.DeserializeCodes(c_eleven_codes_file_path);
		}

		// TEN CODES

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetTenCodesList() {
			static std::vector<CCode> ten_codes_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_ten_codes_file_path);
				}();

			return ten_codes_list;
		}

		// Reloads in-memory codes
		inline void RefreshTenCodesList() {
			CContentSerializer serializer;
			GetTenCodesList() = serializer.DeserializeCodes(c_ten_codes_file_path);
		}

		// VERDICT CODES
		
		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetVerdictCodesList() {
			static std::vector<CCode> verdict_codes_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_verdict_codes_file_path);
				}();

			return verdict_codes_list;
		}

		// Reloads in-memory codes
		inline void RefreshVerdictCodesList() {
			CContentSerializer serializer;
			GetVerdictCodesList() = serializer.DeserializeCodes(c_verdict_codes_file_path);
		}

		// VIOLATION CODES

		// Violation category: Violation of civic trust

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetViolationOfCivicTrustCodesList() {
			static std::vector<CCode> violation_of_civic_trust_codes_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_category1_violation_codes_file_path);
				}();

			return violation_of_civic_trust_codes_list;
		}

		// Reloads in-memory codes
		inline void RefreshViolationOfCivicTrustCodesList() {
			CContentSerializer serializer;
			GetViolationOfCivicTrustCodesList() = serializer.DeserializeCodes(c_category1_violation_codes_file_path);
		}

		// Violation category: Failure to comply with the civil will

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetFailureToComplyWithTheCivilWillCodesList() {
			static std::vector<CCode> failure_to_comply_with_the_civil_will_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_category2_violation_codes_file_path);
				}();

			return failure_to_comply_with_the_civil_will_list;
		}

		// Reloads in-memory codes
		inline void RefreshFailureToComplyWithTheCivilWillCodesList() {
			CContentSerializer serializer;
			GetFailureToComplyWithTheCivilWillCodesList() = serializer.DeserializeCodes(c_category2_violation_codes_file_path);
		}

		// Violation category: Promoting communal unrest

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetPromotingCommunalUnrestCodesList() {
			static std::vector<CCode> promoting_communal_unrest_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_category3_violation_codes_file_path);
				}();

			return promoting_communal_unrest_list;
		}

		// Reloads in-memory codes
		inline void RefreshPromotingCommunalUnrestCodesList() {
			CContentSerializer serializer;
			GetPromotingCommunalUnrestCodesList() = serializer.DeserializeCodes(c_category3_violation_codes_file_path);
		}

		// Violation category: Divisive sociocidal counter-obeyance

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetDivisiveSociocidalCounterObeyanceCodesList() {
			static std::vector<CCode> divisive_sociocidal_counter_obeyance_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_category4_violation_codes_file_path);
				}();

			return divisive_sociocidal_counter_obeyance_list;
		}

		// Reloads in-memory codes
		inline void RefreshDivisiveSociocidalCounterObeyanceList() {
			CContentSerializer serializer;
			GetDivisiveSociocidalCounterObeyanceCodesList() = serializer.DeserializeCodes(c_category4_violation_codes_file_path);
		}


		// Violation category: Destruction of corporal social protection units

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetDestructionOfCorporalSocialProtectionUnitsCodesList() {
			static std::vector<CCode> destruction_of_corporal_social_protection_units_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_category5_violation_codes_file_path);
				}();

			return destruction_of_corporal_social_protection_units_list;
		}

		// Reloads in-memory codes
		inline void RefreshDestructionOfCorporalSocialProtectionUnitsList() {
			CContentSerializer serializer;
			GetDestructionOfCorporalSocialProtectionUnitsCodesList() = serializer.DeserializeCodes(c_category5_violation_codes_file_path);
		}

		// VIOLATION CODE CATEGORY (METADATA)

		// TODO: Refactor these functions a bit

		// Returns a mutable list of violation code categories that are loaded from a JSON file
		inline std::vector<CViolationCodeCategory>& GetViolationCodeCategories() {
			static std::vector<CViolationCodeCategory> violation_code_categories =
				[] {
					CContentSerializer serializer;
					auto metadata =  serializer.DeserializeViolationCodeCategories(c_violation_codes_category_metadata_file_path);

					// Reconnect non-owning pointers to violation codes via TableID
					for (auto& category : metadata) {
						if (category.GetTableID() == "ViolationOfCivicTrustTable")								{ category.SetCodes(&GetViolationOfCivicTrustCodesList());						}
						else if (category.GetTableID() == "FailureToComplyWithTheCivilWillTable")				{ category.SetCodes(&GetFailureToComplyWithTheCivilWillCodesList());			}
						else if (category.GetTableID() == "PromotingCommunalUnrestTable")						{ category.SetCodes(&GetPromotingCommunalUnrestCodesList());					}
						else if (category.GetTableID() == "DivisiveSociocidalCounterObeyanceTable")				{ category.SetCodes(&GetDivisiveSociocidalCounterObeyanceCodesList());			}
						else if (category.GetTableID() == "DestructionOfCorporalSocialProtectionUnitsTable")	{ category.SetCodes(&GetDestructionOfCorporalSocialProtectionUnitsCodesList());	}
					}

					return metadata;
				}();

			return violation_code_categories;
		}

		inline void RefreshViolationCodeCategories() {
			CContentSerializer serializer;
			auto metadata = serializer.DeserializeViolationCodeCategories(c_violation_codes_category_metadata_file_path);

			for (auto& category : metadata) {
				if (category.GetTableID() == "ViolationOfCivicTrustTable")								{ category.SetCodes(&GetViolationOfCivicTrustCodesList());						}
				else if (category.GetTableID() == "FailureToComplyWithTheCivilWillTable")				{ category.SetCodes(&GetFailureToComplyWithTheCivilWillCodesList());			}
				else if (category.GetTableID() == "PromotingCommunalUnrestTable")						{ category.SetCodes(&GetPromotingCommunalUnrestCodesList());					}
				else if (category.GetTableID() == "DivisiveSociocidalCounterObeyanceTable")				{ category.SetCodes(&GetDivisiveSociocidalCounterObeyanceCodesList());			}
				else if (category.GetTableID() == "DestructionOfCorporalSocialProtectionUnitsTable")	{ category.SetCodes(&GetDestructionOfCorporalSocialProtectionUnitsCodesList()); }
			}
			GetViolationCodeCategories() = std::move(metadata);
		}
		
		// OVERRIDE CODES

		// Returns a mutable list of codes that are loaded from a JSON file
		inline std::vector<CCode>& GetOverrideCodesList() {
			static std::vector<CCode> override_codes_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCodes(c_override_codes_file_path);
				}();

			return override_codes_list;
		}

		// Reloads in-memory codes
		inline void RefreshOverrideCodesList() {
			CContentSerializer serializer;
			GetOverrideCodesList() = serializer.DeserializeCodes(c_override_codes_file_path);
		}

		// CIVIC REWARDS

		// Returns a mutable list of civic rewards that are loaded from a JSON file
		inline std::vector<CCivicReward>& GetGeneralPublicServiceDetailRewardsList() {
			static std::vector<CCivicReward> general_public_service_detail_rewards_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCivicRewardInfo(c_general_public_service_details_rewards_file_path);
				}();

			return general_public_service_detail_rewards_list;
		}

		// Reloads in-memory civic rewards
		inline void RefreshGeneralPublicServiceDetailRewardsList() {
			CContentSerializer serializer;
			GetGeneralPublicServiceDetailRewardsList() = serializer.DeserializeCivicRewardInfo(c_general_public_service_details_rewards_file_path);
		}

		// Returns a mutable list of civic rewards that are loaded from a JSON file
		inline std::vector<CCivicReward>& GetCivicDeedRewardsList() {
			static std::vector<CCivicReward> civic_deeds_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCivicRewardInfo(c_civic_deeds_rewards_file_path);
				}();

			return civic_deeds_list;
		}

		// Reloads in-memory civic rewards
		inline void RefreshCivicDeedRewardsList() {
			CContentSerializer serializer;
			GetCivicDeedRewardsList() = serializer.DeserializeCivicRewardInfo(c_civic_deeds_rewards_file_path);
		}

		// CIVIL STATUSES

		// Returns a mutable list of civil statuses that are loaded from a JSON file
		inline std::vector<CCivilStatus>& GetCivilStatusList() {
			static std::vector<CCivilStatus> civil_statuses_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeCivilStatusInfo(c_civil_status_file_path);
				}();

			return civil_statuses_list;
		}

		// Reloads in-memory civil statuses
		inline void RefreshCivilStatusList() {
			CContentSerializer serializer;
			GetCivilStatusList() = serializer.DeserializeCivilStatusInfo(c_civil_status_file_path);
		}

		// CIVIL PROTECTION TERMS

		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetProtocolTermsList() {
			static std::vector<CTerm> protocol_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_protocol_terms_file_path);
				}();

			return protocol_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshProtocolTermsList() {
			CContentSerializer serializer;
			GetProtocolTermsList() = serializer.DeserializeTerms(c_protocol_terms_file_path);
		}

		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetActionTermsList() {
			static std::vector<CTerm> action_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_action_terms_file_path);
				}();

			return action_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshActionTermsList() {
			CContentSerializer serializer;
			GetActionTermsList() = serializer.DeserializeTerms(c_action_terms_file_path);
		}

		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetActionConditionTermsList() {
			static std::vector<CTerm> action_condition_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_action_condition_terms_file_path);
				}();

			return action_condition_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshActionConditionTermsList() {
			CContentSerializer serializer;
			GetActionConditionTermsList() = serializer.DeserializeTerms(c_action_condition_terms_file_path);
		}


		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetHostileEntityTermsList() {
			static std::vector<CTerm> hostile_entity_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_hostile_entity_terms_file_path);
				}();

			return hostile_entity_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshHostileEntityTermsList() {
			CContentSerializer serializer;
			GetHostileEntityTermsList() = serializer.DeserializeTerms(c_hostile_entity_terms_file_path);
		}

		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetEquipmentAssetTermsList() {
			static std::vector<CTerm> equipment_asset_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_equipment_asset_terms_file_path);
				}();

			return equipment_asset_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshEquipmentAssetTermsList() {
			CContentSerializer serializer;
			GetEquipmentAssetTermsList() = serializer.DeserializeTerms(c_equipment_asset_terms_file_path);
		}

		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetOrganizationTermsList() {
			static std::vector<CTerm> organization_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_organization_terms_file_path);
				}();

			return organization_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshOrganizationTermsList() {
			CContentSerializer serializer;
			GetOrganizationTermsList() = serializer.DeserializeTerms(c_organization_terms_file_path);
		}

		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetSociostabilityTermsList() {
			static std::vector<CTerm> sociostability_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_sociostability_terms_file_path);
				}();

			return sociostability_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshSociostabilityTermsList() {
			CContentSerializer serializer;
			GetSociostabilityTermsList() = serializer.DeserializeTerms(c_sociostability_terms_file_path);
		}

		// Returns a mutable list of terms that are loaded from a JSON file
		inline std::vector<CTerm>& GetAreaTermsList() {
			static std::vector<CTerm> area_terms_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeTerms(c_area_terms_file_path);
				}();

			return area_terms_list;
		}

		// Reloads in-memory terms
		inline void RefreshAreaTermsList() {
			CContentSerializer serializer;
			GetAreaTermsList() = serializer.DeserializeTerms(c_area_terms_file_path);
		}

		// CIVIL PROTECTION ASSIGNMENTS

		// Returns a mutable list of assignments that are loaded from a JSON file
		inline std::vector<CAssignment>& GetMandateDutyAssignmentsList() {
			static std::vector<CAssignment> mandate_duties_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeAssignmentInfo(c_mandate_duty_assignments_file_path);
				}();

			return mandate_duties_list;
		}

		// Reloads in-memory assignments
		inline void RefreshMandateDutyAssignmentsList() {
			CContentSerializer serializer;
			GetMandateDutyAssignmentsList() = serializer.DeserializeAssignmentInfo(c_mandate_duty_assignments_file_path);
		}

		// Returns a mutable list of assignments that are loaded from a JSON file
		inline std::vector<CAssignment>& GetProtectionDutyAssignmentsList() {
			static std::vector<CAssignment> protection_duties_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeAssignmentInfo(c_protection_duty_assignments_file_path);
				}();

			return protection_duties_list;
		}

		// Reloads in-memory assignments
		inline void RefreshProtectionDutyAssignmentsList() {
			CContentSerializer serializer;
			GetProtectionDutyAssignmentsList() = serializer.DeserializeAssignmentInfo(c_protection_duty_assignments_file_path);
		}


		// Returns a mutable list of assignments that are loaded from a JSON file
		inline std::vector<CAssignment>& GetAssignmentExpectationsList() {
			static std::vector<CAssignment> assignment_expectations_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeAssignmentInfo(c_assignment_expectations_file_path);
				}();

			return assignment_expectations_list;
		}

		// Reloads in-memory assignments
		inline void RefreshAssignmentExpectationsList() {
			CContentSerializer serializer;
			GetAssignmentExpectationsList() = serializer.DeserializeAssignmentInfo(c_assignment_expectations_file_path);
		}

		// CONTRABAND INFO

		// Returns a mutable list of contraband types that are loaded from a JSON file
		inline std::vector<CContraband>& GetContrabandList() {
			static std::vector<CContraband> contraband_list =
				[] {
					CContentSerializer serializer;
					return serializer.DeserializeContrabandInfo(c_contraband_file_path);
				}();

			return contraband_list;
		}

		// Reloads in-memory contraband list
		inline void RefreshContrabandList() {
			CContentSerializer serializer;
			GetContrabandList() = serializer.DeserializeContrabandInfo(c_contraband_file_path);
		}
	}

}