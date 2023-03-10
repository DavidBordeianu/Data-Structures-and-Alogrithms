#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce elimina elementele cu informatii duplicate
 * Hint:
 *      * parcurgeti lista si modificati nodurile a.i sa elimi-
 *        nati duplicatele
 *      * daca capul listei nu se modifica va trebuii 
 *        sa il returnati
 * 
 * @param list - capul listei ce trebuie sa fie procesata
 * @return node* - returneaza capul listei
 */
node *removeDuplicates(node *list)
{
    node *q, *p, *del;

    q=list;

    while(q!=NULL && q->next!=NULL)
        {
            p=q;

            while(p->next!=NULL)
                if(q->data==p->next->data)
                    {
                        del=p->next;
                        p->next=del->next;         
                        free(del);
                    }
                    else
                        p=p->next;
            q=q->next;
        }
    
return list;
}
