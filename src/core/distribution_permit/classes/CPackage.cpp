#include "CPackage.h"


// Constructors
CPackage::CPackage(const char* new_name, int new_cost) {
	SetPackageName(new_name);
	SetPackageCost(new_cost);
}

CPackage::CPackage() : CPackage("", 0) { } // No-arg constructor

// Setters
void CPackage::SetPackageName(const char* new_name) {
	this->name = new_name;

}
void CPackage::SetPackageCost(int new_cost) {
	this->cost = new_cost;
}

// Getters
const char* CPackage::GetPackageName() const {
	return name;
}
int CPackage::GetPackageCost() const {
	return cost;
}
