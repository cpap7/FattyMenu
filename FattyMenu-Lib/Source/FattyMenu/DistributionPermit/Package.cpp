#include "Package.h"


namespace FattyMenu {
	CPackage::CPackage(const std::string& a_name, uint16_t a_cost, uint16_t a_quantity)
		: m_name(a_name), m_cost(a_cost), m_quantity(a_quantity) {
	}

}