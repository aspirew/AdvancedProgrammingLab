#include "pch.h"
#include "CONST.h"
#include "FileLastError.cpp"
#include "FileThrowEx.cpp"

int main(){

	FileLastError errorCatching1("plkk.txt");
	errorCatching1.printManyLines({ "xd", "succ", "CBT", "TEP" });

	FileThrowEx errorCatching2("plkk.txt");
	errorCatching2.

}
