#pragma once

// For making vector lists
#include <vector>	

// Class definitions (Civil Protection)
#include "../definitions/CPCodes.h"
#include "../definitions/ContrabandIndex.h"
#include "../definitions/CitizenInteractionDirectives.h"
#include "../definitions/CitizenRewards.h"
#include "../definitions/CPTerminologyIndex.h"
#include "../definitions/CPDuties.h"
#include "../definitions/PolitiScheduleEvent.h"

namespace CPSOPLookupTables {
	// Vector to hold abbreviation radio codes
	static const std::vector<CCode> abbreviation_list = {
		CPCodes::Abbreviation::adw,
		CPCodes::Abbreviation::bol,
		CPCodes::Abbreviation::cpt,
		CPCodes::Abbreviation::db,
		CPCodes::Abbreviation::goa,
		CPCodes::Abbreviation::upi,
		CPCodes::Abbreviation::utl,
		CPCodes::Abbreviation::_34s,
		CPCodes::Abbreviation::_187,
		CPCodes::Abbreviation::_415b,
		CPCodes::Abbreviation::_505
	};

	// Vector to hold response codes
	static const std::vector<CCode> response_code_list = {
		CPCodes::Response::code_1,
		CPCodes::Response::code_2,
		CPCodes::Response::code_3,
		CPCodes::Response::code_4,
		CPCodes::Response::code_7,
		CPCodes::Response::code_12,
		CPCodes::Response::code_100
	};

	// Vector to hold 11- codes
	static const std::vector<CCode> eleven_code_list = {
		CPCodes::Eleven::_116,
		CPCodes::Eleven::_1142,
		CPCodes::Eleven::_1143,
		CPCodes::Eleven::_1144,
		CPCodes::Eleven::_1194,
		CPCodes::Eleven::_1199
	};

	// Vector to hold 10- codes
	static const std::vector<CCode> ten_code_list = {
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

	// Code violation lists
	static const std::vector<CCode> anti_civil_level_5_violations = {
		CPCodes::Violation::_28,
		CPCodes::Violation::_35,
		CPCodes::Violation::_54,
		CPCodes::Violation::_59,
		CPCodes::Violation::_91,
		CPCodes::Violation::_311,
		CPCodes::Violation::_374b,
		CPCodes::Violation::_407,
		CPCodes::Violation::_488,
		CPCodes::Violation::_647f,
	};

	static const std::vector<CCode> anti_civil_level_1_violations = {
		CPCodes::Violation::_27,
		CPCodes::Violation::_62,
		CPCodes::Violation::_63,
		CPCodes::Violation::_69,
		CPCodes::Violation::_99,
		CPCodes::Violation::_415,
		CPCodes::Violation::_507,
		CPCodes::Violation::_647e
	};

	static const std::vector<CCode> socio_endangerment_level_5_violations = {
		CPCodes::Violation::_51,
		CPCodes::Violation::_51b,
		CPCodes::Violation::_63s,
		CPCodes::Violation::_95,
		CPCodes::Violation::_148,
		CPCodes::Violation::_603
	};

	static const std::vector<CCode> socio_endangerment_level_1_violations = {
		CPCodes::Violation::_17f,
		CPCodes::Violation::_94,
		CPCodes::Violation::_243,
		CPCodes::Violation::_404
	};

	// Override code list
	static const std::vector<CCode> override_code_list = {
		CPCodes::Override::sociostable,
		CPCodes::Override::unrest_procedure,
		CPCodes::Override::containment_procedure,
		CPCodes::Override::lockdown_procedure
	};

	// Civic point reward lists
	static const std::vector<CCivicReward> public_service_detail_list = {
		Rewards::PublicServiceDetails::t94_322,
		Rewards::PublicServiceDetails::t47_941,
		Rewards::PublicServiceDetails::t37_584,
	};

	static const std::vector<CCivicReward> civic_deed_list = {
		Rewards::CivicDeeds::d92_493,
		Rewards::CivicDeeds::d92_595,
		Rewards::CivicDeeds::d18_303,
		Rewards::CivicDeeds::d18_332,
		Rewards::CivicDeeds::d18_369,
		Rewards::CivicDeeds::d20_102
	};

	// Citizen interaction directive lists
	static const std::vector<CCivilStatus> citizen_interaction_directive_list = {
		StatusTypes::non_citizen,
		StatusTypes::standard_citizen,
		StatusTypes::priority_3_citizen,
		StatusTypes::priority_2_citizen,
		StatusTypes::priority_1_citizen
	};

	// Civil Protection Terminology lists
	static const std::vector<CTerm> protocol_list = {
		CPTerminology::Protocol::emergency_code,
		CPTerminology::Protocol::overload_protocol,
		CPTerminology::Protocol::prosecution,
		CPTerminology::Protocol::response,
		CPTerminology::Protocol::sacrifice
	};

	static const std::vector<CTerm> action_list = {
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

	static const std::vector<CTerm> action_condition_list = {
		CPTerminology::ActionCondition::cohesive,
		CPTerminology::ActionCondition::cohesion,
		CPTerminology::ActionCondition::expired,
		CPTerminology::ActionCondition::non_cohesive
	};

	static const std::vector<CTerm> hostile_list = {
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

	static const std::vector<CTerm> equipment_asset_list = {
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

	static const std::vector<CTerm> organization_list = {
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

	static const std::vector<CTerm> sociostability_list = {
		CPTerminology::Sociostability::combine_civil_code,
		CPTerminology::Sociostability::civic_trust,
		CPTerminology::Sociostability::tag,
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

	static const std::vector<CTerm> area_list = {
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

	static const std::vector<CPolitiSchedule> politi_schedule_event_list = {
		PolitiScheduleEvents::curfew,
		PolitiScheduleEvents::workforce_intake_1,
		PolitiScheduleEvents::ration_intake_1,
		PolitiScheduleEvents::workforce_intake_2,
		PolitiScheduleEvents::ration_intake_2,
		PolitiScheduleEvents::workforce_intake_3,
		PolitiScheduleEvents::ration_intake_1,
		PolitiScheduleEvents::workforce_intake_4
	};

	static const std::vector<CAssignment> mandate_duties_list = {
		CPAssignments::MandateDuties::curfew_procedure,
		CPAssignments::MandateDuties::ration_intake_detail
	};

	static const std::vector<CAssignment> protection_duties_list = {
		CPAssignments::ProtectionDuties::restricted_patrol_protocol,
		CPAssignments::ProtectionDuties::workforce_supervisory_detail,
		CPAssignments::ProtectionDuties::precinct_patrol_protocol,
		CPAssignments::ProtectionDuties::security_checkpoint_oversight,
		CPAssignments::ProtectionDuties::biotic_supervisory_detail,
		CPAssignments::ProtectionDuties::workforce_intake_processing,
		CPAssignments::ProtectionDuties::conscript_custody_oversight,
		CPAssignments::ProtectionDuties::surveillance_network_maintenance
	};

	static const std::vector<CAssignment> miscellaneous_duties_list = {
		CPAssignments::Miscellaneous::expectations,
		CPAssignments::Miscellaneous::tac_usage
	};

	static const std::vector<CContraband> contraband_list = {
		ContrabandIndex::category_1,
		ContrabandIndex::category_2,
		ContrabandIndex::category_3
	};
}
