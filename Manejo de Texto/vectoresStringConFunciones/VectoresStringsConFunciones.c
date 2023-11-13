/*

 VECTORES DE STRINGS COMO PARÁMETROS FORMALES Y ACTUALES DE UNA FUNCIÓN
 ----------------------------------------------------------------------

 Recordar que el nombre o identificador del vector de string es una referencia a la primera dirección de la zona de memoria reservada.

 -vector de string  como parámetro real o actual o argumento:  SOLO DE COLOCA EL NOMBRE O IDENTIFICADOR DE LA MATRIZ.
                                                    EN REALIDAD LO QUE SE ENVÍA ES LA DIRECCIÓN DE INICIO
                                                    DE MEMORIA PARA QUE SE COPIE EN OTRO ARRAY EN VIRTUD
                                                    DE QUE AMBOS APUNTEN A LA MISMA DIRECCIÓN DE MEMORIA.
                                                    EL PASAJE DE PARÁMETROS ES POR REFERENCIA.


- vector de string  como parámetro formal: ES IGUAL A LA DECLARACIÓN DE UN VECTOR DE STRING, PERO NO ES OBLIGATORIO COLOCAR EL TAMAÑO DE FILA,
                                           PERO SÍ ES OBLIGATORIO COLOCAR EL TAMAÑO DE LA COLUMNA.

- Tipo de dato del vector de string  en el prototipo: char [][CANTIDAD DE COLUMNAS]  - NO ES OBLIGATORIO COLOCAR LA CANTIDAD DE FILAS -


*/

#include <stdio.h>
#include <conio.h>

//DECLARACIÓN DE CONSTANTES.
#define CANT_FILAS 4
#define CANT_COLUMNAS 20


//PROTOTIPO DE FUNCIONES

void Carga(char [][CANT_COLUMNAS],int);
void Mostrar(char [][CANT_COLUMNAS],int);




int main()
{

  char VecString [CANT_FILAS][CANT_COLUMNAS];//DECLARACIÓN.


 printf("La direccion de inicio de memoria del vector de string declarada en el main es %x\n\n",VecString);

 //LLAMAR O INVOCAR A LAS FUNCIONES.
 Carga(VecString,CANT_FILAS);  //SOLO SE COLOCAR EL NOMBRE DEL VECTOR DE STRING CUANDO SE ENVÍA COMO PARÁMETOR REAL.
 Mostrar(VecString,CANT_FILAS); //SOLO SE COLOCAR EL NOMBRE DEL VECTOR DE STRING CUANDO SE ENVÍA COMO PARÁMETOR REAL.


 getch();
 return 0;

}

//DEFINICIÓN DE FUNCIONES.
void Carga(char VecString[][CANT_COLUMNAS],int cf)
{
 int f;

 printf("\nEl contenido de la vector de string mat (VecString que recibe como parametro formal) de la funcion en Carga es %x\n\n",VecString);

   for (f=0;f<CANT_FILAS;f++)//CARGA POR FILAS.
       {
          printf("Ingrese el %d string:",f+1);
          gets(VecString[f]);//ACCESO COMO VECTOR.
       }
}
/////////////////////////////////////////////////////////////////////////
void Mostrar(char VecString[][CANT_COLUMNAS],int cf)
{
 int f;

 printf("\nEl contenido de la vector de string mat (VecString que recibe como parametro formal) de la funcion en Carga es %x\n\n",VecString);

  printf("\nVECTOR DE STRINGS\n");
   for (f=0;f<CANT_FILAS;f++)
    {
      puts(VecString[f]);//ACCESO COMO VECTOR.
    }

}

