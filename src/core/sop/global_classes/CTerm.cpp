#include "CTerm.h"

/* This contains the object definition of a "CTerm"
*
* The object is predominantly used in TerminologyIndex.h
* for declarations/definitions of each term used by Civil Protection,
* as well as a few other definitions for Transhuman.
*/


/* Constructor for a CTerm object which takes a specified name and description
* @param new_name -> string containing the name of the term
* @param new_description -> string containing the description of the term
*/
CTerm::CTerm(const char* new_name, const char* new_description) {
	// Set the name and description
	SetName(new_name);
	SetDescription(new_description);
}

/* No-arg constructor */
CTerm::CTerm() : CTerm("", "") { } 

// Destructor
// CTerm::~CTerm() { } // Not needed, leaving it here just in case it's needed in the future 

/* Sets a new name string for a CTerm object
* @param new_name -> string containing the name of the object
*/
void CTerm::SetName(const char* new_name) {
	this->term_name = new_name;
}

/* Sets a new description for a CTerm object
* @param new_description -> string containing the description of the term
*/
void CTerm::SetDescription(const char* new_description) {
	this->term_description = new_description;
}

/* @return -> a string containing the name of the CTerm object */
const char* CTerm::GetName() const {
	return this->term_name;
}

/* @return -> a string containing the description of the CTerm object */
const char* CTerm::GetDescription() const {
	return this->term_description;
}