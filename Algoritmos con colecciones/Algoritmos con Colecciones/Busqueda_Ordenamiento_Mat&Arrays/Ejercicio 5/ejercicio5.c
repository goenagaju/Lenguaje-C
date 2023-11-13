/**1.1.5 La librería Libreto S.A. desea analizar las ventas realizadas por cada una de sus sucursales.
Existen 7 sucursales codificadas con los números 10, 20, 30, 40, 50, 60 y 70.

No se sabe la cantidad de libros que vende la empresa pero sí se sabe que no son más de 100.

Se debe realizar una carga inicial solicitando al usuario que ingrese por teclado los códigos de libros disponibles (los códigos
son de 4 dígitos).

Luego se ingresan por teclado las ventas realizadas, ingresando por cada venta los siguientes datos:

• Código de sucursal (entero 10, 20, 30, 40, 50, 60 o 70)
• Código de libro (entero de 4 cifras)
• Cantidad Vendida (entero mayor a 0)

Puede ingresarse más de una venta por libro/sucursal. Si un libro no se vendió en la sucursal no se informa.
La carga de datos finaliza al ingresar un código de libro igual a 0.

1. Cargar los libros disponibles en la empresa mediante la función CargaLibros, esta función debe asegurar
que se ingresen código de 4 cifras y no debe permitir ingresar códigos repetidos.

2. Mostrar el detalle de cantidad de libros vendidas en cada sucursal con el siguiente formato:

                    Libro/Sucursal 10 20 30 40 50 60 70
                    xxxx xx xx xx xx xx xx xx
                    xxxx xx xx xx xx xx xx xx
                    xxxx xx xx xx xx xx xx xx
                    …
                    xxxx xx xx xx xx xx xx xx

3. Mostrar la o las sucursales que vendieron mayor cantidad de libros

4. Mostrar aquellos libros que NO fueron vendidos en ninguna sucursal
*/

#include <stdio.h>


///funciones

int numeroEntero (int); //mayor a 0
int esDatoValido (int,int,int,int); //dato lim1 lim2 fin
int ingresarDatoValido (int,int,int); //lim1 lim2 fin
void cargaLibros (int[],int); // vector libros ,  ce
int cargaVentas (int[][7],int[],int,int); //matriz , codigo de libros, cf,cc
int buscar (int[],int,int);
void muestroMat(int[][7],int,int); //matriz, cf,cc
void sumoMatporFilas (int[][7],int[],int,int); //matriz, vector sucursales , cf ,cc
void sumoMatporColum (int[][7],int[],int,int);
int valorMaximo (int[],int); //vector libros , ce
void muestroMax (int[],int,int); //vector libros, max ,ce
void esIgualA (int[],int,int); //vector filas, elemento a comparar , ce


int main()
{
    int mat[100][7]={{0}}, vcodlibros[100]={0}, vsucursales[7]={0}/*vec x columnas*/,vlibros[100] /*vec x filas*/;
    int cant,max;

    cargaLibros(vcodlibros,100);
    cant=cargaVentas(mat,vcodlibros,100,7);

    if(cant>0)
    {
        printf("\nLibro/Sucursal 10\t20\t30\t40\t50\t60\t70");
        muestroMat(mat,cant,7);
        sumoMatporFilas(mat,vlibros,cant,7);
        sumoMatporColum(mat,vsucursales,cant,7);
        max=valorMaximo(vsucursales,7);
        printf("\nSucursales con mas ventas:");
        muestroMax(vsucursales,max,7);
        printf("\nLibros que no fueron vendidos:");
        esIgualA(vlibros,0,cant);
    }

}


///funciones

