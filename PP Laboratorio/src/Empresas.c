/*
 * Empresas.c
 *
 *  Created on: 1 nov 2021
 *      Author: EXOSMART
 */

#include "Empresas.h"


int BuscarPorId(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades, char mensaje[])
{
	int retorno;
	int id;

	retorno = -1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0 && mensaje != NULL)
	{
		if(MostrarListaDeEmpresas(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades) == 1)
		{
			printf("\nAun no se hicieron altas");
		}
		else
		{
			IngresarEntero(mensaje, "\nID invalido", &id, 2);

			retorno = BuscarPosicion(listaEmpresas, tamanioEmpresas, id);
		}
	}

	return retorno;
}

int BuscarPosicion(eEmpresa lista[], int tamanio, int id)
{
	int retorno;
	int i;

	retorno = 1;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].id == id)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

//************************************************************************//

int BuscarPorIdPedido(ePedido listaPedido[], int tamanioPedido, char mensaje[], eEmpresa lista[], int tamanio)
{
	int retorno;
	int id;

	retorno = -1;

	if(lista != NULL && tamanio > 0 && mensaje != NULL)
	{
		if(MostrarListaDePedidos(listaPedido, tamanioPedido, lista, tamanio) == 1)
		{
			printf("\nAun no se hicieron altas");
		}
		else
		{
			IngresarEntero(mensaje, "\nID invalido", &id, 2);

			retorno = BuscarPosicionPedido(listaPedido, tamanioPedido, id);
		}
	}

	return retorno;
}

//************************************************************************//

int InicializarEmpresas(eEmpresa lista[], int tamanio)
{
	int i;
	int retorno;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			lista[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}

//************************************************************************//

int Alta(eEmpresa lista[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidad, int* idContador)
{
	int retorno;
	int i;

		retorno = -1;

	if(lista != NULL && tamanio > 0 && listaLocalidades != NULL && tamanio > 0 && idContador != NULL)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].isEmpty == TRUE)
			{
				MostrarListaLocalidades(listaLocalidades, tamanioLocalidad);

				lista[i] = UnaEmpresa(idContador);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

eEmpresa UnaEmpresa(int* idContador)
{
	eEmpresa unaEmpresa;

	if(idContador != NULL)
	{
		if(GenerarId(idContador) != -1)
		{
			unaEmpresa.id = *idContador;

			IngresarCadena(unaEmpresa.nombre, "\nIngrese el nombre de la empresa: ", "\nIngreso invalido", 51, 2); //X
			IngresarEntero("\nIngrese el cuit: ", "\nIngreso invalido", &unaEmpresa.cuit, 2);
			IngresarCadena(unaEmpresa.direccion.calle, "\nIngrese la calle: ", "\nIngreso invalido", 51, 2);
			IngresarEntero("\nIngrese numero del edificio: ", "\nIngreso invalido", &unaEmpresa.direccion.numero, 2);
			IngresarEntero("\nIngrese el id de la localidad de la empresa", "\nIngreso invalido", &unaEmpresa.idLocalidad, 2);


			unaEmpresa.isEmpty = FALSE;
		}
		else
		{
			printf("\nNo se pudo generar el id");
		}
	}

	return unaEmpresa;
}

//************************************************************************//

int MostrarListaDeEmpresas(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades)
{
	int retorno;
	int i;

	retorno = 1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		for(i = 0; i < tamanioEmpresas; i++)
		{
			if(listaEmpresas[i].isEmpty == FALSE)
			{
				MostrarUnaEmpresa(listaEmpresas[i], listaLocalidades, tamanioLocalidades);

				retorno = 0;
			}
		}
	}

	return retorno;
}

void MostrarUnaEmpresa(eEmpresa empresa, eLocalidad lista[], int tamanio)
{
	int index;

	if(lista != NULL && tamanio > 0)
	{
		index = BuscarLocalidadPorId(lista, tamanio, empresa.idLocalidad);

		if(index != -1)
		{
			printf("\n%d %s %d %s %d %s", empresa.id, empresa.nombre, empresa.cuit,
										empresa.direccion.calle, empresa.direccion.numero, lista[index].localidad);
		}
	}
}

int MostrarListaDePedidos(ePedido listaPedidos[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas)
{
	int retorno;
	int i;

	retorno = 1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaPedidos != NULL && tamanioPedido > 0)
	{
		for(i = 0; i < tamanioPedido; i++)
		{
			if(listaPedidos[i].isEmpty == PENDIENTE)
			{
				MostrarUnPedido(listaPedidos[i], listaEmpresas[i]);

				retorno = 0;
			}
		}
	}

	return retorno;
}

void MostrarUnPedido(ePedido pedido, eEmpresa empresa)
{
	printf("\n%s: %d %.2f", empresa.nombre, pedido.id, pedido.cantidadKilos);
}

//************************************************************************//

int Modificar(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades)
{
	int retorno;
	int index;
	int opcion;

	retorno = 1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		index = BuscarPorId(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades, "\nIngrese el ID de la empresa en la que quiere realizar una modificacion: ");

		if(index == -1)
		{
			printf("\nNo se encontro ningna empresa con ese id");
		}
		else
		{
			do
			{
				opcion = Menu("\n1. Direccion.\n2. Localidad.\n3. Direccion y localidad\n4. SALIR");

				switch(opcion)
				{
				case 1:
					if(ModificarDireccion(listaEmpresas, tamanioEmpresas, index) == 1)
					{
						printf("\nNo se pudo realizar la modificacion");
					}
					break;
				case 2:
					if(ModificarLocalidad(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades, index) == 1)
					{
						printf("\nNo se pudo realizar la modificacion");
					}
					break;
				case 3:
					if(ModificarDireccion(listaEmpresas, tamanioEmpresas, index) == 1)
					{
						printf("\nNo se pudo realizar la modificacion");
					}
					if(ModificarLocalidad(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades, index) == 1)
					{
						printf("\nNo se pudo realizar la modificacion");
					}
					break;
				case 4:
					printf("\nSALIR");
					break;
				default:
					printf("\nOpcion invalida");
				}
			}while(opcion != 4);

			MostrarUnaEmpresa(listaEmpresas[index], listaLocalidades, tamanioLocalidades);
		}
	}

	return retorno;
}

