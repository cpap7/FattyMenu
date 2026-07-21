#pragma once

#include <string>

namespace FattyMenu {

	// Player faction types
	enum class EPlayerFactionType : uint16_t {
		None					= 0,
		
		Airwatch				= 1,
		CivilProtection			= 2,
		FemaleCitizen			= 3,
		MaleCitizen				= 4,
		TranshumanCharger		= 8,
		TranshumanGrunt			= 5,
		TranshumanOrdinal		= 6,
		TranshumanSoldier		= 7,
		TranshumanSuppressor	= 9,
		Vortigaunt				= 10,
		
		Default					= None
	};

	std::string PlayerFactionToString(EPlayerFactionType a_player_faction) {
		switch (a_player_faction) {
			case EPlayerFactionType::None:					break;

			case EPlayerFactionType::Airwatch:				return "Airwatch";
			case EPlayerFactionType::CivilProtection:		return "CivilProtection";
			case EPlayerFactionType::FemaleCitizen:			return "FemaleCitizen";
			case EPlayerFactionType::MaleCitizen:			return "MaleCitizen";
			case EPlayerFactionType::TranshumanCharger:		return "TranshumanCharger";
			case EPlayerFactionType::TranshumanGrunt:		return "TranshumanGrunt";
			case EPlayerFactionType::TranshumanOrdinal:		return "TranshumanOrdinal";
			case EPlayerFactionType::TranshumanSoldier:		return "TranshumanSoldier";
			case EPlayerFactionType::TranshumanSuppressor:	return "TranshumanSuppressor";
			case EPlayerFactionType::Vortigaunt:			return "Vortigaunt";

			default:										break;

		}

		return "None";
	}

	EPlayerFactionType PlayerFactionFromString(const std::string& a_player_faction_string) {
		if (a_player_faction_string == "Airwatch")					{ return EPlayerFactionType::Airwatch;				}
		else if (a_player_faction_string == "CivilProtection")		{ return EPlayerFactionType::CivilProtection;		}
		else if (a_player_faction_string == "FemaleCitizen")		{ return EPlayerFactionType::FemaleCitizen;			}
		else if (a_player_faction_string == "MaleCitizen")			{ return EPlayerFactionType::MaleCitizen;			}
		else if (a_player_faction_string == "TranshumanCharger")	{ return EPlayerFactionType::TranshumanCharger;		}
		else if (a_player_faction_string == "TranshumanGrunt")		{ return EPlayerFactionType::TranshumanGrunt;		}
		else if (a_player_faction_string == "TranshumanOrdinal")	{ return EPlayerFactionType::TranshumanOrdinal;		}
		else if (a_player_faction_string == "TranshumanSoldier")	{ return EPlayerFactionType::TranshumanSoldier;		}
		else if (a_player_faction_string == "TranshumanSuppressor") { return EPlayerFactionType::TranshumanSuppressor;	}
		else if (a_player_faction_string == "Vortigaunt")			{ return EPlayerFactionType::Vortigaunt;			}

		return EPlayerFactionType::None;
	}

	enum class EPlayerFactionCategory : uint16_t {
		None	= 0,

		Combine = 1,	// Airwatch, Civil Protection, Transhuman factions
		Citizen = 2,	// Female & Male citizen factions
		Other	= 3,	// Vortigaunt faction (and Wallace Breen - voicelines exist but it's unused in game)

		Default = None
	};

	std::string PlayerFactionCategoryToString(EPlayerFactionCategory a_faction_category) {
		switch (a_faction_category) {
			case EPlayerFactionCategory::None:					break;
			
			case EPlayerFactionCategory::Combine:				return "Combine";
			case EPlayerFactionCategory::Citizen:				return "Citizen";
			case EPlayerFactionCategory::Other:					return "Other";
			
			default:											break;
		}

		return "None";
	}

	EPlayerFactionCategory PlayerFactionCategoryFromString(const std::string& a_player_faction_category_string) {
		if (a_player_faction_category_string == "Combine")		{ return EPlayerFactionCategory::Combine;	}
		else if (a_player_faction_category_string == "Citizen") { return EPlayerFactionCategory::Citizen;	}
		else if (a_player_faction_category_string == "Other")	{ return EPlayerFactionCategory::Other;		}

		return EPlayerFactionCategory::None;
	}

	class CVoiceline {
	private:
		const char* m_command								= "";	// Text to be copied to user's clipboard
		const char* m_full_voiceline						= "";	// Entire voiceline to be displayed next to the command

		// For filtering
		EPlayerFactionType m_player_faction_type			= EPlayerFactionType::Default;
		EPlayerFactionCategory m_player_faction_category	= EPlayerFactionCategory::Default;

	public:
		CVoiceline(const char* a_command, const char* a_full_voiceline, 
			EPlayerFactionType a_player_faction_type = EPlayerFactionType::Default, EPlayerFactionCategory a_player_faction_category = EPlayerFactionCategory::Default);
		CVoiceline() = default;

		// Destructor
		~CVoiceline() = default;

		// Setters
		inline void SetCommand(const char* a_command)								{ m_command				= a_command;										}
		inline void SetFullVoiceline(const char* a_full_voiceline)					{ m_full_voiceline		= a_full_voiceline;									}
		inline void SetPlayerFactionType(EPlayerFactionType a_player_faction_type)	{ m_player_faction_type	= a_player_faction_type;							}

		// Getters
		inline const char* GetCommand() const										{ return m_command;															}
		inline const char* GetFullVoiceline() const									{ return m_full_voiceline;													}
		inline EPlayerFactionType GetPlayerFactionType() const						{ return m_player_faction_type;												}
		
		// Filtering helpers
		// Player faction
		inline bool IsForAirwatch() const											{ return m_player_faction_type == EPlayerFactionType::Airwatch;				}
		inline bool IsForCivilProtection() const									{ return m_player_faction_type == EPlayerFactionType::CivilProtection;		}
		inline bool IsForFemaleCitizen() const										{ return m_player_faction_type == EPlayerFactionType::FemaleCitizen;		}
		inline bool IsForMaleCitizen() const										{ return m_player_faction_type == EPlayerFactionType::MaleCitizen;			}
		inline bool IsForTranshumanCharger() const									{ return m_player_faction_type == EPlayerFactionType::TranshumanCharger;	}
		inline bool IsForTranshumanGrunt() const									{ return m_player_faction_type == EPlayerFactionType::TranshumanGrunt;		}
		inline bool IsForTranshumanOrdinal() const									{ return m_player_faction_type == EPlayerFactionType::TranshumanOrdinal;	}
		inline bool IsForTranshumanSoldier() const									{ return m_player_faction_type == EPlayerFactionType::TranshumanSoldier;	}
		inline bool IsForTranshumanSuppressor() const								{ return m_player_faction_type == EPlayerFactionType::TranshumanSuppressor; }
		inline bool IsForVortigaunt() const											{ return m_player_faction_type == EPlayerFactionType::Vortigaunt;			}

		// Category
		inline bool IsForCombineCategory() const									{ return m_player_faction_category == EPlayerFactionCategory::Combine;		}
		//inline bool IsForCitizenCategory() const									{ return IsForFemaleCitizen() || IsForMaleCitizen();						}
		inline bool IsForCitizenCategory() const									{ return m_player_faction_category == EPlayerFactionCategory::Citizen;		}
		inline bool IsForOtherCategory() const										{ return m_player_faction_category == EPlayerFactionCategory::Other;		}
	};
}