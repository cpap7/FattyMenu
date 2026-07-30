#include "Protocol.h"

namespace FattyMenu {
	// Constructors
	CProtocol::CProtocol(const char* a_protocol_label, std::vector<const char*> a_protocol_directives)
		: m_protocol_label(a_protocol_label), m_protocol_directives(a_protocol_directives), m_specialized_deployment_class("N / A") { // For most protocols
	}

	/*
	CProtocol::CProtocol(std::vector<const char*> new_directives, const char* new_specialized_class) { // Constructor for protocols specific to Specialized Deployment Restrictions
		
	}
	*/

	CProtocol::CProtocol() 
		: CProtocol("", { "" }) {} // No-arg constructor

}




