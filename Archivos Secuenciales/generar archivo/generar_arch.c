///puedo ir modificando segun lo q necesite

#include <stdio.h>
#define ARCHIVO "productos.dat"

typedef struct
{
    int codigo;
    char descripcion[21];
    float precio;
}T_Registro;

int main()
{
    int i, cant;
    T_Registro vec[]={
            {1000,"peine",190.35},
            {2000,"lapiz",290.35},
            {3000,"hojas",290.35}
    };

    FILE *fp;
    cant = sizeof(vec) / sizeof(T_Registro);
    fp = fopen(ARCHIVO, "wb");
    for (i=0;i<cant;i++)
        fwrite(&vec[i],sizeof(T_Registro),1, fp);
    fclose(fp);

    return 0;
}

/**
fopen () Abre un archivo.

fclose () Cierra un archivo.

fwrite () Guarda un registro en el archivo.

fread () Lee un registro del archivo.

feof() Devuelve un número distinto de 0 si se llega al final del archivo. Se utiliza solo si primero se leyo el archivo.


*/
