
/*
SECUENCIAL.

2.13. Confeccionar un programa que solicite el ingreso de un n�mero entero positivo de 4 cifras y pueda calcular
e informar la suma de sus d�gitos hasta llegar a una sola cifra. Ej:2561 ---> 5.

*/

#include <stdio.h>

int main ()

{

    int num,c1,c2,c3,c4,aux,aux2,ct,cf;

    printf("\nIngresar un numero entero positivo de 4 cifras:"); //ej: 5425
    scanf("%d",&num);                                           //se guarda en la variable num

    c1=num/1000;            // c1= 5425/1000=5 
    aux=num%1000;           // aux=5425%1000 ---> 425
    c2=aux/100;             // c2= 425/100=4
    aux2=aux%100;           //aux2= 425%100 --> 25
    c3= aux2/10;            // c3= 25/10 = 2
    c4=aux2%10;             // c4= 25%10 --> 5

    ct= c1+c2+c3+c4;            //cifra total:  16
    cf= (ct/10) + (ct%10);      //cifra final: 16/10 = 1 + 16%10= 6 --> 1+6=7

    printf("\n\nLa suma de los digitos del numero ingresado da como resultado la siguiente cifra: %d \n\n", cf);



}
