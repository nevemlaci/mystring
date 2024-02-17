#include "mystring.h"
#include "cstring"

String::String(const char* cstr) : data(nullptr) {
	if (cstr == nullptr) {
		this->data = new char[1];
		this->data[0] = '\0';
		this->len = 0;
	}
	else {
		this->len = strlen(cstr);
		this->data = new char[this->len + 1];
		strncpy(this->data, cstr, this->len + 1);
	}
}

String::~String() {
	delete[] (this->data);
}

String::String(const String& other) {
	delete[] this->data;
	this->data = new char[other.len + 1];
	strncpy(this->data, other.data, other.len + 1);
	this->len = other.len;
}

String& String::operator=(const char cstr[]) {
	delete[] this->data;
	this->len = strlen(cstr);
	this->data = new char[this->len + 1];
	strncpy(this->data, cstr, this->len + 1);
	return *this;
}

bool String::operator==(String other) const {
	int result = strcmp(this->c_str(), other.c_str());
	return result == 0;
}

bool String::operator>(String other) const {
	return (strcmp(this->c_str(), other.c_str()) > 0);	
}

bool String::operator<(String other) const{
	return (strcmp(this->c_str(), other.c_str()) < 0);
}

size_t String::length() const {
	return this->len;
}

const char* String::c_str() const {
	return this->data;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	for (int i = 0; i < str.length(); i++) {
		os << str.c_str()[i];
	}
	return os;
}