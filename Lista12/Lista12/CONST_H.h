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

const int CONSTRAINTS_OK = 0;
const int CONSTRAINTS_TOO_MUCH_FROM_DISTRIBUTOR = 1;
const int CONSTRAINTS_TOO_MUCH_FROM_FACTORY = 2;
const int CONSTRAINTS_TOO_MUCH_FROM_MAGAZINE = 3;
const int CONSTRAINTS_TOO_MUCH_FOR_STORE = 4;
const int CONSTRAINTS_NOT_ENOUGH_MATERIALS_FOR_FACTORIES = 5;
const int CONSTRAINTS_NOT_ENOUGH_PRODUCTS_FOR_MAGAZINES = 6;


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
const double DEFAULT_TIME = 1;

const int DEFAULT_POPULATION_NUMBER = 1;
const double DEFAULT_CROSS_PROB = 0.3;
const double DIFF_WEIGTH = 0.5;
