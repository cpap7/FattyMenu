#include "NotepadPanel.h"

namespace FattyMenu {
    static char s_notepad_text_buffer[4096] = {};           // String buffer for notepad
    
    // Fixed button dimensions
    static const float s_button_width{ 200.0f };            // Button X
    // const float button_length{ 100.0f };                 // Button Y

    void CNotepadPanel::OnRender(bool* a_p_open) {
        if (!a_p_open || !*a_p_open) { return; } // Check if it's nullptr or false 

        const char* usage_description = "For quickly taking notes";
        const char* hint_text = "Type notes here...";

        if (ImGui::Begin("Notepad", a_p_open)) {
            DisplayNotepad(usage_description, "##general_use", s_notepad_text_buffer, sizeof(s_notepad_text_buffer), hint_text, "Copy to Clipboard");
        }
        ImGui::End();
    }


    // Helper function for rendering notepads in the ImGui menu
    void CNotepadPanel::DisplayNotepad(const char* a_usage_description, const char* a_label,
        char* a_buffer, size_t a_buffer_size, const char* a_default_text, const char* a_button_text) {

        // Display the purpose of a given notepad
        GUI::Helpers::WrappedBulletText(a_usage_description);


        // Render the notepad
        ImGui::InputTextEx(
            a_label,                                                 // ImGui Label
            a_default_text,                                          // Hint/default text
            a_buffer,                                                // Char array buffer
            static_cast<int>(a_buffer_size),                         // Size of the buffer (NOTE: ImGui takes this as an int here instead of size_t)
            ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 10),       // Notepad dimensions
            ImGuiInputTextFlags_Multiline                            // Input text flags
        );

        if (ImGui::Button(a_button_text, ImVec2(s_button_width, 0))) {
            ImGui::SetClipboardText(a_buffer);
        }
    }

  

}