#include "TFTerminologyIndex.h"

/* Terminology Index definitions
* Format = CTerm term_name = { const char* name, const char* description }
*/
namespace TFTerminology {

	// Action/Condition definitions
	namespace ActionCondition {
		CTerm audible = { "Audible", "A sound produced by a hostile or unidentified source" };
		CTerm blackout = { "Blackout", "Complete absence of contact, whether visual or auditory, with any entity or object" };
		CTerm condition_alpha = { "Condition alpha", "Standard condition when an engagement has concluded" };
		CTerm code_breakdown = { "Code breakdown", "A code to spread out and find cover during an engagement" };
		CTerm condition_quicksand = { "Condition quicksand", "To set up ambush positions for a hostile target to enter" };
		CTerm condition_shadow = { "Condition shadow", "Unable to locate hostile / target or provide support from behind" };
		CTerm shade = { "Shade", "Cover" };
		CTerm open_sharp = { "Open / Sharp", "Engage" };
		CTerm friendgame = { "Friendgame", "Tactic to attempt to gain trust with hostile target" };
		CTerm jackpot = { "Jackpot", "High-value target / Helix Vector Tango / HVT" };
		CTerm survival_mark = { "Survival mark", "A distress call for units in danger" };
		CTerm dagger_renew = { "Dagger renew", "The act of replacing the magazine in a firearm" };
		CTerm displace = { "Displace", "To disperse or move away, typically seeking cover or a different location" };
		CTerm flatline = { "Flatline", "When a subject exhibits no vital signs of life" };
		CTerm ripcord = { "Ripcord", "To withdraw, either tactically or otherwise" };
		CTerm suppression = { "Suppression", "Providing covering fire to limit the enemy's ability to return fire" };
		CTerm viscon = { "Viscon", "Visual identification or contact with a subject, object, or specific location" };
	}

	// Hostile entity definitions
	namespace HostileHumansAliens {
		CTerm contaminant = { "Contaminant", "A hostile entity either alien or human" };
		CTerm exogen = { "Exogen", "An external threat, breaching into controlled areas" };
		CTerm parasitic = { "Parasitic", "A headcrab" };
		CTerm necrotic = { "Necrotic", "A headcrab with a host body" };
		CTerm viromes = { "Viromes", "A virus or infection (e.g., antlions)" };
	}

	// Equipment/asset definitions
	namespace EquipmentAsset {
		CTerm antibody_protection_force = { "Antibody Protection Force (APF)", "Designation for a Combine suppressor unit" };
		CTerm echo = { "Echo", "Designation for a Combine grunt" };
		CTerm ghost_drop = { "Ghost drop", "Code for aerial deployment used to send ground reinforcements or supplies" };
		CTerm skyshield = { "Skyshield", "Code for aerial support or defense" };
		CTerm wallhammer = { "Wallhammer", "Designation for a Combine charger unit" };
		CTerm bouncer = { "Bouncer", "Refers to a live hostile grenade" };
		CTerm boosters = { "Boosters", "Upgraded weapons (i.e., with attachments)" };
		CTerm daggers = { "Daggers", "Firearm or weapon" };
		CTerm extractor = { "Extractor", "Denotes a live friendly grenade (except if it's from Preston)" };
		CTerm spikes = { "Spikes", "The act of emitting pulse energy fire" };
		CTerm bodypack = { "Bodypack", "Protective equipment issued to combine forces" };
		CTerm stimdose = { "Stim Dose", "Disposable medical device" };
	}


}