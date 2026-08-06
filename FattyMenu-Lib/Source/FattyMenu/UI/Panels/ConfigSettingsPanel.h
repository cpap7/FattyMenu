#pragma once
// GUI utils
#include "../GUIUtilities.h"
#include "../Panel.h"

#include "../../Serialization/UserConfig.h"

namespace FattyMenu {
	class CConfigSettingsPanel : public IPanel {
	private:
		SUserConfig& m_user_config; // Non-owning reference. This would be owned by CImGuiOverlay
	
	public:
		explicit CConfigSettingsPanel(SUserConfig& a_user_config);
		~CConfigSettingsPanel()	= default;
		
		virtual void OnRender(bool* a_p_open) override;
	
	private:

	};
}

