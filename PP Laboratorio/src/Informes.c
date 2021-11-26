#include "Informes.h"

int ImprimirClientesConPedidosPendientes(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas, eLocalidad listaLocalidades[], int tamanioLocalidades)
{
	int retorno;
	int i;
	int acumulador;
	int contador;

	retorno = -1;
	contador = 0;
	acumulador = 0;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0 && listaPedido != NULL && tamanioPedido > 0)
	{
		printf("\nEmpresas con pedidos pendientes");

		printf("\n***********************************************************");

		MostrarListaDeEmpresas(listaEmpresas, tamanioEmpresas, listaLocalidades, tamanioLocalidades);

		for(i = 0; i < tamanioEmpresas; i++)
		{
			if(listaEmpresas[i].isEmpty == FALSE)
			{
				Contador(listaEmpresas[i], listaPedido, tamanioPedido, &contador, PENDIENTE);

				acumulador+= contador;
			}
		}
			printf("\nCantidad de pedidos de recoleccion: %d", acumulador);

			retorno = 0;

			printf("\n***********************************************************");
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
				index = BuscarPosicion(lista, tamanio, listaPedido[i].idEmpresa);

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
	int auxiliarId;
	int contadorPedidosPendientes;
	int acumulador;

	retorno = -1;
	contadorPedidosPendientes = 0;
	acumulador = 0;

	if(listaPedido != NULL && tamanioPedido > 0 && listaEmpresas != NULL && tamanioEmpresas > 0 && listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		BuscarPorLocalidad(listaLocalidades, tamanioLocalidades, &auxiliarId);

		printf("\n***********************************************************");
		for(i = 0; i < tamanioEmpresas; i++)
		{
			if(listaEmpresas[i].isEmpty == FALSE && listaEmpresas[i].idLocalidad == auxiliarId)
			{
				if(Contador(listaEmpresas[i], listaPedido, tamanioPedido, &contadorPedidosPendientes, PENDIENTE) == 0)
				{
					acumulador+= contadorPedidosPendientes;
				}
			}
		}

		if(acumulador != 0)
		{
			printf("\nCantidad de pedidos de pendeinetes: %d", acumulador);
			retorno = 0;
		}
		else
		{
			printf("\nNo hay pedidos pendientes en la localidad seleccionada");
		}

			printf("\n***********************************************************");
	}

		return retorno;
}

int BuscarPorLocalidad(eLocalidad listaLocalidades[], int tamanioLocalidades,int* idLocalidad)
{
	int retorno;
	int auxiliarId;

	retorno = -1;

	if(listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		MostrarListaLocalidades(listaLocalidades, tamanioLocalidades);

		do
		{
			IngresarEntero("\nIngrese el id de la localidad que desea revisar: ", "\nIngreso invalido", &auxiliarId, 2);
		}while(ValidarId(listaLocalidades, tamanioLocalidades, auxiliarId));

		*idLocalidad = auxiliarId;

		retorno = 0;
	}

	return retorno;
}

int ContarKilosDePP(ePedido listaPedido[], int tamanioPedido, eEmpresa listaEmpresas[], int tamanioEmpresas)
{
	int retorno;
	int i;
	int j;
	float acumulador;
	int contador;
	float promedio;

	retorno = -1;
	acumulador = 0;
	contador = 0;

	if(listaEmpresas != NULL && tamanioEmpresas > 0 && listaPedido != NULL && tamanioPedido > 0)
	{
		for(i = 0; i < tamanioPedido; i++)
		{
			if(listaEmpresas[i].isEmpty == FALSE)
			{
				for(j = 0; j < tamanioPedido; j++)
				{
					if(listaPedido[j].isEmpty == COMPLETADO && listaPedido[j].idEmpresa == listaEmpresas[i].id && listaPedido[j].tiposDePlastico.pp > 0)
					{
						contador++;
						acumulador+= listaPedido[j].tiposDePlastico.pp;
					}
				}
			}
		}

		if(contador > 0)
		{
			promedio = (float)acumulador / contador;

			printf("\nEl promedio de PP reciclado es %f", promedio);

			retorno = 0;
		}
	}

	return retorno;
}

int ClientesConMasPedidios(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, eLocalidad listaLocalidad[], int tamanioLocalidad, int estado)
{
	int retorno;
	int i;
	int contador;
	int contadorAuxiliar;

	retorno = -1;

	contador = 0;
	contadorAuxiliar = 0;

	if(listaPedido != NULL && tamanioPedido > 0 && lista != NULL && tamanio > 0 && listaLocalidad != NULL && tamanioLocalidad > 0)
	{
		if(MaximoContador(listaPedido, tamanioPedido, lista, tamanio, estado, &contador) == 0)
		{
			for(i = 0; i < tamanio; i++)
			{
				if(lista[i].isEmpty == FALSE)
				{
					if(Contador(lista[i], listaPedido, tamanioPedido, &contadorAuxiliar, estado) == 0)
					{
						if(contadorAuxiliar == contador)
						{
							MostrarUnaEmpresa(lista[i], listaLocalidad, tamanioLocalidad);
						}
					}
				}
			}
			printf("\nTienen %d pedidos.", contador);
		}
		retorno = 0;
	}

	return retorno;
}

