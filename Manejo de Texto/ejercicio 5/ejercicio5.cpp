/*Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados por su número
de patente, cargado en la memoria principal en un vector de 30 posiciones.

Al comenzar el procesamiento de los alquileres, se ingresa la fecha y la cotización del dólar de ese día.

A continuación, se ingresan los siguientes datos correspondiente a cada alquiler realizado en el día:
• Patente del auto (alfanumérico, de 6 caracteres)
• Cantidad de días de alquiler (entero, mayor que 0)
• Precio diario del alquiler en dólares (real, mayor que 0)

Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
Determinar e informar:

a. El porcentaje de autos alquilados durante el día.

b. Realizar el informe con el formato siguiente:

									ALQUILER DE AUTOS DEL DÍA: DD-MM-AAAA

										COTIZACION DEL DÓLAR: $ XX,XX

		NRO. DE AUTO 				DIAS DE ALQUILER 			PRECIO DEL ALQUILER		FECHA DE DEVOLUCION
																	EN PESOS					DEL AUTO

		XXXXX 								XX 						XXXX,XX 					XX/XX/XXXX
		XXXXX 								XX 						XXXX,XX 					XX/XX/XXXX


TOTAL RECAUDADO X ALQUILER (EN PESOS) : $ XXXXX,
TOTAL RECAUDADO X ALQUILER (EN DÓLARES): $ XXXXX,XX

*/

#include<stdio.h>
#include<string.h>

//funciones

int numeroEntero (int); //mayor a 0
int ingresarDatoValido(int ,int );
int esdatoValido (int ,int ,int );
void cargaAlquiler (char [][7], int [],float[]); //(patentes,vdiasAlq, vprecioAlq, vfechaAct)
void cargaPatentes (char[][7],int); // vstring de 30x7. CARGA TOTAL
int buscoPatente (char[][7],char[],int); //vstring de 30x7 , ce
void mostrar( char[][7],int[],float[],int);

int main()
{

	int cant, vdiasAlq[30];
	float vprecioAlq[30];
	char patentes [30][7];

    printf("\nCARGA DE PATENTES\n");
    cargaPatentes(patentes,30); // mando las filas.

    cargaAlquiler (patentes,vdiasAlq, vprecioAlq);

}

///FUNCIONES

int numeroEntero (int dato)
{
    if (dato>=0)
        return 1;
    else
        return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------------------------
void cargaAlquiler (char vpatentes[][7], int vdiasAlq[],float vpAlq[])
{
    int dolar, cantDias, i=0,ttalquilados=0,dia,mes,anio,pos;
    char patente[7];
    float precio,recaudado=0;

        printf("\n***PROCESAMIENTO DE LOS ALQUILERES***\n");

        printf("\n**FECHA**\n");

            printf("\nIngresar dia:");
            dia=ingresarDatoValido(1,31);

            printf("\nIngresar mes:");
            mes=ingresarDatoValido(1,12);

            printf("\nIngresar anio:");
            anio=ingresarDatoValido(1900,2023);

        printf("\nIngresar cotizacion del dolar al dia de la fecha:");
        do{
            scanf("%d", &dolar);
        }while(numeroEntero(dolar)==0);

        printf("\nIngresar patente del auto (alfanumérico, de 6 caracteres)--> Para FIN: 'FINDIA':");
        gets(patente);

        while(strcmpi(patente,"FINDIA")!=0)
        {
            do{
                pos=buscoPatente(vpatentes,patente,7); //busco q exista la patente
                if(pos==-1)
                {
                  printf("\nLa patente es incorrecta. Por favor, volver a ingresar:");
                    gets(patente);
                }
                }while(pos==-1);

                strcpy(vpatentes[i],patente); //asigno en el vector patentes en la posicion i la patente ingresada para alquilar.

                printf("\nIngresar cantidad de dias de alquiler:");
                do{
                    scanf("%d", &cantDias);
                }while(numeroEntero(cantDias)==0);

                vdiasAlq[i]=cantDias;

                printf("\nIngresar precio diario de alquiler EN DOLARES:");
                do{
                    scanf("%f", &precio);
                }while(precio<=0);

                vpAlq[i]=precio;

                recaudado+=(precio*cantDias);
                ttalquilados++;

                i++;

                printf("\nIngresar patente del auto (alfanumérico, de 6 caracteres)--> Para FIN: 'FINDIA':");
                gets(patente);
        }

        if(i>0)
        {
            printf("\n\t    ALQUILER DE AUTOS DEL DÍA: %d-%d-%d", dia,mes,anio);
            printf("\n\t    COTIZACION DEL DÓLAR: $ %d", dolar);
            mostrar( vpatentes,vdiasAlq,vpAlq,30);
            printf("\nTOTAL RECAUDADO X ALQUILER (EN DÓLARES): $ %-8f", recaudado);
            printf("\nTOTAL RECAUDADO X ALQUILER (EN PESOS) : $ %-8f", recaudado*dolar);
        }
}
//----------------------------------------------------------------------------------------------------------------------------------------
void cargaPatentes (char vp[][7],int ce)
{
    int i;

    for(i=0;i<ce;i++)
    {
        printf("\n-");
        gets(vp[i]);
    }

}
//----------------------------------------------------------------------------------------------------------------------------------------
int buscoPatente (char vp[][7],char buscado, int ce)
{
    int i=0, pos=-1;

    while(pos==-1 && i<ce)
    {
        if(strcmpi(vp[i],buscado)==0)
            pos=i;
        else
            i++;
    }

    return pos;
}

//-----------------------------------------------------------------------------------------------------------------------------------------
void mostrar( char vp[][7],int vd[],float vpr[],int ce)
{
    int i;

        printf("\n\tNRO. DE AUTO 				DIAS DE ALQUILER 			PRECIO DEL ALQUILER		FECHA DE DEVOLUCION");
        printf("\n\t															EN PESOS				   DEL AUTO");

    for(i=0;i<ce;i++)
    {
        printf("\n\t%s                                %d                           $ %-8f                                 ", vp[i],vd[i],vpr[i]);
    }
}






//codigo para integrar fecha de devolucion

/*
                cantDiasMes=cantMaxDiasMes(mesAct,anioAct);

                if(diaAct==cantDiasMes) //ultima dia
                {
                    if(mesAct==12)
                    {
                        diaD=(diaAct*0)+cantDias;
                        mesD=1;
                        anioAct++;
                        anioD=anioAct;
                    }
                    else
                    {
                       diaD=(diaAct*0)+cantDias;
                       mesAct++;
                       mesD=mesAct;
                    }
                }
                else //si no es igual a fin de mes
                {
                    restaDias=(cantDiasMes-diaAct);
                    totalDias= (cantDias-restaDias);
                    diaAct=0;
                    diaD=totalDias;
                }

*/
