#include "PolitiSchedule.h"

namespace FattyMenu {
	
	CPolitiSchedule::CPolitiSchedule(const char* a_time_start, const char* a_time_end, const char* a_mandate, const char* a_time_length) 
		: m_time_start(a_time_start), m_time_end(a_time_end), m_mandate(a_mandate), m_time_length(a_time_length) {
		
	}

	CPolitiSchedule::CPolitiSchedule() 
		: CPolitiSchedule("", "", "", "") {
	
	}
}
