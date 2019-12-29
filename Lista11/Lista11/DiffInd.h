#pragma once

class DiffInd {

public:

  DiffInd();
  DiffInd(double fitness, double * genotype, int genotypeSize);
  DiffInd(const DiffInd &other);
  ~DiffInd() { delete genotype; }

  bool setGenotypeAt(int index, double val);
  double getFromGenotype(int index);
  double getFitness();
  void setFitness(double fit);
  double * getGenotype() { return genotype; }

  void operator=(const DiffInd &other);
  bool operator!=(const DiffInd &diff);

private:

  int genotypeSize;
  double * genotype;
  double fitness;
  void copyInd(const DiffInd & other);

};
