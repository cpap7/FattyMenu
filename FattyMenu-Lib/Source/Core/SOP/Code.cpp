#include "Code.h"

namespace FattyMenu {

	CCode::CCode(const char* a_code_name, const char* a_code_description, ECodeType a_code_type) 
		: m_code_name(a_code_name), m_code_description(a_code_description), m_code_type(a_code_type) {
	}
	
	CCode::CCode(const char* a_code_name, const char* a_code_description, const char* a_violation_description, ECodeType a_code_type) 
		:  m_code_name(a_code_name), m_code_description(a_code_description), m_violation_description(a_violation_description), m_code_type(a_code_type) {
	}
	
	CCode::CCode(const char* a_code_name, const std::vector<const char*>& a_override_code_description, const std::vector<const char*>& a_override_code_directives, ECodeType a_code_type) 
		: m_code_name(a_code_name), m_override_code_description(a_override_code_description), m_override_code_directives(a_override_code_directives), m_code_type(a_code_type) { 
	}


	/* No-arg constructor */
	CCode::CCode() 
		: CCode("", "", ECodeType::None) { // Calls first constructor
		
	}

	std::string CCode::CodeTypeToString(ECodeType a_code_type) {
		switch (a_code_type) {
			case ECodeType::None:			break;
			case ECodeType::Abbreviation:	return "Abbreviation";
			case ECodeType::ResponseCode:	return "Response Code";
			case ECodeType::ElevenCode:		return "11- code";
			case ECodeType::TenCode:		return "10- code";
			case ECodeType::ViolationCode:	return "Violation Code";
			case ECodeType::OverrideCode:	return "Override Code";

			default:						break;
		}

		return "None";
	}

}



