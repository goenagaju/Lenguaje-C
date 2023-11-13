/*5.2.11 Se ingresan números enteros, hasta que se ingrese el número cero. Determinar los 2 valores mayores*/

#include <stdio.h>

int main ()

{
    int num, max,max2,band=0,band2=0,cont=0,aux;

    do {
        printf("\nIngresar un numero entero (Para finalizar ingresar 0):");
        scanf("%d",&num);

    }while(!(num==0 || num!=0));

    while (num!=0)

    {
        if (band==0)
        {
            max=num;
            max2=num;
            band=1;
        }
        else
        {
            if(num>max)
            {
                aux=max; //se hace una "copia" en aux del numero anterior
                max=num;    //max es el nuevo numero mayor
                max2=aux;  //max2 pasa a ser el SEGUNDO numero mayor donde se "pego" el numero q habia guardado en aux

            }
            else
            {
                if(band2==0||num>max2) //uso una segunda bandera para que si o si -
                                      //haya un segundo numero mayor , porque si el primer numero es MUY alto -
                                    //y los demas no, no tomara un segundo valor

                    max2=num; //si num no era mayor a max, se compara para ver si es mayor a el -
                            //segundo numero mayor, si es mayor lo pisa.
                    band2=1;
            }

        }

        cont++;

            do {
        printf("\nIngresar un numero entero (Para finalizar ingresar 0):");
        scanf("%d",&num);

                }while(!(num==0 || num!=0));

    }

    if (cont>0)
        printf("\nLos dos valores mayores son: %d y %d\n\n", max,max2);
    else
        printf("\n >>>>>>>>>  NO HUBO INGRESOS.\n\n");

    return 0;


}
