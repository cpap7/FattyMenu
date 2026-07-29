#pragma once

#include <string>

namespace FattyMenu {
	class CCivicReward {
	private:
		std::string m_number{};
		std::string m_description{};

	public:
		// Constructors
		CCivicReward(const std::string& a_number, const std::string& a_description);
		CCivicReward() = default;

		// Destructor
		~CCivicReward() = default;

		// Accessors
		inline void SetNumber(const std::string& a_number)								{ m_number		= a_number;			}
		inline void SetDescription(const std::string& a_description)					{ m_description	= a_description;	}

		inline const std::string& GetNumber() const										{ return m_number;					}
		inline const std::string& GetDescription() const								{ return m_description;				}
	};

}