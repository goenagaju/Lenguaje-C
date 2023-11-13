/**7.1.3 Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere
un vector de 10 posiciones con el contenido de ambos vectores intercalados*/

#include <stdio.h>

void cargaVec (int [],int);
void unirVecs (int [], int [], int [], int);
void mostrarvec(int [],int);

int main ()

{
    int v1[5],v2[5],vu[10];

    printf ("\nIngresar valores del primer vector:");
    cargaVec (v1,5);

    printf ("\nIngresar valores del segundo vector:");
    cargaVec (v2,5);

    unirVecs (v1,v2,vu,10);
    mostrarvec (vu,10);
}

//funciones

void cargaVec (int v[], int ce)
{
    int i, dato;


    for (i=0; i<ce ; i++)
    {
        printf ("\n%d:", i+1);
        scanf("%d",&dato);
        v[i]=dato;

    }
}

////////////////////////////////
void unirVecs (int v1[],int v2[],int vu[], int ce)
{
    int i;

    for (i=0;i<ce;i++)
    {
        if (i%2==0)
            vu[i]=v1[i];
        else
            vu[i]=v2[i];
    }
}

/////////////////////////////////

void mostrarvec (int v[], int ce)
{
    int i ;

    for (i=0;i<ce;i++)
    {
        printf("\n%d", v[i]);
    }
}
