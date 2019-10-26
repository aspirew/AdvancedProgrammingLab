#pragma once
class CTable {
public:

	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	void writeTable();
	std::string vGetName();
	CTable *pcClone();
	CTable();
	CTable(std::string, int);
	CTable(const CTable &pcOther);
	~CTable();

private:

	int *cTable;
	std::string s_name;
	int tableLength;
	void overwriteTable(const CTable &pcOther);

};

CTable::CTable() {

	vSetName(S_NAME);
	std::cout << "bezp: " << s_name << std::endl;
	cTable = new int[DEFAULT_TABLE_LENGTH];
	tableLength = DEFAULT_TABLE_LENGTH;

}

CTable::CTable(std::string sName, int iTableLen) {

	vSetName(sName);
	std::cout << "parametr: " << s_name << std::endl;
	cTable = new int[iTableLen];
	tableLength = iTableLen;

}

CTable::CTable(const CTable &pcOther) {
	s_name = pcOther.s_name + "_copy";
	tableLength = pcOther.tableLength;
	cTable = new int[tableLength];

	overwriteTable(pcOther);

	std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::~CTable() {
	std::cout << "usuwam: " << s_name << std::endl;
	delete cTable;
}

void CTable::vSetName(std::string sName) {
	s_name = sName;
}

std::string CTable::vGetName() {
	return s_name;
}

bool CTable::bSetNewSize(int iTableLen) {

	if (iTableLen < 1) {
		return false;
	}

	int *newTable = new int[iTableLen];
	int quantityOfNumbersToCopy = (iTableLen < tableLength) ? iTableLen : tableLength;

	for (int i = 0; i < quantityOfNumbersToCopy; i++) {
		newTable[i] = cTable[i];
	}

	tableLength = iTableLen;

	delete[] cTable;
	cTable = newTable;

	return true;

}

void CTable::writeTable() {
	for (int i = 0; i < tableLength; i++) {
		std::cout << cTable[i] << std::endl;
	}
	std::cout << std::endl;
}

void CTable::overwriteTable(const CTable &pcOther) {
	for (int i = 0; i < tableLength; ++i) {
		cTable[i] = pcOther.cTable[i];
	}
}

CTable * CTable::pcClone() {

	CTable * newTable = new CTable(s_name, tableLength);
	newTable->overwriteTable(*this);

	//CTable * newTable = new CTable(*this);
	return newTable;
}