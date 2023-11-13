/**7.1.11 Para una carrera de automóviles, se toman los tiempos de clasificación (real, mayor que 0 en segundos y
centésimos de segundo) de como máximo 60 autos de carrera inscriptos para la competencia.
Los autos se identifican con números correlativos del 1 al 60, quedando sin información aquellos que no
participan de la presente carrera.
Cuando ya no hay más tiempos de clasificación para cargar, se ingresa un auto con número negativo.
Se solicita determinar:
a. El número de auto que clasificó en primer lugar.
b. El número de auto que obtuvo el peor tiempo de clasificación.
c. La cantidad de autos que superaron el promedio de tiempo de clasificación.
d. El o los números de autos que no participan de la carrera actual. ---------> NO SE COMO HACERLO
*/

#include <stdio.h>


//Prototipo de funciones
int esDatoVali2 (float,int,int);
float ingresarDatoVal2 (int,int);
int cargaDatos (float[],float[],float[],int); //nro auto , seg , cent
void buscarMenorTiem (float[],float[],float[],int);
void buscarMayorTiem (float[],float[],float[],int);
void buscarPromAutos (float[],float[],float[],int);
void mostrarVectores (float[],float[],float[],int);

//----------------------------------------------------------------------------------------------------------------------

int main ()
{

    float vNumAutos[10]={0},cant;
    float vSegundos[10]={0}, vCent[10]={0};

    cant=cargaDatos(vNumAutos,vSegundos,vCent,10);

    if (cant>0)
    {
        buscarMenorTiem (vNumAutos,vSegundos,vCent,cant);
        buscarMayorTiem (vNumAutos,vSegundos,vCent,cant);
        mostrarVectores (vNumAutos,vSegundos,vCent,cant);
    }

}

//FUNCIONES

int esDatoVali2 (float x,int lim1,int lim2)
{
    if(x>=lim1 && x<=lim2 || x<0)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------
float ingresarDatoVal2 (int lim1,int lim2)
{
    int dato;

    do{
        scanf("%f", &dato);

    }while((esDatoVali2(dato,lim1,lim2))==0);

    return dato;
}
//---------------------------------------------------------------------------------------------------------
int cargaDatos (float vna[],float vseg[],float vcent[],int ce) //nro auto , seg , cent
{
    int i=0;
    float numA,seg,cent;

    printf("\nIngresar numero de auto (negativo para finalizar):"); /*me toma solo num negativos???????*/
    numA=ingresarDatoVal2 (1,60);

    while (i<ce && numA>=1)
    {
        vna[i]=numA;

        printf("\nIngresar tiempo de clasificacion. \nSegundos: \n Centesimos:");

        seg=ingresarDatoVal2 (0,60);
        vseg[i]=seg;
        cent=ingresarDatoVal2 (0,60);
        vcent[i]=cent;

        i++;

    printf("\nIngresar numero de auto (negativo para finalizar):");
    numA=ingresarDatoVal2 (1,60);

    }

    return i;

}
//---------------------------------------------------------------------------------------------------------
void buscarMenorTiem (float vna[],float vseg[],float vcent[],int ce)

{
    int i=0;
    float minSeg,minCent,na;

    for(i=0;i<ce;i++)
    {
        if(i==0)
        {
            minSeg=vseg[i];
            minCent=vcent[i];
            na=vna[i];
        }

        else
            if(vseg[i]<minSeg && vcent[i]<minCent)
        {
            minSeg=vseg[i];
            minCent=vcent[i];
            na=vna[i];
        }
    }

    printf ("\nEl número de auto que clasificó en primer lugar es : %6.f",na);



}
//---------------------------------------------------------------------------------------------------------
void buscarMayorTiem (float vna[],float vseg[],float vcent[],int ce)
{
   int i=0;
   float maySeg,mayCent,na;

    for(i=0;i<ce;i++)
    {
        if(i==0)
        {
            maySeg=vseg[i];
            mayCent=vcent[i];
            na=vna[i];
        }

        else
            if(vseg[i]>maySeg && vcent[i]>mayCent)
        {
            maySeg=vseg[i];
            mayCent=vcent[i];
            na=vna[i];
        }
    }

    printf ("\nEl numero de auto que obtuvo el peor tiempo de clasificacion es : %6.f",na);


}
//---------------------------------------------------------------------------------------------------------
void buscarPromAutos (float vna[],float vseg[],float vcent[],int ce)
{
    int i,j,cont=0;
    float promSeg, promCent,sum=0,sumCent=0;

    for(i=0;i<ce;i++)
    {
        sum+=vseg[i];
        sumCent+=vcent[i];
    }

    promSeg=sum/ce;
    promCent=sumCent/ce;

    for(j=0;j<ce;j++)
    {
        if(vseg[i]>promSeg && vcent[i]>promCent)
            cont++;
    }

    printf("\nLa cantidad de autos que superaron el promedio de tiempo de clasificacion: %d", cont);
}

//-------------------------------------------------------------------------------------------------------- NO SE COMO HACERLO
/*void buscarIgualA (float vna[],float vseg[],float vcent[],int ce)

{
    int i;
    printf ("\nEl o los números de autos que no participan de la carrera actual:")
    for (i=0;i<ce;i++)
    {
        if(vna[i]==0)
            printf("\n*%f", vna[i]);
    }


}*/
//---------------------------------------------------------------------------------------------------------
void mostrarVectores (float vna[],float vseg[],float vcent[],int ce)

{
    int i;
    printf ("\nNUM AUTO \t SEGUNDOS \t CENTESIMOS");

    for(i=0;i<ce;i++)
    {
        printf ("\n%f \t %f \t %f", vna[i], vseg[i],vcent[i]);
    }
}

//---------------------------------------------------------------------------------------------------------

