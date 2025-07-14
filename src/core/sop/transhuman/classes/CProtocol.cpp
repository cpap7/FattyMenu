#include "CProtocol.h"

// Constructors
CProtocol::CProtocol(const char* new_protocol_label, std::vector<const char*> new_directives) { // For most protocols
	SetProtocolLabel(new_protocol_label);
	SetProtocolDirectives(new_directives);
	SetSpecializedDeploymentClass("N / A");
} 
/*
CProtocol::CProtocol(std::vector<const char*> new_directives, const char* new_specialized_class) { // Constructor for protocols specific to Specialized Deployment Restrictions
	SetProtocolLabel("Specialized Deployment Restrictions");
	SetProtocolDirectives(new_directives);
	SetSpecializedDeploymentClass(new_specialized_class);
}

*/
CProtocol::CProtocol() : CProtocol("", { "" }) {  } // No-arg constructor

// Destructor
//CProtocol::~CProtocol()		// Not needed for now

// Setters
void CProtocol::SetProtocolLabel(const char* new_protocol_label) {
	this->protocol_label = new_protocol_label;
}
void CProtocol::SetProtocolDirectives(std::vector<const char*> new_directives) {
	this->protocol_directives = new_directives;
}
void CProtocol::SetSpecializedDeploymentClass(const char* new_specialized_deployment_class) {
	this->specialized_deployment_class = new_specialized_deployment_class;
}

// Getters
const char* CProtocol::GetProtocolLabel() {
	return protocol_label;
}
std::vector<const char*> CProtocol::GetProtocolDirectives() {
	return protocol_directives;
}
const char* CProtocol::GetSpecializedDeploymentClass() {
	return specialized_deployment_class;
}
