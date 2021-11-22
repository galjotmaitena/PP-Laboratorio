#include <stdio.h>
#include <stdlib.h>
#ifndef EDITORIAL_H_
#define EDITORIAL_H_


typedef struct
{
	int idEditorial;
	char nombre[128];
}eEditorial;

eEditorial* publisher_new();
eEditorial* publisher_newParametros(char* idStr,char* nombreStr);
void publisher_delete(eEditorial* this);

int publisher_setId(eEditorial* this,int id);
int publisher_getId(eEditorial* this,int* id);

int publisher_setNombre(eEditorial* this,char* nombre);
int Publisher_GetNombre(eEditorial* this,char* nombre);


#endif /* EDITORIAL_H_ */
