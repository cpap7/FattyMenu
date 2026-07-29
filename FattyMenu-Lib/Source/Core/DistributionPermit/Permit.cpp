#include "Permit.h"


namespace FattyMenu {
	CPermit::CPermit(const std::string& a_name, uint16_t a_civic_point_requirement, uint16_t a_cost,
		const std::vector<CPackage>& a_package_list, const std::vector<std::string>& a_authorized_items_list)
		: m_name(a_name), m_civic_point_requirement(a_civic_point_requirement), m_cost(a_cost), 
		m_package_list(a_package_list), m_authorized_items_list(a_authorized_items_list) {

	}
}