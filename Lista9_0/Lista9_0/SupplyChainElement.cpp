#include "SupplyChainElement.h"

SupplyChainElement::SupplyChainElement() {
	initialCost = 1;
	transportationCost = 0;
	oneTimeCost = 0;
	// TODO: constants
}

SupplyChainElement::SupplyChainElement(int initialCost, int transportationCost, int oneTimeCost) {
	this->initialCost = initialCost;
	this->transportationCost = transportationCost;
	this->oneTimeCost = oneTimeCost;
}

SupplyChainElement::~SupplyChainElement() {
	for (int i = 0; i < subjects.size(); i++) {
		delete subjects[i];
	}
}