#pragma once
#include <string>

namespace FattyMenu {

	class CPackage {
	private: 
		std::string m_name	= "";
		int m_cost			= 0;
		int m_quantity		= 5; // NOTE: Most packages contain item quantities of 5

	public:
		CPackage(const std::string& a_name, int a_cost, int a_quantity = 5);
		CPackage() = default;

		~CPackage() = default;

		// Accessors
		inline void SetName(const std::string& a_name)	{ m_name = a_name;			}
		inline void SetCost(int a_cost)					{ m_cost = a_cost;			}
		inline void SetQuantity(int a_quantity)			{ m_quantity = a_quantity;	}

		inline const std::string& GetName() const		{ return m_name;			}
		inline int GetCost() const						{ return m_cost;			}
		inline int GetQuantity() const					{ return m_quantity;		}
	};
}