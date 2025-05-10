#include "CCivilStatus.h"


/* Constructor for a CCivilStatus object
* @param new_status_type -> string containing the name of the civil status
* @param new_status_definition -> string containing the definition of that status according to Combine 'law'
* @param new_interaction_directives -> list of strings detailing how to interact with citizens belonging to that particular type of civil status
*/
CCivilStatus::CCivilStatus(const char* new_status_type, const char* new_civic_point_range, 
						   const char* new_status_definition, std::vector<const char*> new_interaction_directives) {
	SetStatusType(new_status_type);
	SetCivicPointRange(new_civic_point_range);
	SetStatusDefinition(new_status_definition);
	SetInteractionDirectives(new_interaction_directives);
	
}

// No-arg constructor
CCivilStatus::CCivilStatus() : CCivilStatus("", "", "", { "" }) { }

// Destructor
// ~CCivilStatus(); // Not needed, leaving it here just in case it's needed in the future 


/* Sets a string containing the name of the civil status type
* @param new_status_type -> string containing the name of the civil status
*/
void CCivilStatus::SetStatusType(const char* new_status_type) {
	this->status_type = new_status_type;
}

/* Sets a string with the civic point range of a civil status type
* @param new_civic_point_range -> a string containing the civic point range of a civil status
*/
void CCivilStatus::SetCivicPointRange(const char* new_civic_point_range) {
	this->civic_point_range = new_civic_point_range;
}

/* Sets a string containing the definition of the civil status type
* @param new_status_defiinition -> string containing the definition of the civil status
*/
void CCivilStatus::SetStatusDefinition(const char* new_status_definition) {
	this->status_definition = new_status_definition;
}

/* Sets a vector of strings containing info on how to interact with citizens of a particular status type
* @param new_interaction_directives -> vector of strings for how Civil Protection should interact with a citzen of a given civil status
*/
void CCivilStatus::SetInteractionDirectives(std::vector<const char*> new_interaction_directives) {
	this->interaction_directives = new_interaction_directives;
}

/* @return -> a string containing the name of the civil status */
const char* CCivilStatus::GetStatusType() const {
	return status_type;
}

/* @return -> a string containing the civic point range of the civil status */
const char* CCivilStatus::GetCivicPointRange() const {
	return civic_point_range;
}

/* @return -> a string containing the definition of the civil status */
const char* CCivilStatus::GetStatusDefinition() const {
	return status_definition;
}

/* @return -> a vector of strings containing interaction directives for Civil Protection players */
std::vector<const char*> CCivilStatus::GetInteractionDirectives() const {
	return interaction_directives;
}

