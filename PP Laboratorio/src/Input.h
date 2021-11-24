/*
 * Input.h
 *
 *  Created on: 14 oct 2021
 *      Author: EXOSMART
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef INPUT_H_
#define INPUT_H_

int Menu(char opciones[]);

int IngresarCadena(char cadena[], char mensaje[], char mensajeError[], int tamanio, int reintentos);
int GetString(char cadena[], int tamanio);

int IngresarEntero(char mensaje[], char mensajeError[], int*resultado, int reintentos);
int GetInt(int* resultado);

int IngresarFlotante(char mensaje[], char mensajeError[], float*resultado, int reintentos);
int GetFloat(float* resultado);

int EsNumerico(char cadena[]);
int sonSoloLetras(char cadena[]);

int GenerarId(int* idContador);

#endif /* INPUT_H_ */
