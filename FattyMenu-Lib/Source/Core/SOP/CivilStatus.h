#pragma once

#include <vector>
#include <string>

namespace FattyMenu {
	class CCivilStatus {
	private:
		std::string m_status_type{};								// Type of civil status (i.e. standard, priority 3, etc.)
		std::string m_status_definition{};							// Definition of what each civil status entails
		std::string m_civic_point_range{};							// String container for civic point range of a given status

		std::vector<std::string> m_administrative_directives{};		// Directives for how to interact w/ each citizen based on their civil status type

	public:
		// Constructors
		CCivilStatus(const std::string& a_status_type, const std::string& a_civic_point_range,
			const std::string& a_status_definition, const std::vector<std::string>& a_administrative_directives);
		CCivilStatus() = default;
		~CCivilStatus() = default;

		// Accessors
		inline void SetStatusType(const std::string& a_status_type)												{ m_status_type					= a_status_type;				}
		inline void SetCivicPointRange(const std::string& a_civic_point_range)									{ m_civic_point_range			= a_civic_point_range;			}
		inline void SetStatusDefinition(const std::string& a_status_definition)									{ m_status_definition			= a_status_definition;			}
		inline void SetAdministrativeDirectives(const std::vector<std::string>& a_administrative_directives)	{ m_administrative_directives	= a_administrative_directives;	}

		inline const std::string& GetStatusType() const															{ return m_status_type;											}
		inline const std::string& GetCivicPointRange() const													{ return m_civic_point_range;									}
		inline const std::string& GetStatusDefinition() const													{ return m_status_definition;									}
		inline const std::vector<std::string>& GetAdministrativeDirectives() const								{ return m_administrative_directives;							}
	};
}