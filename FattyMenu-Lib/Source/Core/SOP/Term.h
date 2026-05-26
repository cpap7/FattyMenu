#pragma once

/* This contains the object definition of a "CTerm"
*
* The object is predominantly used in TerminologyIndex.h
* for declarations/definitions of each term used by Civil Protection,
* as well as a few other definitions for Transhuman Forces.
*/


namespace FattyMenu {

	// Combine jargon-related
	class CTerm {
	private:
		const char* m_term_label		= "";
		const char* m_term_description	= "";

	public: 
		// Constructors
		CTerm(const char* a_term_label, const char* a_term_description);	// For most term objects
		CTerm();

		// Destructor
		~CTerm() = default;

		// Accessors
		inline void SetName(const char* a_term_label)				{ m_term_label			= a_term_label;			}
		inline void SetDescription(const char* a_term_description)	{ m_term_description	= a_term_description;	}

		inline const char* GetName() const							{ return m_term_label;							}
		inline const char* GetDescription() const					{ return m_term_description;					}
	};
}