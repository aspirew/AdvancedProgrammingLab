#include "RandomSearch.h"
#include "Random.h"
#include <chrono>

template <typename T>
T * RandomSearch<T>::findBestSolution(int instanceSeed, int time) {
	this->timer.setTime(time);
	return findBestSolution(instanceSeed);
}

template <typename T>
T * RandomSearch<T>::findBestSolution()
{
	return findBestSolution(0);
}

template <typename T>
T * RandomSearch<T>::findBestSolution(int instanceSeed)
{
	double bestQuality = INT_MIN;
	int solSize = this->problem->getSize();
	T * sol;
	T * bestSol = new T[0]();

	if (instanceSeed != 0)
		if (!this->problem->setRandomClassSeed(instanceSeed)) return bestSol;

	this->timer.startTimer();

	do {

		bool bestChange = false;
		sol = this->problem->generateRandSolution();
		int currentQuality = this->problem->getQuality(sol, solSize);
			if (currentQuality > bestQuality) {
				delete bestSol;
				bestSol = sol;
				bestQuality = currentQuality;
				bestChange = true;
			}
		if (!bestChange) delete sol;
	} while (!this->timer.hasTimePassed());

	return bestSol;
}

template <typename T>
double RandomSearch<T>::getBestScore()
{
	return this->problem->getQuality(findBestSolution(0, DEFAULT_TIME), this->problem->getSize());
}
