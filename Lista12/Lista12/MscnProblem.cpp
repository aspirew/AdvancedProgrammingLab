#include "mscnProblem.h"
#include "CONST_H.h"
#include <ctime>
#include <cstdlib>
#include "Random.cpp"

template <typename T>
MscnProblem<T>::MscnProblem() : Problem<T>() {

	d = D_COUNT;
	f = F_COUNT;
	m = M_COUNT;
	s = S_COUNT;

	cd = new Matrix<T>(d, f);
	cf = new Matrix<T>(f, m);
	cm = new Matrix<T>(m, s);

	ud.resize(d);
	uf.resize(f);
	um.resize(m);
	sd.resize(d);
	sf.resize(f);
	sm.resize(m);
	ss.resize(s);
	ps.resize(s);

	minmaxxd = new Matrix<MinMaxValues<T>>(d, f);
	minmaxxf = new Matrix<MinMaxValues<T>>(f, m);
	minmaxxm = new Matrix<MinMaxValues<T>>(m, s);

}

template <typename T>
MscnProblem<T>::MscnProblem(std::string fileName) : Problem<T>() {

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "r+");

	if (pFile) {

		std::ifstream is(fileName);
		
		is.ignore(256, ' ');
		is >> d;
		is.ignore(256, ' ');
		is >> f;
		is.ignore(256, ' ');
		is >> m;
		is.ignore(256, ' ');
		is >> s;

		is.ignore(256, ' ');
		sd = deserializeVec<T>(is, d);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		sf = deserializeVec<T>(is, f);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		sm = deserializeVec<T>(is, m);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		ss = deserializeVec<T>(is, s);
		is.ignore(256, ' ');
		is.ignore(256, ' ');

		cd = new Matrix<T>(d, f, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		cf = new Matrix<T>(f, m, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		cm = new Matrix<T>(m, s, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');

		ud = deserializeVec<T>(is, d);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		uf = deserializeVec<T>(is, f);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		um = deserializeVec<T>(is, m);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		ps = deserializeVec<T>(is, s);

		is.ignore(256, ' ');
		is.ignore(256, ' ');

		minmaxxd = new Matrix<MinMaxValues<T>>(d, f, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		minmaxxf = new Matrix<MinMaxValues<T>>(f, m, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		minmaxxm = new Matrix<MinMaxValues<T>>(m, s, is);

		is.close();
	}

	rnd = Random();
	rnd.setSeedFromTxt(SEED_FILE_NAME);

	fclose(pFile);
}

template <typename T>
MscnProblem<T>::~MscnProblem() {
	delete cd;
	delete cf;
	delete cm;
	delete minmaxxd;
	delete minmaxxf;
	delete minmaxxm;
}

template <typename T>
bool MscnProblem<T>::setCountOfD(int val) {

	if (val < 1) return false;
	d = val;
	ud.resize(d);
	sd.resize(d);
	cd->resize(d, f);
	minmaxxd->resize(d, f);
	return true;
}

template <typename T>
bool MscnProblem<T>::setCountOfF(int val) {

	if (val < 1) return false;
	f = val;
	uf.resize(f);
	sf.resize(f);
	cd->resize(d, f);
	minmaxxd->resize(d, f);
	cf->resize(f, m);
	minmaxxf->resize(f, m);
	return true;
}

template <typename T>
bool MscnProblem<T>::setCountOfM(int val) {

	if (val < 1) return false;
	m = val;
	um.resize(m);
	sm.resize(m);
	cf->resize(f, m);
	minmaxxf->resize(f, m);
	cm->resize(m, s);
	minmaxxm->resize(m, s);
	return true;
}

template <typename T>
bool MscnProblem<T>::setCountOfS(int val) {

	if (val < 1) return false;
	s = val;
	ss.resize(s);
	ps.resize(s);
	cm->resize(m, s);
	minmaxxm->resize(m, s);
	return true;
}

template <typename T>
bool MscnProblem<T>::setInCd(T val, int y, int x) { return cd->setElem(val, y, x); }
template <typename T>
bool MscnProblem<T>::setInCf(T val, int y, int x) { return cf->setElem(val, y, x); }
template <typename T>
bool MscnProblem<T>::setInCm(T val, int y, int x) { return cm->setElem(val, y, x); }

template <typename T>
T MscnProblem<T>::getFromCd(int y, int x) { return cd->getElem(y, x); }
template <typename T>
T MscnProblem<T>::getFromCf(int y, int x) { return cf->getElem(y, x); }
template <typename T>
T MscnProblem<T>::getFromCm(int y, int x) { return cm->getElem(y, x); }

template <typename T>
bool MscnProblem<T>::setInUd(T val, int x) { return setInVector(val, x, ud); }
template <typename T>
bool MscnProblem<T>::setInUf(T val, int x) { return setInVector(val, x, uf); }
template <typename T>
bool MscnProblem<T>::setInUm(T val, int x) { return setInVector(val, x, um); }
template <typename T>
bool MscnProblem<T>::setInSd(T val, int x) { return setInVector(val, x, sd); }
template <typename T>
bool MscnProblem<T>::setInSf(T val, int x) { return setInVector(val, x, sf); }
template <typename T>
bool MscnProblem<T>::setInSm(T val, int x) { return setInVector(val, x, sm); }
template <typename T>
bool MscnProblem<T>::setInSs(T val, int x) { return setInVector(val, x, ss); }
template <typename T>
bool MscnProblem<T>::setInPs(T val, int x) { return setInVector(val, x, ps); }

template <typename T>
T MscnProblem<T>::getFromUd(int x) { return getFromVector(x, ud); }
template <typename T>
T MscnProblem<T>::getFromUf(int x) { return getFromVector(x, uf); }
template <typename T>
T MscnProblem<T>::getFromUm(int x) { return getFromVector(x, um); }
template <typename T>
T MscnProblem<T>::getFromSd(int x) { return getFromVector(x, sd); }
template <typename T>
T MscnProblem<T>::getFromSf(int x) { return getFromVector(x, sf); }
template <typename T>
T MscnProblem<T>::getFromSm(int x) { return getFromVector(x, sm); }
template <typename T>
T MscnProblem<T>::getFromSs(int x) { return getFromVector(x, ss); }
template <typename T>
T MscnProblem<T>::getFromPs(int x) { return getFromVector(x, ps); }


template <typename T>
bool MscnProblem<T>::setInVector(T val, int x, std::vector<T> &vector) {
	if (x < 0 || x >= vector.size()) return false;
	vector[x] = val;
	return true;
}

template <typename T>
T MscnProblem<T>::getFromVector(int x, std::vector<T> &vector) {
	if (x < 0 || x >= vector.size())
		return vector[x];
}

template <typename T>
T MscnProblem<T>::getKT(Matrix<T> *xd, Matrix<T> *xf, Matrix<T> *xm) {

	T result = 0;

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++)
			result += cd->getElem(i, j) * xd->getElem(i, j);

	for (int i = 0; i < f; i++)
		for (int j = 0; j < m; j++)
			result += cf->getElem(i, j) * xf->getElem(i, j);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++)
			result += cm->getElem(i, j) * xm->getElem(i, j);

	return result;
}

template <typename T>
T MscnProblem<T>::getKU(Matrix<T> *xd, Matrix<T> *xf, Matrix<T> *xm) {
	T result = 0;

	for (int i = 0; i < d; i++) {
		T KUDF = 0;
		for (int j = 0; j < f; j++) {
			KUDF += xd->getElem(i, j);
		}
		result += eps(KUDF) * ud[i];
	}

	for (int i = 0; i < f; i++) {
		T KUFM = 0;
		for (int j = 0; j < m; j++) {
			KUFM += xf->getElem(i, j);
		}
		result += eps(KUFM) * uf[i];
	}

	for (int i = 0; i < m; i++) {
		T KUMS = 0;
		for (int j = 0; j < s; j++) {
			KUMS += xm->getElem(i, j);
		}
		result += eps(KUMS) * um[i];
	}

	return result;
}

template <typename T>
int MscnProblem<T>::eps(T x) {
	if (x > 0) return 1;
	else return 0;
}

template <typename T>
void MscnProblem<T>::generateMatrix(int width, int heigth, Matrix<MinMaxValues<T>> * minmax, Matrix<T> * x){

	if (this->isTemplateDouble()) {
		for (int i = 0; i < width; i++)
			for (int j = 0; j < heigth; j++) {
				x->setElem(rnd.generateDouble(minmax->getElem(i, j).min, minmax->getElem(i, j).max), i, j);
			}
	}
	else {
		for (int i = 0; i < width; i++)
			for (int j = 0; j < heigth; j++) {
				x->setElem(rnd.generateInt(minmax->getElem(i, j).min, minmax->getElem(i, j).max), i, j);
			}
	}
}

template <typename T>
void MscnProblem<T>::decrementValuesInX(int size, Matrix<T> * x, std::vector<T> * s, Matrix<MinMaxValues<T>> * minmax){
	for (int i = 0; i < size; i++) {
		int overflow = x->sumOneRow(i) - s->at(i);
		for (int j = 0; j < overflow; j++) {
			int newVal = x->getElem(i, j%size) - 1;
			if (newVal >= minmax->getElem(i, j%size).min) x->setElem(newVal, i, j%size);
			else overflow++;
		}
	}
}

template <typename T>
void MscnProblem<T>::fixColumnsAndRowsSumIssue(int sizeOfChild, int sizeOfGrandChild, Matrix<T> * parentX, Matrix<T> * childX, Matrix<MinMaxValues<T>> * parentMinMax, Matrix<MinMaxValues<T>> * childMinMax) {
	for (int i = 0; i < sizeOfChild; i++) {
		T overflow = childX->sumOneRow(i) - parentX->sumOneCol(i);
		bool full = false;
		while (overflow > 0 && !full) {
			T curOverflow = overflow;
			for (int j = 0; j < sizeOfChild; j++) {
				T newValForXd = parentX->getElem(j, i) + 1;
				if (newValForXd <= parentMinMax->getElem(j, i).max) {
					parentX->setElem(newValForXd, j, i);
					overflow--;
				}
				else {
					parentX->setElem(parentMinMax->getElem(j, i).max, j, i);
					overflow - parentMinMax->getElem(i, j).max;
				}
			}
			if (curOverflow == overflow) full = true;
		}

		overflow = childX->sumOneRow(i) - parentX->sumOneCol(i);
		full = false;
		while (overflow > 0 && !full) {
			T curOverflow = overflow;
			for (int j = 0; j < sizeOfGrandChild; j++) {
				T newValForXf = childX->getElem(i, j) - 1;
				if (newValForXf >= childMinMax->getElem(i, j).min) {
					childX->setElem(newValForXf, i, j);
					overflow--;
				}
				else {
					childX->setElem(childMinMax->getElem(j, i).min, j, i);
					overflow -= childMinMax->getElem(j, i).min;
				}
			}
			if (curOverflow == overflow) full = true;
		}
		if (overflow > 0) {
			std::cout << "Nie mozna zbudowac dobrego rozwiazania";
			exit(1);
		}
	}
}

template <typename T>
T MscnProblem<T>::getP(Matrix<T> *xm) {
	T result = 0;

	for (int i = 0; i < m; i++) 
		for (int j = 0; j < s; j++) 
			result += xm->getElem(i, j) * ps[j];

	return result;
}

template <typename T>
MscnSolution<T> MscnProblem<T>::getSolution(T *solution) {

	Matrix<T> * xd = new Matrix<T>(d, f);
	Matrix<T> * xf = new Matrix<T>(f, m);
	Matrix<T> * xm = new Matrix<T>(m, s);

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++) {
			xd->setElem(solution[i*f + j], i, j);
		}

	for (int i = 0; i < f; i++)
		for (int j = 0; j < m; j++) {
			xf->setElem(solution[d*f + i * m + j], i, j);
		}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++) {
			xm->setElem(solution[d*f + f * m + i * s + j], i, j);
		}

	return MscnSolution<T>(xd, xf, xm);
}

