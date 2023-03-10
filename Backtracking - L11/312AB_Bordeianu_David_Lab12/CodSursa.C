#include<stdio.h>
#include<stdlib.h>

typedef struct{

    float gi;
    float pi;
    int idx;
}obj;

typedef struct{

    float gi;
    float pi;
    int *select;
}rez;

//Citirea se face in modul urmator: Gmax, N, iar pentru cele N obiecte (gi, pi).
void citire(float *Gmax, int *N, obj **vect, int **rank)
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
    
    *rank=(int *)malloc(sizeof(int)*(*N));

    for(i=0; i<(*N); i++)
        {
            fscanf(f, "%f", &(*vect)[i].gi);
            fscanf(f, "%f", &(*vect)[i].pi);
            
            (*rank)[i]=i+1;
            (*vect)[i].idx=i;
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

void rucsac(int N, obj *vect, float Gmax, rez tt, int pozitie, rez *ok, int *nr)
{
    int j;
    float cp=0;

    if(N<=pozitie)
        {
            if((*ok).pi<=tt.pi)
                {
                    (*nr)++;

                    for(j=0; j<N; j++)
                        (*ok).select[j]=tt.select[j];
                    
                    (*ok).pi=tt.pi;
                    (*ok).gi=tt.gi;
                }
        }
            else
                {
                   if(tt.gi+vect[pozitie].gi<=Gmax)
                        {
                            tt.select[pozitie]=1;

                            tt.gi+=vect[pozitie].gi;
                            tt.pi+=vect[pozitie].pi;

                            rucsac(N, vect, Gmax, tt, pozitie+1, ok, nr);

                            tt.select[pozitie]=0;

                            tt.pi-=vect[pozitie].pi;
                            tt.gi-=vect[pozitie].gi;
                        }
                    }
    for(j=pozitie+1; j<N; j++)
        cp+=vect[j].pi;
    
    if((*ok).pi<(cp+tt.pi))
        rucsac(N, vect, Gmax, tt, pozitie+1, ok, nr);
}

void print(rez ok, int N, obj *vect, int *rank)
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

    fprintf(f, "Pozitie \t Greutate:\tProfit:\n");

    for(k=0; k<N; k++)
        {
            if(ok.select[k]>0)
                fprintf(f, "%d \t\t\t %.2f \t\t%.2f \n", rank[vect[k].idx], vect[k].gi, vect[k].pi);
        }
    
    fprintf(f, "\nGreutatea aflata in rucsac este %.2f\nProfitul maxim este: %.2f", ok.gi, ok.pi);

    fclose(f);
}

int main()
{
    float Gmax, fp, fw;
    int N, nr, *rank; 
    obj *vect;
    rez tt, ok;

    citire(&Gmax, &N, &vect, &rank);

    quicksort(vect, 0, N-1);

    ok.pi=0;
    ok.gi=0;
    ok.select=(int *)calloc(N, sizeof(int));

    nr=0;

    tt.pi=0;
    tt.gi=0;
    tt.select=(int *)calloc(N, sizeof(int));

    rucsac(N, vect, Gmax, tt, 0, &ok, &nr);

    print(ok, N, vect, rank);

return 0;
}
