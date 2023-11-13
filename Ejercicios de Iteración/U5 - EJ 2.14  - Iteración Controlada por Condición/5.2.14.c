/*Se ingresan datos de los empleados de una empresa. Por cada empleado se ingresa:
 Legajo (entero entre 1000 y 5000)
 Sueldo básico (float mayor a 1000)
 Antigüedad en años (mayor o igual a 0)
 Sexo (‘M' o 'F')
 Categoría (entero entre 1 a 5)

Por cada empleado ingresado se debe calcular el sueldo final a abonar sabiendo que:

 Las Categorías 2 y 3 tienen $500 de bonificación.
 La Categoría 4 tiene 10% de bonificación.
 La Categoría 5 tiene 30% de bonificación.
 Si la antigüedad es mayor a 10 años recibe una bonificación del 10% adicional.

Todos los datos ingresados deben ser validados. El ingreso finaliza con un legajo igual a cero.

Informar:
 El sueldo a abonar a cada empleado.
 Cantidad de empleados de más de 10 años de antigüedad.
 El mayor sueldo y el legajo del empleado que cobra dicho sueldo.
 Cantidad de hombres y de mujeres.*/

#include <stdio.h>
#include <ctype.h>

int main ()

{

    int legajo,categ,antig,band=0, cantm=0,cantf=0, cantant=0, empleados=0, mayor, aux2;
    float sueldo, max, aux;
    char sex;

    do{
    printf ("\nIngresar numero de legajo del empleado. 0 para finalizar :");
    scanf("%d",&legajo);

        }while(!(legajo==0 || (legajo>1000 && legajo<5000)));


    while (legajo!=0)

    {
        empleados++;
        do{
        printf("\ningresar sueldo basico:");
        scanf("%f",&sueldo);
            }while(sueldo<1000);

        do{
        printf("\ningresar antiguedad de anios:");
        scanf("%d",&antig);
            }while(antig<0);


        do{
        printf("\ningresar sexo:");
        fflush(stdin);
        scanf("%c",&sex);
        sex=toupper(sex);
            }while(!(sex=='M' || sex=='F'));

        if (sex=='M')
            cantm++;
        else
            cantf++;

        do{
        printf("\ningresar categoria:");
        scanf("%d",&categ);
            }while(!(categ>1 && categ<=5));

            switch (categ)
            {
                case 2:
                case 3:
                    sueldo+=500;
                    break;
                case 4:
                    sueldo+=(sueldo*0.10);
                    break;
                case 5:
                    sueldo+=(sueldo*0.30);
                    break;
            }

       /* if (categ==2 || categ==3)
            sueldo+=500;
        else
        {
            if (categ==4)
                sueldo+=(sueldo*0.10);
            else
            {
                if(categ==5)
                    sueldo+=(sueldo*0.30);
            }
        }*/

        if (antig>10)
        {
            sueldo+=(sueldo*0.10);
            cantant++;
        }

        printf ("\nEl sueldo final del empleado con legajo %d , es : %.2f\n", legajo, sueldo);

        if(band==0)
        {
            aux=sueldo;
            max=aux;
            aux2=legajo;
            mayor=aux2;
            band=1;
        }
        else
        {
            if(sueldo>max)
            {
                aux=sueldo;
                max=aux;
                aux2=legajo;
                mayor=aux2;
            }
        }

        do{

        printf ("\n\nIngresar numero de legajo del empleado. 0 para finalizar :");
        fflush(stdin);
        scanf("%d",&legajo);

            }while(legajo!=0 && !(legajo>1000 && legajo<5000));
       }






       if(cantant>0)
       {
          printf("\n\nCantidad de empleados de mas de 10 anios de antiguedad: %d", cantant);
       }

       if(cantf>0)
            printf("\n\nCantidad de mujeres:%d", cantf);

        if(cantm>0)
            printf("\nCantidad de hombres: %d", cantm);

       if (empleados>0)
       printf ("\n\n Numero de legajo del empleado con mayor sueldo: %d \n Sueldo: %.2f\n\n", mayor,max);

       return 0;













}
