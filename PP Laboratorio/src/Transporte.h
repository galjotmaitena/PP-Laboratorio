#include <stdio.h>
#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

#define ENVIADO 1
#define EN_PREPARACION 0
#define SIN_HACER -1

#include "Localidad.h"
#include "Input.h"
#include "Pedidos.h"

typedef struct
{
	int id;
	int idLocalidad;
	float precioDelEnvio;
	char patente[7];
	float km;
	int isEmpty;
}eTransporte;

/// \fn int InicializarTransporte(eTransporte[], int)
/// \brief Inicializa la lista de transportes
/// \param listaTransportes lista que sera inicializada
/// \param tamanio tamanio de la lista a recorrer para inicializar
/// \return retorna -1 si la lista es nula o 0 si se logro inicializar
int InicializarTransporte(eTransporte listaTransportes[], int tamanio);

/// \fn int AltaTransporte(eTransporte[], int, eLocalidad[], int, int*)
/// \brief Da de alta un transporte
/// \param listaTransportes lista a ser recorrida en busca de espacio para crear el envio
/// \param tamanio tamanio de la lista a recorrer
/// \param listaLocalidades lista de localidades necesaria para que el usuario seleccione a donde quiere enviar el pedido
/// \param tamanioLocalidades tamnio de la lista de las localidaes
/// \param id puntero necesario para generar el nuevo id
/// \return retorna -1 si las listas son nulas o 0 si se logro realizar la lata
int AltaTransporte(eTransporte listaTransportes[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int *id);

/// \fn eTransporte UnTransporte(int*, eLocalidad[], int)
/// \brief Carga un transporte
/// \param id puntero con el que se generara el id
/// \param listaLocalidades lista que se mostrara para que el usuario seleccione la localidad a la que quiere enviar el pedido
/// \param tamanio tamanio de la lista localidades que sera recorrida
/// \return retorna un transporte con sus datos cargados
eTransporte UnTransporte(int* id, eLocalidad listaLocalidades[], int tamanio);

/// \fn void MostrarUnEnvio(eTransporte, eLocalidad)
/// \brief Muestra los datos de un solo transporte
/// \param unTransporte transporte del que se mostrararn los datos
/// \param unaLocalidad localidad que ayudara a completar los datos del transporte
void MostrarUnEnvio(eTransporte unTransporte, eLocalidad unaLocalidad);

/// \fn int MostrarListaDeEnvios(eTransporte[], int, eLocalidad[], int, int)
/// \brief Muestra la lista con todos los envios
/// \param listaTransportes lista de transportes de la que ser iran obteniendo cada uno de los trasnportes
/// \param tamanio tamanio de la lista de trasnportes a recorrer
/// \param listaLocalidades lista de las localidades necesaria para mostrar los datos de los trasnportes de forma comleta
/// \param tamanioLocalidades tamanio de la lista de las localidades
/// \param estado estado en el que deben estar los envios a mostrar
/// \return retorna -1 si las listas son nulas o 0 si se logro mostrar correctamente
int MostrarListaDeEnvios(eTransporte listaTransportes[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int estado);

/// \fn int CambiarEstadoTransporte(int, eTransporte[], int, int)
/// \brief cambia el estado del transporte
/// \param id id del transporte en el que se necesita hacer el cambio de estado
/// \param listaTransportes lista en la que se buscara el trasnporte con dicho id
/// \param tamanio tamnio de la lista a recorrer en buscra del id
/// \param estado estado al que se desea cambiar el transporte
/// \return retorna -1 si la lista es nula o 0 si se logro cambiar el estado
int CambiarEstadoTransporte(int id, eTransporte listaTransportes[], int tamanio, int estado);

/// \fn int BuscarPorIdTransporte(ePedido[], int, eTransporte)
/// \brief Busca la posicion en la que se encuentra el transporte recibido por parametro
/// \param listaPedidos lista de pedidos que se recorrera en busca del id del transporte solicitado
/// \param tamanio tamanio de la lista a recorrer
/// \param unTransporte transporte con el que se comparara su id
/// \return retorna -1 si la lista es nula o la posicion
int BuscarPorIdTransporte(ePedido listaPedidos[], int tamanio, eTransporte unTransporte);

#endif /* TRANSPORTE_H_ */
