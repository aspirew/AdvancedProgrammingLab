#include "DiffEvolution.h"
#include "mscnProblem.h"
#include "RandomSearch.h"
#include "MinMaxValues.h"

DiffEvolution::DiffEvolution() {
  problem = new MscnProblem();
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;
}

DiffEvolution::DiffEvolution(MscnProblem * problem) {
  this->problem = problem;
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;
}

DiffEvolution::DiffEvolution(MscnProblem * problem, int seed) {
  this->problem = problem;
  r = Random(seed);
  crossProb = DEFAULT_CROSS_PROB;
}

std::vector<DiffInd> DiffEvolution::getBestFound() {
  return getBestFound(DEFAULT_MAX_ITER, DEFAULT_POPULATION_NUMBER);
}

std::vector<DiffInd> DiffEvolution::getBestFound(int maxIteration, int populationNumber) {

  int iterations = 0;
  int genotypeSize = problem->getValidSize();
  DiffInd baseInd, addInd0, addInd1, newInd;
  std::vector<DiffInd> population = initPopulation(populationNumber);

  while (iterations < maxIteration) {
    for (int i = 0; i < populationNumber; i++) {
      do {
        baseInd = getRandomInd();
        addInd0 = getRandomInd();
        addInd1 = getRandomInd();
      } while (!areDiffrent(population[i], baseInd, addInd0, addInd1));

      newInd = DiffInd(0, new double[genotypeSize], genotypeSize);

      for (int geneOffset = 0; geneOffset < genotypeSize; geneOffset++) {
        if (r.generateDouble(0, 1) < DEFAULT_CROSS_PROB) {
          double newVal = 0;
          newVal = baseInd.getFromGenotype(geneOffset) + 1 * (addInd0.getFromGenotype(geneOffset) - addInd1.getFromGenotype(geneOffset));
          if (!isCorrectValue(newVal, geneOffset)) newVal = fixValue(newVal, geneOffset);
          newInd.setGenotypeAt(geneOffset, newVal); 
        }
        else {
          newInd.setGenotypeAt(geneOffset, population[i].getFromGenotype(geneOffset));
        }
      }
        newInd.setFitness(problem->getQuality(newInd.getGenotype(), genotypeSize));
		std::cout << population[i].getFitness() << " | " << newInd.getFitness() << std::endl;
        if (newInd.getFitness() >= population[i].getFitness()) {
                   
          population[i] = newInd;
        }
    }
    iterations++;
  }

  return population;

}

std::vector<DiffInd> DiffEvolution::initPopulation(int populationNumber) {
  std::vector<DiffInd> population(populationNumber);
  //RandomSearch rs = RandomSearch(problem);

  for (int i = 0; i < populationNumber; i++) {
    //MscnSolution sol = rs.findBestSolution(0, 1);
    double * tmpSol = problem->generateRandomSolution(0).toDouble();
    double tmpFit = problem->getQuality(tmpSol, problem->getValidSize());
    population[i] = DiffInd(tmpFit, tmpSol, problem->getValidSize());
  }

  return population;
  
}

bool DiffEvolution::areDiffrent(DiffInd &diff0, DiffInd &diff1, DiffInd &diff2, DiffInd &diff3) {
  return (diff0 != diff1 || diff0 != diff2 || diff0 != diff3);
}

bool DiffEvolution::isCorrectValue(double val, int index) {
  std::vector<MinMaxValues> tmp = problem->getAllMinMaxValues();
  if (tmp[index].min > val || tmp[index].max < val) return false;
  return true;
}

double DiffEvolution::fixValue(double val, int index) {
  std::vector<MinMaxValues> tmp = problem->getAllMinMaxValues();
  //if (tmp[index].min < val) return tmp[index].min;
  //else return tmp[index].min;
  return (tmp[index].min + tmp[index].max) / 2;
}

DiffInd DiffEvolution::getRandomInd() {
  int genotypeSize = problem->getValidSize();
  double * sol = problem->generateRandomSolution(0).toDouble();
  return DiffInd(problem->getQuality(sol, genotypeSize), sol, genotypeSize);
}
