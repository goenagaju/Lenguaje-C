/*7.1.1 Ingresar un vector de 10 unidades reales mediante una función llamada CARGA. Luego mediante una
segunda función llamada INVERTIR, generar un segundo vector del mismo tamaño con los elementos ubicados
en el orden inverso al del vector original. Mostrar el vector invertido con una función llamada MOSTRAR.*/
#include <stdio.h>

//funciones

void cargarvec (float [],int);
void invertirvec (float [],float [], int);
void mostrarvec (float[], int);

int main ()
{
    float vec1[5], vec2[5];

    cargarvec (vec1,5);
    invertirvec (vec1,vec2,5);
    mostrarvec(vec2,5);

}

//funciones

void cargarvec (float v[], int ce)
{
    int i;
    float dato;

    printf ("\nIngresar valores del vector:");

    for (i=0;i<ce;i++)
    {
        printf ("\n%d : ", i+1);
        scanf("%f", &dato);
        v[i]=dato;
    }
}

///////////////////////////////////////////////////////

void invertirvec (float v1[], float v2[], int ce)

{
    int i;

    for (i=0;i<ce;i++)
    {
        v2[i]=v1[ce-1-i];
    }
}

////////////////////////////////////////////////////

void mostrarvec (float v[], int ce)
{
    int i;

    for (i=0;i<ce;i++)
    {
        printf ("\n%6.2f", v[i]);
    }
}
