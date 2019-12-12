#include "MscnProblem.h"

MscnProblem::MscnProblem() {
	chainObjects = SupplyChainElementsContainer();
	setValues();
	packToVector();
}

MscnProblem::MscnProblem(int D, int F, int M, int S) {
	chainObjects = SupplyChainElementsContainer(D, F, M, S);
	setValues();
	packToVector();
}

void MscnProblem::setNumbersOfDistributors(int number) {
	chainObjects.changeNumberOfDistributors(number);
	setValuesToCDArray();
}

void setNumbersOfFactories(int number);
void setNumbersOfMagazines(int number);
void setNumbersOfStores(int number);

void MscnProblem::setValuesToCDArray() {

	int size = chainObjects.getNumberOfDistributors();
	cd = new double[size+1];
	cd[0] = size;

	for (int i = 1; i <= cd[0]; i++) {
		cd[i] = chainObjects.getDistributors()[i - 1].getInitialCost() * chainObjects.getDistributors()[i - 1].getTransportationCost();
	}
	std::cout << std::endl;
}

void MscnProblem::setValuesToCFArray() {

	int size = chainObjects.getNumberOfFactories();
	cf = new double[size + 1];
	cf[0] = size;

	for (int i = 1; i <= cf[0]; i++) {
		cf[i] = chainObjects.getFactories()[i-1].getInitialCost() * chainObjects.getFactories()[i - 1].getTransportationCost();
	}
	std::cout << std::endl;
}

void MscnProblem::setValuesToCMArray() {

	int size = chainObjects.getNumberOfMagazines();
	cm = new double[size + 1];
	cm[0] = size;

	for (int i = 1; i <= cm[0]; i++) {
		cm[i] = chainObjects.getMagazines()[i - 1].getInitialCost() * chainObjects.getMagazines()[i - 1].getTransportationCost();
	}
	std::cout << std::endl;
}

void MscnProblem::setValues() {
	setValuesToCDArray();
	setValuesToCFArray();
	setValuesToCMArray();
}

void MscnProblem::packToVector() {
	allElements.push_back(cd);
	allElements.push_back(cf);
	allElements.push_back(cm);
}

void MscnProblem::printAll() {

	for (int i = 0; i < allElements.size(); i++) {
		for (int j = 1; j <= allElements[i][0]; j++) {
			std::cout << allElements[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
