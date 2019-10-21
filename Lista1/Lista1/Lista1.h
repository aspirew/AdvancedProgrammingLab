#pragma once
const int TABLE_SIZE = 5;
const int SIZE_X_OF_TWO_DIMENSIONAL_TABLE_1 = 3;
const int SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_1 = 4;
const int SIZE_X_OF_TWO_DIMENSIONAL_TABLE_2 = 4;
const int SIZE_Y_OF_TWO_DIMENSIONAL_TABLE_2 = 3;
const int TABLE_ELEMENT_VALUE = 5;

int * v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY);
void b_show_table_2_dim(int **piTable, int iSizeX, int iSizeY);
void b_fill_increasing_table_2_dim(int **piTable, int iSizeX, int iSizeY);
void v_write_table(int * table, int TABLE_SIZE);
void v_delete_table(int *table);
void b_copy_values_table_2_dim(int **piTable1, int sizeXOfFirstTable, int sizeYOfFirstTable, int **piTable2, int sizeXOfSecondTable, int sizeYOfSecondTable);