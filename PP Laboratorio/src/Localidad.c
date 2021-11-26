#include "Localidad.h"

int InicializarLocalidad(eLocalidad lista[], int tamanio)
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

int MostrarUnaLocalidad(eLocalidad unaLocalidad)
{
	int retorno;

	retorno = -1;

	printf("\n%d %s", unaLocalidad.idLocalidad, unaLocalidad.localidad);

	return retorno;
}

int MostrarListaLocalidades(eLocalidad listaLocalidades[], int tamanio)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaLocalidades != NULL && tamanio > 0)
	{
		printf("\nLOCALIDADES");
		for(i = 0; i < tamanio; i++)
		{
			if(MostrarUnaLocalidad(listaLocalidades[i]) == 0)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

int ValidarId(eLocalidad listaLocalidades[], int tamanio, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaLocalidades != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(listaLocalidades[i].idLocalidad == id)
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int BuscarLocalidadPorId(eLocalidad listaLocalidades[], int tamanio, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaLocalidades != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(listaLocalidades[i].idLocalidad == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int BuscarPorIndice(eLocalidad listaLocalidades[], int tamanio, int index)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaLocalidades != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(i == index)
			{
				retorno = listaLocalidades[i].idLocalidad;
				break;
			}
		}
	}

	return retorno;
}

int PrecioYKmPorLocalidad(int id, float *precio, float *km)
{
	int retorno;
	float valorDelEnvio;
	float auxiliarKm;

	retorno = -1;

	if(precio != NULL && km != NULL)
	{
		switch(id)
		{
		case 1:
			valorDelEnvio = 900;
			auxiliarKm = 500;
			break;
		case 2:
			valorDelEnvio = 1100;
			auxiliarKm = 650;
			break;
		case 3:
			valorDelEnvio = 1300;
			auxiliarKm = 1000;
			break;
		case 4:
			valorDelEnvio = 100;
			auxiliarKm = 100;
			break;
		case 5:
			valorDelEnvio = 1950;
			auxiliarKm = 1500;
			break;
		}

		*precio = valorDelEnvio;
		*km = auxiliarKm;
		retorno = 0;
	}

	return retorno;
}
