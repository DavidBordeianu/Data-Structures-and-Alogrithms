#include "merge.h"
#include "quick.h"
#include "utils.h"

//----- MergeSort -----

/**
 * Implementarea metodei "merge" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param middle - pozitia din mijloc
 * @param right - pozitia finala
 */
void merge(int *arr, int left, int middle, int right)
{
    int nr1, nr2, *v1, *v2, i, j, k;

    nr1= middle-left+1;
    nr2= right-middle;

    v1=(int *)malloc(sizeof(int)*nr1);
    v2=(int *)malloc(sizeof(int)*nr2);

    for(i=0; i<nr1; i++)
        v1[i]=arr[i+left];
    
    for(i=0; i<nr2; i++)
        v2[i]=arr[i+middle+1];
    
    i=0;
    j=0, k=left;

    while(i<nr1 && j<nr2)
        {
            if(v1[i]<v2[j])
                {
                    arr[k]=v1[i];
                    i++;
                }
                else
                    {
                        arr[k]=v2[j];
                        j++;
                    }
            k++;
       }
    
    while(j<nr2)
        {
            arr[k]=v2[j];
            j++;
            k++;
        }

    while(i<nr1)
        {
            arr[k]=v1[i];
            k++;
            i++;
        }

free(v1);
free(v2);
}

/**
 * Implementarea metodei "mergesort" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param right - pozitia finala
 */
void mergesort(int *arr, int left, int right)
{
    int mid;

    if(left<right)
        {
            mid = (left+right)/2;
            mergesort(arr, left, mid);
            mergesort(arr, mid+1, right);
            merge(arr, left, mid, right);
        }
}

//----- Quick Sort -----

/**
 * Implementarea metodei de interschimbare a doua elemente
 * @param x - primul element
 * @param y - al doilea element
 */
void swap(int *x, int *y)
{
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

/**
 * Implementarea metodei de partitionare din cadrul algoritmului Quick Sort
 * Consideram pivotul a fi ultimul element din vector
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
int partition(int *arr, int low, int high)
{
    int piv, i, k;

    piv=arr[high];
    i=low-1;

    for(k=low; k<high; k++)
        if(arr[k]<=piv)
            {
                i++;
                swap(&arr[i], &arr[k]);
            }
    
    swap(&arr[i+1], &piv);

    i++;

return i;
}

/**
 * Implementarea metodei "quicksort" din cadrul algoritmului Quick Sort
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
void quicksort(int *arr, int low, int high)
{
    int poz;

    if(low<high)
        {
            poz=partition(arr, low, high);
            quicksort(arr, low, poz-1);
            quicksort(arr, poz+1, high);
        }
}

//----- Analiza functiilor -----

/**
 * Care dintre metodele anterior implementate reprezinta metode de sortare stabile
 * si care reprezinta metode de sortare instabile? Argumentati.
     
    QuickSort este instabil, iar Mergesort este stabil.
    QuickSort este instabil, deoarece elementele se interschimba intre ele in functie de pozitia pivotului, fara a fi luata in seama pozitia originala.
    Pe de alta parte, Mergesort este stabil, deoarece fiecare element din sir isi mentine pozitia originala in relatie cu celelalte elemente.
 */