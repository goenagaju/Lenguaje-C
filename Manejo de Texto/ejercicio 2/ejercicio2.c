/**
1.2.2 Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las
funciones de la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre
coma espacio y apellido) y mostrarlo

*/

#include <stdio.h>
#include <string.h>


void leerTexto (char[],int);

int main()

{
    char nombre[11], apellido[11], AyN[23];

    printf("\nIngresar Nombre:");
    leerTexto(nombre,11);
    printf("\nIngresar Apellido:");
    leerTexto(apellido,11);

    strcpy(AyN,nombre);
    strcat(AyN,", ");
    strcat(AyN,apellido);

    printf("\nSu nombre y apellido es:%s", AyN);
    //puts(AyN);
}

///funciones

void leerTexto (char texto[], int ce)
{
    int i=0;

    fgets(texto,ce,stdin);

    while(texto[i]!='\0')
    {
        if(texto[i-1]=='\n')
            texto[i-1]='\0';

        i++;
    }
}
