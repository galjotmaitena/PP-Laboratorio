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

/// \fn int ImprimirClientesConPedidosPendientes(ePedido[], int, eEmpresa[], int, eLocalidad[], int)
/// \brief Muestra la lista de los clientes y la cantidad de pedidos que estan en estado pendiente
/// \param listaPedido lista de pedidos que se recorrera en busca de los pedidos pendientes
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param listaEmpresas lista de las empresas necesaria para mostrarlas
/// \param tamanioEmpresas tamnio de la lista de empresas a mostrar
/// \param listaLocalidades lista de las localidades necesaria para mostrar los datos de la empresa de forma completa
/// \param tamanioLocalidades tamanio de la lista de localidades necesaria para recorrer
/// \return retorna -1 si las listas son nulas o 0 si se logro mostrar los clientes y la cantidad de pedidos pendientes
int ImprimirClientesConPedidosPendientes(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);

/// \fn int ImprimirPedidos(ePedido[], int, eEmpresa[], int, int)
/// \brief Muestra la lista de empresas con pedidos en un estado en particular enviado por parametro
/// \param listaPedido lista de pedidos d los cuales se verificara el estado
/// \param tamanioPedido tamanio de la lista de pedidos
/// \param lista lista lista de empresas a mostrar
/// \param tamanio tamanio de la lista de empresas necesario para recorrer y mostrar
/// \param estado estado en el que se desea que esten los pedidos de los clientes a mostarar
/// \return retorna -1 si as listas son nulas o 0 si se logro mostrar correctamente
int ImprimirPedidos(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, int estado);


