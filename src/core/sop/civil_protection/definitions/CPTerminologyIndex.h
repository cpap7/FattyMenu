#pragma once

#include "../../global_classes/CTerm.h" // For CTerm class definition

/* Declarations for Terminology Index (dictionary for Combine jargon) */
namespace CPTerminology {
	
	// Protocol code definitions
	namespace Protocol {
		extern CTerm emergency_code;
		extern CTerm overload_protocol;
		extern CTerm prosecution;
		extern CTerm response;
		extern CTerm sacrifice;
	}

	// Action code definitions
	namespace Action {
		extern CTerm administer;
		extern CTerm amputate;
		extern CTerm apply;
		extern CTerm cauterize;
		extern CTerm document;
		extern CTerm examine;
		extern CTerm inject;
		extern CTerm inoculate;
		extern CTerm inquire;
		extern CTerm intercede;
		extern CTerm interlock;
		extern CTerm investigate;
		extern CTerm isolate;
		extern CTerm lock;
		extern CTerm pacify;
		extern CTerm preserve;
		extern CTerm pressure;
		extern CTerm prosecute;
		extern CTerm restrict;
		extern CTerm search;
		extern CTerm serve;
		extern CTerm sterilize;
		extern CTerm suspend;
	}

	// Action/Condition definitions
	namespace ActionCondition {
		extern CTerm cohesive;
		extern CTerm cohesion;
		extern CTerm expired;
		extern CTerm non_cohesive;
	}

	// Hostile entity definitions
	namespace Hostile {
		extern CTerm anti_citizen;
		extern CTerm biotic;
		extern CTerm exogen;
		extern CTerm malcompliant;
		extern CTerm malignant;
		extern CTerm necrotic;
		extern CTerm non_citizen;
		extern CTerm non_corplex_indy;
		extern CTerm parasitic;
		extern CTerm person_of_interest;
		extern CTerm political_conscript;
		extern CTerm virome;
	}

	// Equipment/asset definitions
	namespace EquipmentAsset {
		extern CTerm containment_field;
		extern CTerm ground_unit;
		extern CTerm protection_team;
		extern CTerm restrictor;
		extern CTerm stabilization_delegate;
		extern CTerm stabilization_force;
		extern CTerm stabilization_team;
		extern CTerm tag_unit;
		extern CTerm technician_team;
		extern CTerm sterilizer;
		extern CTerm viscerator;
		extern CTerm anti_fatigue;
		extern CTerm bodypack;
		extern CTerm gene_code;
		extern CTerm reproduction_credit;
		extern CTerm sterilized_credit;
		extern CTerm stim_boost;
		extern CTerm stim_dose;
		extern CTerm verdict;
	}

	// Organization definitions
	namespace Organizations {
		extern CTerm combine_overwatch;
		extern CTerm airwatch;
		extern CTerm civil_protection;
		extern CTerm transhuman_forces;
		extern CTerm synths;
		extern CTerm civic_populace;
		extern CTerm industrial_workforce;
		extern CTerm engineer_core;
		extern CTerm infestation_control;
		extern CTerm science_core;
		extern CTerm medical_workforce;
		extern CTerm security_council;
	}

	namespace Sociostability {
		extern CTerm combine_civil_code;
		extern CTerm civic_trust;
		extern CTerm tag;
		extern CTerm loyalty_check_procedure;
		extern CTerm memory_replacement;
		extern CTerm recall_and_recycle;
		extern CTerm miscount;
		extern CTerm incursion;
		extern CTerm permissive_inactive_coercion;
		extern CTerm viral_interface_bypass;
		extern CTerm socio_endangerment;
		extern CTerm malcompliance;
		extern CTerm malignancy;
		extern CTerm active_signature_imprint;
		extern CTerm passive_signature_imprint;
	}

	namespace Areas {
		extern CTerm block;
		extern CTerm canal_block;
		extern CTerm control_section;
		extern CTerm distribution_block;
		extern CTerm transit_block;
		extern CTerm polity;
		extern CTerm production_block;
		extern CTerm residential_block;
		extern CTerm workforce_intake_hub;
		extern CTerm deserviced_area;
		extern CTerm repurposed_area;
		extern CTerm condemned_zone;
		extern CTerm industrial_zone;
		extern CTerm infested_zone;
		extern CTerm outland_zone;
		extern CTerm quarantine_zone;
		extern CTerm terminal_restriction_zone;
		extern CTerm _404_zone;
		extern CTerm section;
		extern CTerm sector;
		extern CTerm vector;
		extern CTerm zone;
		extern CTerm central_transport_facility;
		extern CTerm citadel;
		extern CTerm hardpoint;
		extern CTerm nexus;
		extern CTerm high_priority_region;
		extern CTerm non_patrol_region;
	}
}

