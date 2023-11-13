/**7.1.4 Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si son guales o un
0 sino lo son.*/

#include <stdio.h>

void cargavec (int[], int);
int igualarvec (int [], int [], int);


int main ()

{
    int v1[5], v2[5], retorno;

    printf ("\nCargar primer vector:");
    cargavec (v1,5);
    printf ("\nCargar segundo vector:");
    cargavec (v2,5);
    retorno=igualarvec(v1,v2,5);

    if (retorno==0)
        printf ("\nLos vectores no son iguales.");
    else
        printf("\nLos vectores son iguales.");

}

////// funciones

void cargavec (int v[] , int ce)
{
    int i , dato ;

    for (i=0;i<ce;i++)
    {
        printf("\n%d:", i+1);
        scanf("%d", &dato);
        v[i]=dato;
    }
}

//////////////////
int igualarvec (int v1[], int v2[],int ce)
{
   int i, igual=0;

   for (i=0;i<ce;i++)
   {
       if (v1[i]==v2[i])
        igual++;
   }

        if (igual==ce)
            return 1;
        else
            return 0;

}
