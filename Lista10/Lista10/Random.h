#pragma once
#include "CONST_H.h"

class Random {
public:
	Random() { randInit(DEFAULT_SEED); }
	Random(int seed) { randInit(seed); }
	
	void randInit(int seed);

	bool setSeed(int seed);
	bool saveSeed(std::string fileName);
	double generateDouble(double leftBoundary, double rightBoundary);
	double generateInt(int leftBoundary, int rightBoundary);
	bool setSeedFromTxt(std::string fileName);

private:
	unsigned int seed;
	std::mt19937 generator;
};