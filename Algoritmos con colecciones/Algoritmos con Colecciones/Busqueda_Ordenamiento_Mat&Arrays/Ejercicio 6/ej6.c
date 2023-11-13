/**El gobierno de la nación desea controlar el volumen de facturación de la matriz energética nacional, que
está compuesto por las empresas que brindan servicios de Luz, Agua y Gas. Existen a lo sumo 10 empresas y
por cada una se debe ingresar:
• Código de la empresa (número entero entre 1000 y 5000)
• Tipo de servicio (caracter L, A o G (correspondiente a Luz, Agua y Gas respectivamente))
La carga finaliza con un código de empresa igual a 0.
Luego se ingresa el detalle de la facturación con los siguientes datos:
• Código de empresa
• Mes
• Importe facturado
No todas empresas facturaron todos los meses y puede existir más de una factura por empresa/mes.
La carga de facturación finaliza con un mes igual a -1.

1.Mostrar la matriz energética con el siguiente formato respetando los títulos
Empresa\Mes    1 2 3 ...................12
xxxx           xxx.xx xxx.xx xxx.xx ... xxx
xxxx           xxx.xx xxx.xx xxx.xx ... xxx
xxxx           xxx.xx xxx.xx xxx.xx xxx.xxx


2. Indicar el/los trimestres de mayor facturación, indicando el número de trimestre y el monto

3. Mostrar en forma ordenada de mayor a menor el importe total facturado por tipo de servicio. Mostrando un
listado con Tipo de empresa y total facturado.

4. Mostrar el código y tipo de servicio de aquellas empresas que no hayan facturado en 2 o más meses

*/

#include <stdio.h>

//prototipo funciones
int validarChar (char);
int numeroEntero (int);
int esDatoValido (int,int,int,int); //dato lim1 lim2 cond.fin
int ingresarDatoValido (int,int,int);
int cargaEmpresas (int[],char[],int);
int cargaFacturacion (int [10][],int[],int[],int[],int,int); //matriz , vec trim , cf,cc
int buscar (int[],int,int);
void ordenar (char[],int[],int);
void mostrarVecs (int[],int[],int);
void mostrarMatriz (int[10][],int,int); //matriz , cf,cc

int main ()

{
    int vcod[10],cant, vtrimestre[4]={0}, mat[10][12]={{0}}, vtotalf[3]={0},ce;
    char vserv[10],vtiposerv[3];

    ce=cargaEmpresas (vcod,vserv,10);
    cant=cargaFacturacion (mat,vcod,vtiposerv,vtrimestre,ce,12);

    if (cant>0)
    {
        mostrarMatriz (mat,ce,12);
        ordenar (vtiposerv,vtotalf,3);
        mostrarVecs(vtiposerv,vtotalf,3);
    }
}

//funciones

int validarChar (char x)
{
    if(x=='L' || x=='A' || x=='G')
        return 1;
    else
    {
        printf("\nDato invalido, volver a ingresar:");
         return 0;
    }

}

//--------------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------------
int cargaEmpresas (int vc[],char vs[],int ce)
{
    int i,codigo;
    char servicio;

    printf ("\nIngresar codigo de empresa (para fin ingresar 0):");
    codigo=ingresarDatoValido (1000,5000,0);

    while (codigo!=0)
    {
        do{
            pos=buscar(vc,codigo,ce);
            if(pos!=-1)
                printf("\nCodigo repetido. Volver a ingresar:");
                codigo=ingresarDatoValido (1000,5000,0);
            }while(pos!=-1);

         vc[i]=codigo;

         do{
             printf("\nIngresar tipo de servicio:");
              scanf("%c" ,&servicio);
         }while((validarChar(servicio))==0);

         vs[i]=servicio;

        printf ("\nIngresar codigo de empresa (para fin ingresar 0):");
        codigo=ingresarDatoValido (1000,5000,0);

    }
}
//--------------------------------------------------------------------------------------------------------------
int cargaFacturacion (int mat[10][], int vc[],int vts[],int vtm[],int cf,int cc)
{
    int mes,pos,codigo;
    float importe;

    printf("\nIngresar mes:");
    mes=ingresarDatoValido(1,12,-1);

    while (mes!=-1)
    {

        printf("\nIngresar codigo de empresa:");
        do{
            codigo=ingresarDatoValido(1000,5000,1000);
            pos=buscar(vc,codigo,cf);
            if(pos==-1)
                printf("\nCodigo incorrecto. Volver a ingresar:");
        }while(pos==-1);

        do{
            printf("\nIngresar importe facturado:");
            scanf("%f", &importe);
        }while((numeroEntero(importe))==0);

        mat[pos][mes-1]+=importe;

        switch (mes)
        {
            case 1:
            case 2:
            case 3:
                vtm[0]+=importe;
                break;
            case 4:
            case 5:
            case 6:
                vtm[1]+=importe;
                break;
            case 7:
            case 8:
            case 9:
                vtm[2]+=importe;
                break;
            case 10:
            case 11:
            case 12:
                vtm[3]+=importe;
                break;
        }


    }


}
//--------------------------------------------------------------------------------------------------------------
int buscar (int v[],int datoBuscado,int ce)
{
    int i,pos=-1;

    for (i=0;i<ce;i++)
    {
        if(v[i]==datoBuscado)
            pos=i;
    }

    return pos;

}
//--------------------------------------------------------------------------------------------------------------
void ordenar (char vs[],int vt [],int  ce) //vs ,  , ce
{
    int i,aux,posmax,j;

    for(i=0;i<ce-1;i++)
    {
        posmax=i; //se le asigna 0 a la variable posmax;

        for(j=i+1;j>ce;j++)
        {
            if(vt[j]<vt[posmax])
                posmax=j;
        }

        if(posmax!=i)
        {
            aux=vt[i];
            vt[i]=vt[posmax];
            vt[posmax]=aux;

            aux=vs[i];
            vs[i]=vs[posmax];
            vs[posmax]=aux;
        }
    }
}
//--------------------------------------------------------------------------------------------------------------
void mostrarVecs (int[],int[],int)
//--------------------------------------------------------------------------------------------------------------
void mostrarMatriz (int[10][],int,int)
//--------------------------------------------------------------------------------------------------------------
