#include "DiffEvolution.h"
#include "mscnProblem.h"
#include "RandomSearch.h"
#include "MinMaxValues.h"

DiffEvolution::DiffEvolution() {
	crossProb = DEFAULT_CROSS_PROB;
	diffWeigth = DIFF_WEIGTH;
  problem = new MscnProblem();
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;
}

DiffEvolution::DiffEvolution(MscnProblem * problem, double cp, double dw) {
	
	if (cp > 1 || cp <= 0) crossProb = DEFAULT_CROSS_PROB;
	else crossProb = cp;

	if (dw > 1 || dw <= 0) diffWeigth = DIFF_WEIGTH;
	else diffWeigth = dw;
	
  this->problem = problem;
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;
}

DiffEvolution::DiffEvolution(MscnProblem * problem, int seed, double cp, double dw) {

	if (cp > 1 || cp <= 0) crossProb = DEFAULT_CROSS_PROB;
	else crossProb = cp;

	if (dw > 1 || dw <= 0) diffWeigth = DIFF_WEIGTH;
	else diffWeigth = dw;

  this->problem = problem;
  r = Random(seed);
  crossProb = DEFAULT_CROSS_PROB;
}

DiffInd DiffEvolution::getBestFound() {
  return getBestFound(DEFAULT_MAX_ITER, DEFAULT_POPULATION_NUMBER);
}

DiffInd DiffEvolution::getBestFound(int maxIteration, int populationNumber) {

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
		  if (r.generateDouble(0, 1) < crossProb) {
			  double newVal = 0;
			  newVal = baseInd.getFromGenotype(geneOffset) + diffWeigth * (addInd0.getFromGenotype(geneOffset) - addInd1.getFromGenotype(geneOffset));
			  if (!isCorrectValue(newVal, geneOffset)) newVal = fixValue(newVal, geneOffset);
			  newInd.setGenotypeAt(geneOffset, newVal);
		  }	  
		  else {
			  newInd.setGenotypeAt(geneOffset, population[i].getFromGenotype(geneOffset));
		  }
	  }
        newInd.setFitness(problem->getQuality(newInd.getGenotype(), genotypeSize));
		//std::cout << problem->constraintsSatisfied(newInd.getGenotype(), genotypeSize);
		//std::cout << population[i].getFitness() << " | " << newInd.getFitness() << std::endl;
        if (newInd.getFitness() >= population[i].getFitness()) {    
          population[i] = newInd;
        }
    }
	iterations++;
  }

  double bestSol = 0;
  DiffInd bestInd;

  for (int i = 0; i < population.size(); i++) {
	  if (population[i].getFitness() > bestSol) {
		  bestSol = population[i].getFitness();
		  bestInd = population[i];
	  }
  }

  return bestInd;

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
	MinMaxValues tmp = problem->getMinMaxValueBy1DimIndex(index);
	
	//std::cout << "MIN: " << tmp.min << " | MAX: " << tmp.max << std::endl;
  if (tmp.min > val || tmp.max < val) return false;
  return true;
}

double DiffEvolution::fixValue(double val, int index) {
  MinMaxValues tmp = problem->getMinMaxValueBy1DimIndex(index);
  //if (tmp.min < val) return tmp.min;
  //else return tmp.min;
  return (tmp.min + tmp.max) / 2;
}

DiffInd DiffEvolution::getRandomInd() {

	bool constraints = true;
	double * sol = new double[0];
	int genotypeSize = problem->getValidSize();
	do {
		delete sol;
		sol = problem->generateRandomSolution(0).toDouble();
		constraints = problem->constraintsSatisfied(sol, genotypeSize);
	} while (problem->getSolutionErrorState() != SOLUTION_VALID || !constraints);

  return DiffInd(problem->getQuality(sol, genotypeSize), sol, genotypeSize);
}
