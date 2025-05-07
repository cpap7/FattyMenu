#include "CVoiceline.h"

/* Constructor for a CVoiceline object which takes specified strings for the trigger text and
* the description.
* 
* @param new_trigger_text -> a string containing the trigger for the CVoiceline
* @param new_voiceline_description -> a string containing the description of the CVoiceline
*/
CVoiceline::CVoiceline(const char* new_trigger_text, const char* new_voiceline_description) {
	SetTriggerText(new_trigger_text);
	SetVoicelineDescription(new_voiceline_description);
}

/* No-arg constructor */
CVoiceline::CVoiceline() : CVoiceline("", "") { }

// Destructor
// TODO: Implement if necessary
/* CVoiceline::~CVoiceline() { } */
	


/* Sets a new trigger text for a CVoiceline object
* @param new_trigger_text -> a string containing the trigger for the CVoiceline
*/
void CVoiceline::SetTriggerText(const char* new_trigger_text) {
	trigger_text = new_trigger_text;
}

/* Sets a new description for a CVoiceline object
* @param new_voiceline_description -> a string containing the description of the CVoiceline
*/
void CVoiceline::SetVoicelineDescription(const char* new_voiceline_description) {
	voiceline_description = new_voiceline_description;
}

/* @return -> a string containing the trigger text for a voiceline */
const char* CVoiceline::GetTriggerText() const {
	return trigger_text;
}

/* @return -> a string containing the description of the voiceline */
const char* CVoiceline::GetVoicelineDescription() const {
	return voiceline_description;
}