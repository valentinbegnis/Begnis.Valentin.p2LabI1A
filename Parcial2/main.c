#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "pelicula.h"
#include "menu.h"
#include "misFunciones.h"

int main()
{
    char seguir = 's';
    LinkedList* listaPeliculas = ll_newLinkedList();
    LinkedList* listaOrdenadas;
    LinkedList* listaFiltradas;
    char archivo[20];
    int flagGuardoArchivo = 0;
    srand(time(NULL));

    do{
        switch(menu())
        {
            case 1:
               if(ll_isEmpty(listaPeliculas) && !flagGuardoArchivo)
                {
                    printf("Ingrese el nombre del archivo a cargar: ");
                    pedirString(archivo, 20, 5);

                    if(!controller_loadFromText("movies.csv", listaPeliculas))
                    {
                        printf("Archivo cargado exitosamente\n");
                    }
                    else
                    {
                        printf("Ocurrio un error al cargar el archivo. Nombre incorrecto\n");
                    }
                }
                else
                {
                    printf("Ya cargo un archivo\n");
                }
                break;
            case 2:
                if(!ll_isEmpty(listaPeliculas))
                {
                    if(controller_ListPeliculas(listaPeliculas))
                    {
                        printf("\nOcurrio un error al mostrar las peliculas\n");
                    }
                }
                else
                {
                    printf("No hay peliculas para mostrar\n");
                }
                break;
            case 3:
                if(!ll_isEmpty(listaPeliculas))
                {
                    listaPeliculas = ll_map(listaPeliculas, eMovie_asignarTiempos);

                    if(listaPeliculas != NULL)
                    {
                        controller_ListPeliculas(listaPeliculas);
                        listaOrdenadas = ll_clone(listaPeliculas); //Clono la lista una vez asignados los tiempos
                        listaFiltradas = ll_clone(listaPeliculas);
                        printf("\nTiempos asignados exitosamente\n");
                    }
                    else
                    {
                        printf("\nOcurrio un error al asignar los tiempos\n");
                    }
                }
                else
                {
                    printf("No hay peliculas a las cuales asignarle un tiempo\n");
                }
                break;
            case 4:
                if(!ll_isEmpty(listaPeliculas))
                {
                    switch(menuGeneros())
                    {
                        case 1:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarAventura);
                            break;
                         case 2:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarDrama);
                            break;
                         case 3:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarComedy);
                            break;
                         case 4:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarRomance);
                            break;
                         case 5:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarDocumentary);
                            break;
                         case 6:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarHorror);
                            break;
                         case 7:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarMusical);
                            break;
                         case 8:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarAnimation);
                            break;
                         case 9:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarAction);
                            break;
                         case 10:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarThriller);
                            break;
                         case 11:
                            listaFiltradas = ll_filter(listaFiltradas, eMovie_filtrarWestern);
                            break;
                         case 12:
                            printf("\nSaliste\n");
                            break;
                         default:
                            printf("Opcion invalida\n");
                    }


                    if(listaFiltradas != NULL)
                    {
                        if(!controller_saveAsText("filtradas.csv", listaFiltradas))
                        {
                            printf("Archivo cargado exitosamente\n");
                        }
                    }
                    else
                    {
                        printf("\nOcurrio un error al guardar el archivo\n");
                    }
                }
                else
                {
                    printf("No hay peliculas para filtrar\n");
                }
                break;
            case 5:
                if(!ll_isEmpty(listaPeliculas))
                {
                    if(!controller_sortPeliculas(listaOrdenadas))
                    {
                        printf("Ordenamiento exitoso\n");
                    }
                    else
                    {
                        printf("Ocurrio un error al ordenar\n");
                    }
                }
                else
                {
                    printf("No hay peliculas para ordenar\n");
                }
                break;
            case 6:
                if(!ll_isEmpty(listaPeliculas))
                {
                    if(!controller_saveAsText("ordenadas.csv", listaOrdenadas))
                    {
                        printf("Archivo guardado con exito\n");
                    }
                    else
                    {
                        printf("\nOcurrio un error al guardar el archivo\n");
                    }
                }
                else
                {
                    printf("No existe un listado de peliculas ordenadas para guardar\n");
                }
                break;
           case 7:
                printf("Saliste\n");
                seguir = 'n';
                break;
            default:
                printf("Opcion invalida\n");
        }

        printf("\nPresione cualquier tecla para continuar...");
        __fpurge(stdin);
        getchar();

    }while(seguir == 's');

    return 0;
}