int ModificarDireccion(eEmpresa lista[], int tamanio, int index)
{
	int retorno;
	int i;
	char auxiliarCalle[51];
	int auxiliarNumero;

	retorno = 1;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].isEmpty == FALSE)
			{
				if(i == index)
				{
					IngresarCadena(auxiliarCalle, "\nIngrese la calle: ", "\nIngreso invalido", 51, 2);
					IngresarEntero("\nIngrese numero del edificio: ", "\nIngreso invalido", &auxiliarNumero, 2);

					strncpy(lista[i].direccion.calle, auxiliarCalle, 51);
					lista[i].direccion.numero = auxiliarNumero;

					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int ModificarLocalidad(eEmpresa listaEmpresas[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int index)
{
	int retorno;
	int i;
	int auxiliarLocalidad;

	retorno = 1;

	if(listaEmpresas != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(listaEmpresas[i].isEmpty == FALSE)
			{
				if(i == index)
				{
					MostrarListaLocalidades(listaLocalidades, tamanioLocalidades);
					IngresarEntero("\nIngrese el id de la nueva localidad: ", "Dato invalido", &auxiliarLocalidad, 2);

					listaEmpresas[i].idLocalidad = auxiliarLocalidad;

					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

//************************************************************************//

int Baja(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades)
{
	int retorno;
	int index;

	retorno = 1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0)
	{
		index = BuscarPorId(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades, "\nIngrese el ID de la empresa a la que desea dar de baja: ");

		if(index == -1)
		{
			printf("\nNo se encontro ningna empresa con ese ID");
		}
		else
		{
			if(CambiarEstado(listaEmpresas, tamanioEmpresas, index) == 1)
			{
				printf("No se pudo dar de baja");
			}
			else
			{
				printf("\n***********************************************");
				MostrarListaDeEmpresas(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades);
				printf("\n***********************************************");
			}
		}
	}

	return retorno;
}

int CambiarEstado(eEmpresa lista[], int tamanio, int index)
{
	int retorno;
    int i;
    int opcion;

	retorno = 1;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].isEmpty == FALSE)
			{
				if(i == index)
				{
					IngresarEntero("\nIngrese 1 para confirmar la baja, o 0 para cancelarla: ", "Opcion invalida", &opcion, 2);

					if(opcion == 1)
					{
						lista[i].isEmpty = TRUE;
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

//************************************************************************//

int CrearPedido(eEmpresa listaEmpresas[], int tamanioEmpresas, ePedido listaPedido[], int tamanioPedido, eLocalidad listaLocalidades[], int tamanioLocalidades, int* id)
{
	int retorno;
	int index;
	int i;

	retorno = -1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaPedido != NULL && tamanioPedido > 0 && listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		index = BuscarPorId(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades, "\nIngrese el ID de la empresa en la que quiere agregar un pedido: ");

		for(i = 0; i < tamanioPedido; i++)
		{
			if(listaPedido[i].isEmpty == SIN_HACER)
			{
				if(IngresarCantidadDeKilosARecolectar(listaPedido, tamanioPedido, i, id) == 0)
				{
					//listaEmpresas[index].idPedido = *id;
					listaPedido[i].idEmpresa = listaEmpresas[index].id;

					printf("\n***********************************************************");
					MostrarUnPedido(listaPedido[i], listaEmpresas[index]);
					printf("\n***********************************************************");

					retorno = 0;

					break;
				}
			}
		}

	}

	return retorno;
}

//************************************************************************//

int ProcesarResiduos(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio)
{
	int retorno;
	int index;
	int retornoFuncion;

	retorno = -1;

	if(listaPedido != NULL && tamanioPedido > 0 && lista != NULL && tamanio > 0)
	{
		index = BuscarPorIdPedido(listaPedido, tamanio, "\nIngrese el ID del pedido que desea setear: ", lista, tamanio);

		do
		{
			retornoFuncion = IngresarCantidadDeKilosPorTipo(listaPedido, index);
		}while(retornoFuncion != 0);

		listaPedido[index].isEmpty = COMPLETADO;

		MostrarCantidadPorTipoDePlatico(listaPedido[index]);

		retorno = 0;
	}

	return retorno;
}

//************************************************************************//
//************************************************************************//
int ImprimirClientesConPedidosPendientes(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades)
{
	int retorno;
	int i;
	int index;
	int contador;

	retorno = -1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0 && listaPedido != NULL && tamanioPedido > 0)
	{
		printf("\nEmpresas con pedidos pendientes");

		printf("\n***********************************************************");

		for(i = 0; i < tamanioEmpresas; i++)
		{
			if(listaPedido[i].isEmpty == PENDIENTE)
			{
				index = BuscarEmpresa(listaEmpresas, tamanioEmpresas, listaPedido[i].idEmpresa);

				if(index != -1)
				{
					MostrarUnaEmpresa(listaEmpresas[index], listaLocalidades, tamanioLocalidades);
					ContarPedidos(listaPedido, tamanioPedido, listaEmpresas[index], PENDIENTE, &contador);
printf("\n%d",contador);
					retorno = 0;
				}
			}
		}


			printf("\nCantidad de pedidos de recoleccion: %d", contador);


		printf("\n***********************************************************");
	}

	return retorno;
}

int BuscarEmpresa(eEmpresa lista[], int tamanio, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].id == id)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

int ContarPedidos(ePedido listaPedido[], int tamanioPedido, eEmpresa unaEmpresa,int estado, int* contador)
{
	int retorno;
	int i;
	int contadorAuxiliar;

	retorno = -1;
	contadorAuxiliar = 0;

	if(listaPedido != NULL && tamanioPedido > 0)
	{
		for(i = 0; i < tamanioPedido; i++)
		{
			if(listaPedido[i].idEmpresa == unaEmpresa.id && listaPedido[i].isEmpty == estado)
			{
				contadorAuxiliar++;
				retorno = 0;
			}
		}

		*contador = contadorAuxiliar;
	}

	return retorno;
}
//************************************************************************//
//************************************************************************//
/*
int ImprimirClientesConPedidosPendientes(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades)
{
	int retorno;
	int i;
	int cantidadDePedidos;
	int index;

	retorno = -1;
	cantidadDePedidos = 0;

	if(listaPedido != NULL && tamanioPedido > 0 && listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		printf("\nEmpresas con pedidos pendientes");

		printf("\n***********************************************************");
		for(i = 0; i < tamanioEmpresas; i++)
		{
			index = BuscarEmpresasConPedidosPendientes(listaEmpresas, tamanioEmpresas, listaPedido[i].id);

			if(index != -1)
			{
				MostrarUnaEmpresa(listaEmpresas[index], listaLocalidades, tamanioLocalidades);
				retorno = 0;

				cantidadDePedidos++;
			}
		}

		if(cantidadDePedidos != 0)
		{
			printf("\nCantidad de pedidos de recoleccion: %d", cantidadDePedidos);
		}

		printf("\n***********************************************************");
	}

	return retorno;
}



int BuscarEmpresasConPedidosPendientes(eEmpresa lista[], int tamanio, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(lista != NULL && tamanio > 0 && id > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].idPedido == id)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}


int ImprimirPedidos(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, int estado)
{
	int retorno;
	int i;
	int index;

	retorno = -1;

	if(listaPedido != NULL && tamanioPedido > 0 && lista != NULL && tamanio > 0)
	{
		printf("\n***********************************************************");
		for(i = 0; i < tamanio; i++)
		{
			if(listaPedido[i].isEmpty == estado)
			{
				index = BuscarEmpresasConPedidosPendientes(lista, tamanio, listaPedido[i].id);

				if(index != -1)
				{
					printf("\n%d %d %s %.2f", lista[index].cuit, lista[index].direccion.numero, lista[index].direccion.calle, listaPedido[i].cantidadKilos);
					retorno = 0;
				}
			}
		}

		printf("\n***********************************************************");
	}

	return retorno;
}



int BuscarPedidosPendientesPorLocalidad(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades)
{
	int retorno;
	int i;
	int index;
	int auxiliarId;
	int cantidadDePedidosPendientes;

	retorno = -1;

	if(listaPedido != NULL && tamanioPedido > 0 && listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		BuscarPorLocalidad(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades, &auxiliarId);

		printf("\n***********************************************************");
		for(i = 0; i < tamanioEmpresas; i++)
		{
			index = BuscarEmpresasConPedidosPendientes(listaEmpresas, tamanioEmpresas, listaPedido[i].id);

			if(auxiliarId == listaEmpresas[index].idLocalidad)
			{
				cantidadDePedidosPendientes++;
			}
		}
		if(cantidadDePedidosPendientes != 0)
		{
			printf("\nCantidad de pedidos de recoleccion: %d", cantidadDePedidosPendientes);
			retorno = 0;
		}

			printf("\n***********************************************************");
	}

		return retorno;
}

int BuscarPorLocalidad(eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades,int* idLocalidad)
{
	int retorno;
	int auxiliarId;

	retorno = -1;

	if(listaEmpresas != NULL && tamanioEmpresas > 0)
	{
		MostrarListaLocalidades(listaLocalidades, tamanioLocalidades);

		IngresarEntero("\nIngrese el id de la localidad que desea revisar: ", "\nIngreso invalido", &auxiliarId, 2);

		*idLocalidad = auxiliarId;

		retorno = 0;
	}

	return retorno;
}
*/
