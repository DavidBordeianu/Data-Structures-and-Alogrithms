#include "test-utils.hpp"


TEST_CASE("Cerinta 3: Calculul matricei drumurilor - Algoritmul Roy Warshall")
{
    int ** mat;
    graph_matrix* graph;

	SECTION("Verificare matrice")
	{
        graph = readMatrix(TASK3_TEST_FILENAME1);
        std::vector<std::vector<int>> mat_ref = readRoads(TASK3_TEST_FILENAME2);
        mat = findPaths(graph);
        REQUIRE(mat != NULL);
        for(int i = 0; i < graph->V; ++i) {
            REQUIRE(mat[i] != NULL);
            for(int j = 0; j < graph->V; ++j) {
                REQUIRE(mat[i][j] == mat_ref[i][j]);
            }
        }
	}
	
}

TEST_CASE("Cerinta 3 - Test2")
{
    int ** mat;
    graph_matrix* graph;

	SECTION("Verificare matrice")
	{
        graph = readMatrix(TASK3_TEST_FILENAME3);
        std::vector<std::vector<int>> mat_ref = readRoads(TASK3_TEST_FILENAME4);
        mat = findPaths(graph);
        REQUIRE(mat != NULL);
        for(int i = 0; i < graph->V; ++i) {
            REQUIRE(mat[i] != NULL);
            for(int j = 0; j < graph->V; ++j) {
                REQUIRE(mat[i][j] == mat_ref[i][j]);
            }
        }
	}
	
}

