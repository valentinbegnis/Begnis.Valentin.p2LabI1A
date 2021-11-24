#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayPaises);
int controller_ListPeliculas(LinkedList* pArrayPelis);
int controller_sortPeliculas(LinkedList* pArrayPelis);
int controller_saveAsText(char* path , LinkedList* pArrayPaises);

#endif // CONTROLLER_H_INCLUDED
