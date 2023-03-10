#include "test-utils.hpp"


TEST_CASE("Cerinta 2: Transformare din reprezentare cu liste in reprezentare cu matrice de adiacenta")
{
	
	graph_list* graph_l;
    graph_matrix* graph_m_transformed;
    graph_matrix* graph_m;

	SECTION("Transformare")
	{
		graph_l = readList(TASK2_TEST_FILENAME1);
        graph_m = readMatrix(TASK2_TEST_FILENAME2);
        graph_m_transformed = listToMatrix(graph_l);
        bool conditie = graph_m_transformed != NULL;
        REQUIRE(conditie == true);
        REQUIRE(graph_m_transformed->matrix != NULL);

        REQUIRE(graph_m_transformed->E == graph_m->E);
        REQUIRE(graph_m_transformed->V == graph_m->V);

        for(int i = 0; i < graph_m->V; ++i) {
            REQUIRE(graph_m_transformed->matrix[i] != NULL);
            for(int j = 0; j < graph_m->V; ++j) {
                REQUIRE(graph_m_transformed->matrix[i][j] == graph_m->matrix[i][j]);
            }
        }

	}
	
	
	SECTION("Eliberare memorie graf-matrice")
	{
        graph_l = readList(TASK2_TEST_FILENAME1);
        free_graph_list(&graph_l);
        bool conditie = graph_l == NULL;
        REQUIRE(conditie == true);
	}
	
}