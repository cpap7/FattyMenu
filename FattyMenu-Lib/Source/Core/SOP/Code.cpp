#include "Code.h"

namespace FattyMenu {

	CCode::CCode(const char* a_name, const char* a_description, ECodeType a_code_type) 
		: m_name(a_name), m_description(a_description), m_code_type(a_code_type) {
	}
	
	CCode::CCode(const char* a_name, const char* a_description, const char* a_violation_description, 
		ECodeType a_code_type, EViolationCodeNote a_violation_code_note)
		: m_name(a_name), m_description(a_description), m_violation_description(a_violation_description), 
		m_code_type(a_code_type), m_violation_code_note(a_violation_code_note) {
	
	}
	
	CCode::CCode(const char* a_name, const std::vector<const char*>& a_override_code_description, 
		const std::vector<const char*>& a_override_code_directives, ECodeType a_code_type) 
		: m_name(a_name), m_override_code_description(a_override_code_description), 
		m_override_code_directives(a_override_code_directives), m_code_type(a_code_type) { 
	}

	/* No-arg constructor */
	CCode::CCode() 
		: CCode("", "", ECodeType::Default) { // Calls first constructor
		
	}

	CViolationCodeCategory::CViolationCodeCategory(const char* a_name, const char* a_description, const char* a_table_id,
		const std::vector<CCode>* a_codes_list, const std::string& a_footnote) 
		: m_footnote(a_footnote), m_name(a_name), m_description(a_description), 
		m_table_id(a_table_id), m_codes_list(a_codes_list) {
	}

}



