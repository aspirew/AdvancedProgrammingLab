#include "MscnProblem.h"

MscnProblem::MscnProblem(int D, int F, int M, int S) {
	chainObjects = SupplyChainElementsContainer(D, F, M, S);
}
