#include "DiffEvolution.h"
#include "mscnProblem.h"
#include "RandomSearch.h"
#include "MinMaxValues.h"

DiffEvolution::DiffEvolution(std::vector<MinMaxValues> allMinMaxValues) {
	crossProb = DEFAULT_CROSS_PROB;
	diffWeigth = DIFF_WEIGTH;
  problem = new MscnProblem();
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;
  this->allMinMaxValues = allMinMaxValues;
	if (allMinMaxValues.size() != problem->getSize()) allMinMaxValues.resize(problem->getSize());

}

DiffEvolution::DiffEvolution(Problem * problem, double cp, double dw, std::vector<MinMaxValues> allMinMaxValues, int time) : Optimizer(problem, time) {

	this->allMinMaxValues = allMinMaxValues;

	if (allMinMaxValues.size() != problem->getSize()) allMinMaxValues.resize(problem->getSize());

	if (cp > 1 || cp <= 0) crossProb = DEFAULT_CROSS_PROB;
	else crossProb = cp;

	if (dw > 1 || dw <= 0) diffWeigth = DIFF_WEIGTH;
	else diffWeigth = dw;
	
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;

}

DiffEvolution::DiffEvolution(Problem * problem, int seed, double cp, double dw, std::vector<MinMaxValues> allMinMaxValues, int time) : Optimizer(problem, time) {

	this->allMinMaxValues = allMinMaxValues;

	if (allMinMaxValues.size() != problem->getSize()) allMinMaxValues.resize(problem->getSize());

	if (cp > 1 || cp <= 0) crossProb = DEFAULT_CROSS_PROB;
	else crossProb = cp;

	if (dw > 1 || dw <= 0) diffWeigth = DIFF_WEIGTH;
	else diffWeigth = dw;

  r = Random(seed);
  crossProb = DEFAULT_CROSS_PROB;
}

DiffInd * DiffEvolution::getBestFound() {
  return getBestFound(DEFAULT_TIME, DEFAULT_POPULATION_NUMBER);
}

DiffInd * DiffEvolution::getBestFound(int time, int populationNumber) {
	timer.setTime(time);
	return getBestFound(populationNumber);
}

DiffInd * DiffEvolution::getBestFound(int populationNumber) {

  int genotypeSize = problem->getSize();
  DiffInd baseInd, addInd0, addInd1, newInd;
  std::vector<DiffInd> population = initPopulation(populationNumber);

  timer.startTimer();

  do{
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
  } while (!timer.hasTimePassed());

  double bestSol = 0;
  DiffInd * bestInd = new DiffInd();

  for (int i = 0; i < population.size(); i++) {
	  if (population[i].getFitness() > bestSol) {
		  delete bestInd;
		  bestSol = population[i].getFitness();
		  bestInd = new DiffInd(population[i]);
	  }
  }

  return bestInd;

}

void DiffEvolution::setMinMaxValues(std::vector<MinMaxValues> allMinMaxValues){
	this->allMinMaxValues = allMinMaxValues;
}

double DiffEvolution::getBestScore(){
	return getBestFound()->getFitness();
}

double * DiffEvolution::solveProblem(Problem * problem){
	setProblem(problem);
	return getBestFound()->getGenotype();
}

std::vector<DiffInd> DiffEvolution::initPopulation(int populationNumber) {
  std::vector<DiffInd> population(populationNumber);
  //RandomSearch rs = RandomSearch(problem);

  for (int i = 0; i < populationNumber; i++) {
    //MscnSolution sol = rs.findBestSolution(0, 1);
	double * tmpSol = problem->generateRandSolution();
    double tmpFit = problem->getQuality(tmpSol, problem->getSize());
    population[i] = DiffInd(tmpFit, tmpSol, problem->getSize());

  }

  return population;
  
}

bool DiffEvolution::areDiffrent(DiffInd &diff0, DiffInd &diff1, DiffInd &diff2, DiffInd &diff3) {
  return (diff0 != diff1 || diff0 != diff2 || diff0 != diff3);
}

bool DiffEvolution::isCorrectValue(double val, int index) {
	MinMaxValues tmp = allMinMaxValues[index];
	
	//std::cout << "MIN: " << tmp.min << " | MAX: " << tmp.max << std::endl;
  if (tmp.min > val || tmp.max < val) return false;
  return true;
}

double DiffEvolution::fixValue(double val, int index) {
  MinMaxValues tmp = allMinMaxValues[index];
  //if (tmp.min < val) return tmp.min;
  //else return tmp.min;
  return (tmp.min + tmp.max) / 2;
}

DiffInd DiffEvolution::getRandomInd() {

	double * sol = problem->generateRandSolution();
	int genotypeSize = problem->getSize();

	return DiffInd(problem->getQuality(sol, genotypeSize), sol, genotypeSize);

}
