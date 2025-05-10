#include "CContraband.h"


// Constructor
CContraband::CContraband(CCode& new_violation, const char* new_verdict, std::vector<const char*> new_examples) {
	SetViolationCode(new_violation);
	SetVerdict(new_verdict);
	SetExamples(new_examples);
}

CCode no_arg; // Empty CCode for no-arg constructor
// No-arg constructor 
CContraband::CContraband() : CContraband(no_arg, "", { "" }) { }

// Destructor
// ~CContraband(); // Not needed, leaving it here just in case it's needed in the future 

// Setters
void CContraband::SetViolationCode(CCode& new_violation) {
	this->violation = new_violation;
}

void CContraband::SetVerdict(const char* new_verdict) {
	this->verdict = new_verdict;
}

void CContraband::SetExamples(std::vector<const char*> new_examples) {
	this->examples = new_examples;
}

// Getters
const CCode& CContraband::GetViolationCode() const {
	return this->violation;
}

const char* CContraband::GetVerdict() const {
	return this->verdict;
}

std::vector<const char*> CContraband::GetExamples() const {
	return this->examples;
}