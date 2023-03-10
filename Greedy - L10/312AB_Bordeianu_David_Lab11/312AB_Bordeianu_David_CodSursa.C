#include<stdio.h>
#include<stdlib.h>

typedef struct{

    float gi;
    float pi;
    float raport;
    int poz;
}obj;


//Citirea se face in modul urmator: Gmax, N, iar pentru cele N obiecte (gi, pi).
void citire(float *Gmax, int *N, obj **vect)
{
    int i;
    FILE *f;

    f=fopen("input1.txt", "rt");
    if(f==NULL)
        {
            puts("Nu s-a putut deschide fisierul.1");
            exit(1);
        }
    
    fscanf(f, "%f", Gmax);
    fscanf(f, "%d", N);

    *vect=(obj *)malloc(sizeof(obj)*(*N));
    if((*vect)==NULL)
        {
            puts("Alocare dinamica a vectorului esuata");
            exit(1);
        }

    for(i=0; i<(*N); i++)
        {
            fscanf(f, "%f", &(*vect)[i].gi);
            fscanf(f, "%f", &(*vect)[i].pi);
            
            (*vect)[i].raport=0;
            (*vect)[i].poz=i;
        }
    
    fclose(f);
}

void swap(obj *a, obj *b)
{
    obj aux;

    aux=*a;
    *a=*b;
    *b=aux;
}

int partition(obj *vect, int prim, int ultim)
{
    int l, k;
    obj piv;

    piv=vect[ultim];
    l=prim-1;

    for(k=prim; k<=ultim-1; k++)
        {
            if((vect[k].pi/vect[k].gi)>(piv.pi/piv.gi))
                {
                    l++;
                    swap(&vect[l], &vect[k]);
                }
        }
    
    swap(&vect[l+1], &vect[ultim]);

return (l+1);
}

void quicksort(obj *vect, int prim, int ultim)
{
    int piv;
    
    if(prim<ultim)
        {
            piv=partition(vect, prim, ultim);

            quicksort(vect, prim, piv-1);
            quicksort(vect, piv+1, ultim);
        }
}

void print(int total, obj *vect)
{
    int k;
    FILE *f;
    float nr=0;

    f=fopen("output.txt", "wt");
    if(f==NULL)
        {
            puts("Nu s-a putut deschide fisierul.2");
            exit(1);
        }

   for(k=0; k<total; k++)
       {
           fprintf(f, "%d     %.2f\n", vect[k].poz, vect[k].raport);
           nr=nr+vect[k].pi*vect[k].raport;
       }
    
    fprintf(f, "\nProfitul maxim este: %.2f", nr);

    fclose(f);
}

void grdy(float Gmax, int N, obj *vect)
{
    obj *nou;
    int m, n;
    float p;

    nou=(obj *)malloc(sizeof(obj)*N);
    if(nou==NULL)
        {
            puts("Alocare dinamica a vectorului esuata");
            exit(1);
        }

    n=0;
    m=0;
    p=0;

    while(p<Gmax)
        {
            if(p+vect[m].gi<=Gmax)
                {
                    p+=vect[m].gi;
                    nou[n]=vect[m];
                    nou[n].raport=1;
                    n++;
                }
                else
                    {
                        nou[n]=vect[m];
                        nou[n].raport=(Gmax-p)/vect[m].gi;
                        p=Gmax;
                        n++;
                    }
            
            m++;
        }
    
    print(n, nou);    
}

int main()
{
    float Gmax;
    int N;
    obj *vect;

    citire(&Gmax, &N, &vect);
    quicksort(vect, 0, N-1);
    grdy(Gmax, N, vect);
}