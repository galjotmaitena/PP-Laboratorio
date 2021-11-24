/*
 ============================================================================
Galjot Maitena divB
 ============================================================================
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Empresas.h"

#define SIN_HACER -1
#define PENDIENTE 0
#define COMPLETADO 1

#define TAM 5

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
	int id;
	int idPedido;

	id = 1000;
	idPedido = 2000;

	InicializarEmpresas(empresas, TAM);
	InicializarPedidos(pedidos, TAM);
	//InicializarLocalidad(localidades, TAM);

	do
	{
		opcion = Menu("\n1. Alta de cliente.\n2. Modificar datos de cliente.\n3. Baja de cliente."
				"\n4. Crear pedidio de recoleccion.\n5. Procesar residuos."
				"\n6. Imprimir clientes con pedidos pendientes y cantidad de pedidos de recoleccion."
				"\n7. Imprimir pedidos pendientes.\n8. Imprimir pedidos procesados."
				"\n9. Pedidos pendientes en localidad.\n10. Promedio.\n11. SALIR.");

		switch(opcion)
		{
		case 1:
			printf("\nALTA de cliente");

			if(Alta(empresas, TAM, localidades, TAM, &id) == 0)
			{

				printf("\nEl id de la empresa sera %d\n", id);
			}
			else
			{
				printf("\nNo se pudo dar de alta");
			}
			break;
		case 2:
			printf("\nMODIFICAR datos de cliente");

			if(Modificar(empresas, TAM, localidades, TAM) == 0)
			{

				printf("\nLa modificacion fue exitosa\n");
			}
			else
			{
				printf("\nNo se pudo realizar la modificacion");
			}

			break;
		case 3:
			printf("\nBAJA de cliente");

			if(Baja(empresas, TAM, localidades, TAM) == 0)
			{

				printf("\nLa baja fue exitosa\n");
			}
			else
			{
				printf("\nNo se pudo dar de baja");
			}

			break;
		case 4:
			printf("\nCrear pedidio de recoleccion");

			if(CrearPedido(empresas, TAM, pedidos, TAM, localidades, TAM, &idPedido) == -1)
			{
				printf("No se pudo cargar el pedido");
			}
			break;
		case 5:
			printf("\nProcesar residuos");
			if(ProcesarResiduos(pedidos, TAM, empresas, TAM) == -1)
			{
				printf("No se pudo procesar el pedido");
			}
			break;
		case 6:
			printf("\nImprimir clientes");

			if(ImprimirClientesConPedidosPendientes(pedidos, TAM, empresas, TAM, localidades, TAM) == -1)
			{
				printf("No hay clientes con pedidos pendientes que mostrar");
			}

			break;
		case 7:
			printf("\nImprimir pedidos pendientes");

			printf("\nPedidos Pendientes");
			/*if(ImprimirPedidos(pedidos, TAM, empresas, TAM, PENDIENTE) == -1)
			{
				printf("No hay pedidos pendientes que mostrar");
			}*/
			break;
		case 8:
			printf("\nImprimir pedidos procesados");

			printf("\nPedidos Completados");
			//if(ImprimirPedidos(pedidos, TAM, empresas, TAM, COMPLETADO) == -1)
			//{
				//printf("No hay pedidos pendientes que mostrar");
			//}
			break;
		case 9:
			printf("\nPedidos pendientes en localidad");

			//if(BuscarPedidosPendientesPorLocalidad(pedidos, TAM, empresas, TAM, localidades, TAM) == -1)
			//{
				//printf("No hay pedidos pendientes que mostrar");
			//}
			break;
		case 10:
			printf("\nPromedio");
			break;
		case 11:
			printf("\nSALIR");
			break;
		default:
			printf("\nOpcion invalida");
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}
