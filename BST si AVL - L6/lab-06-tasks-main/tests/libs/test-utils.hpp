/**
 * @brief this is the header file for the test-utils.cpp implementations.
 *        SHOULD CONTAIN THE FUNCTION HEADERS AND CONSTANTS USED IN UNIT TESTS
 *        
 * @author Rusu Gabriel
 * 
 */
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

#include "catch.hpp"
#include "utils.h"
#include "bst.h"

#define TASK1_TEST_FILENAME1 "../data/test1-data1.txt"
#define TASK1_TEST_FILENAME2 "../data/test1-data2.txt"
#define TASK1_TEST_FILENAME3 "../data/test1-data3.txt"

#define TASK2_TEST_FILENAME "../data/test2-data.txt"

#define TASK3_TEST_FILENAME1 "../data/test3-data1.txt"
#define TASK3_TEST_FILENAME2 "../data/test3-data2.txt"
#define TASK3_TEST_FILENAME3 "../data/test3-data3.txt"

std::vector<int> beforeEach(const char * test_task_data);
BST* readData(const char * test_task_data);