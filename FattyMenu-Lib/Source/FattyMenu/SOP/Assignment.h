#pragma once

#include <vector>
#include <string>

namespace FattyMenu {

	enum class EAssignmentType : uint16_t {
		None				= 0,

		CivilProtection		= 1,	// Assignment pertains to Civil Protection
		TranshumanForces	= 2,	// Assignment pertains to Transhuman Forces
		
		Default				= None
	};

	inline std::string AssignmentTypeToString(EAssignmentType a_assignment_type) {
		switch (a_assignment_type) {
			case EAssignmentType::None:							break;

			case EAssignmentType::CivilProtection:				return "Civil Protection";
			case EAssignmentType::TranshumanForces:				return "Transhuman Forces";

			default:											break;
		}

		return "None";
	}

	inline EAssignmentType AssignmentTypeFromString(const std::string& a_assignment_type_string) {
		if (a_assignment_type_string == "Civil Protection")			{ return EAssignmentType::CivilProtection;	}
		else if (a_assignment_type_string == "Transhuman Forces")	{ return EAssignmentType::TranshumanForces; }
		
		return EAssignmentType::None;
	}


	class CAssignment final {
	private: 
		std::string m_assignment_name{};										// Title of the assignment

		std::string m_cp_units_required{};										// Description of the types of units needed (Civil Protection)
		std::string m_tf_recommended_class{};									// Class that's recommended for a specific assignment (Transhuman only)
		
		std::vector<std::string> m_assignment_description{};					// Vector to hold usually 1-3 strings containing info on how to perform the assignment

		uint16_t m_tf_units_required{ 0 };										// Number of units needed (Transhuman only)
		uint16_t m_tf_shift_duration{ 0 };										// Length of an assignment (Transhuman only)

		EAssignmentType m_assignment_type{ EAssignmentType::Default };

	public:
		// Civil Protection-specific assignment constructor
		CAssignment(const std::string& a_assignment_name, const std::string& a_cp_units_required,
			const std::vector<std::string>& a_assignment_description, EAssignmentType a_type = EAssignmentType::CivilProtection);
		
		// Transhuman Forces-specific assignment constructor
		CAssignment(const std::string& a_assignment_name, uint16_t a_tf_units_required, uint16_t a_tf_shift_duration,
			const std::string& a_tf_recommended_class, const std::vector<std::string>& a_assignment_description, EAssignmentType a_type = EAssignmentType::TranshumanForces);
		
		CAssignment()	= default;
		~CAssignment()	= default; 


		// Accessors
		inline void SetAssignmentName(const std::string& a_assignment_name)								{ m_assignment_name			= a_assignment_name;					}
		inline void SetCPUnitsRequired(const std::string& a_cp_units_required)							{ m_cp_units_required		= a_cp_units_required;					}
		inline void SetTFUnitsRequired(uint16_t a_tf_units_required)									{ m_tf_units_required		= a_tf_units_required;					}
		inline void SetTFShiftDuration(uint16_t a_tf_shift_duration)									{ m_tf_shift_duration		= a_tf_shift_duration;					}
		inline void SetTFRecommendedClass(const std::string& a_tf_recommended_class)					{ m_tf_recommended_class	= a_tf_recommended_class;				}
		inline void SetAssignmentDescription(const std::vector<std::string>& a_assignment_description)	{ m_assignment_description	= a_assignment_description;				}
		inline void SetAssignmentType(EAssignmentType a_assignment_type)								{ m_assignment_type			= a_assignment_type;					}

		inline const std::string& GetAssignmentName() const												{ return m_assignment_name;											}
		inline const std::string& GetCPUnitsRequired() const											{ return m_cp_units_required;										}
		inline uint16_t GetTFUnitsRequired() const														{ return m_tf_units_required;										}
		inline uint16_t GetTFShiftDuration() const														{ return m_tf_shift_duration;										}
		inline const std::string& GetTFRecommendedClass() const											{ return m_tf_recommended_class;									}
		inline const std::vector<std::string>& GetAssignmentDescription() const							{ return m_assignment_description;									}
		inline EAssignmentType GetAssignmentType() const												{ return m_assignment_type;											}

		inline bool IsForCP() const																		{ return m_assignment_type == EAssignmentType::CivilProtection;		}
		inline bool IsForTF() const																		{ return m_assignment_type == EAssignmentType::TranshumanForces;	}
		inline bool HasNoType() const																	{ return m_assignment_type == EAssignmentType::None;				}
	
	};
}