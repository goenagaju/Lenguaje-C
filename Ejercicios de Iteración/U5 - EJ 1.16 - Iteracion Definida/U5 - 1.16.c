/*5.1.16 Se ingresan DNI y la nota promedio de 10 alumnos.
Determinar el DNI del alumno de mayor nota
promedio (considerar único).*/

#include <stdio.h>

int main ()

{
    int dni, prom, may=0,i,mayor=0;

    for (i=1;i<=5;i++)
    {
        printf ("\nIngresar DNI del alumno:"); //i=1=123 , i=2=345
        scanf("%d",&dni);

        printf("\nIngresar nota promedio del alumno:\n"); //i=1=6 , i=2=9
        scanf("%d",&prom);

        if (prom>0 && prom<=10)
        {
            if (prom>may) // i=1= 6>0 ? , si
                        //i=2= 9>6 ?
            {
            may=prom; //entonces i=1=may=prom (6) ; i=2=may=prom (9)
            mayor=dni;//i=1=may=123              ;i=2=may = 345
            }
                                                                        //else
                                                                        //printf ("\n%d no es mayor que %d\n", prom, may);
        }
        else
            printf ("\nEl promedio no es valido.\n");
    }

    printf ("\nEl alumno de DNI:%d tiene el mayor promedio.", mayor);

    return 0;
}


