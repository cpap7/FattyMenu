#include "PolitiScheduleEvent.h"

/* Politi-schedule event definitions 
* Format:
* CPolitiSchedule event_name_number = { "Start time", "End time", "Mandate Name/Title", "Time length" };
*/
namespace PolitiScheduleEvents {
	CPolitiSchedule curfew = { "00:00", "03:00", "Curfew", "3 hours" };
	CPolitiSchedule workforce_intake_1 = { "04:15", "05:45", "Workforce Intake", "1 hour, 30 minutes" };
	CPolitiSchedule ration_intake_1 = { "06:00", "07:00", "Ration Intake", "1 hour" };
	CPolitiSchedule workforce_intake_2 = { "07:15", "11:45", "Workforce Intake", "4 hours, 30 minutes" };
	CPolitiSchedule ration_intake_2 = { "12:00", "13:00", "Nothing", "1 hour" };
	CPolitiSchedule workforce_intake_3 = { "13:15", "17:45", "Workforce Intake", "4 hours, 30 minutes" };
	CPolitiSchedule ration_intake_3 = { "18:00", "19:00", "Ration Intake", "1 hour" };
	CPolitiSchedule workforce_intake_4 = { "19:15", "23:00", "Workforce Intake", "3 hours, 45 minutes" };
}


/*OLD/DEPRECATED
*
* Time definitions
* CTime's constructor has default values for hours, minutes, and seconds (= 0)
*
* Format:
* CTime _hours_minutes = { int hours, int minutes, int seconds };
* OR
* CTime _hours_minutes = { int hours, int minutes }; -> seconds = 0 by default
* OR
* CTime _hours_minutes = { int hours };				 -> minutes = 0, seconds = 0 by default
*
*/
/*
OLD/DEPRECATED

namespace Times {
	// Curfew procedure times
	CTime _0_00 = { 0, 0 };			// Start
	CTime _4_00 = { 4, 0 };			// End

	// Workforce Intake 1 times
	CTime _4_15 = { 4, 15 };		// Start
	CTime _5_45 = { 5, 45 };		// End

	// Ration Intake 1 times
	CTime _6_00 = { 6, 0 };			// Start
	CTime _7_00 = { 7, 0 };			// End

	// Workforce Intake 2 times
	CTime _7_15 = { 7, 15 };		// Start
	CTime _11_45 = { 11, 45 };		// End

	// Ration Intake 2 times
	CTime _12_00 = { 12, 0 };		// Start
	CTime _13_00 = { 13, 0 };		// End

	// Workforce Intake 3 times
	CTime _13_15 = { 13, 15 };		// Start
	CTime _17_45 = { 17, 45 };		// End

	// Ration Intake 3 times
	CTime _18_00 = { 18, 0 };		// Start
	CTime _19_00 = { 19, 0 };		// End

	// Workforce Intake 4 times
	CTime _19_15 = { 19, 15 };		// Start
	CTime _23_00 = { 23, 0 };		// End
}

*/