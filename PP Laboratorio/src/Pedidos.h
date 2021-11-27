/*
 * Pedidos.h
 *
 *  Created on: 1 nov 2021
 *      Author: EXOSMART
 */
#include <stdio.h>
#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "Input.h"

#define SIN_HACER -1
#define PENDIENTE 0
#define COMPLETADO 1

typedef struct
{
	float hdpe;
	float ldpe;
	float pp;
}eTipoDePlastico;

typedef struct
{
	int id;
	int idEmpresa;
	int idTransporte;
	float cantidadKilos;
	eTipoDePlastico tiposDePlastico;
	int isEmpty;
}ePedido;

/// \fn int InicializarPedidos(ePedido[], int)
/// \brief Inicializa cada posicion de la lista de pedidos
/// \param lista lista de pedidos que se inicializara
/// \param tamanio tamnio de la lista a inicializar
/// \return retorna -1 si la lista es nula o 0 si se logro inicializar correctamente
int InicializarPedidos(ePedido lista[], int tamanio);

/// \fn int AltaPedidos(ePedido[], int, int, int*)
/// \brief Crea un pedido
/// \param listaPedido lista de pedidos en la que se agregara el pedido
/// \param tamanioPedido tamanio de la lista del pedido
/// \param index posicion en la que se guardara el pedido
/// \param id puntero con el que se generara el id
/// \return retorna -1 si la lista es nula o 0 si se pudo dar de alta correctamente
int AltaPedidos(ePedido listaPedido[], int tamanioPedido, int index, int*id);

/// \fn int BuscarPosicionPedido(ePedido[], int, int)
/// \brief Busca la posicion en la que se encuentra el pedido con el id recibido por parametro
/// \param lista lista que se recorrera en busca del pedido con ese mismo id
/// \param tamanio tamanio de la lista a recorrer
/// \param id id con el que se comparara el de cada pedido
/// \return retorna -1 si la lista es nula o la posicion del pedido
int BuscarPosicionPedido(ePedido lista[], int tamanio, int id);

/// \fn int IngresarCantidadDeKilosPorTipo(ePedido[], int)
/// \brief Pide el ingreso de la cantidad de plastico por tipo
/// \param listaPedido lista de pedidos en la que se actualizaran los datos
/// \param index posicion de la lista en la que se actualizaran los datos
/// \return retorna -1 si la lista es nula o 0 si se logro el ingreso por tipo
int IngresarCantidadDeKilosPorTipo(ePedido listaPedido[], int index);

/// \fn void MostrarCantidadPorTipoDePlatico(ePedido)
/// \brief Muestra los tipos de plasticos y la cantidad de kilos por cada uno de estos
/// \param pedido pedido del que se mostrara la informacion
void MostrarCantidadPorTipoDePlatico(ePedido pedido);

#endif /* PEDIDOS_H_ */
