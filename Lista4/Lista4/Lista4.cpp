#include "pch.h"
#include "CONST.h"
#include "FileLastError.cpp"
#include "FileThrowEx.cpp"
#include "FileErrCode.cpp"

void testingLastErrFun(std::string fileName) {

	std::cout << "lastError: " << std::endl;

	FileLastError errorCatching;

	for (int i = 0; i < 10; i++) {
		errorCatching.openFile(fileName);
		errorCatching.printManyLines({ "abc", "xyz", "ooo" });
		errorCatching.closeFile();
	}

	if (!(errorCatching.getLastError())) std::cout << TEST_SUCCESFUL << std::endl;
}

void testingThrowingFun(std::string fileName) {

	FileThrowEx errorCatching;
	bool succ = true;

	std::cout << "throwEx: " << std::endl;

	try {
		for (int i = 0; i < 10; i++) {
			errorCatching.openFile(fileName);
			errorCatching.printManyLines({ "abc", "xyz", "ooo" });
			errorCatching.closeFile();
		}
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		succ = false;
	}

	if (succ) std::cout << TEST_SUCCESFUL << std::endl;

}

void testingErrCodeFun(std::string fileName) {

	FileErrCode errorCatching;

	std::cout << "errorCode: " << std::endl;

	bool succ = true;

	for (int i = 0; i < 10; i++) {
		if (!errorCatching.openFile(fileName)) {
			std::cout << ERROR_WHILE_OPENING_FILE << std::endl;
			succ = false;
		}
		if (!errorCatching.printManyLines({ "abc", "xyz", "ooo" })) {
			std::cout << ERROR_WHILE_ADDING_MANY_LINES << std::endl;
			succ = false;
		}
		if (!errorCatching.closeFile()) {
			std::cout << ERROR_NO_FILE_OPENED << std::endl;
			succ = false;
		}
	}

	if (succ) std::cout << TEST_SUCCESFUL << std::endl;
}

int main(){

	testingLastErrFun("textFiles/lastError.txt");
	std::cout << std::endl;
	testingThrowingFun("textFiles/throwException.txt");
	std::cout << std::endl;
	testingErrCodeFun("textFiles/errorCode.txt");
}
