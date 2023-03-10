#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <cstdbool>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

#include "list.h"
#include "utils.h"
#include "catch.hpp"

#define TASK1_TEST_FILENAME "../data/test1-data.txt"
#define TASK2_TEST_FILENAME1 "../data/test2-data1.txt"
#define TASK2_TEST_FILENAME2 "../data/test2-data2.txt"
#define TASK3_TEST_FILENAME "../data/test3-data.txt"

std::vector<int> beforeEach(const char *);
node *studentTaskSetUp(const char *);
childNode *studentGameTaskSetup(const char *test_task_data);
std::vector<childNode> beforeGame(const char *test_task_data);