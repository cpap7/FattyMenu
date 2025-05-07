#pragma once


class CCivicReward {
public:
	// Constructors
	CCivicReward(int, const char*, const char*, const char*);
	CCivicReward();

	// Destructor
	//~CCivicReward(); // Not needed, leaving it here just in case it's needed in the future 

	// Setters
	void SetCivicPoints(int);
	void SetNumber(const char*);
	void SetDescription(const char*);
	void SetRationRewardDescription(const char*);

	// Getters
	int GetCivicPoints() const;
	const char* GetNumber() const;
	const char* GetDescription() const;
	const char* GetRationRewardDescription() const;

private:
	int civic_points;
	const char* num;
	const char* description;
	const char* ration_reward_description;
};