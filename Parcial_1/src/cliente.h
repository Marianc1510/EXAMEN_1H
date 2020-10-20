/*
 * nac.h
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define LIM_NOMBRE 51
#define LIM_APELLIDO 51
#define LIM_CUIT 14
#define TRUE 1
#define FALSE 0

typedef struct
{
	int idCliente;
	int isEmpty;
	char cuit[LIM_CUIT];
	char nombre[LIM_NOMBRE];
	char apellido[LIM_APELLIDO];
}Cliente;

int cli_initClientes(Cliente* pArray, int limite);
int cli_addNewClientes(Cliente* pArray, int limite);
int cli_printClientes(Cliente* pArray, int limite);
int cli_modificaCliente(Cliente* pArray, int limite);
int cli_addCliente(Cliente* pArray, int limite,int indice,char* nombre, char* apellido, char* cuit);
int cli_sortClientes(Cliente* pArray, int limite, int orden);
int cli_buscarPosicionLibre(Cliente* pArray, int limite,int* pIndice);
int cli_findClienteById(Cliente* pArray, int limite, int idBuscar);
int cli_removeCliente(Cliente* pArray, int limite, int id);
int cli_addClienteForzada(Cliente* pArray, int limite, char* name, char* apellido,char* cuit, int posicion);

#endif /* CLIENTE_H_ */
