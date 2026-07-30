#pragma once

#include "Code.h" 

#include <vector>
#include <string>

namespace FattyMenu {
	class CContraband {
	private:
		CCode m_violation_code{};						// Violation code is based on type of contraband
		std::vector<std::string> m_examples{};			// Vector holds different examples of  contraband items

	public:
		CContraband(const CCode& a_violation, const std::vector<std::string>& a_examples);
		CContraband() = default;

		~CContraband() = default;

		// Accessors
		inline void SetViolationCode(const CCode& a_violation_code)			{ m_violation_code	= a_violation_code;	}
		inline void SetExamples(const std::vector<std::string>& a_examples) { m_examples		= a_examples;		}

		inline const CCode& GetViolationCode() const						{ return m_violation_code;				}
		inline const std::vector<std::string>& GetExamples() const			{ return m_examples;					}

	
	};

}