#include "pch.h"
#include "Tab.cpp"

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

int main()
{
	Tab tab1;
	Tab tab2;

	tab1 = std::move(tab2);
}
