#include "list.h"
#include "utils.h"



/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param number - numarul pe care il are copilul
 * @param name - numele copilului
 * @param next  - adresa urmatorului nod
 * @return childNode* - nou nod creat
 */
childNode *makeChildNode(int number, const char *name, childNode *next)
{    
    childNode *p;

    p=(childNode *)malloc(sizeof(childNode));
    
    p->name=(char *)malloc((1+strlen(name))*sizeof(char));
    strcpy(p->name, name);

    p->number=number;
    p->next=next;

return p;    
}




/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeChildNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return childNode* 
 */
childNode *makeCircularList(FILE *file)
{
    char nume[70];
    childNode *p, *head, *q;
    int ok=0, x;

    while(fscanf(file, "%d", &x)!=EOF)
        {
            fscanf(file, "%s", nume);

            if(ok==0)
                {
                    head=makeChildNode(x, nume, NULL);
                    ok=1;

                    q=(childNode *)malloc(sizeof(childNode));
                    q=head;
                }
                else
                  {                      
                      p=makeChildNode(x, nume, head);
                      head=p;
                  }
        }

    q->next=head;

return head;
}


/**
 * @brief Functie ce 
 * 
 * @param head - capul listei ce reprezinta cercul de copii
 * @param p - pasul ce va fi luat pentru eliminarea copiilor
 * @return childNode* 
 */
childNode *playJosephGame(childNode *head, int p)
{
    childNode *q, *nou, *v1, *v2;
    int contor, ok=0;

    v1=head;
    v2=head;
    while(v1->next!=v1)
        {
            contor=1;
            if(ok==0)
                {
                    while(contor<p)
                        {
                            v2=v1;
                            v1=v1->next;
                            contor++;
                        }
                    nou=makeChildNode(v1->number, v1->name, NULL);

                    ok=1;
                    
                    v2->next=v1->next;
                    free(v1);
                    v1=v2->next; 
                }
            else
                {
                    while(contor<p)
                        {
                            v2=v1;
                            v1=v1->next;
                            contor++;
                        }
                    q=makeChildNode(v1->number, v1->name, nou);
                    nou=q;

                    v2->next=v1->next;
                    free(v1);
                    v1=v2->next;
                }
        }

    q=makeChildNode(v1->number, v1->name, nou);
    nou=q;

    v2->next=v1->next;
    free(v1);
    v1=v2->next;

return nou;
}