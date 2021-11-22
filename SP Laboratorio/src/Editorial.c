#include "Editorial.h"
#include "Input.h"


eEditorial* publisher_new()
{
	eEditorial* pEditorial;

	pEditorial = (eEditorial*)malloc(sizeof(eEditorial));

	if(pEditorial == NULL)
	{
		exit(EXIT_FAILURE) ;
	}

	return pEditorial;
}

eEditorial* publisher_newParametros(char* idStr,char* nombreStr)
{
	eEditorial *pEditorial;

	pEditorial = publisher_new();

	if (pEditorial != NULL && idStr != NULL && nombreStr != NULL)
	{
		if(EsNumerico(idStr) == 0)
		{
			publisher_setId(pEditorial, atoi(idStr));
		}
		else
		{
			printf("\nERROR id.");
		}

		if(sonSoloLetras(nombreStr) == 0)
		{
			publisher_setNombre(pEditorial, nombreStr);
		}
		else
		{
			printf("\nERROR.");
		}
	}

	return pEditorial;
}

void publisher_delete(eEditorial* this)
{
	if(this != NULL)
	{
	    free(this);
	}
}

//************************************************************************

int publisher_setId(eEditorial* this,int id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id > 0)
	{
		this->idEditorial = id;
		retorno = 0;
	}

	return retorno;
}
int publisher_getId(eEditorial* this,int* id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int publisher_setNombre(eEditorial* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}

	return retorno;
}
int Publisher_GetNombre(eEditorial* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

