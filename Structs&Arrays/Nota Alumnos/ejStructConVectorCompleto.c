#include <stdio.h>
#include <conio.h>
#include <string.h>
struct alumno
{
 char nombre [31];
 int dni;
 int notas[2];
};

///////////////////PROTOTIPO DE FUNCIONES///////////////////////////////////////////////////////////////////////////
int carga(struct alumno[], int);
void listar(struct alumno[], int);

/////////////////////////////PRINCIPAL////////////////////////////////////////////////////////////////////////////////////
int main()
{
 struct alumno vecAl[50]; //hay un vector con 50 elementos donde casa elemento tendra el tipo de variable Struct alumno
 int ca;
 ca = carga(vecAl,50);
 listar(vecAl,ca);
 getch();
 return 0;
}

/////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////////////////////
int carga(struct alumno va[], int max)
{
         int i=0,j;

         printf("Ingrese el dni del alumno (0 para terminar): ");
         scanf("%d", &va[i].dni);

        while (i<max && va[i].dni!=0)
        {
                 printf("Ingrese el nombre del alumno:");
                 getchar();//CUMPLE LA MISMA FUNCION QUE FFLUSH(STDIN);
                 gets(va[i].nombre);

                for (j=0;j<2;j++)//SE REPITE DOS VECES PORQUE EL VECTOR = vNOTAS[2]
                {

                     do
                     {

                         printf("Ingrese la nota del parcial %d: ", j+1);
                         scanf("%d", &va[i].notas[j]);

                    }while(va[i].notas[j]<1 || va[i].notas[j]>10);//valido que las notas esten dentro del rango

                }

                    i++;

                 if (i<max)
                 {
                     printf("Ingrese el dni del alumno (0 para terminar): ");
                     scanf("%d", &va[i].dni);
                 }
                 else
                    {
                    printf("El curso ya no tiene mas capacidad.\n");
                    }
            }

            return i;//retorno la cantidad de alumnos que se cargaron
        }
//------------------------------------------------------------------------------------------------------------------------------------------------------
void listar(struct alumno va[], int cantA)
{
 int i;
 char cond[9];
        printf ("%10s%31s%9s%10s", "DNI","NOMBRE", "PROMEDIO" , "CONDICION");

         for (i=0;i<cantA;i++)
         {
            if (va[i].notas[0]>=7 && va[i].notas[1]>=7)
                strcpy(cond, "APROBO");
         else
            if (va[i].notas[0]>=4 && va[i].notas[1]>=4)
            strcpy(cond, "CURSO");
         else
            strcpy(cond, "REPROBO");
            printf ("\n%10d%31s%9.2f%10s", va[i].dni,va[i].nombre, (va[i].notas[0]+va[i].notas[1])/2.,cond);
         }                                                      /*saco el promedio, el punto al lado del dos es para castear, es equivalente a poner un (float adelate)*/
}
