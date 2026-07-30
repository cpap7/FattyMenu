project "FattyMenu-Lib"
   kind "SharedLib"
   language "C++"
   cppdialect "C++20"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"
   characterset "MBCS"
   targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
   objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

   files 
   { 
        "Source/**.h", 
        "Source/**.cpp",

		"Vendor/**.h",
		"Vendor/**.hpp",
        "Vendor/**.c",
        "Vendor/**.cpp",
   }

   includedirs
   {
       "Source",
       "%{IncludeDir.imgui}",
       "%{IncludeDir.garrysmod_common}",
       "%{IncludeDir.minhook}",
	   "%{IncludeDir.json}",
       "%{IncludeDir.httplib}",
       "%{IncludeDir.html_parser}",
       "%{IncludeDir.openssl}",       -- vcpkg
       "%{IncludeDir.directx9}"       -- DirectX9
   }
   
   postbuildcommands
   {
      '{COPYFILE} "%{cfg.buildtarget.abspath}" "%{cfg.buildtarget.directory}/gmsv_fattymenu_win64.dll"'
   }
   
   filter "system:windows"
      systemversion "latest"
      toolset "v145" -- VS 2026
      defines { "FM_PLATFORM_WINDOWS" }
      libdirs 
      { 
          "%{LibraryDir.openssl}", "%{LibraryDir.directx9}"
      }
      links 
      { 
          "ws2_32", "ole32", "winmm", "libssl", "libcrypto", "crypt32",           	-- vcpkg
          "d3d9", "d3dx9"           												-- DirectX9-related
      }

   filter "configurations:Debug"
      defines { "FM_DEBUG" }
      buildoptions { "/utf-8" }
      runtime "Debug"
      symbols "On"
    
   filter "configurations:Release"
      defines { "FM_RELEASE" }
      buildoptions { "/utf-8" }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      defines { "FM_DIST" }
      buildoptions { "/utf-8" }
      runtime "Release"
      optimize "On"
      symbols "Off"
      