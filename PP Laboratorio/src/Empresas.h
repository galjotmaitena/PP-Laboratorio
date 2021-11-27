#include <stdio.h>
#ifndef EMPRESAS_H_
#define EMPRESAS_H_

#include "Input.h"

#define TAM 100

#define TRUE 0
#define FALSE 1

#include "Pedidos.h"
#include "Localidad.h"
#include "Transporte.h"

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

/// \fn int InicializarEmpresas(eEmpresa[], int)
/// \brief  Inicializa la lista de empresas como vacia
/// \param lista lista a recorrer e inicializar
/// \param tamanio tamanio de la lista a recorrer
/// \return retorna (-1) si la lista era nula o 0 si se pudo inicializar correctamente
int InicializarEmpresas(eEmpresa lista[], int tamanio);

/// \fn int Alta(eEmpresa[], int, eLocalidad[], int, int*)
/// \brief  Da de alta una empresa
/// \param lista Lista en la que se guardaran los daatos de dicha empresa
/// \param tamanio tamanio de la lista
/// \param listaLocalidades lista de las localidades a elegir
/// \param tamanioLocalidad tamanio de la lista de localidades
/// \param idContador contador que se utilizara para obtener el id de la nueva empresa
/// \return retorna (-1) si la lista es nula o no se encontro espacio disponible, y 0 si se pudo dar de alta una empresa
int Alta(eEmpresa lista[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidad, int* idContador);
/// \fn eEmpresa UnaEmpresa(eLocalidad[], int, int*)
/// \brief Carga los datos de una empresa y la devuelve
/// \param listaLocalidades lista de localidades que se mostrara para que el usuario seleccione una de estas
/// \param tamanioLocalidad tamanio de la lista de las localidades
/// \param idContador contador que se utilizara para obtener el id de la nueva empresa
/// \return retorna una empresa con los datos ya cargados
eEmpresa UnaEmpresa(eLocalidad listaLocalidades[], int tamanioLocalidad, int* idContador);

/// \fn int Modificar(eEmpresa[], int, eLocalidad[], int)
/// \brief Modifica la direccion, localidad o ambas, de una empresa seleccionada por el usuario
/// \param listaEmpresas lista de empresas de la que se obtendra la posicion de la empresa requerida
/// \param tamanioEmpresas tamanio d la lista de empresas
/// \param listaLocalidades lista de localidades, que sera mostrada para que el usuario seleccione la nueva localidad
/// \param tamanioLocalidades tamanio de la lista de localidades
/// \return retorna 1 si la lista es nula, o 0 si se pudo realizar la modificacion
int Modificar(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
/// \fn void ModificarDireccion(eEmpresa)
/// \brief Modifica la direccion de la empresa recibida
/// \param unaEmpresa empresa en la que se realizara la modificacion
void ModificarDireccion(eEmpresa unaEmpresa);
/// \fn int ModificarLocalidad(eEmpresa, eLocalidad[], int)
/// \brief Modifica la localidad de la empresa recibida
/// \param unaEmpresa empresa en la que se realizara la modificacion
/// \param listaLocalidades lista de localidades que se mostrara para que se seleccione la nueva localidad
/// \param tamanioLocalidades tamanio de la lista de localidades
/// \return retorna 1 si la lista es nula o 0 si se realizao la modificacion correctamente
int ModificarLocalidad(eEmpresa unaEmpresa, eLocalidad listaLocalidades[], int tamanioLocalidades);

/// \fn void CambiarEstado(eEmpresa)
/// \brief Cambia el estado de una empresa
/// \param unaEmpresa empresa a la que se le cambiara el estado
void CambiarEstado(eEmpresa unaEmpresa);
/// \fn int Baja(eEmpresa[], int, eLocalidad[], int)
/// \brief Da de baja una empresa
/// \param listaEmpresas lista de empresas en la que buscara a la empresa a la que se desea dar de baja
/// \param tamanioEmpresas tamanio de la lista de empresas
/// \param listaLocalidades lista de localidades necesaria para mostrar las empresas que no se dieron de baja
/// \param tamanioLocalidades tamanio de la lista de localidades
/// \return retorna 1 si las listas son nulas y 0 si se pudo dar de baja
int Baja(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);

/// \fn int CrearPedido(eEmpresa[], int, ePedido[], int, eLocalidad[], int, eTransporte[], int, int*, int*)
/// \brief Crea un pedido para una empresa
/// \param listaEmpresas lista que se mostrara y de la cual el usuario eligira una en la que quiere realizar el pedido
/// \param tamanioEmpresas tamanio de la lista de empresas
/// \param listaPedido lista de pedidos, en la cual se buscara un espacion disponible y se guardara el pedido
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param listaLocalidades lista de localidades necesaria para dar de alta el envio
/// \param tamanioLocalidades tamnio de la lista de localdades
/// \param listaTransportes lista de transportes en la cual se buscara espacio para crear el envio
/// \param tamanioTransportes tamanio de la lista de transportes
/// \param idTransporte puntero con el que obtendremos el id del envio
/// \param idPedido puntero con el que obtendremos el id del pedido
/// \return retorna -1 si las listas son nulas y 0 si se pudo crear el pedido correctamente
int CrearPedido(eEmpresa listaEmpresas[], int tamanioEmpresas, ePedido listaPedido[], int tamanioPedido, eLocalidad listaLocalidades[], int tamanioLocalidades, eTransporte listaTransportes[], int tamanioTransportes, int* idTransporte, int* idPedido);

/// \fn int ProcesarResiduos(ePedido[], int, eEmpresa[], int, eTransporte[], int)
/// \brief Completa el proceso del pedido, pidiendo el ingreso de los kilos de cada tipo de plastico que vienen en el pedido
/// \param listaPedido lista de pedidos en la que se buscara el pedido que quiero completar
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param lista lista de empresas necesaria para mostrar la lista de pedidos
/// \param tamanio tamanio de la lista de empresas
/// \param listaTransportes lista de transportes necesaria para cambiar el estado del envio
/// \param tamanioTransportes tamanio de la lista de transportes
/// \return retorna -1 si las listas son nulas o 0 si se pudo procesar correctamente el pedido
int ProcesarResiduos(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, eTransporte listaTransportes[], int tamanioTransportes);

/// \fn int ValidarIdEmpresas(eEmpresa[], int, int*, char*)
/// \brief Pide un id al usuario y valida que el id sea valido, es decir que exista una empresa con ese id
/// \param listaEmpresas lista en la que se buscara el id
/// \param tamanioEmpresas tamanio de la lista, necesario para recorrerla
/// \param id puntero en el que se guardara el id ingresado, si es correcto
/// \param mensaje mensaje que se mostrarara para indicar al usuario porque debe elegir un id
/// \return retorna -1 si la lista es nula o 0 si se realizo correctamente la modificacion
int ValidarIdEmpresas(eEmpresa listaEmpresas[], int tamanioEmpresas, int* id, char* mensaje);
/// \fn int BuscarPosicion(eEmpresa[], int, int)
/// \brief Busca la posicion de una empresa
/// \param lista lista en la que se buscara la posicion, a traves de la comparacion de id
/// \param tamanio tamanio de la lista de empresas a recorrer
/// \param id id con el que se comparara
/// \return retorna retorna 1 si la lista es nula o no es encontro la posicion o la posicion de la empresa si la operacion fue correcta
int BuscarPosicion(eEmpresa lista[], int tamanio, int id);
/// \fn int BuscarPorId(eEmpresa[], int, eLocalidad[], int, char[])
/// \brief Muestra la lista de empresas, pide el ingreso del id de la empresa requerida y luego se busca la posicion en la que se encuentra esa empresa
/// \param listaEmpresas lista de empresas que se reocrrera para mostrar las empresas y para buscar la posicion
/// \param tamanioEmpresas tamanio de la lista de empresas
/// \param listaLocalidades lista de localidades necesaria para mostrar la informacion de las mpresas
/// \param tamanioLocalidades tamnio de la lista de localidades
/// \param mensaje mensaje que se le mostrara al usuario para seleccionar el id requerido
/// \return retorna retorna retorna 1 si la lista es nula o no es encontro la posicion o la posicion de la empresa si la operacion fue correcta
int BuscarPorId(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades, char mensaje[]);
/// \fn int BuscarPorIdPedido(ePedido[], int, char[], eEmpresa[], int)
/// \brief Muestra la lista de pedidos, pide que se seleccione uno, lo valida y busca la posicion del mismo
/// \param listaPedido lista de pedidos a recorrer para mostrarlos
/// \param tamanioPedido tamanio de la lista de pedidos a recorrer
/// \param mensaje mensaje que se le mostrarar al usuario con el motivo de seleccion del id
/// \param lista lista de empresas necesaria para mostrar los datos del pedido
/// \param tamanio tamanio de la lista de empresas
/// \return retorna -1 si las listas son nulas o la posicion en la que se encuentra el pedido
int BuscarPorIdPedido(ePedido listaPedido[], int tamanioPedido, char mensaje[], eEmpresa lista[], int tamanio);

/// \fn int MostrarListaDeEmpresas(eEmpresa[], int, eLocalidad[], int)
/// \brief Muestra la lista de empresas
/// \param listaEmpresas lista de empresas a recorrer para ir mostrando cada una de ellas
/// \param tamanioEmpresas tamnio de la lista de empresas necesaria para recorer la lista
/// \param listaLocalidades lista de localidades, necesaria para mostrar toda la informacion de la empresa
/// \param tamanioLocalidades tamanio de la lista de localidades a recorrer
/// \return retorna 1 si las listas son nulas o 0 si se pudo mostrar correctamente
int MostrarListaDeEmpresas(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades);
/// \fn void MostrarUnaEmpresa(eEmpresa, eLocalidad[], int)
/// \brief Muestra los datos de una empresa
/// \param empresa Empresa de la que se mostrara la informacion
/// \param lista lista de localidades necesaria para mostrar la informacion completa de la empresa
/// \param tamanio tamanio de la lista de localidades
void MostrarUnaEmpresa(eEmpresa empresa, eLocalidad lista[], int tamanio);

/// \fn int MostrarListaDePedidos(ePedido[], int, eEmpresa[], int)
/// \brief Muestra la lista de pedidos
/// \param listaPedidos lista de pedidios a recorrer para mostrar cada uno de estos
/// \param tamanioPedido tamnio de la lista de pedidos necesaria para recorrer la lista
/// \param lista lista de empresas necesaria para mostrar la informacion completa de los pedidos
/// \param tamanio tamanio de la lista de empresas
/// \return retorna 1 si las listas son nulas o 0 si se pudo mostrar todo correctamente
int MostrarListaDePedidos(ePedido listaPedidos[], int tamanioPedido, eEmpresa lista[], int tamanio);
/// \fn void MostrarUnPedido(ePedido, eEmpresa)
/// \brief Muestra los datos de un solo pedido
/// \param pedido pedido del que se mostraran los datos
/// \param empresa empresa que ayudara a completar los datos del pedido
void MostrarUnPedido(ePedido pedido, eEmpresa empresa);


#endif /* EMPRESAS_H_ */
