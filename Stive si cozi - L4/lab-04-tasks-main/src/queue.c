#include "utils.h"
#include "queue.h"
#include "queue_node.h"


/**
 * @brief Functie ce aloca dinamic memorie pentru coada,
 *        initializand campurile front si rear
 * 
 * @param queue - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru coada
 */
void createQueue(Queue **queue)
{
    *queue=(Queue *)malloc(sizeof(Queue));
    if(*queue==NULL)
        {
            puts("Alocarea dinamica a cozii a esuat.");
            exit(1);
        }
    
    (*queue)->front=NULL;
    (*queue)->rear=NULL;
}

/**
 * @brief Functie ce va fi folosita pentru a adauga un nod in coada queue
 * 
 * * Hint:
 *         * se va folosi functia createQueueNode pentru crearea unui nou nod
 *         * trebuie actualizati poniterii rear si front sau doar front
 *         * a se citi cursul :)
 * 
 * @param queue - coada in care trebuie adaugat un nou nod cu informatia data
 * @param data - datele noului nod
 */
void en(Queue *queue, char *data)
{
    queue_node *qp;

    qp=createQueueNode(data);

    if(queue->rear==NULL)
        queue->rear=qp;
        else
            {
                queue->rear->next=qp;
                queue->rear=qp;
            }
    
    if(queue->front==NULL)
        queue->front=queue->rear;
}

/**
 * @brief Functie ce scoate din coada urmatorul nod si
 *        returneaza datele stocate in nod.
 * * Hint:
 *        * a se citi cursul :)
 * 
 * @param queue - coada din care va fi scos nodul 
 * @return char* - datele din interiorul nodului
 */
char *de(Queue *queue){

    queue_node *auxnod;
    char *auxdata;

    if(isEmptyQueue(queue))
        return '\0';
    
    auxnod=queue->front;

    auxdata=(char *)malloc(sizeof(char)*(strlen(auxnod->data)+1));
    strcpy(auxdata, auxnod->data);

    queue->front=queue->front->next;
    free(auxnod);

return auxdata;
}

/**
 * @brief Functie ce va elibera memoria asociata fiecarui nod al cozi
 *  
 *  * Hint:
 *          * se poate folosi functia deleteQueueNode
 * @param queue - coada a carui noduri vor fi sterse
 */
void deleteQueue(Queue *queue){

    queue_node *ax;
    
    while(isEmptyQueue(queue))
        {
            ax=queue->front;
            queue->front=queue->front->next;
            deleteQueueNode(ax);
            free(ax);
        }
}

/**
 * @brief Functie ce testeaza pointerii rear si front pentru 
 *        a determina daca coada este goala
 * 
 * @param queue - coada ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyQueue(Queue *queue)
{
    if(queue->front==NULL)
        return true;
     else
         return false;
}