template <typename T>
MscnSolution<T> MscnProblem<T>::generateRandomSolution(int seed){

	Matrix<T> * xd = new Matrix<T>(d, f);
	Matrix<T> * xf = new Matrix<T>(f, m);
	Matrix<T> * xm = new Matrix<T>(m, s);

  if (seed != 0)
    if (rnd.setSeed(seed)) return MscnSolution<T>(xd, xf, xm);

	generateMatrix(d, f, minmaxxd, xd);
	generateMatrix(f, m, minmaxxf, xf);
	generateMatrix(m, s, minmaxxm, xm);

	return MscnSolution<T>(xd, xf, xm);

}

template <typename T>
MscnSolution<T> MscnProblem<T>::getSolutionFromTxt(std::string fileName){

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "r+");

	if (!pFile) return MscnSolution<T>();

	std::ifstream is(pFile);

	Matrix<T> * xd = new Matrix<T>(d, f);
	Matrix<T> * xf = new Matrix<T>(f, m);
	Matrix<T> * xm = new Matrix<T>(m, s);

	std::string foo;

	std::getline(is, foo);
	std::getline(is, foo);
	std::getline(is, foo);
	std::getline(is, foo);
	std::getline(is, foo, ' ');

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++) {
			T result;
			is >> result;
			xd->setElem(result, i, j);
		}

	std::getline(is, foo, ' ');
	std::getline(is, foo, ' ');

	for (int i = 0; i < f; i++)
		for (int j = 0; j < m; j++) {
			T result;
			is >> result;
			xf->setElem(result, i, j);
		}

	std::getline(is, foo, ' ');
	std::getline(is, foo, ' ');

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++) {
			T result;
			is >> result;
			xm->setElem(result, i, j);
		}

	is.close();
	fclose(pFile);

	return MscnSolution<T>(xd, xf, xm);
}

