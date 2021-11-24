#include "pais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ePais* ePais_new()
{
    ePais* newEmpleado = (ePais*) malloc(sizeof(ePais));

    if(newEmpleado != NULL)
    {
        newEmpleado->id = 0;
        strcpy(newEmpleado->nombre, "0");
        newEmpleado->horasTrabajadas = 0;
        newEmpleado->sueldo = 0;
    }

    return newEmpleado;
}

ePais* ePais_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    ePais* newEmpleado = ePais_new();

    if(newEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if((ePais_setId(newEmpleado, atoi(idStr))
            || ePais_setNombre(newEmpleado, nombreStr)
            || ePais_setHorasTrabajadas(newEmpleado, atoi(horasTrabajadasStr))
            || ePais_setSueldo(newEmpleado, atoi(sueldoStr))))
        {
            ePais_delete(newEmpleado);
            newEmpleado = NULL;
        }
    }
    return newEmpleado;
}

void ePais_delete(ePais* thisePais)
{
    if(thisePais != NULL)
    {
        free(thisePais);
    }
}

int ePais_setId(ePais* thisePais, int id)
{
    int fallo = 1;

    if(thisePais != NULL && id > 0)
    {
        thisePais->id = id;
        fallo = 0;
    }
    return fallo;
}

int ePais_getId(ePais* thisePais, int* id)
{
    int fallo = 1;

    if(thisePais != NULL && id != NULL)
    {
        *id = thisePais->id;
        fallo = 0;
    }
    return fallo;
}

int ePais_setNombre(ePais* thisePais, char* nombre)
{
    int fallo = 1;

    if(thisePais != NULL && nombre != NULL)
    {
        if(strlen(nombre) > 1 && strlen(nombre) < 128)
        {
            strcpy(thisePais->nombre, nombre);
            fallo = 0;
        }
    }
    return fallo;
}

int ePais_getNombre(ePais* thisePais, char* nombre)
{
    int fallo = 1;

    if(thisePais != NULL && nombre != NULL)
    {
        strcpy(nombre, thisePais->nombre);
        fallo = 0;
    }
    return fallo;
}

int ePais_setHorasTrabajadas(ePais* thisePais, int horasTrabajadas)
{
    int fallo = 1;

    if(thisePais != NULL && horasTrabajadas > 0)
    {
        thisePais->horasTrabajadas = horasTrabajadas;
        fallo = 0;
    }
    return fallo;
}

int ePais_getHorasTrabajadas(ePais* thisePais, int* horasTrabajadas)
{
   int fallo = 1;

    if(thisePais != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas =  thisePais->horasTrabajadas;
        fallo = 0;
    }
    return fallo;
}

int ePais_setSueldo(ePais* thisePais, int sueldo)
{
    int fallo = 1;

    if(thisePais != NULL && sueldo > 0)
    {
        thisePais->sueldo = sueldo;
        fallo = 0;
    }
    return fallo;
}

int ePais_getSueldo(ePais* thisePais, int* sueldo)
{
    int fallo = 1;

    if(thisePais != NULL && sueldo != NULL)
    {
        *sueldo = thisePais->sueldo;
        fallo = 0;
    }
    return fallo;
}

void ePais_mostrarUno(ePais* thisePais)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(thisePais != NULL)
    {
        ePais_getId(thisePais, &id);
        ePais_getNombre(thisePais, nombre);
        ePais_getHorasTrabajadas(thisePais, &horasTrabajadas);
        ePais_getSueldo(thisePais, &sueldo);

        printf("%4d%15s              %3d         %6d\n", id, nombre, horasTrabajadas, sueldo);
    }
}

int ePais_sortId(void* ePaisUno, void* ePaisDos)
{
	int criterio = 0;
	int idePaisUno;
	int idePaisDos;

	ePais* auxePaisUno = (ePais*) ePaisUno;
	ePais* auxePaisDos = (ePais*) ePaisDos;

	if(ePaisUno != NULL && ePaisDos != NULL)
	{
		ePais_getId(auxePaisUno, &idePaisUno);
		ePais_getId(auxePaisDos, &idePaisDos);

		if(idePaisUno > idePaisDos)
        {
			criterio = 1;
		}
		else if(idePaisUno < idePaisDos)
		{
            criterio = -1;
        }
	}
	return criterio;
}

int ePais_sortName(void* ePaisUno, void* ePaisDos)
{
    int criterio = 0;
    char nombreUno[128];
    char nombreDos[128];

    ePais* auxePaisUno = (ePais*) ePaisUno;
    ePais* auxePaisDos = (ePais*) ePaisDos;


    if(ePaisUno != NULL && ePaisDos != NULL)
    {
        ePais_getNombre(auxePaisUno, nombreUno);
		ePais_getNombre(auxePaisDos, nombreDos);

        if(strcmp(nombreUno, nombreDos) > 0)
		{
			criterio = 1;
		}
		else if(strcmp(nombreUno, nombreDos) < 0)
        {
            criterio = -1;
        }
    }
    return criterio;
}

int ePais_sortHours(void* ePaisUno, void* ePaisDos)
{
	int criterio = 0;
    int horasUno;
	int horasDos;

	ePais* auxePaisUno=(ePais*) ePaisUno;
	ePais* auxePaisDos=(ePais*) ePaisDos;

	if(ePaisUno != NULL && ePaisDos != NULL)
	{
		ePais_getHorasTrabajadas(auxePaisUno, &horasUno);
		ePais_getHorasTrabajadas(auxePaisDos, &horasDos);

        if(horasUno > horasDos)
        {
            criterio = 1 ;
        }
        else if(horasUno < horasDos)
        {
            criterio = -1;
        }
	}
	return criterio;
}

int ePais_sortSalary(void* ePaisUno, void* ePaisDos)
{
	int criterio = 0;
	int sueldoUno;
	int sueldoDos;

	ePais* auxePaisUno=(ePais*) ePaisUno;
	ePais* auxePaisDos=(ePais*) ePaisDos;

	if(ePaisUno != NULL && ePaisDos != NULL)
	{
		ePais_getSueldo(auxePaisUno, &sueldoUno);
		ePais_getSueldo(auxePaisDos, &sueldoDos);

        if(sueldoUno > sueldoDos)
        {
            criterio = 1;
        }
        else if(sueldoUno < sueldoDos)
        {
            criterio = -1;
        }
	}
	return criterio;
}