int numeroEntero (int dato)
{
    if (dato>0)
        return 1;
    else
        return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int esDatoValido (int dato,int lim1,int lim2,int fin)
{
    if(dato>=lim1 && dato<=lim2 || dato==fin)
        return 1;
    else
    {
        printf("\nDato incorrecto.Volver a ingresar:");
        return 0;
    }

}
//----------------------------------------------------------------------------------------------------------------------------------------
int ingresarDatoValido (int lim1,int lim2,int fin)
{
    int dato;

    do{
        scanf("%d",&dato);

    }while((esDatoValido(dato,lim1,lim2,fin))==0);

    return dato;
}
//------------------------------------------------------------------------------------------
void cargaLibros (int v[],int ce) // vector libros ,  ce
{
       int codigo,i=0,pos;

       printf("\nIngresar codigo del libro (0 para fin):");
       codigo=ingresarDatoValido(1000,9999,0);

       while(codigo!=0 && i<ce)
       {
            do{
                pos=buscar(v,codigo,i);
                if(pos!=-1)
                {
                  printf("\nCodigo repetido.Volver a ingresar:");
                  codigo=ingresarDatoValido(1000,9999,1000);
                }
            }while(pos!=-1); //mientras que se encuentre un valor

           v[i]=codigo;
           i++;

            printf("\nIngresar codigo del libro (0 para fin):");
            codigo=ingresarDatoValido(1000,9999,0);
       }

}
//------------------------------------------------------------------------------------------
int buscar (int v[],int datoBuscado,int ce)
{
    int i, pos=-1;

    for(i=0;i<ce;i++)
    {
        if(v[i]==datoBuscado)
            pos=i;
    }
        return pos;

}
//------------------------------------------------------------------------------------------
int cargaVentas (int mat[][7],int vlibros[],int cf,int cc) //matriz , codigo de libros, cf,cc
{
    int sucursal,codigo,cantidad,pos,i=0;

    printf("\nIngresar codigo de libro:");
    codigo=ingresarDatoValido(1000,9999,0);

    while(codigo!=0)
    {
        do{
            pos=buscar(vlibros,codigo,cf);
            if(pos==-1)
            {
                printf("\nCodigo incorrecto. Volver a ingresar:");
                codigo=ingresarDatoValido(1000,9999,1000);
            }
        }while(pos==-1);

        printf("\nIngresar codigo de sucursal (10-20-30-40-50-60-70):");
        do{
            sucursal=ingresarDatoValido(10,70,10);
            if((sucursal%10)!=0)
                printf("\nCodigo de sucursal incorrecto, ingresar nuevamente:");
        }while((sucursal%10)!=0);

        printf("\nIngresar cantidad de libros vendidos:");

        do{
            scanf("%d", &cantidad);

            if(numeroEntero(cantidad)==0)
                printf("Valor incorrecto.Volver a ingresar:");

        }while(numeroEntero(cantidad)==0);

        mat[codigo][sucursal]+=cantidad;

        i++;

        printf("\nIngresar codigo de libro:");
        codigo=ingresarDatoValido(1000,9999,0);
    }

        return i;
}
//------------------------------------------------------------------------------------------
void muestroMat (int mat[][7],int cf,int cc) //matriz, cf,cc
{
    int f,c;

    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
            printf("\t%d\n",mat[f][c]);

            printf("\n");
    }

        printf("\n");
}
//------------------------------------------------------------------------------------------
void sumoMatporFilas (int mat[][7],int v[],int cf,int cc) //matriz, vector nuevo , cf ,cc
{
        int f,c;

    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
            {
                v[f]=mat[f][c];
            }
    }
}
//------------------------------------------------------------------------------------------
void sumoMatporColum (int mat[][7],int v[],int cf,int cc)
{
        int f,c;

    for(c=0;c<cc;c++)
    {
        for(f=0;f<cf;f++)
            {
                v[c]=mat[f][c];
            }
    }
}
//------------------------------------------------------------------------------------------
int valorMaximo (int v[],int ce) //vector columnas , ce
{
    int i,max;

    for(i=0;i<ce;i++)
    {
        if(i==0)
            max=v[i];
        else
            if(v[i]>max)
                max=v[i];
    }

    return max;
}
//------------------------------------------------------------------------------------------
void muestroMax (int v[],int max,int ce) //vector columnas, max ,ce
{
    int i;

    for(i=0;i<ce;i++)
    {
        if(v[i]==max)
            printf("\n-%d",v[i]);
    }
}
//------------------------------------------------------------------------------------------
void esIgualA (int v[],int x, int ce) //vector filas
{
    int i;

        for(i=0;i<ce;i++)
        {
            if(v[i]==0)
                printf("\n-%d", v[i]);
        }
}




