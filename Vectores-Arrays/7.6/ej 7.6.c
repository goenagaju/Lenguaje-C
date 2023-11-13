/**7.1.6 Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como
máximo la empresa tiene 100 empleados. Se desea:

a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un
empleado con DNI 99.

b. Generar un vector con la cantidad de empleados en cada sector mediante la función
CuentaPorSector y mostrarlo en forma de listado.

c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.
*/

#include <stdio.h>

//funciones
int esdatoval2 (int,int,int);
int ingresardatoval2 (int, int);
void cuentaxSec (int [],int);
void cargaEmpleados (int [],int [],int [],int);
void mostrarvec (int [], int);

int main ()

{
    int vDni [100], vCod [100], vSueldo [100]={0}, vCuentaxsec[5]={0};
    int  i=0,dni;

    printf ("\nIngresar DNI - FIN 99");
    dni=ingresardatoval2 (0,50000000);

    while (i<100 && dni!=99)
    {
        vDni[i]=dni;
        cargaEmpleados(vCod,vSueldo,vCuentaxsec,i);
        i++;
        if (i<100)
        {
            printf ("\nIngresar DNI - FIN 99");
            dni=ingresardatoval2 (0,50000000);
        }
    }

        printf ("\nSector || Cantidad de Empleados");
        printf ("\n--------------------------------");
        mostrarvec (vCuentaxsec,5);
        totalapagar (vSueldo,i);


}

//funciones

int esdatoval2 (int x,int lim1,int lim2)
{
    if (x>lim1 && x<=lim2)
        return 1;
    else
        return 0;
}
//////////////////////////////////////////////////
int ingresardatoval2 (int lim1, int lim2)
{
    int dato;

    do{
        printf (":");
        scanf("%d", &dato);

    }while((esdatoval2(dato,lim1,lim2)==0));

    return dato;
}
//////////////////////////////////////////////////
void cuentaxSec (int v[],int cod)
{

    switch (cod)
    {
        case 1:
                v[cod-1]++;
                break;
        case 2:
                v[cod-1]++;
                break;
        case 3:

                v[cod-1]++;
                break;
        case 4:

                v[cod-1]++;
                break;
        case 5:

                v[cod-1]++;
                break;
    }

}


//////////////////////////////////////////////////
void cargaEmpleados (int vcod[],int vsueldo[],int vsector[],int pos)
{
    int cod,sueldo;

        printf ("\nIngresar Codigo de sector");
        cod=ingresardatoval2(0,5);
        vcod[pos]=cod;

        printf ("\nIngresar Sueldo");
        sueldo=ingresardatoval2(0,1000000);
        vsueldo[pos]=sueldo;
        cuentaxSec (vsector,cod);


}
//////////////////////////////////////////////////
int totalapagar (int v[], int ce)
{

        int i, sum=0;

        for(i=0;i<ce;i++)
        {
            sum+=v[i];
        }

        printf ("\n\nMonto a pagar en Sueldos: %d\n\n", sum);


}
///////////////////////////////////////////////////////////////
void mostrarvec (int v[], int ce)

{
    int i;



    for (i=0;i<ce;i++)
    {
        printf("\n %d     || \t %d", i+1, v[i]);
    }

}
