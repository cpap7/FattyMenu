#include "CivilStatus.h"


namespace FattyMenu {
	CCivilStatus::CCivilStatus(const std::string& a_status_type, const std::string& a_civic_point_range,
		const std::string& a_status_definition, const std::vector<std::string>& a_administrative_directives)
		: m_status_type(a_status_type),m_civic_point_range(a_civic_point_range), 
		m_status_definition(a_status_definition), m_administrative_directives(a_administrative_directives) {
	}

}
