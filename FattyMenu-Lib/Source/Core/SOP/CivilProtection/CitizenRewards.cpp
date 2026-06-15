#include "CitizenRewards.h"

/* This file contains definitions of different public 
* service details and civic deeds that would 
* allow Civil Protection units to award
* civic points and/or ration coupons to citizens.
*/

/* Format:
	CCivicReward detail_num = { "Detail #", "Description" };
*/

namespace FattyMenu {
	namespace Rewards {
		/* Definitions of public service details */
		namespace GeneralPublicServiceDetails {
			CCivicReward t94_322 = { "T94-322", "Cleaning, removing litter and disposing of trash in a specified area" };
			CCivicReward t47_941 = { "T47-941", "Auditing distribution blocks for contraband and other anti-civil activity" };
			CCivicReward t37_584 = { "T37-584", "Monitoring residential blocks for overcrowding, contraband, etc." };
		}

		/* Definitions of civic deeds */
		namespace CivicDeeds {
			CCivicReward d92_493 = { "D92-493", "Turning in moderate articles of contraband (level 2)" };
			CCivicReward d92_595 = { "D92-595", "Turning in severe articles of contraband (level 1)" };
			CCivicReward d18_303 = { "D18-303", "Reporting moderate violation of offenders (anti-civil activity level 1)" };
			CCivicReward d18_332 = { "D18-332", "Reporting major violation offenders (socio-endangerment level 5)" };
			CCivicReward d18_369 = { "D18-369", "Reporting capital violation offenders (socio-endangerment level 1)" };
			CCivicReward d20_102 = { "D20-102", "Non-invasive aiding of a protection unit in a life-threatening situation" };
		}
	}
}