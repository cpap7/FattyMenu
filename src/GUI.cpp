#include "GUI.h"

// ImGui menu tabs
#include "core/sop/civil_protection/gui/PocketSOP.h"
#include "core/voicelines/gui/VoicelineLibrary.h"
#include "core/distribution_permit/gui/PermitMenu.h"
#include "core/notepads/gui/Notepad.h"

/* Additional Function Prototypes */
// ImGUI Window Process Handler
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND window, UINT message, WPARAM wide_param, LPARAM long_param);

// Window Process
LRESULT CALLBACK WindowProcess(HWND window, UINT message, WPARAM wide_param, LPARAM long_param);



// Sets up the window class
bool GUI::InitializeWindowClass(const char* window_class_name) noexcept {
	// Populate the window class' attributes
	window_class.cbSize = sizeof(WNDCLASSEX);			// Set the size
	window_class.style = CS_HREDRAW | CS_VREDRAW;		// Set the style
	window_class.lpfnWndProc = DefWindowProc;			// Set the window to be the default window process
	window_class.cbClsExtra = 0;						 
	window_class.cbWndExtra = 0;						
	window_class.hInstance = GetModuleHandle(NULL);		// Set the instance handle to NULL
	window_class.hIcon = NULL;							
	window_class.hCursor = NULL;						 
	window_class.hbrBackground = NULL;					
	window_class.lpszMenuName = NULL;					
	window_class.lpszClassName = window_class_name;		
	window_class.hIconSm = NULL;

	// Ensure the window class is properly registered
	if (!(RegisterClassEx(&window_class))) {
		// Return false if it isn't
		return false;
	}
	
	// Window class is properly registered otherwise
	return true;

}

// Unregisters the window class
void GUI::DestroyWindowClass() noexcept {
	// Call the WinAPI UnregisterClass method
	UnregisterClass(
		window_class.lpszClassName,						// Pass the name of the class
		window_class.hInstance							// Pass the instance handle 
	);
}

// Sets up the window
bool GUI::InitializeWindow(const char* window_name) noexcept {
	// Generate a temporary window
	window = CreateWindow(
		window_class.lpszClassName,						// Pass the window class' name
		window_name,									// Pass the window's name
		WS_OVERLAPPEDWINDOW,							// Set the style
		0,												// X = 0
		0,												// Y = 0
		100,											// 100 width
		100,											// 100 height
		0,												// No parent
		0,												// No menu
		window_class.hInstance,							// Pass the window class' instance handle
		0
	);

	// Ensure the window is properly initialized
	if (!window) {	// Check if the window class is still null

		// Window initialization failed
		return false;
	}

	// Window is initialized
	return true;
}

// Unregisters the window
void GUI::DestroyWindow() {
	// Check if the window is valid
	if (window) {
		// Pass the window over to WinAPI's DestroyWindow method
		DestroyWindow(window);
	}
}

// Sets up DirectX9
bool GUI::InitializeDirectX9() noexcept {
	// Get the module handle to the DirectX dll
	const HMODULE handle = GetModuleHandle("d3d9.dll"); // TODO: test w/ auto if it doesn't work

	// Check if the handle is null
	if (!handle) {
		// Return false if it's null
		return false;
	}

	// Define the signature of DirectX's create function (CreateFn) 
	using CreateFn = LPDIRECT3D9(__stdcall*)(UINT);

	// Declare a variable to hold the address of the function
	const auto create = (CreateFn)(GetProcAddress( // GetProcAddress -> Retrieves exports of dlls
		handle,
		"Direct3DCreate9"
	));

	// Check if the create variable is initialized properly
	if (!create) {
		return false; 	// Initialization failed
	}

	// Set the d3d9 pointer to the return value of the create function, 
	// passing the d3d sdk version to the create function's arguments
	d3d9 = create(D3D_SDK_VERSION);

	// Check if the d3d9 pointer was initialized
	if (!d3d9) {
		return false;	// Initialization failed
	}

	// Declare a Direct3D present parameters object
	D3DPRESENT_PARAMETERS d3d_params = { };
	
	// Populate the object's attributes
	d3d_params.BackBufferWidth = 0;
	d3d_params.BackBufferHeight = 0;
	d3d_params.BackBufferFormat = D3DFMT_UNKNOWN;
	d3d_params.BackBufferCount = 0;
	d3d_params.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3d_params.MultiSampleQuality = NULL;
	d3d_params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3d_params.hDeviceWindow = window;				// Set the device window so it can retrieve the device from the window being created
	d3d_params.Windowed = 1;
	d3d_params.EnableAutoDepthStencil = 0;
	d3d_params.AutoDepthStencilFormat = D3DFMT_UNKNOWN;
	d3d_params.Flags = NULL;
	d3d_params.FullScreen_RefreshRateInHz = 0;
	d3d_params.PresentationInterval = 0;

	// Check if the d3d9 device is initialized
	if (d3d9->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_NULLREF, 
		window, D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT, 
		&d3d_params, &d3d9_device) < 0) {
		
		return false; // Initialized failed (< 0)
	}
	
	// Initialization was successful
	return true;
}

