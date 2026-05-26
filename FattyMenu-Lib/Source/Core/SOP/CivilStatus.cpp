#include "CivilStatus.h"


namespace FattyMenu {
	CCivilStatus::CCivilStatus(const char* a_status_type, const char* a_status_definition, const char* a_civic_point_range, const std::vector<const char*>& a_interaction_directives) 
		: m_status_type(a_status_type), m_status_definition(a_status_definition), m_civic_point_range(a_civic_point_range), m_interaction_directives(a_interaction_directives) {
	}

}
