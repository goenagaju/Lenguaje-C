/**7.1.7 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos.

Mostrar:
a. Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado)
b. La máxima nota obtenida y el DNI de los alumnos que la obtuvieron.*/

#include <stdio.h>

//Prototipo de Funciones

int esDatoVali2 (int,int,int);
int ingresarDatoVali2 (int,int);
int cargaAlumn (int [],int [],int);
void mostrarMaxNota (int [], int[],int);
void mostrarVectores (int [], int[],int);

int main ()

{
    int vDni[60] , vNota[60];
    int cant;

    cant=cargaAlumn(vDni,vNota,60);

    if(cant>0)
    {
        printf("\n--DNI    ||    NOTA--");
        mostrarVectores (vDni,vNota,cant);
        mostrarMaxNota (vDni,vNota,cant);
    }








}


///////////////FUNCIONES/////////////////////////////
int esDatoVali2 (int x,int lim1,int lim2)
{
    if(x>=lim1 && x<=lim2 || x<0)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------
int ingresarDatoVali2 (int lim1, int lim2)
{
    int dato;

    do{
        scanf ("%d", &dato);

        }while((esDatoVali2(dato,lim1,lim2)==0));

    return dato;
}
//---------------------------------------------------------------------------------------------
int cargaAlumn (int vDni [],int vNota[],int ce)
{
    int i=0,nota,dni;

        printf ("\nIngresar dni del alumno - Numero negativo para finalizar:");
        dni=ingresarDatoVali2(4000000,50000000);

    while (i<ce && dni>0)
    {

        vDni[i]=dni;
        printf ("\nIngresar nota del alumno:");
        nota=ingresarDatoVali2(1,10);
        vNota[i]=nota;
        i++;
        printf ("\nIngresar dni:");
        dni=ingresarDatoVali2(4000000,50000000);
    }



    return i;
}
//---------------------------------------------------------------------------------------------
void mostrarMaxNota (int vdni[], int vnota[], int ce)
{
    int i,j,maxNota;

    for(i=0;i<ce;i++)
    {
        if (i==0)
        {
            maxNota=vnota[i];
        }
        else
        {
            if(vnota[i]>maxNota)
                maxNota = vnota [i];

        }
    }

    printf ("\n\nMAYOR NOTA: %d\n" , maxNota);
    printf ("\n**ALUMNOS CON LA MAYOR NOTA**\n");
    printf ("\n  DNI");

    for (j=0;j<ce;j++)
    {
        if(vnota[j]==maxNota)
        {
            printf ("\n-%d", vdni[j]);
        }
    }

}
//---------------------------------------------------------------------------------------------
void mostrarVectores (int v1 [], int v2[], int ce)
{
    int i;

    for (i=0;i<ce;i++)
        printf("\n%d\t%d", v1[i], v2[i]);
}
