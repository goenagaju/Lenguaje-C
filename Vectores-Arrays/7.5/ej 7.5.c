/**7.1.5 Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del día. Por
cada pedido se recibe:

 Código de producto (de 1 a 10)
 Cantidad de unidades solicitadas

-Se puede recibir más de un pedido por producto.
-La carga finaliza cuando se ingresa un producto con código igual a cero.
-Al finalizar se debe emitir un listado con código y cantidad de unidades solicitadas de cada producto.*/

#include <stdio.h>
int esdatoval2 (int,int,int);
int ingresarDatoVal2 (int,int);
int cargapedidos (int [],int[],int,int,int);
void mostrarpedidos (int [],int [],int);

int main ()

{

    int vcod[5]={0} , vcant[5]={0}, i=0, cod;

    printf ("\nIngresar codigo del producto - 0 para finalizar:");
    cod=ingresarDatoVal2 (0,10); //ingreso codigo

    while (cod!=0)
    {
        cod=cargapedidos (vcod,vcant, cod,i,5);
        i++;

        if(i<5)
        {
        printf ("\nIngresar codigo del producto - 0 para finalizar:");
        cod=ingresarDatoVal2 (0,10); //ingreso codigo
        }

    }

    mostrarpedidos(vcod,vcant,5);
}


///funciones

int esdatoval2 (int x, int lim1, int lim2)

{
    if (x>=lim1 && x<=lim2)
        return 1;
    else
        return 0;
}
//////////////////////////////////////////////////////////////////////////
int ingresarDatoVal2 (int lim1, int lim2)

{
   int x;

   do{
        scanf ("%d", &x);

   }while((esdatoval2(x,lim1,lim2)==0));

   return x;

}
/////////////////////////////////////////////////////////////////////////

int cargapedidos (int vcod[], int vcant[],int cod, int i, int ce)

{

    int cant=0,aux,aux2;

    if (i<ce)
        {
            if (i==0 && cod!=0)
            {
            vcod[i]=cod; //guardo el codigo en el vector vcod en la posicion i
            aux=cod; // guardo el codigo en una variable auxiliar
            aux2=i;// guardo la posicion en una variable auxiliar
            printf("\nIngresar cantidad de unidades del producto: ");
            cant=ingresarDatoVal2(1,1000);
            vcant[i]+=cant;
            }
            else

                if(cod==aux && cod!=0) //si el codigo que se ingreso es igual a la variable aux , entonces
                {
                    vcod[i]=cod;
                    printf("\nIngresar cantidad de unidades del producto: ");
                    cant=ingresarDatoVal2(1,1000); //ingreso cantidad de unidades del producto ingresado
                    vcant[i]+=cant; //guardo en la posicion guardada en aux2

                }

            else
            {
                    if(cod!=0)
                       {
                        printf("\nIngresar cantidad de unidades del producto: ");
                        cant=ingresarDatoVal2(1,1000);
                        vcant[i]+=cant;
                        aux=cod;
                        aux2=i;
                       }
                        else
                        return 0;

            }

            return cod;
        }
    else
        return 0;

}

//////////////////////////////////////////////////////////////////////

void mostrarpedidos (int vcod[],int vcant[], int ce)

{
    int i;

    printf("\nCODIGO \t CANTIDAD");

    for(i=0;i<ce;i++)
    {
        printf("\n%d \t %d", vcod[i],vcant[i]);
    }

}

