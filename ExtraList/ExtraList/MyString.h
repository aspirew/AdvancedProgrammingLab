#pragma once
#include <string>
#include <iostream>

class MyString {
public:

	MyString();
	MyString(char * initialValue);
	MyString(const MyString &other);
	~MyString();

	int size() { return length; }

	MyString & operator=(const char * newWord);
	MyString & operator=(const MyString &other);

	friend MyString operator+(const MyString& s1, const MyString& s2);
	friend MyString operator+(const MyString& s, const char * c);
	friend MyString operator+(const char * c, const MyString& s);

	MyString & operator+=(const char * newWord);
	MyString & operator+=(const MyString &other);
	char& operator[] (int index);
	operator bool() const;

	friend std::ostream& operator<<(std::ostream &os, const MyString &string);

	std::string toStandard();

private:

	char * word;
	int length;
};