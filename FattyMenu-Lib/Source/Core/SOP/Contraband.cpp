#include "Contraband.h"

namespace FattyMenu {
	CContraband::CContraband(const CCode& a_violation_code, const std::vector<const char*>& a_examples)
		: m_violation_code(a_violation_code), m_examples(a_examples) {
	}

}