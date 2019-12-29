#pragma once
#include "MscnSolution.h"
#include "DiffIndividual.h"
#include "CONST_H.h"

class DiffEvol {
public:

  DiffEvol();
  DiffEvol(MscnProblem * problem, int seed);
  DiffEvol(MscnProblem * problem) {
    this->problem = problem;
    r = Random();
    crossProb = r.generateDouble(0, 1);
  }
  ~DiffEvol() { delete problem; }
  void setProblem(MscnProblem *problem) { this->problem = problem; }
  DiffIndividual getBestFound(int maxIteration, int populationNumber) {

    int iterations = 0;
    int genotypeSize = problem->getValidSize();
    DiffIndividual baseInd, addInd0, addInd1, newInd;
    MscnSolution baseSol, addSol0, addSol1;
    std::vector<DiffIndividual> population = initPopulation(populationNumber);

    while (iterations <= maxIteration) {
      for (int i = 0; i < populationNumber; i++) {
        do { // TODO: cant assign value to sth here another time
          baseSol = problem->generateRandomSolution(); //TODO: let set seed?
          baseInd = DiffIndividual(problem->getQuality(baseSol.toDouble(), genotypeSize), baseSol.toDouble(), genotypeSize);
          addSol0 = problem->generateRandomSolution();
          addInd0 = DiffIndividual(problem->getQuality(addSol0.toDouble(), genotypeSize), addSol0.toDouble(), genotypeSize);
          addSol1 = problem->generateRandomSolution();
          addInd1 = DiffIndividual(problem->getQuality(addSol1.toDouble(), genotypeSize), addSol1.toDouble(), genotypeSize);
        } while (!areDiffrent(population[i], baseInd, addInd0, addInd1));

        newInd = DiffIndividual(problem->getQuality(baseSol.toDouble(), genotypeSize), baseSol.toDouble(), genotypeSize);

        for (int geneOffset = 0; geneOffset < genotypeSize; geneOffset++) {
          if (r.generateDouble(0, 1) < crossProb) {
            double newVal = baseInd.getGenotype()[geneOffset] + 1 * (addInd0.getGenotype()[geneOffset] + addInd1.getGenotype()[geneOffset]);
            newInd.setGenotypeAt(newVal, geneOffset);
          }
          else {
            newInd.setGenotypeAt(population[i].getGenotype()[geneOffset], geneOffset);
          }
          newInd.setFitness(problem->getQuality(newInd.getGenotype(), genotypeSize));
          if (newInd.getFitness() >= population[i].getFitness()) population[i] = newInd;
        }
      }
      iterations++;
    }

    int bestIndex = 0;

    for (int i = 0; i < populationNumber; i++) {
      if (population[i].getFitness() > population[bestIndex].getFitness()) bestIndex = i;
    }

    return population[bestIndex];

  }
  DiffIndividual getBestFound() {
    return getBestFound(DEFAULT_MAX_ITER, DEFAULT_POPULATION_NUMBER);
  }

private:

  Random r;
  double crossProb = 0;
  std::vector<DiffIndividual> initPopulation(int populationNumber) {
    RandomSearch rs(problem);
    std::vector<DiffIndividual> res(populationNumber);
    int arrSize = problem->getValidSize();

    for (int i = 0; i < populationNumber; i++) {
      double * tmpSol = rs.findBestSolution(0, 1).toDouble();
      double tmpQuality = problem->getQuality(tmpSol, arrSize);
      res[i] = DiffIndividual(tmpQuality, tmpSol, arrSize);
    }

    return res;

  }
  MscnProblem * problem;
  bool areDiffrent(DiffIndividual diff0, DiffIndividual diff1, DiffIndividual diff2, DiffIndividual diff3) {
    return (diff0 != diff1 || diff0 != diff2 || diff0 != diff3);
  }

};
