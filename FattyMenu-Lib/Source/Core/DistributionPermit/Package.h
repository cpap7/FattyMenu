#pragma once

namespace FattyMenu {
	class CPackage {
	private: 
		const char* m_name	= "";
		int m_cost			= 0;

	public:
		CPackage(const char* a_name, int a_cost);
		CPackage() = default;

		~CPackage() = default;

		// Accessors
		inline void SetPackageName(const char* a_name)	{ m_name = a_name; }
		inline void SetPackageCost(int a_cost)			{ m_cost = a_cost; }

		inline const char* GetPackageName() const	{ return m_name; }
		inline int GetPackageCost() const			{ return m_cost; }
	};
}