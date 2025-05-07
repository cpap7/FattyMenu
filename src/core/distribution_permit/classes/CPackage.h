#pragma once

class CPackage {
public: // Function prototypes
	// Constructors
	CPackage(const char*, int);
	CPackage(); // No-arg constructor
	
	// Destructor
	// ~CPackage();

	// Setters
	void SetPackageName(const char* new_name);
	void SetPackageCost(int new_cost);

	// Getters
	const char* GetPackageName() const;
	int GetPackageCost() const;


private: // Object attributes
	const char* name;
	int cost;
};