/**
1.2.1 Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas por un único espacio.
b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo

*/


#include <stdio.h>

void leerTexto (char[], int ce);
int contarPalabras (char[]);
int contPalabras(char[]);


int main()

{
    int cantidad,cant;
    char frase[501]; //el uno es por el fin de texto '\0'

    printf("\nIngresar frase:");
    leerTexto(frase,501);
    cantidad=contarPalabras(frase);
    printf("\n\tLa frase separada por un unico espacio tiene %d palabra/s\n\n", cantidad);

    printf("\nIngresar frase:");
    leerTexto(frase,501);
    cant=contPalabras(frase);
    printf("\n\tLa frase separada por más de un espacio consecutivo tiene %d palabras\n\n", cant);


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
//-------------------------------------------------------------------------------------------------
int contarPalabras (char texto[])
{
    int i=0,palabras=0;

    while (texto[i]!='\0')
    {
        if(texto[i]==' ')
            palabras++;

        i++;
    }

    return palabras+1; // si hay 3 palabras separadas por un unico espacio va a contar 2 palabras, por eso el +1
}
//-------------------------------------------------------------------------------------------------
int contPalabras (char texto[])
{
    int i=0,palabras=0;

    while(texto[i]!='\0')
    {
        //i>0 por si arranca con un espacio
        //si antes habia otro espacio entonces hay espacios seguidos

        if(i>0 && texto[i]==' ' && texto[i-1]!=' ') // si el actual es (espacio) y ademas i-1 (el anterior) NO es (espacio) cuanto una palabra
            palabras++;

        i++;
    }

        //agrego una palabra mas porque la ultima no la cuenta por el \0
        if(i>0 && texto[i-1]!=' ')
            palabras++;
    return palabras;
}


