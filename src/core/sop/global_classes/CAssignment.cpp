#include "CAssignment.h"
// TODO: Finish documentation

// Constructors
// For Civil Protection 
CAssignment::CAssignment(const char* new_assignment_name, const char* new_units_required, std::vector<const char*> new_assignment_description) 
						 : tf_units_required(0), shift_duration(0), recommended_class("")  { // Set TF values to 0 or empty
	SetAssignmentName(new_assignment_name);
	SetCPUnitsRequired(new_units_required);
	SetAssignmentDescription(new_assignment_description);
}

// For Transhuman (length of shift + recommended class included)
CAssignment::CAssignment(const char* new_assignment_name, int new_units_required, int new_duration, 
						 const char* new_recommended_class, std::vector<const char*> new_assignment_description) {
	SetAssignmentName(new_assignment_name);
	SetTFUnitsRequired(new_units_required);
	SetShiftDuration(new_duration);
	SetRecommendedClass(new_recommended_class);
	SetAssignmentDescription(new_assignment_description);
} 


/* No-arg constructor */
CAssignment::CAssignment() : CAssignment("", 0, { "None" }) { } // Defaults to Civil Protection-related constructor

//Destructor
//CAssignment::~CAssignment() { } // Not needed, leaving it here just in case it's needed in the future 


// Setters
void CAssignment::SetAssignmentName(const char* new_assignment_name) {
	this->assignment_name = new_assignment_name;
}

void CAssignment::SetCPUnitsRequired(const char* new_units_required) {
	this->cp_units_required = new_units_required;
}

void CAssignment::SetTFUnitsRequired(int new_units_required) {
	this->tf_units_required = new_units_required;
}

// Transhuman related attribute setters
void CAssignment::SetShiftDuration(int new_duration) {
	this->shift_duration = new_duration;
}

void CAssignment::SetRecommendedClass(const char* new_recommended_class) {
	this->recommended_class = new_recommended_class;
}

void CAssignment::SetAssignmentDescription(std::vector<const char*> new_assignment_description) {
	this->assignment_description = new_assignment_description;
}

// Getters
const char* CAssignment::GetAssignmentName() const { 
	return this->assignment_name; 
}

const char* CAssignment::GetCPUnitsRequired() const { 
	return this->cp_units_required;
}

// Transhuman related attribute getters
int CAssignment::GetTFUnitsRequired() const {
	return this->tf_units_required;
}

int CAssignment::GetShiftDuration() const {
	return this->shift_duration;
}

const char* CAssignment::GetRecommendedClass() const {
	return this->recommended_class;
}

// For both Civil Protection and Transhuman
std::vector<const char*> CAssignment::GetAssignmentDescription() const {
	return this->assignment_description;
}