template <typename T>
double MscnProblem<T>::getProfit(MscnSolution<T> sol) {

	return getP(sol.xm) - getKT(sol.xd, sol.xf, sol.xm) - getKU(sol.xd, sol.xf, sol.xm);
}

template <typename T>
int MscnProblem<T>::checkIfSolutionIsValid(T *solution, int arrSize) {
	if (solution == NULL) return ERROR_SOLUTION_IS_NULL;
	if (arrSize != getSize()) return ERROR_WRONG_SIZE;
	for (int i = 0; i < arrSize; i++) {
		if (solution[i] < 0) return ERROR_NEGATIVE_VALUES;
	}

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < f; j++) {
			if (solution[i*f + j] < minmaxxd->getElem(i, j).min) return ERROR_NUMBER_TOO_SMALL;
			if (solution[i*f + j] > minmaxxd->getElem(i, j).max) return ERROR_NUMBER_TOO_BIG;
		}
	}

	for (int i = 0; i < f; i++) {
		for (int j = 0; j < m; j++) {
			if (solution[d*f + i*m + j] < minmaxxf->getElem(i, j).min) return ERROR_NUMBER_TOO_SMALL;
			if (solution[d*f + i*m + j] > minmaxxf->getElem(i, j).max) return ERROR_NUMBER_TOO_BIG;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < s; j++) {
			if (solution[d*f + f*m + i*s + j] < minmaxxm->getElem(i, j).min) return ERROR_NUMBER_TOO_SMALL;
			if (solution[d*f + f*m + i*s + j] > minmaxxm->getElem(i, j).max) return ERROR_NUMBER_TOO_BIG;
		}
	}

	return SOLUTION_VALID;
}

