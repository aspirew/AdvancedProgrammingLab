#pragma once

class FileLastError : public FileErr {
private:
	static bool lastError;
	FILE *pFile;

public:
	static bool getLastError() { return(lastError); }

	FileLastError();
	FileLastError(std::string fileName);
	~FileLastError();

	void openFile(std::string fileName);
	void closeFile();
	void printLine(std::string text);
	void printManyLines(std::vector <std::string> text);

};