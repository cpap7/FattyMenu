#pragma once

#include <string>

// Forward declarations
typedef struct IDirect3DTexture9* LPDIRECT3DTEXTURE9, * PDIRECT3DTEXTURE9;

namespace FattyMenu {
	class CTexture2D {
	private:
		std::string m_file_path{};

		PDIRECT3DTEXTURE9 m_texture_handle = nullptr;
		
		// Image data
		int m_width{ 0 };
		int m_height{ 0 };

		// Flags for loading
		bool m_load_attempted{ false };
		bool m_load_ok{ false };

	public:
		CTexture2D(const std::string& a_file_path);

		CTexture2D(const CTexture2D& a_other)				= delete;
		CTexture2D& operator=(const CTexture2D& a_other)	= delete;
		
		CTexture2D(CTexture2D&& a_other) noexcept;
		CTexture2D& operator=(CTexture2D&& a_other) noexcept;

		~CTexture2D();

		void Invalidate();		// Called in constructor - releases previously held texture first (if any) and (re)loads texture from file path
		void Release();			// Called in destructor  - releases all resources

		// Accessors
		inline const std::string& GetFilePath() const						{ return m_file_path;						}
		inline PDIRECT3DTEXTURE9 GetHandle() const							{ return m_texture_handle;					}
		inline int GetWidth() const											{ return m_width;							}
		inline int GetHeight() const										{ return m_height;							}
		inline bool HasAttemptedToLoad() const								{ return m_load_attempted;					}
		inline bool HasLoadedOK() const										{ return m_load_ok;							}

		inline void UpdatePathAndReload(const std::string& a_file_path)		{ m_file_path = a_file_path; Invalidate();	}
		//inline void SetFilePath(const std::string& a_file_path)			{ m_file_path = a_file_path;				} // Probably not needed

	private:
		void LoadFromFilePath();	// Loads from file path specified in constructor - called in Invalidate()

	};
}

