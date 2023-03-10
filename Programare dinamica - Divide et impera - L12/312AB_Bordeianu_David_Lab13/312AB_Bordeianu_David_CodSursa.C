#include<stdio.h>
#include<stdlib.h>

//Citire
void readfile(int ***a, int *N, char *numefisier)
{
    FILE *f;
    int k, l;

    f=fopen(numefisier, "rt");
    if(f==NULL)
        {
            printf("\nFisierul-input nu s-a putut deschide.\n");
            exit(1);
        }
    
    fscanf(f, "%d", N);

    (*a)=(int **)malloc(((*N)+2)*sizeof(int*));
    for(k=0; k<=(*N)+1; k++)
        (*a)[k]=(int *)malloc(sizeof(int)*((*N)+2));
    
    for(k=1; k<=(*N); k++)
        for(l=1; l<=(*N); l++)
            fscanf(f, "%d", &(*a)[k][l]);
    
    fclose(f);
}

//Bordare
void BRD(int N, int ***a)
{
    //int k;

    for(int k=0; k<=N+1; k++)
        {
            (*a)[k][0]=-1;
            (*a)[k][N+1]=-1;
        }

    for(int l=0; l<=N+1; l++)
        {
            (*a)[0][l]=-1;
            (*a)[N+1][l]=-1;
        }
}

//Afisare
void print(int **a, int N, int nr_o, char *numefisier)
{
    FILE *f;
    int k, l;

    f=fopen(numefisier, "wt");
    if(f==NULL)
        {
            printf("\nFisierul-output nu s-a putut deschide.\n");
            exit(1);
        }
    
    fprintf(f, "%d\n", nr_o);

    for(k=1; k<=N; k++)
        {
            for(l=1; l<=N; l++)
                fprintf(f, "%4d", a[k][l]);
            
            fprintf(f, "\n");
        }
    
    fclose(f);
}

//Definirea fiecarui obiect
void OBJ(int x, int y, int ***a, int nr_o)
{
    if((*a)[x][y]==0)
        {
            (*a)[x][y]=nr_o;

            OBJ(x-1, y, a, nr_o);
            OBJ(x-1, y-1, a, nr_o);
            OBJ(x-1, y+1, a, nr_o);

            OBJ(x, y-1, a, nr_o);
            OBJ(x, y+1, a, nr_o);
            
            OBJ(x+1, y-1, a, nr_o);
            OBJ(x+1, y, a, nr_o);
            OBJ(x+1, y+1, a, nr_o);
        }
}

int main()
{
    int nr_o=0, N, **a, i, j;

//Primul test
    readfile(&a, &N, (char*)"input1.txt");

    BRD(N, &a);

    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            if(a[i][j]==0)
                {
                    nr_o++;
                    OBJ(i, j, &a, nr_o);
                }

    print(a, N, nr_o, (char*)"output1.txt");

//Al doilea test    
    nr_o=0;
    /*
    for(i=0; i<=N+1; i++)
        free(a[i]);

    free(a);
    */

    readfile(&a, &N, (char*)"input2.txt");

    BRD(N, &a);

    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            if(a[i][j]==0)
                {
                    nr_o++;
                    OBJ(i, j, &a, nr_o);
                }

    print(a, N, nr_o, (char*)"output2.txt");

    for(i=0; i<=N+1; i++)
        free(a[i]);

    free(a);

return 0;
}