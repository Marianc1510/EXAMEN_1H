/*
 ============================================================================
 Name        : Parcial_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "utN.h"
#include "cliente.h"
#include "publicidad.h"
#define QTY_CLIENTE 10
#define QTY_PUBLICACION 10

int main(void) {
	Publicidad pArrayPublicidad[QTY_PUBLICACION];
	Cliente pArrayCliente[QTY_CLIENTE];
	int opcion;
	int auxiliarIndice;
	//int auxiliarId;
	int auxiliarCliente;

	if(pub_initPublicidads(pArrayPublicidad, QTY_PUBLICACION)==0 &&
	   cli_initClientes(pArrayCliente, QTY_CLIENTE)==0){
		printf("\nSe inicializo los arrays Cliente y AVISOS");

		cli_addClienteForzada(pArrayCliente, QTY_CLIENTE, "Mariana", "gomez","20666689633", 1);
		cli_addClienteForzada(pArrayCliente, QTY_CLIENTE, "lucia", "Cardozo","20407859633", 2);
		cli_addClienteForzada(pArrayCliente, QTY_CLIENTE, "Rocio", "Pucheta","20397852037", 3);
		cli_addClienteForzada(pArrayCliente, QTY_CLIENTE, "RITA", "PEREZ","27407851231", 4);
		pub_addPublicidadForzada(pArrayPublicidad, QTY_PUBLICACION, 23, "Promo Heladera", 1, 1);
		pub_addPublicidadForzada(pArrayPublicidad, QTY_PUBLICACION, 12, "Coca cola", 2, 2);
		pub_addPublicidadForzada(pArrayPublicidad, QTY_PUBLICACION, 40, "Mozzarella", 1, 3);

		do{
			if(utn_getNumero("\n-----MENU PUBLICACIONES----\n"
							"1)Alta Cliente\n"
							"2)Modificar datos cliente\n"
							"3)Baja cliente\n"
							"4)Publicar Aviso\n"
							"5)Pausar publicacion\n"
							"6)Reanudar publicacion\n"
							"7)Imprimir\n"
							"8)Informar\n","OPCION INVALIDA\n", &opcion, 2, 1,8)==0)
			{
				switch(opcion)
				{
				case 1:

					if(cli_addNewClientes(pArrayCliente, QTY_CLIENTE)==0)
						{
							printf("\n******************************\n"
									"  Se dio correctamente de alta\n"
									"*******************************\n");
						}else {
							printf("NO se pudo dar de alta");
						}
					break;
				case 2:
					if(cli_printClientes(pArrayCliente, QTY_CLIENTE)==0)
					{
						if(cli_modificaCliente(pArrayCliente, QTY_CLIENTE)==0)
						{
							cli_printClientes(pArrayCliente, QTY_CLIENTE);
						}
					}
					break;
				case 3:
						cli_printClientes(pArrayCliente, QTY_CLIENTE);
						if(pub_bajaPublicidadCliente(pArrayPublicidad, QTY_PUBLICACION, pArrayCliente, QTY_CLIENTE)==0)
						{
							printf("\nBAJA EXITOSA");
							cli_printClientes(pArrayCliente, QTY_CLIENTE);
						}
						else
						{
							printf("\nDATO INVALIDO");

						}
					break;
				case 4:
					cli_printClientes(pArrayCliente, QTY_CLIENTE);
					if(utn_getNumero("\n------SELECCIONE ID DEL CLIENTE---------\n", "\nID INVALIDO\n", &auxiliarCliente, 2, 0, QTY_CLIENTE)==0)
					{
						if(pub_buscarLibreRef(pArrayPublicidad, QTY_PUBLICACION, &auxiliarIndice)==0 &&
								cli_findClienteById(pArrayCliente, QTY_CLIENTE,auxiliarCliente)==0)
						{
							pub_addPublicidad(pArrayPublicidad, QTY_PUBLICACION, auxiliarIndice, auxiliarCliente);
							pub_printAvisoCliente(pArrayPublicidad, QTY_PUBLICACION, auxiliarCliente);
							printf("\n**************************\n"
									"   Carga exitosa de aviso\n"
									"**************************\n");
						}
						else
						{
							printf("\n**************************\n"
									"   No se cargo el aviso\n"
									"**************************\n");
						}
					}
					break;
				case 5:
					if(pub_pausarPublicacion(pArrayPublicidad, QTY_PUBLICACION)==0)
					{
						printf("\nSU AVISO CAMBIO AL ESTADO PAUSADO");
						pub_printPublicidads(pArrayPublicidad, QTY_PUBLICACION);
					}
					else
					{
						printf("\nNO SE PUDO MODIFICAR SU ESTADO");
					}
					break;
				case 6:
					break;
				case 7:
					pub_printPublicidads(pArrayPublicidad, QTY_PUBLICACION);

					break;
				case 8:
					break;
				}
			}

		}while(opcion <=8);
	}

	return EXIT_SUCCESS;
}
