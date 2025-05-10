#pragma once
#include <vector>

class CCivilStatus {
public:
	// Constructors
	CCivilStatus(const char*, const char*, const char*, std::vector<const char*>);
	CCivilStatus();	// No-arg constructor

	// Destructor
	// ~CCivilStatus(); // Not needed, leaving it here just in case it's needed in the future 

	// Setters
	void SetStatusType(const char*);
	void SetCivicPointRange(const char*);
	void SetStatusDefinition(const char*);
	void SetInteractionDirectives(std::vector<const char*>);
	

	// Getters
	const char* GetStatusType() const;
	const char* GetCivicPointRange() const;
	const char* GetStatusDefinition() const;
	std::vector<const char*> GetInteractionDirectives() const;
	

private:
	const char* status_type;									// Type of civil status (i.e. standard, priority 3, etc.)
	const char* status_definition;								// Definition of what each civil status entails
	std::vector<const char*> interaction_directives;			// Directives for how to approach each citizen based on their civil status
	const char* civic_point_range;								// String container for civic point range of a given status
};