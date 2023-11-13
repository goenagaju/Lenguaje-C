/**Una cadena de supermercados tiene 5 sucursales y comercializa 12 rubros distintos
de mercaderia. A diario se recibe las notas de pedido de mercaderia originidas por sus sucursales
estos datos son:

*Numero de sucursal (int , 1 a 5)
*Codigo de rubro (int 1 a 12)
*Cantidad pedida (int mayor a 0)

el ingreso de datos termina con numero de sucursal igual a cero, los datos vienen desor
denados y pueden venir para la misma sucursal y rubro mas de una informacion.

informar:
a- Cantidad pedida por sucursal en cada rubro
b- cantidad pedida por sucursal
c-cantidad pedida por rubro
d- rubro de MAYOR cantidad pedida (en total- suponemos unico)
e- cantidad pedidas del rubro 7 para todas las sucursales.
f- que sucursal pidio la MENOR cantidad en total (puede haber mas de una sucursal.)
g- cantidad de rubros NO pedidos por ninguna sucursal.*/

#include <stdio.h>


// Prototipo de funciones
int esDatoVali2 (int,int,int);
int ingreseDatoVali2 (int,int);
int CargaMatriz(int [][12], int, int);
void MostrarMatriz(int [][12], int, int);
void cargaVecXColumna(int [][12],int [],int,int);
void cargaVecXFila (int [][12],int [],int,int); // vector paralelo a las columnas
void mostrarVec (int [], int);
void buscarMax (int [], int);
void buscarMin (int [], int);
void buscarEnMatriz (int [][12],int); //punto e
void compararElementos (int [], int); //punto g


int main ()
{

    int mCargaDatos[5][12]={{0}},cant=0;
    int vRubro[12]={0},vSucursal[5]={0};


    cant=CargaMatriz(mCargaDatos,5,12);

    if (cant>0)
    {

        MostrarMatriz(mCargaDatos,5,12);

        cargaVecXFila(mCargaDatos,vSucursal,5,12); //cargo vec sucursal
        printf("\n\ncantidad pedida por Sucursal");
        mostrarVec(vSucursal,5);

        cargaVecXColumna(mCargaDatos,vRubro,5,12); //cargo vec rubro
        printf("\n\ncantidad pedida por Rubro");
        mostrarVec(vRubro,12);

        buscarMax(vRubro,12);
        buscarMin (vSucursal,5);
        buscarEnMatriz (mCargaDatos,5); //punto e
        compararElementos (vRubro,12);
    }
}

// FUNCIONES

int esDatoVali2 (int lim1,int lim2,int x)
{
    if(x>=lim1 && x<=lim2)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------
int ingreseDatoVali2 (int lim1,int lim2)
{
   int dato;

        do{
            scanf("%d", &dato);

            }while ((esDatoVali2(lim1,lim2,dato)==0));

        return dato;
}

//---------------------------------------------------------------------------------------------------------------------------------
int CargaMatriz(int mat[][12], int cf, int cc)
{
int rubro,sucursal,cant,i=0;

            printf("\nIngrese numero de Sucursal: ");
            sucursal=ingreseDatoVali2(0,5);

        while (sucursal!=0) // corre mientras que sucursal sea distinto que 0 y que i sea menor a cantidad de filas
        {
            printf("\nIngrese Codigo de Rubro:");
            fflush(stdin);
            rubro=ingreseDatoVali2(1,12);

            printf("\nIngrese Cantidad pedida: ");
            cant=ingreseDatoVali2(0,1000000);

            mat[sucursal-1][rubro-1]+=cant;   //cargo la matriz por acceso directo, y ademas acumulo la cantidad pedida.

            i++;

            printf("\n\nIngrese numero de Sucursal: ");
            sucursal=ingreseDatoVali2(0,5);
        }

        return i;
}

//---------------------------------------------------------------------------------------------------------------------------------

void MostrarMatriz(int mat[][12], int cf, int cc)

{
    int f,c;

    printf ("\n\tSUCURSAL x RUBRO\n\n");

    for (f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            printf ("\t%d", mat[f][c]);
        }

        printf ("\n");
    }

    printf ("\n\n");
}

//-------------------------------------------------------------------------------------------------------------------------
void cargaVecXColumna (int mat[][12], int vec[], int cf, int cc)
{
 int f,c,suma;

    for (c=0;c<cc;c++)
         {
            for (f=0;f<cf;f++)
             {
                vec[c] += mat[f][c];
             }
         }
}

//-------------------------------------------------------------------------------------------------------------------------
void cargaVecXFila (int mat[][12], int vec[], int cf, int cc)
{
 int f,c,suma;

    for (f=0;f<cf;f++)
         {
             for (c=0;c<cc;c++)
             {
                vec[f]+=mat[f][c];
             }
         }
}

//-------------------------------------------------------------------------------------------------------------------------
void buscarMax (int v[], int ce)
{
    int i, max, pos;

    for(i=0;i<ce;i++)
    {
        if(i==0)
        {
            max=v[i];
            pos=i+1;
        }
        else
            if (v[i]>max)
            {
                max=v[i];
                pos=i+1;
            }
    }

    printf("\n\nLa mayor cantidad pedida fue en el Rubro %d\n\n", pos);
}
//-------------------------------------------------------------------------------------------------------------------------
void buscarMin (int v[], int ce)

{
    int i,min,j;

    for(i=0;i<ce;i++)
    {
        if(i==0)
        {
          min=v[i];
        }
        else
            if (v[i]<min)
            {
                min=v[i];
            }
    }

    printf ("\nSucursal/es con la MENOR cantidad pedida:");

    for(j=0;j<ce;j++)
    {
        if(v[j]==min)
            printf("\n%d", j+1);
    }

}
//---------------------------------------------------------------------------------------------------
void mostrarVec (int v[], int ce)
{
    int i;

    for(i=0;i<ce;i++)
    {
        printf("\t%d", v[i]);
    }
}
//---------------------------------------------------------------------------------------------------
void buscarEnMatriz (int mat[][12],int cf)
{
    int f;

        for(f=0;f<cf;f++)
        {
            printf("\nCantidad pedida en sucursal %d: %d" ,f+1, mat[f][6]);
        }

}
//---------------------------------------------------------------------------------------------------
void compararElementos (int v[],int ce)
{
    int i,cant=0;

    for(i=0;i<ce;i++)
    {
        if(v[i]==0)
            cant++;
    }

    printf("\n\nCantidad de rubros NO pedidos por ninguna sucursal:%d\n\n", cant);
}
