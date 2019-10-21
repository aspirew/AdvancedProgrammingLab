#include "pch.h"
#include <iostream>
#include "lista1.h"

using std::cout;

int main()
{
	int * table = v_alloc_table_add_5(TABLE_SIZE);
	//v_write_table(table, TABLE_SIZE);
	v_delete_table(table);
	int **piTable1;
	int **piTable2;
	bool isAllocated1 = b_alloc_table_2_dim(&piTable1, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_1, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_1);
	bool isAllocated2 = b_alloc_table_2_dim(&piTable2, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_2, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_2);
	if (isAllocated1 && isAllocated2) {
		b_fill_increasing_table_2_dim(piTable1, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_1, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_1);
		b_fill_increasing_table_2_dim(piTable2, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_2, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_2);		
		b_show_table_2_dim(piTable1, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_1, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_1);
		b_show_table_2_dim(piTable2, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_2, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_2);
		b_copy_values_table_2_dim(piTable1, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_1, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_1, piTable2, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_2, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_2);
		b_show_table_2_dim(piTable2, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_2, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_2);
		b_dealloc_table_2_dim(piTable1, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_1, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_1);
		b_dealloc_table_2_dim(piTable2, SIZE_X_OF_TWO_DIMENSIONAL_TABLE_2, SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_2);
	}
}

void v_write_table(int *table, int sizeOfTable) {
	if (table != NULL) {
		for (int i = 0; i < sizeOfTable; i++) {
			cout << table[i];
		}
	}
}

void v_delete_table(int *table) {
	delete[] table;
}

int * v_alloc_table_add_5(int iSize) {

	if (iSize < 0) {
		cout << "Nieprawidłowa wielkość tablicy!" << std::endl;
		return NULL;
	}
	else {

		int *table;
		table = new int[iSize];

		for (int offset = 0; offset < iSize; offset++) {
			table[offset] = offset + TABLE_ELEMENT_VALUE;
		}

		return table;
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

	if (iSizeX <= 0 || iSizeY <= 0)
		return false;

	for (int i = 0; i < iSizeX; i++) {
		delete [] piTable[i];
	}

	delete [] piTable;
	return true;
}

void b_show_table_2_dim(int **piTable, int iSizeX, int iSizeY) {
	
	for (int i = 0; i < iSizeX; i++) {
		for (int j = 0; j < iSizeY; j++) {
			cout << piTable[i][j] << "; ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void b_fill_increasing_table_2_dim(int **piTable, int iSizeX, int iSizeY) {
	int increment = 0;

	for (int i = 0; i < iSizeX; i++) {
		for (int j = 0; j < iSizeY; j++) {
			piTable[i][j] = increment++;
		}
	}
}

void b_copy_values_table_2_dim(int **piTable1, int sizeXOfFirstTable, int sizeYOfFirstTable, int **piTable2, int sizeXOfSecondTable, int sizeYOfSecondTable) {
	int initialSizeX = (sizeXOfFirstTable < sizeXOfSecondTable) ? sizeXOfFirstTable : sizeXOfSecondTable;
	int initialSizeY = (sizeYOfFirstTable < sizeYOfSecondTable) ? sizeYOfFirstTable : sizeYOfSecondTable;

	for (int i = 0; i < initialSizeX; i++) {
		for (int j = 0; j < initialSizeY; j++) {
			piTable2[i][j] = piTable1[i][j];
		}
	}
}
