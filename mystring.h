#ifndef __STRING_H__
#define __STRING_H__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

/// @brief Dynamic character array storage.
/// Stores a null-terminated char array.
/// 
class String {
public:
	/// @brief 
	/// @param cstr 
	String(const char* cstr = nullptr);

	~String();

	size_t length() const;

	const char* c_str() const;

	String(const String& other);

	String& operator=(const char cstr[]);

	bool operator==(String other) const;

	bool operator>(String other) const;

	bool operator<(String other) const;

private:
	char* data = nullptr;
	size_t len = 0;
};

std::ostream& operator<<(std::ostream&, const String& str);

#endif
