#pragma once

#include "CharacterTypes/Airwatch.h"
#include "CharacterTypes/CivilProtection.h"
#include "CharacterTypes/FemaleCitizen.h"
#include "CharacterTypes/MaleCitizen.h"
#include "CharacterTypes/TranshumanGrunt.h"
#include "CharacterTypes/Vortigaunt.h"

#include <vector>

namespace FattyMenu {
	/* Look-up Tables */

	// Construct on first use accessors to prevent static init order fiasco between lookup tables
	const std::vector<CVoiceline>& GetAirwatchVoicelines();
	const std::vector<CVoiceline>& GetCivilProtectionVoicelines();
	const std::vector<CVoiceline>& GetFemaleCitizenVoicelines();
	const std::vector<CVoiceline>& GetMaleCitizenVoicelines();
	const std::vector<CVoiceline>& GetTranshumanGruntVoicelines();
	const std::vector<CVoiceline>& GetVortigauntVoicelines();
}