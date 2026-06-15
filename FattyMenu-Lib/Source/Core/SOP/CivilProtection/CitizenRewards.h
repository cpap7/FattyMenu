#pragma once

#include "../CivicReward.h" // Class definition for CCivicReward

/* This header contains declarations of 
* different public service details and civic deeds
* that would allow Civil Protection units to award
* civic points and/or ration coupons to Citizens. 
*/

namespace FattyMenu {

	namespace Rewards {
		/* Declarations of public service details */
		namespace GeneralPublicServiceDetails {
			extern CCivicReward t94_322;
			extern CCivicReward t47_941;
			extern CCivicReward t37_584;
		}

		/* Declarations of civic deeds */
		namespace CivicDeeds {
			extern CCivicReward d92_493;
			extern CCivicReward d92_595;
			extern CCivicReward d18_303;
			extern CCivicReward d18_332;
			extern CCivicReward d18_369;
			extern CCivicReward d20_102;
		}
	}
}
