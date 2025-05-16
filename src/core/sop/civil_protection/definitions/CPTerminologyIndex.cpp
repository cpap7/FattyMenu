#include "CPTerminologyIndex.h"

/* Terminology Index definitions
* Format = CTerm term_name = { const char* name, const char* description }
*/
namespace CPTerminology {

	// Protocol code definitions
	namespace Protocol {
		CTerm emergency_code = { "Emergency code", "Rules of operation during a priority emergency situation" };
		CTerm overload_protocol = { "Overload protocol", "A directive to use maximum force to contain or neutralize the situation" };
		CTerm prosecution = { "Prosecution code", "Rules of operation for teams called to prosecute an individual" };
		CTerm response = { "Response code", "Required form of response to a given situation and its level of urgency" };
		CTerm sacrifice = { "Sacrifice", "Achieve the given task even if it equates to certain death" };
	}

	// Action code definitions
	namespace Action {
		CTerm administer = { "Administer", "Manage or apply procedures for control or compliance" };
		CTerm amputate = { "Amputate", "To sever or execute, often used metaphorically to describe cutting off parts of a group or structure" };
		CTerm apply = { "Apply", "Put into action or use a particular tool or procedure (e.g., apply forward pressure)" };
		CTerm cauterize = { "Cauterize", "Take drastic or severe action to stop something harmful (e.g., an infection or rebellion)" };
		CTerm document = { "Document", "Record or observe details, possibly about citizens or locations" };
		CTerm examine = { "Examine", "Inspect closely, potentially for assessment or to find faults" };
		CTerm inject = { "Inject", "Introduce a substance or directive, into a system or population" };
		CTerm inoculate = { "Innoculate", "Protect against future threats through intense security measures" };
		CTerm inquire = { "Inquire", "Locate and retrieve a subject for interrogation" };
		CTerm intercede = { "Intercede", "Intervene in situations, potentially to stop certain actions or conflicts" };
		CTerm interlock = { "Interlock", "Lock together, unite to form a firm cohesive structure or team" };
		CTerm investigate = { "Investigate", "Look into an event or anomaly more closely, gathering information" };
		CTerm isolate = { "Isolate", "Separate an individual from the rest of a group to take punitive action" };
		CTerm lock = { "Lock", "Secure an area or mechanism, preventing entry or manipulation" };
		CTerm pacify = { "Pacify", "To subdue or incapacitate a target, usually via non-lethal means" };
		CTerm preserve = { "Preserve", "Maintain order or keep an area secure from external threats" };
		CTerm pressure = { "Pressure", "Apply force or pressure, likely to control or subdue an area or individuals" };
		CTerm prosecute = { "Prosecute", "Take legal or military action against an individual or group" };
		CTerm restrict = { "Restrict", "Limit movement or access, implementing controls over an area or people" };
		CTerm search = { "Search", "Conduct a search for contraband, individuals, or information" };
		CTerm serve = { "Serve", "Deliver a warning, command, or notice, often as part of enforcing civil code" };
		CTerm sterilize = { "Sterilize", "Cleanse an area or remove unwanted elements, often through lethal means" };
		CTerm suspend = { "Suspend", "Pause or halt a particular operation or activity" };
	}

	// Action/Condition definitions
	namespace ActionCondition {
		CTerm cohesive = { "Cohesive", "Together / working efficiently (e.g., Block is secure and working effectively)" };
		CTerm cohesion = { "Cohesion", "Sticking together (e.g., Officers are sticking together tightly)" };
		CTerm expired = { "Expired", "Subject is deceased" };
		CTerm non_cohesive = { "Non-cohesive", "Separated / working inefficiently (e.g., Squad is separated or down to the last man)" };
	}

