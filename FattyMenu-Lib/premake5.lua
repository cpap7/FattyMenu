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
   }
   
   links 
   {
		"d3d9",
   }
   
   postbuildcommands
   {
      '{COPYFILE} "%{cfg.buildtarget.abspath}" "%{cfg.buildtarget.directory}/gmsv_fattymenu_win64.dll"'
   }
   
   filter "system:windows"
      systemversion "latest"
      toolset "v145" -- VS 2026
      defines { "FM_PLATFORM_WINDOWS" }
      links { "ws2_32", "ole32", "winmm" }

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
      