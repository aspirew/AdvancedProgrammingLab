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

	CTable c_tab_0, c_tab_1;
	c_tab_0.vSetName("c_tab_0");
	c_tab_1.vSetName("c_tab_1");
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);

	for (int i = 0; i < 6; i++) {
		c_tab_0.vSetValueAt(i, i);
	}

	for (int i = 0; i < 4; i++) {
		c_tab_1.vSetValueAt(i, 50 + i);
	}

	c_tab_0.vShow();
	c_tab_1.vShow();

	CTable mergedTab = c_tab_0 + c_tab_1 + c_tab_0;

	std::cout << "Polaczone tablice: " << std::endl;

	mergedTab.vShow();

	CTable jumpedMergedTab = mergedTab /= 3;

	jumpedMergedTab.vShow();

	std::cout << std::endl;

	c_tab_0 = c_tab_1;

	c_tab_1.vSetValueAt(2, 123);

	c_tab_0.vShow();
	c_tab_1.vShow();



}