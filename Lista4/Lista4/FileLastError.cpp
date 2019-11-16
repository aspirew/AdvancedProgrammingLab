#include "FileLastErrorHeader.h"

bool FileLastError::lastError;

FileLastError::FileLastError() {
	lastError = false;
}

FileLastError::FileLastError(std::string fileName) {
	lastError = false;
	openFile(fileName);
}

FileLastError::~FileLastError() {
	closeFile();
}

void FileLastError::printLine(std::string text) {

	lastError = false;

	if (pFile == NULL) {
		lastError = true;
		std::cout << ERROR_WHILE_ADDING_ONE_LINE << std::endl;
		return;
	}

	if (fprintf(pFile, "%s\n", text.c_str()) < 0) {
		std::cout << ERROR_WHILE_ADDING_ONE_LINE << std::endl;
	}

}

void FileLastError::printManyLines(std::vector<std::string> text) {
	
	lastError = false;

	if (pFile == NULL) {
		lastError = true;
		std::cout << ERROR_WHILE_ADDING_MANY_LINES << std::endl;
		return;
	}

	for (int i = 0; i < text.size(); i++) {
		printLine(text[i]);
		if (getLastError()) {
			std::cout << ERROR_WHILE_ADDING_MANY_LINES << std::endl;
			return;
		}
	}
}

void FileLastError::openFile(std::string fileName) {
	lastError = false;
	pFile = fopen(fileName.c_str(), "w+");
	if (pFile == NULL) {
		lastError = true;
		std::cout << ERROR_WHILE_OPENING_FILE << std::endl;
	}
}

void FileLastError::closeFile() {
	lastError = false;
	if (pFile != NULL) fclose(pFile);
	else {
		std::cout << ERROR_NO_FILE_OPENED << std::endl;
		lastError = true;
	}
}
