#include "Term.h"

namespace FattyMenu {
	
	/* Constructor for a CTerm object which takes a specified label/name and description
	* @param a_term_label -> string containing the label or name of the term
	* @param a_term_description -> string containing the description of the term
	*/
	CTerm::CTerm(const std::string& a_term_label, const std::string& a_term_description)
		: m_term_label(a_term_label), m_term_description(a_term_description)  { 	
	}

}
