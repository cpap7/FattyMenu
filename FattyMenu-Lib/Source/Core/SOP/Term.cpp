#include "Term.h"

namespace FattyMenu {
	
	/* Constructor for a CTerm object which takes a specified name and description
	* @param new_name -> string containing the name of the term
	* @param new_description -> string containing the description of the term
	*/
	CTerm::CTerm(const char* a_term_label, const char* a_term_description) 
		: m_term_label(a_term_label), m_term_description(a_term_description)  { 	
	}

	/* No-arg constructor */
	CTerm::CTerm() 
		: CTerm("", "None") { 
	}

}
