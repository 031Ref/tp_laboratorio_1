#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

int main()
{
    float num1,num2,rta;
    int fir=1;
    char seguir='s';
    int opcion=0;


    while(seguir=='s'&&fir==1)
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese numero.\n");
            scanf("%f",&num1);
            printf("Numero ingresado.\n");
            fir=2;
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }
    while(seguir=='s'&&fir==2)
    {
        printf("1- Ingresar 1er operando (A=%f)\n",num1);
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese numero.\n");
            scanf("%f",&num1);
            printf("Numero ingresado.\n");
            break;
        case 2:
            printf("Ingrese numero.\n");
            scanf("%f",&num2);
            printf("Numero ingresado.\n");
            fir=0;
            break;
        case 7:
            rta=mFac(num1);
            printf("El factorial de A es %f\n",rta);
            break;
        case 9:
            seguir = 'n';
            break;
        }

    }
    while(seguir=='s'&&fir==0)
    {
        printf("1- Ingresar 1er operando (A=%f)\n",num1);
        printf("2- Ingresar 2do operando (B=%f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese numero.\n");
            scanf("%f",&num1);
            printf("Numero ingresado.\n");
            break;
        case 2:
            printf("Ingrese numero.\n");
            scanf("%f",&num2);
            printf("Numero ingresado.\n");
            break;
        case 3:
            rta=mSum(num1,num2);
            printf("La suma es %f\n",rta);
            break;
        case 4:
            rta=mRes(num1,num2);
            printf("La resta es %f\n",rta);
            break;
        case 5:
            if(num2==0){
                printf("accion no valida\n");
            }else{
            rta=mDiv(num1,num2);
            printf("La division es %f\n",rta);
            }
            break;
        case 6:
            rta=mMul(num1,num2);
            printf("La multiplicacion es %f\n",rta);
            break;
        case 7:
            if(num1<0){
                printf("accion no valida\n");
            }else{
            rta=mFac(num1);
            printf("El factorial de A es %f\n",rta);
            }
            break;
        case 8:
            rta=mSum(num1,num2);
            printf("La suma es %f\n",rta);
            rta=mRes(num1,num2);
            printf("La resta es %f\n",rta);
            rta=mDiv(num1,num2);
            if(num2==0){
                printf("accion no valida\n");
            }else{
            printf("La division es %f\n",rta);
            }
            rta=mMul(num1,num2);
            printf("La multiplicacion es %f\n",rta);
            if(num1<0){
                printf("accion no valida\n");
            }else{
            rta=mFac(num1);
            printf("El factorial de A es %f\n",rta);
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }


    return 0;
}
