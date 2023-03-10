#include "stack_node.h"

/**
 * @brief Functie ce creaza un nod pentru stiva
 * 
 * 
 * @param data - informatiile noului nod
 * @return stack_node* - pointer-ul noului 
 */
stack_node *createStackNode(char data)
{
    stack_node *p;

    p=(stack_node *)malloc(sizeof(stack_node));
    if(p==NULL)
        {
            puts("Alocarea dinamica a nodului a esuat.");
            exit(1);
        }
    
    p->data=data;
    p->next=NULL;

return p;
}