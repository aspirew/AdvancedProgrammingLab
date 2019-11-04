#include <iostream>
#include <string>
#include "CLASS_H.h"
#include "CONST_H.h"

CTable::CTable() {

	vSetName(S_NAME);
	std::cout << "bezp: " << s_name << std::endl;
	piTable = new int[DEFAULT_TABLE_LENGTH];
	tableLength = DEFAULT_TABLE_LENGTH;

}

CTable::CTable(std::string sName, int iTableLen) {

	if (iTableLen < 1) {
		std::cout << ELEMENTS_LESS_THAN_1_SETTING_DEFAULT << std::endl;
		iTableLen = DEFAULT_TABLE_LENGTH;
	}

	vSetName(sName);
	std::cout << "parametr: " << s_name << std::endl;
	piTable = new int[iTableLen];
	tableLength = iTableLen;

}

CTable::CTable(const CTable &pcOther) {
	s_name = pcOther.s_name + "_copy";
	tableLength = pcOther.tableLength;
	piTable = new int[tableLength];

	vOverwriteTable(pcOther);

	std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::~CTable() {
	std::cout << "usuwam: " << s_name << std::endl;
	delete [] piTable;
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
		newTable[i] = piTable[i];
	}

	tableLength = iTableLen;

	delete[] piTable;
	piTable = newTable;

	return true;

}

void CTable::vWriteTable() {
	for (int i = 0; i < tableLength; i++) {
		std::cout << piTable[i] << "; ";
	}
	std::cout << std::endl;
}

void CTable::vOverwriteTable(const CTable &pcOther) {
	for (int i = 0; i < tableLength; ++i) {
		piTable[i] = pcOther.piTable[i];
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
		piTable[i] = i * i;
	}
}

CTable CTable::GetPairSumsTable() {
	CTable returnCTable(s_name + "_PairSums", tableLength - 1);

	if (tableLength < 2) {
		std::cout << NOT_ENOUGH_ELEMENTS << std::endl;
	}

	for (int i = 1; i < tableLength; i++) {
		returnCTable.piTable[i - 1] = piTable[i - 1] + piTable[i];
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

	piTable[iOffset] = iNewVal;
}

CTable & CTable::operator=(CTable &table) {

	if (this == &table) return *this;

	s_name = table.s_name;
	tableLength = table.tableLength;
	delete[] piTable;
	piTable = new int[tableLength];
	std::copy(table.piTable, table.piTable + table.tableLength, piTable);

	return *this;
}

CTable CTable::operator+(CTable &table) {
	int lenOfSecondTable = table.getTableLength();
	int newLen = lenOfSecondTable + tableLength;
	CTable newTable("mergedTable", newLen);

	for (int i = 0; i < tableLength; i++) {
		newTable.piTable[i] = piTable[i];
	}

	for (int i = 0; i < lenOfSecondTable; i++) {
		newTable.piTable[i + tableLength] = table.piTable[i];
	}

	return newTable;
}

CTable & CTable::operator/=(int divider) {
	if (divider < 2) {
		std::cout << CANT_JUMP << std::endl;
		return *this;
	}

	int increment = 0;

	for (int i = 0; i < tableLength; i += divider) {
		piTable[increment++] = piTable[i];
	}

	bSetNewSize(increment);

	return *this;

}