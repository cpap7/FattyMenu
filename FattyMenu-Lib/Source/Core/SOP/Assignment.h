#pragma once
#include <vector>

namespace FattyMenu {

	enum class EAssignmentType {
		None				= 0,
		CivilProtection		= 1,	 // Assignment pertains to Civil Protection
		TranshumanForces	= 2		 // Assignment pertains to Transhuman Forces
	};


	class CAssignment final {
	private: 
		std::vector<const char*> m_assignment_description{};								// Vector to hold usually 1-3 strings containing info on how to perform the assignment
		const char* m_assignment_name			= "";										// Title of the assignment

		const char* m_cp_units_required			= "";										// Description of the types of units needed (Civil Protection)
		
		const char* m_tf_recommended_class		= "";										// Class that's recommended for a specific assignment (Transhuman only)
		int m_tf_units_required					= 0;										// Number of units needed (Transhuman only)
		int m_tf_shift_duration					= 0;										// Length of an assignment (Transhuman only)

		EAssignmentType m_assignment_type		= EAssignmentType::None;

	public:
		// Constructors
		CAssignment(const char* a_assignment_name, const char* a_cp_units_required, 
			const std::vector<const char*>& a_assignment_description, EAssignmentType a_type = EAssignmentType::CivilProtection
		);
		
		CAssignment(const char* a_assignment_name, int a_units_required, int a_duration, 
			const char* a_recommended_class, const std::vector<const char*>& a_assignment_description, EAssignmentType a_type = EAssignmentType::TranshumanForces
		);
		CAssignment(); // No-arg constructor defaults to Civil Protection

		// Destructor
		~CAssignment() = default; 


		// Accessors
		inline void SetAssignmentName(const char* a_assignment_name)									{ m_assignment_name = a_assignment_name;							}
		inline void SetCPUnitsRequired(const char* a_cp_units_required)									{ m_cp_units_required = a_cp_units_required;						}
		inline void SetTFUnitsRequired(int a_tf_units_required)											{ m_tf_units_required = a_tf_units_required;						}
		inline void SetTFShiftDuration(int a_duration)													{ m_tf_shift_duration = a_duration;									}
		inline void SetRecommendedClass(const char* a_recommended_class)								{ m_tf_recommended_class = a_recommended_class;						}
		inline void SetAssignmentDescription(const std::vector<const char*>& a_assignment_description)	{ m_assignment_description = a_assignment_description;				}

		inline const char* GetAssignmentName() const													{ return m_assignment_name;											}
		inline const char* GetCPUnitsRequired() const													{ return m_cp_units_required;										}
		inline int GetTFUnitsRequired() const															{ return m_tf_units_required;										}
		inline int GetTFShiftDuration() const															{ return m_tf_shift_duration;										}
		inline const char* GetTFRecommendedClass() const												{ return m_tf_recommended_class;									}
		inline const std::vector<const char*>& GetAssignmentDescription() const							{ return m_assignment_description;									}
		
		// Useful 


		inline bool IsForCP() const																		{ return m_assignment_type == EAssignmentType::CivilProtection;		}
		inline bool IsForTF() const																		{ return m_assignment_type == EAssignmentType::TranshumanForces;	}
		inline bool HasType() const																		{ return !(m_assignment_type == EAssignmentType::None);				}
	
	};
}