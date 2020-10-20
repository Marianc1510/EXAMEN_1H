/*
 * informes.c
 *
 *  Created on: 15 oct. 2020
 *      Author: mariana
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utN.h"
#include "publicidad.h"
#include "cliente.h"
#define QTY_CLIENTE 10
#define QTY_PUBLICACION 10

int inf_maxAvisos(Cliente* pArrayCli,int limC,Publicidad* pArrayP,int limP)
{
	int retorno = -1;
	int i;
	int flagAvisos=0;
	int maximoAvisos;
	int contadorAviso=0;
	Cliente clienteMaximo;
	if(pArrayCli !=NULL)
	{
		for(i=0;i <QTY_CLIENTE ; i++)
		{

			if(pArrayCli[i].isEmpty ==FALSE)
			{
				inf_contadorIdAviso(pArrayCli, QTY_CLIENTE, contadorAviso, pArrayCli[i].idCliente);
				if(flagAvisos==0)
				{
					maximoAvisos= contadorAviso;
					clienteMaximo= pArrayCli[i];
					flagAvisos=1;
				}
				else if(contadorAviso > maximoAvisos)
				{
					maximoAvisos=contadorAviso;
					clienteMaximo= pArrayCli[i];
				}
			}
			retorno=0;
		}
		printf("\nNOMBRE %s| APELLIDO %s |CANTIDAD %d",clienteMaximo.nombre,clienteMaximo.apellido,maximoAvisos);
	}
	return retorno;
}
int inf_contadorIdAviso(Publicidad* pArray,int limite,int* contadorAviso, int idCliente)
{
	int retorno=-1;
	int i;
	int acumulador=0;
	if(pArray !=NULL && limite >0 && contadorAviso !=NULL && idCliente >0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].idClienteAnuncio == idCliente && pArray[i].isEmpty==FALSE)
			{
				acumulador ++;
				retorno=0;
			}
		}
		*contadorAviso=acumulador;
	}
	return retorno;
}
int inf_contadorAvisosPausados(Publicidad* pArray,int limite)
{
	int retorno=-1;
	int contador=0;
	int acumuladorAvisos=0;
	int avisosPausados;
	if(pArray !=NULL && limite >0)
	{
		pub_printAvisoCliente(pArray, limite, avisosPausados);
	}
	return retorno;
}

int inf_maxRubro(Publicidad* pArray,Cliente* pArrayCli)
{
	int retorno=-1;
	return retorno;
}
int inf_maxAvisosActivos(Publicidad* pArray,Cliente* pArrayCli)
{
	int retorno=-1;
	return retorno;
}
int inf_maxAvisosPausados(Publicidad* pArray,Cliente* pArrayCli)
{
	int retorno=-1;
	return retorno;
}

