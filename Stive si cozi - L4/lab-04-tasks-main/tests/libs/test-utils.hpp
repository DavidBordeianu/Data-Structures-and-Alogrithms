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
#include <sstream>
#include <stack>
#include <queue>
#include "stack.h"
#include "queue.h"


#define TASK_TEST_FILENAME "../data/ds-test.txt"
#define TEST1_FILE "../data/test1.txt"
#define TEST2_FILE "../data/test2.txt"

std::string make_input_from(const char * filename);

void compare(Stack *stack,std::stack<char> &test_stack);
void compare(Queue *queue, std::queue<std::string> &test_queue);
std::stack<char> process(std::string &input);
std::stack<char> reverse(std::stack<char>& test_stack);