#pragma once

// Combine jargon-related
class CTerm {
public: // Function prototypes
	// Constructors
	CTerm();
	CTerm(const char*, const char*);

	// Destructor
	// ~CTerm(); // Not needed, leaving it here just in case it's needed in the future 


	// Setters
	void SetName(const char*);
	void SetDescription(const char*);

	// Getters
	const char* GetName() const;
	const char* GetDescription() const;

private:
	const char* term_name;
	const char* term_description;
};