#include "NotePad.h"

// Helper function for initializing the buffer text in each notepad
void Notepad::InitializeBuffer(char* buffer, size_t buffer_size, const char* default_text) {
    // Check if the buffer starts with a null terminating character
    if (buffer[0] == '\0') {
        // This check is done after the initial / first load of the notepad, 
        // It populates the notepad first w/ the default text, and retains additional typed info later 

        // Copy the default text to the buffer
        strcpy_s(buffer, buffer_size, default_text);
    }
}

// Helper function for rendering notepads in the ImGui menu
void Notepad::RenderNotepad(const char* usage_description, const char* label,
                            char* buffer, size_t buffer_size, 
                            const char* default_text, const char* button_text) {
    // Display the purpose of a given notepad
    GUI::Helpers::WrappedBulletText(usage_description);

    // Set up the buffer to display predefined default text
    InitializeBuffer(buffer, buffer_size, default_text);

    // Render the notepad
    ImGui::InputTextMultiline(
        label,                                                 // ImGUI Label
        buffer,                                                // Char array buffer
        buffer_size,                                           // Size of the buffer
        ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 10),     // Notepad dimensions
        ImGuiInputTextFlags_None                               // Input text flags
    );

    // Include a button to copy the text from the notepad
    if (ImGui::Button(button_text, ImVec2(button_width, 0))) {
        // When the button is pressed, set the user's clipboard text to whatever is in the buffer
        ImGui::SetClipboardText(buffer);
    }
}

// Function to initialize parameters for rendering a Patrol Log notepad
void Notepad::RenderPatrolLogNotepad() {
    // Declare a string to hold the usage description
    const char* usage_description = "For use by PTLs";

    // Declare a string to hold the default text
    const char* default_text =
        "**Team Assessment**\n"
        "**Date & Time:**\n"
        "**Team Leader:**\n"
        "**Assignments Performed:**\n"
        "**Personal Notes:**\n\n"
        "**Unit 2:**\n"
        "**Individual Notes:**\n"
        "**Areas of Improvement:**\n"
        "**Commendation:** Yes / No / N/A\n\n"
        "**Unit 3:**\n"
        "**Individual Notes:**\n"
        "**Areas of Improvement:**\n"
        "**Commendation:** Yes / No / N/A\n\n"
        "**Unit 4:**\n"
        "**Individual Notes:**\n"
        "**Areas of Improvement:**\n"
        "**Commendation:** Yes / No / N/A\n";

    // Pass everything to the render method
    RenderNotepad(usage_description, "##patrol_log", patrol_log_buffer, sizeof(patrol_log_buffer), default_text, "Copy Patrol Logs");
}

// Function to initialize parameters for rendering a notepad for probationary recommendations
void Notepad::RenderProbieRecommendationNotepad() {
    // Declare a string to hold the usage description
    const char* usage_description = "For use by PTLs and Solo-Actives with 1 probationary unit attached";

    // Declare a string to hold the default text
    const char* default_text = "**Designation:**\n**SteamID:**\n**Rank Points:**\n**Region:** (Put N/A if unsure, or ask them directly in LOOC)\n**Additional Notes:**\n";

    // Pass everything to the render method
    RenderNotepad(usage_description, "##probie_recommendation", probie_recommendation_buffer, sizeof(probie_recommendation_buffer), default_text, "Copy Recommendation");
}

// Function to initialize parameters for rendering a notepad for taking regular notes
void Notepad::RenderGeneralUseNotepad() {
    // Declare a string to hold the usage description
    const char* usage_description = "For taking regular notes";

    // Declare a string to hold the default text
    const char* default_text = "Type notes here...";
 
    // Pass everything to the render method
    RenderNotepad(usage_description, "##general_use", general_use_buffer, sizeof(general_use_buffer), default_text, "Copy to Clipboard");
}
