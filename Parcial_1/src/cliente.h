/*
 * nac.h
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "publicidad.h"
#define LIM_NOMBRE 51
#define LIM_APELLIDO 51
#define LIM_CUIT 14

typedef struct
{
	int idCliente;
	int isEmpty;
	//int isState;
	char cuit[LIM_CUIT];
	char nombre[LIM_NOMBRE];
	char apellido[LIM_APELLIDO];
}Cliente;
int cli_addCliente(Cliente* pArray, int limite,int indiceBuscado,int* id);
int cli_initClientes(Cliente* pArray, int limite);
int cli_printClientes(Cliente* pArray, int limite);
int cli_sortClientes(Cliente* pArray, int limite, int orden);
int cli_getEmptyIndex(Cliente* pArray, int limite, int* pIndice);
int cli_findClienteById(Cliente* pArray, int limite, int idBuscar);
int cli_newClientes(Cliente* pArray, int limite);
int cli_modificaCliente(Cliente* pArray, int limite);
int cli_addClienteForzada(Cliente* pArray, int limite, char* name, char* apellido,char* cuit, int posicion);

#endif /* CLIENTE_H_ */
