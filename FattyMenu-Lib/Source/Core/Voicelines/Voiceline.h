#pragma once
#include "../../Base.h"

#include <string>
#include <vector>
#include <type_traits>

namespace FattyMenu {

	// Player faction bitwise flags
	enum class EFaction : uint16_t {
		None					= 0,
		
		Airwatch				= BIT(0),
		CivilProtection			= BIT(1),
		FemaleCitizen			= BIT(2),
		MaleCitizen				= BIT(3),
		TranshumanCharger		= BIT(4),
		TranshumanGrunt			= BIT(5),
		TranshumanOrdinal		= BIT(6),
		TranshumanSoldier		= BIT(7),
		TranshumanSuppressor	= BIT(8),
		Vortigaunt				= BIT(9),
		
		Default					= None
	};

	// EFaction operator overloads for bit operations (i.e., OR, AND)

	constexpr EFaction operator|(EFaction a_lhs, EFaction a_rhs) {
		using underlying = std::underlying_type_t<EFaction>;

		return static_cast<EFaction>(static_cast<underlying>(a_lhs) | static_cast<underlying>(a_rhs));
	}

	constexpr EFaction& operator|=(EFaction& a_lhs, EFaction a_rhs) {
		a_lhs = a_lhs | a_rhs;
		return a_lhs;
	}

	constexpr EFaction operator&(EFaction a_lhs, EFaction a_rhs) {
		using underlying = std::underlying_type_t<EFaction>;

		return static_cast<EFaction>(static_cast<underlying>(a_lhs) & static_cast<underlying>(a_rhs));
	}

	constexpr EFaction& operator&=(EFaction& a_lhs, EFaction a_rhs) {
		a_lhs = a_lhs & a_rhs;
		return a_lhs;
	}

	constexpr EFaction operator~(EFaction a_value) {
		using underlying = std::underlying_type_t<EFaction>;

		return static_cast<EFaction>(~static_cast<underlying>(a_value));
	}

	constexpr bool HasFaction(EFaction a_value, EFaction a_flag) {
		return (a_value & a_flag) == a_flag;
	}

	// String conversion helpers for single faction bits

	// Converts a single faction bit to its corresponding string 
	inline std::string FactionToString(EFaction a_faction) {
		switch (a_faction) {
			case EFaction::None:					break;

			case EFaction::Airwatch:				return "Airwatch";
			case EFaction::CivilProtection:			return "Civil Protection";
			case EFaction::FemaleCitizen:			return "Female Citizen";
			case EFaction::MaleCitizen:				return "Male Citizen";
			case EFaction::TranshumanCharger:		return "Transhuman Charger";
			case EFaction::TranshumanGrunt:			return "Transhuman Grunt";
			case EFaction::TranshumanOrdinal:		return "Transhuman Ordinal";
			case EFaction::TranshumanSoldier:		return "Transhuman Soldier";
			case EFaction::TranshumanSuppressor:	return "Transhuman Suppressor";
			case EFaction::Vortigaunt:				return "Vortigaunt";

			default:								break;

		}

		return "None";
	}

	// Converts a single faction token to its corresponding faction bit
	inline EFaction FactionFromString(const std::string& a_faction_string) {
		if (a_faction_string == "Airwatch")						{ return EFaction::Airwatch;				}
		else if (a_faction_string == "Civil Protection")		{ return EFaction::CivilProtection;			}
		else if (a_faction_string == "Female Citizen")			{ return EFaction::FemaleCitizen;			}
		else if (a_faction_string == "Male Citizen")			{ return EFaction::MaleCitizen;				}
		else if (a_faction_string == "Transhuman Charger")		{ return EFaction::TranshumanCharger;		}
		else if (a_faction_string == "Transhuman Grunt")		{ return EFaction::TranshumanGrunt;			}
		else if (a_faction_string == "Transhuman Ordinal")		{ return EFaction::TranshumanOrdinal;		}
		else if (a_faction_string == "Transhuman Soldier")		{ return EFaction::TranshumanSoldier;		}
		else if (a_faction_string == "Transhuman Suppressor")	{ return EFaction::TranshumanSuppressor;	}
		else if (a_faction_string == "Vortigaunt")				{ return EFaction::Vortigaunt;				}

		return EFaction::None;
	}
	
