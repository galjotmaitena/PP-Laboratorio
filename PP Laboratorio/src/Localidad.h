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
	char localidad[128];;
	int isEmpty;
}eLocalidad;

/// \fn int InicializarLocalidad(eLocalidad[], int)
/// \brief Inicializa la lista de localidades
/// \param lista lista a inicializar
/// \param tamanio tamanio de la lista a recorrer para incializar
/// \return retorna -1 si la lista es nula o 0 si se logro inicializar correctamente
int InicializarLocalidad(eLocalidad lista[], int tamanio);

/// \fn void MostrarUnaLocalidad(eLocalidad)
/// \brief Muestra los datos de una localidad
/// \param unaLocalidad la localidad de la que se mostraran los datos
void MostrarUnaLocalidad(eLocalidad unaLocalidad);

/// \fn int MostrarListaLocalidades(eLocalidad[], int)
/// \brief Muestra la lista de las localidades
/// \param listaLocalidades lista de la que se mostrara cada una de las localidades al recorrerla
/// \param tamanio tamanio de la lista a recorrer
/// \return retorna -1 si las listas son nulas o 0 si se logro mostrar correctamente
int MostrarListaLocalidades(eLocalidad listaLocalidades[], int tamanio);

/// \fn int ValidarId(eLocalidad[], int, int)
/// \brief Vlida que el id recibido por parametro pertenezca a algna de las localidades
/// \param listaLocalidades lista de localidades que se recorrera en busca del id
/// \param tamanio tamnio de la lista a recorrer
/// \param id id con el que se realizara la comparacion
/// \return retorna -1 si la lista es nula y si no se encontro el id o 0 si el id fue encontrado
int ValidarId(eLocalidad listaLocalidades[], int tamanio, int id);

/// \fn int BuscarLocalidadPorId(eLocalidad[], int, int)
/// \brief Busca la posicion de la localidad con el id recibido por parametro
/// \param listaLocalidades lista de localidades a recorrer en busca del id recibido y de la posicion de la localidad a la que pertenece ese id
/// \param tamanio tamanio de la lista a recorrer
/// \param id id con el que se ira comparando
/// \return retorna -1 si la lista es nula o si no se encontraron coincidencias con el id o la posicion en la que se encuentra la localidad
int BuscarPorIndice(eLocalidad listaLocalidades[], int tamanio, int id);

/// \fn int BuscarPorIndice(eLocalidad[], int, int)
/// \brief Busca el id de la localidad comparando las posiciones de la lista
/// \param listaLocalidades lista que se recorrera en busca del id
/// \param tamanio tamanio de la lista a recorrer
/// \param index posicion con la que se ira comparando hasta obtener el id
/// \return retorna -1 si la lista es nula o el id de la localidad
int BuscarLocalidadPorId(eLocalidad listaLocalidades[], int tamanio, int index);

/// \fn int PrecioYKmPorLocalidad(int, float*, float*)
/// \brief Indica la cantidad de km que hay desde la planta hast cada localidad y el valor del envio a cada una de las localidades
/// \param id id de la localidad
/// \param precio puntero en el que se gardara el precio del viaje
/// \param km puntero en el que guardaran los km hasta la localidad
/// \return retorna -1 si los punteros son nulos o 0 si no
int PrecioYKmPorLocalidad(int id, float *precio, float *km);

#endif /* LOCALIDAD_H_ */
