#pragma once
#include "mscnProblem.h"
#include "MscnSolution.h"
#include "Random.h"
#include "DiffInd.cpp"
#include "CONST_H.h"

class DiffEvolution {
public:

  DiffEvolution();
  DiffEvolution(MscnProblem * problem);
  DiffEvolution(MscnProblem * problem, int seed);
  ~DiffEvolution() { }
  void setProblem(MscnProblem *problem) { this->problem = problem; }

  std::vector<DiffInd> getBestFound();
  std::vector<DiffInd> getBestFound(int maxIteration, int populationNumber);


private:

  MscnProblem * problem;
  Random r;
  double crossProb = 0;
  std::vector<DiffInd> initPopulation(int populationNumber);

  bool areDiffrent(DiffInd &diff0, DiffInd &diff1, DiffInd &diff2, DiffInd &diff3);
  bool isCorrectValue(double val, int index);
  double fixValue(double val, int index);
  DiffInd getRandomInd();

};
