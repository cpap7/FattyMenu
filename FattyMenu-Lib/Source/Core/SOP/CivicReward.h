#pragma once


namespace FattyMenu {
	class CCivicReward {
	private:
		const char* m_number						= "";
		const char* m_description					= "";

	public:
		// Constructors
		CCivicReward(const char* a_number, const char* a_description);
		CCivicReward() = default;

		// Destructor
		~CCivicReward() = default;

		// Accessors
		inline void SetNumber(const char* a_number)										{ m_number		= a_number;			}
		inline void SetDescription(const char* a_description)							{ m_description	= a_description;	}

		inline const char* GetNumber() const											{ return m_number;					}
		inline const char* GetDescription() const										{ return m_description;				}
	};

}