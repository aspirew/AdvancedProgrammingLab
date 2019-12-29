#pragma once
#include <vector>
#include "MscnSolution.h"
#include "mscnProblem.h"

class DiffIndividual {
public:

  DiffIndividual() { }
  DiffIndividual(double fitness, double * genotype, int genotypeSize) {
    this->fitness = fitness;
    this->genotype = new double[genotypeSize];
    this->genotypeSize = genotypeSize;
    for (int i = 0; i < genotypeSize; i++) {
      this->genotype[i] = genotype[i];
    }
  }
  ~DiffIndividual() { delete genotype; }
  double getFitness() { return fitness; }
  void setFitness(double value) { fitness = value; }

  double * getGenotype() { return genotype; }
  void setGenotype(double *gen) { genotype = gen; }
  void setGenotypeAt(double value, int offset) { genotype[offset] = value; }
  int getGenotypeSize() { return genotypeSize; }

  bool operator!=(const DiffIndividual &diff) {

    if (genotypeSize != diff.genotypeSize) return true;

    for (int i = 0; i < genotypeSize; i++) {
      if (genotype[i] != diff.genotype[i]) return true;
    }

    std::cout << "XDDDDD";

    return false;
  }

private:
  int genotypeSize;
  double * genotype;
  double fitness;
};
