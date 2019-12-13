#include "mscnProblem.h"
#include "CONST_H.h"

struct MsncSolution {
	Matrix<double> xd;
	Matrix<double> xf;
	Matrix<double> xm;
};

MscnProblem::MscnProblem() {

	d = D_COUNT;
	f = F_COUNT;
	m = M_COUNT;
	s = S_COUNT;

	cd = Matrix<double>(d, f);
	cf = Matrix<double>(f, m);
	cm = Matrix<double>(m, s);

	ud.resize(d);
	uf.resize(f);
	um.resize(m);
	sd.resize(d);
	sf.resize(f);
	sm.resize(m);
	ss.resize(s);
	ps.resize(s);

}

bool MscnProblem::setCountOfD(int val) {

	if (val < 1) return false;
	d = val;
	ud.resize(d);
	sd.resize(d);
	cd.resize(d, f);
	return true;
}

bool MscnProblem::setCountOfF(int val) {

	if (val < 1) return false;
	f = val;
	uf.resize(f);
	sf.resize(f);
	cd.resize(d, f);
	cf.resize(f, m);
	return true;
}

bool MscnProblem::setCountOfM(int val) {

	if (val < 1) return false;
	m = val;
	um.resize(m);
	sm.resize(m);
	cf.resize(f, m);
	cm.resize(m, s);
	return true;
}

bool MscnProblem::setCountOfS(int val) {

	if (val < 1) return false;
	s = val;
	ss.resize(s);
	ps.resize(s);
	cm.resize(m, s);
	return true;
}

bool MscnProblem::setInCd(double val, int y, int x) { return cd.setElem(val, y, x); }
bool MscnProblem::setInCf(double val, int y, int x) { return cf.setElem(val, y, x); }
bool MscnProblem::setInCm(double val, int y, int x) { return cm.setElem(val, y, x); }

double MscnProblem::getFromCd(int y, int x) { return cd.getElem(y, x); }
double MscnProblem::getFromCf(int y, int x) { return cf.getElem(y, x); }
double MscnProblem::getFromCm(int y, int x) { return cm.getElem(y, x); }


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

double MscnProblem::getKT(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm) {

	double result = 0;

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++)
			result += cd.getElem(i, j) * xd.getElem(i, j);

	for (int i = 0; i < f; i++)
		for (int j = 0; j < m; j++)
			result += cf.getElem(i, j) * xf.getElem(i, j);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++)
			result += cm.getElem(i, j) * xm.getElem(i, j);

	return result;
}

double MscnProblem::getKU(Matrix<double> &xd, Matrix<double> &xf, Matrix<double> &xm) {
	double result = 0;

	for (int i = 0; i < d; i++) {
		double KUDF = 0;
		for (int j = 0; j < f; j++) {
			KUDF += xd.getElem(i, j);
		}
		result += eps(KUDF) * ud[i];
	}

	for (int i = 0; i < f; i++) {
		double KUFM = 0;
		for (int j = 0; j < m; j++) {
			KUFM += xf.getElem(i, j);
		}
		result += eps(KUFM) * uf[i];
	}

	for (int i = 0; i < m; i++) {
		double KUMS = 0;
		for (int j = 0; j < s; j++) {
			KUMS += xm.getElem(i, j);
		}
		result += eps(KUMS) * um[i];
	}

	return result;
}

int MscnProblem::eps(double x) {
	if (x > 0) return 1;
	else return 0;
}

double MscnProblem::getP(Matrix<double> &xm) {
	double result = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++)
			result += xm.getElem(i, j) * ps[j];

	return result;
}

MscnSolution MscnProblem::getSolutionStructure(double *solution) {

	Matrix<double> xd(d, f);
	Matrix<double> xf(f, m);
	Matrix<double> xm(m, s);

	for (int i = 0; i < d; i++)
		for (int j = 0; j < f; j++)
			xd.setElem(solution[i*d + j], i, j);

	for (int i = 0; i < f; i++)
		for (int j = 0; j < m; j++)
			xf.setElem(solution[d*f + i * f + j], i, j);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++)
			xm.setElem(solution[f*m + i * s + j], i, j);

	return { xd, xf, xm };
}

double MscnProblem::getProfit(MscnSolution &s) {
	return getP(s.xm) - getKT(s.xd, s.xf, s.xm) - getKU(s.xd, s.xf, s.xm);
}

int MscnProblem::checkIfSolutionIsValid(double *solution, int arrSize) {
	if (solution == NULL) return ERROR_SOLUTION_IS_NULL;
	int validSize = d * f + f * m + m * s;
	if (arrSize != validSize) return ERROR_WRONG_SIZE;
	for (int i = 0; i < arrSize; i++) {
		if (solution[i] < 0) return ERROR_NEGATIVE_VALUES;
	}

	return SOLUTION_VALID;
}

double MscnProblem::getQuality(double *solution, int arrSize){

	qualityErrorState = checkIfSolutionIsValid(solution, arrSize);

	if (qualityErrorState != SOLUTION_VALID) return 0;

	MscnSolution solutionStructure = getSolutionStructure(solution);

	return getProfit(solutionStructure);

}

void MscnProblem::printAll() {
	std::cout << "Ilosc D: " << d << std::endl;
	std::cout << "cd: " << std::endl;
	cd.print();
	std::cout << std::endl << "ud: ";
	for (int i = 0; i < ud.size(); i++)
		std::cout << ud[i] << " ";
	std::cout << std::endl << "sd: ";
	for (int i = 0; i < sd.size(); i++)
		std::cout << sd[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Ilosc F: " << f << std::endl;
	std::cout << "cf: " << std::endl;
	cf.print();
	std::cout << std::endl << "uf: ";
	for (int i = 0; i < uf.size(); i++)
		std::cout << uf[i] << " ";
	std::cout << std::endl << "sd: ";
	for (int i = 0; i < sf.size(); i++)
		std::cout << sf[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Ilosc M: " << m << std::endl;
	std::cout << "cm: " << std::endl;
	cm.print();
	std::cout << std::endl << "um: ";
	for (int i = 0; i < um.size(); i++)
		std::cout << um[i] << " ";
	std::cout << std::endl << "sm: ";
	for (int i = 0; i < sm.size(); i++)
		std::cout << sm[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Ilosc S: " << s << std::endl;
	std::cout << std::endl << "ss: ";
	for (int i = 0; i < ss.size(); i++)
		std::cout << ss[i] << " ";
	std::cout << std::endl << "ps: ";
	for (int i = 0; i < ps.size(); i++)
		std::cout << ps[i] << " ";
	std::cout << std::endl << std::endl;
	
	std::cout << std::endl;

}