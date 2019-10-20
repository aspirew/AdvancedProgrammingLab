#include "pch.h"
#include <iostream>
#include "lista1.h"

using std::cout;

int main()
{
	v_alloc_table_add_5(TABLE_SIZE);
	int **piTable;
	bool isAllocated = b_alloc_table_2_dim(&piTable, SIZE_X_OF_TWO_DIMENSIONAL_TABLE, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE);
	b_dealloc_table_2_dim(piTable, SIZE_X_OF_TWO_DIMENSIONAL_TABLE, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE);
}

void v_write_table(int *table, int sizeOfTable) {
	for (int i = 0; i < sizeOfTable; i++) {
		cout << table[i];
	}
}

void v_alloc_table_add_5(int iSize) {

	if (iSize < 0) {
		cout << "Nieprawidłowa wielkość tablicy!" << std::endl;
	}
	else {

		int *table;
		table = new int[iSize];

		for (int offset = 0; offset < iSize; offset++) {
			table[offset] = offset + TABLE_ELEMENT_VALUE;
		}

		v_write_table(table, iSize);

		delete table;
	}
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {

	if (iSizeX < 1 || iSizeY < 1) {
		return false;
	}

	*piTable = new int*[iSizeX];

	for (int i = 0; i < iSizeX; i++) {
		(*piTable)[i] = new int[iSizeY];
	}

	return true;
}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY) {

	if (iSizeX != SIZE_X_OF_TWO_DIMENSIONAL_TABLE || iSizeY != SIZE_Y_OF_TWO_DIMENSIONAL_TABLE)
		return false;

	for (int i = 0; i < iSizeX; i++) {
		delete [] piTable;
	}

	delete [] piTable;
	return true;
}

