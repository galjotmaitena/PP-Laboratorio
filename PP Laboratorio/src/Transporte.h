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

int InicializarTransporte(eTransporte listaTransportes[], int tamanio);
int CargaDelTransporte(eTransporte listaTransportes[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int *id);
eTransporte UnTransporte(int* id, eLocalidad listaLocalidades[], int tamanio);
void MostrarUnEnvio(eTransporte unTransporte, eLocalidad unaLocalidad);
int MostrarListaDeEnvios(eTransporte listaTransportes[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int estado);
int CambiarEstadoTransporte(int id, eTransporte listaTransportes[], int tamanio, int estado);
int BuscarPorIdTransporte(ePedido listaPedidos[], int tamanio, eTransporte unTransporte);

#endif /* TRANSPORTE_H_ */
