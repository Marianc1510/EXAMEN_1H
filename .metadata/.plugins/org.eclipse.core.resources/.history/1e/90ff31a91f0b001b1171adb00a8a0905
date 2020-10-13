/*
 * utN.c
 *
 *  Created on: 22 sep. 2020
 *      Author: mariana
 */

#include "utN.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define LONG_NOMBRE 50

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int esNumeroDecimal(char* cadena);
static int getFloat(float* pResultado);
static int esNombre(char* cadena, int limite);
static int getString(char* cadena, int limite);
static int esSoloCaracter(char* pResultado);
static int getEmail(char* cadena, int limite);
static int esEmail(char* cadena, int limite);
static int esNumeroAdicional(char* cadena);
static int getNumeroAdicional(int* pResultado);

/*
 *\brief myGets: lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un
 *\				maximo de 'longitud -1'cadacteres
 *\param char cadena,cadena de caracteres a ser analizada
 *\param int longitud, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena)
    {
		__fpurge(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno =0;
    }
    return retorno;
}
/*
 *\brief getInt: verifica si la cadena ingresa es numerica de enteros
 *\param int pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[4096];
    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
    	{
			retorno  = 0;
			*pResultado = atoi(buffer);
    	}
    }
    return retorno;
}
/*
 *\brief getFloat: verifica si la cadena ingresa es numerica con decimales
 *\param float pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */

static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumeroDecimal(buffer))
		{
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}
static int getNumeroAdicional(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumeroAdicional(buffer))
		{
			retorno = 0;
			*pResultado = atoi(buffer);
		}
	}
	return retorno;
}
/*
 *\brief esNumerica: verifica si la cadena ingresa es numerica
 *\param char cadena,cadena de caracteres a ser analizada
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */


