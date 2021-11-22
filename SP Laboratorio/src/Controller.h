/*
 * Controller.h
 *
 *  Created on: 22 nov 2021
 *      Author: EXOSMART
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Libros.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPublisher, int opcion);
int controller_ListBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorial);
eEditorial* controller_GetEditorial(eLibro* unLibro, LinkedList* pArrayListEditorial);
int controller_SortBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorial);
int controller_FilterEditorial(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial);

#endif /* CONTROLLER_H_ */