// Unregisters DirectX9 
void GUI::DestroyDirectX9() noexcept {
	// Check if the d3d9 device is valid
	if (d3d9_device) {
		// If true, release it and set it to null
		d3d9_device->Release();
		d3d9_device = NULL;
	}

	// Check if the d3d9 pointer is valid
	if (d3d9) {
		// If true, release it and set it to null
		d3d9->Release();
		d3d9 = NULL;
	}
}

// Sets up the device
void GUI::InitializeDevice() {
	// Handle runtime exception errors first

	// Check to see the window class was initialized properly
	if (!InitializeWindowClass("FattyMenuWndClass")) {
		// If not, throw an error
		throw std::runtime_error("Window class could not be created.");
	}

	// Check to see the window was initialized properly
	if (!InitializeWindow("FattyMenuWnd")) {
		// If not, throw an error
		throw std::runtime_error("Window could not be created.");
	}

	// Check to see the DirectX was initialized properly
	if (!InitializeDirectX9()) {
		// If not, throw an error
		throw std::runtime_error("D3D9 device could not be created.");
	}

	// Unregister the Window and Window Class
	DestroyWindow();
	DestroyWindowClass();

	// All that's left is the DirectX device
}

// Initializes ImGUI menu
void GUI::InitializeMenu(LPDIRECT3DDEVICE9 d3d9_device) noexcept {
	// Create a D3D device creation parameters object
	auto d3d_params = D3DDEVICE_CREATION_PARAMETERS{ };
	
	// Populate the object's parameters/attributes
	d3d9_device->GetCreationParameters(&d3d_params);

	// Temp window is destroyed at this point
	// Thus allowing the menu window to be opened and take priority

	// Set the menu window to the game window
	window = d3d_params.hFocusWindow;

	// Store the original window process
	o_window_proc = (WNDPROC)(SetWindowLongPtr( // Might need to change some type-cast conversions to reinterpret_cast for readability/maintainability later
		window, 
		GWLP_WNDPROC, 
		(LONG_PTR)(WindowProcess)
	)); 

	ImGui::CreateContext(); 			// Create the ImGUI context
	ImGui::StyleColorsDark();			// Set the style of the colors
	
	ImGui_ImplWin32_Init(window);		// Pass the game's window to ImGui's initialization method
	ImGui_ImplDX9_Init(d3d9_device);	// Pass the DirectX3D9 device to ImGui's initialization method

	initialized = true; // Menu initialization is complete
}

// Unregisters everything
void GUI::Destroy() noexcept {
	// Shut down the ImGui context
	ImGui_ImplDX9_Shutdown();		// Shutdown DirectX
	ImGui_ImplWin32_Shutdown();		// Shutdown the Window
	ImGui::DestroyContext();

	// Revert any previous change of the game's window process being superceded by the menu's window process
	SetWindowLongPtr(
		window, 
		GWLP_WNDPROC, 
		(LONG_PTR)(o_window_proc)  // Might need to change type-cast conversion to reinterpret_cast for readability/maintainability later
	);

	// Unregister DirectX
	DestroyDirectX9();
}

