#include "CCivicReward.h" // For class declaration

/* Constructor for a CCivicReward object which takes a specified
* number of civic points,  number designation, and descriptions
*
* @param new_points -> an integer representing the number of civic points to be awarded for performing a public service
* @param new_num -> a string containing the designation number of the CCivicReward object
* @param new_description -> a string containing the description of the CCivicReward object
* @param new_ration_reward_description -> a string containing whether or not a ration coupon is administered
*/
CCivicReward::CCivicReward(int new_points, const char* new_num, const char* new_description, const char* new_ration_reward_description) {
	SetCivicPoints(new_points);
	SetNumber(new_num);
	SetDescription(new_description);
	SetRationRewardDescription(new_ration_reward_description);
}

/* No-arg constructor */
CCivicReward::CCivicReward() : CCivicReward(0, "", "", "") { }

// Destructor
//CCivicReward::~CCivicReward() { } // Not needed, leaving it here just in case it's needed in the future 

/* Sets the number of civic points to be awarded for performing a public service
* @param new_points -> integer representing the number of civic points to be awarded
*/
void CCivicReward::SetCivicPoints(int new_points) {
	this->civic_points = new_points;
}

/* Sets the  serial designation for a CCivicReward object 
* @param new_num -> string containing the designation code/number for the  
*/
void CCivicReward::SetNumber(const char* new_num) {
	this->num = new_num;
}

/* Sets the description for a CCivicReward object 
* @param new_description -> string containing the description of the object
*/
void CCivicReward::SetDescription(const char* new_description) {
	this->description = new_description;
}

/* Sets the ration reward description for a CCivicReward object
* for example: "optional" means give civic points OR the coupon
* "mandatory" means give civic points AND the coupon
*/
void CCivicReward::SetRationRewardDescription(const char* new_ration_reward_description) {
	this->ration_reward_description = new_ration_reward_description;
}

/* @return -> an integer representing the number of civic points to be awarded */
int CCivicReward::GetCivicPoints() const {
	return this->civic_points;
}

/* @return -> a string containing the  number of a CCivicReward object */
const char* CCivicReward::GetNumber() const {
	return this->num;
}

/* @return -> a string containing the description of a CCivicReward object */
const char* CCivicReward::GetDescription() const {
	return this->description;
}

/* @return -> a string containing the ration reward of a CPublicServiceDetail object */
const char* CCivicReward::GetRationRewardDescription() const {
	return this->ration_reward_description;
}
