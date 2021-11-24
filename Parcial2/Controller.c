#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "pelicula.h"
#include "parser.h"
#include "menu.h"

/** \brief Carga los datos de las peliculas desde el archivo correspondiente
 *
 * \param path char*
 * \param pArrayPelis LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayPelis)
{
    int fallo = 1;
    FILE* txtFile;

    if(path != NULL && pArrayPelis != NULL)
    {
        txtFile = fopen(path, "r");

        if(txtFile != NULL)
        {
            fallo = parser_eMovieFromText(txtFile, pArrayPelis);
            fclose(txtFile);
        }
    }
    return fallo;
}

/** \brief Listar peliculas
 *
 * \param path char*
 * \param pArrayPelis LinkedList*
 * \return int
 *
 */
int controller_ListPeliculas(LinkedList* pArrayPelis)
{
    int fallo = 1;
    int tam;
    eMovie* eMovie = NULL;

    if(pArrayPelis != NULL)
    {
        system("clear");
        printf("----------------------------------------------------------------------\n");
        printf("-------------------------Listado de peliculas-------------------------\n");
        printf("----------------------------------------------------------------------\n");
        printf("  ID            Titulo                     Genero           Duracion  \n");

        tam = ll_len(pArrayPelis);

        for(int i = 0; i < tam; i++)
        {
            eMovie = ll_get(pArrayPelis, i);
            eMovie_mostrarUna(eMovie);
        }
        fallo = 0;
    }
    return fallo;
}

/** \brief Ordenar peliculas por genero y por duracion descendente
 *
 * \param path char*
 * \param pArrayPelis LinkedList*
 * \return int
 *
 */
int controller_sortPeliculas(LinkedList* pArrayPelis)
{
    int fallo = 1;
    LinkedList* auxLista = NULL;

    if(pArrayPelis != NULL)
    {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("------------Ordenar por duracion y genero-------------\n");
        printf("------------------------------------------------------\n");

        auxLista = pArrayPelis;

        if(!ll_sort(auxLista, eMovie_sortGenero, 1))
        {
            if(!ll_sort(auxLista, eMovie_sortDuracion, 0))
            {
                controller_ListPeliculas(auxLista);
                fallo = 0;
            }
        }
        else
        {
            printf("Se produjo un error al ordenar\n");
        }
    }
    return fallo;
}

/** \brief Guarda los datos de las peliculas en un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayPelis LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayPelis)
{
    int fallo = 1;
    FILE* txtFile;
    eMovie* eMovie;
    int id;
    char titulo[30];
    char genero[12];
    int duracion;
    int tam;

	if(path != NULL && pArrayPelis != NULL)
	{
		txtFile = fopen(path, "w");
		eMovie = eMovie_new();
		tam = ll_len(pArrayPelis);

		if(txtFile != NULL && eMovie != NULL)
		{
            fprintf(txtFile, "id_peli,titulo,genero,duracion\n");

            for(int i = 0; i < tam; i++)
            {
                eMovie = ll_get(pArrayPelis, i);
                if(eMovie != NULL)
                {
                    eMovie_getId(eMovie, &id);
                    eMovie_getTitulo(eMovie, titulo);
                    eMovie_getGenero(eMovie, genero);
                    eMovie_getDuracion(eMovie, &duracion);

                    fprintf(txtFile,"%d,%s,%s,%d\n", id, titulo, genero, duracion);
                    fallo = 0;
                }
            }
            fclose(txtFile);
        }
	}
    return fallo;
}
