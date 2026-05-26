-- premake5.lua
workspace "FattyMenu"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "FattyMenu-Lib"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "External.lua"
