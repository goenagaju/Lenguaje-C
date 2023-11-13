/*Se realizó un concurso de tiro al blanco.
Existen 5 participantes y cada uno de ellos efectúa 3 disparos,
registrándose las coordenadas X-Y de cada disparo.

Determinar:
a. Cuantos disparos se efectuaron en cada cuadrante por cada participante

b. Cuantos disparos se efectuaron en total en el centro.

NOTA: no considere disparos sobre los ejes*/

#include <stdio.h>

int main ()

{
    int i,j,c1=0,c2=0,c3=0,c4=0,cen=0,x,y;

    for (i=1;i<=5;i++)
    {
        for(j=1;j<=3;j++)

        {
            printf ("\n Ingrese x: ");
            scanf ("%d", &x);
            printf("\n Ingrese y:");
            scanf("%d", &y);

                if(x>0 && y>0)
                    c1++;
                else
                    if(x<0 && y>0)
                        c2++;
                    else
                        if(x<0 && y<0)
                            c3++;
                        else
                            if(x>0 && y<0)
                            c4++;
                            else
                                if (x==0 && y==0)
                                cen++;
        }
        printf ("\nEl participante %d disparo en:\n c1: %d \n c2: %d \n c3: %d \n c4: %d", i, c1,c2,c3,c4);
        c1=c2=c3=c4=0;

    }

    if (cen>0)
        printf ("\n Se efectuaron en total %d disparos en el centro.", cen);
    else
    printf("\nNo hubo disparos en el centro");


    return 0;
}
