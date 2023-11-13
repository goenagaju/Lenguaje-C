/***1.1.4 Una empresa desea realizar un cuadro con el detalle anual de las ventas de sus productos
Por teclado se ingresa el detalle de ventas:

• Código de Producto (entero de 5 cifras)
• Mes (entero del 1 al 12)
• Cantidad Vendida (entero mayor a 0)
• Precio Unitario (float)

La carga se realiza sin orden alguno y finaliza con un código de producto igual a 0.

No se sabe la cantidad exacta de productos, pero sí que no son más de 30.
No se realiza carga inicial de productos ya que se van ingresando junto con el detalle de ventas.

Si se ingresan dos veces ventas para el mismo producto/mes se debe preguntar al usuario si desea reemplazar o no el dato anterior.

En base a los datos ingresados se debe mostrar por pantalla un cuadro resumen del importe recaudado en
cada mes de las ventas de cada producto según el siguiente esquema respetando los títulos.

            Mes
Producto 1 2 ... 12
xxxxx xxx.xx xxx.xx ... xxx.xx
xxxxx xxx.xx xxx.xx ... xxx.xx
*/
#include <stdio.h>

//FUNCIONES

int numeroEntero (float); //mayor a 0
int esDatoValido (int,int,int,int); //dato lim1 lim2 fin
int ingresarDatoValido (int,int,int); //lim1 lim2 fin
int carga (float [][12], int [],int,int); //matriz de codigos x mes, vector de codigos , cf ,cc
int buscar (int[],int,int);// vector codigo , dato buscado , hasta donde busco
void mostrar (float[][12],int[],int,int); //matriz , vector , cf, cc

int main()

{
    int vcodigo[30]={0},cant;
    float mat[30][12]={{0}};

    cant=carga(mat,vcodigo,30,12);

    if(cant>0)
        mostrar(mat,vcodigo,cant,12);
}

//funciones

int numeroEntero (float dato)
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
        return 0;

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
//----------------------------------------------------------------------------------------------------------------------------------------
int carga (float mat[][12], int vc[],int cf,int cc)
{
    int i=0,pos,codigo,mes,cantidad,cont=0, respuesta;
    float precio;

    printf("\nIngresar codigo del producto . (0 para finalizar):");
    codigo=ingresarDatoValido(10000,99999,0);

    while(codigo!=0)
    {
            printf("\nIngresar MES:");
            mes=ingresarDatoValido(1,12,1);

            pos=buscar(vc,codigo,cf); //busco el codigo

            if(pos==-1 && cont<30) //no lo encontro, por lo tanto es un nuevo codigo entonces lo guardo
                {
                    vc[i]=codigo;
                    cont++;
                }

            if(pos!=-1 && mat[pos][mes-1]!=0) //lo encontro, por lo tanto pregunto si quiero reemplazar los datos o no
                {
                            do{
                                printf("\nDesea remplazar los datos o acumular a los registrados? 1 para remplazar , 0 para acumular:");
                                scanf("%d" ,&respuesta);
                            }while(!(respuesta==1 || respuesta==0));
                }

            do{
                printf("\nIngresar cantidad vendida:");
                scanf("%d", &cantidad);
            }while((numeroEntero((float)cantidad))==0);

           do{
                printf("\nIngresar precio por unidad del producto:");
                scanf("%f", &precio);
           }while((numeroEntero(precio))==0);

            if(respuesta==1)
                mat[pos][mes-1]=(cantidad*precio);

            if(pos==-1 || respuesta==0)
                    mat[pos][mes-1]+=(cantidad*precio);

            i++;

            printf("\nIngresar codigo del producto.(0 para finalizar):");
            codigo=ingresarDatoValido(10000,99999,0);
    }

    return cont; //retorna la cantidad de codigos ingresados, y son los q va a mostrar.

}
//----------------------------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------------------------
void mostrar (float mat[][12],int vc[],int cf,int cc)
{
    int f,c;

    printf("\n\t\t\t\t\t                  MES\n");
    printf("\n\tPRODUCTOS\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12");
    printf("\n--------------------------------------------------");

    for(f=0;f<cf;f++)
    {
        printf("\n%d",vc[f]); //codigos

        for(c=0;c<cc;c++)
        {
            printf("\t%8f",mat[f][c]);
        }


            printf ("\n");
    }
     printf ("\n\n");
}
//----------------------------------------------------------------------------------------------------------------------------------------