template <typename T>
void MscnProblem<T>::fixSolutionForConstraints(MscnSolution<T> * sol, int err){

	if (err == CONSTRAINTS_TOO_MUCH_FROM_DISTRIBUTOR) decrementValuesInX(d, sol->xd, &sd, minmaxxd);

	if (err == CONSTRAINTS_TOO_MUCH_FROM_FACTORY) decrementValuesInX(f, sol->xf, &sf, minmaxxf);

	if (err == CONSTRAINTS_TOO_MUCH_FROM_MAGAZINE) decrementValuesInX(m, sol->xm, &sm, minmaxxm);

	if(err == CONSTRAINTS_TOO_MUCH_FOR_STORE) decrementValuesInX(m, sol->xm, &ss, minmaxxm);

	//(sol.xd->sumOneCol(i) < sol.xf->sumOneRow(i))

	if (err == CONSTRAINTS_NOT_ENOUGH_MATERIALS_FOR_FACTORIES) fixColumnsAndRowsSumIssue(f, m, sol->xd, sol->xf, minmaxxd, minmaxxf);

	if (err == CONSTRAINTS_NOT_ENOUGH_MATERIALS_FOR_FACTORIES) {
		for (int i = 0; i < f; i++) {
			bool full = false;
			T overflow = sol->xf->sumOneRow(i) - sol->xd->sumOneCol(i);
			//std::cout << overflow;
			for (int j = 0; j < overflow; j++) {
				T newValForXf = sol->xf->getElem(i, j%m) - 1;
				T newValForXd = sol->xd->getElem(j%f, i) + 1;
				//std::cout << j % m << " : " << sol->xf->getElem(i, j%m) << " | " << minmaxxf->getElem(i, j%m).min << " ... ";
				if (newValForXd <= minmaxxd->getElem(j%f, i).max) {
					sol->xd->setElem(newValForXd, j%f, i);
					full = false;
				}
				else if (newValForXf >= minmaxxf->getElem(i, j%m).min) {
					sol->xf->setElem(newValForXf, i, j%m);
					full = false;
					//std::cout << j % m << " : " << sol->xf->getElem(i, j%m) << " | " << minmaxxf->getElem(i, j%m).min << std::endl;
				}
				else if (!full) {
					overflow++;
					if (j%m == 0) full = true;
				}
			}
		}
	}

	if (err == CONSTRAINTS_NOT_ENOUGH_PRODUCTS_FOR_MAGAZINES) {
		for (int i = 0; i < m; i++) {
			bool full = false;
			T overflow = sol->xm->sumOneRow(i) - sol->xf->sumOneCol(i);
			for (int j = 0; j < overflow; j++) {
				T newValForXf = sol->xf->getElem(j%m, i) + 1;
				T newValForXm = sol->xm->getElem(i, j%s) - 1;
				if (newValForXm >= minmaxxm->getElem(i, j%s).min) {
					sol->xm->setElem(newValForXm, i, j%s);
					full = false;
				}
				else if (newValForXf <= minmaxxf->getElem(j%m, i).max) {
					sol->xf->setElem(newValForXf, j%m, i);
					full = false;
				}
				else if (!full) {
					overflow++;
					if (j%m == 0) full = true;
				}
			}
		}
	}



}

