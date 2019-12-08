#pragma once
#ifndef TAB_H
#define TAB_H
#include "CONST_H.h"

class Tab
{
public:
	Tab() { tab = new int[DEFAULT_TAB_SIZE]; size = DEFAULT_TAB_SIZE; }
	Tab(const Tab &other);
	Tab(Tab &&other);
	Tab& operator=(const Tab &other);
	Tab& operator=(Tab &&other);
	~Tab();

	bool setSize(int newSize);
	int getSize() { return(size); }

	int getElement(int offset) { return tab[offset]; }

private:
	void copy(const Tab &other);

	int *tab;
	int size;
};

#endif // TAB_H