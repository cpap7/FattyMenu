#include "CivicReward.h" // For class declaration

namespace FattyMenu {
	CCivicReward::CCivicReward(int a_civic_points, const char* a_number, const char* a_description, const char* a_ration_reward_description) 
		: m_civic_points(a_civic_points), m_number(a_number), m_description(a_description), m_ration_reward_description(a_ration_reward_description) {
		
	}
}