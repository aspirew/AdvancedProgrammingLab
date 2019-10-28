#pragma once
class CTable {
public:

	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	void vWriteTable();
	std::string sGetName();
	CTable *pcClone();
	void vShow();
	void vFillTable();
	CTable GetPairSumsTable();
	CTable();
	CTable(std::string, int);
	CTable(const CTable &pcOther);
	~CTable();

private:

	int *cTable;
	std::string s_name;
	int tableLength;
	void vOverwriteTable(const CTable &pcOther);

};

