#pragma once
#include <vector>

class CAssignment {
public:
	// Constructors
	CAssignment(const char*, const char*, std::vector<const char*>);				   // For Civil Protection
	CAssignment(const char*, int, int, const char*, std::vector<const char*>); // For Transhuman (length of shift + recommended class included)
	CAssignment();

	// Destructor
	//~CAssignment(); // Not needed, leaving it here just in case it's needed in the future 


	// Setters
	void SetAssignmentName(const char*);
	void SetCPUnitsRequired(const char*);						// Each Civil Protection assignment has their own unique description for unit requirements 						
	void SetTFUnitsRequired(int);								// Transhuman related assignments just indicate the number of units
	void SetShiftDuration(int);									// Transhuman related
	void SetRecommendedClass(const char*);						// Transhuman related
	void SetAssignmentDescription(std::vector<const char*>);

	// Getters
	const char* GetAssignmentName() const;
	const char* GetCPUnitsRequired() const;
	int GetTFUnitsRequired() const;								// Transhuman related
	int GetShiftDuration() const;								// Transhuman related
	const char* GetRecommendedClass() const;					// Transhuman related
	std::vector<const char*> GetAssignmentDescription() const;

	
private: // Object attributes
	const char* assignment_name;						// Title of the assignment
	const char* cp_units_required;						// Description of the types of units needed (Civil Protection)
	int tf_units_required;								// Number of units needed (Transhuman only)
	int shift_duration;									// Length of an assignment (Transhuman only)
	const char* recommended_class;						// Class that's recommended for a specific assignment (Transhuman only)
	std::vector<const char*> assignment_description;	// Vector to hold 1-3 strings containing info on how to perform the assignment  
};