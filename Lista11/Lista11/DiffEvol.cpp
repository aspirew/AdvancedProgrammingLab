#include "DiffEvol.h"
#include "RandomSearch.h"
#include "Random.h"

DiffEvol::DiffEvol() {
  problem = MscnProblem();
  r = Random();
  crossProb = r.generateDouble(0, 1);
}

DiffEvol::DiffEvol(MscnProblem * problem, int seed) {
  this->problem = problem;
  r = Random(seed);
  crossProb = r.generateDouble(0, 1);
}

//DiffEvol::DiffEvol(MscnProblem * problem) 

//DiffIndividual DiffEvol::getBestFound()

//std::vector<DiffIndividual> DiffEvol::initPopulation(int populationNumber) 

//bool DiffEvol::areDiffrent(DiffIndividual diff0, DiffIndividual diff1, DiffIndividual diff2, DiffIndividual diff3) 

//DiffIndividual DiffEvol::getBestFound(int maxIteration, int populationNumber) 
