#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int menu()
{
    int opcion;

    system("clear");

    printf("-----------------------------------------------------------------------------\n");
    printf("------------------------------Sistema Peliculas------------------------------\n");
    printf("-----------------------------------------------------------------------------\n\n");
    printf("1. Cargar archivo (modo texto)\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar tiempos\n");
    printf("4. Filtrar por tipo\n");
    printf("5. Mostrar duraciones\n");
    printf("6. Guardar peliculas (modo texto)\n");
    printf("7. Salir\n");

    printf("\nElegir una opcion: ");
    __fpurge(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuGeneros()
{
    int opcion;

    system("clear");
    printf("1. Adventure\n");
    printf("2. Drama\n");
    printf("3. Comedy\n");
    printf("4. Romance\n");
    printf("5. Documentary\n");
    printf("6. Horror\n");
    printf("7. Musical\n");
    printf("8. Animation\n");
    printf("9. Action\n");
    printf("10. Thriller\n");
    printf("11. Western\n");
    printf("12. Salir\n");

    printf("\nElegir una opcion: ");
    __fpurge(stdin);
    scanf("%d", &opcion);

    return opcion;
}




