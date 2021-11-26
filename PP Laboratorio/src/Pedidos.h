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

int InicializarPedidos(ePedido lista[], int tamanio);

int IngresarCantidadDeKilosARecolectar(ePedido listaPedido[], int tamanioPedido, int index, int*id);

int BuscarPosicionPedido(ePedido lista[], int tamanio, int id);

void MostrarCantidadPorTipoDePlatico(ePedido pedido);

int IngresarCantidadDeKilosPorTipo(ePedido listaPedido[], int index);

#endif /* PEDIDOS_H_ */
