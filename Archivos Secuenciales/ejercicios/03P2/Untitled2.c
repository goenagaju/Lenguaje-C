#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    int codigo;
    float precio;
    char descripcion[50];
} sProducto;

int carga_productos(sProducto []);
void actualizar_productos(sProducto [], int);
int busco_producto(sProducto[], int, int);
void lectura(sProducto [], int);

int main()
{
    int cant, i;
    sProducto prod[100]; //vector de estructura

    printf("\nCARGA PRODUCTOS\n");
    cant = carga_productos(prod);  //funcion donde cargo los productos y retorno la cantidad cargada

    printf("\nACTUALIZACION DE PRODUCTOS\n");
    actualizar_productos(prod, cant); //funcion para actualizar la carga

    lectura(prod, cant); //funcion para leer los productos

    getch();
}
//---------------------------------------------------------------------------------------
int carga_productos(sProducto prod[])
{
    int codigo, i = 0, pos;
    float precio;

    FILE *ar, *exportar; //abro archivos

    ar = fopen("productos.dat", "wb");
    exportar = fopen("productos.csv", "wb");
    if (ar == NULL || exportar == NULL) //verifico q haya abierto bien
    {
        printf("Error, no se puedo abrir el archivo.");
        getch();
        exit(1);
    }

    printf("\nIngresar codigo del producto (para FIN codigo=0):");
    do
    {
        fflush(stdin);
        scanf("%d", &codigo);
    } while (codigo < 0);

    while (codigo != 0)
    {
        do
        {
            pos = busco_producto(prod, codigo, i);
            if (pos != -1)
            {
                printf("\nEl codigo ya se encuentra cargado, ingresar nuevamente:");
                do
                {
                    fflush(stdin);
                    scanf("%d", &codigo);
                } while (codigo < 0);
            }
        } while (pos != -1);

        prod[i].codigo = codigo;

        printf("\nIngresar precio del producto:");
        do
        {
            fflush(stdin);
            scanf("%f", &precio);
        } while (precio < 0);
        prod[i].precio = precio;

        printf("\nIngresar descripcion del producto:");
        getchar();
        gets(prod[i].descripcion);

        fwrite(&prod[i], sizeof(sProducto), 1, ar); //escribo el archivo con los datos cargados en PROD (&guardo en esa posicion de prod, con ese tamanio, esa cantidad, en ese archivo)
        fwrite(&prod[i], sizeof(sProducto), 1, exportar);

        i++;

        printf("\nIngresar codigo del producto (para FIN codigo=0):");
        do
        {
            fflush(stdin);
            scanf("%d", &codigo);
        } while (codigo < 0);
    }
    fclose(ar);
    fclose(exportar); //cierro archivos
    return i;
}
//---------------------------------------------------------------------------------------
void actualizar_productos(sProducto prod[], int ce)
{
    int pos, codigo;
    float precio;

    FILE *ar, *exportar;

    ar = fopen("productos.dat", "ab");
    exportar = fopen("productos.csv", "ab");

    if (ar == NULL || exportar == NULL)
    {
        printf("Error, no se puedo abrir el archivo.");
        getch();
        exit(1);
    }

    printf("\nIngresar codigo del producto (para FIN codigo=0):");
    do
    {
        fflush(stdin);
        scanf("%d", &codigo);
    } while (codigo < 0);

    while (codigo != 0)
    {
        do
        {
            pos = busco_producto(prod, codigo, ce);
            if (pos == -1)
            {
                printf("\nEl codigo NO se encuentra cargado, ingresar nuevamente:");
                do
                {
                     fflush(stdin);
                    scanf("%d", &codigo);
                } while (codigo < 0);
            }
        } while (pos == -1);

        printf("\nIngresar el precio del producto actualizado:");
        do
        {
             fflush(stdin);
            scanf("%f", &precio);
        } while (precio < 0);
        prod[pos].precio = precio;

        fwrite(&prod[pos], sizeof(sProducto), 1, ar);
        fwrite(&prod[pos], sizeof(sProducto), 1, exportar);

        printf("\nIngresar codigo del producto (para FIN codigo=0):");
        do
        {
             fflush(stdin);
            scanf("%d", &codigo);
        } while (codigo < 0);
    }

    fclose(ar);
    fclose(exportar);
}
//---------------------------------------------------------------------------------------
int busco_producto(sProducto prod[], int buscado, int ce)
{
    int i = 0, pos = -1;

    for (i = 0; i < ce; i++)
    {
        if (prod[i].codigo == buscado)
            pos = i;
    }

    return pos;
}
//---------------------------------------------------------------------------------------
void lectura(sProducto prod[], int ce)
{
    int i = 0;

    FILE *ar, *exportar;

    ar = fopen("productos.dat", "rb");
    exportar = fopen("productos.csv", "wb");

    if (ar == NULL || exportar == NULL)
    {
        printf("Error al abrir el archivo.");
        getch();
        exit(1);
    }

    fprintf(exportar, "CODIGO;PRECIO;DESCRIPCION\n");

    for (i = 0; i < ce; i++)
    {
        fread(&prod[i], sizeof(sProducto), 1, ar);
        fprintf(exportar, "%d;%.2f;%s\n", prod[i].codigo, prod[i].precio, prod[i].descripcion);
    }

    fclose(ar);
    fclose(exportar);
}
