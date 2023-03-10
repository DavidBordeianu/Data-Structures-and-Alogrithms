#include "functions.h"
#include "utils.h"

/**
 * @brief Functie ce testeaza daca cuvantul primit ca parametru este "stop"
 * 
 *  * Hint:
 *          * puteti folosi functia strcmp(...) pentru comparare de siruri de caractere
 * 
 * @param word cuvantul ce trebuie testat
 * @return true/false in functie de rezultatul comparatiei cu "stop" 
 */
bool isNotStop(const char *word)
{
    if(strcmp(word, "stop")==0)
        return true;
            else
                return false;
}

/**
 * @brief Functie ce citeste cuvant cu cuvant din fisierul primit ca parametru, adauga fiecare cuvant citit in coada
 *        pana la intalnirea cuvantului "stop"
 * 
 * * Hint:
 *      * se vor implementa mai intai functiile asociate stivei si cozi
 * 
 * @param queue - coada ce trebuie populata cu cuvinte
 * @param file - fisierul din care se face citirea
 */
void readInputIn(Queue *queue, FILE *file)
{
    char cuvant[40];

    while(fscanf(file, "%s", cuvant)!=EOF)
        {
            if(isNotStop(cuvant)==1)
                break;
            
            en(queue, cuvant);
        }
}

/**
 * @brief Functie ce parcurge coada de cuvinte, populeaza o stiva pentru inversarea cuvantului,
 *        dupa inversarea cuvantului continutul stivei este transferat in stiva results cu ajutorul
 *        operatiilor pop/push
 * * Hint:
 *      * se vor implementa mai intai functiile asociate stivei si cozi
 *      * detaliile de functioare se gasesc si in sectiunea HINTURI din README
 * 
 * @param queue - coada de cuvinte ce trebuie procesata
 * @param results - stiva ce contine rezultatul final al inversarii oridini cuvintelor
 */
void processInput(Queue *queue, Stack *results)
{
    Stack *stiva;
    char *cuv, car;
    int nr=0, i;
    //stack_node *p;

    createStack(&stiva);

    //cap=queue->front;
    while(!isEmptyQueue(queue))
        {
            cuv=de(queue);
            nr=strlen(cuv);

            for(i=0; i<nr; i++)
                {
                    push(stiva, cuv[i]);
                    i++;
                }

            while(!isEmptyStack(stiva))
                {
                    car=pop(stiva);
                    push(results, car);
                } 
        }
}
