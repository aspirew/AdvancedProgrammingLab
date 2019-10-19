#include "pch.h"
#include <iostream>
#include <string>

const std::string S_NAME = "CTable";
const int DEFAULT_TABLE_LENGTH = 5;

class CTable {
public:
	
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable *pcClone();
	CTable();
	CTable(std::string, int);
	CTable(const CTable &pcOther);
	~CTable();

private:

	int *cTable;
	std::string s_name;
	int tableLength;

};

void CTable::vSetName(std::string sName) {
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {

	if (iTableLen < tableLength) {
		return false;
	}

	int *newTable = new int[iTableLen];

	for (int i = 0; i < tableLength; i++) {
		newTable[i] = cTable[i];
	}

	delete [] cTable;
	cTable = newTable;

	return true;

}

CTable *CTable::pcClone() {
	CTable thisTable;
	thisTable.vSetName(s_name);
	thisTable.bSetNewSize(tableLength);
	CTable *newCTable = new CTable(thisTable);
	return newCTable;
}

CTable::CTable() {

	vSetName(S_NAME);
	std::cout << "bezp: " << s_name << std::endl;
	cTable = new int[DEFAULT_TABLE_LENGTH];
	tableLength = DEFAULT_TABLE_LENGTH;

}

CTable::CTable(std::string sName, int iTableLen) {

	vSetName(sName);
	std::cout << "parametr: " << s_name;
	bSetNewSize(iTableLen);

}

CTable::CTable(const CTable &pcOther) {
	s_name = pcOther.s_name + "_copy";
	cTable = pcOther.cTable;
	std::cout << "kopiuj: " << s_name;
}

CTable::~CTable() {
	std::cout << "usuwam: " << s_name << std::endl;
}

void v_mod_tab(CTable *pcTab, int iNewSize) {
	pcTab->vSetName("v_mod_pointer_modified");
}

void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.vSetName("v_mod_modified");
}

int main(){
	CTable tab;
	CTable * tab1 = new CTable();
	CTable * tab2 = new CTable("nowaNazwa", 7);

	std::cout << tab1->pcClone << std::endl;
	CTable * tab3 = new CTable(tab);
}