template<typename T>
void MscnProblem<T>::genInstInt()
{

	for (int i = 0; i < d; i++) {
		setInSd(rnd.generateInt(RAND_S_MIN, RAND_S_MAX), i);
		setInUd(rnd.generateInt(RAND_U_MIN, RAND_U_MAX), i);
		for (int j = 0; j < f; j++) {
			setInCd(rnd.generateInt(RAND_C_MIN, RAND_C_MAX), i, j);
		}
	}

	for (int i = 0; i < f; i++) {
		setInSf(rnd.generateInt(RAND_S_MIN, RAND_S_MAX), i);
		setInUf(rnd.generateInt(RAND_U_MIN, RAND_U_MAX), i);
		for (int j = 0; j < m; j++) {
			setInCf(rnd.generateInt(RAND_C_MIN, RAND_C_MAX), i, j);
		}
	}

	for (int i = 0; i < m; i++) {
		setInSm(rnd.generateInt(RAND_S_MIN, RAND_S_MAX), i);
		setInUm(rnd.generateInt(RAND_U_MIN, RAND_U_MAX), i);
		for (int j = 0; j < s; j++) {
			setInCm(rnd.generateInt(RAND_C_MIN, RAND_C_MAX), i, j);
		}
	}

	for (int i = 0; i < s; i++) {
		setInPs(rnd.generateInt(RAND_P_MIN, RAND_P_MAX), i);
		setInSs(rnd.generateInt(RAND_S_MIN, RAND_S_MAX), i);
	}
}

