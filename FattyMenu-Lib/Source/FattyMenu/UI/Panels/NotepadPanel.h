#pragma once
#include "../GUIUtilities.h"
#include "../Panel.h"

// ImGui dependencies
#include <../imgui/imgui.h>

namespace FattyMenu {
    class CNotepadPanel : public IPanel {
    public:
        CNotepadPanel()     = default;
        ~CNotepadPanel()    = default;

        virtual void OnRender(bool* a_p_open) override;

    private:
        void DisplayNotepad(const char* a_usage_description, const char* a_label,
            char* a_buffer, size_t a_buffer_size, const char* a_default_text, const char* a_button_text);
    };
}

