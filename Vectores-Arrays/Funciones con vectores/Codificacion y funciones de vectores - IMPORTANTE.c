#include <stdio.h>

//funciones
void cargaVec (int [],int);
void copiaVec (int [],int[],int);
void sumarVec (int [],int [],int[],int);
void invertirVec (int [],int [],int);
void mostrarVecs (int [],int [],int [],int[],int);
void mostrarPosElemParVec (int [],int);
void mostrarPosImpVec (int [],int);
int sumaElemVec (int [],int);
int promVec (int [],int);
int contarIguales (int [],int,int);

int main ()

{

        int vecA [5], vecB [5], vecC [5], vecD[5],dato,suma,prom,cont;

        cargaVec (vecA,5);
        copiaVec (vecA,vecB,5);
        sumarVec (vecA,vecB,vecC,5);
        invertirVec (vecA,vecD,5);
        mostrarVecs (vecA,vecB, vecC , vecD, 5);
        mostrarPosElemParVec (vecA,5);
        mostrarPosImpVec(vecA,5);
        suma=sumaElemVec (vecA,5);
        prom=promVec(vecA,5);

        printf ("\n\nIngresar un valor entero :");
        scanf ("%d" , &dato);

        cont=contarIguales (vecA,5,dato);

        if (suma>0)
            printf ("\nLa suma de los valores es: %d \n", suma);

        if (prom>0)
            printf ("\nEl promedio es: %d \n", prom);

        if(cont>0)
            printf ("\nCantidad de valores iguales al dato ingresado : %d \n", cont);

}
////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////////////////
void cargaVec (int v[],int ce)
{
    int i,dat;

    for(i=0;i<ce;i++) //tambien podria ser i=ce-1
    {
        printf ("\ningresar valor:");
        scanf ("%d", &dat);
        v[i]=dat;
    }

}

//////////////////////////////////////////
void copiaVec (int v1[],int v2[],int ce)
{
    int i;

    for (i=0;i<ce;i++)
    {
        v2[i]=v1[i];
    }


}
//////////////////////////////////////////
void sumarVec (int v1[],int v2[],int v3[],int ce)
{
    int i;

    for (i=0;i<ce;i++)
    {
        v3[i]=v1[i]+v2[i];
    }
}
//////////////////////////////////////////
void invertirVec (int v1 [],int v2[],int ce)
{
    int i;

    for (i=0;i<ce;i++)
    {
        v2[i]=v1[ce-1-i];
    }
}
//////////////////////////////////////////
void mostrarVecs (int v1[],int v2[],int v3[],int v4[],int ce)
{
    int i=0;

    printf ("\nOrden \t V1 \t V2 \t V3 \t V4 \t \n");


   for (i=0;i<ce;i++)
    {
        printf("\n %d \t %d \t %d \t %d \t %d", i+1,v1[i],v2[i],v3[i],v4[i]); // i+1 es el orden , v[i] siempre muestra el contenido de la posicion correspondiente
    }

}
//////////////////////////////////////////
void mostrarPosElemParVec (int v[],int ce)
{
    int i;

    for (i=0;i<ce;i++)
    {
        if (v[i]%2==0) //si el contenido dividido 2 da resto cero (Es decir es PAR), muestro
        printf("\n\nPosiciones con contenido par: %d \n", i); //muestra posicion y contenido
    }


}
//////////////////////////////////////////
void mostrarPosImpVec (int v[],int ce)
{
        int i;

    for (i=0;i<ce;i++)
    {
        if (i%2!=0) //si la POSICION dividido 2 da resto DIFERENTE de cero (Es decir es IMPAR), muestro
        printf("\n\nElemento con posicion impar: %d \n", v[i]); //muuestra contenido
    }
}
//////////////////////////////////////////
int sumaElemVec (int v[],int ce)
{
    int sum=0,i;

    for (i=0;i<ce;i++)
    {
      sum+=v[i];
    }

    return sum;
}
//////////////////////////////////////////
int promVec (int v[],int ce)
{
    return sumaElemVec (v,ce)/ce;
}
//////////////////////////////////////////
int contarIguales (int v[],int ce ,int n)
{
    int cont=0,i;

    for (i=0;i<ce;i++)
    {
        if (n==v[i])
            cont++;
    }

    return cont;
}
