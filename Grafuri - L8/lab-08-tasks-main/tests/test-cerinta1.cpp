#include "test-utils.hpp"


TEST_CASE("Cerinta 1: Transformare din reprezentare cu matrice in reprezentare cu lista de adiacenta")
{
	
	graph_list* graph_l;
    graph_list* graph_l_transformed;
    graph_matrix* graph_m;

	SECTION("Transformare")
	{
		graph_l = readList(TASK1_TEST_FILENAME1);
        graph_m = readMatrix(TASK1_TEST_FILENAME2);
        graph_l_transformed = matrixToList(graph_m);
        REQUIRE(graph_l_transformed != NULL);
        REQUIRE(graph_l_transformed->listHeads != NULL);

        REQUIRE(graph_l_transformed->E == graph_l->E);
        REQUIRE(graph_l_transformed->V == graph_l->V);

        for(int i = 0; i < graph_l->V; ++i) {
            node* newNode = graph_l_transformed->listHeads[i];
            node* refNode = graph_l->listHeads[i];
            while(refNode != NULL) {
                bool conditie = newNode != NULL;
                REQUIRE(conditie == true);
                REQUIRE(newNode->vertexNr == refNode->vertexNr);
                refNode = refNode->next;
                newNode = newNode->next;
            }
        }

	}
	
	
	SECTION("Eliberare memorie graf-matrice")
	{
        graph_m = readMatrix(TASK1_TEST_FILENAME2);
        free_graph_matrix(&graph_m);
        bool conditie = graph_m == NULL;
        REQUIRE(conditie == true);
	}
	
}