#include<stdio.h>

int ingresarDatoValido(int ,int );
int esdatoValido (int ,int ,int );
int esBisiesto (int); //anio
int cantMaxDiasMes (int, int);
int esFechaValida (int,int,int); //dia, mes , anio


int main()
{
	int dia, mes, anio,valido;
	int cantDiasMes;

		printf("\nIngresar dia:");
		dia=ingresarDatoValido(1,31);

		printf("\nIngresar mes:");
		mes=ingresarDatoValido(1,12);

		printf("\nIngresar anio:");
		anio=ingresarDatoValido(1900,2023);

		cantDiasMes=cantMaxDiasMes(mes,anio);

		if(dia==cantDiasMes) // es decir que estoy en el ultimo dia del mes.
		{
			if(mes==12)
			{
				dia=1;
				mes=1;
				anio++;
			}
			else
			{
				dia=1;
				mes++;
			}
		}
		else //es decir que que no es el ultimo mes
			dia++;

			printf("\nLa fecha del siguiente dia es: %d/ %d/ %d", dia,mes,anio);


}

//funciones

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
int esBisiesto (int a)
{
	if(a%4==0 && a%100!=0 || a%400==0)
		return 1;
	else
		return 0;
}
//-----------------------------------------------------------------------------------
int cantMaxDiasMes (int m, int a)
{
	if(m==1 || m==3 || m==5|| m==7|| m==8 || m==10|| m==12)
		return 31;
	if(m==4 || m==6 || m==9|| m==11)
		return 30;
	if (m==2)
	{
		if(esBisiesto(a)==1)
			return 29;
		else
			return 28;
	}
}
//---------------------------------------------------------------------------------

