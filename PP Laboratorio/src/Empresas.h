/*
 * Empresas.h
 *
 *  Created on: 1 nov 2021
 *      Author: EXOSMART
 */
#include <stdio.h>
#ifndef EMPRESAS_H_
#define EMPRESAS_H_

#include "Input.h"


#define TAM 5

#define TRUE 0
#define FALSE 1

#include "Pedidos.h"
#include "Localidad.h"

typedef struct
{
	char calle[51];
	int numero;
}eDireccion;

typedef struct
{
	int id;
	char nombre[51];
	int cuit;
	eDireccion direccion;
	int idLocalidad;
	int isEmpty;
}eEmpresa;

int InicializarEmpresas(eEmpresa lista[], int tamanio);

int Alta(eEmpresa lista[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidad, int* idContador);
eEmpresa UnaEmpresa(int* idContador);


int MostrarListaDeEmpresas(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
void MostrarUnaEmpresa(eEmpresa empresa, eLocalidad lista[], int tamanio);

int Modificar(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
int BuscarPosicion(eEmpresa lista[], int tamanio, int id);
int BuscarPorId(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades, char mensaje[]);
int ModificarDireccion(eEmpresa lista[], int tamanio, int index);
int ModificarLocalidad(eEmpresa listaEmpresas[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int index);

int CambiarEstado(eEmpresa lista[], int tamanio, int index);
int Baja(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);

int MostrarListaDePedidos(ePedido listaPedidos[], int tamanioPedido, eEmpresa lista[], int tamanio);
void MostrarUnPedido(ePedido pedido, eEmpresa empresa);

int CrearPedido(eEmpresa listaEmpresas[], int tamanioEmpresas, ePedido listaPedido[], int tamanioPedido, eLocalidad listaLocalidades[], int tamanioLocalidades, int* id);

int BuscarPorIdPedido(ePedido listaPedido[], int tamanioPedido, char mensaje[], eEmpresa lista[], int tamanio);


int ProcesarResiduos(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio);

int ImprimirClientesConPedidosPendientes(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
int BuscarEmpresa(eEmpresa lista[], int tamanio, int id);
int ContarPedidos(ePedido listaPedido[], int tamanioPedido, eEmpresa unaEmpresa,int estado, int* contador);
/*
int ImprimirClientesConPedidosPendientes(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
int CantidadDePedidosPendientesPorEmpresa(ePedido listaPedido[], int tamanioPedido, eEmpresa unaEmpresa, int estado);
int BuscarEmpresasConPedidosPendientes(eEmpresa lista[], int tamanio, int id);

int ImprimirPedidos(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, int estado);

int BuscarPedidosPendientesPorLocalidad(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
int BuscarPorLocalidad(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades,int* idLocalidad);
*/
#endif /* EMPRESAS_H_ */
