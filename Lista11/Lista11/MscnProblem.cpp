#include "mscnProblem.h"
#include "CONST_H.h"
#include <ctime>
#include <cstdlib>
#include "Random.cpp"

MscnProblem::MscnProblem() {

	d = D_COUNT;
	f = F_COUNT;
	m = M_COUNT;
	s = S_COUNT;

	cd = new Matrix<double>(d, f);
	cf = new Matrix<double>(f, m);
	cm = new Matrix<double>(m, s);

	ud.resize(d);
	uf.resize(f);
	um.resize(m);
	sd.resize(d);
	sf.resize(f);
	sm.resize(m);
	ss.resize(s);
	ps.resize(s);

	minmaxxd = new Matrix<MinMaxValues>(d, f);
	minmaxxf = new Matrix<MinMaxValues>(f, m);
	minmaxxm = new Matrix<MinMaxValues>(m, s);

}

MscnProblem::MscnProblem(std::string fileName) {

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
		sd = deserializeVec<double>(is, d);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		sf = deserializeVec<double>(is, f);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		sm = deserializeVec<double>(is, m);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		ss = deserializeVec<double>(is, s);
		is.ignore(256, ' ');
		is.ignore(256, ' ');

		cd = new Matrix<double>(d, f, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		cf = new Matrix<double>(f, m, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		cm = new Matrix<double>(m, s, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');

		ud = deserializeVec<double>(is, d);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		uf = deserializeVec<double>(is, f);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		um = deserializeVec<double>(is, m);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		ps = deserializeVec<double>(is, s);

		is.ignore(256, ' ');
		is.ignore(256, ' ');

		minmaxxd = new Matrix<MinMaxValues>(d, f, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		minmaxxf = new Matrix<MinMaxValues>(f, m, is);
		is.ignore(256, ' ');
		is.ignore(256, ' ');
		minmaxxm = new Matrix<MinMaxValues>(m, s, is);

		is.close();
	}

	rnd = Random();
	rnd.setSeedFromTxt(SEED_FILE_NAME);

	fclose(pFile);
}

MscnProblem::~MscnProblem() {
	delete cd;
	delete cf;
	delete cm;
	delete minmaxxd;
	delete minmaxxf;
	delete minmaxxm;
}

bool MscnProblem::setCountOfD(int val) {

	if (val < 1) return false;
	d = val;
	ud.resize(d);
	sd.resize(d);
	cd->resize(d, f);
	minmaxxd->resize(d, f);
	return true;
}

bool MscnProblem::setCountOfF(int val) {

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

bool MscnProblem::setCountOfM(int val) {

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

bool MscnProblem::setCountOfS(int val) {

	if (val < 1) return false;
	s = val;
	ss.resize(s);
	ps.resize(s);
	cm->resize(m, s);
	minmaxxm->resize(m, s);
	return true;
}

bool MscnProblem::setInCd(double val, int y, int x) { return cd->setElem(val, y, x); }
bool MscnProblem::setInCf(double val, int y, int x) { return cf->setElem(val, y, x); }
bool MscnProblem::setInCm(double val, int y, int x) { return cm->setElem(val, y, x); }

double MscnProblem::getFromCd(int y, int x) { return cd->getElem(y, x); }
double MscnProblem::getFromCf(int y, int x) { return cf->getElem(y, x); }
double MscnProblem::getFromCm(int y, int x) { return cm->getElem(y, x); }


bool MscnProblem::setInUd(double val, int x) { return setInVectorOfDoubles(val, x, ud); }
bool MscnProblem::setInUf(double val, int x) { return setInVectorOfDoubles(val, x, uf); }
bool MscnProblem::setInUm(double val, int x) { return setInVectorOfDoubles(val, x, um); }
bool MscnProblem::setInSd(double val, int x) { return setInVectorOfDoubles(val, x, sd); }
bool MscnProblem::setInSf(double val, int x) { return setInVectorOfDoubles(val, x, sf); }
bool MscnProblem::setInSm(double val, int x) { return setInVectorOfDoubles(val, x, sm); }
bool MscnProblem::setInSs(double val, int x) { return setInVectorOfDoubles(val, x, ss); }
bool MscnProblem::setInPs(double val, int x) { return setInVectorOfDoubles(val, x, ps); }

double MscnProblem::getFromUd(int x) { return getFromVectorOfDoubles(x, ud); }
double MscnProblem::getFromUf(int x) { return getFromVectorOfDoubles(x, uf); }
double MscnProblem::getFromUm(int x) { return getFromVectorOfDoubles(x, um); }
double MscnProblem::getFromSd(int x) { return getFromVectorOfDoubles(x, sd); }
double MscnProblem::getFromSf(int x) { return getFromVectorOfDoubles(x, sf); }
double MscnProblem::getFromSm(int x) { return getFromVectorOfDoubles(x, sm); }
double MscnProblem::getFromSs(int x) { return getFromVectorOfDoubles(x, ss); }
double MscnProblem::getFromPs(int x) { return getFromVectorOfDoubles(x, ps); }


bool MscnProblem::setInVectorOfDoubles(double val, int x, std::vector<double> &vector) {
	if (x < 0 || x >= vector.size()) return false;
	vector[x] = val;
	return true;
}

double MscnProblem::getFromVectorOfDoubles(int x, std::vector<double> &vector) {
	if (x < 0 || x >= vector.size())
		return vector[x];
}

bool MscnProblem::setInVectorOfInts(int val, int x, std::vector<int> &vector) {
	if (x < 0 || x >= vector.size()) return false;
	vector[x] = val;
	return true;
}

double MscnProblem::getFromVectorOfInts(int x, std::vector<int> &vector) {
	if (x < 0 || x >= vector.size())
		return vector[x];
}

double MscnProblem::getKT(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm) {

	double result = 0;


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

double MscnProblem::getKU(Matrix<double> *xd, Matrix<double> *xf, Matrix<double> *xm) {
	double result = 0;

	for (int i = 0; i < d; i++) {
		double KUDF = 0;
		for (int j = 0; j < f; j++) {
			KUDF += xd->getElem(i, j);
		}
		result += eps(KUDF) * ud[i];
	}

	for (int i = 0; i < f; i++) {
		double KUFM = 0;
		for (int j = 0; j < m; j++) {
			KUFM += xf->getElem(i, j);
		}
		result += eps(KUFM) * uf[i];
	}

	for (int i = 0; i < m; i++) {
		double KUMS = 0;
		for (int j = 0; j < s; j++) {
			KUMS += xm->getElem(i, j);
		}
		result += eps(KUMS) * um[i];
	}

	return result;
}

int MscnProblem::eps(double x) {
	if (x > 0) return 1;
	else return 0;
}

void MscnProblem::generateMatrix(int width, int heigth, Matrix<MinMaxValues> * minmax, Matrix<double> * x){

	for (int i = 0; i < width; i++)
		for (int j = 0; j < heigth; j++) {
			x->setElem(rnd.generateDouble(minmax->getElem(i, j).min, minmax->getElem(i, j).max), i, j);
		}
}

double MscnProblem::getP(Matrix<double> *xm) {
	double result = 0;

	for (int i = 0; i < m; i++) 
		for (int j = 0; j < s; j++) 
			result += xm->getElem(i, j) * ps[j];

	return result;
}

MscnSolution MscnProblem::getSolution(double *solution) {

	Matrix<double> * xd = new Matrix<double>(d, f);
	Matrix<double> * xf = new Matrix<double>(f, m);
	Matrix<double> * xm = new Matrix<double>(m, s);

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

	return MscnSolution(xd, xf, xm);
}

MscnSolution MscnProblem::generateRandomSolution(int seed){

	Matrix<double> * xd = new Matrix<double>(d, f);
	Matrix<double> * xf = new Matrix<double>(f, m);
	Matrix<double> * xm = new Matrix<double>(m, s);

  if (seed != 0)
    if (rnd.setSeed(seed)) return MscnSolution(xd, xf, xm);

	generateMatrix(d, f, minmaxxd, xd);
	generateMatrix(f, m, minmaxxf, xf);
	generateMatrix(m, s, minmaxxm, xm);

	//for (int i = 0; i < d; i++)
	//	for (int j = 0; j < f; j++) {
	//		xd->setElem(rnd.generateDouble(minmaxxd->getElem(i, j).min, minmaxxd->getElem(i, j).max), i, j);
	//	}

	//for (int i = 0; i < f; i++)
	//	for (int j = 0; j < m; j++) {
	//		xf->setElem(rnd.generateDouble(minmaxxf->getElem(i, j).min, minmaxxf->getElem(i, j).max), i, j);
	//	}

	//for (int i = 0; i < m; i++)
	//	for (int j = 0; j < s; j++) {
	//		xm->setElem(rnd.generateDouble(minmaxxm->getElem(i, j).min, minmaxxm->getElem(i, j).max), i, j);
	//	}

	return MscnSolution(xd, xf, xm);

}

MscnSolution MscnProblem::getSolutionFromTxt(std::string fileName){

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "r+");

	if (!pFile) return MscnSolution();

	std::ifstream is(pFile);

	Matrix<double> * xd = new Matrix<double>(d, f);
	Matrix<double> * xf = new Matrix<double>(f, m);
	Matrix<double> * xm = new Matrix<double>(m, s);

	std::string foo;

	std::getline(is, foo);
	std::getline(is, foo);
	std::getline(is, foo);
	std::getline(is, foo);
	std::getline(is, foo, ' ');

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++) {
			double result;
			is >> result;
			xd->setElem(result, i, j);
		}

	std::getline(is, foo, ' ');
	std::getline(is, foo, ' ');

	for (int i = 0; i < f; i++)
		for (int j = 0; j < m; j++) {
			double result;
			is >> result;
			xf->setElem(result, i, j);
		}

	std::getline(is, foo, ' ');
	std::getline(is, foo, ' ');

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++) {
			double result;
			is >> result;
			xm->setElem(result, i, j);
		}

	is.close();
	fclose(pFile);

	return MscnSolution(xd, xf, xm);
}

double MscnProblem::getProfit(MscnSolution sol) {

	return getP(sol.xm) - getKT(sol.xd, sol.xf, sol.xm) - getKU(sol.xd, sol.xf, sol.xm);
}

int MscnProblem::checkIfSolutionIsValid(double *solution, int arrSize) {
	if (solution == NULL) return ERROR_SOLUTION_IS_NULL;
	if (arrSize != getValidSize()) return ERROR_WRONG_SIZE;
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

double MscnProblem::getQuality(double *solution, int arrSize){

	solutionErrorState = checkIfSolutionIsValid(solution, arrSize);

	if (solutionErrorState != SOLUTION_VALID) return SOLUTION_NOT_VALID;

	MscnSolution sol = getSolution(solution);

	return getP(sol.xm) - getKT(sol.xd, sol.xf, sol.xm) - getKU(sol.xd, sol.xf, sol.xm);

}

double MscnProblem::constraintsSatisfied(double *solution, int arrSize) {

	solutionErrorState = checkIfSolutionIsValid(solution, arrSize);

	if (solutionErrorState != SOLUTION_VALID) return CONSTRAINTS_NOT_SATISFIED;

	MscnSolution sol = getSolution(solution);

	return constraintsCheck(sol);
}

bool MscnProblem::constraintsCheck(MscnSolution &sol) {

	for (int i = 0; i < d; i++) {
		if (sol.xd->sumOneRow(i) > sd[i]) return CONSTRAINTS_NOT_SATISFIED;
	}

	for (int i = 0; i < f; i++) {
		if (sol.xf->sumOneRow(i) > sf[i]) return CONSTRAINTS_NOT_SATISFIED;
	}

	for (int i = 0; i < m; i++) {
		if (sol.xm->sumOneRow(i) > sm[i]) return CONSTRAINTS_NOT_SATISFIED;
	}

	for (int i = 0; i < s; i++) {
		if (sol.xm->sumOneCol(i) > ss[i]) return CONSTRAINTS_NOT_SATISFIED;
	}

	for (int i = 0; i < f; i++) {
		if (sol.xd->sumOneCol(i) < sol.xf->sumOneRow(i)) return CONSTRAINTS_NOT_SATISFIED;
	}

	for (int i = 0; i < m; i++) {
		if (sol.xf->sumOneCol(i) < sol.xm->sumOneRow(i)) return CONSTRAINTS_NOT_SATISFIED;
	}

	return CONSTRAINTS_SATISFIED;

}


bool MscnProblem::saveData(std::string const &path) {

	FILE * pFile;
	pFile = fopen(path.c_str(), "w+");

	if (!pFile) return false;

	std::ofstream file(pFile);
	file << *this;
	file.close();

	return true;
}

bool MscnProblem::saveSolution(double * solution, std::string const &path) {

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

std::ostream& operator<<(std::ostream &os, MscnProblem &p){

	os << "D " << p.d << "\n" << "F " << p.f << "\n";
	os << "M " << p.m << "\n" << "S " << p.s << "\n";
	os << "sd \n" << p.sd << "\n";
	os << "sf \n" << p.sf << "\n";
	os << "sm \n" << p.sm << "\n";
	os << "ss \n" << p.ss << "\n";

	os << "cd \n";
	for (int i = 0; i < p.cd->getHeigth(); i++) {
		for (int j = 0; j < p.cd->getWidth(); j++) {
			os << p.cd->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "cf \n";
	for (int i = 0; i < p.cf->getHeigth(); i++) {
		for (int j = 0; j < p.cf->getWidth(); j++) {
			os << p.cf->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "cm \n";
	for (int i = 0; i < p.cm->getHeigth(); i++) {
		for (int j = 0; j < p.cm->getWidth(); j++) {
			os << p.cm->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "ud \n" << p.ud << "\n";
	os << "uf \n" << p.uf << "\n";
	os << "um \n" << p.um << "\n";

	os << "p \n" << p.ps << "\n";

	os << "minmaxxd \n";
	for (int i = 0; i < p.minmaxxd->getHeigth(); i++) {
		for (int j = 0; j < p.minmaxxd->getWidth(); j++) {
			os << p.minmaxxd->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "minmaxxf \n";
	for (int i = 0; i < p.minmaxxf->getHeigth(); i++) {
		for (int j = 0; j < p.minmaxxf->getWidth(); j++) {
			os << p.minmaxxf->getElem(i, j) << " ";
		}
		os << "\n";
	}

	os << "minmaxxm \n";
	for (int i = 0; i < p.minmaxxm->getHeigth(); i++) {
		for (int j = 0; j < p.minmaxxm->getWidth(); j++) {
			os << p.minmaxxm->getElem(i, j) << " ";
		}
		os << "\n";
	}

	return os;
}

void MscnProblem::generateInstance(int instanceSeed) {

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

std::vector<MinMaxValues> MscnProblem::getAllMinMaxValues() {

  std::vector<MinMaxValues> res;
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

MinMaxValues MscnProblem::getMinMaxValueBy1DimIndex(int index){

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

void MscnProblem::setRandomElementsCount(int maxDist) {
	setCountOfD(rnd.generateInt(1, maxDist));
	setCountOfF(rnd.generateInt(1, maxDist*2));
	setCountOfM(rnd.generateInt(1, maxDist*3));
	setCountOfS(rnd.generateInt(1, maxDist*4));
}

void MscnProblem::setRandomMinMaxValues(int maxMin){
	double min = 0;
	double max = 0;

	double minBound = 0;
	double minBoundForXF = 0;
	double minBoundForXD = 0;

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
