#include "FileErrCodeHeader.h"

FileErrCode::FileErrCode() {}

FileErrCode::FileErrCode(std::string fileName) {
	if (!openFile(fileName)) {
		std::cout << ERROR_WHILE_OPENING_FILE_NO_SUCH_FILE << std::endl;
	}
}

FileErrCode::~FileErrCode() {
	if (!closeFile()) {
		std::cout << ERROR_NO_FILE_OPENED << std::endl;
	}
}

bool FileErrCode::printLine(std::string text) {

	const char *cstr = text.c_str();

	if (pFile == NULL) return false;

	fprintf(pFile, cstr);
	fprintf(pFile, "\n");
	return true;

}

bool FileErrCode::printManyLines(std::vector<std::string> text) {

		if (pFile == NULL) return false;

		for (int i = 0; i < text.size(); i++) {
			if(printLine(text[i]) == false) return false;
		}

		return true;

}

bool FileErrCode::openFile(std::string fileName) {
	const char *fileNamecstr = fileName.c_str();

		pFile = fopen(fileNamecstr, "r+");
		if (pFile == NULL) return false;
		return true;

}

bool FileErrCode::closeFile() {

	if (pFile == NULL) return false;
	fclose(pFile);
	return true;

}
