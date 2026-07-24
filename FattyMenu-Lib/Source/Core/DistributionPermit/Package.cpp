#include "Package.h"


namespace FattyMenu {
	CPackage::CPackage(const std::string& a_name, int a_cost, int a_quantity)
		: m_name(a_name), m_cost(a_cost), m_quantity(a_quantity) {
	}

}