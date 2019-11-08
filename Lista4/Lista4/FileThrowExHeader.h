#pragma once

class FileThrowEx {
private:

	FILE *pFile;

public:

	FileThrowEx(std::string fileName);
	~FileThrowEx();

	void openFile(std::string fileName);
	void closeFile();
	void printLine(std::string text);
	void printManyLines(std::vector <std::string> text);

};