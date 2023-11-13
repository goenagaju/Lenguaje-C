/*7.1.10 Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados). Se pide
determinar el/los empleados/as de máximo sueldo. El fin de carga de sueldos está dado por un legajo igual a
cero.

a. Los números de legajo son números correlativos de 1 a 100.*/

#include <stdio.h>

//funciones

int esDatoVali2 (int,int,int);
int ingresarDatoVal2 (int,int);
int cargarEmpleados (int[],int[],int);
void buscarMax (int[],int);
void mostrarVec (int[],int[],int);

int main ()

{
    int vLegajos[5],cant;
    int vSueldos [5];


        cant=cargarEmpleados (vLegajos,vSueldos,5);

    if(cant>0)
    {
        buscarMax(vSueldos,cant);
        mostrarVec (vLegajos,vSueldos,cant);
    }



}

//FUNCIONES

int esDatoVali2 (int x,int lim1,int lim2)
{
    if(x>=lim1 && x<=lim2)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------
int ingresarDatoVal2 (int lim1,int lim2)
{
    int dato;

    do{
        scanf("%d", &dato);

    }while((esDatoVali2(dato,lim1,lim2))==0);

    return dato;
}
//---------------------------------------------------------------------------------------------------------
int cargarEmpleados (int vl[],int vs[],int ce)

{
    int i=0,legajo,sueldo;

    printf ("\nIngresar numero de legajo del empleado - 0 para terminar. :");
    legajo=ingresarDatoVal2(0,100);

    while (i<ce && legajo!=0)
    {
        vl[i]=legajo;

        printf ("\nIngresar Sueldo del empleado - Mayor a 0:");
        sueldo=ingresarDatoVal2(1,1000000);
        vs[i]=sueldo;

        i++;
        printf ("\nIngresar numero de legajo del empleado - 0 para terminar. :");
        legajo=ingresarDatoVal2 (0,100);
    }

    return i;
}
//---------------------------------------------------------------------------------------------------------
void buscarMax (int vs[],int ce)

{
    int i;
    int maxSueldo;

    for (i=0;i<ce;i++)
    {
        if(i==0)
            maxSueldo=vs[i];
        else
            if(vs[i]>maxSueldo)
                maxSueldo=vs[i];
    }

    printf ("\n***** El sueldo maximo es: %d *****", maxSueldo);
}
//---------------------------------------------------------------------------------------------------------
void mostrarVec (int vl[],int vs[],int ce)
{
    int i;

    printf("\nLEGAJO \t SUELDO");

    for(i=0;i<ce;i++)
    {
        printf("\n%d \t %d",vl[i],vs[i]);
    }

}
//---------------------------------------------------------------------------------------------------------
