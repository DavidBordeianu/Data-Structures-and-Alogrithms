#include "utils.h"


/**
 * O functie ce transforma un graf reprezentat de o matrice de adiacenta 
 * intr-unul reprezentat cu ajutorul listelor de adiacenta
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - Graful in reprezentarea liste de adiacenta
 */
graph_list* matrixToList(graph_matrix* graph) {

    graph_list *gf;
    int i, j;
    node *p, *nn;

    gf=(graph_list *)malloc(sizeof(graph_list));
    if(gf==NULL)
        {
            puts("Alocarea dinamica a grafului esuata.");
            exit(1);
        }
    
    gf->V=graph->V;
    gf->listHeads=(node **)malloc(gf->V * sizeof(node));
    gf->E=graph->E;

    for(i=0; i<gf->V; i++)
        {
            p=NULL;

            for(j=0; j<graph->V; j++)
                if(p==NULL && graph->matrix[i][j]==1)
                    {
                        nn=(node *)malloc(sizeof(node));
                        nn->vertexNr=j;
                        nn->next=NULL;

                        gf->listHeads[i]=nn;
                        p=gf->listHeads[i];
                    }
                    else
                        {
                            if(p!=NULL && graph->matrix[i][j]==1)
                                {
                                    nn=(node *)malloc(sizeof(node));
                                    nn->vertexNr=j;
                                    nn->next=NULL;

                                    p->next=nn;
                                    p=p->next;
                                }
                        }
        }
        
return gf;
}

/**
 * Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_matrix(graph_matrix** graph) {

    int i;

    for(i=0; i<(*graph)->V; i++)
        free((*graph)->matrix[i]);    

    free((*graph)->matrix);
    free((*graph));
    (*graph)=NULL;
}

/*
node* push_values(node* root, int val) {
    // nice to have; functie de adauga o valoare intr-o lista
}


void print_graph_list(graph_list* graph) {
    // nice to have; functie care afiseaza continutul unui graf reprezentat prin liste de adiacenta
}
*/



