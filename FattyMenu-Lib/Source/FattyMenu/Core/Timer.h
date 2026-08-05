#pragma once
#include "PlatformDetection.h"

#include <chrono>

namespace FattyMenu {
	class CTimer {
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_start;

	public:
		FM_FORCE_INLINE CTimer() {
			Reset();
		}

		FM_FORCE_INLINE void Reset() {
			m_start = std::chrono::high_resolution_clock::now();
		}

		// Accessors

		FM_FORCE_INLINE float GetTimeElapsed() {
			return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_start).count() * 0.001f * 0.001f;
		}

		FM_FORCE_INLINE float GetTimeElapsedMillis() {
			return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_start).count() * 0.001f;
		}
	};
}