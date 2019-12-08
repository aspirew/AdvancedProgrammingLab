#pragma once
#ifndef CONST_H
#define CONST_H

#include <iostream>
#include <string>

#define DEFAULT_TABLE_NAME "Default table name"
#define DEFAULT_TABLE_LEN 5
#define DEFAULT_TAB_SIZE 10

const std::string S_NAME = "CTable";
const int DEFAULT_TABLE_LENGTH = 5;
const std::string NOT_ENOUGH_ELEMENTS = "Iloœæ elementów jest za ma³a by mo¿na je dodawaæ";
const std::string ELEMENTS_LESS_THAN_1_SETTING_DEFAULT = "Iloœæ elementów tablicy mniejsza ni¿ 1! Ustawiam wartoœæ domyœln¹...";
const std::string WRONG_POSITION = "Podany offset poza zakresem tablicy, ustawiam na wartoœci 0...";
const std::string CANT_JUMP = "Przez tablice nie mo¿na przeskakiwaæ mniej ni¿ co jeden element";

#endif // CONST_H