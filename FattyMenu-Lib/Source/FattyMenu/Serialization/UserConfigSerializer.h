#pragma once
#include "UserConfig.h"
#include "ResourcePaths.h"

namespace FattyMenu {
	class CUserConfigSerializer {
	public:
		static bool SaveUserConfig(const SUserConfig& a_config, const std::string& a_file_path = c_user_config_file_path);
		static bool LoadUserConfig(SUserConfig& a_config,		const std::string& a_file_path = c_user_config_file_path);
	};
}

