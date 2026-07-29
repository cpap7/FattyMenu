#pragma once

#include <string>
#include <cstddef>

namespace FattyMenu {

	class CPackage {
	private: 
		std::string m_name{};

		uint16_t m_cost{ 0 };
		uint16_t m_quantity{ 5 }; // NOTE: Most packages contain item quantities of 5

	public:
		CPackage(const std::string& a_name, uint16_t a_cost, uint16_t a_quantity = 5);
		CPackage() = default;

		~CPackage() = default;

		// Accessors
		inline void SetName(const std::string& a_name)	{ m_name		= a_name;			}
		inline void SetCost(uint16_t a_cost)			{ m_cost		= a_cost;			}
		inline void SetQuantity(uint16_t a_quantity)	{ m_quantity	= a_quantity;		}

		inline const std::string& GetName() const		{ return m_name;					}
		inline uint16_t GetCost() const					{ return m_cost;					}
		inline uint16_t GetQuantity() const				{ return m_quantity;				}
	};
}