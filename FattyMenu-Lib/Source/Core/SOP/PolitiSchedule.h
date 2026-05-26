#pragma once

namespace FattyMenu {

	class CPolitiSchedule {
	private: // Object attributes
		const char* m_time_start	= "";			// Start time
		const char* m_time_end		= "";			// End time
		const char* m_mandate		= "";			// Mandate title
		const char* m_time_length	= "";			// Time length (start time - end time)

	public:
		// Constructors
		CPolitiSchedule(const char* a_time_start, const char* a_time_end, const char* a_mandate, const char* a_time_length);
		CPolitiSchedule();

		// Destructor
		~CPolitiSchedule() = default;

		// Accessors
		inline void SetTimeStart(const char* a_time_start)		{ m_time_start		= a_time_start;		}
		inline void SetTimeEnd(const char* a_time_end)			{ m_time_end		= a_time_end;		}
		inline void SetMandate(const char* a_mandate)			{ m_mandate			= a_mandate;		}
		inline void SetTimeLength(const char* a_time_length)	{ m_time_length		= a_time_length;	}
		
		inline const char* GetTimeStart() const					{ return m_time_start;					}
		inline const char* GetTimeEnd() const					{ return m_time_end;					}
		inline const char* GetMandate() const					{ return m_mandate;						}
		inline const char* GetTimeLength() const				{ return m_time_length;					}

	
	};

}
