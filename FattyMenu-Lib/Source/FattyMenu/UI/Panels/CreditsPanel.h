#pragma once
#include "../Panel.h"
#include "../GUIUtilities.h"

namespace FattyMenu {
	class CCreditsPanel : public IPanel {
	public:
		CCreditsPanel()		= default;
		~CCreditsPanel()	= default;

		virtual void OnRender(bool* a_p_open) override;
	
	private:
		void DisplayCredits();
	};
}