#pragma once
#include "Package.h"
#include <vector>

namespace FattyMenu {
	class CPermit {
	private: 
		std::vector<CPackage> m_package_list{};					// List of packages available to the permit
		std::vector<const char*> m_authorized_items_list{};		// List of items authorized by the Combine for the permit holder to sell

		const char* m_name				= "";					// Name of the permit
		int m_civic_point_requirement	= 0;					// Required # of civic points to purchase the permit
		int m_cost						= 0;					// Required # of credits to purchase the permit
		

	public:
		CPermit(const char* a_name, int a_civic_point_requirement, int a_cost, const std::vector<CPackage>& a_package_list, const std::vector<const char*>& a_authorized_items_list);
		CPermit() = default;

		~CPermit() = default;

		// Accessors
		inline void SetPermitName(const char* a_name)												{ m_name					= a_name;						}
		inline void SetCivicPointRequirement(int a_civic_point_requirement)							{ m_civic_point_requirement = a_civic_point_requirement;	}
		inline void SetPermitCost(int a_cost)														{ m_cost					= a_cost;						}
		inline void SetPackages(const std::vector<CPackage>& a_package_list)						{ m_package_list			= a_package_list;				}
		inline void SetAuthorizedItems(const std::vector<const char*>& a_authorized_items_list)		{ m_authorized_items_list	= a_authorized_items_list;		}

		// Getters
		inline const char* GetPermitName() const													{ return m_name;											}
		inline int GetCivicPointRequirement() const													{ return m_civic_point_requirement;							}
		inline int GetPermitCost() const															{ return m_cost;											}
		inline const std::vector<CPackage>& GetPackages() const										{ return m_package_list;									}
		inline const std::vector<const char*>& GetAuthorizedItems() const							{ return m_authorized_items_list;							}


	
	};
}

