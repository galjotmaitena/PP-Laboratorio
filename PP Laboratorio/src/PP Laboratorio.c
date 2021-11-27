/*
 ============================================================================
Galjot Maitena divB
 ============================================================================
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#include "Informes.h"

#define SIN_HACER -1
#define PENDIENTE 0
#define COMPLETADO 1

#define TAM 100

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	eEmpresa empresas[TAM];
	ePedido pedidos[TAM];
	eLocalidad localidades[TAM] = {{1, "Lomas de Zamora", FALSE},
								   {2, "Monte Grande", FALSE},
								   {3, "Pompeya", FALSE},
								   {4, "Caballito", FALSE},
								   {5, "San Vicente", FALSE}};
	eTransporte transportes[TAM];
	int id;
	int idPedido;
	int idTransporte;

	int flagAlta;
	int flagPedidoPendiente;
	int flagPedidoProcesado;

	id = 1000;
	idPedido = 2000;
	idTransporte = 150;

	flagAlta = 0;
	flagPedidoPendiente = 0;
	flagPedidoProcesado = 0;

	InicializarEmpresas(empresas, TAM);
	InicializarPedidos(pedidos, TAM);
	//InicializarLocalidad(localidades, TAM);
	InicializarTransporte(transportes, TAM);

	do
	{
		opcion = Menu("\n1. Alta de cliente.\n2. Modificar datos de cliente.\n3. Baja de cliente."
				"\n4. Crear pedidio de recoleccion.\n5. Procesar residuos."
				"\n6. Imprimir clientes con pedidos pendientes y cantidad de pedidos de recoleccion."
				"\n7. Imprimir pedidos pendientes.\n8. Imprimir pedidos procesados."
				"\n9. Pedidos pendientes en localidad.\n10. Promedio.\n11. Clientes con mas pedidos pendientes."
				"\n12. Clientes con mas pedidos completados"
				"\n13. Empresas con total de pedidos enviados, total a pagar y total de km a recorrer"
				"\n14. SALIR");

		switch(opcion)
		{
		case 1:
			printf("\nALTA de cliente");

			if(Alta(empresas, TAM, localidades, TAM, &id) == 0)
			{
				printf("\nEl id de la empresa sera %d\n", id);
				flagAlta = 1;
			}
			else
			{
				printf("\nNo se pudo dar de alta");
			}
			break;
		case 2:
			if(flagAlta == 1)
			{
				printf("\nMODIFICAR datos de cliente");

				if(Modificar(empresas, TAM, localidades, TAM) == 0)
				{

					printf("\nLa modificacion fue exitosa\n");
				}
				else
				{
					printf("\nNo se pudo realizar la modificacion");
				}
			}
			else
			{
				printf("\nPrimero debe dar de alta");
			}

			break;
		case 3:
			if(flagAlta == 1)
			{
				printf("\nBAJA de cliente");

				if(Baja(empresas, TAM, localidades, TAM) == -1)
				{

					printf("\nNo se pudo dar de baja");
				}
			}
			else
			{
				printf("\nPrimero debe dar de alta");
			}

			break;
		case 4:
			if(flagAlta == 1)
			{
				printf("\nCrear pedidio de recoleccion");

				if(CrearPedido(empresas, TAM, pedidos, TAM, localidades, TAM, transportes, TAM, &idTransporte, &idPedido) == -1)
				{
					printf("\nNo se pudo cargar el pedido");
				}
				else
				{
					flagPedidoPendiente = 1;
				}
			}
			else
			{
				printf("\nPrimero debe dar de alta");
			}
			break;
		case 5:
			if(flagPedidoPendiente == 1)
			{
				printf("\nProcesar residuos");
				if(ProcesarResiduos(pedidos, TAM, empresas, TAM, transportes, TAM) == -1)
				{
					printf("\nNo se pudo procesar el pedido");
				}
				else
				{
					flagPedidoProcesado = 1;
				}
			}
			else
			{
				printf("\nPrimero debe crear un pedido");
			}
			break;
		case 6:
			if(flagPedidoPendiente == 1)
			{
				printf("\nImprimir clientes con pedidos pendientes");

				if(ImprimirClientesConPedidosPendientes(pedidos, TAM, empresas, TAM, localidades, TAM) == -1)
				{
					printf("\nNo hay clientes con pedidos pendientes que mostrar");
				}
			}
			else
			{
				printf("\nPrimero debe crear un pedido");
			}
			break;
		case 7:
			if(flagPedidoPendiente == 1)
			{
				printf("\nImprimir pedidos pendientes");

				printf("\nPedidos Pendientes");
				if(ImprimirPedidos(pedidos, TAM, empresas, TAM, PENDIENTE) == -1)
				{
					printf("\nNo hay pedidos pendientes que mostrar");
				}
			}
			else
			{
				printf("\nPrimero debe crear un pedido");
			}

			break;
		case 8:
			if(flagPedidoProcesado == 1)
			{
				printf("\nImprimir pedidos procesados");

				printf("\nPedidos Completados");
				if(ImprimirPedidos(pedidos, TAM, empresas, TAM, COMPLETADO) == -1)
				{
					printf("\nNo hay pedidos procesados que mostrar");
				}
			}
			else
			{
				printf("\nPrimero debe procesar el pedido");
			}
			break;
		case 9:
			if(flagPedidoPendiente == 1)
			{
				printf("\nPedidos pendientes en localidad");

				if(BuscarPedidosPendientesPorLocalidad(pedidos, TAM, empresas, TAM, localidades, TAM) == -1)
				{
					printf("\nNo hay pedidos pendientes que mostrar en la localidad");
				}
			}
			else
			{
				printf("\nPrimero debe crear un pedido");
			}
			break;
		case 10:
			if(flagPedidoProcesado == 1)
			{
				printf("\nPromedio");
				if(ContarKilosDePP(pedidos, TAM, empresas, TAM) == -1)
				{
					printf("\nNo se pudo calcular el promedio de kilos de PP por cliente");
				}
			}
			else
			{
				printf("\nPrimero debe procesar un pedido");
			}
			break;
		case 11:
			if(flagPedidoPendiente == 1)
			{
				printf("\nCliente con mas pedidos pendientes");
				if(ClientesConMasPedidios(pedidos, TAM, empresas, TAM, localidades, TAM, PENDIENTE) == -1)
				{
					printf("\nNo se encontraron clientes con la mayor cantidad de pedidos pendientes");
				}
			}
			else
			{
				printf("\nPrimero debe crear un pedido");
			}
			break;
		case 12:
			if(flagPedidoProcesado == 1)
			{
				printf("\nCliente con mas pedidos completados");
				if(ClientesConMasPedidios(pedidos, TAM, empresas, TAM, localidades, TAM, COMPLETADO) == -1)
				{
					printf("\nNo se encontraron clientes con la mayor cantidad de pedidos completados");
				}
			}
			else
			{
				printf("\nPrimero debe procesar un pedido");
			}
			break;
		case 13:
			if(TotalDePedidosEnviados(pedidos, TAM, empresas, TAM, transportes, TAM, localidades, TAM) == -1)
			{
				printf("\nError");
			}
			break;
		case 14:
			printf("\nSALIR");
			break;
		default:
			printf("\nOpcion invalida");
		}
	}while(opcion != 14);

	return EXIT_SUCCESS;
}
