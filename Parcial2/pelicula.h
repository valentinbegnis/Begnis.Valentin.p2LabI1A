#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id_peli;
    char titulo[30];
    char genero[12];
    int duracion;
}eMovie;

#endif // PELICULA_H_INCLUDED

/** \brief Inicializa una nueva pelicula
 * \return eMovie* Dirección de memoria de la pelicula en cuestion
 */
eMovie* eMovie_new();

/** \brief Asigna valores hardcodeados a una pelicula
 * \param idStr char* Cadena de caracteres del ID
 * \param tituloStr char* Cadena de caracteres del titulo
 * \param generoStr char* Cadena de caracteres del genero
 * \param duracionStr char* Cadena de caracteres de la duracion
 * \return eMovie* Dirección de memoria de la pelicula en cuestion
 */
eMovie* eMovie_newParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr);

/** \brief Hace un free a la pelicula pasada por parametro
 * \param this eMovie* Puntero a estructura eMovie
 * \return void
 */
void eMovie_delete(eMovie* this);

/** \brief Setea un ID a una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \param id int ID a setear
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_setId(eMovie* this, int id);

/** \brief Obtiene el ID de una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \param id int* Puntero a entero del ID
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_getId(eMovie* this, int* id);

 /** \brief Setea un titulo a una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \param titulo char*
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_setTitulo(eMovie* this, char* titulo);

 /** \brief Obtiene el titulo de una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \param nombre char* Puntero a char del titulo
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_getTitulo(eMovie* this, char* titulo);

/** \brief Setea un genero a una pelicula
 * \param thi eMovie* Puntero a estructura eMovie
 * \param genero char*
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_setGenero(eMovie* this, char* genero);

/** \brief Obtiene el genero de una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \param genero char* Puntero a char del genero
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_getGenero(eMovie* this, char* genero);

/** \brief Muestra una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \return void
 */


/** \brief Setea la duracion a una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \param duracion int duracion a setear
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_setDuracion(eMovie* this, int duracion);

/** \brief Obtiene la duracion de una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \param duracion int* Puntero a entero de la duracion
 * \return int 1 si fallo, 0 si no fallo
 */
int eMovie_getDuracion(eMovie* this, int* duracion);

/** \brief Muestra una pelicula
 * \param this eMovie* Puntero a estructura eMovie
 * \return void
 */
void eMovie_mostrarUna(eMovie* this);
void* eMovie_asignarTiempos(void* element);

int eMovie_filtrarAventura(void* element);
int eMovie_filtrarDrama(void* element);
int eMovie_filtrarComedy(void* element);
int eMovie_filtrarRomance(void* element);
int eMovie_filtrarDocumentary(void* element);
int eMovie_filtrarHorror(void* element);
int eMovie_filtrarMusical(void* element);
int eMovie_filtrarAnimation(void* element);
int eMovie_filtrarAction(void* element);
int eMovie_filtrarThriller(void* element);
int eMovie_filtrarWestern(void* element);

int eMovie_sortGenero(void* elementUno, void* elementDos);
int eMovie_sortDuracion(void* elementUno, void* elementDos);




