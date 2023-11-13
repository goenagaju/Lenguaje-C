/*7.1.2 Realizar una función que reciba por parámetro dos vectores enteros
de 5 elementos cada uno y genere un vector de 10 posiciones con el contenido
de ambos vectores uno a continuación del otro.*/

#include<stdio.h>

//funciones

void cargaVec (int [],int);
void unirVecs (int [], int [], int [], int);
void mostrarVeccs(int [], int [], int [],int, int);

int main ()
{
        int vec1 [5], vec2[5], vec3[10];

        printf ("\ningresar valores para el primer vector:\n");

        cargaVec(vec1,5);

        printf ("\ningresar valores para el segundo vector:\n");

        cargaVec(vec2,5);

        unirVecs (vec1,vec2,vec3,10);

        mostrarVeccs (vec1,vec2,vec3,5,10);
}

/////funciones///////

void cargaVec (int v[], int ce)
{
    int i,d;

    for(i=0;i<ce;i++)
    {
        printf("\n%d : ", i+1);
        scanf("%d", &d);
        v[i]=d;
    }
}

//////////////////////////////////////////////////////////////////////
void unirVecs (int v1[],int v2[],int vu[],int ce)

{
    int i;

    for (i=0;i<ce;i++)
    {
        vu[i]=v1[i]; // i=2 , v3[2]=v1[2]

        vu[i+ce]=v2[i]; // i=2 , v3[0+5=5]=v2[0]
    }

}
////////////////////////////////////////////////////////////////////
void mostrarVeccs (int v1[],int v2[],int v3[],int ce1, int ce2)

{
    int i,j;

    printf ("\nORDEN \t V1 \t V2");

    for (i=0;i<ce1;i++)
    {
        printf("\n %d \t %d \t %d", i+1,v1[i],v2[i]);
    }

    printf ("\n\n ---- Vector unido -----");

    for (j=0;j<ce2;j++)
    {
        printf("\n%d", v3[j]);
    }



}
