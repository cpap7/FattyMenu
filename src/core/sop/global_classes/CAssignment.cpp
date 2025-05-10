#include "CAssignment.h"
// TODO: Finish documentation

// Constructors
// For Civil Protection 
CAssignment::CAssignment(const char* new_assignment_name, const char* new_units_required, std::vector<const char*> new_assignment_description) { 
	SetAssignmentName(new_assignment_name);
	SetUnitsRequired(new_units_required);
	SetShiftDuration(0);
	SetRecommendedClass("Civil Protection Unit");
	SetAssignmentDescription(new_assignment_description);
}

// For Transhuman (length of shift + recommended class included)
CAssignment::CAssignment(const char* new_assignment_name, const char* new_units_required, 
						 int new_duration, const char* new_recommended_class, 
						 std::vector<const char*> new_assignment_description) {
	SetAssignmentName(new_assignment_name);
	SetUnitsRequired(new_units_required);
	SetShiftDuration(new_duration);
	SetRecommendedClass(new_recommended_class);
	SetAssignmentDescription(new_assignment_description);
} 


/* No-arg constructor */
CAssignment::CAssignment() : CAssignment("", "", { "None" }) { } // Defaults to Civil Protection-related constructor

//Destructor
//CAssignment::~CAssignment() { } // Not needed, leaving it here just in case it's needed in the future 


// Setters
void CAssignment::SetAssignmentName(const char* new_assignment_name) {
	this->assignment_name = new_assignment_name;
}

void CAssignment::SetUnitsRequired(const char* new_units_required) {
	this->units_required = new_units_required;
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

const char* CAssignment::GetUnitsRequired() const { 
	return this->units_required;
}

// Transhuman related attribute getters
int CAssignment::GetShiftDuration() const {
	return this->shift_duration;
}

const char* CAssignment::GetRecommendedClass() const {
	return this->recommended_class;
}

std::vector<const char*> CAssignment::GetAssignmentDescription() const {
	return this->assignment_description;
}
