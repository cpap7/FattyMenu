#pragma once


namespace FattyMenu {
	class CCivicReward {
	private:
		const char* m_number						= "";
		const char* m_description					= "";
		const char* m_ration_reward_description		= "";
		int m_civic_points							= 0;

	public:
		// Constructors
		CCivicReward(int a_civic_points, const char* a_number, const char* a_description, const char* a_ration_reward_description);
		CCivicReward() = default;

		// Destructor
		~CCivicReward() = default;

		// Setters
		inline void SetCivicPoints(int a_civic_points)									{ m_civic_points				= a_civic_points;				}
		inline void SetNumber(const char* a_number)										{ m_number						= a_number;						}
		inline void SetDescription(const char* a_description)							{ m_description					= a_description;				}
		inline void SetRationRewardDescription(const char* a_ration_reward_description)	{ m_ration_reward_description	= a_ration_reward_description;	}

		// Getters
		inline int GetCivicPoints() const												{ return m_civic_points;										}
		inline const char* GetNumber() const											{ return m_number;												}
		inline const char* GetDescription() const										{ return m_description;											}
		inline const char* GetRationRewardDescription() const							{ return m_ration_reward_description;							}
	};

}