#pragma once

class CVoiceline {
public: // Function prototypes
	// Constructors
	CVoiceline(const char* new_trigger_text, const char* new_voiceline_description);
	CVoiceline(); // No-arg constructor
	
	// Destructor
	//~CVoiceline();

	// Setters
	void SetTriggerText(const char* new_trigger_text);
	void SetVoicelineDescription(const char* new_voiceline_description);

	// Getters
	const char* GetTriggerText() const;
	const char* GetVoicelineDescription() const;

private: // Object attributes
	const char* trigger_text; // Text to be copied to user's clipboard
	const char* voiceline_description;
};