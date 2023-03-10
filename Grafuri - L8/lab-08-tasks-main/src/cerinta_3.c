#include "utils.h"

/**
 * Implementati o functie ce ce genereaza matricea drumurilor unui graf reprezentat cu 
 * ajutorul matricei de adiacenta
 * @note   
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - o matrice reprezentand matricea drumurilor
 */
int** findPaths(graph_matrix* graph) {

    int **mat, i, j, k;

    mat=(int **)malloc(sizeof(int)*graph->V);
    if(mat==NULL)
        {
            puts("Alocarea dinamica a matricei esuata.");
            exit(1);
        }
    

    for(i=0; i<graph->V; i++)
        {
            mat[i]=(int *)calloc(graph->V, sizeof(int));
        }
    
    mat=graph->matrix;

    for(i=0; i<graph->V; i++)
        for(k=0; k<graph->V; k++)
            for(j=0; j<graph->V; j++)
                if(k!=j && mat[k][j]==0 && mat[k][i]==1 && mat[i][j]==1)
                    mat[k][j]=1;

return mat;
}