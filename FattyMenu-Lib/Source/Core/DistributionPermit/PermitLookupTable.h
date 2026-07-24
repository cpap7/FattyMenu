#pragma once
#include "../Serialization/ContentSerializer.h"
#include "Permit.h"

#include <vector>
#include <string>

namespace FattyMenu {
	/* Look-up Table */

	const std::string c_permit_info_file_path = "FattyMenu/FattyMenu_DistributionPermitInfo.json"; // Relative to gmod.exe

	// Returns a mutable list of permits that are loaded from a JSON file
	inline std::vector<CPermit>& GetPermitList() {
		static std::vector<CPermit> permit_list = 
			[] {
				CContentSerializer serializer;
				return serializer.DeserializePermitInfo(c_permit_info_file_path);
			}();

		return permit_list;
	}

	// Reloads in-memory permit info
	inline void RefreshPermitInfo() {
		CContentSerializer serializer;
		GetPermitList() = serializer.DeserializePermitInfo(c_permit_info_file_path);
	}
}