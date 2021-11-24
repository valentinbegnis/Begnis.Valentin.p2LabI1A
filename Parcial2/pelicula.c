#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eMovie* eMovie_new()
{
    eMovie* newPelicula = (eMovie*) malloc(sizeof(eMovie));

    if(newPelicula != NULL)
    {
        newPelicula->id_peli = 0;
        strcpy(newPelicula->titulo, "-");
        strcpy(newPelicula->genero, "-");
        newPelicula->duracion = 0;
    }
    return newPelicula;
}

eMovie* eMovie_newParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
    eMovie* newPelicula = eMovie_new();

    if(newPelicula != NULL && idStr != NULL && tituloStr != NULL && generoStr != NULL && duracionStr != NULL)
    {
        if((eMovie_setId(newPelicula, atoi(idStr))
            || eMovie_setTitulo(newPelicula, tituloStr)
            || eMovie_setGenero(newPelicula, generoStr)
            || eMovie_setDuracion(newPelicula, atoi(duracionStr))))
        {
            eMovie_delete(newPelicula);
            newPelicula = NULL;
        }
    }
    return newPelicula;
}

void eMovie_delete(eMovie* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int eMovie_setId(eMovie* this, int id)
{
    int fallo = 1;

    if(this != NULL && id > 0)
    {
        this->id_peli = id;
        fallo = 0;
    }
    return fallo;
}

int eMovie_getId(eMovie* this, int* id)
{
    int fallo = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id_peli;
        fallo = 0;
    }
    return fallo;
}

int eMovie_setTitulo(eMovie* this, char* titulo)
{
    int fallo = 1;

    if(this != NULL && titulo != NULL)
    {
        if(strlen(titulo) > 1 && strlen(titulo) < 50)
        {
            strcpy(this->titulo, titulo);
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_getTitulo(eMovie* this, char* titulo)
{
    int fallo = 1;

    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        fallo = 0;
    }
    return fallo;
}

int eMovie_setGenero(eMovie* this, char* genero)
{
    int fallo = 1;

    if(this != NULL && genero != NULL)
    {
        if(strlen(genero) > 1 && strlen(genero) < 50)
        {
            strcpy(this->genero, genero);
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_getGenero(eMovie* this, char* genero)
{
    int fallo = 1;

    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        fallo = 0;
    }
    return fallo;
}

int eMovie_setDuracion(eMovie* this, int duracion)
{
    int fallo = 1;

    if(this != NULL)
    {
        this->duracion = duracion;
        fallo = 0;
    }
    return fallo;
}

int eMovie_getDuracion(eMovie* this, int* duracion)
{
    int fallo = 1;

    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        fallo = 0;
    }
    return fallo;
}

void eMovie_mostrarUna(eMovie* this)
{
    int id;
    char titulo[30];
    char genero[12];
    int duracion;

    if(this != NULL)
    {
        eMovie_getId(this, &id);
        eMovie_getTitulo(this, titulo);
        eMovie_getGenero(this, genero);
        eMovie_getDuracion(this, &duracion);

        printf("  %-2d      %-30s  %-12s        %-3d\n", id, titulo, genero, duracion);
    }
}

void* eMovie_asignarTiempos(void* element)
{
    eMovie* auxMovie = (eMovie*) element;

    int min = 100;
    int max = 240;
    int tiempo = rand() % (max - min + 1) + min;

    if(element != NULL)
    {
        eMovie_setDuracion(auxMovie, tiempo);
    }
    return auxMovie;
}


int eMovie_filtrarAventura(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Adventure") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarDrama(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Drama") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarComedy(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Comedy") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarRomance(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Romance") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarDocumentary(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Documentary") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarHorror(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Horror") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarMusical(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Musical") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarAnimation(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Animation") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarAction(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Action") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarThriller(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Thriller") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}

int eMovie_filtrarWestern(void* element)
{
    eMovie* auxMovie = (eMovie*) element;
    char genero[12];
    int fallo = 1;

    if(element != NULL)
    {
        eMovie_getGenero(auxMovie, genero);
        if(strcmp(genero, "Western") == 0)
        {
            fallo = 0;
        }
    }
    return fallo;
}
//////////////////////////////

int eMovie_sortGenero(void* elementUno, void* elementDos)
{
    int criterio = 0;
	char generoUno[12];
	char generoDos[12];

    eMovie* auxElementUno = (eMovie*) elementUno;
    eMovie* auxElementDos = (eMovie*) elementDos;

	if(elementUno != NULL && elementDos != NULL)
	{
		eMovie_getGenero(auxElementUno, generoUno);
		eMovie_getGenero(auxElementDos, generoDos);

        if(strcmp(generoUno, generoDos) > 0)
		{
			criterio = 1;
		}
		else if(strcmp(generoUno, generoDos) < 0)
        {
            criterio = -1;
        }
	}
	return criterio;
}

int eMovie_sortDuracion(void* elementUno, void* elementDos)
{
    int criterio = 0;
	char generoUno[12];
	char generoDos[12];
	int duracionUno;
	int duracionDos;

    eMovie* auxElementUno = (eMovie*) elementUno;
    eMovie* auxElementDos = (eMovie*) elementDos;

	if(elementUno != NULL && elementDos != NULL)
	{
		eMovie_getGenero(auxElementUno, generoUno);
		eMovie_getGenero(auxElementDos, generoDos);

		eMovie_getDuracion(auxElementUno, &duracionUno);
		eMovie_getDuracion(auxElementDos, &duracionDos);

        if(strcmp(generoUno, generoDos) == 0)
		{
            if(duracionUno > duracionDos)
            {
                criterio = 1 ;
            }
            else if(duracionUno < duracionDos)
            {
                criterio = -1;
            }
		}
	}
	return criterio;
}


