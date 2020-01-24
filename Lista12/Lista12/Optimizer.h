#pragma once
#include "Problem.h"
#include "Timer.h"

template <typename T>
class Optimizer {
public:

	Optimizer() {
		if (!isCorrectTemplate()) {
			std::cout << "Template is wrong!";
			exit(1);
		}
	}
	Optimizer(Problem<T> *problem, int time) {
		if (!isCorrectTemplate()) {
			std::cout << "Template is wrong!";
			exit(1);
		}
		setProblem(problem);
		timer = Timer(time);
	}

	void setProblem(Problem<T> *problem) {
		if (!isCorrectTemplate()) {
			std::cout << "Template is wrong!";
			exit(1);
		}
		this->problem = problem;
	}

	virtual double getBestScore() = 0;
	virtual T * solveProblem(Problem<T> * problem) = 0;

protected:

	Problem<T> * problem;
	Timer timer;

private:

	bool isCorrectTemplate() { return isTemplateDouble() || isTemplateInt(); }
	bool isTemplateDouble();
	bool isTemplateInt();

};

template<typename T>
inline bool Optimizer<T>::isTemplateDouble()
{
	return false;
}

template<>
inline bool Optimizer<double>::isTemplateDouble()
{
	return true;
}

template<typename T>
inline bool Optimizer<T>::isTemplateInt()
{
	return false;
}

template<>
inline bool Optimizer<int>::isTemplateInt()
{
	return true;
}