/**
 * @brief in this file are defined all the common functions used in the
 * 		  test suite
 * @author Rusu Gabriel
 * 
 */
#include "test-utils.hpp"


std::vector<int> beforeEach(const char * test_task_data)
{
		
	std::ifstream file(test_task_data);
	
	std::vector<int> array;
	int size, element;
	file >> size;
	
	for (int i = 0; i < size; i++) {
		file >> element;
		array.push_back(element);
	}
	
	return array;
}

BST* readData(const char * test_task_data)
{
	std::ifstream file(test_task_data);
	int size, data;
	file >> size;
	BST *root = NULL;
	for (int i = 0; i < size; i++)
	{
		file >> data;
		root = insertInBST(root, data);
	}
	
	return root;
}

