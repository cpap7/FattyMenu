#include "ImGuiOverlay.h"
#include "Application.h"

#include "../Core/Version.h"

#include "../UI/GUIUtilities.h"



#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9")

// ImGUI headers
#include <../imgui/imgui.h>
#include <../imgui/imgui_impl_win32.h>
#include <../imgui/imgui_impl_dx9.h>

#include <memory>

// ImGui WndProc Handler
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param);

namespace FattyMenu {

	CImGuiOverlay::~CImGuiOverlay() {
		Shutdown();
	}

	void CImGuiOverlay::Init(LPDIRECT3DDEVICE9 a_game_d3d9_device) {
		// Create a D3D device creation parameters object
		auto d3d_params = D3DDEVICE_CREATION_PARAMETERS{ };

		// Populate the object's parameters/attributes
		a_game_d3d9_device->GetCreationParameters(&d3d_params);

		// Temp window is destroyed at this point
		// Thus allowing the menu window to be opened and take priority
		m_game_window_handle = d3d_params.hFocusWindow;	

		// Store original wndproc
		m_original_window_proc = (WNDPROC)(SetWindowLongPtr(		// TODO: Might need to change some type-cast conversions to reinterpret_cast for readability/maintainability later
			m_game_window_handle,
			GWLP_WNDPROC,
			(LONG_PTR)(CApplication::WndProc)
		));

		m_is_initialized = true;									// Menu initialization is complete

		ImGui::CreateContext(); 									// Create the ImGUI context
		ImGuiIO& io = ImGui::GetIO();

		// Set the mouse cursor flag to not change & enable docking flags
		io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;		// Prevents cursor flickering at the crosshair when the menu is open in-game
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui_ImplWin32_Init(m_game_window_handle);					// Pass the game's window to ImGui's initialization method
		ImGui_ImplDX9_Init(a_game_d3d9_device);						// Pass the Direct3D9 device to ImGui's initialization method

		ImGui::StyleColorsDark();									// Set the style of the colors
		GUI::Themes::SetThemeCivilProtection();

		RegisterPanels();
	}

	void CImGuiOverlay::RegisterPanels() {
		// Register panels
		m_cpsop_panel				= std::make_unique<CCPSOPPanel>();
		m_credits_panel				= std::make_unique<CCreditsPanel>();
		m_map_panel					= std::make_unique<CMapPanel>();
		m_notepad_panel				= std::make_unique<CNotepadPanel>();
		m_permit_panel				= std::make_unique<CPermitPanel>();
		//m_tfsop_panel				= std::make_unique<CTFSOPPanel>();
		m_voiceline_library_panel	= std::make_unique<CVoicelineLibraryPanel>();
	}

	void CImGuiOverlay::Shutdown() noexcept {
		if (m_is_initialized) {
			// Shut down ImGui
			ImGui_ImplDX9_Shutdown();							// Shutdown DirectX
			ImGui_ImplWin32_Shutdown();							// Shutdown the Window
			ImGui::DestroyContext();

			m_is_initialized = false;
		}
		if (m_game_window_handle && m_original_window_proc) {
			// Revert any previous change of the game's window proc being superceded by the menu's window proc
			SetWindowLongPtr(
				m_game_window_handle,
				GWLP_WNDPROC,
				(LONG_PTR)(m_original_window_proc)				// TODO: Might need to change type-cast conversion to reinterpret_cast for readability/maintainability later
			);

			m_original_window_proc = nullptr;
		}

		UnregisterPanels();
	}

	void CImGuiOverlay::UnregisterPanels() {
		// LIFO
		m_voiceline_library_panel.reset();
		//m_tfsop_panel.reset();
		m_permit_panel.reset();
		m_notepad_panel.reset();
		m_map_panel.reset();
		m_credits_panel.reset();
		m_cpsop_panel.reset();
	}

	void CImGuiOverlay::OnRender() {
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

		// Render overlays
		RenderMenuBar();
		RenderVersionWindow(&m_panel_state_controller.m_open_version_overlay);

		// Render panels
		m_cpsop_panel->OnRender(&m_panel_state_controller.m_open_cpsop_panel);
		m_credits_panel->OnRender(&m_panel_state_controller.m_open_credits_panel);
		m_map_panel->OnRender(&m_panel_state_controller.m_open_map_panel);
		m_notepad_panel->OnRender(&m_panel_state_controller.m_open_notepad_panel);
		m_permit_panel->OnRender(&m_panel_state_controller.m_open_permit_panel);
		//m_tfsop_panel->OnRender(&m_panel_state_controller.m_open_tfsop_panel);
		m_voiceline_library_panel->OnRender(&m_panel_state_controller.m_open_voiceline_library_panel);

		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}

	void CImGuiOverlay::RenderMenuBar() {
		if (!m_is_open) { return; } // Nothing to do 

		auto& app = CApplication::GetInstance();
		if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("File")) {
				if (ImGui::MenuItem("Unload FattyMenu", " | END KEY")) {
					app.Unload();
				}
				ImGui::MenuItem("Display FattyMenu", " | R-ALT", &m_is_open);

				ImGui::EndMenu(); // File
			}

