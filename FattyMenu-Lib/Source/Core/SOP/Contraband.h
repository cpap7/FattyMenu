#pragma once

#include "CivilProtection/CPCodes.h" // For code definitions 
#include <vector>

namespace FattyMenu {
	class CContraband {
	private:
		CCode m_violation_code{};						// Violation is based on type of contraband
		std::vector<const char*> m_examples{};			// Vector holds different example contraband items

	public:
		CContraband(const CCode& a_violation, const std::vector<const char*>& a_examples);
		CContraband() = default;

		~CContraband() = default;

		// Accessors
		inline void SetViolationCode(const CCode& a_violation_code)			{ m_violation_code	= a_violation_code;	}
		inline void SetExamples(const std::vector<const char*>& a_examples) { m_examples		= a_examples;		}

		inline const CCode& GetViolationCode() const						{ return m_violation_code;				}
		inline const std::vector<const char*>& GetExamples() const			{ return m_examples;					}

	
	};

}