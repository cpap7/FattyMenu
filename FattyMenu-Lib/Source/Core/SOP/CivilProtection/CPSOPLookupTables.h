#pragma once

// For making vector lists
#include <vector>	

// Class definitions (Civil Protection)
#include "CPCodes.h"
#include "ContrabandIndex.h"
#include "CivilStatusTypes.h"
#include "CitizenRewards.h"
#include "CPTerminologyIndex.h"
#include "CPDuties.h"
#include "Core/Tabs/CPSOP.h"

namespace FattyMenu {
	namespace CPSOPLookupTables {
		// List of abbreviation radio codes
		inline const std::vector<CCode> abbreviation_list = {
			CPCodes::Abbreviation::adw,
			CPCodes::Abbreviation::bol,
			CPCodes::Abbreviation::cpt,
			CPCodes::Abbreviation::db,
			CPCodes::Abbreviation::goa,
			CPCodes::Abbreviation::oc,
			CPCodes::Abbreviation::upi,
			CPCodes::Abbreviation::utl,
			CPCodes::Abbreviation::_34s,
			CPCodes::Abbreviation::_187,
			CPCodes::Abbreviation::_415b,
			CPCodes::Abbreviation::_505
		};

		// Response codes list
		inline const std::vector<CCode> response_code_list = {
			CPCodes::Response::code_1,
			CPCodes::Response::code_2,
			CPCodes::Response::code_3,
			CPCodes::Response::code_4,
			CPCodes::Response::code_7,
			CPCodes::Response::code_12,
			CPCodes::Response::code_100
		};

		// 11- codes list
		inline const std::vector<CCode> eleven_code_list = {
			CPCodes::Eleven::_116,
			CPCodes::Eleven::_1142,
			CPCodes::Eleven::_1143,
			CPCodes::Eleven::_1144,
			CPCodes::Eleven::_1194,
			CPCodes::Eleven::_1199
		};

		// 10- codes list
		inline const std::vector<CCode> ten_code_list = {
			CPCodes::Ten::_100,
			CPCodes::Ten::_101,
			CPCodes::Ten::_102,
			CPCodes::Ten::_103,
			CPCodes::Ten::_104,
			CPCodes::Ten::_106,
			CPCodes::Ten::_107,
			CPCodes::Ten::_108,
			CPCodes::Ten::_109,
			CPCodes::Ten::_1012,
			CPCodes::Ten::_1014,
			CPCodes::Ten::_1015,
			CPCodes::Ten::_1019,
			CPCodes::Ten::_1020,
			CPCodes::Ten::_1022,
			CPCodes::Ten::_1025,
			CPCodes::Ten::_1026,
			CPCodes::Ten::_1027,
			CPCodes::Ten::_1030,
			CPCodes::Ten::_1031,
			CPCodes::Ten::_1032,
			CPCodes::Ten::_1033,
			CPCodes::Ten::_1038,
			CPCodes::Ten::_1041,
			CPCodes::Ten::_1042,
			CPCodes::Ten::_1054d,
			CPCodes::Ten::_1065,
			CPCodes::Ten::_1078,
			CPCodes::Ten::_1091d,
			CPCodes::Ten::_1093,
			CPCodes::Ten::_1096,
			CPCodes::Ten::_1097,
			CPCodes::Ten::_1099,
			CPCodes::Ten::_10103,
			CPCodes::Ten::_10103m,
			CPCodes::Ten::_10107,
			CPCodes::Ten::_10108,
			CPCodes::Ten::_10109
		};

		// Verdict code list
		inline const std::vector<CCode> verdict_code_list = {
			CPCodes::Verdict::verbal_warning,
			CPCodes::Verdict::citation,
			CPCodes::Verdict::prosecution,
			CPCodes::Verdict::terminal_prosecution,
			CPCodes::Verdict::disassociation,
			CPCodes::Verdict::amputation,
			CPCodes::Verdict::immediate_amputation
		};

