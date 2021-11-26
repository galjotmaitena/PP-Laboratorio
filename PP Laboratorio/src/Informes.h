/*
 * Informes.h
 *
 *  Created on: 24 nov 2021
 *      Author: EXOSMART
 */
#include <stdio.h>
#ifndef INFORMES_H_
#define INFORMES_H_

#include "Empresas.h"
#include "Pedidos.h"
#include "Localidad.h"
#include "Transporte.h"

int ImprimirClientesConPedidosPendientes(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
int ContarPedidos(ePedido listaPedido[], int tamanioPedido, eEmpresa unaEmpresa,int estado, int* contador);

int ImprimirPedidos(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, int estado);

int BuscarPedidosPendientesPorLocalidad(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
int BuscarPorLocalidad(eLocalidad listaLocalidades[], int tamanioLocalidades,int* idLocalidad);

int ContarKilosDePP(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas);

int ClientesConMasPedidios(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, eLocalidad listaLocalidad[], int tamanioLocalidad, int estado);
int Contador(eEmpresa unaEmpresa, ePedido listaPedido[], int tamanioPedido, int* contador, int estado);
int MaximoContador(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, int estado, int* contador);


int EmpresasConPedidosEnviados(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, eTransporte listaTransportes[], int tamanioTransportes, eLocalidad listaLocalidad[], int tamanioLocalidad);
int BuscarPedidosDeUnaEmpresa(eEmpresa unaEmpresa, ePedido listaPedido[], int tamanioPedido, eTransporte listaTransportes[], int tamanioTransportes, float* acumuladorKm, float* acumuladorPrecio, int* contadorPedidos);
int TotalKmyPrecioDeUnaEmpresa(ePedido unPedido, eTransporte listaTransportes[], int tamanioTransportes, float* acumuladorKm, float* acumuladorPrecio, int* contadorPedidos);

#endif /* INFORMES_H_ */
