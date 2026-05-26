#include "Assignment.h"

namespace FattyMenu {

	CAssignment::CAssignment(const char* a_assignment_name, const char* a_cp_units_required, const std::vector<const char*>& a_assignment_description, EAssignmentType a_type)
		: m_assignment_name(a_assignment_name), m_cp_units_required(a_cp_units_required),
		m_assignment_description(a_assignment_description), m_assignment_type(a_type) {
	}

	CAssignment::CAssignment(const char* a_assignment_name, int a_tf_units_required, int a_tf_shift_duration,
		const char* a_tf_recommended_class, const std::vector<const char*>& a_assignment_description, EAssignmentType a_type)
		: m_assignment_name(a_assignment_name), m_tf_units_required(a_tf_units_required), m_tf_recommended_class(a_tf_recommended_class),
		m_assignment_description(a_assignment_description), m_assignment_type(a_type) {

	}

	// No-arg constructor defaults to Civil Protection
	CAssignment::CAssignment()
		: CAssignment("", 0, { "None" }, EAssignmentType::CivilProtection) { 
	}
}


