#pragma once
#include <vector>

class CAssignment {
public:
	// Constructors
	CAssignment(const char*, const char*, std::vector<const char*>);				   // For Civil Protection
	CAssignment(const char*, const char*, int, const char*, std::vector<const char*>); // For Transhuman (length of shift + recommended class included)
	CAssignment();

	// Destructor
	//~CAssignment(); // Not needed, leaving it here just in case it's needed in the future 


	// Setters
	void SetAssignmentName(const char*);
	void SetUnitsRequired(const char*);
	void SetShiftDuration(int);									// Transhuman related
	void SetRecommendedClass(const char*);						// Transhuman related
	void SetAssignmentDescription(std::vector<const char*>);

	// Getters
	const char* GetAssignmentName() const;
	const char* GetUnitsRequired() const;
	int GetShiftDuration() const;								// Transhuman related
	const char* GetRecommendedClass() const;					// Transhuman related
	std::vector<const char*> GetAssignmentDescription() const;

	
private: // Object attributes
	const char* assignment_name;						// Title of the assignment
	const char* units_required;							// Description for the types of units needed
	int shift_duration;									// Length of an assignment (Transhuman only)
	const char* recommended_class;						// Class that's recommended for a specific assignment (Transhuman only)
	std::vector<const char*> assignment_description;	// Vector to hold 1-3 strings containing info on how to perform the assignment  
};