		// Violation code lists sorted by category
		// Violation category: Violation of civic trust
		inline const std::vector<CCode> violation_of_civic_trust_codes_list = {
			CPCodes::Violation::_27,
			CPCodes::Violation::_54,
			CPCodes::Violation::_62,
			CPCodes::Violation::_69,
			CPCodes::Violation::_91,
			CPCodes::Violation::_99,
			CPCodes::Violation::_311,
			CPCodes::Violation::_374b,
			CPCodes::Violation::_488,
			CPCodes::Violation::_647f
		};

		// Violation category: Failure to comply with the civil will
		inline const std::vector<CCode> failure_to_comply_with_the_civil_will_list = {
			CPCodes::Violation::_35,
			CPCodes::Violation::_59,
			CPCodes::Violation::_63,
			CPCodes::Violation::_148,
			CPCodes::Violation::_507,
			CPCodes::Violation::_647e
		};

		// Violation category: Promoting communal unrest
		inline const std::vector<CCode> promoting_communal_unrest_list = {
			CPCodes::Violation::_28,
			CPCodes::Violation::_404,
			CPCodes::Violation::_407,
			CPCodes::Violation::_415
		};

		// Violation category: Divisive sociocidal counter-obeyance
		inline const std::vector<CCode> divisive_sociocidal_counter_obeyance_list = {
			CPCodes::Violation::_17f,
			CPCodes::Violation::_51,
			CPCodes::Violation::_63s,
			CPCodes::Violation::_94,
			CPCodes::Violation::_95,
			CPCodes::Violation::_603
		};

		// Violation category: Destruction of corporal social protection units
		inline const std::vector<CCode> destruction_of_corporal_social_protection_units = {
			CPCodes::Violation::_51b,
			CPCodes::Violation::_243
		};

		// Container for each violation code based on category
		inline const std::vector<CViolationCodeCategory> violation_code_categories = {
			{
				"VIOLATION OF CIVIC TRUST",
				"Actions that undermine civic responsibility, authorized resource allocation, workforce obligations or public trust\n",
				"ViolationOfCivicTrustTable",
				&violation_of_civic_trust_codes_list,
				"Sanctioned distribution requires the permit holder to distribute only items corresponding to their permit inside their assigned distribution block. Units with at least 40 rank points may authorize distribution outside of their assigned block. Combine anti-fatigue rations may not be distributed whatsoever."
			},

			{
				"FAILURE TO COMPLY WITH THE CIVIL WILL",
				"Failure to obey, respect, or cooperate w / lawful directives issued by Civil Protection\n",
				"FailureToComplyWithTheCivilWillTable",
				&failure_to_comply_with_the_civil_will_list
			},

			{
				"PROMOTING COMMUNAL UNREST",
				"Actions intended to disrupt civic harmony, encourage disorder or undermine public stability\n",
				"PromotingCommunalUnrestTable",
				&promoting_communal_unrest_list
			},

			{
				"DIVISIVE SOCIOCIDAL COUNTER-OBEYANCE",
				"Organized resistance to authority, interference with operations, or support of anti - civil elements\n",
				"DivisiveSociocidalCounterObeyanceTable",
				&divisive_sociocidal_counter_obeyance_list
			},

			{
				"DESTRUCTION OF CORPORAL SOCIAL PROTECTION UNITS",
				"Acts resulting in damage to Civil Protection personnel, assets or operational capability\n",
				"DestructionOfCorporalSocialProtectionUnitsTable",
				&destruction_of_corporal_social_protection_units
			},
		};
		
		// Override code list
		inline const std::vector<CCode> override_code_list = {
			CPCodes::Override::sociostable,
			CPCodes::Override::unrest_procedure,
			CPCodes::Override::containment_procedure,
			CPCodes::Override::lockdown_procedure
		};

		// Civic reward lists
		inline const std::vector<CCivicReward> public_service_detail_list = {
			Rewards::GeneralPublicServiceDetails::t94_322,
			Rewards::GeneralPublicServiceDetails::t47_941,
			Rewards::GeneralPublicServiceDetails::t37_584,
		};