static int esNumerica(char* cadena)
{
  int i=0;
  int retorno =-1;
  if(cadena != NULL && strnlen(cadena,sizeof(cadena)) > 0)
  {
	while(cadena[i] != '\0')
	{
		if(cadena[0] == '-' || cadena[0] == '+')
		{
			continue;
		}
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno =0;
			break;
		}
		i++;
	}
   }
   return retorno;
}
/*
 *\brief esNumeroDecimales: verifica si la cadena ingresa es numerica con decimales
 *\param char* cadena, cadena de caracteres a ser analizada
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int esNumeroDecimal(char* cadena)
{
	int i =0;
	int retorno = -1;
	if(cadena != NULL && strnlen(cadena,sizeof(cadena)) > 0)
	{
		while(cadena[i] !='\0')
		{
			if(cadena[0] == '-' || cadena[0] == '+' || cadena[i] == '.')
					{
						continue;
					}
					if(cadena[i] < '0' || cadena[i] > '9')
					{
						retorno =0;
						break;
					}
					i++;
		}
	}
	return retorno;
}
/*
 *\brief getString: verifica si la cadena ingresa son solo letras
 *\param char* cadena,puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param int limite, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getString(char* cadena, int limite)
{
	char buffer[4096];
	int retorno =-1;
	if(cadena !=NULL && limite > 0)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)))
		{
			retorno  = 0;
			strncpy(cadena,buffer,limite);
		}
	}
	return retorno;
}
/*
 *\brief getCaracter: verifica si la cadena ingresada son solo caracteres
 *\param char* cadena, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getCaracter(char* cadena)
{
	char buffer[4096];
	int retorno =-1;
	if(cadena !=NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esSoloCaracter(buffer))
		{
			retorno  = 0;
			strcpy(cadena,buffer);
		}
	}
	return retorno;
}
/*
 *\brief getEmail: verifica si la cadena ingresa son los caracteres permitidos para un email
 *\param char* cadena,puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param int limite, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getEmail(char* cadena, int limite)
{
	char buffer[4096];
	int retorno =-1;
	if(cadena !=NULL && limite > 0)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esEmail(buffer,sizeof(buffer)))
		{
			retorno  = 0;
			strncpy(cadena,buffer,limite);
		}
	}
	return retorno;
}
/*
 *\brief esSoloLetras: verifica si la cadena ingresa son solo letras
 *\param char* cadena,cadena de caracteres a ser analizada
 *\param int limite, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int esNombre(char* cadena, int limite)
{
	int respuesta = 1; //TODO OK
	for(int i;i<=limite && cadena[i]!='\0' ;i++)
	{
		if( (cadena[i]<'A'|| cadena[i]>'Z') &&
			(cadena[i]<'a'|| cadena[i]>'z') &&
			 cadena[i] != '.')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/*
 *\brief esSoloCaracter: verifica si el caracter ingresado es una letra
 *\param char* pResultado,Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int esSoloCaracter(char* pResultado)
{
	int i;
	int retorno =-1;
	if(pResultado != NULL && strnlen(pResultado,sizeof(pResultado)) > 0)
	  {
		while(pResultado[i] != '\0')
		{
			if((pResultado[i] < 'a' || pResultado[i] > 'z') &&
				(pResultado[i]<'A' || pResultado[i]>'Z'))
			{
				retorno =0;
				break;
			}
			i++;
		}
	   }
	return retorno;
}
/*
 *\brief esEmail: valida si la cadena ingresa son los caracteres permitidos para un mail
 *\param char cadena,cadena de caracteres a ser analizada
 *\param int limite, define el tamaño de la cadena
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int esEmail(char* cadena, int limite)
{
	int respuesta = 1; //TODO OK
		for(int i;i<=limite && cadena[i]!='\0' ;i++)
		{
			if( (cadena[i]<'A'|| cadena[i]>'Z') && (cadena[i]<'a'|| cadena[i]>'z') &&
				(cadena[i]< '!' || cadena[i]> 39) && (cadena[i]< '+' || cadena[i]>'/') &&
				(cadena[i]!='_' &&  cadena[i]!= 95 && cadena[i]!= 126 && cadena[i]!='@'))
			{
				respuesta = 0;
				break;
			}
		}
		return respuesta;
}
/*
 *\brief esNumeroAdicional: verifica si la cadena ingresa es numerica con caracteres adicionales
 *\							para diferentes funciones como telefono, dni o cuit
 *\param char* cadena, cadena de caracteres a ser analizada
 *\return retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int esNumeroAdicional(char* cadena)
{
	int i =0;
	int retorno = -1;
	if(cadena != NULL && strnlen(cadena,sizeof(cadena)) > 0)
	{
		while(cadena[i] !='\0')
		{
			if(cadena[0] == '+' || cadena[0] == '(' )
			{
				continue;
			}
			if((cadena[i] < '0' || cadena[i] > '9')&&
			  (cadena[i]!='-'|| cadena[i]!=')'))
			{
				retorno =0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
/*
 *\brief utn_getNumero : Pide al usuario un numero entero
 *\param char* msg: El mensaje que imprime para pedir un valor
 *\param char* msgError: mensaje que imprime si el rango no es valido
 *\param int* pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 *\param int reintentos, cantidad de oportunidades para ingresar el dato
 *\param int min: valor minimo admitido(inclusive)
 *\param int max: valor maximo admitido (no inclusive)
 *\ Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumero(char* msg,char* msgError,int* pResultado,int reintentos,int min,int max)
{
	int retorno=-1;
	int bufferInt;

	if(msg!=NULL &&
			msgError !=NULL &&
			pResultado !=NULL &&
			reintentos >=0 &&
			max >= min)
	{
		do
		{
			printf("%s\n",msg);
			if (getInt(&bufferInt)==0 && bufferInt>=min && bufferInt <=max)
				{
					*pResultado= bufferInt;
					retorno=0;
					break;
				}
			else
			{
				printf("%s",msgError);
				reintentos--;
			}
		}while(reintentos > 0);
	}
	return retorno;
}
/* \brief utn_getChar : Pide al usuario caracteres
 * \param char mensaje: El mensaje que imprime para pedir un valor
 * \param char mensajeError: mensaje que imprime si el rango no es valido
 * \param int pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param char min: valor minimo admitido (inclusive)
 * \param char max: valor maximo admitido  (no inclusive)
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */

