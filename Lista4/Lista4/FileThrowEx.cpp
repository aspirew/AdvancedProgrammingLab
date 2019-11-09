#include "FileThrowExHeader.h"

FileThrowEx::FileThrowEx(std::string fileName) {
	openFile(fileName);
}

FileThrowEx::~FileThrowEx() {
	closeFile();
}

void FileThrowEx::printLine(std::string text) {

	const char *cstr = text.c_str();

	try {
		if (pFile == NULL) throw ERROR_WHILE_ADDING_ONE_LINE; 
		else{
			fprintf(pFile, cstr);
			fprintf(pFile, "\n");
		}
	}
	catch(std::string e){
		std::cout << e << std::endl;
	}

}

void FileThrowEx::printManyLines(std::vector<std::string> text) {

	try {
		if (pFile == NULL) throw ERROR_WHILE_ADDING_MANY_LINES;
		else {
			for (int i = 0; i < text.size(); i++) {
				printLine(text[i]);
			}
		}
	}
	catch(std::string e){
		std::cout << e << std::endl;
	}
}

void FileThrowEx::openFile(std::string fileName) {
	const char *fileNamecstr = fileName.c_str();
	try {
		pFile = fopen(fileNamecstr, "r+");
		if (pFile == NULL) throw ERROR_WHILE_OPENING_FILE_NO_SUCH_FILE;
	}
	catch (std::string e) {
		std::cout << e << std::endl;
	}
}

void FileThrowEx::closeFile() {
	try {
		if (pFile == NULL) throw ERROR_NO_FILE_OPENED;
		fclose(pFile);
	}
	catch (std::string e) {
		std::cout << e << std::endl;
	}
}
