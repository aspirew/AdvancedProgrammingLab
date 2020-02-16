#include "DiffEvolution.h"
#include "mscnProblem.h"
#include "RandomSearch.h"
#include "MinMaxValues.h"

template <typename T>
DiffEvolution<T>::DiffEvolution(std::vector<MinMaxValues<T>> allMinMaxValues) : Optimizer<T>() {
	crossProb = DEFAULT_CROSS_PROB;
	diffWeigth = DIFF_WEIGTH;
  this->problem = new MscnProblem<T>();
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;
  this->allMinMaxValues = allMinMaxValues;
	if (allMinMaxValues.size() != this->problem->getSize()) allMinMaxValues.resize(this->problem->getSize());

}

template <typename T>
DiffEvolution<T>::DiffEvolution(Problem<T> * problem, double cp, T dw, std::vector<MinMaxValues<T>> allMinMaxValues, int time) : Optimizer<T>(problem, time) {

	this->allMinMaxValues = allMinMaxValues;

	if (allMinMaxValues.size() != problem->getSize()) allMinMaxValues.resize(problem->getSize());

	if (cp > 1 || cp <= 0) crossProb = DEFAULT_CROSS_PROB;
	else crossProb = cp;

	if (dw > 1 || dw <= 0) diffWeigth = DIFF_WEIGTH;
	else diffWeigth = dw;
	
  r = Random();
  crossProb = DEFAULT_CROSS_PROB;

}

template <typename T>
DiffEvolution<T>::DiffEvolution(Problem<T> * problem, int seed, double cp, T dw, std::vector<MinMaxValues<T>> allMinMaxValues, int time) : Optimizer<T>(problem, time) {

	this->allMinMaxValues = allMinMaxValues;

	if (allMinMaxValues.size() != problem->getSize()) allMinMaxValues.resize(problem->getSize());

	if (cp > 1 || cp <= 0) crossProb = DEFAULT_CROSS_PROB;
	else crossProb = cp;

	if (dw > 1 || dw <= 0) diffWeigth = DIFF_WEIGTH;
	else diffWeigth = dw;

  r = Random(seed);
  crossProb = DEFAULT_CROSS_PROB;
}

template <typename T>
DiffInd<T> * DiffEvolution<T>::getBestFound() {
	return getBestFound(DEFAULT_POPULATION_NUMBER);
}

template <typename T>
DiffInd<T> * DiffEvolution<T>::getBestFound(int time, int populationNumber) {
	this->timer.setTime(time);
	return getBestFound(populationNumber);
}

template <typename T>
DiffInd<T> * DiffEvolution<T>::getBestFound(int populationNumber) { 

  int genotypeSize = this->problem->getSize();
  DiffInd<T> baseInd, addInd0, addInd1, newInd;
  std::vector<DiffInd<T>> population = initPopulation(populationNumber);

  this->timer.startTimer();

  do{
    for (int i = 0; i < populationNumber; i++) {
      do {
        baseInd = getRandomInd();
        addInd0 = getRandomInd();
        addInd1 = getRandomInd();
      } while (!areDiffrent(population[i], baseInd, addInd0, addInd1));

      newInd = DiffInd<T>(0, new T[genotypeSize], genotypeSize);

	  for (int geneOffset = 0; geneOffset < genotypeSize; geneOffset++) {
		  if (r.generateDouble(0, 1) < crossProb) {
			  T newVal = 0;
			  newVal = baseInd.getFromGenotype(geneOffset) + diffWeigth * (addInd0.getFromGenotype(geneOffset) - addInd1.getFromGenotype(geneOffset));
			  if (!isCorrectValue(newVal, geneOffset)) newVal = fixValue(newVal, geneOffset);
			  newInd.setGenotypeAt(geneOffset, newVal);
		  }
		  else {
			  newInd.setGenotypeAt(geneOffset, population[i].getFromGenotype(geneOffset));
		  }
	  }
		 newInd.setFitness(this->problem->getQuality(newInd.getGenotype(), genotypeSize));
		//std::cout << problem->constraintsSatisfied(newInd.getGenotype(), genotypeSize);
		//std::cout << population[i].getFitness() << " | " << newInd.getFitness() << std::endl;
        if (newInd.getFitness() >= population[i].getFitness()) {    
          population[i] = newInd;
        }
    }
	//std::cout << "1";
  } while (!this->timer.hasTimePassed());

  double bestSol = 0;
  DiffInd<T> * bestInd = new DiffInd<T>();

  for (int i = 0; i < population.size(); i++) {
	  if (population[i].getFitness() > bestSol) {
		  delete bestInd;
		  bestSol = population[i].getFitness();
		  bestInd = new DiffInd<T>(population[i]);
	  }
  }

  return bestInd;

}

template <typename T>
void DiffEvolution<T>::setMinMaxValues(std::vector<MinMaxValues<T>> allMinMaxValues){
	this->allMinMaxValues = allMinMaxValues;
}

template <typename T>
double DiffEvolution<T>::getBestScore(){
	return getBestFound()->getFitness();
}

template <typename T>
T * DiffEvolution<T>::solveProblem(Problem<T> * problem){
	this->setProblem(problem);
	return getBestFound()->getGenotype();
}

template <typename T>
std::vector<DiffInd<T>> DiffEvolution<T>::initPopulation(int populationNumber) {
  std::vector<DiffInd<T>> population(populationNumber);
  //RandomSearch rs = RandomSearch(problem);
  for (int i = 0; i < populationNumber; i++) {
    //MscnSolution sol = rs.findBestSolution(0, 1);
	T * tmpSol = this->problem->generateRandSolution();
    double tmpFit = this->problem->getQuality(tmpSol, this->problem->getSize());
    population[i] = DiffInd<T>(tmpFit, tmpSol, this->problem->getSize());
  }

  return population;
  
}

template <typename T>
bool DiffEvolution<T>::areDiffrent(DiffInd<T> &diff0, DiffInd<T> &diff1, DiffInd<T> &diff2, DiffInd<T> &diff3) {
  return (diff0 != diff1 || diff0 != diff2 || diff0 != diff3);
}

template <typename T>
bool DiffEvolution<T>::isCorrectValue(T val, int index) {
	MinMaxValues<T> tmp = allMinMaxValues[index];
	
	//std::cout << "MIN: " << tmp.min << " | MAX: " << tmp.max << std::endl;
  if (tmp.min > val || tmp.max < val) return false;
  return true;
}

template <typename T>
double DiffEvolution<T>::fixValue(T val, int index) {
  MinMaxValues<T> tmp = allMinMaxValues[index];
  //if (tmp.min < val) return tmp.min;
  //else return tmp.min;
  return (tmp.min + tmp.max) / 2;
}

template <typename T>
DiffInd<T> DiffEvolution<T>::getRandomInd() {

	T * sol = this->problem->generateRandSolution();
	int genotypeSize = this->problem->getSize();

	return DiffInd<T>(this->problem->getQuality(sol, genotypeSize), sol, genotypeSize);

}
