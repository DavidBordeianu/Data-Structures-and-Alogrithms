#include "test-utils.hpp"


TEST_CASE("Cerinta 2: Succesor si Predecesor")
{
	
	BST* root;
	SECTION("Succesor in subarborele drept")
	{
		root = readData(TASK2_TEST_FILENAME);
		REQUIRE(root != NULL);
		root = findNode(root, 45);
		REQUIRE(root != NULL);
		root = findSuccesor(root);
		REQUIRE(root != NULL);
		
		REQUIRE(root->data == 50);
	}
	
	SECTION("Succesorul este primul stramos drept")
	{
		root = readData(TASK2_TEST_FILENAME);
		REQUIRE(root != NULL);
		root = findNode(root, 55);
		REQUIRE(root != NULL);
		root = findSuccesor(root);
		REQUIRE(root != NULL);
		
		REQUIRE(root->data == 77);
	}	
	
	SECTION("Predecesor in subarborele drept")
	{
		root = readData(TASK2_TEST_FILENAME);
		REQUIRE(root != NULL);
		root = findNode(root, 20);
		REQUIRE(root != NULL);
		root = findPredecessor(root);
		REQUIRE(root != NULL);
		
		REQUIRE(root->data == 18);
	}
	
	SECTION("Predecesorul este primul stramos stang")
	{
		root = readData(TASK2_TEST_FILENAME);
		REQUIRE(root != NULL);
		root = findNode(root, 24);
		REQUIRE(root != NULL);
		root = findPredecessor(root);
		REQUIRE(root != NULL);
		
		REQUIRE(root->data == 23);
	}		
	
}