/** Se dispone de un archivo ventas.dat con el siguiente formato:
• Código de producto (alfanumérico 10 caracteres)
• Código de vendedor (entero 1 a 5)
• Cantidad (entero)

El archivo puede contener más de una venta para el mismo producto/vendedor. Luego se dispone de un
segundo archivo llamado productos.dat que contiene:

• Código de producto (alfanumérico 10 caracteres)
• Precio de venta (float)
Como máximo hay 15 productos.

a. Se desea mostrar la cantidad de ventas realizada por cada vendedor de cada producto (utilizar una
matriz).

Producto vendedor 1 vendedor 2 vendedor 3 vendedor 4 vendedor 5
Prod1
Prod2

b. Registrar nuevas ventas ingresando por teclado:
• Código de producto
• Código de vendedor
• Cantidad

(el ingreso por teclado finaliza con vendedor igual a 99)

c. Mostrar nuevamente el listado del punto a actualizado con las nuevas ventas

d. Mostrar un listado ordenado de mayor a menor por importe de ventas mostrando código de
vendedor e importe total vendido.

e. Mostrar el / los productos que vendieron menor cantidad de unidades

f. Actualizar el archivo ventas.dat

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

///defino estructuras

typedef struct
{
    char cod_prod [11];
    int cod_vend;
    int cantidad;

} sVentas;
/////////////////////////////////////////////////////////
typedef struct
{
    char codigo_prod[11];
    float precio;
}sProductos;

//-----------------------------------------------------------------

///defino funciones

int MayorACero (int);
int esDatoValido(int,int,int,int);
int ingresarDatoValido (int,int,int);
int leerArchivos (int[][5],sVentas[]);
void muestroMat (int [][5], sVentas[], int , int);
void cargoMatFilaColumna (int [][5],int[],float [],sProductos[],int,int);
int nuevasVentas (int[][5],sVentas[],int);
//void Ordenar_Mostrar(float[],sVentas[]); // vec de importes total con vector de importes total
//void mostrar(int[],sProductos[]);//cant y cod.productos
//void ActualizarArcVentas();

int main()
{

    sProductos vprod [15];
    sVentas ventas[15];
    //sVentas ventas;
    int cantVentas[15]={0}, mat[15][5]={{0}}, cant,newcant;
    float ImporteTT[5]={0};

        cant=leerArchivos (mat,ventas);
        if(cant>0)
        {
            muestroMat(mat,ventas,cant,5);
            cargoMatFilaColumna (mat,cantVentas,ImporteTT,vprod,cant,5);

            newcant=nuevasVentas (mat,ventas,cant);
            muestroMat(mat,newcant,5);

            //Ordenar_Mostrar(ImporteTT,ventas); // vec de importes total con vector de importes total
            //mostrar(cantVentas,vprod);//cant y cod.productos
            //ActualizarArcVentas();
        }

}



/////////////////FUNCIONES///////////////////////////////////
int MayorACero (int dato)
{
    if(dato>0)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
int leerArchivos (int mat[][5],sVentas ventas[]) //leo archivos y cargo matriZ
{
    int i=0;
    FILE*archVentas;
    archVentas=fopen(".../archivos/ventas.dat","rb");

    if(archVentas==NULL)
    {
        printf("\nError al abrir el archivo.\n");
        getch();
        exit(1);
    }

    fread(&sVentas,sizeof(archVentas),1,archVentas);

    if(!feof(archVentas))
    {
        mat[ventas[i].cod_prod][ventas[i].cod_vend-1]+=ventas[i].cantidad;
        i++;
        fread(sVentas,sizeof(archVentas),1,archVentas);
    }

    fclose(archVentas);

    return i;

}
//---------------------------------------------------------------------------------------
void muestroMat (int mat[][5], sVentas vv[],int cf , int cc)
{

    int f,c;

    printf("\n\tPRODUCTO/VENDEDOR\tVEND 1\tVEND.2\tVEND.3\tVEND.4\tVEND.5\n");
    for(f=0;f<cf;f++)
    {
        printf("\n%-10s", ventas[f].cod_prod);
        for(c=0;c<cc;c++)
        {
            printf("\n%d", mat[f][c]);
        }
    }

}
//---------------------------------------------------------------------------------------
void cargoMatFilaColumna (int mat[][5],int vc[],float vi[], sProductos vp[], int cf,int cc)
{
    int f,c;

    for(f=0;f<cf;f++)
    {
        vc[f]+=mat[f][c];
    }
    for(c=0;c<cc;c++)
    {
        vi[c]+=((float)(mat[f][c])*vp[c].precio);
    }
}
//---------------------------------------------------------------------------------------
int nuevasVentas (,int mat[][5],sVentas vv[]int ce)
{
    sVentas auxVentas;
    char cp[11];
    int cv, cantidad,i=0;

    printf("\nIngresar CODIGO DE VENDEDOR (1 al 5 ,99 para fin):");
    auxVentas.cod_prod=ingresarDatoValido(1,5,99);

    while(cv!=99)
    {
        printf("\nIngresar CODIGO DE PRODUCTO (alfanumerico 10 caracteres):");
        getchar();
        do{
            gets(auxVentas.cod_prod);
            pos=buscarCodigo(vv,auxVentas.cod_prod,ce);
            if(pos==-1)
                printf("\nEl codigo no existe, volver a ingresar:");
        }while(pos==-1);


        printf("\nIngresar cantidad:");
        {
            fflush(stdin);
            scanf("%d",&auxVentas.cantidad);
        }while(MayorACero(auxVentas.cantidad)==0);

        mat[pos][cv]+=auxVentas.cantidad;

        i++;

        printf("\nIngresar CODIGO DE VENDEDOR (1 al 5 ,99 para fin):");
        auxVentas.cod_prod=ingresarDatoValido(1,5,99);
    }

    return i;
}

