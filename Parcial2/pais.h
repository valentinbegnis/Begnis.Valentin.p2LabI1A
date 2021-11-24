#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[50];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;

#endif // PAIS_H_INCLUDED

/** \brief Inicializa un nuevo empleado
 * \return ePais* Dirección de memoria del empleado en cuestion
 */
ePais* ePais_new();

/** \brief Asigna valores hardcodeados a un empleado
 * \param idStr char* Cadena de caracteres del ID
 * \param nombreStr char* Cadena de caracteres del nombre
 * \param horasTrabajadasStr char* Cadena de caracteres de las horas trabajadas
 * \param sueldoStr char* Cadena de caracteres del sueldo
 * \return ePais* Dirección de memoria del empleado en cuestion
 */
ePais* ePais_newParametros(char* idStr,char* nombreStr, char* vacunaUnoStr, char* vacunaDosStr, char* sinVacunarStr);

/** \brief Hace un free al empleado pasado por parametro
 * \param thisePais ePais* Puntero a estructura ePais
 * \return void
 */
void ePais_delete(ePais* thisePais);

/** \brief Setea un ID a un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param id int ID a setear
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_setId(ePais* this, int id);

/** \brief Obtiene el ID de un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param id int* Puntero a entero del ID
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_getId(ePais* this, int* id);

/** \brief Setea un nombre a un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param nombre char*
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_setNombre(ePais* this, char* nombre);

/** \brief Obtiene el nombre de un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param nombre char* Puntero a char del nombre
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_getNombre(ePais* this, char* nombre);

/** \brief Setea las horas trabajadas a un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param horasTrabajadas int
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_setVacunaUno(ePais* this, int vacunaUno);

/** \brief Obtiene las horas trabajadas de un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param id int* Puntero a entero de las horas trabajadas
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_getVacunaUno(ePais* this, int* vacunaUno);

/** \brief Setea un sueldo a un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param sueldo int
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_setVacunaDos(ePais* this, int vacunaDos);

/** \brief Obtiene las horas trabajadas de un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \param id int* Puntero a entero de las horas trabajadas
 * \return int 1 si fallo, 0 si no fallo
 */
int ePais_getVacunaDos(ePais* this, int* vacunaDos);

/** \brief Muestra un empleado
 * \param thisePais ePais* Puntero a estructura ePais
 * \return void
 */

int ePais_setSinVacunar(ePais* this, int sinVacunar);
int ePais_getSinVacunar(ePais* this, int* sinVacunar);

void ePais_mostrarUno(ePais* this);

/** \brief Compara los ID
 * \param ePaisUno void* Puntero a void del empleado uno
 * \param ePaisDos void* Puntero a void del empleado dos
 * \return int -1 si el orden es descendente, 1 si es ascendente, 0 si hubo un error
 */
int ePais_sortId(void* ePaisUno, void* ePaisDos);

void* ePais_asignarEstadisticas(void* element);
int ePais_exitosos(void* element);
int ePais_horno(void* element);
int ePais_sortNivel(void* elementUno, void* elementDos);
