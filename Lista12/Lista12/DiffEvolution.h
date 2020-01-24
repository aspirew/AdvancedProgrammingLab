#pragma once
#include "mscnProblem.h"
#include "MscnSolution.h"
#include "Random.h"
#include "DiffInd.cpp"
#include "Optimizer.h"
#include "CONST_H.h"

template <typename T>
class DiffEvolution : public Optimizer<T> {
public:

  DiffEvolution(std::vector<MinMaxValues<T>> allMinMaxValues);
  DiffEvolution(Problem<T> * problem, double cp, double dw, std::vector<MinMaxValues<T>> allMinMaxValues, int time);
  DiffEvolution(Problem<T> * problem, int seed, double cp, double dw, std::vector<MinMaxValues<T>> allMinMaxValues, int time);
  ~DiffEvolution() { }

DiffInd<T> * getBestFound();
DiffInd<T> * getBestFound(int time);
DiffInd<T> * getBestFound(int time, int populationNumber);

void setMinMaxValues(std::vector<MinMaxValues<T>> allMinMaxValues);

double getBestScore();
T * solveProblem(Problem<T> * problem);

private:

  Random r;
  std::vector<DiffInd<T>> initPopulation(int populationNumber);

  bool areDiffrent(DiffInd<T> &diff0, DiffInd<T> &diff1, DiffInd<T> &diff2, DiffInd<T> &diff3);
  bool isCorrectValue(T val, int index);
  double fixValue(T val, int index);
  DiffInd<T> getRandomInd();

  double crossProb;
  double diffWeigth;

  std::vector<MinMaxValues<T>> allMinMaxValues;

};
