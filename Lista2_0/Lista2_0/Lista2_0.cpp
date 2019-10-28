#include "pch.h"
#include <iostream>
#include <string>
#include "CONST_H.h"
#include "CTable.cpp"


void v_mod_tab(CTable *pcTab, int iNewSize) {
	pcTab->vSetName("v_mod_pointer_modified");
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.vSetName("v_mod_modified");
	cTab.bSetNewSize(iNewSize);
}

int main() {

	CTable tab;
	CTable * pc_new_tab;
	pc_new_tab = tab.pcClone();

	tab.vWriteTable();

	pc_new_tab->bSetNewSize(2);

	pc_new_tab->vWriteTable();
	tab.vWriteTable();

	delete pc_new_tab;

	CTable * tab1 = new CTable();
	CTable * tab2 = new CTable("nowaNazwa", 7);

	v_mod_tab(tab2, 3);
	v_mod_tab(tab, 1);

	tab.vWriteTable();
	tab2->vWriteTable();

	CTable * tab3 = new CTable(tab);

	std::cout << std::endl;

	tab1->vFillTable();
	tab2->vFillTable();
	tab3->vFillTable();

	tab1->vShow();
	tab2->vShow();
	tab3->vShow();

	std::cout << std::endl;

	tab1->GetPairSumsTable().vShow();

	std::cout << std::endl;

	delete tab1;
	delete tab2;
	delete tab3;

}