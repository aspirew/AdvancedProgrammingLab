#include "SupplyChainElementsContainer.h"

SupplyChainElementsContainer::SupplyChainElementsContainer() {
	setAllChains(2, 3, 4, 5); // TODO: constants
}

SupplyChainElementsContainer::SupplyChainElementsContainer(int D, int F, int M, int S) {
	setAllChains(D, F, M, S);
}

void SupplyChainElementsContainer::setAllChains(int D, int F, int M, int S) {
	distributors = new SupplyChainElement[D]; // TODO: setValues
	factories = new SupplyChainElement[F];
	magazines = new SupplyChainElement[M];
	stores = new SupplyChainElement[S];
	// TODO: destruktor
}