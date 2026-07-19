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
		// Vector to hold abbreviation radio codes
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

		// Vector to hold response codes
		inline const std::vector<CCode> response_code_list = {
			CPCodes::Response::code_1,
			CPCodes::Response::code_2,
			CPCodes::Response::code_3,
			CPCodes::Response::code_4,
			CPCodes::Response::code_7,
			CPCodes::Response::code_12,
			CPCodes::Response::code_100
		};

		// Vector to hold 11- codes
		inline const std::vector<CCode> eleven_code_list = {
			CPCodes::Eleven::_116,
			CPCodes::Eleven::_1142,
			CPCodes::Eleven::_1143,
			CPCodes::Eleven::_1144,
			CPCodes::Eleven::_1194,
			CPCodes::Eleven::_1199
		};

		// Vector to hold 10- codes
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

		inline const std::vector<CCode> verdict_code_list = {
			CPCodes::Verdict::verbal_warning,
			CPCodes::Verdict::citation,
			CPCodes::Verdict::prosecution,
			CPCodes::Verdict::terminal_prosecution,
			CPCodes::Verdict::disassociation,
			CPCodes::Verdict::amputation,
			CPCodes::Verdict::immediate_amputation
		};

		// TODO: Revisit this later and have SViolationRow include CCode as a member/constructor argument  
		inline const std::vector<SViolationRow> civic_trust_violations = {
			// Columns:
			// Code				Violation							Description													Separate, optional note/flag - see TableRowTypes.h & DisplayViolationTable() function in CPSOP.cpp
			{ "27",				"Attempted crime",					"Attempting a violation w/o successful completion"													},
			{ "54",				"Possession of materials",			"Possession of minor contraband articles"															},
			{ "62",				"Alarms",							"Knowingly making false reports to Civil Protection"												},
			{ "69",				"Possession of resources",			"Possession of moderate contraband articles"														},
			{ "91",				"Non-sanctioned distribution",		"Distributing items outside authorized distribution zones",	EViolationNote::SanctionedDistribution	},
			{ "99",				"Reckless operation",				"Unsafe or negligent operation of equipment"														},
			{ "311",			"Verbal indiscretion",				"Loitering or excessive conversation w/o civic purpose"												},
			{ "374b",			"Illegal disposal",					"Littering, defacement, or unsanitary waste disposal"												},
			{ "488",			"Theft",							"Unlawful taking or scavenging of property"															},
			{ "647f",			"Civic dysfunction",                "Public intoxication or impairment"																	},
		};

		inline const std::vector<SViolationRow> civil_will_violations = {
			{ "35",				"Civil privacy violation",			"Unauthorized intrusion, observation or harassment"													},
			{ "59",				"Movement transgression",			"Excessive running, climbing, or unauthorized movement"												},
			{ "63",				"Criminal trespass",				"Entering a restricted area w/o authorization"														},
			{ "148",			"Resisting arrest",					"Resisting, evading or fleeing from prosecution"													},
			{ "507",		    "Public non-compliance",			"Failure to comply w/ lawful directives"															},
			{ "647e",			"Disengaged from Workforce",        "Deviating from assigned duties or non-corplex status"												},
		};

		inline const std::vector<SViolationRow> communal_unrest_violations = {
			{ "28",				"Felony incite",					"Encouraging or directing others to commit violations"												},
			{ "404",		    "Riot",								"Participating in or promoting communal unrest"														},
			{ "407",			"Unlawful assembly",				"Unauthorized gathering posing a stability risk"													},
			{ "415",			"Civic disunity",					"Disturbing public order assaulting civilians"														},
		};

		inline const std::vector<SViolationRow> divisive_sociocidal_violations = {
			{ "17f",			"Fugitive detachment",				"Haboring or concealing wanted individuals"															},
			{ "51",				"Non-sanctioned arson",				"Starting or spreading fire w/o authorization"														},
			{ "63s",			"Illegal in operation",				"Obstruction of authorized civic operations"														},
			{ "94",				"Weapon",							"Possession or use of any firearm"																	},
			{ "95",				"Illegal carrying",					"Possession of major contraband articles",					EViolationNote::FirearmsCharge			},
			{ "603",			"Unlawful entry",					"Gaining entry through force, fraud, or deception"													},
		};

		inline const std::vector<SViolationRow> destruction_violations = {
			{ "51b",			"Threat to property",				"Damage to Combine equipment, assets or infrastructure",											},
			{ "243",			"Assault on protection team",		"Any threat, physical contact or use of force directed against Overwatch forces"					},
		};

		// TODO: Old - revisit this later and integrate w/ SViolationRow LUTs above 
		// Violation Category: Violation of civic trust
		// Category Description: Actions that undermine civic responsibility, authorized resource allocation, workforce obligations or public trust
		inline const std::vector<CCode> violation_of_civic_trust_codes = {
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

		// Violation Category: Failure to comply with the civil will
		// Category Description: Failure to obey, respect, or cooperate w/ lawful directives issued by Civil Protection
		inline const std::vector<CCode> failure_to_comply_with_the_civil_will = {
			CPCodes::Violation::_35,
			CPCodes::Violation::_59,
			CPCodes::Violation::_63,
			CPCodes::Violation::_148,
			CPCodes::Violation::_507,
			CPCodes::Violation::_647e
		};

		// Violation Category: Promoting communal unrest
		// Category Description: Actions intented to disrupt civic harmony, encourage disorder or undermine public stability
		inline const std::vector<CCode> promoting_communal_unrest = {
			CPCodes::Violation::_28,
			CPCodes::Violation::_404,
			CPCodes::Violation::_407,
			CPCodes::Violation::_415
		};

		// Violation Category: Divisive sociocidal counter-obeyance
		// Category Description: Organized resistance to authority, interference with operations, or support of anti-civil elements
		inline const std::vector<CCode> divisive_sociocidal_counter_obeyance = {
			CPCodes::Violation::_17f,
			CPCodes::Violation::_51,
			CPCodes::Violation::_63s,
			CPCodes::Violation::_94,
			CPCodes::Violation::_95,
			CPCodes::Violation::_603
		};

		// Violation Category: Destruction of corporal social protection units
		// Category Description: Acts resulting in damage to Civil Protection personnel, assets or operational capability 		
		inline const std::vector<CCode> destruction_of_corporal_social_protection_units = {
			CPCodes::Violation::_51b,
			CPCodes::Violation::_243
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

		// Citizen interaction directive lists
		inline const std::vector<CCivilStatus> citizen_interaction_directive_list = {
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