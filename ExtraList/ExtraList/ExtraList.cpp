#include "pch.h"
#include <iostream>
#include "MyString.h"
int main()
{
	MyString c_str;
	std::cout << (bool)c_str << std::endl;

	c_str = "maja ";
	(c_str += "kota") += ", zolwia";
	c_str = c_str + ", psa" + " i rybke";
	c_str = "Ala " + ("i Jacek " + c_str);
	std::cout << c_str << std::endl;
	c_str[0] = 'E';
	std::cout << c_str << std::endl;

	std::cout << (bool)c_str << std::endl;

	std::string str = c_str.toStandard();
	std::cout << str.at(0);

}
