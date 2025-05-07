#pragma once

// ImGui dependencies
#include "../../../../ext_dependencies/imgui/imgui.h"

// GUI utilities
#include "../../../GUIUtilities.h"

// Methods declared here are later defined in Notepad.cpp
// Then, they're called in GUI.cpp as a separate tab

namespace Notepad {
    // Declare a char array buffer for each notepad
    static char patrol_log_buffer[4096] = "";	         // Buffer for notepad to hold strings related to patrol logs
    static char probie_recommendation_buffer[2048] = ""; // Buffer for notepad to hold strings related to probationary recommendations
    static char general_use_buffer[4096] = "";           // Buffer for general purpose notepad

    // Declare fixed dimensions for the button
    const float button_width = 200.0f;                   // Button X
    // const float button_length = 100.0f;               // Button Y

    // Helper function for initializing the buffer text in each notepad
    void InitializeBuffer(char*, size_t, const char*);

    // Helper function for rendering notepads in the menu
    void RenderNotepad(const char*, const char*, char*, size_t, const char*, const char*);

    // Function to initialize parameters for rendering a notepad for Patrol Logs
    void RenderPatrolLogNotepad();

    // Function to initialize parameters for rendering a notepad for probationary recommendations
    void RenderProbieRecommendationNotepad();

    // Function to initialize parameters for rendering a notepad for taking regular notes
    void RenderGeneralUseNotepad();
    
}

