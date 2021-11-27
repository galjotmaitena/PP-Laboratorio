#include "Pedidos.h"

int InicializarPedidos(ePedido lista[], int tamanio)
{
	int i;
	int retorno;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			lista[i].isEmpty = SIN_HACER;
			retorno = 0;
		}
	}

	return retorno;
}

int AltaPedidos(ePedido listaPedido[], int tamanioPedido, int index, int*id)
{
	int retorno;

	retorno = -1;

	if(listaPedido != NULL && tamanioPedido > 0 && id != NULL)
	{
		if(IngresarFlotante("\nIngrese la cantidad de kilos a recolectar: ", "Ingreso invalido", &listaPedido[index].cantidadKilos, 2) == 0)
		{
			if(GenerarId(id) != -1)
			{
				listaPedido[index].id = *id;
				listaPedido[index].isEmpty = PENDIENTE;

				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo cargar el pedido");
			}
		}
	}
	return retorno;
}

int BuscarPosicionPedido(ePedido lista[], int tamanio, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].isEmpty == PENDIENTE)
			{
				if(lista[i].id == id)
				{
					retorno = i;
				}
			}
		}
	}

	return retorno;
}

int IngresarCantidadDeKilosPorTipo(ePedido listaPedido[], int index)
{
	int retorno;
	float total;

	retorno = -1;

	if(listaPedido != NULL)
	{
		IngresarFlotante("\nIngrese la cantidad de kilos de HDPE: ", "Ingreso invalido", &listaPedido[index].tiposDePlastico.hdpe, 2);
		IngresarFlotante("\nIngrese la cantidad de kilos de LDPE: ", "Ingreso invalido", &listaPedido[index].tiposDePlastico.ldpe, 2);
		IngresarFlotante("\nIngrese la cantidad de kilos de PP: ", "Ingreso invalido", &listaPedido[index].tiposDePlastico.pp, 2);

		total = listaPedido[index].tiposDePlastico.hdpe + listaPedido[index].tiposDePlastico.ldpe + listaPedido[index].tiposDePlastico.pp;

		if(total == listaPedido[index].cantidadKilos)
		{
			retorno = 0;
		}
	}

	return retorno;
}

void MostrarCantidadPorTipoDePlatico(ePedido pedido)
{
	printf("\n************************************************************************************");
	printf("\nHDPE: %-8.2f \nLDPE: %-8.2f \nPP: %-8.2f", pedido.tiposDePlastico.hdpe,
												   	   	 pedido.tiposDePlastico.ldpe,
														 pedido.tiposDePlastico.pp);
	printf("\n************************************************************************************");
}
