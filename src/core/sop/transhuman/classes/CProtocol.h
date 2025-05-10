#pragma once

#include <vector>

/* This outlines all the necessary attributes for 
* defining deployment protocol descriptions
*/
class CProtocol {
public:
	// Constructors
	CProtocol(const char*, std::vector<const char*>); // For most protocols
	CProtocol(std::vector<const char*>, const char*); // Default label = "Specialized Deployment Restrictions"
	CProtocol();									  // No-arg constructor
	
	// Destructor
	//~CProtocol()									  // Not needed for now
	
	// Setters
	void SetProtocolLabel(const char*);
	void SetProtocolDirectives(std::vector<const char*>);
	void SetSpecializedDeploymentClass(const char*);

	// Getters
	const char* GetProtocolLabel();
	std::vector<const char*> GetProtocolDirectives();
	const char* GetSpecializedDeploymentClass();

private:
	const char* protocol_label;						// String containing name of the protocol
	std::vector<const char*> protocol_directives;	// Container for strings of the protocol's description
	const char* specialized_deployment_class;		// String containing name of the class for specialized deployment
	
};