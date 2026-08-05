#pragma once


#define FM_BUILD_VERSION_MAJOR "1"
#define FM_BUILD_VERSION_MINOR "8"
#define FM_BUILD_VERSION_PATCH "0"

#define FM_BUILD_VERSION "v" FM_BUILD_VERSION_MAJOR "." FM_BUILD_VERSION_MINOR "." FM_BUILD_VERSION_PATCH

// Build platform
#if defined (FM_PLATFORM_WINDOWS)
	#define FM_BUILD_PLATFORM_NAME "Windows x64"
#elif defined (FM_PLATFORM_LINUX)
	#define FM_BUILD_PLATFORM_NAME "Linux"
#elif defined (FM_PLATFORM_MACOS)
	#define FM_BUILD_PLATFORM_NAME "macOS"
#else
	#define FM_BUILD_PLATFORM_NAME "Unknown"
#endif

// Build configuration
#if defined(FM_DEBUG)
	#define FM_BUILD_CONFIG_NAME "Debug Build"
#elif defined(FM_RELEASE)
	#define FM_BUILD_CONFIG_NAME "Release Build"
#elif defined(FM_DIST)
	#define FM_BUILD_CONFIG_NAME "Distribution Build"
#endif

#define FM_VERSION_LONG "FattyMenu " FM_BUILD_VERSION " (" FM_BUILD_PLATFORM_NAME " - " FM_BUILD_CONFIG_NAME ")" 