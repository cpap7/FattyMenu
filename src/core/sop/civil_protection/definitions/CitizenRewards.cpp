#include "CitizenRewards.h"

/* This file contains definitions of different public 
* service details and civic deeds that would 
* enable Civil Protection units to award
* civic points and/or ration coupons to citizens.
*/

/* Format =
	CCivicReward name { int num_civic_points_reward, "Name", "Description" };
*/

namespace Rewards {
	/* Definitions of public service details */
	namespace PublicServiceDetails {
		CCivicReward t94_322 = { 1, "T94-322", "Cleaning, removing litter and disposing of trash in a specified area", "None" };
		CCivicReward t47_941 = { 2, "T47-941", "Auditing distribution blocks for contraband and other anti-civil activity", "None"};
		CCivicReward t37_584 = { 3, "T37-584", "Monitoring residential blocks for overcrowding, contraband, etc.", "Optional" };
	}

	/* Definitions of civic deeds */
	namespace CivicDeeds {
		CCivicReward d92_493 = { 2, "D92-493", "Turning in moderate articles of contraband (level 2)", "None" };
		CCivicReward d92_595 = { 2, "D92-595", "Turning in severe articles of contraband (level 1)", "None" };
		CCivicReward d18_303 = { 2, "D18-303", "Reporting moderate violation of offenders (anti-civil activity level 1)", "Optional" };
		CCivicReward d18_332 = { 2, "D18-332", "Reporting major violation offenders (socio-endangerment level 5)", "Optional" };
		CCivicReward d18_369 = { 2, "D18-369", "Reporting capital violation offenders (socio-endangerment level 1)", "Mandatory" };
		CCivicReward d20_102 = { 2, "D20-102", "Non-invasive aiding of a protection unit in a life-threatening situation", "Mandatory" };
	}
}