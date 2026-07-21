#include "Voiceline.h"

namespace FattyMenu {

	CVoiceline::CVoiceline(const char* a_command, const char* a_full_voiceline, 
		EPlayerFactionType a_player_faction_type, EPlayerFactionCategory a_player_faction_category)
		: m_command(a_command), m_full_voiceline(a_full_voiceline), 
		m_player_faction_type(a_player_faction_type), m_player_faction_category(a_player_faction_category) {

	}


}