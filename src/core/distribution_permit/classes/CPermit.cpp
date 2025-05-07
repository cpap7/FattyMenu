#include "CPermit.h"


// Constructors
CPermit::CPermit(const char* new_name, int new_civic_point_requirement, int new_cost, 
	std::vector<CPackage> new_package_list, std::vector<const char*> new_authorized_items_list) {

	// Call each setter for all the object attributes
	SetPermitName(new_name);
	SetCivicPointRequirement(new_civic_point_requirement);
	SetPermitCost(new_cost);
	SetPackages(new_package_list);
	SetAuthorizedItems(new_authorized_items_list);

}
CPermit::CPermit() : CPermit("", 0, 0, { CPackage() }, { "" }) {  } // No-arg constructor

// Destructor
// CPermit::~CPermit() {  }

// Setters
void CPermit::SetPermitName(const char* new_name) {
	this->name = new_name;
}
void CPermit::SetCivicPointRequirement(int new_civic_point_requirement) {
	this->civic_point_requirement = new_civic_point_requirement;
}
void CPermit::SetPermitCost(int new_cost) { 
	this->cost = new_cost;
}
void CPermit::SetPackages(std::vector<CPackage> new_package_list) { 
	this->package_list = new_package_list;
}
void CPermit::SetAuthorizedItems(std::vector<const char*> new_authorized_items_list) {
	this->authorized_items_list = new_authorized_items_list;
}

// Getters
const char* CPermit::GetPermitName() const { 
	return name;
}
int CPermit::GetCivicPointRequirement() const { 
	return civic_point_requirement;
}
int CPermit::GetPermitCost() const { 
	return cost; 
}
std::vector<CPackage> CPermit::GetPackages() const { 
	return package_list; 
}
std::vector<const char*> CPermit::GetAuthorizedItems() const { 
	return authorized_items_list; 
}