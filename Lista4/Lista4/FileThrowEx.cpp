#include "FileThrowExHeader.h"

FileThrowEx::FileThrowEx(std::string fileName) {
	const char *fileNamecstr = fileName.c_str();
	pFile = fopen(fileNamecstr, "r+");
}

FileThrowEx::~FileThrowEx() {
	if (pFile != NULL) fclose(pFile);
}

void FileThrowEx::printLine(std::string text) {

	const char *cstr = text.c_str();

	try {
		fprintf(pFile, cstr);
		fprintf(pFile, "\n");
	}
	catch(...){
		std::cout << ERROR_WHILE_ADDING_ONE_LINE << std::endl;
	}

	}

void FileThrowEx::printManyLines(std::vector<std::string> text) {

	for (int i = 0; i < text.size(); i++) {
		printLine(text[i]);
	}

}

void FileThrowEx::openFile(std::string fileName) {
	const char *fileNamecstr = fileName.c_str();
	try {
		pFile = fopen(fileNamecstr, "r+");
	}
	catch (...) {
		std::cout << ERROR_WHILE_OPENING_FILE_NO_SUCH_FILE << std::endl;
	}
}

void FileThrowEx::closeFile() {
	try {
		fclose(pFile);
	}
	catch (...) {
		std::cout << ERROR_NO_FILE_OPENED << std::endl;
	}
}
