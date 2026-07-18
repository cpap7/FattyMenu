#include "Permit.h"


namespace FattyMenu {
	CPermit::CPermit(const char* a_name, int a_civic_point_requirement, int a_cost, 
		const std::vector<CPackage>& a_package_list, const std::vector<const char*>& a_authorized_items_list) 
		: m_name(a_name), m_civic_point_requirement(a_civic_point_requirement), m_cost(a_cost), 
		m_package_list(a_package_list), m_authorized_items_list(a_authorized_items_list) {

	}
}