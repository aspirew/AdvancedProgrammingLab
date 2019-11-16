#include "FileErrCodeHeader.h"

FileErrCode::FileErrCode() {}

FileErrCode::FileErrCode(std::string fileName) {
	if (!openFile(fileName)) {
		std::cout << ERROR_WHILE_OPENING_FILE << std::endl;
	}
}

FileErrCode::~FileErrCode() {
	if (!closeFile()) {
		std::cout << ERROR_NO_FILE_OPENED << std::endl;
	}
}

bool FileErrCode::printLine(std::string text) {

	if (pFile == NULL) return FAILURE;

	if (fprintf(pFile, "%s\n", text.c_str()) < 0) return FAILURE;

	return SUCCESS;

}

bool FileErrCode::printManyLines(std::vector<std::string> text) {

		if (pFile == NULL) return FAILURE;

		for (int i = 0; i < text.size(); i++) {
			if(printLine(text[i]) == false) return FAILURE;
		}

		return SUCCESS;

}

bool FileErrCode::openFile(std::string fileName) {
	const char *fileNamecstr = fileName.c_str();

		pFile = fopen(fileNamecstr, "w+");
		if (pFile == NULL) return FAILURE;
		return SUCCESS;

}

bool FileErrCode::closeFile() {

	if (pFile == NULL) return FAILURE;
	fclose(pFile);
	return SUCCESS;

}
