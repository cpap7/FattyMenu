
IncludeDir = {}
IncludeDir["garrysmod_common"] = "../FattyMenu-Lib/Vendor/garrysmod_common"
IncludeDir["imgui"] = "../FattyMenu-Lib/Vendor/imgui"
IncludeDir["minhook"] = "../FattyMenu-Lib/Vendor/minhook"
IncludeDir["json"] = "../FattyMenu-Lib/Vendor/json"
IncludeDir["html_parser"] = "../FattyMenu-Lib/Vendor/html_parser"
IncludeDir["httplib"] = "../FattyMenu-Lib/Vendor/httplib"
IncludeDir["directx9"] = "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
IncludeDir["openssl"] = "C:/vcpkg/installed/x64-windows-static-md/include"

LibraryDir = {}
LibraryDir["openssl"] = "C:/vcpkg/installed/x64-windows-static-md/lib"
LibraryDir["directx9"] = "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64"


group "Core"
	include "FattyMenu-Lib"
group ""
