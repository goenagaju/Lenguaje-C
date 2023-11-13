/**Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la información ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la raíz cuadrada del respectivo elemento de VA.
(para el cálculo de la raíz cuadrada utilizar la función sqrt disponible en la biblioteca math.h). Si el
número es negativo poner un 0 ya que no se puede calcular la raíz
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor máximo del vector VA y en qué posición se halló (el mayor es único).
f. Hallar el valor mínimo del vector VB y en qué posiciones se hallaron (el mínimo se pude repetir).
g. Dado un valor ingresado por teclado, indicar en qué posición se encontró del vector VC.
h. Mostrar el contenido de todos los vectores.

FUNCIONES:
I. Para el ingreso del vector AA, del punto a).
II. Para generar el vector CC, del punto c).
III. Para realizar la búsqueda del punto g).
V. Para mostrar los valores de todos los vectores del punto j).*/

#include <stdio.h>
#include <math.h>

//prototipo de funciones

void cargaVec(float [],int);
void OperRaiz (float [],float [],int);
void sumarVec (float [],float[],float[],int);
void vecInvert (float [],float [],int);
void  buscarMax (float[],int);
void buscarMin (float [],int);
void buscarValEnPos (float [],int);
void mostrarVect (float[],float[],float[],float[],int);

int main ()

{
    float vecA[10]={0}, vecB[10]={0}, vecC[10]={0},vecD[10]={0};
    float min,max;

    cargaVec(vecA,10);
    OperRaiz (vecA,vecB,10);
    sumarVec(vecA,vecB,vecC,10);
    vecInvert(vecC,vecD,10);
    buscarMax (vecA,10);
    buscarMin(vecB,10);
    buscarValEnPos (vecC,10);
    mostrarVect (vecA,vecB,vecC,vecD,10);

}

//FUNCIONES

void cargaVec(float vA[],int ce)
{
    int i;
    float dato;

    printf ("\nIngresar 10 valores para la carga:\n");

    for (i=0;i<ce;i++)
    {
        printf ("%d: ", i+1);
        fflush(stdin);
        scanf("%f", &dato);
        vA[i]=dato;
    }
}
//--------------------------------------------------------------------------------------------------
void OperRaiz (float vA [],float vB[],int ce)
{

    int i;
    float n;

        for (i=0;i<ce;i++)
        {
         if(vA[i]!=0)
         {
             n=vA[i];
             n= sqrt (n); //hago la raiz
             vB[i]= n;
         }
        }
}
//--------------------------------------------------------------------------------------------------
void sumarVec (float vA[],float vB[],float vC[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        vC[i]=vA[i]+vB[i];
    }
}
//--------------------------------------------------------------------------------------------------
void vecInvert (float vC[],float vD[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        vD[i]=vC[ce-1-i];
    }
}
//--------------------------------------------------------------------------------------------------
void  buscarMax (float vA[],int ce)
{
    int i,pos;
    float max;

    for (i=0;i<ce;i++)
    {
        if(i==0)
        {
            max=vA[i];
            pos=i+1;
        }
        else
            if(vA[i]>max)
        {
            max=vA[i];
            pos=i;
        }
    }

     printf ("\nEl valor MAXIMO del vector A es: %6.2f y esta en la posicion %d", max,pos);

}
//--------------------------------------------------------------------------------------------------
void buscarMin (float vB[],int ce)
{
    int i,j;
    float min;

    for(i=0;i<ce;i++)
    {
        if(i==0)
        {
             min=vB[i]; //el primer valor se toma como el minimo
        }
        else
            if (vB[i]<min) //comparo el proxima valor con el min
        {
            min=vB[i]; //si es menor al minimo, hago un cambio
        }
    }

    printf ("\n\nValor MINIMO del vector B: %6.2f", min);
    printf("\n\n*Posiciones con el valor minino*");

    for(j=0;j<ce;j++)
    {
        if(vB[j]==min) //si el elemento que esta en la pos I es igual al minimo, muestro la posicion
            printf("\n*%d",j);
    }



}
//--------------------------------------------------------------------------------------------------
void buscarValEnPos (float vC[],int ce) /**NO ME FUNCIONA EL PRINT DE LA POSICION*/
{
    int i,pos=55;
    float dato;

    printf("\n\nIngresar un nuevo valor:");
    scanf("%f", &dato);

    for(i=0;i<ce;i++)
    {
        if(vC[i]==dato) //si el elemento de vecC en i es igual al nuevo dato ingresado
            pos=i; //guarda la posicion en la variable Pos
    }

    if(pos!=55) //pos=1
        printf ("\nEl dato se encuentra en la posicion: %d", pos);
        else
        printf("\nNo se encontro ningun dato igual al valor ingresado.\n");

}
//--------------------------------------------------------------------------------------------------
void mostrarVect (float vA[],float vB[],float vC[],float vD[],int ce)
{
        int i;
        printf("\nVEC A  \t VEC B \t VEC C \t VEC D");
        for(i=0;i<ce;i++)
        {
            printf("\n%6.2f  %6.2f  %6.2f  %6.2f", vA[i],vB[i],vC[i],vD[i]);
        }
}
//--------------------------------------------------------------------------------------------------
