#pragma once
#include <vector>

class CCode {
public: // Function prototypes
	// Constructors
	// TODO: Possibly remove some of these flags.
	CCode(const char*, const char*, bool, bool, bool, bool);
	CCode(const char*, const char*, const char*);							// For violations
	CCode(const char*, std::vector<const char*>, std::vector<const char*>); // For override codes
	CCode();

	// Destructor
	//~CCode(); // Not needed, leaving it here just in case it's needed in the future 

	// Object attribute setters
	void SetName(const char*);
	void SetDescription(const char*);
	void SetViolationDescription(const char*);
	void SetOverrideDescription(std::vector<const char*>);
	void SetOverrideDirectives(std::vector<const char*>);

	// Boolean flag setters
	void SetAsAbbreviationCode(bool);
	void SetAsResponseCode(bool);
	void SetAsElevenCode(bool);
	void SetAsTenCode(bool);
	void SetAsViolationCode(bool);
	void SetAsOverrideCode(bool);

	// Getters for attributes
	const char* GetName() const;
	const char* GetDescription() const;
	const char* GetViolationDescription() const;						 // For violations
	std::vector<const char*> GetOverrideDescription() const;			 // For override codes
	std::vector<const char*> GetOverrideDirectives() const;				 // For override codes
	
	// Getters for boolean flags
	bool IsAbbreviationCode() const;
	bool IsResponseCode() const;
	bool IsElevenCode() const;
	bool IsTenCode() const;
	bool IsViolationCode() const;
	bool IsOverrideCode() const;

private: // Object attributes
	const char* code_name;												// Name of the code
	const char* code_description;										// Description of the code
	const char* violation_description;									// Description of the violation
	std::vector<const char*> override_code_description;					// Descriptions relevant to override codes
	std::vector<const char*> override_code_directives;					// Directives for override codes

	// Flags to make future search filtering implementations less of a headache later
	bool is_abbreviation_code;											// Flag for abbreviation codes
	bool is_response_code;												// Flag for response codes
	bool is_eleven_code;												// Flag for 11- radio codes
	bool is_ten_code;													// Flag for 10- radio codes
	bool is_violation_code;												// Flag for violation codes
	bool is_override_code;												// Flag for override codes
};





