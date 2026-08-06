#pragma once

#include "../Panel.h"
#include "../GUIUtilities.h"

// Map image file path
#include "../../Serialization/ResourcePaths.h"

// ImGui
#include <../imgui/imgui.h>
#include <../imgui/imgui_internal.h>

#include <memory>

namespace FattyMenu {
	class CMapPanel : public IPanel {
	private:
		std::unique_ptr<CTexture2D> m_map_texture	= nullptr;
		float* m_image_scale						= nullptr; // Non-owning; points into SImageConfig via CImGuiOverlay
	
	public:
		explicit CMapPanel(float* a_image_scale);
		~CMapPanel();

		virtual void OnRender(bool* a_p_open) override;		
	
	private:
		void LoadMapTexture();
		void DisplayMapTexture();
	};
}