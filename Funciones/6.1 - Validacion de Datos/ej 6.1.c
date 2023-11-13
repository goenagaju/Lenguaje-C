#include <stdio.h>
#include <ctype.h>

////prototipos de funciones
int esDatoVal2 (int,int);
int ingresarDato (int);
int mostrarMenu (int,int);


int main ()

{
    int n1,n2,op;

    n1=ingresarDato (0);
    n2=ingresarDato(0);

    op=mostrarMenu(n1,n2);

    while(op!=6)
    {
        switch(op)
        {
            case 1:
                    printf ("\n\nLa suma entre ambos numeros es: %d", n1+n2);
                    getchar();
                    break;
            case 2 :
                    printf("\n\nLa resta entre los numeros es: %d", n1-n2);
                    getchar();
                    break;
            case 3:
                    printf("\n\nLa multiplicacion entre los numeros es: %d", n1*n2);
                    getchar();
                    break;
            case 4:
                    printf("\n\nLa division entre los numeros es: %.2f", (float)n1/n2);
                    getchar();
                    break;
            case 5:
                        n1=ingresarDato (0);
                        n2=ingresarDato(0);
                        op=mostrarMenu(n1,n2);
                        break;
        }

        getchar();
        op=mostrarMenu(n1,n2);
    }
}

int esDatoVal2 (int x, int lim)
{
    if (x>lim)
        return 1;
    else
        return 0;
}

int ingresarDato (int lim)

{
    int x,r;

    do{
        printf ("Ingresar dato:");
        scanf ("%d", &x);
    }while((r=esDatoVal2(x,lim))==0);

    return x;
}



int mostrarMenu (int n1,int n2)

{
    int op;

    printf("\n\nMenu de opciones \n -------------- \n Numero 1 : %d \t\t Numero 2: %d", n1,n2);
    printf ("\n\n1) Sumar \n 2) Restar \n 3) Multiplicar \n 4) Dividir \n 5) Ingresar Nuevos Numeros \n 6) Salir \n\n");

    op=ingresarDato (0);

    return op;
}

