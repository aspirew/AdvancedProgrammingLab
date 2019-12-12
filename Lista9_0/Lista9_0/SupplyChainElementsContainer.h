#pragma once
#include "SupplyChainElement.h"

class SupplyChainElementsContainer {

public:

	SupplyChainElementsContainer();
	SupplyChainElementsContainer(int D, int F, int M, int S);

	void setAllChains(int D, int F, int M, int S);
	void setValues(SupplyChainElement &elem, double initVal, double transVal, double oneTimeVal);
	void setDefaultValues(SupplyChainElement &elem);
	void setDefaultValuesToLayer(SupplyChainElement *elem, int size);
	void setDefaultValuesToAll();

	void changeNumberOfDistributors(int newSize) { changeNumberOfElementsInLayer(*distributors, numberOfDistributors, newSize); }
	void changeNumberOfFactories(int newSize) { changeNumberOfElementsInLayer(*factories, numberOfDistributors, newSize); }
	void changeNumberOfMagazines(int newSize) { changeNumberOfElementsInLayer(*magazines, numberOfDistributors, newSize); }
	void changeNumberOfStores(int newSize) { changeNumberOfElementsInLayer(*stores, numberOfDistributors, newSize); }

	void changeNumberOfElementsInLayer(SupplyChainElement &elem, int currentSize, int newSize);

	void createObject();
	void createObjects();

	int getNumberOfDistributors() { return numberOfDistributors; }
	int getNumberOfFactories() { return numberOfFactories; }
	int getNumberOfMagazines() { return numberOfMagazines; }
	int getNumberOfStores() { return numberOfStores; }

	SupplyChainElement * getDistributors() { return distributors; }
	SupplyChainElement * getFactories() { return factories; }
	SupplyChainElement * getMagazines() { return magazines; }
	SupplyChainElement * getStores() { return stores; }

private:

	SupplyChainElement * distributors;
	SupplyChainElement * factories;
	SupplyChainElement * magazines;
	SupplyChainElement * stores;

	int numberOfDistributors;
	int numberOfFactories;
	int numberOfMagazines;
	int numberOfStores;

};