/**
 * @brief in this file are defined all the common functions used in the
 * 		  test suite
 * @author Rusu Gabriel
 * 
 */
#include "test-utils.hpp"

graph_matrix* readMatrix(const char * test_task_data)
{
	std::ifstream file(test_task_data);
	int v, e;
	file >> v >> e;
	graph_matrix* graph = new graph_matrix;
    graph->V = v;
    graph->E = e;
    graph->matrix = new int*[v];
    for(int i = 0; i < v; ++i) {
        graph->matrix[i] = new int[v];
        for(int j = 0; j < v; ++j) {
            file >> graph->matrix[i][j];
        }
    }
	
	return graph;
}

graph_list* readList(const char * test_task_data)
{
	std::ifstream file(test_task_data);
	int v, e;
	file >> v >> e;

    graph_list* graph = new graph_list;
    graph->E = e;
    graph->V = v;
    graph->listHeads = new node*[v];

    for(int i = 0; i < v; ++i) {
        graph->listHeads[i] = NULL;
        int n;
        file >> n;
        for(int j = 0; j < n; ++j) {
            int val;
            file >> val;
            node* newNode = new node;
            newNode->next = NULL;
            newNode->vertexNr = val;

            node* root = graph->listHeads[i];
            if(root == NULL) {
                graph->listHeads[i] = newNode;
            }
            else {
                while(root->next != NULL) {
                    root = root->next;
                }  
                root->next = newNode;
            }
            
        }
    }

	return graph;
}

std::vector<std::vector<int>> readRoads(const char * test_task_data) {
    std::vector<std::vector<int>> sol;

    std::ifstream file(test_task_data);
	int n;
    file >> n;

    for(int i = 0; i < n; ++i) {
        sol.push_back(std::vector<int>());

        for(int j = 0; j < n; ++j) {
            int val;
            file >> val;
            sol[i].push_back(val);
        }
    }

    return sol;
}
