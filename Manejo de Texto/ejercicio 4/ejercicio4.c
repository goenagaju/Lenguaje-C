/**Se ingresan código y precio unitario de los productos que vende un negocio.

No se sabe la cantidad exacta de productos, pero sí se sabe que son menos de 50.

El código es alfanumérico de 3 caracteres y la carga de los datos de productos termina con un código igual al “FIN”.

Luego se registran las ventas del día y por cada venta se ingresa el código de producto y cantidad de unidades vendidas terminando con
una cantidad igual a 0. Se solicita:

c. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.

d. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto*/
#include <stdio.h>
#include <string.h>

int numeroEntero (int); //mayor a 0
int esDatoValido (int,int); //dato lim1 
int ingresarDatoValido (int); //lim1 
int buscarTexto (char[][4],char [], int); //busqueda de texto
int cargaInicial (char[][4],int[],int); //codigo y precio unitario, ce
int cargaVentas (int [],char[][4],int[],int); //cantidad , codigo de producto , ce
void esMenor (int[],char[][4],int); //cantidad , codigo de producto , ce

int main()

{
    char codigo[50][4];
    int cantidad[50],cant,cargas;
    int precio[50];

        printf("\nIngresar codigo y precio unitario de los productos (para finalizar ingresar 'FIN')\n");
        cant=cargaInicial(codigo,precio,4);

        if(cant>0)
        {
            printf("\ningresa el codigo de producto y cantidad de unidades vendidas (para finalizar ingresar CANTIDAD igual a 0)\n");
            cargas=cargaVentas(cantidad,codigo,precio,cant);

            if(cargas>0)
            {
                printf("\nProducto del cual se vendio menor cantidad de unidades:");
                esMenor(cantidad,codigo,cant);
            }
        }
}

///funciones

int numeroEntero (int dato)
{
    if (dato>=0)
        return 1;
    else
        return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int esDatoValido (int dato,int lim1)
{
    if(dato>=lim1)
        return 1;
    else
    {
        printf("\nDato incorrecto.Volver a ingresar:");
        return 0;
    }

}
//----------------------------------------------------------------------------------------------------------------------------------------
int ingresarDatoValido (int lim1)
{
    int dato;

    do{
        scanf("%d",&dato);

    }while((esDatoValido(dato,lim1))==0);

    return dato;
}
//---------------------------------------------------------------------------------------------
int buscarTexto (char tex[][4],char buscado[], int ce) //busqueda de texto
{
    int i=0, pos=-1;

    while(pos==-1 && i<ce)
    {
        if(strcmpi(tex[i],buscado)==0)
            pos=i;
        else
            i++;
    }

    return pos;
}
//---------------------------------------------------------------------------------------------
int cargaInicial (char codigo[][4],int vprecio[],int ce) //codigo y precio unitario
{
    int i=0,pos,precio;
    char cod[4];

    printf("\nIngresar codigo alfanumerico de 3 caracteres:");
    fflush(stdin);
    gets(cod);

    while(strcmpi(cod,"FIN")!=0)
    {
        do{
                pos=buscarTexto(codigo,cod,i);

                if(pos!=-1)
                {
                    printf("\nCodigo duplicado, volver a ingresar:");
                    fflush(stdin);
                    gets(cod);
                }
            }while(pos!=-1);

        strcpy(codigo[i],cod); //copio la variable en esa posicion

        printf("\nIngresar precio unitario del producto:");
        do{
        	fflush(stdin);
            scanf("%d",&precio);
        }while((numeroEntero(precio))==0);

        vprecio[i]=precio;

        i++;

        printf("\nIngresar codigo alfanumerico de 3 caracteres:");
        fflush(stdin);
        gets(cod);
    }

    return i;
}
//---------------------------------------------------------------------------------------------
int cargaVentas (int vc[],char vt[][4],int vp[],int ce) //cantidad , codigo de producto , ce
{
    int i=0,pos,sumtotal=0,cant;
    char cod[4];

    printf("\nIngresar cantidad de productos:");
    cant=ingresarDatoValido(0);
    
    while(cant!=0)
    {
        vc[i]=cant;

        printf("\nIngresar codigo alfanumerico de 3 caracteres:");
        do{
        	fflush(stdin);
            gets(cod);
            pos=buscarTexto(vt,cod,ce);
            if(pos==-1)
                printf("\nEl codigo no es valido,volver a ingresar:");
        }while(pos==-1);

        sumtotal+=(cant*(vp[pos]));

        i++;

        printf("\nIngresar cantidad de productos:");
        cant=ingresarDatoValido(0);
    }
    
    printf("\nRecaudacion total del dia:%d", sumtotal);

    return i;
}

//---------------------------------------------------------------------------------------------
void esMenor (int vc[],char vp[][4],int ce) //cantidad , codigo de producto , ce
{
    int i,j,menor;

    for(i=0;i<ce;i++) //busco menor
    {
        if(i==0)
            menor=vc[i];
        else
        {
            if(menor>vc[i])
                menor=vc[i];
        }
    }

    for(j=0;j<ce;j++)
    {
        if(vc[j]==menor) //muestro codigos con la menor cantidad de ventas
            printf("\n%s", vp[j]);
    }
}
