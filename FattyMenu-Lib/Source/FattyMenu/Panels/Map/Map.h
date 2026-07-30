#pragma once

#include "../GUIUtilities.h"

// Map image file path
#include "../../Serialization/ResourcePaths.h"

// ImGui
#include <../imgui/imgui.h>
#include <../imgui/imgui_internal.h>

namespace FattyMenu {
	namespace Map {

		void LoadAndDisplayMapTexture();								// Loads & displays the map texture from disk
		void RenderMap();												// Main render function
	}
}