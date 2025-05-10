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
