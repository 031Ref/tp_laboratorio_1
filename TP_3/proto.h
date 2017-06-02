#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
} EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param la estructura a ser agregada al archivo
 */
void agrMov(EMovie);

/**
 *  Borra una pelicula del archivo binario
 *  @param la estructura a ser eliminada al archivo
 */
void delMov(EMovie);

/**
 *  Modifica una pelicula del archivo binario
 * \param la estructura a modificar
 */
void modMov(EMovie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param la estructura de las peliculas
 *  @param el nombre para el archivo.
 */
void genPag(EMovie, char[]);

#endif // FUNCIONES_H_INCLUDED
