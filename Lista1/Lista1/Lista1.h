#pragma once
void v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);

const int TABLE_SIZE = 5;
const int SIZE_X_OF_TWO_DIMENSIONAL_TABLE = 5;
const int SIZE_Y_OF_TWO_DIMENSIONAL_TABLE = 3;
const int TABLE_ELEMENT_VALUE = 5;