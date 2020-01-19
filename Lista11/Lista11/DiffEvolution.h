#pragma once
#include "mscnProblem.h"
#include "MscnSolution.h"
#include "Random.h"
#include "DiffInd.cpp"
#include "CONST_H.h"

class DiffEvolution {
public:

  DiffEvolution();
  DiffEvolution(MscnProblem * problem, double cp, double dw);
  DiffEvolution(MscnProblem * problem, int seed, double cp, double dw);
  ~DiffEvolution() { }
  void setProblem(MscnProblem *problem) { this->problem = problem; }

DiffInd getBestFound();
DiffInd getBestFound(int maxIteration, int populationNumber);


private:

  MscnProblem * problem;
  Random r;
  std::vector<DiffInd> initPopulation(int populationNumber);

  bool areDiffrent(DiffInd &diff0, DiffInd &diff1, DiffInd &diff2, DiffInd &diff3);
  bool isCorrectValue(double val, int index);
  double fixValue(double val, int index);
  DiffInd getRandomInd();

  double crossProb;
  double diffWeigth;

};
