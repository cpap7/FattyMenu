#pragma once

#include <string>
#include <vector>
#include <cstdint>

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
			case ECodeType::ResponseCode:						return "Response Code";
			case ECodeType::ElevenCode:							return "Eleven Code";
			case ECodeType::TenCode:							return "Ten Code";
			case ECodeType::ViolationCode:						return "Violation Code";
			case ECodeType::OverrideCode:						return "Override Code";
			case ECodeType::VerdictCode:						return "Verdict Code";

			default:											break;
		}

		return "None";
	}

	inline ECodeType CodeTypeFromString(const std::string& a_code_type_string) {
		// Yan-dev design pattern (lol)
		if (a_code_type_string == "Abbreviation")					{ return ECodeType::Abbreviation;	}
		else if (a_code_type_string == "Response Code")				{ return ECodeType::ResponseCode;	}
		else if (a_code_type_string == "Eleven Code")				{ return ECodeType::ElevenCode;		}
		else if (a_code_type_string == "Ten Code")					{ return ECodeType::TenCode;		}
		else if (a_code_type_string == "Violation Code")			{ return ECodeType::ViolationCode;	}
		else if (a_code_type_string == "Override Code")				{ return ECodeType::OverrideCode;	}
		else if (a_code_type_string == "Verdict Code")				{ return ECodeType::VerdictCode;	}

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
			
			case EViolationCodeNote::SanctionedDistribution:	return "Sanctioned Distribution";
			case EViolationCodeNote::FirearmsCharge:			return "Firearms Charge";
			
			default:											break;
		}

		return "None";
	}
	
	inline EViolationCodeNote ViolationCodeNoteFromString(const std::string& a_violation_code_note) {
		if (a_violation_code_note == "Sanctioned Distribution")		{ return EViolationCodeNote::SanctionedDistribution;	}
		else if (a_violation_code_note == "Firearms Charge")		{ return EViolationCodeNote::FirearmsCharge;			}

		return EViolationCodeNote::None;
	}

	// NOTE: 
	// This could be done via dynamic dispatch, but given how simple the class is 
	// & the potential runtime overhead for dynamic dispatch, I've decided to leave it within a singular monolithic class
	// 
	// Moreover, these descriptor structs might be better suited to be placed within the class as private, but I can't be bothered with having to write :: everywhere

	struct SViolationCodeDescriptor {
		std::string m_description{};								// Optional - violation code description
		EViolationCodeNote m_note{ EViolationCodeNote::Default };	// Optional - for specific violation codes that require additional info/clarification
	};

	struct SOverrideCodeDescriptor {
		std::vector<std::string> m_description{};					// Optional - descriptions relevant to override codes
		std::vector<std::string> m_directives{};					// Optional - directives for override codes
	};

	class CCode {
	private:
		std::string m_name{};										// Name of the code
		std::string m_description{};								// Description of the code
		
		// Optional descriptors
		SOverrideCodeDescriptor m_override_code_descriptor{};
		SViolationCodeDescriptor m_violation_code_descriptor{};

		ECodeType m_code_type{ ECodeType::Default };

	public:
		// Code constructor - for most code types
		CCode(const std::string& a_name, const std::string& a_description, ECodeType a_code_type);
		
		// Violation code constructor
		CCode(const std::string& a_name, const std::string& a_description, const SViolationCodeDescriptor& a_violation_code_descriptor, 
			ECodeType a_code_type = ECodeType::ViolationCode);

		// Override code constructor
		CCode(const std::string& a_name, const SOverrideCodeDescriptor& a_override_code_descriptor,
			ECodeType a_code_type = ECodeType::OverrideCode);
		
		CCode() = default;
		~CCode() = default;
		
		// Accessors	
		inline void SetName(const std::string& a_name)													{ m_name									= a_name;							}
		inline void SetDescription(const std::string& a_description)									{ m_description								= a_description;					}
		inline void SetViolationDescription(const std::string& a_violation_description)					{ m_violation_code_descriptor.m_description = a_violation_description;			}
		inline void SetViolationCodeNote(EViolationCodeNote a_violation_code_note)						{ m_violation_code_descriptor.m_note		= a_violation_code_note;			}
		inline void SetOverrideDescription(const std::vector<std::string>& a_override_description)		{ m_override_code_descriptor.m_description	= a_override_description;			}
		inline void SetOverrideDirectives(const std::vector<std::string>& a_override_directives)		{ m_override_code_descriptor.m_directives	= a_override_directives;			}
		inline void SetCodeType(ECodeType a_code_type)													{ m_code_type								= a_code_type;						}
	
		inline const std::string& GetName() const														{ return m_name;																}
		inline const std::string& GetDescription() const												{ return m_description;															}
		inline const std::string& GetViolationDescription() const										{ return m_violation_code_descriptor.m_description;								}
		inline EViolationCodeNote GetViolationCodeNote() const											{ return m_violation_code_descriptor.m_note;									}
		inline const std::vector<std::string>& GetOverrideDescription() const							{ return m_override_code_descriptor.m_description;								}
		inline const std::vector<std::string>& GetOverrideDirectives() const							{ return m_override_code_descriptor.m_directives;								}
		inline ECodeType GetCodeType() const															{ return m_code_type;															}

		// Additional helper functions
		inline bool IsAbbreviationCode() const															{ return m_code_type == ECodeType::Abbreviation;								}
		inline bool IsResponseCode() const																{ return m_code_type == ECodeType::ResponseCode;								}
		inline bool IsElevenCode() const																{ return m_code_type == ECodeType::ElevenCode;									}
		inline bool IsTenCode() const																	{ return m_code_type == ECodeType::TenCode;										}
		inline bool IsViolationCode() const																{ return m_code_type == ECodeType::ViolationCode;								}
		inline bool IsOverrideCode() const																{ return m_code_type == ECodeType::OverrideCode;								}
		inline bool IsVerdictCode() const																{ return m_code_type == ECodeType::VerdictCode;									}
		inline bool HasCodeType() const																	{ return m_code_type != ECodeType::Default || m_code_type != ECodeType::None;	}
	};

	class CViolationCodeCategory {
	private:
		std::string m_name{};									// Header/title in uppercase letters (i.e., "VIOLATION OF CIVIC TRUST")
		std::string m_description{};							// Category description string
		std::string m_footnote{};								// Optional extra note to be displayed at the bottom of the UI
		
		std::string m_table_id{};								// ImGui table ID

		const std::vector<CCode>* m_codes_list	= nullptr;		// Non-owning - violation codes come from existing lookup table
				
	public:
		CViolationCodeCategory(const std::string& a_name, const std::string& a_description, const std::string& a_table_id,
			const std::vector<CCode>* a_codes_list, const std::string& a_footnote = "");

		CViolationCodeCategory()	= default;
		~CViolationCodeCategory()	= default;

		inline const std::string& GetName() const								{ return m_name;					}
		inline const std::string& GetDescription() const						{ return m_description;				}
		inline const std::string& GetFootnote() const							{ return m_footnote;				}
		inline const std::string& GetTableID() const							{ return m_table_id;				}
		inline const std::vector<CCode>* GetCodes() const						{ return m_codes_list;				}

		inline void SetName(const std::string& a_name)							{ m_name		= a_name;			}
		inline void SetDescription(const std::string& a_description)			{ m_description = a_description;	}
		inline void SetFootnote(const std::string& a_footnote)					{ m_footnote	= a_footnote;		}
		inline void SetTableID(const std::string& a_table_id)					{ m_table_id	= a_table_id;		}
		inline void SetCodes(const std::vector<CCode>* a_codes_list)			{ m_codes_list	= a_codes_list;		}
	};

}