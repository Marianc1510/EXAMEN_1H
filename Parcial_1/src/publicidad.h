/*
 * nac.h
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_
#include "cliente.h"
#define LIM_CARACTER 256
#define TRUE 1
#define FALSE 0
#define ACTIVA 1
#define PAUSADA 0

typedef struct
{
	char textoAviso[LIM_CARACTER];
	int numeroRubro;
	int isEmpty;
	int isState;
	int idPublicidad;
	int idClienteAnuncio;
}Publicidad;

int pub_initPublicidads(Publicidad* pArray, int limite);
int pub_printPublicidads(Publicidad* pArray, int limite);
int pub_addPublicidad(Publicidad* pArray, int limite,int indice, int idCliente);
int pub_removePublicidad(Publicidad* pArray, int limite, int id);
//int pub_sortPublicidads(Publicidad* pArray, int limite, int orden);
int pub_buscarLibreRef(Publicidad* pArray, int limite, int* pIndice);
int pub_findPublicidadById(Publicidad* pArray, int limite, int idBuscar);
int pub_addPublicidadForzada(Publicidad* pArray, int limite,int numeroRubro,char* texto,int idCliente, int posicion);
int pub_printAvisoCliente(Publicidad* pArray, int limite,int valorBuscado);
int pub_cambiarEstado(Publicidad* pArray, int limite,int* estado);
int pub_pausarPublicacion(Publicidad* pArray, int limite);

#endif /* PUBLICIDAD_H_ */
