/**2.2 Un laboratorio dispone de una lista con sus 50 medicamentos.
De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).

Se solicita:
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.*/

#include <stdio.h>
#include <string.h>
#define TAM 6

///declaro struct

typedef struct
    {
        int codigo;
        float precio;
        int stock;

    } medicamentos;

//declaro funciones

void ingreso (medicamentos [], int);
float busqueda_med (medicamentos[],int); //vector , ce
void informe (medicamentos[],int);
int buscarMed (medicamentos[],int,int); //vector , codigo med , ce

int main()
{
    medicamentos med[TAM];
    float precio;

    printf("\n\tCARGA MEDICAMENTOS");
    ingreso(med,TAM);

    precio=busqueda_med(med,1);
    
    if(precio!=-1) //si es -1 no deberia mostrar este msj
    printf("\nEl precio del medicamento buscado es $%2.f \n", precio);

    informe(med,TAM);

}

///funciones

void ingreso (medicamentos vm[], int ce)
{
   int i;

   for(i=0;i<ce;i++)
   {
       printf("\nIngresar codigo del medicamento:");
       do{
       		fflush(stdin);
           scanf("%d", &vm[i].codigo);

       }while(vm[i].codigo<100 && vm[i].codigo>999);

        printf("\nIngresar precio del medicamento:");
        do{
        	fflush(stdin);
            scanf("%f" , &vm[i].precio);
        }while(vm[i].precio<0);

        printf("\nIngresar stock:");
        do{
        	fflush(stdin);
            scanf("%d", &vm[i].stock);
        }while(vm[i].stock<0);
    }
}
//-------------------------------------------------------------------------------------------------
float busqueda_med (medicamentos vm[], int ce) //vector , ce
{
    int i,pos;

	printf("\n----------------------------------------------------------\n");
    for(i=0;i<ce;i++)
    {
         printf("\nIngresar codigo del medicamento que desea buscar:");
         do{
         	fflush(stdin);
        	scanf("%d", &vm[i].codigo);
        	}while(vm[i].codigo<100 && vm[i].codigo>999);

        pos=buscarMed(vm,vm[i].codigo,ce);

        if(pos!=-1) 				// es decir que si lo encontro retorna el precio de ese codigo
            return vm[pos].precio;
        else
            return pos; // si no lo encontro retorna -1
    }

}
//-------------------------------------------------------------------------------------------------
void informe (medicamentos vm[], int ce)
{
    int i;
    
	printf("\n----------------------------------------------------------\n");
    printf("\nMedicamentos cuyo stock es inferior a 10 unidades:");

    for(i=0;i<ce;i++)
    {
        if(vm[i].stock<10)
            printf("\n\t-%d", vm[i].codigo);
    }
}
//-------------------------------------------------------------------------------------------------
int buscarMed (medicamentos vm[],int buscado,int ce) //vector , codigo med , ce
{
    int i, pos=-1;

    for(i=0;i<ce;i++)
    {
        if(vm[i].codigo==buscado)
            pos=i;
    }

    return pos;
}
