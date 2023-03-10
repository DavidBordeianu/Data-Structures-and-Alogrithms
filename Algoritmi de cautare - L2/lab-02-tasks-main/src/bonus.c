#include "utils.h"
#include "counting.h"

//----- Counting Sort -----

/**
 * Implementarea algoritmului counting sort
 * Restrictii: 0 <= arr[i] < 50
 * Dimensiunea vectorului de frecventa va fi 50
 * @param arr - vectorul care trebuie sortat
 * @param dim - dimensiunea vectorului
 * @return vectorul de frecventa utilizat in algoritm
 */
int* countingSort(int *arr, int dim)
{
    int v[dim];
    int i, cnt[50], nr, total;

    for(i=0; i<50; i++)
        cnt[i]=0;
    
    for(i=0; i<dim; i++)
        cnt[arr[i]]++;

    total=0;

    for(i=0; i<50; i++)
        {
            nr=cnt[i];
            cnt[i]=total;
            total+=nr;
        } 

    for(i=0; i<dim; i++)
        {
            v[cnt[arr[i]]]=arr[i];
            cnt[arr[i]]++;
        }
    
    for(i=0; i<dim; i++)
        arr[i]=v[i];

return arr;
}

/**
 * Care este complexitatea spatiala si cea temporala?
 * De ce nu este mai folosit?

   Complexitatea este O(dim+max), unde dim este dimensiunea vectorului ce trebuie sortat, iar max este numarul maxim din acest sir (arr[i]<max pentru orice i).

   Algoritmul Counting Sort este un algoritm ineficient deoarece poate fi folosit doar pentru valori simple (spre exemplu nr. intregi), intrucat altfel vectorul de frecventa 
     nu poate fi construit. De asemenea, este greu de implementat pentru un set mare de date, cat si pentru valori de tip sir de caractere. Singura instanta cand acesta este
     eficient, este atunci cand lungimea intervalului de valori ale elementelor din vector este suficient de mica in raport cu lungimea vectorului.

 
 */