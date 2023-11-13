/**2.1 Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:

• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).

Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.

Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.

El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:

a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:

DESCRIPCION      CANTIDAD UNIDADES              IMPORTE TOTAL
                    VENDIDAS                        VENDIDO

XXXXXXX              XXXX                          $XXXXX,XX


*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

///declaracion de estructuras

typedef struct
            {
                char codigo[6];
                float precio;
                char descripcion[31];
                int cantUnidades;
                float totalVendido;

            }productos;

///funciones

int cargaProductos (productos []);
int cargaVentas (productos[],int);
int buscar (productos[],char [],int);
void mostrar (productos[],int);

int main()
{
    productos prod[50];
    int canttotal, cant;


    canttotal=cargaProductos(prod);

    if(canttotal>0)
    {
        cant=cargaVentas(prod,canttotal);
        if(cant>0)
            mostrar(prod,canttotal);
    }
}

///funciones

int cargaProductos (productos vp[])
{
   int i=0,pos;

    printf("\n\tCARGA DE PRODUCTOS");

    printf("\nIngresar descripcion del producto (30 caracteres)-(para finalizar 'FIN'):");
    getchar();
    gets(vp[i].descripcion);

    while(strcmpi(vp[i].descripcion,"FIN")!=0)
    {
        printf("\nIngresar codigo del producto (5 caracteres):");
        do{
            getchar();
            gets(vp[i].codigo);

            pos=buscar(vp,vp[i].codigo,i);

            if(pos!=-1)
            printf("\nEl codigo ya se encuentra cargado. Ingresar nuevamente:");

        }while(pos!=-1);


        printf("\nIngresar precio del producto:");
        do{
            fflush(stdin);
            scanf("%f", &vp[i].precio);
        }while(vp[i].precio<0);

        printf("\nIngresar cantidad de unidades vendidas (mes anterior):");
        do{
                fflush(stdin);
            scanf("%f", &vp[i].cantUnidades);
        }while(vp[i].cantUnidades<0);

        i++;

        printf("\nIngresar descripcion del producto (30 caracteres)-(para finalizar 'FIN'):");
        getchar();
        gets(vp[i].descripcion);

    }

    return i;

}
//-------------------------------------------------------------------------------------------------
int cargaVentas (productos vp[],int ce)
{
    int i=0,pos;

    for(i=0;i<ce;i++)
        vp[i].totalVendido=0;

    printf("\n\tCARGA DE PRODUCTOS ACTUALIZADA");

    printf("\nIngresar cantidad de productos pedidos(para finalizar ingresar 0):");
    do{
            fflush(stdin);
        scanf("%d", &vp[i].cantUnidades);

        if(vp[i].cantUnidades<0)
            printf("\nDato invalido, volver a ingresar:");

    }while(vp[i].cantUnidades<0);

    while(vp[i].cantUnidades!=0)
    {
        printf("\nIngresar codigo del producto (5 caracteres):");
        do{
            getchar();
            gets(vp[i].codigo);

            pos=buscar(vp,vp[i].codigo,ce);

            if(pos==-1)
                printf("\nEl codigo de producto ingresado no existe, volver a ingresar:");
        }while(pos==-1);

        vp[i].totalVendido+=(vp[i].cantUnidades*vp[i].precio);

        i++;

        printf("\nIngresar cantidad de productos pedidos(para finalizar ingresar 0):");
        do{
                fflush(stdin);
            scanf("%d", &vp[i].cantUnidades);

            if(vp[i].cantUnidades<0)
                printf("\nDato invalido, volver a ingresar:");

        }while(vp[i].cantUnidades<0);
    }

    return i;
}
//-------------------------------------------------------------------------------------------------
int buscar (productos vp[],char buscado[],int ce)
{
    int i, pos=-1;

    for(i=0;i<ce;i++)
    {
        if(strcmpi(vp[i].codigo,buscado)==0)
            pos=i;
    }

    return pos;
}
//-------------------------------------------------------------------------------------------------
void mostrar (productos vp[],int ce)
{
    int i=0;
    printf("\n\tDESCRIPCION\tCANTIDAD UNIDADES VENDIDAS\tIMPORTE TOTAL VENDIDO\n");

    for(i=0;i<ce;i++)
        printf("\n\t%s      \t      %d                  \t      $ %-8f",vp[i].descripcion,vp[i].cantUnidades,vp[i].totalVendido);
}
