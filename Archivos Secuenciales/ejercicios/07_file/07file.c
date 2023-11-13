/**Se dispone de un archivo que [contiene información] de los vuelos realizados por las distintas aerolíneas a lo
largo del mes. El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
• Código Aerolínea (alfanumérico de 10 caracteres máximo)
• Día (entero)
• Número de Vuelo (entero)
• Costo del pasaje (real)
• Pasajeros (inicialmente en el archivo viene en 0)

El mes tiene 30 días y se sabe que como máximo cada aerolínea realiza 5 vuelos diarios. Luego se dispone de un
segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros del mes para la aerolínea
con código “Aero1”, el archivo contiene los siguientes campos:
• DNI (entero)
• Número de Vuelo (entero)

Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1”
con la información de los pasajeros que realizar los viajes. Al finalizar, grabar la información en un nuevo
archivo llamado Aero1.dat. Agregar la opción para exportar el archivo Aero1 a formato csv.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#define TAM 50

///defino estructuras

typedef struct
{
    char codigo[11];
    int dia;
    int nro_vuelo;
    float costo_pasaje;
    int pasajeros;
}sVuelos;

typedef struct
{
    int dni;
    int nro_Vuelo;
}sPasajeros;

typedef struct
{
    int dia;
    int nroVuelo;
    float valorPas;
    int cantPas;
} sAero1;

///prototipo funciones

int esDatoValido(int,int,int);
int ingresarDatoValido (int,int);
int leerVuelos (sVuelos[], int);
void actualizarVuelos(sVuelos[],int);
void genero_Aero1 (sVuelos[],sAero1,int);
char constultar_csv();
int busqueda(sVuelos[],int,int);

int main()
{
    int cant;
    sAero1 aero1;
    sVuelos vv[150];

    cant=leerVuelos(vv,150);

    if(cant>0)
    {
        actualizarVuelos(vv,cant);
        genero_Aero1(vv,aero1,cant);
    }



}

///funciones

int esDatoValido(int dato,int lim1,int lim2)
{
    if(dato>=lim1 && dato<=lim2)
        return 1;
    else
    {
        printf("\nDato incorrecto.Volver a ingresar:");
        return 0;
    }
}
//---------------------------------------------------------------------------------------
int ingresarDatoValido (int lim1,int lim2)
{
    int dato;

    do{
        scanf("%d",&dato);

    }while((esDatoValido(dato,lim1,lim2))==0);

    return dato;
}
//---------------------------------------------------------------------------------------
int leerVuelos (sVuelos vv[], int ce) //filtro datos
{
    sVuelos auxVuelos;
    int i=0;

    FILE*archVuelos;
    printf("\nAbriendo archivo vuelos.dat");
    archVuelos=fopen(".../archivos/vuelos.dat","rb");
    if(archVuelos==NULL)
    {
        printf("\nError al abrir al archivo.");
        getch();
        exit(1);
    }

    fread(&auxVuelos,sizeof(sVuelos),1,archVuelos);

    while(!feof(archVuelos) && i<ce)
    {
            if(strcmpi(auxVuelos.codigo,"Aero1")==0)
            {
               strcpy(vv[i].codigo,auxVuelos.codigo);
                i++;
            }
            fread(&auxVuelos,sizeof(archVuelos),1,archVuelos);
    }

    fclose(archVuelos);
    printf("\ archivo vuelos.dat cerrado");
        return i;

}
//---------------------------------------------------------------------------------------
void actualizarVuelos(sVuelos vv[], int ce) //abro el archivo de pasajeros
{
    int pos;
    sPasajeros pas;

    FILE*archPas;

    printf("\nAbriendo archivo pasajeros.dat");

    archPas=fopen(".../archivos/pasajeros.dat","rb");

    fread(&pas,sizeof(archPas),1,archPas);

	while(!feof(archPas))
	{
	    pos=busqueda(vv,pas.nro_Vuelo,ce);

		if(pos!=-1)
            vv[pos].costo_pasaje++;
        fread(&pas,sizeof(archPas),1,archPas);
	}

	fclose(archPas);
	printf("\ archivo pasajeros.dat cerrado");
}
//---------------------------------------------------------------------------------------
void genero_Aero1 (sVuelos vv[],sAero1 aero1,int ce)
{
    char generar;
    int i;

	FILE*archAero1;
	FILE*exportar;

    printf("\nAbriendo archivo aero.dat");

	archAero1=fopen(".../archivos/Aero1.dat","wb");
    if(archAero1==NULL)
    {
        printf("\nError al abrir al archivo.");
        getch();
        exit(1);
    }

    generar=constultar_csv();
    if(generar=='S')
    {
        exportar=fopen(".../archivos/Aero1.csv","wt");
            if(exportar==NULL)
        {
            printf("\nError al abrir al archivo.");
            getch();
            exit(1);
        }

        for(i=0;i<ce;i++)
        {
            aero1.dia=vv[i].dia;
            aero1.nroVuelo=vv[i].nro_vuelo;
            aero1.valorPas=vv[i].costo_pasaje;
            aero1.cantPas=vv[i].pasajeros;
            fprintf(exportar, "%d,%d,%.2f,%d\n", aero1.dia, aero1.nroVuelo, aero1.valorPas, aero1.cantPas);

           // fwrite (&aero1,sizeof(exportar),1,exportar);
        }
    }

        fclose(archAero1);
    printf("\ archivo aero.dat cerrado");
        if(generar=='S')
        fclose(exportar);
}
//---------------------------------------------------------------------------------------
char constultar_csv()
{
    char respuesta;

    printf("\nDesea exportar el archivo, SI insertar ''S' o NO insertar 'N'?\n");
    do{
        scanf("%c", &respuesta);
    }while(!(respuesta=='S' || respuesta=='N'));

    return respuesta;
}
//---------------------------------------------------------------------------------------
int busqueda(sVuelos vv[],int buscado,int ce)
{
    int i,pos=-1;

    for(i=0;i<ce;i++)
    {
        if(vv[i].nro_vuelo==buscado)
            pos=i;
    }

    return pos;
}
//---------------------------------------------------------------------------------------
