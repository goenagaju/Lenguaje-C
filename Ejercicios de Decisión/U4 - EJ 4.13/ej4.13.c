/*4.13. Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los
números de catálogo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Se desea
confeccionar un programa al que informándole el número de catálogo indique si el artículo es o no
defectuoso. Los artículos del catálogo van desde el 1200 al 90000. Si se ingresa otro número informar
“FUERA DE CATALOGO”.*/

/*ANALISIS: un rango de x a x articulos son defectuosos
1:ingreso num cat
2: identifico si esta dentro del rango del catalogo de los arituculos (12000 al 90000)
3:si el articulo es valido identifico si el numero del articulo esta dentro de los defectuosos
4:si es defectuoso informar si es o no defectuoso


*/
#include <stdio.h>

int main ()

{
    int art;

    printf ("\n Ingresar numero de articulo que sea valido:");
    scanf ("%d",&art);

    if (art>=1200 && art<=90000) //art valido
    {

        if(art>=12121 && art<=18081 || art>=30012 && art<=45565 || art>=67000 && art<=68000)

        {
            printf("\nEl articulo es defectuoso.\n");
        }

        else
            printf ("\nEl articulo NO es defectuoso.\n");
    }

    else
        printf("\nEl numero de articulo no esta dentro del catalogo.");

























}
