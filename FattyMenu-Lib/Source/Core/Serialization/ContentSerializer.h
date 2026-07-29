#pragma once
#include <string>
#include <vector>

namespace FattyMenu {
	// Forward declarations
	class CVoiceline;
	class CPermit;

	class CCode;
	class CViolationCodeCategory; // Metadata
	class CTerm;
	class CCivicReward;
	class CCivilStatus;
	class CContraband;
	class CAssignment;


	class CContentSerializer {
	public:
		CContentSerializer() = default;
		~CContentSerializer() = default;

		std::vector<CVoiceline> DeserializeVoicelines(const std::string& a_file_path);
		std::vector<CPermit> DeserializePermitInfo(const std::string& a_file_path);

		std::vector<CCode> DeserializeCodes(const std::string& a_file_path);
		std::vector<CViolationCodeCategory> DeserializeViolationCodeCategories(const std::string& a_file_path);
		std::vector<CTerm> DeserializeTerms(const std::string& a_file_path);
		std::vector<CCivicReward> DeserializeCivicRewardInfo(const std::string& a_file_path);
		std::vector<CCivilStatus> DeserializeCivilStatusInfo(const std::string& a_file_path);
		std::vector<CContraband> DeserializeContrabandInfo(const std::string& a_file_path);
		std::vector<CAssignment> DeserializeAssignmentInfo(const std::string& a_file_path);


#ifdef FM_DEBUG
		// For debug purposes - namely, dumping existing or hardcoded LUTs in memory
		void SerializeVoicelines(const std::vector<CVoiceline>& a_voiceline_list, const std::string& a_file_path);
		void SerializePermitInfo(const std::vector<CPermit>& a_permit_list, const std::string& a_file_path);
		
		void SerializeCodes(const std::vector<CCode>& a_codes_list, const std::string& a_file_path);
		void SerializeViolationCategories(const std::vector<CViolationCodeCategory>& a_categories_list, const std::string& a_file_path);
		void SerializeTerms(const std::vector<CTerm>& a_terms_list, const std::string& a_file_path);
		void SerializeCivicRewardInfo(const std::vector<CCivicReward>& a_civic_rewards_list, const std::string& a_file_path);
		void SerializeCivilStatusInfo(const std::vector<CCivilStatus>& a_civil_status_list, const std::string& a_file_path);
		void SerializeContrabandInfo(const std::vector<CContraband>& a_contraband_list, const std::string& a_file_path);
		void SerializeAssignmentInfo(const std::vector<CAssignment>& a_assignments_list, const std::string& a_file_path);
#endif

	};

#ifdef FM_DEBUG
	// NOTE: These functions are for debugging purposes
	// They are just for dumping existing or hardcoded LUTs to JSON files

	inline void DumpToJSON(const std::vector<CVoiceline>& a_voiceline_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeVoicelines(a_voiceline_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CPermit>& a_permit_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializePermitInfo(a_permit_list, a_file_path);
	}

	// SOP

	inline void DumpToJSON(const std::vector<CCode>& a_code_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeCodes(a_code_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CViolationCodeCategory>& a_categories_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeViolationCategories(a_categories_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CTerm>& a_terms_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeTerms(a_terms_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CCivicReward>& a_civic_rewards_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeCivicRewardInfo(a_civic_rewards_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CCivilStatus>& a_civil_status_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeCivilStatusInfo(a_civil_status_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CContraband>& a_contraband_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeContrabandInfo(a_contraband_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CAssignment>& a_assignment_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeAssignmentInfo(a_assignment_list, a_file_path);
	}
#endif

}

