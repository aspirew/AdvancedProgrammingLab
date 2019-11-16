#pragma once
class FileErrCode {
private:
	FILE *pFile;
public:
	FileErrCode();
	FileErrCode(std::string fileName);
	~FileErrCode();
	bool openFile(std::string fileName);
	bool closeFile();
	bool printLine(std::string text);
	bool printManyLines(std::vector<std::string> text);
};