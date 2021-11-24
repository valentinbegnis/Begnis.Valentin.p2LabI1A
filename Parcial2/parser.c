#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pelicula.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int parser_eMovieFromText(FILE* pFile , LinkedList* pArrayPelis)
{
    int fallo = 1;
    eMovie* auxPelicula;
    char buffer[4][200];

    if(pFile != NULL && pArrayPelis != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        do{
            if((fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3])) == 4)
            {
                auxPelicula = eMovie_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(auxPelicula != NULL)
                {
                    if(ll_add(pArrayPelis, auxPelicula))
                    {
                        eMovie_delete(auxPelicula);
                        break;
                    }
                    else
                    {
                        fallo = 0;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }
    return fallo;
}
