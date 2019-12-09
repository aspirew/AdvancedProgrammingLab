#pragma once
#include "CONST_H.h"

class CTable {
public:

	static int numberOfCopies;
	static int numberOfMoves;

	void vSetValueAt(int iOffset, int iNewVal);
	CTable operator+(CTable &table);
	CTable & operator/=(int divider);
	CTable & operator=(CTable &table);
	CTable & operator=(CTable &&table);
	int *piTable;

	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	void vWriteTable();
	int getTableLength();
	std::string sGetName();
	CTable pcClone();
	void vShow();
	void vFillTable();
	CTable GetPairSumsTable();
	CTable();
	CTable(std::string, int);
	CTable(const CTable &pcOther);
	CTable(CTable &&pcOther);
	~CTable();

private:

	std::string s_name;
	int tableLength;
	void vOverwriteTable(const CTable &pcOther);

};
