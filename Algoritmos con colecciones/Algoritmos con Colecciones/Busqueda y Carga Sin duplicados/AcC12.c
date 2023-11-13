/**1.1.2 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden
existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de
mayor a menor por nota.
*/

#include <stdio.h>

int numeroEntero (int);
int esDatoValido (int,int,int,int); //dato lim1 lim2 cond.fin
int ingresarDatoValido (int,int,int);
int carga (int[],int[],int); // vdni , vnota, ce
int buscar (int[],int,int); //vdni, dato buscado , ce a buscar
void ordenar (int[],int); //vnota , ce
void mostrarVecs (int[],int[],int);


int main()
{
    int vdni[60],vnota[60],cant;

    cant=carga(vdni,vnota,60);
    if(cant>0)
    {
        ordenar(vnota,60);
        mostrarVecs(vdni,vnota,60);
    }
}

//FUNCIONES

int numeroEntero (int x)
{
    if (x>0)
        return 1;
    else
    {
        printf("\nEl dato ingresado no es valido. Volver a ingresar:");
        return 0;
    }

}
//------------------------------------------------------------------------------
int esDatoValido (int dato,int lim1,int lim2,int fin) //dato lim1 lim2 cond.fin
{
    if (dato>=lim1 && dato<=lim2 || dato==fin)
        return 1;
    else
        return 0;

}
//------------------------------------------------------------------------------
int ingresarDatoValido (int lim1,int lim2,int fin) //lim1,lim2, cond.fin
{
    int dato;

    do{
        scanf("%d", &dato);

    }while(esDatoValido(dato,lim1,lim2,fin)==0);

    return dato;
}
//------------------------------------------------------------------------------
int carga (int vd[],int vn[],int ce) // vdni , vnota, ce
{
   int i,dni,nota,pos;

   printf("\nIngresar DNI del alumno - (para FIN: dni menor a 0):");
   dni=ingresarDatoValido(7000000,50000000,-1);

   while(dni>0)
   {
       do{
            pos=buscar(vd,dni,i);
            if(pos==-1)
            {
            printf("DNI no valido. Ingresar otro:");
            dni=ingresarDatoValido(7000000,50000000,-1);
            }

         }while(pos==-1);

        vd[i]=dni;

        printf("\nIngresar nota del alumno:");

        do{
           scanf("%d",&nota);
        }while((numeroEntero(nota))==0);

        vn[i]=nota;
        i++;
       dni=ingresarDatoValido(7000000,50000000,-1);
   }

    return i;
}
//------------------------------------------------------------------------------
int buscar (int vec[],int datoBuscado,int ce) //vdni, dato buscado , ce a buscar
{
    int i,pos=-1;

    for(i=0;i<ce;i++)
    {
        if(vec[i]==datoBuscado)
            return pos;
    }

    return pos;
}
//------------------------------------------------------------------------------
void ordenar (int v[],int ce) //vnota , ce
{
    int i,aux,posmin,j;

    for(i=0;i<ce-1;i++)
    {
        posmin=i; //se le asigna 0 a la variable posmin;

        for(j=i+1;j<ce;j++)
        {
            if(v[j]<v[posmin])
                posmin=j;
        }

        if(posmin!=i)
        {
            aux=v[i];
            v[i]=v[posmin];
            v[posmin]=aux;

        }
    }
}
//------------------------------------------------------------------------------
void mostrarVecs (int vd[],int vn[],int ce)
{
    int i;
    printf("\n     LISTADO");
    printf("\n------------");
    printf("\nDNI\tNOTA");

    for(i=0;i<ce;i++)
        printf("\n%8d\t%8d", vd[i],vn[i]);
}
//------------------------------------------------------------------------------






























