	// Hostile entity definitions
	namespace Hostile {
		CTerm anti_citizen = { "Anti-citizen", "A status bestowed to a citizen who is deemed a threat" };
		CTerm biotic = { "Biotic", "Living organisms, distinct from synthetic or mechanical entities (i.e., antlions, vortiguants, etc.)" };
		CTerm exogen = { "Exogen", "External forces, typically referring to any hostile entities outside of Combine's control" };
		CTerm malcompliant = { "Malcompliant", "An individual who is disobedient or engages in defiance" };
		CTerm malignant = { "Malignant", "Used to describe something as criminally active, or a malicious force / threat" };
		CTerm necrotic = { "Necrotic", "Reanimated organisms, commonly referred to as zombies" };
		CTerm non_citizen = { "Non-citizen", "A status bestowed to an individual stripped of their citizenship" };
		CTerm non_corplex_indy = { "Non-corplex indy", "A non-metroplex, unregistered individual" };
		CTerm parasitic = { "Parasitic/parasite", "Headcrab" };
		CTerm person_of_interest = { "Person of interest", "A person being monitored, sought or questioned in connection with a criminal investigation or security operation, especially as a potential suspect" };
		CTerm political_conscript = { "Political conscript", "Enslaved vortigaunts or prisoners" };
		CTerm virome = { "Virome", "A pack, group or community of aliens" };
	}

	// Equipment/asset definitions
	namespace EquipmentAsset {
		CTerm containment_field = { "Containment field", "Refers to a Combine shield/forcefield" };
		CTerm ground_unit = { "Ground unit", "Refers to any Combine soldier or Civil Protection unit" };
		CTerm protection_team = { "Protection team", "Refers to a squad of Civil Protection units" };
		CTerm restrictor = { "Restrictor", "Refers to an antlion deterrent device (thumper)" };
		CTerm stabilization_delegate = { "Stabilization delegate", "Refers to an individual Combine soldier" };
		CTerm stabilization_force = { "Stabilization force", "Refers to a detachment or garrison of Combine soldiers" };
		CTerm stabilization_team = { "Stabilization team", "Refers to a squad of combine soldiers" };
		CTerm tag_unit = { "Tag unit", "Refers to any Combine Scanner" };
		CTerm technician_team = { "Technician team", "Refers to a group of Combine engineers" };
		CTerm sterilizer = { "Sterilizer", "Refers to a Combine sentry gun (ground/ceiling turret)" };
		CTerm viscerator = { "Viscerator", "Refers to an autonomous aerial weapon (manhack)" };
		CTerm anti_fatigue = { "Anti-fatigue", "An energy stimulant mixed into rations" };
		CTerm bodypack = { "Bodypack", "Armor, typically a combat vest" };
		CTerm gene_code = { "Gene-code", "Genetic markers used to restrict access to Combine equipment to certain individuals" };
		CTerm reproduction_credit = { "Reproduction credit", "Reward currency for both Civil Protection and the civic populace" };
		CTerm sterilized_credit = { "Sterilized credit", "Reward currency for both Civil Protection and the civic populace" };
		CTerm stim_boost = { "Stim-boost", "A drug that allows the user to get back into the fight quickly" };
		CTerm stim_dose = { "Stim-dose", "A medical vial or syringe which injects a substance with healing properties" };
		CTerm verdict = { "Verdict", "Ammunition, gunfire (also refers to type of punishment issued)" };
	}

	// Organization definitions
	namespace Organizations {
		CTerm combine_overwatch = { "Combine Overwatch", "The Combine's join humanoid military and police forces on Earth" };
		CTerm airwatch = { "Airwatch", "An aerial support and surveillance branch" };
		CTerm civil_protection = { "Civil Protection", "A conscripted human law enforcement force" };
		CTerm transhuman_forces = { "Transhuman forces", "A military ground force of modified human soldiers" };
		CTerm synths = { "Synths", "A conglomerate of modified species from various other worlds" };
		CTerm civic_populace = { "Civic populace", "All humans designated as citizens within a Combine-controlled city" };
		CTerm industrial_workforce = { "Industrial Workforce", "The Combine's humanoid civilian labor force" };
		CTerm engineer_core = { "Engineer Core", "A non-combatant technician unit that participates in the maintenance or construction of Combine technology and other infrastructure" };
		CTerm infestation_control = { "Infestation Control", "A non-combatant hazmat service that specializes in cleaning up areas that have been infested with alien flora and fauna from Xen" };
		CTerm science_core = { "Science Core", "A non-combatant human scientific division" };
		CTerm medical_workforce = { "Medical Workforce", "A volunteer-sanctioned medical group organized by civilians" };
		CTerm security_council = { "Security Council", "The puppet civilian body utilized to oversee minor civic affairs and spread Combine-affiliated propaganda" };
	}

