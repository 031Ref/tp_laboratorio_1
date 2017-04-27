#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "proto.h"

int main()
{
    EPersona lista[20];
    iniPer(lista, 20);
    char seguir='s';
    int opcion=0;
    int banCap;
    int posicion;
    int dniA;
    char nombre[50];
    int age;
    int toDel;
    int i;
    char ans;
    int con0018=0;
    int con1935=0;
    int con35up=0;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            banCap=0;
            posicion = buscarLibre(lista, 20);
            if(posicion!=-1)
            {
                printf("Ingrese DNI: ");
                scanf("%d", &dniA);
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombre);
                printf("Ingrese edad: ");
                scanf("%d", &age);
                if(age>=0&&age<=18)
                {
                    con0018++;
                }
                else if(age>=19&&age<=35)
                {
                    con1935++;
                }
                else if(age>=36)
                {
                    con35up++;
                }
                lista[posicion] = crearPersona(dniA, nombre,age);
                mostrarPersona( lista[posicion]);
            }
            else
            {
                printf("No hay mas espacio");
            }
            break;
        case 2:
            banCap=0;
            printf("Ingrese el DNI de la persona que desea eliminar: ");
            scanf("%d", &toDel);
            for(i=0; i<20; i++)
            {
                if(lista[i].estado==1 &&toDel == lista[i].dni)//encontro la persona
                {
                    mostrarPersona(lista[i]);
                    printf("Esta seguro de eliminar? ");
                    ans = getche();
                    if(ans=='s')
                    {
                        lista[i].estado=0;
                        if(lista[i].edad>=0&&lista[i].edad<=18)
                        {
                            con0018--;
                        }
                        else if(lista[i].edad>=19&&lista[i].edad<=35)
                        {
                            con1935--;
                        }
                        else if(lista[i].edad>=36)
                        {
                            con35up--;
                        }
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario");
                    }
                    banCap=1;
                    break;
                }
            }
            if(banCap==0)
            {
                printf("La persona es inexistente!");
            }
            break;
        case 3:
            ordPer(lista,20);
            mostrarLista(lista, 20);
            break;
        case 4:
            graEda(con0018,con1935,con35up);
            printf("\n<18\t19-35\t>35\n");
            break;
        case 5:
            seguir='n';
            break;
        }
    }
    return 0;
}
