#pragma once

#include <vector>

namespace FattyMenu {

	/* This outlines all the necessary attributes for
	* defining deployment protocol descriptions
	* NOTE: This is only relevant for Transhuman Forces
	*/
	class CProtocol {
	private:
		std::vector<const char*> m_protocol_directives{};				// Container for strings of the protocol's description
		const char* m_protocol_label					= "";			// String containing name of the protocol
		const char* m_specialized_deployment_class		= "";			// String containing name of the class for specialized deployment

	public:
		// Constructors
		CProtocol(const char* a_protocol_label, std::vector<const char*> a_protocol_directives);	// For most protocols
		//CProtocol(std::vector<const char*>, const char*);											// Default label = "Specialized Deployment Restrictions"
		CProtocol();																				// No-arg constructor

		// Destructor
		~CProtocol() = default;

		// Accessors
		inline void SetProtocolLabel(const char* a_protocol_label)								{ m_protocol_label					= a_protocol_label;					}
		inline void SetProtocolDirectives(std::vector<const char*> a_protocol_directives)		{ m_protocol_directives				= a_protocol_directives;			}
		inline void SetSpecializedDeploymentClass(const char* a_specialized_deployment_class)	{ m_specialized_deployment_class	= a_specialized_deployment_class;	}

		inline const char* GetProtocolLabel()													{ return m_protocol_label;												}
		inline std::vector<const char*> GetProtocolDirectives()									{ return m_protocol_directives;											}
		inline const char* GetSpecializedDeploymentClass()										{ return m_specialized_deployment_class;								}

	};


}