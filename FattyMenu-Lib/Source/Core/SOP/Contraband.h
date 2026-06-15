#pragma once

#include "CivilProtection/CPCodes.h" // For radio code definitions 
#include <vector>

namespace FattyMenu {
	class CContraband {
	private:
		CCode m_violation_code{};						// Violation is based on type of contraband
		std::vector<const char*> m_examples{};			// Vector holds different example contraband items
		const char* m_verdict = "";						// Verdict depends on the violation

	public:
		CContraband(const CCode& a_violation, const char* a_verdict, const std::vector<const char*>& a_examples);
		CContraband() = default;

		~CContraband() = default;

		// Accessors
		inline void SetViolationCode(const CCode& a_violation_code)			{ m_violation_code	= a_violation_code;	}
		inline void SetVerdict(const char* a_verdict)						{ m_verdict			= a_verdict;		}
		inline void SetExamples(const std::vector<const char*>& a_examples) { m_examples		= a_examples;		}

		inline const const CCode& GetViolationCode() const					{ return m_violation_code;				}
		inline const char* GetVerdict() const								{ return m_verdict;						}
		inline const std::vector<const char*>& GetExamples() const			{ return m_examples;					}

	
	};

}