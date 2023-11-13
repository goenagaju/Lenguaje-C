/*5.2.5 De cada uno de los alumnos de un curso se ingresa su número de DNI y las notas de los dos exámenes
parciales confeccionar, un programa que muestre por cada alumno su condición final con el siguiente
mensaje:

“El alumno con DNI: xxxxxxx, obtuvo las notas: xx y xx [condición final]”
La condición final se establece según las siguientes reglas:
 PROMOCIONA: ambas notas > = 7
 RINDE EXAMEN FINAL: ambas notas > = 4
 REPROBO LA MATERIA: alguna nota no cumple lo anterior
El programa finaliza cuando se ingresa un valor negativo como número de DNI. Al finalizar mostrar la nota
promedio de alumnos promocionados.*/

#include <stdio.h>

int main ()

{
    int n1,n2,dni=0;

    printf ("\n Ingresar DNI del alumno:");
    fflush (stdin);
    scanf("%d", &dni);

    while (!(dni<0))
    {
        printf("\nIngresar primer Nota:");
        scanf("%d", &n1);
        printf("\nIngresar segunda Nota:");
        scanf("%d", &n2);

        if (n1 >= 7 && n2 >= 7)
            printf ("\nEl alumno con dni %d PROMOCIONA.", dni);
        else
            if (n1 >=4 && n2 >=4)
                printf ("\nEl alumno con dni %d RINDE EXAMEN FINAL.");
            else
                if (n1 <4 || n2 < 4)
                    printf ("\nEl alumno con dni %d REPROBO LA MATERIA.");

        printf ("\n Ingresar DNI del alumno:");
        scanf("%d", &dni);

    }

    return 0;
}