template <typename T>
void MscnProblem<T>::fixSolution(T * solution, int arrSize){

	std::vector<MinMaxValues<T>> minmax = getAllMinMaxValues();

	std::cout << " , " <<  solutionErrorState;

	if (solutionErrorState == ERROR_SOLUTION_IS_NULL) {
		solution = new T[arrSize]();
		for (int i = 0; i < arrSize; i++) {
			solution[i] = (minmax[i].min + minmax[i].max) / 2;
		}
	}

	if (solutionErrorState == ERROR_WRONG_SIZE) {
		T * tmpSol = new T[getSize()];
		int smaller = getSize() < arrSize ? getSize() : arrSize;
		for (int i = 0; i < smaller; i++) {
			tmpSol[i] = solution[i];
		}

		if (arrSize < smaller) {
			for (int i = arrSize; i < smaller; i++) {
				tmpSol[i] = (minmax[i].min + minmax[i].max) / 2;
			}
		}	
		delete solution;
		solution = tmpSol;
	}

	if (solutionErrorState == ERROR_NEGATIVE_VALUES) {
		for (int i = 0; i < arrSize; i++) {
			if(solution[i] < 0) solution[i] *= -1;
		}
	}

	if (solutionErrorState == ERROR_NUMBER_TOO_SMALL || solutionErrorState == ERROR_NUMBER_TOO_BIG) {
		for (int i = 0; i < arrSize; i++) {
			solution[i] = (minmax[i].min + minmax[i].max) / 2;
		}
	}

	if (checkIfSolutionIsValid(solution, arrSize) != SOLUTION_VALID) fixSolution(solution, arrSize);

}

template <typename T>
double MscnProblem<T>::getQuality(T *solution, int arrSize){

	solutionErrorState = checkIfSolutionIsValid(solution, arrSize);

	if (solutionErrorState != SOLUTION_VALID) fixSolution(solution, arrSize);

	MscnSolution<T> sol = getSolution(solution);

	if (constraintsCheck(sol) != CONSTRAINTS_OK) fixSolutionForConstraints(&sol, constraintsCheck(sol));

	return getP(sol.xm) - getKT(sol.xd, sol.xf, sol.xm) - getKU(sol.xd, sol.xf, sol.xm);

}

template <typename T>
int MscnProblem<T>::constraintsSatisfied(T *solution, int arrSize) {

	solutionErrorState = checkIfSolutionIsValid(solution, arrSize);

	if (solutionErrorState != SOLUTION_VALID) fixSolution(solution, arrSize);

	MscnSolution<T> sol = getSolution(solution);

	return constraintsCheck(sol);
}

template <typename T>
int MscnProblem<T>::constraintsCheck(MscnSolution<T> &sol) {

	for (int i = 0; i < d; i++) {
		if (sol.xd->sumOneRow(i) > sd[i]) return CONSTRAINTS_TOO_MUCH_FROM_DISTRIBUTOR;
	}

	for (int i = 0; i < f; i++) {
		if (sol.xf->sumOneRow(i) > sf[i]) return CONSTRAINTS_TOO_MUCH_FROM_FACTORY;
	}

	for (int i = 0; i < m; i++) {
		if (sol.xm->sumOneRow(i) > sm[i]) return CONSTRAINTS_TOO_MUCH_FROM_MAGAZINE;
	}

	for (int i = 0; i < s; i++) {
		if (sol.xm->sumOneCol(i) > ss[i]) return CONSTRAINTS_TOO_MUCH_FOR_STORE;
	}

	for (int i = 0; i < f; i++) {
		if (sol.xd->sumOneCol(i) < sol.xf->sumOneRow(i)) return CONSTRAINTS_NOT_ENOUGH_MATERIALS_FOR_FACTORIES;
	}

	for (int i = 0; i < m; i++) {
		if (sol.xf->sumOneCol(i) < sol.xm->sumOneRow(i)) return CONSTRAINTS_NOT_ENOUGH_PRODUCTS_FOR_MAGAZINES;
	}

	return CONSTRAINTS_OK;

}

