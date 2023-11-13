//4.4. Ingresar 3 valores reales y:
//a. Si los dos primeros son mayores al tercero informar “MAYORES AL TERCERO”.
//b. Si los tres son iguales informar “TRES IGUALES .
//c. Si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR”.

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


    if (n1&&n2>n3)
    {
        printf("\nMAYORES AL TERCERO");
    }
    else
    {
        if (n1==n2 && n2==n3)
        {
            printf("\nTRES IGUALES");
        }
        else
        {
            if(n1<n3 || n2<n3)
            {
                printf("\nALGUNO ES MENOR");

            }
        }
    }
}
