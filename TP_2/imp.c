#include "proto.h"
#include <conio.h>
#include <string.h>
#include <stdio.h>

void iniPer(EPersona subToIni[], int w)
{
    int i;
    for(i=0; i<w; i++)
    {
        subToIni[i].estado=0;
    }
}

int buscarLibre(EPersona subToFin[], int x)
{
    int lugar = -1;
    int i;
    for(i=0; i<x; i++)
    {
        if(subToFin[i].estado==0)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}

void mostrarPersona(EPersona subToSho)
{
    printf("\n%d\t%s\t%d\n",subToSho.dni, subToSho.nombre, subToSho.edad);
}

EPersona crearPersona(int dniA, char nombre[], int eda)
{
    EPersona curSub;
    curSub.dni = dniA;
    strcpy(curSub.nombre,nombre);
    curSub.edad = eda;
    curSub.estado = 1;
    return curSub;
}

void ordPer(EPersona subToOrd[], int y)
{
    int i;
    int j;
    EPersona auxPer;
    for(i=0; i<y-1; i++)
    {
        for(j=i+1; j<y; j++)
        {
            if(strcmp(subToOrd[i].nombre,subToOrd[j].nombre)>0)
            {
                auxPer = subToOrd[i];
                subToOrd[i] = subToOrd[j];
                subToOrd[j] = auxPer;
            }
        }
    }
}

void mostrarLista(EPersona subToSho[], int z)
{
    int i;
    for(i=0; i<z; i++)
    {
        if(subToSho[i].estado!=0)
        {
            mostrarPersona(subToSho[i]);
        }
    }
}

void graEda(int a,int b,int c)
{
    int val[]={a,b,c};
    int i;
    int j;
    int max;
    max=0;
    for(i=0;i<3;i++)
    {
        if(val[i]>max)
        {
            max=val[i];
        }
    }
    for(i=max;i>0;i--)
    {
        for(j=0;j<3;j++)
        {
            if(val[j]>=i)
            {
                printf(" *\t");
            }
            else
            {
                printf("  \t");
            }
        }
        putchar('\n');
    }
}
