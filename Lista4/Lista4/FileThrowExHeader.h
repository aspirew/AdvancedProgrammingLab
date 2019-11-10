#pragma once

class FileThrowEx : public FileErr {
private:

	FILE *pFile;

public:

	FileThrowEx();
	FileThrowEx(std::string fileName);
	~FileThrowEx();

	void openFile(std::string fileName);
	void closeFile();
	void printLine(std::string text);
	void printManyLines(std::vector <std::string> text);

};