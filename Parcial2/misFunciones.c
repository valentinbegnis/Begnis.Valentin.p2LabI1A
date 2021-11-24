#include "misFunciones.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int pedirString(char string[], int len, int min)
{
	int todoOk = 0;
	char bufferString[100];

	if(string != NULL && len > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) >= min &&
					strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				strncpy(string, bufferString, len);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}
