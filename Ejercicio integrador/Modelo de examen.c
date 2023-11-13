/*Un centro de atención telefónica de soporte técnico desea realizar un informe de los tiempos de atención de sus empleados.
Por cada empleado se ingresa el número de identificación (legajo), el tiempo de atención en minutos (mayor a cero – VALIDAR EL INGRESO DE ESTE DATO)
y la categoría del empleado (S = Senior, J = Junior y T = Trainee).
El programa iniciará preguntando el ingreso por teclado de la categoría del empleado, pudiendo finalizar la ejecución mediante la letra F en dicho ingreso de dato.
Se desea conocer:

A) El promedio de tiempo de atención por categoría de empleado.

B) El número de identificación del empleado con el tiempo de atención más alto y el del más bajo. Aclaración: todos los empleados tienen tiempos de atención distintos.*/

#include <stdio.h>
#include <ctype.h>
int main ()
{
    int  legajo,tiempo,cants=0,sums=0,cantj=0,sumj=0,cantt=0,sumt=0,band=0,band2=0,max,mayor,min,menor;
    char cat;


    do {
            printf("\nIngresar categoria:");
            fflush (stdin);
            scanf("%c",&cat);
            cat=tolower(cat);

        }while(!(cat=='f'||cat=='s'|| cat=='j'||cat=='t'));

    while (cat!='f')
    {
        do{
            printf("\nIngresar num legajo:");
            fflush (stdin);
            scanf("%d",&legajo);
            }while(legajo<0);

        do{
            printf("\nIngresar tiempo de atencion al cliente:");
            fflush (stdin);
            scanf("%d",&tiempo);
            }while(tiempo<0);

            switch (cat)
            {
            case 's':
                    cants++;
                    sums+=tiempo;
                    break;
            case 'j':
                    cantj++;
                    sumj+=tiempo;
                    break;
            case 't':
                    cantt++;
                    sumt+=tiempo;
            }

                if(band==0 || tiempo>max)
                {

                    max=tiempo;
                    mayor=legajo;
                    band=1;
                }

                if(band2==0 || tiempo<min)
                    {
                        min=tiempo;
                        menor=legajo;
                        band2=1;
                    }
            do {
                printf("\n\n\nhIngresar categoria:");
                fflush (stdin);
                scanf("%c",&cat);
                cat=tolower(cat);

                }while(!(cat=='f'||cat=='s'|| cat=='j'||cat=='t'));


        }

        if(cants>0)
            printf("\n\nEl promedio del tiempo de atencion de los empleados Categoria S es: %d", sums/cants);
        if(cantj>0)
            printf("\n\nEl promedio del tiempo de atencion de los empleados Categoria J es: %d", sumj/cantj);
        if (cantt>0)
            printf("\n\nEl promedio del tiempo de atencion de los empleados Categoria T es: %d", sumt/cantt);

            if(band==1)
            {
                printf("\n\nEl empleado con legajo numero %d tiene el mayor tiempo de atencion: %d", mayor,max);
                printf("\n\nEl empleado con legajo numero %d tiene el menor tiempo de atencion: %d \n\n", menor, min);
            }













}


