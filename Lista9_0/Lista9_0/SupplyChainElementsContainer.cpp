#include "SupplyChainElementsContainer.h"

SupplyChainElementsContainer::SupplyChainElementsContainer() {
	setAllChains(2, 3, 4, 5); // TODO: constants
}

SupplyChainElementsContainer::SupplyChainElementsContainer(int D, int F, int M, int S) {
	setAllChains(D, F, M, S);
}

void SupplyChainElementsContainer::setAllChains(int D, int F, int M, int S) {
	distributors = new SupplyChainElement[D];
	numberOfDistributors = D;
	factories = new SupplyChainElement[F];
	numberOfFactories = F;
	magazines = new SupplyChainElement[M];
	numberOfMagazines = M;
	stores = new SupplyChainElement[S];
	numberOfStores = S;
	// TODO: destruktor
}

void SupplyChainElementsContainer::changeNumberOfElementsInLayer(SupplyChainElement &elem, int currentSize, int newSize) {
	SupplyChainElement * tmpTable;

	int smallerNumber = (newSize < currentSize) ? newSize : currentSize;
	tmpTable = new SupplyChainElement[newSize];

	for (int i = 0; i < smallerNumber; i++) {
		tmpTable[i] = elem[i];
	}

	elem = tmpTable;

	delete tmpTable;
}

void SupplyChainElementsContainer::setValues(SupplyChainElement &elem, double initVal, double transVal, double oneTimeVal){
	elem.setIntitialCost(initVal);
	elem.setTransportationCost(transVal);
	elem.setOneTimeCost(oneTimeVal);
}

void SupplyChainElementsContainer::setDefaultValues(SupplyChainElement &elem) {
	setValues(elem, 0, 0, 0); //TODO: constants
}

void SupplyChainElementsContainer::setDefaultValuesToLayer(SupplyChainElement *elem, int size) {
	for (int i = 0; i < size; i++) {
		setDefaultValues(*elem);
	}
}

void SupplyChainElementsContainer::setDefaultValuesToAll() {
	setDefaultValuesToLayer(distributors, numberOfDistributors);
	setDefaultValuesToLayer(factories, numberOfFactories);
	setDefaultValuesToLayer(magazines, numberOfMagazines);
	setDefaultValuesToLayer(stores, numberOfStores);
}