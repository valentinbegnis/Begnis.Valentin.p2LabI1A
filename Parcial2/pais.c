#include "peli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ePais* ePais_new()
{
    ePais* newPais = (ePais*) malloc(sizeof(ePais));

    if(newPais != NULL)
    {
        newPais->id = 0;
        strcpy(newPais->nombre, "-");
        newPais->vac1dosis = 0;
        newPais->vac2dosis = 0;
        newPais->sinVacunar = 0;
    }

    return newPais;
}

ePais* ePais_newParametros(char* idStr, char* nombreStr, char* vacunaUnoStr, char* vacunaDosStr, char* sinVacunarStr)
{
    ePais* newPais = ePais_new();

    if(newPais != NULL && idStr != NULL && nombreStr != NULL && vacunaUnoStr != NULL && vacunaDosStr != NULL && sinVacunarStr != NULL)
    {
        if((ePais_setId(newPais, atoi(idStr))
            || ePais_setNombre(newPais, nombreStr)
            || ePais_setVacunaUno(newPais, atoi(vacunaUnoStr))
            || ePais_setVacunaDos(newPais, atoi(vacunaDosStr))
            || ePais_setSinVacunar(newPais, atoi(sinVacunarStr))))
        {
            ePais_delete(newPais);
            newPais = NULL;
        }
    }
    return newPais;
}

void ePais_delete(ePais* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int ePais_setId(ePais* this, int id)
{
    int fallo = 1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        fallo = 0;
    }
    return fallo;
}

int ePais_getId(ePais* this, int* id)
{
    int fallo = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        fallo = 0;
    }
    return fallo;
}

int ePais_setNombre(ePais* this, char* nombre)
{
    int fallo = 1;

    if(this != NULL && nombre != NULL)
    {
        if(strlen(nombre) > 1 && strlen(nombre) < 50)
        {
            strcpy(this->nombre, nombre);
            fallo = 0;
        }
    }
    return fallo;
}

int ePais_getNombre(ePais* this, char* nombre)
{
    int fallo = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        fallo = 0;
    }
    return fallo;
}

int ePais_setVacunaUno(ePais* this, int vacunaUno)
{
    int fallo = 1;

    if(this != NULL)
    {
        this->vac1dosis = vacunaUno;
        fallo = 0;
    }
    return fallo;
}

int ePais_getVacunaUno(ePais* this, int* vacunaUno)
{
   int fallo = 1;

    if(this != NULL && vacunaUno != NULL)
    {
        *vacunaUno = this->vac1dosis;
        fallo = 0;
    }
    return fallo;
}

int ePais_setVacunaDos(ePais* this, int vacunaDos)
{
    int fallo = 1;

    if(this != NULL)
    {
        this->vac2dosis = vacunaDos;
        fallo = 0;
    }
    return fallo;
}

int ePais_getVacunaDos(ePais* this, int* vacunaDos)
{
    int fallo = 1;

    if(this != NULL && vacunaDos != NULL)
    {
        *vacunaDos = this->vac2dosis;
        fallo = 0;
    }
    return fallo;
}

int ePais_setSinVacunar(ePais* this, int sinVacunar)
{
    int fallo = 1;

    if(this != NULL)
    {
        this->sinVacunar = sinVacunar;
        fallo = 0;
    }
    return fallo;
}

int ePais_getSinVacunar(ePais* this, int* sinVacunar)
{
    int fallo = 1;

    if(this != NULL && sinVacunar != NULL)
    {
        *sinVacunar = this->sinVacunar;
        fallo = 0;
    }
    return fallo;
}

void ePais_mostrarUno(ePais* this)
{
    int id;
    char nombre[50];
    int vacunaUno;
    int vacunaDos;
    int sinVacunar;

    if(this != NULL)
    {
        ePais_getId(this, &id);
        ePais_getNombre(this, nombre);
        ePais_getVacunaUno(this, &vacunaUno);
        ePais_getVacunaDos(this, &vacunaDos);
        ePais_getSinVacunar(this, &sinVacunar);

        printf("%4d%15s           %2d\%%           %2d\%%         %2d\%%\n", id, nombre, vacunaUno, vacunaDos, sinVacunar);
    }
}

int ePais_sortPrimeraDosis(void* ePaisUno, void* ePaisDos)
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

void* ePais_asignarEstadisticas(void* element)
{
    ePais* auxPais = (ePais*) element;

    int minUno = 1, maxUno = 60;
    int minDos = 1, maxDos = 40;
    int vacunaUno = rand() % (maxUno - minUno + 1) + minUno;
    int vacunaDos = rand() % (maxDos - minDos + 1) + minDos;
    int sinVacunar;

    if(element != NULL)
    {
        sinVacunar = 100 - (vacunaUno + vacunaDos);

        ePais_setVacunaUno(auxPais, vacunaUno);
        ePais_setVacunaDos(auxPais, vacunaDos);
        ePais_setSinVacunar(auxPais, sinVacunar);
    }
    return auxPais;
}

int ePais_exitosos(void* element)
{
    ePais* auxPais = (ePais*) element;
    int vacunaDos;
    int fallo = 1;

    if(element != NULL)
    {
        ePais_getVacunaDos(auxPais, &vacunaDos);
        if(vacunaDos > 30)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int ePais_horno(void* element)
{
    ePais* auxPais = (ePais*) element;
    int vacunaUno;
    int vacunaDos;
    int sinVacunar;
    int fallo = 1;

    if(element != NULL)
    {
        ePais_getVacunaUno(auxPais, &vacunaUno);
        ePais_getVacunaDos(auxPais, &vacunaDos);
        ePais_getSinVacunar(auxPais, &sinVacunar);

        if(sinVacunar > (vacunaUno + vacunaDos))
        {
            fallo = 0;
        }
    }
    return fallo;
}

int ePais_sortNivel(void* elementUno, void* elementDos)
{
    int criterio = 0;
	int vacUno1;
	int vacUno2;

    ePais* auxElementUno = (ePais*) elementUno;
    ePais* auxElementDos = (ePais*) elementDos;

	if(elementUno != NULL && elementDos != NULL)
	{
		ePais_getVacunaUno(auxElementUno, &vacUno1);
		ePais_getVacunaUno(auxElementDos, &vacUno2);

        if(vacUno1 > vacUno2)
        {
            criterio = 1;
        }
        else if(vacUno1 < vacUno2)
        {
            criterio = -1;
        }
	}
	return criterio;
}

