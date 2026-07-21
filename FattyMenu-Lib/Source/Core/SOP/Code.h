#pragma once

#include <string>
#include <vector>

namespace FattyMenu {

	enum class ECodeType : uint16_t {
		None			= 0,
		
		Abbreviation	= 1,
		ResponseCode	= 2,
		ElevenCode		= 3,
		TenCode			= 4,
		ViolationCode	= 5,
		OverrideCode	= 6,
		VerdictCode		= 7,

		Default			= None
	};
	
	inline std::string CodeTypeToString(ECodeType a_code_type) {
		switch (a_code_type) {
			case ECodeType::None:								break;

			case ECodeType::Abbreviation:						return "Abbreviation";
			case ECodeType::ResponseCode:						return "ResponseCode";
			case ECodeType::ElevenCode:							return "ElevenCode";
			case ECodeType::TenCode:							return "TenCode";
			case ECodeType::ViolationCode:						return "ViolationCode";
			case ECodeType::OverrideCode:						return "OverrideCode";
			case ECodeType::VerdictCode:						return "VerdictCode";

			default:											break;
		}

		return "None";
	}

	inline ECodeType CodeTypeFromString(const std::string& a_code_type_string) {
		// Yan-dev design pattern (lol)
		if (a_code_type_string == "Abbreviation")				{ return ECodeType::Abbreviation;	}
		else if (a_code_type_string == "ResponseCode")			{ return ECodeType::ResponseCode;	}
		else if (a_code_type_string == "ElevenCode")			{ return ECodeType::ElevenCode;		}
		else if (a_code_type_string == "ViolationCode")			{ return ECodeType::ViolationCode;	}
		else if (a_code_type_string == "OverrideCode")			{ return ECodeType::OverrideCode;	}
		else if (a_code_type_string == "VerdictCode")			{ return ECodeType::VerdictCode;	}

		return ECodeType::None;
	}

	// Optional for violation codes
	// Used for special cases for some frontend code (see CPSOP.cpp for some examples)
	enum class EViolationCodeNote : uint16_t {
		None					= 0,

		SanctionedDistribution	= 1,
		FirearmsCharge			= 2,

		Default					= None
	};

	inline std::string ViolationCodeNoteToString(EViolationCodeNote a_violation_code_note) {
		switch (a_violation_code_note) {
			case EViolationCodeNote::None:						break;
			
			case EViolationCodeNote::SanctionedDistribution:	return "SanctionedDistribution";
			case EViolationCodeNote::FirearmsCharge:			return "FirearmsCharge";
			
			default:											break;
		}

		return "None";
	}
	
	inline EViolationCodeNote ViolationCodeNoteFromString(const std::string& a_violation_code_note) {
		if (a_violation_code_note == "SanctionedDistribution")	{ return EViolationCodeNote::SanctionedDistribution;	}
		else if (a_violation_code_note == "FirearmsCharge")		{ return EViolationCodeNote::FirearmsCharge;			}

		return EViolationCodeNote::None;
	}

	class CCode {
	private:
		std::vector<const char*> m_override_code_description{};						// Descriptions relevant to override codes
		std::vector<const char*> m_override_code_directives{};						// Directives for override codes
		
		const char* m_name							= "";							// Name of the code
		const char* m_description					= "";							// Description of the code
		
		const char* m_violation_description			= "";							// Optional - violation code description
		EViolationCodeNote m_violation_code_note	= EViolationCodeNote::Default;	// Optional - for specific violation codes that require additional info/clarification

		ECodeType m_code_type						= ECodeType::Default;

	public:
		CCode(const char* a_name, const char* a_description, ECodeType a_code_type);
		CCode(const char* a_name, const char* a_description, const char* a_violation_description, 
			ECodeType a_code_type = ECodeType::ViolationCode, EViolationCodeNote a_violation_code_note = EViolationCodeNote::None);
		CCode(const char* a_name, const std::vector<const char*>& a_override_code_description, 
			const std::vector<const char*>& a_directives, ECodeType a_code_type = ECodeType::OverrideCode);
		CCode();

