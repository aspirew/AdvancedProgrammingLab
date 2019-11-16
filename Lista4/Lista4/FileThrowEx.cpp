#include "FileThrowExHeader.h"

FileThrowEx::FileThrowEx(){}

FileThrowEx::FileThrowEx(std::string fileName) {
	openFile(fileName);
}

FileThrowEx::~FileThrowEx() {
	if(pFile != NULL) closeFile();
}

void FileThrowEx::printLine(std::string text) {

	if (pFile == NULL) throw ERROR_WHILE_ADDING_ONE_LINE; 
	else{

		if (fprintf(pFile, "%s\n", text.c_str()) < 0) {
			std::cout << ERROR_WHILE_ADDING_ONE_LINE << std::endl;
		}

	}
}

void FileThrowEx::printManyLines(std::vector<std::string> text) {

	if (pFile == NULL) throw ERROR_WHILE_ADDING_MANY_LINES;
	else {
		for (int i = 0; i < text.size(); i++) {
			printLine(text[i]);
		}
	}
}

void FileThrowEx::openFile(std::string fileName) {
	pFile = fopen(fileName.c_str(), "w+");
	if (pFile == NULL) throw ERROR_WHILE_OPENING_FILE;
}

void FileThrowEx::closeFile() {
	if (pFile == NULL) throw ERROR_NO_FILE_OPENED;
	else fclose(pFile);
}
