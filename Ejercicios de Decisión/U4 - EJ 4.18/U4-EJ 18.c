/*4.18. Confeccionar un programa que permita ingresar la fecha actual (día, mes y año) y la fecha de nacimiento
de una persona (día, mes y año). Con ambos datos debe calcular la edad de dicha persona.*/

#include <stdio.h>

int main ()

{
    int diaactual,mesactual,anioactual, dianacimiento, mesnacimiento, anionacimiento;

    printf ("\nIngresar dia de hoy:\n");
    scanf("%d", &diaactual);

    if (diaactual>0 && diaactual <=31)
    {
        printf ("\nIngresar mes actual:\n");
        scanf ("%d" , &mesactual);

        if (mesactual>0 && mesactual<=12)
        {
            printf ("\nIngresar anio actual:\n");
            scanf("%d", &anioactual);

            if (anioactual > 1955 && anioactual <=2023)
            {
                printf ("\nIngresar dia de nacimiento:\n");
                scanf ("%d",&dianacimiento);

                if (dianacimiento>0 && dianacimiento <=31)
                {
                    printf("\nIngresar mes de nacimiento:\n");
                    scanf ("%d", &mesnacimiento);

                    if (mesnacimiento>0 && mesnacimiento<=12)
                    {
                        printf("\nIngresar anio de nacimiento:\n");
                        scanf("%d",&anionacimiento);

                        if (anionacimiento > 1955 && anionacimiento<=2023)
                        {
                            if (diaactual<dianacimiento && mesactual<=mesnacimiento)

                            printf ("\nLa edad es: %d\n", (anioactual-anionacimiento)-1);

                            else
                                printf("\nLa edad es:%d\n", anioactual-anionacimiento);
                        }
                        else
                            printf ("\nEl anio de nacimiento no es valido.");
                    }
                    else
                        printf("\nEl mes de nacimiento no es valido.");
                }
                else
                    printf("\nEl dia indicado no es valido.");
            }

            else
                printf ("\nEl anio actual no es valido.");
        }
        else
            printf ("\nEl mes actual no es valido.");
    }

    else
        printf ("\nEl dia indicado no es valida");



return 0;

}
