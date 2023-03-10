#include "test-utils.hpp"


TEST_CASE("Cerinta 3: Testare continut BST")
{
	
	BST *root_s, *root_d;
	SECTION("Contin acelasi valori")
	{
		root_s = readData(TASK3_TEST_FILENAME1);
		REQUIRE(root_s != NULL);
		root_d = readData(TASK3_TEST_FILENAME2);
		REQUIRE(root_d != NULL);
		
		int size_s = numberOfNodesInBetween(root_s, INT_MAX, INT_MIN);
		int size_d = numberOfNodesInBetween(root_d, INT_MAX, INT_MIN);
		
		REQUIRE(size_s == size_d);

		
		BST** arr_s = (BST**)malloc(sizeof(BST*) * size_s);
		BST** arr_d = (BST**)malloc(sizeof(BST*) * size_d);
		
		int size_ret_s, size_ret_d;
		size_ret_s = size_ret_d = 0;
		
		bstToArray(root_s, arr_s, &size_ret_s, INT_MAX, INT_MIN);
		bstToArray(root_d, arr_d, &size_ret_d, INT_MAX, INT_MIN);
		
		REQUIRE(size_s == size_ret_s);
		REQUIRE(size_d == size_ret_d);
		
		for(int i = 0; i < size_ret_s; i++)
			REQUIRE(arr_s[i]->data == arr_d[i]->data);
		
	}
	
		SECTION("Nu contin acelasi valori")
	{
		root_s = readData(TASK3_TEST_FILENAME1);
		REQUIRE(root_s != NULL);
		root_d = readData(TASK3_TEST_FILENAME3);
		REQUIRE(root_d != NULL);
		
		int size_s = numberOfNodesInBetween(root_s, INT_MAX, INT_MIN);
		int size_d = numberOfNodesInBetween(root_d, INT_MAX, INT_MIN);
		
		REQUIRE(size_s == size_d);
		
		BST** arr_s = (BST**)malloc(sizeof(BST*) * size_s);
		BST** arr_d = (BST**)malloc(sizeof(BST*) * size_d);
		
		int size_ret_s, size_ret_d;
		size_ret_s = size_ret_d = 0;
		
		bstToArray(root_s, arr_s, &size_ret_s, INT_MAX, INT_MIN);
		bstToArray(root_d, arr_d, &size_ret_d, INT_MAX, INT_MIN);
		
		REQUIRE(size_s == size_ret_s);
		REQUIRE(size_d == size_ret_d);
		
		bool ans = true;
		
		for(int i = 0; i < size_ret_s; i++)
			if(arr_s[i]->data != arr_d[i]->data)
				ans = false;
		
		REQUIRE(ans == false);
	}
	
	
	
}