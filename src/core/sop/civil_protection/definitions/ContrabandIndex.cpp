#include "ContrabandIndex.h"

/* File for defining different contraband categories */
/* Format = 
   CContraband category_num = {
		CPRadioCodes::Violation::number,
		"VERDICT: ",
		{
			"Example 1",
			"Example 2",
			"Example 3",
			"Example 4"
		}
   };
 
*/
namespace ContrabandIndex {
	/* Verdict code = 54 */
	CContraband category_1 = {
		CPCodes::Violation::_54,
		"VERDICT: Citation",
		{
			"Scrap materials (aluminum, glass, etc.)",
			"Harmful chemicals and illicit narcotics",
			"Ballistic materials (aramid fiber)",
			"Concealing clothing (face wraps)"
		}
	};

	/* Verdict code = 69 */
	CContraband category_2 = {
		CPCodes::Violation::_69,
		"VERDICT: Prosecution",
		{
			"Communication devices (handheld radios)",
			"Non-sanctioned tools (zip ties, lockpicks)",
			"Advanced medical equipment and rations (vials, pens, anti-fatigue rations)",
			"Protective gear (armor, gas masks, helmets)"
		}
	};

	/* Verdict code = 95 */
	CContraband category_3 = {
		CPCodes::Violation::_95,
		"VERDICT: Request from Dispatch before proceeding",
		{
			"Melee weapons (knives, pipes, etc.)",
			"Ammunition and explosive devices",
			"Security bypass technology (EMP devices)",
			"Stolen assets (CMB packages, resin)"
		}
	};
}