		inline const std::vector<CCivicReward> civic_deed_list = {
			Rewards::CivicDeeds::d92_493,
			Rewards::CivicDeeds::d92_595,
			Rewards::CivicDeeds::d18_303,
			Rewards::CivicDeeds::d18_332,
			Rewards::CivicDeeds::d18_369,
			Rewards::CivicDeeds::d20_102
		};

		// Civil status info list
		inline const std::vector<CCivilStatus> civil_status_info_list = {
			CivilStatusTypes::non_citizen,
			CivilStatusTypes::standard_citizen,
			CivilStatusTypes::priority_3_citizen,
			CivilStatusTypes::priority_2_citizen,
			CivilStatusTypes::priority_1_citizen
		};

		// Civil Protection Terminology lists
		inline const std::vector<CTerm> protocol_list = {
			CPTerminology::Protocol::emergency_code,
			CPTerminology::Protocol::overload_protocol,
			CPTerminology::Protocol::prosecution_code,
			CPTerminology::Protocol::response_code,
			CPTerminology::Protocol::sacrifice_code
		};

		inline const std::vector<CTerm> action_list = {
			CPTerminology::Action::administer,
			CPTerminology::Action::amputate,
			CPTerminology::Action::apply,
			CPTerminology::Action::cauterize,
			CPTerminology::Action::document,
			CPTerminology::Action::examine,
			CPTerminology::Action::inject,
			CPTerminology::Action::inoculate,
			CPTerminology::Action::inquire,
			CPTerminology::Action::intercede,
			CPTerminology::Action::interlock,
			CPTerminology::Action::investigate,
			CPTerminology::Action::isolate,
			CPTerminology::Action::lock,
			CPTerminology::Action::pacify,
			CPTerminology::Action::preserve,
			CPTerminology::Action::pressure,
			CPTerminology::Action::prosecute,
			CPTerminology::Action::restrict,
			CPTerminology::Action::search,
			CPTerminology::Action::serve,
			CPTerminology::Action::sterilize,
			CPTerminology::Action::suspend
		};

		inline const std::vector<CTerm> action_condition_list = {
			CPTerminology::ActionCondition::cohesive,
			CPTerminology::ActionCondition::cohesion,
			CPTerminology::ActionCondition::expired,
			CPTerminology::ActionCondition::non_cohesive,
			CPTerminology::ActionCondition::tag
		};

		inline const std::vector<CTerm> hostile_list = {
			CPTerminology::Hostile::anti_citizen,
			CPTerminology::Hostile::biotic,
			CPTerminology::Hostile::exogen,
			CPTerminology::Hostile::malcompliant,
			CPTerminology::Hostile::malignant,
			CPTerminology::Hostile::necrotic,
			CPTerminology::Hostile::non_citizen,
			CPTerminology::Hostile::non_corplex_indy,
			CPTerminology::Hostile::parasitic,
			CPTerminology::Hostile::person_of_interest,
			CPTerminology::Hostile::political_conscript,
			CPTerminology::Hostile::virome
		};

		inline const std::vector<CTerm> equipment_asset_list = {
			CPTerminology::EquipmentAsset::containment_field,
			CPTerminology::EquipmentAsset::ground_unit,
			CPTerminology::EquipmentAsset::protection_team,
			CPTerminology::EquipmentAsset::restrictor,
			CPTerminology::EquipmentAsset::stabilization_delegate,
			CPTerminology::EquipmentAsset::stabilization_force,
			CPTerminology::EquipmentAsset::stabilization_team,
			CPTerminology::EquipmentAsset::tag_unit,
			CPTerminology::EquipmentAsset::technician_team,
			CPTerminology::EquipmentAsset::sterilizer,
			CPTerminology::EquipmentAsset::viscerator,
			CPTerminology::EquipmentAsset::anti_fatigue,
			CPTerminology::EquipmentAsset::bodypack,
			CPTerminology::EquipmentAsset::gene_code,
			CPTerminology::EquipmentAsset::reproduction_credit,
			CPTerminology::EquipmentAsset::sterilized_credit,
			CPTerminology::EquipmentAsset::stim_boost,
			CPTerminology::EquipmentAsset::stim_dose,
			CPTerminology::EquipmentAsset::verdict,
		};

