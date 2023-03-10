#include "queue_node.h"
#include "utils.h"

/**
 * @brief Functie ce copiaza sirul de caractere data si atribuie
 *        adresa de memorie a noului sir campului data al noului
 *        nod creat
 * 
 * @param data 
 * @return queue_node* 
 */
queue_node *createQueueNode(char *data)
{
    queue_node *qp;

    qp=(queue_node *)malloc(sizeof(queue_node));
    if(qp==NULL)
       {
           puts("Alocarea dinamica a nodului din coada a esuat.");
           exit(1);
       }    
    
    qp->data=(char *)malloc(sizeof(char)*(strlen(data)+1));
    strcpy(qp->data, data);
    
    qp->next=NULL;

return qp;
}

/**
 * @brief Functie ce face eliberarea de memorie pentru nodul oldNode
 * 
 * * Hint:
 *         * doar campul data necesita eliberarea memoriei, acesta fiind alocat dinamic
 * 
 * @param oldNode - nodul a carui date trebuie sterse
 */
void deleteQueueNode(queue_node *oldNode){

    free(oldNode->data);
}