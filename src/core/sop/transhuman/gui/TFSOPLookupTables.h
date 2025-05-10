#pragma once
#include "../definitions/TFDuties.h"
#include "../definitions/TFCodes.h"
#include "../definitions/TFTerminologyIndex.h"

namespace TFSOPLookupTables {
	/* Code index */
	// Alphabetic radio codes
	static const std::vector<CTerm> tf_radio_codes_list = {
		TFCodes::PhoneticAlphabetCode::a,
		TFCodes::PhoneticAlphabetCode::b,
		TFCodes::PhoneticAlphabetCode::c,
		TFCodes::PhoneticAlphabetCode::d,
		TFCodes::PhoneticAlphabetCode::e,
		TFCodes::PhoneticAlphabetCode::f,
		TFCodes::PhoneticAlphabetCode::g,
		TFCodes::PhoneticAlphabetCode::h,
		TFCodes::PhoneticAlphabetCode::i,
		TFCodes::PhoneticAlphabetCode::j,
		TFCodes::PhoneticAlphabetCode::k,
		TFCodes::PhoneticAlphabetCode::l,
		TFCodes::PhoneticAlphabetCode::m,
		TFCodes::PhoneticAlphabetCode::n,
		TFCodes::PhoneticAlphabetCode::o,
		TFCodes::PhoneticAlphabetCode::p,
		TFCodes::PhoneticAlphabetCode::q,
		TFCodes::PhoneticAlphabetCode::r,
		TFCodes::PhoneticAlphabetCode::s,
		TFCodes::PhoneticAlphabetCode::t,
		TFCodes::PhoneticAlphabetCode::u,
		TFCodes::PhoneticAlphabetCode::v,
		TFCodes::PhoneticAlphabetCode::w,
		TFCodes::PhoneticAlphabetCode::x,
		TFCodes::PhoneticAlphabetCode::y,
		TFCodes::PhoneticAlphabetCode::z
	};

	/* Terminology index */
	// Action / Condition list
	static const std::vector<CTerm> tf_action_condition_list = {
		TFTerminology::ActionCondition::audible,
		TFTerminology::ActionCondition::blackout,
		TFTerminology::ActionCondition::condition_alpha,
		TFTerminology::ActionCondition::code_breakdown,
		TFTerminology::ActionCondition::condition_quicksand,
		TFTerminology::ActionCondition::condition_shadow,
		TFTerminology::ActionCondition::shade,
		TFTerminology::ActionCondition::open_sharp,
		TFTerminology::ActionCondition::friendgame,
		TFTerminology::ActionCondition::jackpot,
		TFTerminology::ActionCondition::survival_mark,
		TFTerminology::ActionCondition::dagger_renew,
		TFTerminology::ActionCondition::displace,
		TFTerminology::ActionCondition::flatline,
		TFTerminology::ActionCondition::ripcord,
		TFTerminology::ActionCondition::suppression,
		TFTerminology::ActionCondition::viscon

	};

	// Hostile Humans / Aliens list
	static const std::vector<CTerm> tf_hostile_humans_aliens_list = {
		TFTerminology::HostileHumansAliens::contaminant,
		TFTerminology::HostileHumansAliens::exogen,
		TFTerminology::HostileHumansAliens::parasitic,
		TFTerminology::HostileHumansAliens::necrotic,
		TFTerminology::HostileHumansAliens::viromes
	};

	// Equipment / Asset list
	static const std::vector<CTerm> tf_equipment_asset_list = {
		TFTerminology::EquipmentAsset::antibody_protection_force,
		TFTerminology::EquipmentAsset::echo,
		TFTerminology::EquipmentAsset::ghost_drop,
		TFTerminology::EquipmentAsset::skyshield,
		TFTerminology::EquipmentAsset::wallhammer,
		TFTerminology::EquipmentAsset::bouncer,
		TFTerminology::EquipmentAsset::boosters,
		TFTerminology::EquipmentAsset::daggers,
		TFTerminology::EquipmentAsset::extractor,
		TFTerminology::EquipmentAsset::spikes,
		TFTerminology::EquipmentAsset::bodypack,
		TFTerminology::EquipmentAsset::stimdose
	};

	// Stabilization duty index
	static const std::vector<CAssignment> tf_duties_list = {
		TFAssignments::StabilizationDuties::outland_sector_sweep,
		TFAssignments::StabilizationDuties::stalker_supervisory_detail,
		TFAssignments::StabilizationDuties::surveillance_network_maintenance,
		TFAssignments::StabilizationDuties::hazmat_scientist_security_oversight,
		TFAssignments::StabilizationDuties::asset_security_oversight,
		TFAssignments::StabilizationDuties::breach_containment_protocol
	};


}#pragma once
