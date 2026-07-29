#pragma once

/* This contains the object definition of a "CTerm"
*
* The object is predominantly used in TerminologyIndex.h
* for declarations/definitions of each term used by Civil Protection,
* as well as a few other definitions for Transhuman Forces.
*/

#include <string>

namespace FattyMenu {

	// Combine jargon-related
	class CTerm {
	private:
		std::string m_term_label{};
		std::string m_term_description{};

	public: 
		// Constructors
		CTerm(const std::string& a_term_label, const std::string& a_term_description);	// For most term objects
		CTerm() = default;

		// Destructor
		~CTerm() = default;

		// Accessors
		inline void SetName(const std::string& a_term_label)				{ m_term_label			= a_term_label;			}
		inline void SetDescription(const std::string& a_term_description)	{ m_term_description	= a_term_description;	}

		inline const std::string& GetName() const							{ return m_term_label;							}
		inline const std::string& GetDescription() const					{ return m_term_description;					}
	};
}