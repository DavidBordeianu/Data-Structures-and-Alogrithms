#include "test-utils.hpp"


TEST_CASE("Cerinta 1: Verificare proprietate BST")
{
	
	BST* root;
	SECTION("Arborele respecta conditia de BST")
	{
		root = readData(TASK1_TEST_FILENAME1);
		REQUIRE(root != NULL);
		REQUIRE(checkBST(root, INT_MAX, INT_MIN) == true);
	}
	
	
	SECTION("Arborele nu respecta conditia de BST - partial corect")
	{
		FILE* file = fopen(TASK1_TEST_FILENAME3, "r");
		int size;
		fscanf(file, "%d", &size);
		root = createBalanced(size, file);
		REQUIRE(root != NULL);
		REQUIRE(checkBST(root, INT_MAX, INT_MIN) == false);
	}
	
	SECTION("Arborele nu respecta conditia de BST - 100% corect")
	{
		FILE* file = fopen(TASK1_TEST_FILENAME2, "r");
		int size;
		fscanf(file, "%d", &size);
		root = createBalanced(size, file);
		REQUIRE(root != NULL);
		REQUIRE(checkBST(root, INT_MAX, INT_MIN) == false);
	}
	
	
}