int MaximoContador(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, int estado, int* contador)
{
	int retorno;
	int contadorAuxiliar;
	int contadorFuncion;
	int i;

	retorno = -1;

	contadorAuxiliar = 0;
	contadorFuncion = 0;

	if(listaPedido != NULL && tamanioPedido > 0 && lista != NULL && tamanio > 0 && contador != NULL)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].isEmpty == FALSE)
			{
				if(Contador(lista[i], listaPedido, tamanioPedido, &contadorAuxiliar, estado) == 0)
				{
					if(contadorAuxiliar > contadorFuncion)
					{
						contadorFuncion = contadorAuxiliar;
					}
				}
			}
		}
		*contador = contadorFuncion;
		retorno = 0;
	}



	return retorno;
}

int Contador(eEmpresa unaEmpresa, ePedido listaPedido[], int tamanioPedido, int* contador, int estado)
{
	int retorno;
	int contadorAuxiliar;
	int i;

	retorno = -1;
	contadorAuxiliar = 0;

	if(listaPedido != NULL && tamanioPedido > 0 && contador != NULL)
	{
		for(i = 0; i < tamanioPedido; i++)
		{
			if(listaPedido[i].isEmpty == estado && listaPedido[i].idEmpresa == unaEmpresa.id)
			{
				contadorAuxiliar++;
			}
		}

		*contador = contadorAuxiliar;
		retorno = 0;
	}

	return retorno;
}



int EmpresasConPedidosEnviados(ePedido listaPedido[], int tamanioPedido, eEmpresa lista[], int tamanio, eTransporte listaTransportes[], int tamanioTransportes, eLocalidad listaLocalidad[], int tamanioLocalidad)
{
	int retorno;
	int i;
	float acumuladorKm;
	float acumuladorPrecio;
	int contadorPedidos;

	retorno = -1;

	if(listaPedido != NULL && tamanioPedido > 0 && lista != NULL && tamanio > 0 && listaTransportes != NULL && tamanioTransportes > 0 && listaLocalidad != NULL && tamanioLocalidad > 0)
	{
		for(i = 0; i < tamanio; i++ )
		{
			if(lista[i].isEmpty == FALSE)
			{
				if(BuscarPedidosDeUnaEmpresa(lista[i], listaPedido, tamanioPedido, listaTransportes, tamanioTransportes, &acumuladorKm, &acumuladorPrecio, &contadorPedidos) == 0)
				{
					MostrarUnaEmpresa(lista[i], listaLocalidad, tamanioLocalidad);

					printf("\nCantidad de pedidos enviados: %d", contadorPedidos);
					printf("\nSuma de los km recorridos para los envios de la empresa: %.2f", acumuladorKm);
					printf("\nTotal a pagar por todos los enviados: %.2f", acumuladorPrecio);
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int BuscarPedidosDeUnaEmpresa(eEmpresa unaEmpresa, ePedido listaPedido[], int tamanioPedido, eTransporte listaTransportes[], int tamanioTransportes, float* acumuladorKm, float* acumuladorPrecio, int* contadorPedidos)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaPedido != NULL && tamanioPedido > 0 && listaTransportes != NULL && tamanioTransportes > 0 && acumuladorKm != NULL && acumuladorPrecio != NULL && contadorPedidos != NULL)
	{
		for(i = 0; i < tamanioPedido; i++)
		{
			if(listaPedido[i].isEmpty == COMPLETADO && listaPedido[i].idEmpresa == unaEmpresa.id)
			{
				if(TotalKmyPrecioDeUnaEmpresa(listaPedido[i], listaTransportes, tamanioTransportes, acumuladorKm, acumuladorPrecio, contadorPedidos) == 0)
				{
					printf("\nKM %.2f", *acumuladorKm);
					printf("\nPRECIO %.2f", *acumuladorPrecio);
					printf("\nTOTAL PEDIDOS %d", *contadorPedidos);
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int TotalKmyPrecioDeUnaEmpresa(ePedido unPedido, eTransporte listaTransportes[], int tamanioTransportes, float* acumuladorKm, float* acumuladorPrecio, int* contadorPedidos)
{
	int retorno;
	int i;
	int contadorAuxiliar;
	float acumuladorKmAuxiliar;
	float acumuladorPrecioAuxiliar;

	retorno = -1;

	contadorAuxiliar = 0;
	acumuladorKmAuxiliar = 0;
	acumuladorPrecioAuxiliar = 0;

	if(listaTransportes != NULL && tamanioTransportes > 0 && acumuladorPrecio != NULL && acumuladorKm != NULL && contadorPedidos != NULL)
	{
		for(i = 0; i < tamanioTransportes; i++)
		{
			if(listaTransportes[i].isEmpty == ENVIADO && listaTransportes[i].id == unPedido.idTransporte)
			{
				contadorAuxiliar++;

				acumuladorKmAuxiliar+= listaTransportes[i].km;
				acumuladorPrecioAuxiliar+= listaTransportes[i].precioDelEnvio;

				retorno = 0;
			}
		}

		*acumuladorKm = acumuladorKmAuxiliar;
		*acumuladorPrecio = acumuladorPrecioAuxiliar;

		*contadorPedidos = contadorAuxiliar;

		printf("\nKM %.2f", acumuladorKmAuxiliar);
		printf("\nPRECIO %.2f", acumuladorPrecioAuxiliar);
		printf("\nTOTAL PEDIDOS %d", contadorAuxiliar);
	}

	return retorno;
}
