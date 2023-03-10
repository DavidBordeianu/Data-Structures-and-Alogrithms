#include "utils.h"

/**
 * O functie ce transforma un graf reprezentat prin liste de adiacenta 
 * intr-unul reprezentat cu ajutorul unei matrice de adiacenta
 * @note   Nodurile trebuie indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
graph_matrix* listToMatrix(graph_list* graph) {

    graph_matrix *gf;
    int i;
    node *p;

    gf=(graph_matrix *)malloc(sizeof(graph_matrix));
    if(gf==NULL)
        {
            puts("Alocarea dinamica a grafului esuata.");
            exit(1);
        }

    gf->V=graph->V;
    gf->E=graph->E;

    gf->matrix=(int **)malloc(sizeof(int)*graph->V);
    if(gf->matrix==NULL)
        {
            puts("Alocarea dinamica a matricei graficului esuata.");
            exit(1);
        }

    for(i=0; i<graph->V; i++)
        gf->matrix[i]=(int *)calloc(graph->V, sizeof(int));
    
    
    for(i=0; i<graph->V; i++)
        {
            p=graph->listHeads[i];
            while(p)
                {
                    gf->matrix[i][p->vertexNr]=1;
                    p=p->next;
                }
        }

return gf;
}


/**
 * Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_list(graph_list** graph) {

    int i;

    for(i=0; i<(*graph)->V; i++)
        free((*graph)->listHeads[i]);    

    free((*graph)->listHeads);
    free((*graph));
    (*graph)=NULL;

}


void print_graph_matrix(graph_matrix* graph) {
    // nice to have; functie de afiseaza continutul unui graf reprezentat prin matrice de adiacenta
}