void GUI::Render() noexcept {
	// Get the ImGui input/output
	ImGuiIO& io = ImGui::GetIO();

	// Set the mouse cursor flag to not change
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange; // Prevents cursor flickering at the crosshair when the menu is open in-game

	// Set up ImGui frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	GUIUtils::SetThemeCivilProtection();

	// ImGui window begins
	ImGui::Begin("FattyMenu v1.6.2 | RCTRL = Open or Close | END = Uninject Menu", &open_menu);

	// ImGui tab bar begins
	if (ImGui::BeginTabBar("Menu Tabs")) {
		/* Old deprecated tab, source for it not included
		// Render the calculator tab
		if (ImGui::BeginTabItem("Item Calculator")) {
			if (ImGui::CollapsingHeader("FattyCalc - Calculate resources needed for MULTIPLE different items")) {
				FattyCalc::RenderCalculatorMenu();
			}
			if (ImGui::CollapsingHeader("DietCalc - Calculate resources needed for a SINGLE item")) {
				DietCalc::RenderCalculatorMenu();
			}
			ImGui::EndTabItem();
		}
		*/

		// Render operating procedures tab
		if (ImGui::BeginTabItem("Operating Procedures")) {
			PocketSOP::RenderCivilProtectionSOP();
			ImGui::EndTabItem();
		}

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
		if (ImGui::BeginTabItem("Notepads")) {
			// Render patrol log notepad
			if (ImGui::CollapsingHeader("Patrol Logs")) {
				Notepad::RenderPatrolLogNotepad();
			}

			// Render probie recommendation tab
			if (ImGui::CollapsingHeader("Probationary Recommendations")) {
				Notepad::RenderProbieRecommendationNotepad();
			}

			// Render general-use notepad
			if (ImGui::CollapsingHeader("Notepad")) {
				Notepad::RenderGeneralUseNotepad();
			}

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Credits")) {
			ImGui::TextWrapped("Internal menu created by: @wiener_water88 (JoeRogaine) on Discord aka cpap7 on Github\n");
			ImGui::Separator();

			ImGui::TextWrapped("Special thanks to the following people for their help: \n\n");

			ImGui::TextWrapped("-> MajoraPLZ for helping me find the right people to ask for info, and answering any questions I had\n");
			ImGui::TextWrapped("-> Cazzette for providing feedback, and also helping me find people to ask for info\n\n");
			ImGui::TextWrapped("-> voprositelnii for providing TAC usage etiquette and duty expectations");
			ImGui::Separator();

			ImGui::TextWrapped("SOP files\n");
			ImGui::TextWrapped("-> Rommel & Cazzette for sending me the SOP pdfs\n\n");
			ImGui::Separator();

			ImGui::TextWrapped("Voiceline Data\n");
			ImGui::TextWrapped("-> -Broken-\n\n");

			ImGui::EndTabItem();
		}

		// End tab bar
		ImGui::EndTabBar();
	}
	
	// End ImGui window
	ImGui::End();

	// End frame and render ImGui data
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}


/* Controls window/input priority between the menu window and game process */
LRESULT CALLBACK WindowProcess(HWND window, UINT message, WPARAM wide_param, LPARAM long_param) {

	// Check if the menu is toggled on or off
	if (GetAsyncKeyState(VK_RCONTROL) & 1) {		// '& 1' -> Detect one keystroke
		GUI::open_menu = !GUI::open_menu;	// If true, set to false & vice versa
		// e.g.: menu is opened -> you press the key -> it will close & vice versa
	}

	// Pass messages to ImGUI
	if (GUI::open_menu && ImGui_ImplWin32_WndProcHandler(window, message, wide_param, long_param)) {
		// Return 1 long -> it won't call the original game process so long as the menu is open
		return 1L;
	}

	// Restore input priority back to the game process
	return CallWindowProc(
		GUI::o_window_proc,
		window,
		message,
		wide_param,
		long_param
	);
}