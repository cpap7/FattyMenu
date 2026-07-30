#include "GUI.h"

// Main panel content
#include "../Panels/Main/CPSOP.h"
#include "../Panels/Main/TFSOP.h"
#include "../Panels/Main/VoicelineLibrary.h"
#include "../Panels/Main/PermitMenu.h"
#include "../Panels/Main/Notepad.h"

// Map panel content
#include "../Panels/Map/Map.h"

#include "../Panels/GUIUtilities.h" // ImGUI utilities


/* Function Prototypes */
// ImGUI Window Process Handler
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param);

// Window Process
LRESULT CALLBACK HandleWindowProcessMessages(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param);

namespace FattyMenu {

	// Sets up the window class
	bool GUI::InitializeWindowClass(const char* a_window_class_name) noexcept {
		// Populate the window class' attributes
		g_window_class.cbSize			= sizeof(WNDCLASSEX);			
		g_window_class.style			= CS_HREDRAW | CS_VREDRAW;		// Style
		g_window_class.lpfnWndProc		= DefWindowProc;				// Set to be the default window process
		g_window_class.cbClsExtra		= 0;
		g_window_class.cbWndExtra		= 0;
		g_window_class.hInstance		= GetModuleHandle(NULL);		// Instance handle to NULL
		g_window_class.hIcon			= NULL;
		g_window_class.hCursor			= NULL;
		g_window_class.hbrBackground	= NULL;
		g_window_class.lpszMenuName		= NULL;
		g_window_class.lpszClassName	= a_window_class_name;
		g_window_class.hIconSm			= NULL;

		// Ensure the window class is properly registered
		if (!(RegisterClassEx(&g_window_class))) {
			return false;
		}

		// Window class setup successful
		return true;

	}

	// Unregisters the window class
	void GUI::DestroyWindowClass() noexcept {
		// Destruction via WinAPI UnregisterClass method
		UnregisterClass(
			g_window_class.lpszClassName,					// Pass the name of the class
			g_window_class.hInstance						// Pass the instance handle 
		);
	}

	// Sets up the window
	bool GUI::InitializeWindow(const char* a_window_name) noexcept {
		// Generate a temporary window
		g_window = CreateWindow(
			g_window_class.lpszClassName,					// Pass the window class' name
			a_window_name,									// Pass the window's name
			WS_OVERLAPPEDWINDOW,							// Set the style
			0,												// X = 0
			0,												// Y = 0
			100,											// 100 width
			100,											// 100 height
			0,												// No parent
			0,												// No menu
			g_window_class.hInstance,						// Pass the window class' instance handle
			0
		);

		if (!g_window) {
			// Window initialization failed
			return false;
		}

		// Window is initialized
		return true;
	}

	// Unregisters the window
	void GUI::DestroyWindow() {
		// Check if the window is valid
		if (g_window) {
			::DestroyWindow(g_window); // Pass the window over to WinAPI's DestroyWindow method
			g_window = nullptr;
		}
	}

	// Sets up DirectX9
	bool GUI::InitializeDirectX9() noexcept {
		// Get the module handle to the DirectX dll
		const HMODULE d3d9_handle = GetModuleHandle("d3d9.dll");

		if (!d3d9_handle) {
			return false;
		}

		using CreateFn = LPDIRECT3D9(__stdcall*)(UINT);										// Signature of DirectX's create function (CreateFn) 

		// Declare a variable to hold the address of the create function
		const auto create_fn = (CreateFn)(GetProcAddress(d3d9_handle, "Direct3DCreate9"));	// GetProcAddress retrieves exports of dlls		

		// Check if the create variable is initialized properly
		if (!create_fn) {
			return false;
		}

		// Set the d3d9 pointer to the return value of the create function, 
		// passing the d3d sdk version to the create function's arguments
		g_d3d9 = create_fn(D3D_SDK_VERSION);

		// Check if the d3d9 pointer was initialized
		if (!g_d3d9) {
			return false;
		}

		D3DPRESENT_PARAMETERS d3d_params = { };
		// Populate the d3d present parameters attributes
		d3d_params.BackBufferWidth				= 0;
		d3d_params.BackBufferHeight				= 0;
		d3d_params.BackBufferFormat				= D3DFMT_UNKNOWN;
		d3d_params.BackBufferCount				= 0;
		d3d_params.MultiSampleType				= D3DMULTISAMPLE_NONE;
		d3d_params.MultiSampleQuality			= NULL;
		d3d_params.SwapEffect					= D3DSWAPEFFECT_DISCARD;
		d3d_params.hDeviceWindow				= g_window;				// Set the device window so it can retrieve the device from the window being created
		d3d_params.Windowed						= 1;
		d3d_params.EnableAutoDepthStencil		= 0;
		d3d_params.AutoDepthStencilFormat		= D3DFMT_UNKNOWN;
		d3d_params.Flags						= NULL;
		d3d_params.FullScreen_RefreshRateInHz	= 0;
		d3d_params.PresentationInterval			= 0;

		// Check if the d3d9 device is initialized
		if (g_d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_NULLREF,
			g_window, D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT,
			&d3d_params, &g_d3d9_device) < 0) {

			return false; // Initialization failed (< 0)
		}

