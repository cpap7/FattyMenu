#pragma once
#include "Package.h"

#include <vector>
#include <string>
#include <cstddef>

namespace FattyMenu {
	class CPermit {
	private:
		std::string m_name{};									// Name of the permit

		std::vector<CPackage> m_package_list{};					// List of packages available to the permit
		std::vector<std::string> m_authorized_items_list{};		// List of items authorized by the Combine for the permit holder to sell

		uint16_t m_civic_point_requirement{ 0 };				// Required # of civic points to purchase the permit
		uint16_t m_cost{ 0 };									// Required # of credits to purchase the permit
		
	public:
		CPermit(const std::string& a_name, uint16_t a_civic_point_requirement, uint16_t a_cost,
			const std::vector<CPackage>& a_package_list, const std::vector<std::string>& a_authorized_items_list);
		CPermit() = default;

		~CPermit() = default;

		// Accessors
		inline void SetPermitName(const std::string& a_name)										{ m_name					= a_name;						}
		inline void SetCivicPointRequirement(uint16_t a_civic_point_requirement)					{ m_civic_point_requirement = a_civic_point_requirement;	}
		inline void SetPermitCost(uint16_t a_cost)													{ m_cost					= a_cost;						}
		inline void SetPackages(const std::vector<CPackage>& a_package_list)						{ m_package_list			= a_package_list;				}
		inline void SetAuthorizedItems(const std::vector<std::string>& a_authorized_items_list)		{ m_authorized_items_list	= a_authorized_items_list;		}

		inline const std::string& GetPermitName() const												{ return m_name;											}
		inline uint16_t GetCivicPointRequirement() const											{ return m_civic_point_requirement;							}
		inline uint16_t GetPermitCost() const														{ return m_cost;											}
		inline const std::vector<CPackage>& GetPackages() const										{ return m_package_list;									}
		inline const std::vector<std::string>& GetAuthorizedItems() const							{ return m_authorized_items_list;							}
	
	};
}

