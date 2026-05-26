#include "Contraband.h"

namespace FattyMenu {
	CContraband::CContraband(const CCode& a_violation_code, const char* a_verdict, const std::vector<const char*>& a_examples) 
		: m_violation_code(a_violation_code), m_verdict(a_verdict), m_examples(a_examples) {
	
	}

}