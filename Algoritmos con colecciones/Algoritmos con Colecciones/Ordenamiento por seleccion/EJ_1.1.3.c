/**1.1.3
Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos).
Luego se ingresan las ventas realizadas durante el día.

Por cada venta se ingresa:

-código de vendedor
-código de artículo
-cantidad.

-Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005.
-Se puede recibir más de una venta de un mismo vendedor y artículo.
-El ingreso de datos finaliza con código de vendedor igual a 0.

Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.

                                       CANT UNIDADES   CÓDIGO
                                            XXX         XXX
                                            XXX         XXX

b. Indicar el/los vendedores que realizaron mayor cantidad de ventas (no de unidades).*/

#include <stdio.h>

int numeroEntero (int); //mayor a 0
int esDatoValido (int,int,int,int); //dato lim1 lim2 fin
int ingresarDatoValido (int,int,int);
void ingresoCodigos (int[],int); //vp ce
int carga (int[],int[],int[]); // vp vv vc
int valorMax (int[],int);
void mostrarMaximos(int[],int,int);
int buscar (int[],int,int); //
void ordenar (int[],int[],int); //cant unidades x codigo , vectores paralelos
void mostrarVecs (int[],int[],int); //vc vp ce


int main ()
{

    int cant, vProductos[15], vVendedor[5]={0}, vCantidad[15]={0},max;


        printf("\n\t**CARGA CODIGO DE PRODUCTOS**");
        ingresoCodigos(vProductos,15);

        printf ("\n**VENTAS**");
        cant=carga(vProductos,vVendedor,vCantidad);

        if(cant>0)
        {
            ordenar(vCantidad,vProductos,15);
            mostrarVecs(vCantidad,vProductos,15);
            max=valorMax (vVendedor,5);
            printf("\nLa mayor cantidad de ventas fue:%d", max);
            mostrarMaximos(vVendedor,max,5);

        }
}


//FUNCIONES

int numeroEntero (int dato)
{
    if (dato>0)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------------------
int esDatoValido (int dato,int lim1,int lim2,int fin)
{
    if(dato>=lim1 && dato<=lim2 || dato==fin)
        return 1;
    else
        return 0;

}
//---------------------------------------------------------------------------------------------------------------------
int ingresarDatoValido (int lim1,int lim2,int fin)
{
    int dato;

    do{
        scanf("%d" ,&dato);

    }while((esDatoValido(dato,lim1,lim2,fin))==0);

    return dato;
}
//---------------------------------------------------------------------------------------------------------------------
void ingresoCodigos (int vp[],int ce) //carga sin duplicados
{
    int i,pos,codigo;

    printf("\nIngresar los codigos de los productos\n");

    for(i=0;i<ce;i++)
    {
        printf("-");

        do{
            codigo=ingresarDatoValido(100,999,100);
            pos=buscar(vp,codigo,i);
            if(pos!=-1)
                printf("\nCodigo de articulo REPETIDO. Ingresar nuevamente:");

        }while(pos!=-1); //si es -1 corta, si es diferente a -1
                        //sigue porq quiere decir q es duplicado

        vp[i]=codigo;
    }

}
//---------------------------------------------------------------------------------------------------------------------
int carga (int vp[],int vv[],int vc[])
{
    int cant,cvendedor,pos,i=0,articulo;

    printf("\nIngresar codigo del vendedor:");
    cvendedor=ingresarDatoValido(1001,1005,0);

    while (cvendedor!=0)
    {
        vv[cvendedor-1001]++;

        printf ("\nIngresar codigo del Articulo:");

        do{
            articulo=ingresarDatoValido(100,999,100);
            pos=buscar(vp,articulo,15);

            if(pos==-1)
                printf("\nCodigo de articulo no valido, ingresar nuevamente:");

        }while(pos==-1);


        do{
            printf("\nIngresar cantidad de unidades pedidas:");
            scanf("%d" ,&cant);
        }while(numeroEntero(cant)==0);

        vc[pos]+=cant;

        printf("\nIngresar codigo del vendedor:");
        cvendedor=ingresarDatoValido(1001,1005,0);
        i=1;
    }

    return i;

}
//---------------------------------------------------------------------------------------------------------------------
int buscar (int v[],int datoBuscado,int ce)
{
    int i, pos=-1;

    for(i=0;i<ce;i++)
    {
        if(v[i]==datoBuscado)
            pos=i;
    }
        return pos;

}
//---------------------------------------------------------------------------------------------------------------------
void ordenar (int vc[],int vp[],int ce)

{
    int j,aux,cota=ce-1,aux2;
    int desordenado=1;

    while (desordenado!=0)
    {
        desordenado=0; //quiere decir q le asigno al vector que esta "ordenado" , si vuelve a estar en 1 es pq estaba desordenado

        for(j=0;j<cota;j++)
        {
            if(vc[j] < vc[j+1])
            {
                aux=vc[j];
                vc[j]=vc[j+1];
                vc[j+1]=aux;

                aux2=vp[j];
                vp[j]=vp[j+1];
                vp[j+1]=aux2;

                desordenado=j;
            }
        }

        cota=desordenado;
    }



}
//--------------------------------------------------------------------------------------------------------------------
int valorMax (int v[],int ce)
{
    int i,max;

    for(i=0;i<ce;i++)
    {
        if(i==0)
            max=v[i];
        else
            if(v[i]>max)
                max=v[i];
    }

    return max;
}
//---------------------------------------------------------------------------------------------------------------------
void mostrarMaximos(int v[],int max,int ce)
{
    int i;

    printf("\nVendedores con la mayor cantidad de ventas hechas:");
    for(i=0;i<ce;i++)
    {
        if(v[i]==max)
            printf("\n-%d", i+1001);
    }
}
//---------------------------------------------------------------------------------------------------------------------
void mostrarVecs (int vc[],int vp[],int ce)
{
    int i;
    printf("\nCANT UNIDADES\tCODIGO");
    printf("\n------------------------");

    for(i=0;i<ce;i++)
        printf("\n%8d\t%8d",vc[i],vp[i]);

}
//---------------------------------------------------------------------------------------------------------------------

