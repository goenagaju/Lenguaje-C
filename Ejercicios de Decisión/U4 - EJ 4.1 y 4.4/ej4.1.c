//4.1. Se ingresan 3 números distintos. Determinar el mayor.

#include <stdio.h>

int main ()

{
    int n1,n2,n3;

    printf("\nIngresar n1:");
    scanf("%d",&n1);

    printf("\nIngresar n2:");
    scanf("%d",&n2);

    printf("\nIngresar n3:");
    scanf("%d",&n3);

    if (n1>n2)
    {
        if (n1>n3)
        {
            printf ("\nEl n1 es el numero mayor.\n\n");
        }
        else
            printf("\nEl numero 3 es el mayor numero.\n\n");
    }
    else
    {
        if (n2>n3)
        {
             printf ("\nEl n2 es el numero mayor.\n\n");
        }
        else
            printf("\nEl numero 3 es el mayor numero.\n\n");
    }

    return 0;
}

