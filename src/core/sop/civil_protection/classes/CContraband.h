#pragma once

#include "../definitions/CPCodes.h" // For radio code definitions 
#include <vector>

class CContraband {
public:
	// Constructor
	CContraband(CCode&, const char*, std::vector<const char*>);
	CContraband(); // No-arg constructor

	// Destructor
	// ~CContraband(); // Not needed, leaving it here just in case it's needed in the future 

	// Setters
	void SetViolationCode(CCode&);
	void SetVerdict(const char*);
	void SetExamples(std::vector<const char*>);

	// Getters
	const CCode& GetViolationCode() const;
	const char* GetVerdict() const;
	std::vector<const char*> GetExamples() const;
	
private: // Object attributes
	CCode violation;				   // Violation is based on type of contraband
	const char* verdict;			   // Verdict depends on the violation
	std::vector<const char*> examples; // Vector holds different example contraband items
};