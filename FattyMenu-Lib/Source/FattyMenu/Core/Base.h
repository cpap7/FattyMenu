#pragma once

// Miscellaneous macros & other useful utilities

#define BIT(x) (1 << x)

// Size of a static C-style array. Don't use on pointers!
#define FM_ARRAYSIZE(_ARR) ((int)(sizeof(_ARR) / sizeof(*(_ARR))))


// OOP utility macros 
// For rule of 0, 3 & 5
#define FM_UNCOPYABLE_CLASS(ClassName) \
	ClassName(const ClassName&)				= delete; \
	ClassName& operator=(const ClassName&)	= delete; 

#define FM_UNMOVABLE_CLASS(ClassName) \
	ClassName(ClassName&&)					= delete; \
	ClassName& operator=(ClassName&&)		= delete;

#define FM_DEFAULT_COPYABLE_CLASS(ClassName) \
	ClassName(const ClassName&)				= default; \
	ClassName& operator=(const ClassName&)	= default; 

#define FM_DEFAULT_MOVABLE_CLASS(ClassName) \
	ClassName(ClassName&&)					= default; \
	ClassName& operator=(ClassName&&)		= default;

#define FM_DEFAULT_CONSTRUCTOR(ClassName) \
	ClassName()								= default;

#define FM_DEFAULT_DESTRUCTOR(ClassName) \
	~ClassName()							= default;

#define FM_COPYABLE_CLASS(ClassName) \
	ClassName(const ClassName&); \
	ClassName& operator=(const ClassName&); 

#define FM_MOVABLE_CLASS(ClassName) \
	ClassName(ClassName&&); \
	ClassName& operator=(ClassName&&);

#define FM_HANDLE(HandleType, name) \
private: \
	HandleType name{}; \
public: \
	HandleType GetHandle() const { return name; }