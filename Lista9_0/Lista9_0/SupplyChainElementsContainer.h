#pragma once
#include "SupplyChainElement.h"

class SupplyChainElementsContainer {

public:

	SupplyChainElementsContainer();
	SupplyChainElementsContainer(int D, int F, int M, int S);

	void setAllChains(int D, int F, int M, int S);

protected:

	SupplyChainElement * distributors;
	SupplyChainElement * factories;
	SupplyChainElement * magazines;
	SupplyChainElement * stores;

};