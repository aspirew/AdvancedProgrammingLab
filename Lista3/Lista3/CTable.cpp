#include <iostream>
#include <string>
#include "CLASS_H.h"
#include "CONST_H.h"

CTable::CTable() {

	vSetName(S_NAME);
	std::cout << "bezp: " << s_name << std::endl;
	cTable = new int[DEFAULT_TABLE_LENGTH];
	tableLength = DEFAULT_TABLE_LENGTH;

}

CTable::CTable(std::string sName, int iTableLen) {

	if (iTableLen < 1) {
		std::cout << ELEMENTS_LESS_THAN_1_SETTING_DEFAULT << std::endl;
		iTableLen = DEFAULT_TABLE_LENGTH;
	}

	vSetName(sName);
	std::cout << "parametr: " << s_name << std::endl;
	cTable = new int[iTableLen];
	tableLength = iTableLen;

}

CTable::CTable(const CTable &pcOther) {
	s_name = pcOther.s_name + "_copy";
	tableLength = pcOther.tableLength;
	cTable = new int[tableLength];

	vOverwriteTable(pcOther);

	std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::~CTable() {
	std::cout << "usuwam: " << s_name << std::endl;
	//delete cTable;
}

void CTable::vSetName(std::string sName) {
	s_name = sName;
}

std::string CTable::sGetName() {
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

void CTable::vWriteTable() {
	for (int i = 0; i < tableLength; i++) {
		std::cout << cTable[i] << "; ";
	}
	std::cout << std::endl;
}

void CTable::vOverwriteTable(const CTable &pcOther) {
	for (int i = 0; i < tableLength; ++i) {
		cTable[i] = pcOther.cTable[i];
	}
}

CTable * CTable::pcClone() {

	CTable * newTable = new CTable(s_name, tableLength);
	newTable->vOverwriteTable(*this);

	//CTable * newTable = new CTable(*this);
	return newTable;
}

void CTable::vShow() {
	std::cout << s_name << std::endl;
	vWriteTable();
}

void CTable::vFillTable() {
	for (int i = 0; i < tableLength; i++) {
		cTable[i] = i * i;
	}
}

CTable CTable::GetPairSumsTable() {
	CTable returnCTable(s_name + "_PairSums", tableLength - 1);

	if (tableLength < 2) {
		std::cout << NOT_ENOUGH_ELEMENTS << std::endl;
	}

	for (int i = 1; i < tableLength; i++) {
		returnCTable.cTable[i - 1] = cTable[i - 1] + cTable[i];
	}

	return returnCTable;
}

int CTable::getTableLength() {
	return tableLength;
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
	if (iOffset < 0 || iOffset >= tableLength) {
		std::cout << WRONG_POSITION << std::endl;
		return;
	}

	cTable[iOffset] = iNewVal;
}

int * CTable::operator+(CTable &table) {
	int lenOfSecondTable = table.getTableLength();
	int newLen = lenOfSecondTable + tableLength;
	int * newTable = new int[newLen];

	for (int i = 0; i < tableLength; i++) {
		newTable[i] = cTable[i];
	}

	for (int i = 0; i < lenOfSecondTable; i++) {
		newTable[i + tableLength] = table.cTable[i];
	}

	return newTable;

}