#pragma once
#include <string>
#include <vector>


namespace FattyMenu {

	enum class ECodeType {
		None			= 0,
		Abbreviation	= 1,
		ResponseCode	= 2,
		ElevenCode		= 3,
		TenCode			= 4,
		ViolationCode	= 5,
		OverrideCode	= 6,
	};

	class CCode {
	private:
		std::vector<const char*> m_override_code_description{};				// Descriptions relevant to override codes
		std::vector<const char*> m_override_code_directives{};				// Directives for override codes

		const char* m_code_name					= "";						// Name of the code
		const char* m_code_description			= "";						// Description of the code
		const char* m_violation_description		= "";						// Description of the violation
		
		ECodeType m_code_type					= ECodeType::None;

	public:
		CCode(const char* a_name, const char* a_code_description, ECodeType a_code_type);
		CCode(const char* a_name, const char* a_code_description, const char* a_violation_description, ECodeType a_code_type = ECodeType::ViolationCode);	
		CCode(const char* a_name, const std::vector<const char*>& a_override_code_description, const std::vector<const char*>& a_directives, ECodeType a_code_type = ECodeType::OverrideCode);
		CCode();

		~CCode() = default;

		std::string CodeTypeToString(ECodeType a_code_type);

		// Accessors
		inline void SetName(const char* a_name)														{ m_code_name					= a_name;					}
		inline void SetDescription(const char* a_code_description)									{ m_code_description			= a_code_description;		}
		inline void SetViolationDescription(const char* a_violation_description)					{ m_violation_description		= a_violation_description;	}
		inline void SetOverrideDescription(const std::vector<const char*>& a_override_description)	{ m_override_code_description	= a_override_description;	}
		inline void SetOverrideDirectives(const std::vector<const char*>& a_override_description)	{ m_override_code_directives	= a_override_description;	}
		inline void SetCodeType(ECodeType a_code_type)												{ m_code_type					= a_code_type;				}
	
		inline const char* GetName() const															{ return m_code_name;										}
		inline const char* GetDescription() const													{ return m_code_description;								}
		inline const char* GetViolationDescription() const											{ return m_violation_description;							}
		inline const std::vector<const char*>& GetOverrideDescription() const						{ return m_override_code_description;						}
		inline const std::vector<const char*>& GetOverrideDirectives() const						{ return m_override_code_directives;						}
		inline ECodeType GetCodeType() const														{ return m_code_type;										}

		// Additional helper functions
		inline bool IsAbbreviationCode() const														{ return m_code_type == ECodeType::Abbreviation;			}
		inline bool IsResponseCode() const															{ return m_code_type == ECodeType::ResponseCode;			}
		inline bool IsElevenCode() const															{ return m_code_type == ECodeType::ElevenCode;				}
		inline bool IsTenCode() const																{ return m_code_type == ECodeType::TenCode;					}
		inline bool IsViolationCode() const															{ return m_code_type == ECodeType::ViolationCode;			}
		inline bool IsOverrideCode() const															{ return m_code_type == ECodeType::OverrideCode;			}
	};
}