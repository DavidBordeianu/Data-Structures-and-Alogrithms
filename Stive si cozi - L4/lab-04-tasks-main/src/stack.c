#include "utils.h"
#include "stack.h"
#include "stack_node.h"

/**
 * @brief Functie ce aloca dinamic memorie pentru stiva,
 *        initializand campurile head si size
 * 
 * @param stack - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru stiva
 */

void createStack(Stack **stack)
{
    (*stack)=(Stack *)malloc(sizeof(Stack));
    if((*stack)==NULL)
        {
            puts("Alocarea dinamica a stivei a esuat.");
            exit(1);
        }

    (*stack)->head=NULL;
    (*stack)->size=0;
}

/**
 * @brief Functie ce dealoca memoria pentru stiva
 * 
 * @param stack - stiva a carei elemente trebuie sterse
 */
void deleteStack(Stack *stack)
{
    stack_node *nd;

    while(isEmptyStack(stack))
        {
            nd=stack->head;
            stack->head=stack->head->next;
            free(nd);
            stack->size--;                        
        }
}

/**
 * @brief Functie ce adauga un nou nod in stiva
 * 
 *  * Hint:
 *          * a se citi cursul :)
 *          * se va modifica pointer-ul head al structurii Stack
 * 
 * @param stack - stiva in care se va adauga un nou nod
 * @param data - informatiile noului nod
 */
void push(Stack *stack, char data)
{
    stack_node *nd;

    nd=createStackNode(data);
    stack->size++;

    if(isEmptyStack(stack))
        stack->head=nd;
        else
            {
                nd->next=stack->head;
                stack->head=nd;
            }
}

/**
 * @brief Functie ce elimina urmatorul nod din stiva
 * 
 *  * Hint:
 *          * a se citi cursul :)
 *          * se va modifica pointer-ul head al structurii Stack
 * 
 * @param stack - stiva din care se va elimina nodul
 * @param data - informatiile nodului scos
 */
char pop(Stack *stack)
{
    stack_node *q;
    char aux;

    if(isEmptyStack(stack))
        return 'E';
    
    q=stack->head;
    aux=q->data;

    stack->head=stack->head->next;
    free(q);

    stack->size--;

return aux;
}

/**
 * @brief Functie ce testeaza dimensiune stivei pentru a vedea daca este goala
 * 
 * @param stack - stiva ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyStack(Stack *stack)
{
    if(stack->size==0)
        return true;
        else
            return false;
}
