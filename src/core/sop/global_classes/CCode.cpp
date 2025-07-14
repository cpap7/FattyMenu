#include "CCode.h"



/* Constructor for a CCode object that takes a specified name, description
* and boolean flag options. Specifically made for search filtering implementations. 
* 
* String params
* @param new_name -> string containing the name of the code
* @param new_description -> string containing the code's description
* 
*/
CCode::CCode(const char* new_name, const char* new_code_description, CodeType new_code_type) {	
	// Set the name & description
	SetName(new_name);
	SetDescription(new_code_description);
	
	// Set the flags
	SetCodeType(new_code_type);
}

/* Constructor for a CCode object that takes a specified name and description strings.
* This is specifically for violations.
* 
* String params
* @param new_name -> string containing the name of the code
* @param new_description -> string containing the code's description
* @param new_violation_description -> string containing the description of the code violation
*/
CCode::CCode(const char* new_name, const char* new_code_description, const char* new_violation_description, CodeType new_code_type) {
	// Set the name & description
	SetName(new_name);
	SetDescription(new_code_description);
	
	// Set the violation's description as well
	SetViolationDescription(new_violation_description);

	// Set the flags
	SetCodeType(new_code_type);
}

/* Constructor for a CCode object that takes a specified name, description, and vector of strings pertaining to directives.
* This is specifically for override codes.
*
* String params
* @param new_name -> string containing the name of the code
* @param new_description -> string containing the code's description
* @param new_override_code_directives -> vector containing the directives for the override code
*/
CCode::CCode(const char* new_name, std::vector<const char*> new_override_code_description, std::vector<const char*> new_directives, CodeType new_code_type) {
	SetName(new_name);
	SetOverrideDescription(new_override_code_description);
	SetOverrideDirectives(new_directives);

	// Set the flags
	SetCodeType(new_code_type);
}

/* No-arg constructor */
CCode::CCode() : CCode("", "", CodeType::None) { } // For non-violation codes

// Destructor
// CCode::~CCode() { } // Not needed, leaving it here just in case it's needed in the future 

/* Sets a name for a given CCode object
* @param new_name -> string containing the name to be set to the CCode object
*/
void CCode::SetName(const char* new_name) {
	this->code_name = new_name;
}

/* Sets a description for a given CCode object
* @param new_code_description -> string containing the description to be set to the CCode object
*/
void CCode::SetDescription(const char* new_code_description) {
	this->code_description = new_code_description;
}

/* Sets a description for a given CCode object pertaining to violations
* @param new_violation_description -> string containing the violation description to be set to the CCode object
*/
void CCode::SetViolationDescription(const char* new_violation_description) {
	this->violation_description = new_violation_description;
}

/* Sets a list of descriptions for a given CCode object specific to override codes
* @param new_override_description -> vector of strings containing the override code description being set to the CCode object
*/
void CCode::SetOverrideDescription(std::vector<const char*> new_override_description) {
	this->override_code_description = new_override_description;
}

/* Sets a list of directives for a given CCode object specific to override codes
* @param new_override_directives -> vector of strings containing the override code's directives being set to the CCode object
*/
void CCode::SetOverrideDirectives(std::vector<const char*> new_override_description) {
	this->override_code_directives = new_override_description;
}

/* Handles setting the boolean flags based on the code type
* @param new_code_type -> enum containing the radio code's corresponding type
*/
void CCode::SetCodeType(CodeType new_code_type) {
	// Set the flags to false (true by default)
	SetAsAbbreviationCode(false);
	SetAsResponseCode(false);
	SetAsElevenCode(false);
	SetAsTenCode(false);

	// Set the special case flags to false
	SetAsViolationCode(false);
	SetAsOverrideCode(false);

	// Check the code type value and set its corresponding boolean flag to true
	switch (new_code_type) {
		case CodeType::None:										break;
		case CodeType::Abbreviation:  SetAsAbbreviationCode(true);	break;
		case CodeType::ResponseCode:  SetAsResponseCode(true);		break;
		case CodeType::ElevenCode:	  SetAsElevenCode(true);		break;
		case CodeType::TenCode:		  SetAsTenCode(true);			break;
		case CodeType::ViolationCode: SetAsViolationCode(true);		break;
		case CodeType::OverrideCode:  SetAsOverrideCode(true);		break;
	}
}

/* Sets a boolean flag for CCode objects that are an abbreviation code
* @param new_abbreviation_code_flag -> true or false boolean value to be set to the CCode object
*/
void CCode::SetAsAbbreviationCode(bool new_abbreviation_code_flag) {
	this->is_abbreviation_code = new_abbreviation_code_flag;
}

/* Sets a boolean flag for CCode objects that are a response code
* @param new_response_code_flag -> true or false boolean value to be set to the CCode object
*/
void CCode::SetAsResponseCode(bool new_response_code_flag) {
	this->is_response_code = new_response_code_flag;
}

/* Sets a boolean flag for CCode objects that start with "11-"
* @param new_eleven_code_flag -> true or false boolean value to be set to the CCode object
*/
void CCode::SetAsElevenCode(bool new_eleven_code_flag) {
	this->is_eleven_code = new_eleven_code_flag;
}

/* Sets a boolean flag for CCode objects that start with "10-"
* @param new_ten_code_flag -> true or false boolean value to be set to the CCode object
*/
void CCode::SetAsTenCode(bool new_ten_code_flag) {
	this->is_ten_code = new_ten_code_flag;
}

/* Sets a boolean flag for CCode objects that are violations
* @param new_violation_code_flag -> true or false boolean value to be set to the CCode object
*/
void CCode::SetAsViolationCode(bool new_violation_code_flag) {
	this->is_violation_code = new_violation_code_flag;
}

/* Sets a boolean flag for CCode objects pertaining to override codes
* @param new_override_code_flag -> true or false boolean value to be set to the CCode object
*/
void CCode::SetAsOverrideCode(bool new_override_code_flag) {
	this->is_override_code = new_override_code_flag;
}

/* @return -> a string containing the name of the CCode */
const char* CCode::GetName() const {
	return this->code_name;
}

/* @return -> a string containing the description of the CCode */
const char* CCode::GetDescription() const {
	return this->code_description;
}

/* @return -> a string containing the description of the violation */
const char* CCode::GetViolationDescription() const {
	return this->violation_description;
}

/* @return -> a vector of strings containing the descriptions for an override code */
std::vector<const char*> CCode::GetOverrideDescription() const {
	return this->override_code_description;
}

/* @return -> a vector of strings containing the protocols for an override code */
std::vector<const char*> CCode::GetOverrideDirectives() const {
	return this->override_code_directives;
}

/* @return -> true or false depending on if the CCode is an abbreviation */
bool CCode::IsAbbreviationCode() const {
	return this->is_abbreviation_code;
}

/* @return -> true or false depending on if the CCode is a response code */
bool CCode::IsResponseCode() const {
	return this->is_response_code;
}

/* @return -> true or false depending on if the CCode starts with "11-" */
bool CCode::IsElevenCode() const {
	return this->is_eleven_code;
}

/* @return -> true or false depending on if the CCode starts with "10-" */
bool CCode::IsTenCode() const {
	return this->is_ten_code;
}

/* @return -> true or false depending on if the CCode is a violation */
bool CCode::IsViolationCode() const {
	return this->is_violation_code;
}

/* @return -> true or false depending on if the CCode is an override code */
bool CCode::IsOverrideCode() const {
	return this->is_override_code;
}