/// \fn int BuscarPedidosPendientesPorLocalidad(ePedido[], int, eEmpresa[], int, eLocalidad[], int)
/// \brief Muestra la lista de pedidos pendientes y se pide la selccion de una localidad en la cual se contaran los pedidos pendintes que posee
/// \param listaPedido lista de pedidos que se recorrera en busca de los pendientes
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param listaEmpresas lista de empresas necesaria para mostrar la lista
/// \param tamanioEmpresas tamanio de la lista de empreas a recorrer
/// \param listaLocalidades lista de localidades que se mostrara para que se seleccione el id de la que se desea contar los pedidos pendientes
/// \param tamanioLocalidades tamanio de la lista de localidades a recorrer
/// \return retorna -1 si las listas son nulas o 0 si se logro mostrar y contar
int BuscarPedidosPendientesPorLocalidad(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
/// \fn int BuscarPorLocalidad(eLocalidad[], int, int*)
/// \brief Mostrara la lista de localidades y pedira la seleccion del id que luego sera devuelto por el puntero
/// \param listaLocalidades lista de localidades a recorrer y mostrar
/// \param tamanioLocalidades tamanio de la lista a recorrer
/// \param idLocalidad id de la localidad que sera devuelto
/// \return retorna -1 si la lista es nula o 0 si se verifico el id
int BuscarPorLocalidad(eLocalidad listaLocalidades[], int tamanioLocalidades,int* idLocalidad);

/// \fn int ContarKilosDePP(ePedido[], int, eEmpresa[], int)
/// \brief Mostrara el promedio por cliente de kilos de pp reciclado
/// \param listaPedido lista de pedidos a recorrer en busca del pedido de una empresa
/// \param tamanioPedido tamnio de la lista de pedidos a recorrer
/// \param listaEmpresas lista de empresas a recorrer con la que el id de cada una se comparara con el id de empresa guardado en los pedidos
/// \param tamanioEmpresas tamanio de la lista de empresas a recorrer
/// \return retorna -1 si las listas son nulas o 0 si se logro sacar el promedio
int ContarKilosDePP(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas);

/// \fn int ClientesConMasPedidios(ePedido[], int, eEmpresa[], int, eLocalidad[], int, int)
/// \brief Mostrara la lista de empresas con mas pedidos en el estado recibido por parametro
/// \param listaPedido lista de pedidos que se recorrera en busca de pedidos en ese estado
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param lista lista de empresas a recorrer comparando el id con el id de empresa que guarda cada pedio y necesaria par mostrar los clientes
/// \param tamanio tamanio de la lista de empresas a recorrer
/// \param listaLocalidad lista de localidades necesaria para mostrar de forma completa la informacion de la empresa
/// \param tamanioLocalidad tamanio de la lista de localidades a recorrer
/// \param estado estado en el que se desea que esten los pedidos de las empresas a mostra
/// \return retorna -1 si las listas son nulas o 0 si se logro mostrar lo requerido
int ClientesConMasPedidios(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, eLocalidad listaLocalidad[], int tamanioLocalidad, int estado);
/// \fn int Contador(eEmpresa, ePedido[], int, int*, int)
/// \brief Cuenta la cantidad de pedidos en un estado en particular
/// \param unaEmpresa empresa de la que se usara su id para obtener los pedidos hechos por dicha empresa
/// \param listaPedido lista de pedidos que se recorrera y con la que se ira comparando que coincida el id de la empresa
/// \param tamanioPedido tamanio de la lista de pedidos a recorer
/// \param contador puntero en el que se ira guardando la cantidad de pedidos
/// \param estado estado en el que se desea que este el pedido
/// \return retorna -1 si las listas y punteros son nulos o 0 si se logro contar
int Contador(eEmpresa unaEmpresa, ePedido listaPedido[], int tamanioPedido, int* contador, int estado);
/// \fn int MaximoContador(ePedido[], int, eEmpresa[], int, int, int*)
/// \brief Selecciona los mayores pedidos
/// \param listaPedido lista de pedidos que se recorrera
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param lista lista de empresas que se recorrera para ir comparando su id con el id de empresa que guarda el pedido
/// \param tamanio tamanio de la lista de empresas a recorrer
/// \param estado estado en el que se desea que este el pediod
/// \param contador puntero en el que se guardara el mayor pediod
/// \return retorna -1 si las listas son nulas o 0 si se logro contar
int MaximoContador(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, int estado, int* contador);

/// \fn int TotalDePedidosEnviados(ePedido[], int, eEmpresa[], int, eTransporte[], int, eLocalidad[], int)
/// \brief Muestra cada una de las empresas con la cantidad de pedidos enviados que posee y el total a pagar por los envios y el total de km a recorrer
/// \param listaPedido lista de pedidos a recorrer en busca de pedidos completados y enviados
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param lista lista de empresas que se recorrera para luego recorrer los pedidos y ver si posee pedidos
/// \param tamanio tamanio de la lista de empresas a recorrer
/// \param listaTransportes lista de transportes que se recorrera para contar los pedidos enviados y sumar los precios y km
/// \param tamanioTransportestamanio de la lista de transportes a recorrer
/// \param listaLocalidad lista de localidades necesaria para mostrar de forma completa los datos de la empresa
/// \param tamanioLocalidad tamanio de la lista de localidades a recorrer
/// \return
int TotalDePedidosEnviados(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, eTransporte listaTransportes[], int tamanioTransportes, eLocalidad listaLocalidad[], int tamanioLocalidad);
/// \fn int BuscarPedidosEnviadosDeUnaEmpresa(eEmpresa, ePedido[], int, eTransporte[], int, float*, float*, int*)
/// \brief recorre la lista de pedidos en busca de los completados para asi recorrer luego la de transpoets
/// \param unaEmpresa empresa de la que se comparara el id con el id de empresa que posee la lista de pedidos
/// \param listaPedido lista de pedidos a recorrer
/// \param tamanioPedido tamanio de la lista de pedidos
/// \param listaTransportes lista de transportes necesaria para recorrer y contar pedidos enviados y sumar preios y km
/// \param tamanioTransportestamanio de la lista de transportes a recorrer
/// \param acumuladorKm puntero donde se guardara el total de km
/// \param acumuladorPrecio puntero donde se guardara el total del precio
/// \param contadorPedidos puntero donde se guardara el total de pedidos
/// \return retorna -1 si las listas y punteros son nulas o 0 si se logo contar y acumular
int BuscarPedidosEnviadosDeUnaEmpresa(eEmpresa unaEmpresa, ePedido listaPedido[], int tamanioPedido, eTransporte listaTransportes[], int tamanioTransportes, float* acumuladorKm, float* acumuladorPrecio, int* contadorPedidos);
/// \fn int AcumularKmYPrecioDelPedidoDeUnaEmpresa(ePedido, eTransporte[], int, float*, float*, int*)
/// \brief Recorre la lista de transportes sumando precios, km y pedidos enviado
/// \param unPedido pedido que se verificara que haya sido enviado
/// \param listaTransportes lista de transportes que se recorrera para verificar el pedido
/// \param tamanioTransportes tamanio de la lista de transportes a recorrer
/// \param acumuladorKm puntero donde se gardaran el total de km
/// \param acumuladorPrecio puntero donde se guardara el total de los precios
/// \param contadorPedidos puntero donde se guardara el total de los pedidos enviados
/// \return retorna -1 si los punteros y listas son nulas o 0 si se logo contar
int AcumularKmYPrecioDelPedidoDeUnaEmpresa(ePedido unPedido, eTransporte listaTransportes[], int tamanioTransportes, float* acumuladorKm, float* acumuladorPrecio, int* contadorPedidos);

#endif /* INFORMES_H_ */
