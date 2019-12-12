#pragma once
#include <vector>
#include "SupplyChainElement.h"

class SupplyChainElement {
private:

	double initialCost;
	double transportationCost;
	double oneTimeCost;

	int amountOfMaterial;

public:

	SupplyChainElement();
	SupplyChainElement(double initialCost, double transportationCost, double oneTimeCost, int amntOfMaterial);
	~SupplyChainElement();

	double getInitialCost() { return initialCost; }
	void setIntitialCost(double newVal) { initialCost = newVal; }
	double getTransportationCost() { return transportationCost; }
	void setTransportationCost(double newVal) { transportationCost = newVal; }
	double getOneTimeCost() { return oneTimeCost; }
	void setOneTimeCost(double newVal) { oneTimeCost = newVal; }

	void setValues(double init, double trans, double oneTime);
	void setDefaultValues();

	double overallCost() { return initialCost * transportationCost; }

};