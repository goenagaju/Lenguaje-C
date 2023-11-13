/**Los datos de los alumnos de una comisión de Computación Transversal son:

• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)

a. Declarar un tipo de dato que contenga la información del alumno.

b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”.

        !!! Esta información de grabación finaliza con DNI cero.

c. Leer los datos del archivo, mediante la Función LECTURA.
*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <conio.h>

//estructuras

typedef struct
{
    int dni;
    char nya [81];
    int nota1;
    int nota2;
    float promedio;
}sAlumnos;

///funciones

int esDatoValido(int,int,int,int);
int ingresarDatoValido (int,int,int);
sAlumnos carga_Alumnos();
void lectura(sAlumnos);


int main()
{

    sAlumnos alumnos;
    FILE* ar;

    ar=fopen("C:\\Users\\Pichi\\Documents\\Juli facu\\PROGRAMACION\\Lenguaje C\\Archivos Secuenciales\\ejercicios\\01_file\\alumnos.dat","wb");

    if(ar==NULL)
    {
        printf("\nError en el archivo, no se puedo abrir.");
        getch();
        exit(1);
    }

    printf("\nCARGA ALUMNOS\n");
        alumnos=carga_Alumnos(); //cargo el archivo

    lectura(alumnos); //lectura de archivo

    fclose(ar); //cierro el archivo

    printf("\n");
    getch();
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
sAlumnos carga_Alumnos()
{
    int dni,nota1,nota2;
    sAlumnos alum;

    FILE *ar; // Abrir el archivo aquí

    ar = fopen("C:\\Users\\Pichi\\Documents\\Juli facu\\PROGRAMACION\\Lenguaje C\\Archivos Secuenciales\\ejercicios\\01_file\\alumnos.dat", "ab");

    if (ar == NULL)
    {
        printf("\nError al abrir el archivo.");
        getch();
        exit(1);
    }

    printf("\nIngresar DNI del alumno (para FIN : 0):");
    dni=ingresarDatoValido(7000000,50000000,0);

    while(dni!=0)
    {
        alum.dni=dni;

        printf("\nIngresar Nombre y Apellido:");
        getchar();
        gets(alum.nya);

        printf("\nIngresar Nota 1:");
        fflush(stdin);
        nota1=ingresarDatoValido(1,10,1);
        alum.nota1=nota1;

        printf("\nIngresar Nota 2:");
        fflush(stdin);
        nota2=ingresarDatoValido(1,10,1);
        alum.nota2=nota2;

        alum.promedio=((float)(alum.nota1+alum.nota2)/2);

        fwrite(&alum, sizeof(alum), 1, ar);

        printf("\nIngresar DNI del alumno (para FIN : 0):");
        fflush(stdin);
        dni=ingresarDatoValido(7000000,50000000,0);

    }

     fclose(ar);

    return alum;
}


//---------------------------------------------------------------------------------------
void lectura(sAlumnos alum)
{
    FILE* ar;

    ar=fopen("C:\\Users\\Pichi\\Documents\\Juli facu\\PROGRAMACION\\Lenguaje C\\Archivos Secuenciales\\ejercicios\\01_file\\alumnos.dat","rb");

    if (ar==NULL)
    {
        printf("Error al abrir el archivo.");
        getch();
        exit(1);
    }

    printf("\n\tDNI         \tNombre y Apellido   \tNota 1    \tNota 2    \tPromedio");
    fread(&alum,sizeof(alum),1,ar);

    while(!feof(ar))
    {
        printf("\n\t%-8d    \t%-20s\t%-2d      \t%-2d      \t%-2.2f", alum.dni,alum.nya,alum.nota1,alum.nota2,alum.promedio);
        fread(&alum,sizeof(alum),1,ar);
    }

    fclose(ar);

}