	namespace Sociostability {
		CTerm combine_civil_code = { "Combine Civil Code", "'The law' imposed by the Combine Civil Authority" };
		CTerm civic_trust = { "Civic trust", "The 'trust' in a citizen to be law-abiding. Crimes are a breach of civic trust" };
		CTerm tag = { "Tag", "To identify or confirm a kill on a target" };
		CTerm loyalty_check_procedure = { "Loyalty check procedure", "A performative test/instruction to gauge a citizen's obedience/status" };
		CTerm memory_replacement = { "Memory replacement", "To receive a memory-altering procedure that washes away traumatic or negative sensations as part of the transhuman conversion process" };
		CTerm recall_and_recycle = { "Recall and recycle", "Withdraw from assigned objective and face disciplinary action" };
		CTerm miscount = { "Miscount", "Less or more citizens than to be accounted for" };
		CTerm incursion = { "Incursion", "A hostile breach of a Combine-controlled area" };
		CTerm permissive_inactive_coercion = { "Permissive inactive coercion", "Failure of an individual to report malcompliance in the community" };
		CTerm viral_interface_bypass = { "Viral interface bypass", "Unauthorized security systems breach/hacking a Combine interface" };
		CTerm socio_endangerment = { "Socio-endangerment", "Actions that threaten the stability of an urban zone" };
		CTerm malcompliance = { "Malcompliance", "Disobedience/failure to cooperate" };
		CTerm malignancy = { "Malignancy", "Organized disobedience or dissent against the Combine" };
		CTerm active_signature_imprint = { "Active signature imprint", "A strong energy signature from a specified location" };
		CTerm passive_signature_imprint = { "Passive signature imprint", "A faint energy signature from a specified region" };
	}

	namespace Areas {
		CTerm block = { "Block", "A small area in the city or a Combine installation/outpost" };
		CTerm canal_block = { "Canal block", "The part of the canals that's still within the confines of the city" };
		CTerm control_section = { "Control section", "Controlled area of significance" };
		CTerm distribution_block = { "Distribution block", "Storefront or commercial building" };
		CTerm transit_block = { "Transit block", "Train station area" };
		CTerm polity = { "Polity", "City/urban center" };
		CTerm production_block = { "Production block", "Factory/warehouse area" };
		CTerm residential_block = { "Residential block", "Housing area, usually consisting of multiple tenement buildings" };
		CTerm workforce_intake_hub = { "Workforce intake hub", "One of the only few official channels in or out of a city often used to take in new citizens from other cities" };
		CTerm deserviced_area = { "Deserviced area", "An area which is no longer in service by the Combine" };
		CTerm repurposed_area = { "Repurposed area", "An  area that has been refurbished to serve a different purpose than its original" };
		CTerm condemned_zone = { "Condemned zone", "A restricted area, likely one that is no longer in use" };
		CTerm industrial_zone = { "Industrial zone", "An industrialized zone containing pre-occupation factories" };
		CTerm infested_zone = { "Infested zone", "An area infested by alien presence containing parasites/xen growth" };
		CTerm outland_zone = { "Outland zone", "Areas outside of Combine-controlled cities" };
		CTerm quarantine_zone = { "Quarantine zone", "Restricted area infested by abundant alien presence" };
		CTerm terminal_restriction_zone = { "Terminal restriction zone", "No trespass under penalty of terminal prosecution" };
		CTerm _404_zone = { "404 zone", "An area where a riot or active communal unrest is currently ongoing" };
		CTerm section = { "Section", "A large area in the city determining Civil Protection jurisdiction" };
		CTerm sector = { "Sector", "A large region under Combine control/jurisdiction" };
		CTerm vector = { "Vector", "The position of one point in space relative to another" };
		CTerm zone = { "Zone", "A large purpose-oriented area, such as the industrial region of a city, a quarantine or the areas in between cities" };
		CTerm central_transport_facility = { "Central Transport Facility", "A depot housing prisoners and/or stalkers" };
		CTerm citadel = { "Citadel", "A Combine megastructure that houses a bulk of the Combine's assets" };
		CTerm hardpoint = { "Hardpoint", "An outlying structure or defensive position outside of a fortification" };
		CTerm nexus = { "Nexus", "A central command center for the Combine Overwatch's forces in a given region" };
		CTerm high_priority_region = { "High priority region", "An area with significant importance to the Combine" };
		CTerm non_patrol_region = { "Non-patrol region", "An area in which no effort is put into controlling" };
	}
}