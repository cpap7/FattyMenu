#include "Notepad.h"

namespace FattyMenu {
 
    // Helper function for rendering notepads in the ImGui menu
    void Notepad::DisplayNotepad(const char* a_usage_description, const char* a_label, 
        char* a_buffer, size_t a_buffer_size, const char* a_default_text, const char* a_button_text) {

        // Display the purpose of a given notepad
        GUI::Helpers::WrappedBulletText(a_usage_description);


        // Render the notepad
        ImGui::InputTextEx(
            a_label,                                                 // ImGUI Label
            a_default_text,
            a_buffer,                                                // Char array buffer
            a_buffer_size,                                           // Size of the buffer
            ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 10),       // Notepad dimensions
            ImGuiInputTextFlags_Multiline                            // Input text flags
        );

        if (ImGui::Button(a_button_text, ImVec2(button_width, 0))) {
            ImGui::SetClipboardText(a_buffer);
        }
    }


    // Function to initialize parameters for rendering a notepad for taking regular notes
    void Notepad::RenderGeneralUseNotepad() {
        const char* usage_description = "For taking regular notes";

        const char* default_text = "Type notes here...";

        // Pass everything to the render method
        DisplayNotepad(usage_description, "##general_use", general_use_buffer, sizeof(general_use_buffer), default_text, "Copy to Clipboard");
    }

}