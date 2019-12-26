#pragma once
#include "CONST_H.h"

template <typename T>
class Random {
public:
	Random(int seed, T leftBoundary, T rightBoundary);
	~Random() { }

	void setSeed(int seed) { this->seed = seed; }
	bool saveSeed(std::string fileName);
	void setLeftBoundary(T bound) { leftBoundary = bound; }
	void setRightBoundary(T bound) { rightBoundary = bound; }
	T generateNumber();
	bool setSeedFromTxt(std::string fileName);

private:
	unsigned int seed;
	T leftBoundary;
	T rightBoundary;
};