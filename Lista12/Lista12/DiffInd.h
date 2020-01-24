#pragma once

template <typename T>
class DiffInd {

public:

  DiffInd();
  DiffInd(double fitness, T * genotype, int genotypeSize);
  DiffInd(const DiffInd &other);
  ~DiffInd() { delete genotype; }

  bool setGenotypeAt(int index, T val);
  T getFromGenotype(int index);
  double getFitness();
  void setFitness(double fit);
  T * getGenotype() { return genotype; }

  void operator=(const DiffInd<T> &other);
  bool operator!=(const DiffInd<T> &diff);

private:

  int genotypeSize;
  T * genotype;
  double fitness;
  void copyInd(const DiffInd<T> & other);

};
