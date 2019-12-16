#include "mscnProblem.h"
#include "MinMaxValues.h"

MscnProblem::MscnProblem() {
	initialize();
}

MscnProblem::MscnProblem(std::string fileName) {

	FILE * pFile;
	pFile = fopen(fileName.c_str(), "r+");

	if (pFile) {

		std::ifstream is(fileName);
		std::string dummyS;
		int fool;

		std::getline(is, dummyS, ' ');
		is >> d;
		std::getline(is, dummyS, ' ');
		is >> f;
		std::getline(is, dummyS, ' ');
		is >> m;
		std::getline(is, dummyS, ' ');
		is >> s;

		std::getline(is, dummyS, ' ');
		sd = deserializeVec<double>(is, d);
		std::getline(is, dummyS, ' ');
		sf = deserializeVec<double>(is, f);
		std::getline(is, dummyS, ' ');
		sm = deserializeVec<double>(is, m);
		std::getline(is, dummyS, ' ');
		ss = deserializeVec<double>(is, s);

		cd = new Matrix<double>(d, f, is);
		std::getline(is, dummyS, ' ');
		cf = new Matrix<double>(f, m, is);
		std::getline(is, dummyS, ' ');
		cm = new Matrix<double>(m, s, is);
		std::getline(is, dummyS, ' ');

		std::getline(is, dummyS, ' ');
		ud = deserializeVec<double>(is, d);
		std::getline(is, dummyS, ' ');
		uf = deserializeVec<double>(is, f);
		std::getline(is, dummyS, ' ');
		um = deserializeVec<double>(is, m);
		std::getline(is, dummyS, ' ');
		ps = deserializeVec<double>(is, s);

		is.close();

		fclose(pFile);
	}
	else initialize();

}

void MscnProblem::initialize() {
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
}

MscnProblem::~MscnProblem() {
	delete cd;
	delete cf;
	delete cm;
}

bool MscnProblem::setCountOfD(int val) {

	if (val < 1) return false;
	d = val;
	ud.resize(d);
	sd.resize(d);
	cd->resize(d, f);
	return true;
}

bool MscnProblem::setCountOfF(int val) {

	if (val < 1) return false;
	f = val;
	uf.resize(f);
	sf.resize(f);
	cd->resize(d, f);
	cf->resize(f, m);
	return true;
}

bool MscnProblem::setCountOfM(int val) {

	if (val < 1) return false;
	m = val;
	um.resize(m);
	sm.resize(m);
	cf->resize(f, m);
	cm->resize(m, s);
	return true;
}

bool MscnProblem::setCountOfS(int val) {

	if (val < 1) return false;
	s = val;
	ss.resize(s);
	ps.resize(s);
	cm->resize(m, s);
	return true;
}

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
	return 0;
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
		for (int j = 0; j < f; j++)
			xd->setElem(solution[i*d + j], i, j);

	for (int i = 0; i < f; i++)
		for (int j = 0; j < m; j++)
			xf->setElem(solution[d*f + i * f + j], i, j);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++)
			xm->setElem(solution[f*m + i * s + j], i, j);


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
	int fool, fool2;

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

int MscnProblem::checkIfSolutionIsValid(double *solution, int arrSize) {
	if (solution == NULL) return ERROR_SOLUTION_IS_NULL;
	if (arrSize != getValidSize()) return ERROR_WRONG_SIZE;
	for (int i = 0; i < arrSize; i++) {
		if (solution[i] < 0) return ERROR_NEGATIVE_VALUES;
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

	if (solutionErrorState != SOLUTION_VALID) return SOLUTION_NOT_VALID;

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

std::vector<MinMaxValues> MscnProblem::getMinMaxValues(std::vector<double> &constraint) {
	std::vector<MinMaxValues> res;

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++)
			res.push_back({ 0, constraint[i] });

	return res;
}

std::vector<MinMaxValues> MscnProblem::getXMMinMaxValues() {
	std::vector<MinMaxValues> res;

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++)
			res.push_back({ 0, std::max(sm[i], ss[i]) });

	return res;
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

	os << "cd \n";
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

	os << "xdminmax \n" << p.getMinMaxValues(p.sd) << "\n";
	os << "xfminmax \n" << p.getMinMaxValues(p.sf) << "\n";
	os << "xmminmax \n" << p.getXMMinMaxValues() << "\n";

	return os;
}

void MscnProblem::setRandomValues(int count) {
	srand(time(0));
	for (int i = 0; i < count; i++) {
		setInCd(rand() % 100, rand() % d, rand() % f);
		setInCf(rand() % 100, rand() % f, rand() % m);
		setInCm(rand() % 100, rand() % m, rand() % s);

		setInPs(rand() % 100, rand() % s);
		setInSd(rand() % 100, rand() % d);
		setInSf(rand() % 100, rand() % f);
		setInSm(rand() % 100, rand() % m);
		setInSs(rand() % 100, rand() % s);
		setInUd(rand() % 100, rand() % d);
		setInUf(rand() % 100, rand() % f);
		setInUm(rand() % 100, rand() % m);
	}
}

void MscnProblem::setRandomElementsCount(int maxDist) {
	srand(time(0));
	setCountOfD(rand() % maxDist);
	setCountOfF(rand() % maxDist*2);
	setCountOfM(rand() % maxDist*3);
	setCountOfS(rand() % maxDist*4);
}