		inline const std::vector<CTerm> organization_list = {
			CPTerminology::Organizations::combine_overwatch,
			CPTerminology::Organizations::airwatch,
			CPTerminology::Organizations::civil_protection,
			CPTerminology::Organizations::transhuman_forces,
			CPTerminology::Organizations::synths,
			CPTerminology::Organizations::civic_populace,
			CPTerminology::Organizations::industrial_workforce,
			CPTerminology::Organizations::engineer_core,
			CPTerminology::Organizations::infestation_control,
			CPTerminology::Organizations::science_core,
			CPTerminology::Organizations::medical_workforce,
			CPTerminology::Organizations::security_council
		};

		inline const std::vector<CTerm> sociostability_list = {
			CPTerminology::Sociostability::combine_civil_code,
			CPTerminology::Sociostability::civic_trust,
			CPTerminology::Sociostability::loyalty_check_procedure,
			CPTerminology::Sociostability::memory_replacement,
			CPTerminology::Sociostability::recall_and_recycle,
			CPTerminology::Sociostability::miscount,
			CPTerminology::Sociostability::incursion,
			CPTerminology::Sociostability::permissive_inactive_coercion,
			CPTerminology::Sociostability::viral_interface_bypass,
			CPTerminology::Sociostability::socio_endangerment,
			CPTerminology::Sociostability::malcompliance,
			CPTerminology::Sociostability::malignancy,
			CPTerminology::Sociostability::active_signature_imprint,
			CPTerminology::Sociostability::passive_signature_imprint
		};

		inline const std::vector<CTerm> area_list = {
			CPTerminology::Areas::block,
			CPTerminology::Areas::canal_block,
			CPTerminology::Areas::control_section,
			CPTerminology::Areas::distribution_block,
			CPTerminology::Areas::transit_block,
			CPTerminology::Areas::polity,
			CPTerminology::Areas::production_block,
			CPTerminology::Areas::residential_block,
			CPTerminology::Areas::workforce_intake_hub,
			CPTerminology::Areas::deserviced_area,
			CPTerminology::Areas::repurposed_area,
			CPTerminology::Areas::condemned_zone,
			CPTerminology::Areas::industrial_zone,
			CPTerminology::Areas::infested_zone,
			CPTerminology::Areas::outland_zone,
			CPTerminology::Areas::quarantine_zone,
			CPTerminology::Areas::terminal_restriction_zone,
			CPTerminology::Areas::_404_zone,
			CPTerminology::Areas::section,
			CPTerminology::Areas::sector,
			CPTerminology::Areas::vector,
			CPTerminology::Areas::zone,
			CPTerminology::Areas::central_transport_facility,
			CPTerminology::Areas::citadel,
			CPTerminology::Areas::hardpoint,
			CPTerminology::Areas::nexus,
			CPTerminology::Areas::high_priority_region,
			CPTerminology::Areas::non_patrol_region
		};

		inline const std::vector<CAssignment> mandate_duties_list = {
			CPAssignments::MandateDuties::curfew_procedure,
			CPAssignments::MandateDuties::ration_intake_detail
		};

		inline const std::vector<CAssignment> protection_duties_list = {
			CPAssignments::ProtectionDuties::restricted_patrol_protocol,
			CPAssignments::ProtectionDuties::workforce_supervisory_detail,
			CPAssignments::ProtectionDuties::precinct_patrol_protocol,
			CPAssignments::ProtectionDuties::security_checkpoint_oversight,
			CPAssignments::ProtectionDuties::biotic_supervisory_detail,
			CPAssignments::ProtectionDuties::workforce_intake_processing,
			CPAssignments::ProtectionDuties::conscript_custody_oversight,
			CPAssignments::ProtectionDuties::surveillance_network_maintenance
		};

		inline const std::vector<CAssignment> miscellaneous_duties_list = {
			CPAssignments::Miscellaneous::expectations,
			CPAssignments::Miscellaneous::tac_usage
		};

		inline const std::vector<CContraband> contraband_list = {
			ContrabandIndex::category_1,
			ContrabandIndex::category_2,
			ContrabandIndex::category_3
		};
	}

}