		// Initialization was successful
		return true;
	}

	void GUI::DestroyDirectX9() noexcept {
		if (g_d3d9_device) {
			g_d3d9_device->Release();
			g_d3d9_device = nullptr;
		}

		if (g_d3d9) {
			g_d3d9->Release();
			g_d3d9 = nullptr;
		}
	}

	bool GUI::InitializeD3DX9() noexcept {
		const HMODULE d3dx9_module_handle = LoadLibraryA("d3dx9_43.dll"); // Load (may not be mapped yet)
		if (!d3dx9_module_handle) {
			return false;	// June 2010 D3D9 redist probably not installed
		}

		// Look up function
		const auto create_texture_fn = (CreateTextureFn)(GetProcAddress(d3dx9_module_handle, "D3DXCreateTextureFromFileA"));

		if (!create_texture_fn) {
			return false;
		}

		g_d3dx9_module_handle = d3dx9_module_handle;		// Cache the handle
		g_create_texture_fn = create_texture_fn;			// Cache function ptr
		return true;										// Setup successful
	}

	void GUI::DestroyD3DX9() noexcept {
		if (g_d3dx9_module_handle) {
			FreeLibrary(g_d3dx9_module_handle);
			g_d3dx9_module_handle = nullptr;
		}

		if (g_create_texture_fn) {	
			g_create_texture_fn = nullptr;
		}
	}

	void GUI::Initialize() {
		// Set up window class, window, D3D9 & D3DX9, and throw an error if the setup has issues

		if (!InitializeWindowClass("FattyMenuWndClass")) {
			throw std::runtime_error("[FattyMenu Error] Window class could not be created.");
		}

		if (!InitializeWindow("FattyMenuWnd")) {
			throw std::runtime_error("[FattyMenu Error] Window could not be created.");
		}

		if (!InitializeDirectX9()) {
			throw std::runtime_error("[FattyMenu Error] D3D9 device could not be created.");
		}

		if (!InitializeD3DX9()) {
			throw std::runtime_error("[FattyMenu Error] d3dx9_43.dll could not be loaded/resolved.");
		}

		// Unregister the Window and Window Class
		DestroyWindow();
		DestroyWindowClass();
	}

	// Initializes ImGUI menu
	void GUI::InitializeMenu(LPDIRECT3DDEVICE9 a_d3d9_device) noexcept {
		// Create a D3D device creation parameters object
		auto d3d_params = D3DDEVICE_CREATION_PARAMETERS{ };

		// Populate the object's parameters/attributes
		a_d3d9_device->GetCreationParameters(&d3d_params);

		// Temp window is destroyed at this point
		// Thus allowing the menu window to be opened and take priority
		g_window = d3d_params.hFocusWindow;						// Set the menu window to the game window

		// Store the original window process
		g_original_window_proc = (WNDPROC)(SetWindowLongPtr(	// TODO: Might need to change some type-cast conversions to reinterpret_cast for readability/maintainability later
			g_window,
			GWLP_WNDPROC,
			(LONG_PTR)(HandleWindowProcessMessages)
		));

		ImGui::CreateContext(); 								// Create the ImGUI context
		ImGui::StyleColorsDark();								// Set the style of the colors
		
		GUI::Themes::SetThemeCivilProtection();

		ImGui_ImplWin32_Init(g_window);							// Pass the game's window to ImGui's initialization method
		ImGui_ImplDX9_Init(a_d3d9_device);						// Pass the DirectX3D9 device to ImGui's initialization method

		ImGuiIO& io = ImGui::GetIO();
		// Set the mouse cursor flag to not change
		io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange; // Prevents cursor flickering at the crosshair when the menu is open in-game

		g_initialized = true;									// Menu initialization is complete
	}

	// Unregisters everything
	void GUI::Destroy() noexcept {
		if (g_initialized) {
			// Shut down ImGui
			ImGui_ImplDX9_Shutdown();							// Shutdown DirectX
			ImGui_ImplWin32_Shutdown();							// Shutdown the Window
			ImGui::DestroyContext();

			g_initialized = false;
		}

		if (g_window && g_original_window_proc) {
			// Revert any previous change of the game's window process being superceded by the menu's window process
			SetWindowLongPtr(
				g_window,
				GWLP_WNDPROC,
				(LONG_PTR)(g_original_window_proc)				// TODO: Might need to change type-cast conversion to reinterpret_cast for readability/maintainability later
			);

			g_original_window_proc = nullptr;
		}

		
		DestroyDirectX9();										// Unregister DirectX
		DestroyD3DX9();											// Shutdown D3DX9
	}

	void GUI::Render() noexcept {
		// Set up ImGui frame
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		
		//ImGui::ShowDemoWindow();

		// ImGui panels begin

		const std::string main_panel_header{ "FattyMenu v1.7.2 | Main Panel | RALT = Open or Close | END = Uninject Menu" };
		const std::string map_panel_header{ "FattyMenu v1.7.2 | Map Panel | RALT = Open or Close | END = Uninject Menu" };

		if (ImGui::Begin(map_panel_header.c_str(), &g_open_panels)) {
			Map::RenderMap();

			ImGui::End();
		}

		if (ImGui::Begin(main_panel_header.c_str(), &g_open_panels)) {
			// ImGui tab bar begins
			if (ImGui::BeginTabBar("Menu Tabs")) {
				// Render Civil Protection operating procedures tab
				if (ImGui::BeginTabItem("Civil Protection SOP")) {
					CPSOP::RenderCivilProtectionSOP();
					ImGui::EndTabItem();
				}

				/* Render Transhuman Forces operating procedures tab
				if (ImGui::BeginTabItem("Transhuman Forces SOP")) {
					TFSOP::RenderTranshumanForcesSOP();
					ImGui::EndTabItem();
				} */

				// Render voiceline library tab
				if (ImGui::BeginTabItem("Voiceline Library")) {
					VoicelineLibrary::RenderVoicelineLibraryMenu();
					ImGui::EndTabItem();
				}

				// Render distribution permit info tab
				if (ImGui::BeginTabItem("Distribution Permit Info")) {
					PermitMenu::RenderPermitMenu();
					ImGui::EndTabItem();
				}

				// Render tab for notepads
				if (ImGui::BeginTabItem("Notepad")) {
					// Render general-use notepad
					Notepad::RenderGeneralUseNotepad();

					ImGui::EndTabItem();
				}


				if (ImGui::BeginTabItem("Credits")) {
					ImGui::TextWrapped("Internal menu created by: JoeRogaine on Discord aka cpap7 on Github\n");

					ImGui::Separator();

					ImGui::TextWrapped("Special thanks to the following people for their help:");
					ImGui::TextWrapped("-> MajoraPLZ for helping me find the right people to ask for info, and answering any questions I had");
					ImGui::TextWrapped("-> Cazzette for providing feedback, and also helping me find people to ask for info");
					ImGui::TextWrapped("-> voprositelnii for providing TAC usage etiquette and duty expectations");

					ImGui::Separator();

					ImGui::TextWrapped("SOP files");
					ImGui::TextWrapped("-> Rommel & Cazzette for sending me the SOP pdfs");

					ImGui::Separator();

					ImGui::TextWrapped("Voiceline Data");
					ImGui::TextWrapped("-> -Broken-");
					ImGui::TextWrapped("-> Recker");

					ImGui::Separator();

					ImGui::TextWrapped("Frontend Programming Assistance");
					ImGui::TextWrapped("-> @fblawyer on Discord");

					ImGui::Separator();

					ImGui::EndTabItem();
				}

				// End tab bar
				ImGui::EndTabBar();
			}

			// End ImGui window
			ImGui::End();
		}
		

		// End frame and render ImGui data
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}
	
}

/* Controls window/input priority between the menu window and game process */
LRESULT CALLBACK HandleWindowProcessMessages(HWND a_window, UINT a_message, WPARAM a_wide_param, LPARAM a_long_param) {
	// Check if the main panel is toggled on or off (RALT)
	if (GetAsyncKeyState(VK_RMENU) & 1) {													// '& 1' -> Detect one keystroke
		FattyMenu::GUI::g_open_panels = !FattyMenu::GUI::g_open_panels;						// If true, set to false & vice versa
																							// e.g.: menu is opened -> you press the key -> it will close & vice versa
	}

	// Pass messages to ImGUI
	if (FattyMenu::GUI::g_open_panels) {
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
		FattyMenu::GUI::g_original_window_proc,
		a_window,
		a_message,
		a_wide_param,
		a_long_param
	);
}