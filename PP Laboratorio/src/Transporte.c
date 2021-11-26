#include "Transporte.h"

int InicializarTransporte(eTransporte listaTransportes[], int tamanio)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaTransportes != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			listaTransportes[i].isEmpty = SIN_HACER;
			retorno = 0;
		}
	}

	return retorno;
}

int CargaDelTransporte(eTransporte listaTransportes[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int *id)
{
	int retorno;
	int i;
	int index;

	retorno = -1;

	if(listaTransportes != NULL && tamanio > 0 && listaLocalidades != NULL && tamanioLocalidades > 0 && id != NULL)
	{
		if(InicializarTransporte(listaTransportes, tamanio) == 0)
		{
			for(i = 0; i < tamanio; i++)
			{
				if(listaTransportes[i].isEmpty == SIN_HACER)
				{
					listaTransportes[i] = UnTransporte(id, listaLocalidades, tamanioLocalidades);
					index = BuscarLocalidadPorId(listaLocalidades, tamanioLocalidades, listaTransportes[i].idLocalidad);

					MostrarUnEnvio(listaTransportes[i], listaLocalidades[index]);

					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

eTransporte UnTransporte(int* id, eLocalidad listaLocalidades[], int tamanio)
{
	eTransporte unTransporte;
	float precio;
	float km;

	if(id != NULL && listaLocalidades != NULL && tamanio > 0)
	{
		if(GenerarId(id) != -1)
		{
			MostrarListaLocalidades(listaLocalidades, tamanio);

			unTransporte.id = *id;

			do
			{
				IngresarEntero("\nIngrese el id de la localidad de la empresa: ", "\nIngreso invalido", &unTransporte.idLocalidad, 2);
			}while(ValidarId(listaLocalidades, tamanio, unTransporte.idLocalidad) != 0);

			if(PrecioYKmPorLocalidad(unTransporte.idLocalidad, &precio, &km) == 0)
			{
				unTransporte.precioDelEnvio = precio;
				unTransporte.km = km;
			}
			IngresarCadenaAlfanumerica(unTransporte.patente, "\nIngrese la patente del transporte", "\nIngreso invalido", 7, 2);
			unTransporte.isEmpty = EN_PREPARACION;
		}
	}

	return unTransporte;
}

int CambiarEstadoTransporte(int id, eTransporte listaTransportes[], int tamanio, int estado)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaTransportes != NULL)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(listaTransportes[i].id == id)
			{
				listaTransportes[i].isEmpty = estado;
				printf("\nCAMBIADO");
			}
		}
		retorno = 0;
	}

	return retorno;
}

void MostrarUnEnvio(eTransporte unTransporte, eLocalidad unaLocalidad)
{
	printf("\n%d %s %.2f %.2f %s", unTransporte.id, unaLocalidad.localidad, unTransporte.precioDelEnvio,
								unTransporte.km, unTransporte.patente);
}

int MostrarListaDeEnvios(eTransporte listaTransportes[], int tamanio, eLocalidad listaLocalidades[], int tamanioLocalidades, int estado)
{
	int retorno;
	int i;
	int index;

	retorno = -1;

	if(listaTransportes != NULL && tamanio > 0 && listaLocalidades != NULL && tamanioLocalidades > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(listaTransportes[i].isEmpty == estado)
			{
				index = BuscarLocalidadPorId(listaLocalidades, tamanioLocalidades, listaTransportes[i].idLocalidad);
				MostrarUnEnvio(listaTransportes[i], listaLocalidades[index]);
			}
		}
	}

	return retorno;
}

int BuscarPorIdTransporte(ePedido listaPedidos[], int tamanio, eTransporte unTransporte)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaPedidos != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(listaPedidos[i].idTransporte == unTransporte.id)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}
