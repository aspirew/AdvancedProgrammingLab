#include "DiffInd.h"

DiffInd::DiffInd() {
  genotypeSize = 1;
  fitness = 0;
  genotype = new double[genotypeSize];
}

DiffInd::DiffInd(double fitness, double * genotype, int genotypeSize) {
  this->genotypeSize = genotypeSize;
  this->fitness = fitness;
  this->genotype = genotype;
}

DiffInd::DiffInd(const DiffInd & other) {
  copyInd(other);
}

bool DiffInd::setGenotypeAt(int index, double val) {
  if (index < 0 || index >= genotypeSize) return false;

  genotype[index] = val;
  return true;
}

double DiffInd::getFromGenotype(int index) {
  if (index < 0 || index >= genotypeSize) return 0.0;
  return genotype[index];
}

double DiffInd::getFitness() {
  return fitness;
}

void DiffInd::setFitness(double fit) {
  fitness = fit;
}

void DiffInd::operator=(const DiffInd & other) {
  copyInd(other);
}

bool DiffInd::operator!=(const DiffInd & diff) {
    if (genotypeSize != diff.genotypeSize) return true;

    for (int i = 0; i < genotypeSize; i++) {
      if (genotype[i] != diff.genotype[i]) return true;
    }

    return false;
}

void DiffInd::copyInd(const DiffInd & other) {
  delete[] genotype;

  genotypeSize = other.genotypeSize;
  genotype = new double[genotypeSize];
  for (int i = 0; i < genotypeSize; i++) {
    genotype[i] = other.genotype[i];
  }
  fitness = other.fitness;
}
