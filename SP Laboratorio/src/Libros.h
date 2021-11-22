/*
 * Libros.h
 *
 *  Created on: 22 nov 2021
 *      Author: EXOSMART
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include "Editorial.h"

typedef struct
{
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
}eLibro;

eLibro* Books_New();
eLibro* Books_NewParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);
void Books_Delete(eLibro* this);

int Books_SetId(eLibro* this,int id);
int Books_GetId(eLibro* this,int* id);

int Books_SetTitulo(eLibro* this,char* nombre);
int Books_GetTitulo(eLibro* this,char* nombre);

int Books_SetAutor(eLibro* this,char* autor);
int Books_GetAutor(eLibro* this,char* autor);

int Books_SetPrecio(eLibro* this,float precio);
int Books_GetPrecio(eLibro* this,float* precio);

int Books_SetIdEditorial(eLibro* this,int idEditorial);
int Books_GetIdEditorial(eLibro* this,int* idEditorial);

int Books_ImprimirUnLibro(eLibro* unLibro, eEditorial* unaEditorial);

int Books_CompareByAutor(void* x, void* y);

int Books_FilterMinotauro(void* unLibro);

#endif /* LIBROS_H_ */
