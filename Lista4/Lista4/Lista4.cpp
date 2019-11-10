#include "pch.h"
#include "CONST.h"
#include "FileErrorHeader.h"
#include "FileLastError.cpp"
#include "FileThrowEx.cpp"
#include "FileErrCode.cpp"

void testingLastErrFun(FileLastError &toCheck, std::string fileName) {
	for (int i = 0; i < 10; i++) {
		toCheck.openFile(fileName);
	}
}

void testingThrowingFun(FileThrowEx &toCheck, std::string fileName) {
	for (int i = 0; i < 10; i++) {
		toCheck.openFile(fileName);
	}
}

void testingErrCodeFun(FileErrCode &toCheck, std::string fileName) {
	for (int i = 0; i < 10; i++) {
		if(!toCheck.openFile(fileName)) std::cout << ERROR_WHILE_OPENING_FILE_NO_SUCH_FILE << std::endl;
	}
}

int main(){

	FileLastError errorCatching1;
	//errorCatching1.printManyLines({ "icup", "succ", "CBT" });

	FileThrowEx errorCatching2;
	//errorCatching2.printManyLines({ "Crash team racing", "lets", "smash bros" });

	FileErrCode errorCatching3;
	//std::cout << errorCatching3.printManyLines({ "MACINTOSH PLUS - FLORAL SHOPPE - 02", "scythelord", "katamari 05" });

	testingLastErrFun(errorCatching1, "asd.txt");
	std::cout << std::endl;
	testingThrowingFun(errorCatching2, "plkk.txt");
	std::cout << std::endl;
	testingErrCodeFun(errorCatching3, "dddas.txt");
}
