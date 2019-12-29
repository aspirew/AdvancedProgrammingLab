#pragma once
#include <algorithm>
#include <fstream>
#include <random>
#include <time.h>

const int D_COUNT = 2;
const int F_COUNT = 3;
const int M_COUNT = 4;
const int S_COUNT = 5;

const int SOLUTION_VALID = 0;
const int ERROR_SOLUTION_IS_NULL = 1;
const int ERROR_WRONG_SIZE = 2;
const int ERROR_NEGATIVE_VALUES = 3;
const int ERROR_NUMBER_TOO_SMALL = 4;
const int ERROR_NUMBER_TOO_BIG = 5;

const int SOLUTION_NOT_VALID = INT_MIN;

const bool CONSTRAINTS_SATISFIED = true;
const bool CONSTRAINTS_NOT_SATISFIED = false;

const std::string PROBLEM_FILE_NAME = "database/problem.txt";
const std::string SOLUTION_FILE_NAME = "database/solution.txt";
const std::string SEED_FILE_NAME = "database/seed.txt";

const int RAND_C_MIN = 2;
const int RAND_C_MAX = 20;
const int RAND_S_MIN = 100;
const int RAND_S_MAX = 10000;
const int RAND_U_MIN = 1;
const int RAND_U_MAX = 5;
const int RAND_P_MIN = 60;
const int RAND_P_MAX = 600;

const unsigned int DEFAULT_SEED = 1577381086;

const int DEFAULT_MAX_ITER = 100;
const int DEFAULT_POPULATION_NUMBER = 5;
const int DEFAULT_CROSS_PROB = 0.5;
