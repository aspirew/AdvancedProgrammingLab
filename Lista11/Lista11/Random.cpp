#include "Random.h"

void Random::randInit(int seed) {
	this->seed = seed;
	std::mt19937 gen(seed);
	generator = gen;
}

double Random::generateDouble(double leftBoundary, double rightBoundary) {
	std::uniform_real_distribution<> dist(leftBoundary, rightBoundary);
	return dist(generator);
}

double Random::generateInt(int leftBoundary, int rightBoundary) {
	std::uniform_int_distribution<> dist(leftBoundary, rightBoundary);
	return dist(generator);
}


bool Random::setSeedFromTxt(std::string fileName){

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "r+");

	if (!pFile) return false;

	std::ifstream is(pFile);

	is >> seed;

	is.close();
	fclose(pFile);
	
	return true;

}

bool Random::setSeed(int seed) {
	if (seed < 0) return false;
	this->seed = seed;
	std::mt19937 gen(seed);
	generator = gen;
	return true;
}

bool Random::saveSeed(std::string fileName) {

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "w+");

	if (!pFile) return false;

	std::ofstream file(pFile);
	file << seed;
	file.close();
	fclose(pFile);

	return true;
}