#include "pch.h"
#include <iostream>
#include <string>
#include "CONST_H.h"
#include "CLASS_H.h"


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

	tab.writeTable();

	pc_new_tab->bSetNewSize(2);

	pc_new_tab->writeTable();
	tab.writeTable();

	delete pc_new_tab;

	CTable * tab1 = new CTable();
	CTable * tab2 = new CTable("nowaNazwa", 7);

	v_mod_tab(tab2, 3);
	v_mod_tab(tab, 1);

	tab.writeTable();
	tab2->writeTable();

	CTable * tab3 = new CTable(tab);

	std::cout << tab1->vGetName() << std::endl;
	std::cout << tab2->vGetName() << std::endl;
	std::cout << tab3->vGetName() << std::endl;

	delete tab1;
	delete tab2;
	delete tab3;

}