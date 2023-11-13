/**1.1.1 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa mediante
la función IngresaCódigos.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/

#include <stdio.h>
int numeroEntero (int );
int esDatoValido (int,int,int,int); //dato lim1 lim2 cond.fin
int ingresarDatoValido (int,int,int); //lim1,lim2, cond.fin
void ingresarCodigos (int [],int); // vproduc , ce
int carga (int[],int[],int); //vproduc , vcantidad , ce
int buscar (int[],int,int); //vproduc , dato buscado , ce a buscar
void mostrarVecs (int[],int[],int);
int valorMaximo (int[],int);
void Maximos (int [],int[],int, int); //vproduc (este muestra), vcant (contra este compara) , valor max, ce
int valorMinimo (int[],int);
void Minimos (int [],int[],int, int);

int main ()
{
    int vProductos[10], vCantidad[10]={0}, cant, maximo,minimo;

    ingresarCodigos(vProductos,10); //cargo sin duplicar
    cant=carga(vProductos,vCantidad,10);

    if(cant>0)
    {
        mostrarVecs(vProductos,vCantidad,10);
        maximo=valorMaximo(vCantidad,10); //busco
        Maximos(vProductos,vCantidad,maximo,10); //muestro

        minimo=valorMinimo(vCantidad,10); //busco
        Minimos(vProductos,vCantidad,minimo,10); //muestro

    }
}

//FUNCIONES
int numeroEntero (int x)
{
    if (x>0)
        return 1;
    else
    {
        printf("\nEl dato ingresado no es valido. Volver a ingresar:");
        return 0;
    }

}
//-----------------------------------------------------------------------
int esDatoValido (int dato,int lim1,int lim2,int fin) //dato lim1 lim2 cond.fin
{
    if (dato>=lim1 && dato<=lim2 || dato==fin)
        return 1;
    else
        return 0;

}
//------------------------------------------------------------------------------------
int ingresarDatoValido (int lim1,int lim2,int fin) //lim1,lim2, cond.fin
{
    int dato;

    do{
        scanf("%d", &dato);

    }while(esDatoValido(dato,lim1,lim2,fin)==0);

    return dato;
}
//------------------------------------------------------------------------------------
void ingresarCodigos (int vec[],int ce) // vproduc , ce
{
    int i,pos,codigo;

    printf("\nINGRESAR CODIGOS DE PRODUCTOS:\n");

    for(i=0;i<ce;i++)
    {
        printf("-");
        do{

            codigo=ingresarDatoValido(1000,9999,1000);
            pos=buscar(vec,codigo,i);
            if(pos!=-1)
                printf("\nDato duplicado.Ingrese otro codigo:");

        }while(pos!=-1); //si es -1 corta, si es diferente a -1
                        //sigue porq quiere decir q es duplicado
            vec[i]=codigo;
    }
}
//------------------------------------------------------------------------------------
int carga (int vp[],int vc[],int ce) //vproduc , vcantidad , ce
{
    int i=0,pos,cod,cant;

    printf("\nIngresar codigo de producto. (0 para FIN):");
    cod=ingresarDatoValido(1000,9999,0);

    while(cod!=0)
    {
        do{
            pos=buscar(vp,cod,10);
            if(pos==-1)
            {
                printf("\nCodigo no registrado, ingresar nuevamente:");
                cod=ingresarDatoValido(1000,9999,0);
            }


        }while(pos==-1);

        printf("\nIngresar la cantidad pedida del producto:");
        do{
            scanf("%d", &cant);
        }while((numeroEntero(cant))==0);

        vc[pos]+=cant;
        i++;

        printf("\nIngresar codigo de producto:");
        cod=ingresarDatoValido(1000,9999,0);
    }

    return i;

}
//------------------------------------------------------------------------------------
int buscar (int vec[],int datoBuscado,int ce) //vproduc , dato buscado , ce a buscar
{
    int i, pos=-1;

    for(i=0;i<ce;i++)
    {
        if(vec[i]==datoBuscado)
            pos=i;
    }

    return pos;
}
//------------------------------------------------------------------------------------
void mostrarVecs (int vp[],int vc[],int ce)
{
    int i;

    printf("\n     PEDIDOS");
    printf("\n-----------------\n");
    printf("\nProducto\tCantidad");

    for(i=0;i<ce;i++)
        printf("\n%8d\t%8d",vp[i],vc[i]);

}
//------------------------------------------------------------------------------------
int valorMaximo (int vec[],int ce)
{
    int i,max;

    for(i=0;i<ce;i++)
    {
        if(i==0)
            max=vec[i];
        else
        {
            if(vec[i]>max)
                max=vec[i];
        }
    }

    return max;
}
//------------------------------------------------------------------------------------
void Maximos (int vp[], int vc[],int max, int ce)//vec , valor max, ce
{
    int i;

    printf("\n\nEl / los productos del cual se solicitaron mayor cantidad de unidades:");

    for(i=0;i<ce;i++)
    {
        if(vc[i]==max)
            printf("\t%d", vp[i]);
    }
}
//------------------------------------------------------------------------------------
int valorMinimo (int vec[],int ce)

{
    int i,min;

    for(i=0;i<ce;i++)
    {
        if(i==0)
             min=vec[i];
        else
        {
            if(min>vec[i])
                min=vec[i];
        }
    }

    return min;
}

//------------------------------------------------------------------------------------
void Minimos (int vp[],int vc[], int min, int ce)
{
    int i;

    printf("\n\nEl / los productos del cual se solicitaron menos cantidad de unidades:");

    for(i=0;i<ce;i++)
    {
        if(vc[i]==min)
            printf("\t%d", vp[i]);
    }


}
//------------------------------------------------------------------------------------

