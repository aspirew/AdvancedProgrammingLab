#include "Random.h"
#include <random>

template <typename T>
Random<T>::Random(int seed, T leftBoundary, T rightBoundary) {
	this->seed = seed;
	this->leftBoundary = leftBoundary;
	this->rightBoundary = rightBoundary;
}

template <typename T>
T Random<T>::generateNumber() {
	std::mt19937 gen(seed); 
	using dist = std::conditional_t<
		std::is_integral<T>::value,
		std::uniform_int_distribution<T>,
		std::uniform_real_distribution<T>
	>;
	return dist{ leftBoundary, rightBoundary }(gen);
}

template <typename T>
bool Random<T>::setSeedFromTxt(std::string fileName){

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "r+");

	if (!pFile) return false;

	std::ifstream is(pFile);

	is >> seed;

	is.close();
	fclose(pFile);
	
	return true;

}

template <typename T>
bool Random<T>::saveSeed(std::string fileName) {

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "w+");

	if (!pFile) return false;

	std::ofstream file(pFile);
	file << seed;
	file.close();
	fclose(pFile);

	return true;
}