		~CCode() = default;
		
		// Accessors	
		inline void SetName(const char* a_name)														{ m_name						= a_name;										}
		inline void SetDescription(const char* a_description)										{ m_description					= a_description;								}
		inline void SetViolationDescription(const char* a_violation_description)					{ m_violation_description		= a_violation_description;						}
		inline void SetOverrideDescription(const std::vector<const char*>& a_override_description)	{ m_override_code_description	= a_override_description;						}
		inline void SetOverrideDirectives(const std::vector<const char*>& a_override_description)	{ m_override_code_directives	= a_override_description;						}
		inline void SetViolationCodeNote(EViolationCodeNote a_violation_code_note)					{ m_violation_code_note			= a_violation_code_note;						}
		inline void SetCodeType(ECodeType a_code_type)												{ m_code_type					= a_code_type;									}
	
		inline const char* GetName() const															{ return m_name;																}
		inline const char* GetDescription() const													{ return m_description;															}
		inline const char* GetViolationDescription() const											{ return m_violation_description;												}
		inline const std::vector<const char*>& GetOverrideDescription() const						{ return m_override_code_description;											}
		inline const std::vector<const char*>& GetOverrideDirectives() const						{ return m_override_code_directives;											}
		inline EViolationCodeNote GetViolationCodeNote() const										{ return m_violation_code_note;													}
		inline ECodeType GetCodeType() const														{ return m_code_type;															}

		// Additional helper functions
		inline bool IsAbbreviationCode() const														{ return m_code_type == ECodeType::Abbreviation;								}
		inline bool IsResponseCode() const															{ return m_code_type == ECodeType::ResponseCode;								}
		inline bool IsElevenCode() const															{ return m_code_type == ECodeType::ElevenCode;									}
		inline bool IsTenCode() const																{ return m_code_type == ECodeType::TenCode;										}
		inline bool IsViolationCode() const															{ return m_code_type == ECodeType::ViolationCode;								}
		inline bool IsOverrideCode() const															{ return m_code_type == ECodeType::OverrideCode;								}
		inline bool IsVerdictCode() const															{ return m_code_type == ECodeType::VerdictCode;									}
		inline bool HasCodeType() const																{ return m_code_type != ECodeType::Default || m_code_type != ECodeType::None;	}
	};

	class CViolationCodeCategory {
	private:
		std::string m_footnote{};								// Optional extra note to be displayed at the bottom of the UI
		
		const char* m_name						= "";			// Header/title in uppercase letters (i.e., "VIOLATION OF CIVIC TRUST")
		const char* m_description				= "";			// Category description string
		const char* m_table_id					= "";			// ImGui table ID

		const std::vector<CCode>* m_codes_list	= nullptr;		// Non-owning - violation codes come from existing lookup table
				
	public:
		CViolationCodeCategory(const char* a_name, const char* a_description, const char* a_table_id, 
			const std::vector<CCode>* a_codes_list, const std::string& a_footnote = "");
		~CViolationCodeCategory() = default;

		inline const char* GetName() const								{ return m_name;					}
		inline const char* GetDescription() const						{ return m_description;				}
		inline const char* GetTableID() const							{ return m_table_id;				}
		inline const std::vector<CCode>* GetCodes() const				{ return m_codes_list;				}
		inline const std::string& GetFootnote() const					{ return m_footnote;				}

		inline void SetName(const char* a_name)							{ m_name		= a_name;			}
		inline void SetDescription(const char* a_description)			{ m_description = a_description;	}
		inline void SetTableID(const char* a_table_id)					{ m_table_id	= a_table_id;		}
		inline void SetCodes(const std::vector<CCode>* a_codes_list)	{ m_codes_list	= a_codes_list;		}
		inline void SetFootnote(const std::string& a_footnote)			{ m_footnote	= a_footnote;		}
	};

}