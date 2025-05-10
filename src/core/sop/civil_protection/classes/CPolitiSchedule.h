#pragma once

class CPolitiSchedule {
public:
	// Constructors
	CPolitiSchedule(const char*, const char*, const char*, const char*);
	CPolitiSchedule();

	// Destructor
	//~CPolitiSchedule(); // Not needed, leaving it here just in case it's needed in the future 

	// Setters
	void SetTimeStart(const char*);
	void SetTimeEnd(const char*);
	void SetMandate(const char*);
	void SetTimeLength(const char*);

	// Getters
	const char* GetTimeStart() const;
	const char* GetTimeEnd() const;
	const char* GetMandate() const;
	const char* GetTimeLength() const;

private: // Object attributes
	const char* time_start;			// Start time
	const char* time_end;			// End time
	const char* mandate;			// Mandate title
	const char* time_length;		// Time length (start time - end time)
};

