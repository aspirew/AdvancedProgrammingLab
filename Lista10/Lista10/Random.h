#pragma once
#include "CONST_H.h"

class Random {
public:
	Random() { randInit(time(NULL)); }
	Random(int seed) { randInit(seed); }
	
	void randInit(int seed);

	void setSeed(int seed) { this->seed = seed; }
	bool saveSeed(std::string fileName);
	double generateDouble(double leftBoundary, double rightBoundary);
	double generateInt(int leftBoundary, int rightBoundary);
	bool setSeedFromTxt(std::string fileName);

private:
	unsigned int seed;
	std::mt19937 generator;
};