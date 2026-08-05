#pragma once

namespace FattyMenu {
	class IPanel {
	public:
		virtual ~IPanel() = default;

	protected: // Optional overrides for 2-step construction (if needed)
		virtual void OnInit() {}
		virtual void OnShutdown() {}

	public:
		virtual void OnRender(bool* a_p_open) = 0;
	};
}

