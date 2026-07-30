#pragma once

// ImGui dependencies
#include <../imgui/imgui.h>

// GUI utilities
#include "../GUIUtilities.h"


namespace FattyMenu {
    namespace Notepad {
        static char general_use_buffer[4096] = {};           // Buffer for general purpose notepad

        // Fixed button dimensions
        const float button_width{ 200.0f };                   // Button X
        // const float button_length{ 100.0f };               // Button Y

        // Helper function for rendering notepads in the menu
        void DisplayNotepad(const char* a_usage_description, const char* a_label, 
            char* a_buffer, size_t a_buffer_size, const char* a_default_text, const char* a_button_text);

        // Function to initialize parameters for rendering a notepad for taking regular notes
        void RenderGeneralUseNotepad();

    }
}

