#include "pch.h"
#include "CONST_H.h"
#include "Tab.cpp"
#include "CTable.cpp"

Tab cCreateTab()
{
	Tab c_result;
	c_result.setSize(5);
	return(std::move(c_result));
}//CTab cCreateTab()

void i_ms_test()
{
	cCreateTab();
	/*DO STH WITH c_tab*/
}//int i_ms_test()

void aTest(){
	Tab tab1;
	Tab tab2;
	Tab tab3;

	tab1 = tab2;

	tab1 = std::move(tab3);

}

void bTest() {
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

	CTable mergedTab = std::move(c_tab_0 + (c_tab_1 + c_tab_0));
	//CTable mergedTab = (c_tab_0 + c_tab_1 + c_tab_0);

	std::cout << "Polaczone tablice: " << std::endl;

	mergedTab.vShow();

	CTable copiedTab = mergedTab.pcClone();

	copiedTab.vShow();

	std::cout << "Ilosc kopii: " << mergedTab.numberOfCopies << " | Ilosc przesuniec: " << mergedTab.numberOfMoves << std::endl;

}

int main()
{
	//aTest();
	bTest();
}