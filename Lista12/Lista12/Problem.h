#pragma once
#include "CONST_H.h"
#include "Random.h"

template <typename T>
class Problem {
public:

	Problem() {
		if (!isCorrectTemplate()) {
			std::cout << "Template is wrong!";
			exit(1);
		}
	}
	
	virtual bool saveData(std::string const &path) = 0;
	virtual bool saveSolution(T *solution, std::string const &path) = 0;
	virtual double getQuality(T *solution, int arrSize) = 0;
	virtual bool setRandomClassSeed(int seed) = 0;
	virtual T * generateRandSolution() = 0;
	virtual int getSize() = 0;

protected:

	bool isCorrectTemplate() { return isTemplateDouble() || isTemplateInt(); }
	bool isTemplateDouble();
	bool isTemplateInt();


};

template<typename T>
inline bool Problem<T>::isTemplateDouble()
{
	return false;
}

template<>
inline bool Problem<double>::isTemplateDouble()
{
	return true;
}

template<typename T>
inline bool Problem<T>::isTemplateInt()
{
	return false;
}

template<>
inline bool Problem<int>::isTemplateInt()
{
	return true;
}
