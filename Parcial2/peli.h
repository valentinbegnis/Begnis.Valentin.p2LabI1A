#ifndef PELI_H_INCLUDED
#define PELI_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id_peli;
    char titulo[50];
    char genero[50];
    int duracion;
}ePelicula;

#endif // PELI_H_INCLUDED

/** \brief Inicializa un nuevo empleado
 * \return ePelicula* Dirección de memoria del empleado en cuestion
 */
ePelicula* ePelicula_new();

/** \brief Asigna valores hardcodeados a un empleado
 * \param idStr char* Cadena de caracteres del ID
 * \param nombreStr char* Cadena de caracteres del nombre
 * \param horasTrabajadasStr char* Cadena de caracteres de las horas trabajadas
 * \param sueldoStr char* Cadena de caracteres del sueldo
 * \return ePelicula* Dirección de memoria del empleado en cuestion
 */
ePelicula* ePelicula_newParametros(char* idStr,char* nombreStr, char* vacunaUnoStr, char* vacunaDosStr, char* sinVacunarStr);

/** \brief Hace un free al empleado pasado por parametro
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \return void
 */
void ePelicula_delete(ePelicula* this);

/** \brief Setea un ID a un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param id int ID a setear
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_setId(ePelicula* this, int id);

/** \brief Obtiene el ID de un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param id int* Puntero a entero del ID
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_getId(ePelicula* this, int* id);

/** \brief Setea un nombre a un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param nombre char*
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_setNombre(ePelicula* this, char* nombre);

/** \brief Obtiene el nombre de un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param nombre char* Puntero a char del nombre
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_getNombre(ePelicula* this, char* nombre);

/** \brief Setea las horas trabajadas a un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param horasTrabajadas int
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_setVacunaUno(ePelicula* this, int vacunaUno);

/** \brief Obtiene las horas trabajadas de un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param id int* Puntero a entero de las horas trabajadas
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_getVacunaUno(ePelicula* this, int* vacunaUno);

/** \brief Setea un sueldo a un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param sueldo int
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_setVacunaDos(ePelicula* this, int vacunaDos);

/** \brief Obtiene las horas trabajadas de un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \param id int* Puntero a entero de las horas trabajadas
 * \return int 1 si fallo, 0 si no fallo
 */
int ePelicula_getVacunaDos(ePelicula* this, int* vacunaDos);

/** \brief Muestra un empleado
 * \param thisePelicula ePelicula* Puntero a estructura ePelicula
 * \return void
 */

int ePelicula_setSinVacunar(ePelicula* this, int sinVacunar);
int ePelicula_getSinVacunar(ePelicula* this, int* sinVacunar);

void ePelicula_mostrarUno(ePelicula* this);

/** \brief Compara los ID
 * \param ePeliculaUno void* Puntero a void del empleado uno
 * \param ePeliculaDos void* Puntero a void del empleado dos
 * \return int -1 si el orden es descendente, 1 si es ascendente, 0 si hubo un error
 */
int ePelicula_sortId(void* ePeliculaUno, void* ePeliculaDos);

void* ePelicula_asignarEstadisticas(void* element);
int ePelicula_exitosos(void* element);
int ePelicula_horno(void* element);
int ePelicula_sortNivel(void* elementUno, void* elementDos);

