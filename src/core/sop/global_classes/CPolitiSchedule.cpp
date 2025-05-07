#include "CPolitiSchedule.h"

/* Originally incorporated a separate class I made called "CTime" for defining time values,
* however due to instability issues w/ ImGui and operator overloading functions (i.e., subtraction, output stream), 
* I've opted for boring-ass const char* strings to hold and display time values instead. Oh well!
*/


/* Constructor with a specified time start, time end, mandate, and time length
* @param new_time_start -> string containing the time that the scheduled event starts
* @param new_time_end -> string containing the time that the scheduled event ends
* @param new_mandate ->  string containing name of the mandate/duty detail performed by Civil Protection units during the scheduled event
* @param new_time_length -> string containing the difference between new_time_start and new_time_end (new_time_end - new_time_start, basically)
*/
CPolitiSchedule::CPolitiSchedule(const char* new_time_start, const char* new_time_end, const char* new_mandate, const char* new_time_length) {
	// Set the start and end times
	SetTimeStart(new_time_start);
	SetTimeEnd(new_time_end);

	// Set the mandate title
	SetMandate(new_mandate);
	
	// Set the time length
	SetTimeLength(new_time_length);	
}

/* No-arg delegate constructor */
CPolitiSchedule::CPolitiSchedule() : CPolitiSchedule("", "", "", "") { }

/* Destructor */
//CPolitiSchedule::~CPolitiSchedule() { } // Not needed, leaving it here just in case it's needed in the future 

/* Sets a new time start string for a scheduled event 
* @param new_time_start -> a string containing the time when the event starts
*/
void CPolitiSchedule::SetTimeStart(const char* new_time_start) {
	this->time_start = new_time_start;
}

/* Sets a new time end string 
* @param new_time_end -> a string containing the time when the event ends
*/
void CPolitiSchedule::SetTimeEnd(const char* new_time_end) {
	this->time_end = new_time_end;
}

/* Sets a new mandate string
* @param new_mandate -> string containing the mandate title/name 
*/
void CPolitiSchedule::SetMandate(const char* new_mandate) {
	this->mandate = new_mandate;
}

/* Sets a new time length string
* @param new_time_length -> string containing the difference (or length) between the start and end times
*/
void CPolitiSchedule::SetTimeLength(const char* new_time_length) {
	this->time_length = new_time_length;
}

/* @return -> a string containing the start time for a scheduled event */
const char* CPolitiSchedule::GetTimeStart() const {
	return this->time_start;
}

/* @return -> a string containing the end time for a scheduled event */
const char* CPolitiSchedule::GetTimeEnd() const {
	return this->time_end;
}
/* @return -> a string containing the mandate duty performed by Civil Protection for a scheduled event */
const char* CPolitiSchedule::GetMandate() const {
	return this->mandate;
}

/* @return -> a string containing the length of time for a given scheduled event */
const char* CPolitiSchedule::GetTimeLength() const {
	return this->time_length;
}