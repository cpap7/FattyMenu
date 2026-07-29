#include "Code.h"

namespace FattyMenu {

	CCode::CCode(const std::string& a_name, const std::string& a_description, ECodeType a_code_type) 
		: m_name(a_name), m_description(a_description), m_code_type(a_code_type) {
	}
	

	// Violation code constructor
	CCode::CCode(const std::string& a_name, const std::string& a_description, const SViolationCodeDescriptor& a_violation_code_descriptor,
		ECodeType a_code_type)
		: m_name(a_name), m_description(a_description), m_violation_code_descriptor(a_violation_code_descriptor),
		m_code_type(a_code_type) {

	}

	// Override code constructor
	CCode::CCode(const std::string& a_name, const SOverrideCodeDescriptor& a_override_code_descriptor,
		ECodeType a_code_type) 
		: m_name(a_name), m_override_code_descriptor(a_override_code_descriptor), 
		m_code_type(a_code_type) {

	}

	CViolationCodeCategory::CViolationCodeCategory(const std::string& a_name, const std::string& a_description, const std::string& a_table_id,
		const std::vector<CCode>* a_codes_list, const std::string& a_footnote) 
		: m_footnote(a_footnote), m_name(a_name), m_description(a_description), 
		m_table_id(a_table_id), m_codes_list(a_codes_list) {
	}

}



