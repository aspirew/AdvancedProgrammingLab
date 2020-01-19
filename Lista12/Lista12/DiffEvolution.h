#pragma once
#include "mscnProblem.h"
#include "MscnSolution.h"
#include "Random.h"
#include "DiffInd.cpp"
#include "Optimizer.h"
#include "CONST_H.h"

class DiffEvolution : public Optimizer {
public:

  DiffEvolution(std::vector<MinMaxValues> allMinMaxValues);
  DiffEvolution(Problem * problem, double cp, double dw, std::vector<MinMaxValues> allMinMaxValues, int time);
  DiffEvolution(Problem * problem, int seed, double cp, double dw, std::vector<MinMaxValues> allMinMaxValues, int time);
  ~DiffEvolution() { }

DiffInd * getBestFound();
DiffInd * getBestFound(int time);
DiffInd * getBestFound(int time, int populationNumber);

void setMinMaxValues(std::vector<MinMaxValues> allMinMaxValues);

double getBestScore();
double * solveProblem(Problem * problem);

private:

  Random r;
  std::vector<DiffInd> initPopulation(int populationNumber);

  bool areDiffrent(DiffInd &diff0, DiffInd &diff1, DiffInd &diff2, DiffInd &diff3);
  bool isCorrectValue(double val, int index);
  double fixValue(double val, int index);
  DiffInd getRandomInd();

  double crossProb;
  double diffWeigth;

  std::vector<MinMaxValues> allMinMaxValues;

};