int utn_getCaracter(char* mensaje, char* mensajeError,char* pResultado,int reintentos,char min, char max)
{
	int retorno=-1;
	char bufferChar;

	if(pResultado != NULL && mensaje !=NULL && mensajeError !=NULL)
		{
			while(reintentos>=0)
				{
					printf("%s\n",mensaje);
					if (getCaracter(&bufferChar)==0 && bufferChar>=min && bufferChar <=max && reintentos !=0)
						{
							*pResultado=bufferChar;
							retorno=0;
							break;
						}
					else
					{
						printf("%s",mensajeError);
						reintentos--;
					}
				}
		}


	return retorno;
}
/* \brief utn_getNumeroConDecimal : Pide al usuario un numeros decimales
 * \param char mensaje: El mensaje que imprime para pedir un valor
 * \param char mensajeError: mensaje que imprime si el rango no es valido
 * \param float pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int min: valor minimo admitido (inclusive)
 * \param int max: valor maximo admitido  (no inclusive)
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumeroConDecimal(char* mensaje, char* mensajeError,float* pResultado,int reintentos,int min, int max)
{
	int retorno=-1;
	float bufferFloat;

	if(pResultado != NULL && mensaje !=NULL && mensajeError !=NULL)
	{
		while(reintentos > 0)
			{
				printf("%s\n",mensaje);
				if (getFloat(&bufferFloat)==0 && bufferFloat>=min && bufferFloat <=max)
					{
						*pResultado= bufferFloat;
						retorno=0;
						break;
					}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}
	}
	return retorno;
}
/* \brief utn_getNumeroConSigno : Pide al usuario un numeros enteros con signo
 * \param char mensaje: El mensaje que imprime para pedir un valor al usuario
 * \param char mensajeError: mensaje que imprime si el rango no es valido
 * \param int pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int min: valor minimo admitido (inclusive)
 * \param int max: valor maximo admitido  (no inclusive)
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getNumeroConSigno(char* mensaje, char* mensajeError,int* pResultado,int reintentos,int min, int max)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje !=NULL && mensajeError !=NULL)
		{
			while(reintentos > 0)
				{
					printf("%s\n",mensaje);
					if (getInt(&bufferInt)==0 && bufferInt>=min && bufferInt <=max)
						{
							*pResultado= bufferInt;
							retorno=0;
							break;
						}
					else
					{
						printf("%s",mensajeError);
						reintentos--;
					}
				}
		}
		return retorno;
}
/* \brief utn_getTexto : Pide al usuario un texto
 * \param char mensaje: El mensaje que imprime para pedir un valor al usuario
 * \param char mensajeError: mensaje que imprime si el rango no es valido
 * \param char pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param char min: valor minimo admitido (inclusive)
 * \param char max: valor maximo admitido  (no inclusive)
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getTexto(char* mensaje, char* mensajeError,char* pResultado,int limite,int reintentos)
{	int retorno = 0;
	char buffer[4096];
	if(mensaje != NULL && mensajeError !=NULL && pResultado != NULL && limite >0)
	{
		while(reintentos > 0)
		{
			printf("%s",mensaje);
			if(getString(buffer,limite) ==0 )
			{
				strncpy(pResultado,buffer,limite);
				retorno =0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}
	}
	return retorno;
}
/* \brief utn_getEmail : Pide al usuario un email
 * \param char* mensaje: El mensaje que imprime para pedir un valor al usuario
 * \param char* mensajeError: mensaje que imprime si el rango no es valido
 * \param char* pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param char min: valor minimo admitido (inclusive)
 * \param char max: valor maximo admitido  (no inclusive)
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getEmail(char* mensaje, char* mensajeError,char* pResultado,int limite,int reintentos)
{	int retorno = 0;
	char buffer[4096];
	if(mensaje != NULL && mensajeError !=NULL && pResultado != NULL && limite >0)
	{
		while(reintentos > 0)
		{
			printf("%s",mensaje);
			if(getEmail(buffer, limite)==0 )
			{
				strncpy(pResultado,buffer,limite);
				retorno =0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}
	}
	return retorno;
}
int utn_getTelefono(char* mensaje, char* mensajeError,int* pResultado,int reintentos,int min, int max)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje !=NULL && mensajeError !=NULL)
		{
			while(reintentos > 0)
				{
					printf("%s\n",mensaje);
					if (getNumeroAdicional(&bufferInt)==0 && bufferInt>=min && bufferInt <=max)
						{
							*pResultado= bufferInt;
							retorno=0;
							break;
						}
					else
					{
						printf("%s",mensajeError);
						reintentos--;
					}
				}
		}
		return retorno;
}
void imprimirTexto(char arrayChar[],int len)
{
	for(int i=0; i<len; i++)
		{
			printf("%c",arrayChar[i]);
		}
}


