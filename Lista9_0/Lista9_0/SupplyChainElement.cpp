#include "SupplyChainElement.h"

SupplyChainElement::SupplyChainElement() {
	setDefaultValues();
	amountOfMaterial = 0;
}

SupplyChainElement::SupplyChainElement(double initialCost, double transportationCost, double oneTimeCost, int amntOfMaterial) {
	setValues(initialCost, transportationCost, oneTimeCost);
	amountOfMaterial = amntOfMaterial;
}

SupplyChainElement::~SupplyChainElement() {

}

void SupplyChainElement::setValues(double init, double trans, double oneTime) {
	setIntitialCost(init);
	setTransportationCost(trans);
	setOneTimeCost(oneTime);
}

void SupplyChainElement::setDefaultValues() {
	setValues(30, 2, 3); // TODO: constants
}