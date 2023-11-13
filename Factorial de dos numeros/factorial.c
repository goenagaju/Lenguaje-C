#include <stdio.h>

int main ()
{
    int j, m , n , fm=1, fn=1;


    do{
        do{

        printf("Indicar valor de m:");
        scanf("%d", &m);

            }while(m<=0);

        do {
        printf("Indicar valor de n:");
        scanf("%d", &n);
            }while(n<=0);

        }while(m<=n);

        for (j=1;j<=m;j++)
            {
                fm*=j;
            }

        for (j=1;j<=n;j++)
            {
                fn*=j;
            }


        printf ("La productoria de %d es %d , la de %d es %d ", m,fm,n,fn);


}
