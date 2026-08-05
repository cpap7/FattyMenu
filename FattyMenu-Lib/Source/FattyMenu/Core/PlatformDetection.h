#pragma once

// Platform detection macros
#ifdef _WIN32 // Windows x86
	#ifdef _WIN64 // Windows x86-x64
		//#define FM_PLATFORM_WINDOWS // HACK to keep the compiler from complaining - TODO: update premake to not define this
		#define WIN32_LEAN_AND_MEAN
		#define NOMINMAX
		#include <Windows.h>
	#else
		/* Windows x86 */
		#error "FattyMenu is not supported on Windows x86 (32-bit) builds!"
	#endif

#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all platforms,
	* so all different Apple platforms must be
	* checked to ensure it's running on macOS, not
	* iOS or some other Apple platform
	*/
	#if TARGET_IPHONE_SIMULATOR == 1
		#define FM_PLATFORM_IOS_SIMULATOR
		#error "FattyMenu is not supported on iOS simulators!"
	#elif TARGET_OS_IPHONE == 1
		#define FM_PLATFORM_IOS
		#error "FattyMenu is not supported on iOS!"
	#elif TARGET_OS_MAC == 1
		#define FM_PLATFORM_MACOS
		#error "FattyMenu is not supported on macOS!"
	#else
		#error "Unknown Apple platform!"
#endif

// Also have to check __ANDROID__ before __linux__ since
// android is based on the linux kernel and has __linux__ defined
#elif defined(__ANDROID__)
	#define FM_PLATFORM_ANDROID
	#error "FattyMenu is not supported on Android!"
#elif defined(__linux__)
	#define FM_PLATFORM_LINUX
	#error "FattyMenu is not supported on Linux!"
#endif 

// Compiler platform detection macros
#if defined(__GNUC__)
	#if defined(__clang__)
		#define FM_COMPILER_CLANG
	#else
		#define FM_COMPILER_GCC
	#endif
#elif defined(_MSC_VER)
	#define FM_COMPILER_MSVC
#endif

#ifdef FM_COMPILER_MSVC
	#define FM_FORCE_INLINE __forceinline
	#define FM_EXPLICIT_STATIC static
#elif defined (__GNUC__)
	#define FM_FORCE_INLINE __attribute__((always_inline)) inline
	#define FM_EXPLICIT_STATIC
#else
	#define FM_FORCE_INLINE inline
	#define FM_EXPLICIT_STATIC
#endif