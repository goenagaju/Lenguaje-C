/**
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:

• Código de cliente (entero de 4 dígitos ).
• Nombre y Apellido (50 caracteres máximo).

Por cada venta se ingresa:

• Número de cliente (entero de 4 dígitos ).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).

El ingreso de datos finaliza con un número de cliente 999.

Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
cliente, informando:

CODIGO DE CLIENTE   NOMBRE Y APELLIDO      TOTAL FACTURADO

        X               XXXXX XXXXXXXX       $ XXXXXXXXX,XX
*/

#include<stdio.h>
#include<string.h>

//estructuras
typedef struct

    {
        int nrocliente;
        char ayn[50];
    }sCliente;

typedef struct
    {
        int nrocliente;
        float importe;
        int nrovendedor;
    }sVentas;



//funciones

int esDatoValido(int,int,int,int);
int ingresarDatoValido (int,int,int);
int cargaClientes (sCliente[]);
int cargaVentas(sVentas,sCliente[],int[],int[],float[],int);
int buscar(sCliente[],int,int);
void mostrar (sCliente[],float[],int);


int main()
{
    sCliente clientes[100];
    sVentas ventas;
    int cant,cantv,cargaC[100]={0}, cargaV[10]={0};
    float vImporte[100]={0};

        printf("\n\t**CARGA CLIENTES**\n");
        cant=cargaClientes(clientes);
        if(cant>0)
        {
            printf("\n\---------------*---------------*---------------*---------------*---------------*---------------\n");
            printf("\n\t                              **CARGA VENTAS**\n");
            cantv=cargaVentas(ventas,clientes,cargaC,cargaV,vImporte,cant);
            printf("\n\n");
            mostrar(clientes,vImporte,cant);
        }

    printf("\n\n");
    getchar();


}

///funciones
int esDatoValido(int dato,int lim1,int lim2,int fin)
{
    if(dato>=lim1 && dato<=lim2 || dato==fin)
        return 1;
    else
    {
        printf("\nDato incorrecto.Volver a ingresar:");
        return 0;
    }
}
//---------------------------------------------------------------------------------------
int ingresarDatoValido (int lim1,int lim2,int fin)
{
    int dato;

    do{
        scanf("%d",&dato);

    }while((esDatoValido(dato,lim1,lim2,fin))==0);

    return dato;
}
//-----------------------------------------------------------------------------
int cargaClientes (sCliente vc[])
{
    int i=0,cliente,pos;

    printf("\nIngresar Nro. de Cliente(1000 al 9999 - para FIN: 999):");
    fflush(stdin);
    cliente=ingresarDatoValido(1000,9999,999);

    while(cliente!=999)
    {
        do{
            pos=buscar(vc,cliente,i);
            if(pos!=-1)
            {
                printf("\nEl numero de cliente ya se encuentra registrado, volver a ingresar:");
                cliente=ingresarDatoValido(1000,9999,1000);
            }

        }while(pos!=-1);

        vc[i].nrocliente=cliente;

        printf("\nIngresar Apellido y Nombre:");
        getchar();
        gets(vc[i].ayn);

        i++;

        printf("\nIngresar Nro. de Cliente(1000 al 9999 - para FIN: 999):");
        fflush(stdin);
        cliente=ingresarDatoValido(1000,9999,999);

    }

       return i;
}
//-----------------------------------------------------------------------------
int cargaVentas(sVentas ventas,sCliente vc[],int cc[],int cv[],float vi[],int ce)
{
    int i=0,cliente,vendedor,pos;
    float importe;

    printf("\nIngresar Nro. de Cliente(1000 al 9999 - para FIN: 999):");
    cliente=ingresarDatoValido(1000,9999,999);

    while(cliente!=999)
    {
        do{
            pos=buscar(vc,cliente,ce);
            if(pos==-1)
            {
                printf("\nEl numero de cliente no se encuentra registrado, volver a ingresar:");
                cliente=ingresarDatoValido(1000,9999,1000);
            }
        }while(pos==-1);

        cc[pos]++; //cantidad d ventas por cliente

        printf("\nIngresar importe:");
        do{
            scanf("%f", &importe);
        }while(importe<0);

        vi[pos]+=importe;  //importe total recaudado por cliente

        printf("\nIngrese Numero de vendedor (del 1 al 10):");
        vendedor=ingresarDatoValido(1,10,1);

        cv[vendedor-1]++; //cantidad de ventas x vendedor

        i++;

        printf("\nIngresar Nro. de Cliente(1000 al 9999 - para FIN: 999):");
        cliente=ingresarDatoValido(1000,9999,999);
    }

    return i;

}
//-----------------------------------------------------------------------------
int buscar(sCliente vc[],int buscado,int ce)
{
    int i,pos=-1;

    for(i=0;i<ce;i++)
    {
            if(vc[i].nrocliente==buscado)
                pos=i;
    }

    return pos;
}

//-----------------------------------------------------------------------------
void mostrar (sCliente vc[],float importe[],int ce)

{
    int i;

    printf("\n\tCODIGO DE CLIENTE\tNOMBRE Y APELLIDO\tTOTAL FACTURADO");
    printf("\n\t------------------\t----------------\t------------------");

    for(i=0;i<ce;i++)
    {
        printf("\n\t    %d         \t%-20s      \t$ %3.f", vc[i].nrocliente,vc[i].ayn,importe[i]);
    }

}
