#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include <string.h>

int main()
{
    char seg='s';
    char nom[50];
    int opc=0;

    EMovie movie;

    while(seg=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("9- Salir\n");

        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            agrMov(movie);
            break;
        case 2:
            delMov(movie);
            break;
        case 3:
            modMov(movie);
            break;
        case 4:
            printf("Ingrese nombre de la pagina: ");
            fflush(stdin);
            gets(nom);
            genPag(movie,nom);
            break;
        case 9:
            seg='n';
            break;
        default:
            printf("Opcion invalida");
            break;
        }
    }
    return 0;
}
