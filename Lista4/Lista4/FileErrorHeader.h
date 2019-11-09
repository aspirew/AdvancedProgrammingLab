#pragma once

class FileErr {
public:
	void openFile(std::string fileName);
	void closeFile();
	void printLine(std::string text);
	void printManyLines(std::vector <std::string> text);
};