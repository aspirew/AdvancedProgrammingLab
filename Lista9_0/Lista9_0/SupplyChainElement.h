#pragma once
#include <vector>
#include "SupplyChainElement.h"

class SupplyChainElement {
private:

	double initialCost;
	double transportationCost;
	double oneTimeCost;

	std::vector<SupplyChainElement *> subjects;


public:

	SupplyChainElement();
	SupplyChainElement(int initialCost, int transportationCost, int oneTimeCost);
	~SupplyChainElement();

	double getInitialCost() { return initialCost; }
	void setIntitialCost(double newVal) { initialCost = newVal; }
	double getTransportationCost() { return transportationCost; }
	void setTransportationCost(double newVal) { transportationCost = newVal; }
	double getOneTimeCost() { return oneTimeCost; }
	void setOneTimeCost(double newVal) { oneTimeCost = newVal; }

	double overallCost() { return initialCost * transportationCost; }

	void addSubject(SupplyChainElement *elem) {
		subjects.push_back(elem);
	}

	SupplyChainElement * getSubject(int elem) {
		return subjects[elem];
	}

};