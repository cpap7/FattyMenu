#include "Assignment.h"

namespace FattyMenu {

	CAssignment::CAssignment(const std::string& a_assignment_name, const std::string& a_cp_units_required, 
		const std::vector<std::string>& a_assignment_description, EAssignmentType a_type)
		: m_assignment_name(a_assignment_name), m_cp_units_required(a_cp_units_required),
		m_assignment_description(a_assignment_description), m_assignment_type(a_type) {
	}

	CAssignment::CAssignment(const std::string& a_assignment_name, uint16_t a_tf_units_required, uint16_t a_tf_shift_duration,
		const std::string& a_tf_recommended_class, const std::vector<std::string>& a_assignment_description, EAssignmentType a_type)
		: m_assignment_name(a_assignment_name), m_tf_units_required(a_tf_units_required), m_tf_recommended_class(a_tf_recommended_class),
		m_assignment_description(a_assignment_description), m_assignment_type(a_type) {

	}

}