template <typename T>
bool MscnProblem<T>::saveData(std::string const &path) {

	FILE * pFile;
	pFile = fopen(path.c_str(), "w+");

	if (!pFile) return false;

	std::ofstream file(pFile);
	file << *this;
	file.close();

	return true;
}

template <typename T>
bool MscnProblem<T>::saveSolution(T * solution, std::string const &path) {

	FILE * pFile;
	pFile = fopen(path.c_str(), "w+");

	if (!pFile) return false;

	std::ofstream file(pFile);
	file << "D " << d << "\n";
	file << "F " << f << "\n";
	file << "M " << m << "\n";
	file << "S " << s << "\n";
	file << getSolution(solution);

	fclose(pFile);

	return true;
}

template <>
void MscnProblem<double>::generateInstance(int instanceSeed) {

	if (instanceSeed != 0) {
		rnd.setSeed(instanceSeed);
	}
	for (int i = 0; i < d; i++) {
		setInSd(rnd.generateDouble(RAND_S_MIN, RAND_S_MAX), i);
		setInUd(rnd.generateDouble(RAND_U_MIN, RAND_U_MAX), i);
		for (int j = 0; j < f; j++) {
			setInCd(rnd.generateDouble(RAND_C_MIN, RAND_C_MAX), i, j);
		}
	}

	for (int i = 0; i < f; i++) {
		setInSf(rnd.generateDouble(RAND_S_MIN, RAND_S_MAX), i);
		setInUf(rnd.generateDouble(RAND_U_MIN, RAND_U_MAX), i);
		for (int j = 0; j < m; j++) {
			setInCf(rnd.generateDouble(RAND_C_MIN, RAND_C_MAX), i, j);
		}
	}

	for (int i = 0; i < m; i++) {
		setInSm(rnd.generateDouble(RAND_S_MIN, RAND_S_MAX), i);
		setInUm(rnd.generateDouble(RAND_U_MIN, RAND_U_MAX), i);
		for (int j = 0; j < s; j++) {
			setInCm(rnd.generateDouble(RAND_C_MIN, RAND_C_MAX), i, j);
		}
	}

	for (int i = 0; i < s; i++) {
		setInPs(rnd.generateDouble(RAND_P_MIN, RAND_P_MAX), i);
		setInSs(rnd.generateDouble(RAND_S_MIN, RAND_S_MAX), i);
	}
}

template <>
void MscnProblem<MyInt>::generateInstance(int instanceSeed) {
	if (instanceSeed != 0) {
		rnd.setSeed(instanceSeed);
	}
	genInstInt();
}

template <>
void MscnProblem<int>::generateInstance(int instanceSeed) {

	if (instanceSeed != 0) {
		rnd.setSeed(instanceSeed);
	}
	genInstInt();

}

template <typename T>
std::vector<MinMaxValues<T>> MscnProblem<T>::getAllMinMaxValues() {

  std::vector<MinMaxValues<T>> res;
  int iterator = 0;

  for (int i = 0; i < d; i++) {
    for (int j = 0; j < f; j++) {
      res.push_back(minmaxxd->getElem(i, j));
    }
  }

  for (int i = 0; i < f; i++) {
    for (int j = 0; j < m; j++) {
      res.push_back(minmaxxf->getElem(i, j));
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < s; j++) {
      res.push_back(minmaxxm->getElem(i, j));
    }
  }

  return res;
}

template <typename T>
MinMaxValues<T> MscnProblem<T>::getMinMaxValueBy1DimIndex(int index){

	if (index >= d*f + f * m) {
		index -= d * f + f * m;
		return minmaxxm->getElemByOneDimIndex(index);
	}
	else if (index >= d*f) {
		index -= d * f;
		return minmaxxf->getElemByOneDimIndex(index);
	}
	else return minmaxxd->getElemByOneDimIndex(index);
}

