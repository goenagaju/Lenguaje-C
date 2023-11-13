#include <stdio.h>

//prototipo funciones

int esDatoVali2(int,int,int);
int ingresarDatoVali2 (int,int);
int cargaDatos(int [][50],int[],int[],int[],int,int );
void mostrarmat (int [][50], int, int);
void sumarPorColumna (int [][50],int [],int,int);
void mostrarvec (int[],int);
void mostrarigualA(int [],int,int);

int main()

{
        int mat[24][50]={{0}}, vhora[24]={0}, vinterno[50], vlegajo[50], vTotalpasajeros[50]={0};
        int cant,i;

        cant=cargaDatos (mat,vhora,vinterno,vlegajo,24,50);

        if (cant!=0)
        {
            mostrarmat(mat,24,50);
            sumarPorColumna(mat,vTotalpasajeros,24,50);
            printf ("\n\nCantidad de pasajajeros por Colectivo\n\n");
            for (i=0;i<50;i++)
            {
                printf("\t%-4d",i+101);
            }
            mostrarvec(vTotalpasajeros,50);
            printf("\n\n\nColectivos que no hicieron ningun viaje\n\n");
            for (i=0;i<50;i++)
            {
                printf("\t%-4d",i+101);
            }
            mostrarigualA(vTotalpasajeros,50,0);


        }
}
//funciones
int esDatoVali2(int dato,int lim1,int lim2)
{
    if (dato>=lim1 && dato<=lim2)
        return 1;
    else
        return 0;
}
//-------------------------------------------------------------------------------------
int ingresarDatoVali2 (int lim1,int lim2)
{
    int dato;

    do{

        scanf("%d",&dato);

    }while((esDatoVali2(dato,lim1,lim2)==0));

    return dato;
}
//-------------------------------------------------------------------------------------
int cargaDatos(int mat[][50],int vh[],int vi[],int vl[],int cf, int cc )
{
    int hora,legajo,interno,i=0,cant,j,k;

    printf("\nIngresar numero de legajo (1001 al 1050, 0 para finalizar):");
    scanf("%d", &legajo);

    while(legajo!=0)
    {
        printf("\nIngresar hora de llegada a la terminal:");
        hora=ingresarDatoVali2(0,23);

        printf("\nIngresar cantidad de pasajeros que utilizaron el colectivo:");
        do{
            scanf("%d", &cant);
            }while(cant<0);

        vh[hora]+=cant;

        printf("\nIngresar numero de interno:");
        interno=ingresarDatoVali2(101,150);

        mat[hora][interno-101]+=1;

        i++;

        printf("\nIngresar numero de legajo (1001 al 1050, 0 para finalizar):");
        fflush(stdin);
        scanf("%d", &legajo);

    }


    if(i==1)
    {
        printf("\n\nCantidad de pasajeros por colectivo entre las 0 y 6 horas.");
        printf("\nCOLECTIVO/HORA \t1\t2\t3\t4\t5\t6");

        for(j=0;j<6;j++)
            printf("\n\t%d", j+101);

        for(k=0;k<6;k++)
            printf("\t%d", vh[j]);
    }
        printf("\n\n");
    return i;

}
//-------------------------------------------------------------------------------------
void mostrarmat (int mat[][50], int cf, int cc)
{
    int f,c;

    printf("\nHORA / INTERNO\t");
    for(f=0;f<cf;f++)
    {
        //printf("\n%d",f); //hora
        //printf("\t%-4d",f+101); //interno
        for(c=0;c<cc;c++)
        {
         printf("\t%-4d", mat[f][c]); //matriz
        }


    }

}
//-------------------------------------------------------------------------------------
void sumarPorColumna (int mat[][50],int v[],int cf,int cc)
{
    int f,c;
    for(c=0;c<cc;c++)
    {
        for(f=0;f<cf;f++)
        {
            v[c]+=mat[f][c];
        }
    }
}
//-------------------------------------------------------------------------------------
void mostrarvec (int v[],int ce)
{
    int i;

    for(i=0;i<ce;i++)
    {
        printf("\t%-4d", v[i]);
    }
}
//-------------------------------------------------------------------------------------
void mostrarigualA(int v[],int ce,int x)
{
    int i,cant=0;

    for(i=0;i<ce;i++)
    {
        if(v[i]==x)
            printf("\t%d", v[i]);
    }
}

