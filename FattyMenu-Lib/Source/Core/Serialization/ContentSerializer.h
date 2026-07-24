#pragma once
#include <string>
#include <vector>

namespace FattyMenu {
	// Forward declarations
	class CVoiceline;
	class CPermit;

	class CContentSerializer {
	public:
		CContentSerializer() = default;
		~CContentSerializer() = default;

		// For debug purposes
		void SerializeVoicelines(const std::vector<CVoiceline>& a_voiceline_list, const std::string& a_file_path);
		void SerializePermitInfo(const std::vector<CPermit>& a_permit_list, const std::string& a_file_path);
		
		std::vector<CVoiceline> DeserializeVoicelines(const std::string& a_file_path);
		std::vector<CPermit> DeserializePermitInfo(const std::string & a_file_path);
	};

	// TODO: temporary for now - just for dumping existing LUTs to JSON files

	inline void DumpToJSON(const std::vector<CVoiceline>& a_voiceline_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializeVoicelines(a_voiceline_list, a_file_path);
	}

	inline void DumpToJSON(const std::vector<CPermit>& a_permit_list, const std::string& a_file_path) {
		CContentSerializer serializer;
		serializer.SerializePermitInfo(a_permit_list, a_file_path);
	}
}

