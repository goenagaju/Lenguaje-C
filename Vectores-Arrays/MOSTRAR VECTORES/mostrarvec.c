#include <stdio.h>

// funciones
void cargaVec (int[], int);
void mostrarContenidoVec (int [], int);
void mostrarPosicionVec (int [], int);
void mostrarOrdenVec (int [], int);

int main ()

{
    int vec [5];

    cargaVec (vec,5);
    mostrarContenidoVec (vec,5);
    mostrarPosicionVec (vec,5);
    mostrarOrdenVec (vec,5);

}

//funciones
void cargaVec (int v[], int ce)

{
    int i;


    for (i=0; i<ce;i++)
    {
        printf ("\nIngresar un numero:");
        scanf ("%d" , &v[i]);
    }
}
/////////////////////////////////////////////////////////
void mostrarContenidoVec (int v[], int ce )

{
    int i;

        printf ("\nCONTENIDO");

    for (i=0;i<ce;i++)
    {
        printf ("\n\t %d\n", v[i]);
    }
}
/////////////////////////////////////////////////////////
void mostrarOrdenVec (int v[], int ce)
{
    int i;

    printf ("\n\nORDEN");

    for (i=0;i<ce;i++)
    {
        printf ("\n %d \t %d\n", i+1 , v[i]);
    }
}
/////////////////////////////////////////////////////////
void mostrarPosicionVec (int v[], int ce)
{
    int i;

    printf ("\nPOSICION");

    for (i=0;i<ce;i++)
    {
        printf ("\n %d \t %d\n", i , v[i]);
    }
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
