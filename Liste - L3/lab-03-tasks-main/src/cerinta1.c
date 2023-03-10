#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param data - informatia nodului respectiv
 * @param next - adresa urmatorului nod
 * @return node* nou nod creat
 */
node *makeNode(int data, node *next)
{
    node *q;

    q=(node *)malloc(sizeof(node));

    q->data=data;
    q->next=next;

return q;
}



/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return node* 
 */
node *makeList(FILE *file)
{
    int x, nr, v1, v2;
    node *head, *p;

    nr=0;

    while(fscanf(file, "%d", &x)!=EOF)
        {
            if(nr==0)
                {
                    head=makeNode(x, NULL);
                    v1=head->data;
                }
               else if(nr==1)
                    {
                        p=makeNode(x, head);
                        head=p;
                        v2=head->data;
                    }
                  else
                  {
                      if(v1==v2)
                          {
                              p=makeNode(x, head);
                              head=p;
                              v2=head->data;
                          }

                      if(v1>=v2 && x<=head->data)
                          {
                              p=makeNode(x, head);
                              head=p;
                          }
                      else if(v1<=v2 && x>=head->data)
                               {
                                   p=makeNode(x, head);
                                   head=p;
                               }
                  }

            nr++;
          }

return head;
}


/**
 * @brief Functie ce afiseaza toate elementele unei liste
 *  
 * @param head - capul listei de afisat

void print(node *head)
{
    node *cophead;
    cophead=head;

    while(cophead!=NULL)
        {
            printf("%d", cophead->data);
            cophead=cophead->next;
        }      
}
*/