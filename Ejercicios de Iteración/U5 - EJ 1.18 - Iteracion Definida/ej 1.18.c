/*Realizar un programa que muestre por pantalla las tablas de multiplicar del 1 al 9 de la siguiente forma:

        1 2 3 4 5 6 7 8 9
        2 4 6 8 10 12 14 16 18
        3 6 9 12 15 18 21 24 27
        4 8 12 16 20 24 28 32 36
        5 10 15 20 25 30 35 40 45
        6 12 18 24 30 36 42 48 54
        7 14 21 28 35 42 49 56 63
        8 16 24 32 40 48 56 64 72
        9 18 27 36 45 54 63 72 81

*/

#include <stdio.h>

int main ()

{
    int i=0,j=0;

    for (i=1;i<5;i++)
    {
        for (j=1;j<=5;i++)
        {
        //printf ("\n");
        printf (" %d", i*j);
        printf ("\t|");
        }

    }

    return 0;
}

/*
#include <stdio.h>

int main ()

{
    int i=0;

    for (i=1;i<=9;i++)
    {
        printf ("\n");
        printf ("%d", i*1);
        printf ("\t|");
        printf ("%d  ", i*2);
        printf ("|\t");
        printf ("%d  ", i*3);
        printf ("|\t");
        printf ("%d  ", i*4);
        printf ("|\t");
        printf ("%d  ", i*5);
        printf ("|\t");
        printf ("%d  ", i*6);
        printf ("|\t");
        printf ("%d  ", i*7);
        printf ("|\t");
        printf ("%d  ", i*8);
        printf ("|\t");
        printf ("%d  ", i*9);


    }

    return 0;
}
*/

