#pragma once

// Combine jargon-related
class CTerm {
public: // Function prototypes
	// Constructors
	CTerm();
	CTerm(const char*, const char*);	// For most terms
	CTerm(char, const char*);			// For Transhuman Phonetic Alphabet/Codes

	// Destructor
	// ~CTerm(); // Not needed, leaving it here just in case it's needed in the future 


	// Setters
	void SetName(const char*);
	void SetAlphabetChar(char);
	void SetDescription(const char*);

	// Getters
	const char* GetName() const;
	char GetAlphabetChar() const;
	const char* GetDescription() const;

private:
	const char* term_name;
	char term_alphabet_char;
	const char* term_description;
};