template <typename T>
void MscnProblem<T>::setRandomElementsCount(int maxDist) {
	setCountOfD(rnd.generateInt(1, maxDist));
	setCountOfF(rnd.generateInt(1, maxDist*2));
	setCountOfM(rnd.generateInt(1, maxDist*3));
	setCountOfS(rnd.generateInt(1, maxDist*4));
}

template <typename T>
void MscnProblem<T>::setCorrectRandomMinMaxValues(int maxMin){
	T min = 0;
	T max = 0;

	T minBound = 0;
	T minBoundForXF = 0;
	T minBoundForXD = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < s; j++) {
			min = rnd.generateDouble(0, maxMin/2);
			max = rnd.generateDouble(maxMin/2, maxMin);
			minBound += max;
			minmaxxm->setElem({ min, max }, i, j);
		}
		if (minBoundForXF <= minBound) minBoundForXF = minBound;
		minBound = 0;
	}

	minBoundForXF /= f;
	minBound = 0;

	for (int i = 0; i < f; i++) {
		for (int j = 0; j < m; j++) {
			min = rnd.generateDouble(minBoundForXF, minBoundForXF+maxMin/2);
			max = rnd.generateDouble(minBoundForXF + maxMin / 2, minBoundForXF + maxMin);
			minBound += max;
			minmaxxf->setElem({ min, max }, i, j);
		}
		if (minBoundForXD <= minBound) minBoundForXD = minBound;
		minBound = 0;
	}

	minBoundForXD /= d;

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < f; j++) {
			min = rnd.generateDouble(minBoundForXD, minBoundForXD + maxMin / 2);
			max = rnd.generateDouble(minBoundForXD + maxMin / 2, minBoundForXD + maxMin);
			minmaxxd->setElem({ min, max }, i, j);
		}
	}

}

template <>
void MscnProblem<double>::setRandomMinMaxValues(int maxDist){

	double min = 0;
	double max = 0;

	auto assignValues = [&](int width, int heigth, int iteration, Matrix<MinMaxValues<double>> * minmax)
	{
		for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				min = rnd.generateDouble(iteration*maxDist, (iteration + 1)*maxDist);
				max = rnd.generateDouble((iteration + 1)*maxDist, (iteration + 2)*maxDist);
				minmax->setElem({ min, max }, i, j);
			}
		}
	};

	assignValues(s, m, 0, minmaxxm);
	assignValues(m, f, 1, minmaxxf);
	assignValues(f, d, 2, minmaxxd);

}

template <>
void MscnProblem<int>::setRandomMinMaxValues(int maxDist) {

	int min = 0;
	int max = 0;

	auto assignValues = [&](int width, int heigth, int iteration, Matrix<MinMaxValues<int>> * minmax)
	{
		for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				min = rnd.generateInt(iteration*maxDist, (iteration + 1)*maxDist);
				max = rnd.generateInt((iteration + 1)*maxDist, (iteration + 2)*maxDist);
				minmax->setElem({ min, max }, i, j);
			}
		}
	};

	assignValues(s, m, 0, minmaxxm);
	assignValues(m, f, 1, minmaxxf);
	assignValues(f, d, 2, minmaxxd);

}

template <>
void MscnProblem<MyInt>::setRandomMinMaxValues(int maxDist) {

	MyInt min = 0;
	MyInt max = 0;

	auto assignValues = [&](int width, int heigth, int iteration, Matrix<MinMaxValues<MyInt>> * minmax)
	{
		for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				min = rnd.generateInt(iteration*maxDist, (iteration + 1)*maxDist);
				max = rnd.generateInt((iteration + 1)*maxDist, (iteration + 2)*maxDist);
				minmax->setElem({ min, max }, i, j);
			}
		}
	};

	assignValues(s, m, 0, minmaxxm);
	assignValues(m, f, 1, minmaxxf);
	assignValues(f, d, 2, minmaxxd);

}
