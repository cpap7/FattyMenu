#pragma once

namespace FattyMenu {

	class CVoiceline {
	private:
		const char* m_trigger_text				= ""; // Text to be copied to user's clipboard
		const char* m_voiceline_description		= "";

	public:
		CVoiceline(const char* a_trigger_text, const char* a_voiceline_description);
		CVoiceline() = default;

		// Destructor
		~CVoiceline() = default;

		// Setters
		inline void SetTriggerText(const char* a_trigger_text)						{ m_trigger_text = a_trigger_text;						}
		inline void SetVoicelineDescription(const char* a_voiceline_description)	{ m_voiceline_description = a_voiceline_description;	}

		// Getters
		inline const char* GetTriggerText() const									{ return m_trigger_text;								}
		inline const char* GetVoicelineDescription() const							{ return m_voiceline_description;						}

	
	};
}