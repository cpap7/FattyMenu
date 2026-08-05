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
		std::unique_ptr<CTexture2D> m_map_texture = nullptr; // { c_map_image_file_path };
		float m_image_scale{ 0.45f };
	
	public:
		CMapPanel();
		~CMapPanel();

		virtual void OnRender(bool* a_p_open) override;		
	
	private:
		void LoadMapTexture();
		void DisplayMapTexture();
	};
}