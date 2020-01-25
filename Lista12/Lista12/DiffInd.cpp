#include "DiffInd.h"

template <typename T>
DiffInd<T>::DiffInd() {
  genotypeSize = 1;
  fitness = 0;
  genotype = new T[genotypeSize];
}

template <typename T>
DiffInd<T>::DiffInd(double fitness, T * genotype, int genotypeSize) {
  this->genotypeSize = genotypeSize;
  this->fitness = fitness;
  this->genotype = genotype;
}

template <typename T>
DiffInd<T>::DiffInd(const DiffInd & other) {
  copyInd(other);
}

template <typename T>
bool DiffInd<T>::setGenotypeAt(int index, T val) {
  if (index < 0 || index >= genotypeSize) return false;

  genotype[index] = val;
  return true;
}

template <typename T>
T DiffInd<T>::getFromGenotype(int index) {
  if (index < 0 || index >= genotypeSize) return 0.0;
  return genotype[index];
}

template <typename T>
double DiffInd<T>::getFitness() {
  return fitness;
}

template <typename T>
void DiffInd<T>::setFitness(double fit) {
  fitness = fit;
}

template <typename T>
void DiffInd<T>::operator=(const DiffInd<T> & other) {
  copyInd(other);
}

template <typename T>
bool DiffInd<T>::operator!=(const DiffInd<T> & diff) {
    if (genotypeSize != diff.genotypeSize) return true;

    for (int i = 0; i < genotypeSize; i++) {
      if (genotype[i] != diff.genotype[i]) return true;
    }

    return false;
}

template <typename T>
void DiffInd<T>::copyInd(const DiffInd<T> & other) {
  delete[] genotype;

  genotypeSize = other.genotypeSize;
  genotype = new T[genotypeSize];
  for (int i = 0; i < genotypeSize; i++) {
    genotype[i] = other.genotype[i];
  }
  fitness = other.fitness;
}
