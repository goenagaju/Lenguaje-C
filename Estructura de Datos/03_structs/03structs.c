/**
Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos.

De cada alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).

Se solicita:
.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.

d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.

e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.

*/

#include <stdio.h>
#include <string.h>

typedef struct
    {
        int dni;
        char ayn[80];
        int nota1;
        int nota2;
        float promedio;
    }sAlumnos;

///prototipo funciones

int esDatoValido(int,int,int,int);
int ingresarDatoValido (int,int,int);
int INGRESO (sAlumnos[]);
void RESULTADO (sAlumnos[],int);
void INFORME_PROMO (sAlumnos[],int);


int main()
{
    sAlumnos alumnos[80];
    int cant;

    printf("\n\t***CARGA ALUMNOS***\n");
    cant=INGRESO(alumnos);
    if(cant>0)
    {
        RESULTADO(alumnos,cant);
        INFORME_PROMO(alumnos,cant);
    }

}

///funciones
int esDatoValido(int dato,int lim1,int lim2,int fin)
{
    if(dato>=lim1 && dato<=lim2 || dato==fin)
        return 1;
    else
    {
        printf("\nDato incorrecto.Volver a ingresar:");
        return 0;
    }
}
//---------------------------------------------------------------------------------------
int ingresarDatoValido (int lim1,int lim2,int fin)
{
    int dato;

    do{
        scanf("%d",&dato);

    }while((esDatoValido(dato,lim1,lim2,fin))==0);

    return dato;
}
//---------------------------------------------------------------------------------------
int INGRESO (sAlumnos va[])
{
    int i=0,nota1,nota2,dni;

    printf("\nIngresar DNI del alumno:");
    dni=ingresarDatoValido(7000000,50000000,0);

    while(dni!=0)
    {
        va[i].dni=dni;

        printf("\nIngresar Apellido y Nombre del alumno:");
        getchar();
        gets(va[i].ayn);

        printf("\nIngresar NOTA 1:");
        nota1=ingresarDatoValido(1,10,1);
        va[i].nota1=nota1;

        printf("\nIngresar NOTA 1:");
        nota2=ingresarDatoValido(1,10,1);
        va[i].nota2=nota2;

        va[i].promedio=((nota1+nota2)/2);

        i++;

        printf("\nIngresar DNI del alumno:");
        dni=ingresarDatoValido(7000000,50000000,0);
    }

    return i;
}
//---------------------------------------------------------------------------------------
void RESULTADO (sAlumnos va[],int ce)
{
    int i, aprobados=0,reprobados=0;

    printf("\n");
    for(i=0;i<ce;i++)
    {
        if(va[i].nota1>=4 && va[i].nota2>=4)
            aprobados++;
        else
            reprobados++;
    }

    printf("\nCantidad de alumnos que APROBARON la materia: %d", aprobados);
    printf("\nCantidad de alumnos que REPROBARON la materia: %d\n", reprobados);
}
//---------------------------------------------------------------------------------------
void INFORME_PROMO (sAlumnos va[],int ce)
{
    int i;

    printf("\nAlumnos APROBADOS:\n");

    for(i=0;i<ce;i++)
    {
        if(va[i].nota1>=7 && va[i].nota2>=7)
            printf("\nDNI:%d\tApellido y Nombre:%-8s\t Nota Promedio:%3.f\n", va[i].dni,va[i].ayn,va[i].promedio);
    }

}