	// Lookup table - Canonical list of all faction bits for the serializer & converter to iterate through
	inline constexpr EFaction c_voiceline_faction_flags[] = {
		EFaction::Airwatch,
		EFaction::CivilProtection,
		EFaction::FemaleCitizen,
		EFaction::MaleCitizen,
		EFaction::TranshumanCharger,
		EFaction::TranshumanGrunt,
		EFaction::TranshumanOrdinal,
		EFaction::TranshumanSoldier,
		EFaction::TranshumanSuppressor,
		EFaction::Vortigaunt
	};

	// Expands a combined bitmask into a list of faction name strings
	inline std::vector<std::string> FactionMaskToStrings(EFaction a_mask) {
		std::vector<std::string> faction_names;

		for (EFaction flag : c_voiceline_faction_flags) {
			if (HasFaction(a_mask, flag)) {
				faction_names.push_back(FactionToString(flag)); // Append to vector if found
			}
		}

		return faction_names;
	}

	// Builds a combined bitmask by ORing each faction token in a list
	inline EFaction FactionMaskFromStrings(const std::vector<std::string>& a_names) {
		EFaction faction_mask = EFaction::None;
		
		for (const std::string& name : a_names) {
			faction_mask |= FactionFromString(name);
		}

		return faction_mask;
	}

	class CVoiceline {
	private:
		std::string m_command				= "";	// Text to be copied to user's clipboard
		std::string m_full_voiceline		= "";	// Entire voiceline to be displayed next to the command

		// For filtering
		EFaction m_factions					= EFaction::Default;

	public:
		CVoiceline(const std::string& a_command, const std::string& a_full_voiceline, EFaction a_factions = EFaction::Default);
		CVoiceline() = default;

		// Destructor
		~CVoiceline() = default;

		// Setters
		inline void SetCommand(const std::string& a_command)									{ m_command					= a_command;							}
		inline void SetFullVoiceline(const std::string& a_full_voiceline)						{ m_full_voiceline			= a_full_voiceline;						}
		inline void SetFactions(EFaction a_factions)											{ m_factions				= a_factions;							}

		// Getters
		inline const std::string& GetCommand() const											{ return m_command;													}
		inline const std::string& GetFullVoiceline() const										{ return m_full_voiceline;											}
		inline EFaction GetFactions() const														{ return m_factions;												}

		// Filtering helpers
		// Player faction
		inline bool IsForAirwatch() const														{ return HasFaction(m_factions, EFaction::Airwatch);				}
		inline bool IsForCivilProtection() const												{ return HasFaction(m_factions, EFaction::CivilProtection);			}
		inline bool IsForFemaleCitizen() const													{ return HasFaction(m_factions, EFaction::FemaleCitizen);			}
		inline bool IsForMaleCitizen() const													{ return HasFaction(m_factions, EFaction::MaleCitizen);				}
		inline bool IsForTranshumanCharger() const												{ return HasFaction(m_factions, EFaction::TranshumanCharger);		}
		inline bool IsForTranshumanGrunt() const												{ return HasFaction(m_factions, EFaction::TranshumanGrunt);			}
		inline bool IsForTranshumanOrdinal() const												{ return HasFaction(m_factions, EFaction::TranshumanOrdinal);		}
		inline bool IsForTranshumanSoldier() const												{ return HasFaction(m_factions, EFaction::TranshumanSoldier);		}
		inline bool IsForTranshumanSuppressor() const											{ return HasFaction(m_factions, EFaction::TranshumanSuppressor);	}
		inline bool IsForVortigaunt() const														{ return HasFaction(m_factions, EFaction::Vortigaunt);				}
	};
}