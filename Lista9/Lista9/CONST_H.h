#pragma once
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

const int D_COUNT = 2;
const int F_COUNT = 3;
const int M_COUNT = 4;
const int S_COUNT = 5;

const int SOLUTION_VALID = 0;
const int ERROR_SOLUTION_IS_NULL = 1;
const int ERROR_WRONG_SIZE = 2;
const int ERROR_NEGATIVE_VALUES = 3;

const int SOLUTION_NOT_VALID = 0;

const bool CONSTRAINTS_SATISFIED = true;
const bool CONSTRAINTS_NOT_SATISFIED = false;

const std::string PROBLEM_FILE_NAME = "database/problem.txt";
const std::string SOLUTION_FILE_NAME = "database/solution.txt";