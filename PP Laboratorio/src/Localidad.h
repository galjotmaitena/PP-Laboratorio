/*
 * Localidad.h
 *
 *  Created on: 23 nov 2021
 *      Author: EXOSMART
 */
#include <stdio.h>
#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#define TRUE 0
#define FALSE 1

typedef struct
{
	int idLocalidad;
	char localidad[128];
	int isEmpty;
}eLocalidad;

int InicializarLocalidad(eLocalidad lista[], int tamanio);
int MostrarUnaLocalidad(eLocalidad unaLocalidad);
int MostrarListaLocalidades(eLocalidad listaLocalidades[], int tamanio);
int ValidarId(eLocalidad listaLocalidades[], int tamanio, int id);
int BuscarLocalidadPorId(eLocalidad listaLocalidades[], int tamanio, int id);
int BuscarPorIndice(eLocalidad listaLocalidades[], int tamanio, int index);

#endif /* LOCALIDAD_H_ */