			if (ImGui::BeginMenu("View")) {
				ImGui::MenuItem("Show Location Readout",			nullptr,			&m_panel_state_controller.m_open_map_panel);
				ImGui::MenuItem("Show Civil Protection SOP",		nullptr,			&m_panel_state_controller.m_open_cpsop_panel);
				ImGui::MenuItem("Show Voiceline Library",			nullptr,			&m_panel_state_controller.m_open_voiceline_library_panel);
				ImGui::MenuItem("Show Distribution Permit Info",	nullptr,			&m_panel_state_controller.m_open_permit_panel);
				ImGui::MenuItem("Show Notepad",						nullptr,			&m_panel_state_controller.m_open_notepad_panel);

				ImGui::EndMenu(); // View
			}

			if (ImGui::BeginMenu("About")) {
				ImGui::MenuItem("Version", nullptr, &m_panel_state_controller.m_open_version_overlay);

				ImGui::Separator();

				ImGui::MenuItem("Credits", nullptr, &m_panel_state_controller.m_open_credits_panel);

				ImGui::EndMenu(); // About
			}

			ImGui::EndMainMenuBar();
		}
	}

	void CImGuiOverlay::RenderVersionWindow(bool* a_p_open) {
		if (!a_p_open || !*a_p_open) { return; } // Check if it's nullptr or false 

		static int location = 0;
		ImGuiIO& io = ImGui::GetIO();
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
		if (location >= 0) {
			const float pad = 10.0f;
			const ImGuiViewport* viewport = ImGui::GetMainViewport();

			ImVec2 work_pos = viewport->WorkPos; // Use work area to avoid menu-bar/task-bar, if any!
			ImVec2 work_size = viewport->WorkSize;
			ImVec2 window_pos, window_pos_pivot;

			window_pos.x = (location & 1) ? (work_pos.x + work_size.x - pad) : (work_pos.x + pad);
			window_pos.y = (location & 2) ? (work_pos.y + work_size.y - pad) : (work_pos.y + pad);

			window_pos_pivot.x = (location & 1) ? 1.0f : 0.0f;
			window_pos_pivot.y = (location & 2) ? 1.0f : 0.0f;

			ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
			ImGui::SetNextWindowViewport(viewport->ID);

			window_flags |= ImGuiWindowFlags_NoMove;
		}
		else if (location == -2) {
			// Center window
			ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
			window_flags |= ImGuiWindowFlags_NoMove;
		}

		ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
		if (ImGui::Begin("##VersionOverlay", a_p_open, window_flags)) {
			ImGui::Text(FM_VERSION_LONG);
			ImGui::Separator();
			ImGui::Text("R-ALT = Open or Close | END KEY = Unload");

			if (ImGui::IsItemHovered()) {
				ImGui::SetTooltip("Press right-click to reposition or hide this overlay");
			}

			if (ImGui::BeginPopupContextWindow()) {
				if (ImGui::MenuItem("Top-left",		nullptr, location == 0))		{ location = 0;			}
				if (ImGui::MenuItem("Top-right",	nullptr, location == 1))		{ location = 1;			}
				if (ImGui::MenuItem("Bottom-left",	nullptr, location == 2))		{ location = 2;			}
				if (ImGui::MenuItem("Bottom-right", nullptr, location == 3))		{ location = 3;			}
				if (a_p_open && ImGui::MenuItem("Hide"))							{ *a_p_open = false;	}
				ImGui::EndPopup();
			}
		}
		ImGui::End();
	}

	void CImGuiOverlay::InvalidateDeviceObjects() {
		ImGui_ImplDX9_InvalidateDeviceObjects();
	}
	
	void CImGuiOverlay::CreateDeviceObjects() {
		ImGui_ImplDX9_CreateDeviceObjects();
	}

	LRESULT CImGuiOverlay::HandleWndProcMessages(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param) {
		if (GetAsyncKeyState(VK_RMENU) & 1) { // '& 1' -> Detect one keystroke
			Toggle();
		}

		// Pass messages to ImGUI
		if (IsOpen()) {
			ImGui_ImplWin32_WndProcHandler(a_window, a_message, a_wide_param, a_long_param);	// Have imgui observe message so its state remains current for each frame
			const ImGuiIO& io = ImGui::GetIO();

			// Handle class of input and override so game never sees it
			switch (a_message) {
				// Handle mouse input
				case WM_MOUSEMOVE:
				case WM_LBUTTONDOWN: case WM_LBUTTONUP: case WM_LBUTTONDBLCLK:
				case WM_RBUTTONDOWN: case WM_RBUTTONUP: case WM_RBUTTONDBLCLK:
				case WM_MBUTTONDOWN: case WM_MBUTTONUP: case WM_MBUTTONDBLCLK:
				case WM_XBUTTONDOWN: case WM_XBUTTONUP:
				case WM_MOUSEWHEEL:  case WM_MOUSEHWHEEL:
					if (io.WantCaptureMouse) {
						return 1L;																// Return 1 long -> it won't call the original game process so long as the menu is open
					}
					break;

				// Handle keyboard input
				case WM_KEYDOWN:	case WM_KEYUP:
				case WM_SYSKEYDOWN: case WM_SYSKEYUP:
				case WM_CHAR:
					if (io.WantCaptureKeyboard) {
						return 1L;
					}
					break;

				default:
					break;
			}
		}

		// Restore input priority back to the game process
		return CallWindowProc(
			m_original_window_proc,
			a_window,
			a_message,
			a_wide_param,
			a_long_param
		);
	}

}