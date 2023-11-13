/**
Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos.

La carga finaliza con un alumno de nombre FIN.

Luego de cargar los alumnos se pide:

a. Ingresar nombres de a uno en uno y buscarlos.

Si el nombre está en el curso mostrar su DNI y sino informar que no está.

Seguir ingresando nombres hasta que se ingrese un nombre igual a NOBUSCARMAS.

b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor*/

#include<stdio.h>
#include<string.h>

int esdatoValido (int,int,int);
int ingresarDatoValido(int,int);
int cargaAlumnos (char[][16],int[]); //vector string [50][15] , vector dni , ce
void buscarAlumnos (char[][16],int[],int);
int buscotexto (char [][16],char,int);
void mostrartexto (char[][16], int);
void ordenartexto (char [][16], int);

int main()
{
    int vdni[50],cant;
    char valumnos[50][16];

    cant=cargaAlumnos(valumnos,vdni);
    buscarAlumnos(valumnos,vdni,cant);
    ordenartexto(valumnos,cant);
    printf("\nListado de alumnos ordenado alfabeticamente de menor a mayor:");
    mostrartexto(valumnos,cant);


}

///funciones

int esdatoValido (int dato,int lim1,int lim2)
{
    if(dato>=lim1 && dato<=lim2)
        return 1;
    else
    {
        printf("\nEl dato ingresado es incorrecto.Volver a ingresar:");
        return 0;
    }

}
//-----------------------------------------------------------------------------------
int ingresarDatoValido(int lim1,int lim2)
{
    int dato;

    do{
        scanf("%d",&dato);
    }while((esdatoValido(dato,lim1,lim2)==0));

    return dato;
}
//-----------------------------------------------------------------------------------
int cargaAlumnos (char v[][16],int vdni[]) //vector string [50][15] , vector dni , ce
{
    int i=0,dni;
    char nombre[16];

    printf("\nIngresar nombre del alumno:");
    fflush(stdin);
    gets(nombre);

    while(strcmpi(nombre,"FIN")!=0)
    {
        strcpy(v[i],nombre);

        printf("\nIngrese numero de dni:");
        dni=ingresarDatoValido(7000000,50000000);
        vdni[i]=dni;

        i++;

        printf("\nIngresar nombre del alumno:");
        fflush(stdin);
        gets(nombre);

    }

    return i;
}
//-----------------------------------------------------------------------------------
void buscarAlumnos (char vn[][16],int vdni[],int ce) // vstring nombres, dni's , ce
{
    int pos;
    char nombre[16];

    printf("\nIngresar nombre del alumno que desea buscar (para fin 'NOBUSCARMAR'):"); // llega hasta aca y muere
    fflush(stdin);
    gets(nombre);

    while(strcmpi(nombre,"NOBUSCARMAR")!=0)
    {
       pos=buscotexto(vn,nombre,ce);

       if(pos!=-1)
           printf("\n\tEl DNI del alumno es %d" , vdni[pos]);
       else
       {
       	    if(pos==-1)
            	printf("\nEl alumno no se encuentra en la lista.");
	   }


        printf("\nIngresar nombre del alumno que desea buscar:");
        fflush(stdin);
        gets(nombre);

    }
}
//-----------------------------------------------------------------------------------
int buscotexto (char v[][16],char buscado,int ce)
{
    int i,pos=-1;

    while(pos==-1 && i<ce)
    {
        if(strcmpi(v[i],buscado)==0)
            pos=i;
        else
            i++;
    }

    return pos;
}
//-----------------------------------------------------------------------------------
void mostrartexto (char v[][16], int ce)
{
 int f;

   for (f=0;f<ce;f++)
    {
      puts(v[f]);//ACCESO COMO VECTOR.
    }
}
//-----------------------------------------------------------------------------------
void ordenartexto (char v[][16], int ce)
{
    int i,j;
    char aux[16];

    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(strcmpi(v[j],v[j+1])>0) //si v[j] es mayor a v[j+1] HACE EL INTERCAMBIO
            {
                strcpy(aux,v[j]);
                strcpy(v[j],v[j+1]);
                strcpy(v[j+1],aux);
            }
        }
    }
}
