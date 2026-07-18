#pragma once

namespace FattyMenu {
	class CPackage {
	private: 
		const char* m_name	= "";
		int m_cost			= 0;
		int m_quantity		= 5; // NOTE: This is the same across all packages as of now

	public:
		CPackage(const char* a_name, int a_cost, int a_quantity = 5);
		CPackage() = default;

		~CPackage() = default;

		// Accessors
		inline void SetName(const char* a_name)	{ m_name = a_name;			}
		inline void SetCost(int a_cost)			{ m_cost = a_cost;			}
		inline void SetQuantity(int a_quantity)	{ m_quantity = a_quantity;	} // Optional -- added for completeness

		inline const char* GetName() const		{ return m_name;			}
		inline int GetCost() const				{ return m_cost;			}
		inline int GetQuantity() const			{ return m_quantity;		}
	};
}