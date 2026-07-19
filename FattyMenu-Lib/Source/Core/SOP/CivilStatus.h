#pragma once
#include <vector>

namespace FattyMenu {
	class CCivilStatus {
	private:
		std::vector<const char*> m_administrative_directives{};				// Directives for how to approach each citizen based on their civil status

		const char* m_status_type		= "";								// Type of civil status (i.e. standard, priority 3, etc.)
		const char* m_status_definition = "";								// Definition of what each civil status entails
		const char* m_civic_point_range = "";								// String container for civic point range of a given status

	public:
		// Constructors
		CCivilStatus(const char* a_status_type, const char* a_civic_point_range, 
			const char* a_status_definition, const std::vector<const char*>& a_administrative_directives);
		CCivilStatus() = default;
		~CCivilStatus() = default;

		// Accessors
		inline void SetStatusType(const char* a_status_type)													{ m_status_type					= a_status_type;				}
		inline void SetCivicPointRange(const char* a_civic_point_range)											{ m_civic_point_range			= a_civic_point_range;			}
		inline void SetStatusDefinition(const char* a_status_definition)										{ m_status_definition			= a_status_definition;			}
		inline void SetAdministrativeDirectives(const std::vector<const char*>& a_administrative_directives)	{ m_administrative_directives	= a_administrative_directives;	}

		inline const char* GetStatusType() const																{ return m_status_type;											}
		inline const char* GetCivicPointRange() const															{ return m_civic_point_range;									}
		inline const char* GetStatusDefinition() const															{ return m_status_definition;									}
		inline const std::vector<const char*>& GetAdministrativeDirectives() const								{ return m_administrative_directives;							}
	};
}