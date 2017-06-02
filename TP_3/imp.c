#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include <string.h>

void agrMov(EMovie M)
{
    char tit[20], gen[20], des[50], linkI[50];
    int dur, pun;

    FILE* arc;
    arc=fopen("cartelera.dat","rb+");
    if(arc==NULL)
    {
        fclose(arc);
        arc=fopen("cartelera.dat","wb");
    }

    printf("Ingrese titulo: ");
    fflush(stdin);
    gets(tit);
    strcpy(M.titulo,tit);

    printf("Ingrese genero: ");
    fflush(stdin);
    gets(gen);
    strcpy(M.genero,gen);

    printf("Ingrese duracion: ");
    scanf("%d",&dur);
    while(dur<=0)
    {
        printf("Duracion muy corta. Ingrese un numero mayor a 0: ");
        scanf("%d",&dur);
    }
    M.duracion=dur;

    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(des);
    strcpy(M.descripcion,des);

    printf("Ingrese puntaje: ");
    scanf("%d",&pun);
    M.puntaje=pun;

    printf("Ingrese link de la imagen: ");
    fflush(stdin);
    gets(linkI);
    strcpy(M.linkImagen,linkI);

    fseek(arc,0L,SEEK_END);
    fwrite(&M,sizeof(EMovie),1,arc);

    fclose(arc);

    printf("Pelicula agregada exitosamente\n");
}

void delMov(EMovie M)
{
    int F;
    char tit[20];
    FILE* arc;

    arc=fopen("cartelera.dat","rb+");

    printf("Ingrese nombre de pelicula a borrar: ");
    fflush(stdin);
    gets(tit);

    if(arc==NULL)
    {
        printf("El archivo no existe");
        exit(1);
    }

    while(!feof(arc))
    {
        F=fread(&M,sizeof(EMovie),1,arc);
        if(F==1&&(stricmp(tit,M.titulo)==0))
        {
            M.duracion=0;
        }
    }

    fseek(arc,0L,SEEK_SET);
    fwrite(&M,sizeof(EMovie),1,arc);

    fclose(arc);
}

void modMov(EMovie M)
{
    int F, C=1, O=0, dur, pun;
    char tit[20], gen[20], des[50], linkI[50];
    FILE* arc;

    arc=fopen("cartelera.dat","rb+");

    printf("Ingrese nombre de pelicula a modificar: ");
    fflush(stdin);
    gets(tit);

    if(arc==NULL)
    {
        printf("El archivo no existe");
    }

    while(!feof(arc))
    {
        F=fread(&M,sizeof(EMovie),1,arc);
        if(F==1&&(stricmp(tit,M.titulo)==0)&&M.duracion!=0)
        {
            while(C==1)
            {
                printf("1- Modificar titulo\n");
                printf("2- Modificar genero\n");
                printf("3- Modificar duracion\n");
                printf("4- Modificar descripcion\n");
                printf("5- Modificar puntaje\n");
                printf("6- Modificar imagen\n");
                printf("9- Salir\n");

                scanf("%d",&O);
                switch(O)
                {
                case 1:
                    printf("Ingrese titulo: ");
                    fflush(stdin);
                    gets(tit);
                    strcpy(M.titulo,tit);
                    break;
                case 2:
                    printf("Ingrese genero: ");
                    fflush(stdin);
                    gets(gen);
                    strcpy(M.genero,gen);
                    break;
                case 3:
                    printf("Ingrese duracion: ");
                    scanf("%d",&dur);
                    while(dur<=0)
                    {
                        printf("Duracion muy corta. Ingrese un numero mayor a 0: ");
                        scanf("%d",&dur);
                    }
                    M.duracion=dur;
                    break;
                case 4:
                    printf("Ingrese descripcion: ");
                    fflush(stdin);
                    gets(des);
                    strcpy(M.descripcion,des);
                    break;
                case 5:
                    printf("Ingrese puntaje: ");
                    scanf("%d",&pun);
                    M.puntaje=pun;
                    break;
                case 6:
                    printf("Ingrese link de la imagen: ");
                    fflush(stdin);
                    gets(linkI);
                    strcpy(M.linkImagen,linkI);
                    break;
                case 9:
                    C=0;
                    break;
                default:
                    printf("opcion no valida");
                    break;
                }
            }
            break;
        }
        else
        {
            printf("Pelicula no encontrada");
        }
    }

    fseek(arc,0L,SEEK_SET);
    fwrite(&M,sizeof(EMovie),1,arc);

    fclose(arc);
}

void genPag(EMovie M, char nombre[])
{
    FILE* html;
    FILE* arc;
    char buffer[1080]={};
    char cas[3]={};
    int F;
    strcat(nombre,".html");

    arc=fopen("cartelera.dat","rb");
    html=fopen(nombre,"a");

    strcpy(buffer, "<h1>Lista De Peliculas:</h1>");
    fwrite(&buffer,sizeof(buffer),1,html);

    while(!feof(arc))
    {
        F=fread(&M,sizeof(EMovie),1,arc);
        if(F==1&&M.duracion!=0)
        {
            strcpy(buffer,"<article class='col-md-4 article-intro'>");
            strcat(buffer,"<a href='#'>");
            strcat(buffer,"<img class='img-responsive img-rounded' src='");
            strcat(buffer,M.linkImagen);
            strcat(buffer,"alt=''>");
            strcat(buffer,"</a><h3>");
            strcat(buffer,"<a href='#'>");
            strcat(buffer,M.titulo);
            strcat(buffer,"</a></h3><ul><li>Género:");
            strcat(buffer,M.genero);
            strcat(buffer,"</li><li>Puntaje:");
            sprintf(cas, "%d", M.puntaje);
            strcat(buffer, cas);
            strcat(buffer,"</li><li>Duración:");
            sprintf(cas, "%d", M.duracion);
            strcat(buffer,cas);
            strcat(buffer,"</li></ul><p>");
            strcat(buffer,M.descripcion);
            strcat(buffer,"</p></article>");
            fwrite(&buffer,sizeof(buffer),1,html);
        }
    }

    fclose(arc);
	fclose(html);
}
