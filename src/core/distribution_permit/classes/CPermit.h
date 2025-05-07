#pragma once
#include "CPackage.h"
#include <vector>

class CPermit {
public:	// Function prototypes
	// Constructors
	CPermit(const char*, int, int, std::vector<CPackage>, std::vector<const char*>);
	CPermit(); // No-arg constructor

	// Destructor
	// ~CPermit();

	// Setters
	void SetPermitName(const char*);
	void SetCivicPointRequirement(int);
	void SetPermitCost(int);
	void SetPackages(std::vector<CPackage>);
	void SetAuthorizedItems(std::vector<const char*>);

	// Getters
	const char* GetPermitName() const;
	int GetCivicPointRequirement() const;
	int GetPermitCost() const;
	std::vector<CPackage> GetPackages() const;
	std::vector<const char*> GetAuthorizedItems() const;


private: // Object attributes
	const char* name;								// Name of the permit
	int civic_point_requirement;					// Required # of civic points to purchase the permit
	int cost;										// Required # of credits to purchase the permit
	std::vector<CPackage> package_list;				// List of packages available to the permit
	std::vector<const char*> authorized_items_list;	// List of items authorized by the Combine for the permit holder to sell
};

