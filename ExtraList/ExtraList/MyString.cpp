#include "pch.h"
#include "MyString.h"

MyString::MyString() {
	length = 0;
	word = NULL;
}

MyString::MyString(char * initialValue){
	length = strlen(initialValue);
	word = new char[length];
	strncpy(word, initialValue, length);
}

MyString::MyString(const MyString &other) {
	length = other.length;
	word = new char[length];
	strncpy(word, other.word, length);
}

MyString::~MyString(){
	delete[] word;
}

MyString & MyString::operator=(const char * newWord) {
	delete[] word;
	length = strlen(newWord);
	word = new char[length];
	strncpy(word, newWord, length);
	return *this;
}

MyString & MyString::operator=(const MyString &other) {
	if (this != &other) {
		delete[] word;
		length = other.length;
		word = new char[length];
		strncpy(word, other.word, length);
	}
	return *this;
}

MyString operator+(const char * c, const MyString & s){
	MyString res;
	res.length = strlen(c) + s.length;
	res.word = new char[res.length];
	strncpy(res.word, c, strlen(c));
	strncpy(res.word + strlen(c), s.word, s.length);
	return res;
}

MyString operator+(const MyString & s1, const MyString & s2){
	MyString res;
	res.length = s1.length + s2.length;
	res.word = new char[res.length];
	strncpy(res.word, s1.word, s1.length);
	strncpy(res.word + s1.length, s2.word, s2.length);
	return res;
}

MyString operator+(const MyString & s, const char * c)
{
	MyString res;
	res.length = strlen(c) + s.length;
	res.word = new char[res.length];
	strncpy(res.word, s.word, s.length);
	strncpy(res.word + s.length, c, strlen(c));
	return res;
}

MyString & MyString::operator+=(const char * newWord) {
	*this = *this + newWord;
	return *this;
}

MyString & MyString::operator+=(const MyString &other) {
	*this = *this + other;
	return *this;
}

MyString::operator bool() const {
	return length > 0;
}

char& MyString::operator[] (int index)
{
	if (index >= 0 || index < length) return word[index];
}

std::string MyString::toStandard() {
	std::string res;
	for (int i = 0; i < length; i++) res.push_back(word[i]);
	return res;
}

std::ostream & operator<<(std::ostream & os, const MyString & string)
{
	for (int i = 0; i < string.length; i++) os.put(string.word[i]);
	return os;
}
