/*
 * nac.c
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */
#include "publicidad.h"

static int pub_generarIdNuevo(void);

/*
 *brief addPublicidadForzada:
 *\param publicidad pArray
 *\param int limite
 *\param int numeroRubro
 *\param char texto
 *\param int idCliente
 *\param int posicion
 *\param return retorno
 */
int pub_addPublicidadForzada(Publicidad* pArray, int limite,int numeroRubro,char* texto,int idCliente, int posicion)
{
	int retorno = -1;
	Publicidad buffer;

	strncpy(buffer.textoAviso,texto,LIM_CARACTER);
	buffer.numeroRubro = numeroRubro;
	buffer.idPublicidad= pub_generarIdNuevo();
	buffer.idClienteAnuncio= idCliente;
	pArray[posicion]=buffer;
	pArray[posicion].isEmpty= FALSE;
	retorno=0;
	return retorno;
}
/*
 *brief addPublicidad:
 *\param publicidad* pArray
 *\param int limite
 *\param int indice
 *\param int idCliente
 *\return retorno
 */
int pub_addPublicidad(Publicidad* pArray, int limite,int indice,int idCliente)
{
	int retorno =-1;
	Publicidad bufferEntidad;

	if(pArray !=NULL && limite > 0 && indice >=0)
	{
		if(utn_getNumero("\nIngrese numero de rubro:\n", "\nNumero incorrecto\n",&bufferEntidad.numeroRubro,2,0, 100)==0 &&
		   utn_getTexto("\nIngrese el texto del aviso\n", "\nDatos incorrectos\n",bufferEntidad.textoAviso, LIM_CARACTER, 2)==0)
		{
			bufferEntidad.idClienteAnuncio=idCliente;
			bufferEntidad.idPublicidad= pub_generarIdNuevo();
			pArray[indice]= bufferEntidad;
			pArray[indice].isEmpty= FALSE;

			retorno=0;
		}
	}
	return retorno;
}
static int pub_generarIdNuevo(void)
{
	static int id=0;
	id= id+1;
	return id;
}
/*
 * \brief initEnployees: inicializa el array indicando que todas las posiciones esten vacias
 * \param pArray, array de Publicidad a ser actualizado
 * \param int limite, la longitud del limite del array de employee
 * \return retorno 0 (EXITO) si esta todo bien, -1 (ERROR) si no
 */
int pub_initPublicidads(Publicidad* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(int i=0; i< limite; i ++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno =0;
	}

	return retorno;
}
/*
 * brief printPublicidads: Imprime el array de empleados de manera columnada
 * \param Publicidad* pArray,  direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \return retorno 0(EXITO) se pudo imprimir, -1(ERROR) si no
 */
int pub_printPublicidads(Publicidad* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		printf("\n-----------------------------------------------------------------------"
			   "\n ID AVISO  NUMERO RUBRO  TEXTO AVISO   ID CLIENTE    ESTADO AVISO "
			   "\n-----------------------------------------------------------------------");
		for( i=0; i< limite; i ++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("\n %d  \t  %d   \t    %s  \t  %d      ", pArray[i].idPublicidad,pArray[i].numeroRubro,pArray[i].textoAviso,pArray[i].idClienteAnuncio);
				if(pArray[i].isState == ACTIVA){
					printf("\t | ACTIVO \n");
				}else{
					printf("\t | PAUSADO \n");
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * brief printAvisoCliente: Imprime el array de avisos de un cliente de manera columnada
 * \param Publicidad* pArray,  direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param int valorBuscado,busca el identificador numerico del cliente
 * \return retorno 0(EXITO) se pudo imprimir, -1(ERROR) si no
 */
int pub_printAvisoCliente(Publicidad* pArray, int limite,int valorBuscado)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		printf("\n--------------------------------------------------------------"
			   "\n ID Aviso  | NUMERO DE RUBRO  |TEXTO AVISO      | ID CLIENTE  "
			   "\n--------------------------------------------------------------");
		for( i=0; i< limite; i ++)
		{
			if(pArray[i].idClienteAnuncio == valorBuscado)
			{
				printf("\n %d \t %d \t %s \t %d\n", pArray[i].idPublicidad,pArray[i].numeroRubro,pArray[i].textoAviso,pArray[i].idClienteAnuncio);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief removePublicidad: Recorre el array para eliminar un empleado utilizando su id
 * \param Publicidad* pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param int id, valor cual debemos buscar en el array
 * \return retorno 0(EXITO)si se pudo eliminar, -1(ERROR) si no se pudo encontrar el empleado, puntero nulo
 */
int pub_removePublicidad(Publicidad* pArray, int limite, int id)
{
	int retorno = -1;
	int i;
	if(pArray !=NULL && limite >=0)
	{
			for(i=0; i < limite; i++)
			{
				if(pArray[i].idClienteAnuncio == id && pArray[i].isEmpty == FALSE)
				 {
							pArray[i].isEmpty = TRUE;
							retorno=0;
				 }
			}
	}
	return retorno;
}
/*

 * brief sortPublicidads: recorre el array ordenando a los empleados por los apellidos y sector de manera ascendente
 * \param Publicidad* pArray,  direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param int orden, valor que indica de que manera a ordenar 1 (UP,ascendente), 0(DOWN, descendente)
 * \return retorno 0(exito) si se pudo ordenar, -1 (ERROR) si no

int pub_sortPublicidads(Publicidad* pArray, int limite, int orden)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Publicidad buffer;
	if(pArray != NULL && limite >= 0 && (orden ==0 || orden ==1))
	{
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				if(pArray[i].isEmpty == FALSE && pArray[i+1].isEmpty == FALSE)
				{
					if((orden == 1 && strncmp(pArray[i].lastname,pArray[i+1].lastname,LONG_LASTNAME) > 0) ||
					   (orden == 0 && strncmp(pArray[i].lastname,pArray[i+1].lastname,LONG_LASTNAME) < 0)==0 ||
					   ((orden ==1 && pArray[i].sector == pArray[i+1].sector) > 0) ||
					   ((orden ==0 && pArray[i].sector == pArray[i+1].sector) < 1 ))
					{
						buffer=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=buffer;
						flagSwap =1;
					}
				}
			}
		}while(flagSwap);
	}
	return retorno;
}*/

/*
 * brief buscarLibreRef: recorre el array buscando una posicion vacia
 * \param Publicidad* pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param int* pIndice, direccion de memoria donde se va a guardar el espacio vacio
 * \return retorno 0(EXITO)si encuentra espacio vacio, -1(ERROR)si no
 */

int pub_buscarLibreRef(Publicidad* pArray, int limite,int* pIndice)
{	int retorno =-1;
	int i;

	if(pArray != NULL && limite > 0 && pIndice!=NULL)
	{
		for(i=0; i<limite; i++)
		{
			if(pArray[i].isEmpty == TRUE)
			{
				*pIndice=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * \brief cambiarEstado: recorre el listado de avisos, cambiandole su estado
 * \param pArray, array de Publicidad a ser actualizado
 * \param int limite, la longitud del limite del array de employee
 * \param int estado
 * \return retorno 0 (EXITO) si esta todo bien, -1 (ERROR) si no
 */
int pub_cambiarEstado(Publicidad* pArray,int indice,int estadoACambiar)
{	int retorno =-1;

	if(pArray != NULL && pArray[indice].isEmpty == FALSE)
	{
		pArray[indice].isState = estadoACambiar;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief findPublicidadById: recorre el array buscando por su ID
 * \param Publicidad* pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, es la longitud del array
 * \param int idBuscar, valor cual debemos buscar en el array
 * \return retorno la posicion en cual se encuentra el array, devolviendo el valor buscado.
 */
int pub_findPublicidadById(Publicidad* pArray, int limite, int idBuscar)
{
	int retorno =-1;
	int i;

	if(pArray != NULL && limite > 0  && idBuscar >=0)
	{
		for(i=0; i<limite; i++)
		{
			if(pArray[i].idPublicidad == idBuscar)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/*
 * brief pausarPublicacion: recorre el listado de avisos, para pausar el aviso ingresado por el usuario
 * \param Publicidad pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, es la longitud del array
 * \return retorno 0 (EXITO) si se pudo pausar publicacion, 1 (ERROR) si no
 */
int pub_pausarPublicacion(Publicidad* pArray, int limite)
{
	int retorno=-1;
	int idABuscar;
	int respuesta;
	int indiceAvisoApausar;
	if(pArray !=NULL && limite >0)
	{
		pub_printPublicidads(pArray, limite);
		if(utn_getNumero("\n-----INGRESE ID DEL AVISO----\n","\nDATO INCORRECTO\n", &idABuscar, 1, 0, limite)==0)
		{
			pub_printAvisoCliente(pArray, limite, idABuscar);
			if(utn_getNumero("\n----¿DESEA CAMBIAR EL ESTADO A 'PAUSADO' SI[1] NO[2]?------\n", "\nERROR\n", &respuesta, 1, 1, 2)==0 && respuesta ==1)
			{
					indiceAvisoApausar= pub_findPublicidadById(pArray, limite, idABuscar);
					if(indiceAvisoApausar >0)
					{
							pub_cambiarEstado(pArray, indiceAvisoApausar,PAUSADA);
							pub_printPublicidads(pArray, limite);
							printf("\n*******SU AVISO CAMBIO AL ESTADO PAUSADO*******");
							retorno=0;
					}
					else
					{
						printf("\nNO SE PUDO MODIFICAR SU ESTADO");
					}
			}
		}
	}
	return retorno;
}
/*
 * brief reanudarPublicacion: recorre el listado de avisos, para activar el aviso ingresado por el usuario
 * \param Publicidad pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, es la longitud del array
 * \return retorno 0 (EXITO) si se pudo activar publicacion, 1 (ERROR) si no
 */
int pub_reanudarPublicacion(Publicidad* pArray, int limite)
{
	int retorno=-1;
	int idABuscar;
	int respuesta;
	int indiceAvisoActivar;
	if(pArray !=NULL && limite >0)
	{
		pub_printPublicidads(pArray, limite);
		if(utn_getNumero("\n-----INGRESE ID DEL AVISO----\n","\nDATO INCORRECTO\n", &idABuscar, 1, 0, limite)==0)
		{
			pub_printAvisoCliente(pArray, limite, idABuscar);
			if(utn_getNumero("\n----¿DESEA CAMBIAR EL ESTADO A 'ACTIVO' SI[1] NO[2]?------\n", "\nERROR\n", &respuesta, 1, 1, 2)==0 && respuesta ==1)
			{
				indiceAvisoActivar = pub_findPublicidadById(pArray, limite, idABuscar);
				if(indiceAvisoActivar >0){
					pub_cambiarEstado(pArray,indiceAvisoActivar,ACTIVA);
					pub_printPublicidads(pArray, limite);
					printf("\n*******SU AVISO CAMBIO AL ESTADO ACTIVO********");
					retorno=0;
				}
				else
				{
					printf("\nNO SE PUDO MODIFICAR SU ESTADO");
				}
			}
		}
	}
	return retorno;
}
/*
 * \Brief printDatosCompletos: Imprime el array completo de un cliente junto a sus avisos publicados de manera columnada
 * \param Publicidad* pArray,  direccion de memoria donde se guardan todos los datos
 * \param int limite, longitud del array
 * \param Cliente* pArrayCliente, direccion de memoria donde se guardan todos los datos
 * \param int limCliente,longitud del arrayCliente
 * \return retorno 0(EXITO) se pudo imprimir, -1(ERROR) si no
 */
int pub_printDatosCompletos(Publicidad* pArray, int limite,Cliente* pArrayCliente, int limCliente)
{
	int retorno=-1;
	int i;
	int j;
	if(pArray !=NULL && limite >0 && pArrayCliente !=NULL && limCliente >0)
	{
		printf("\n-----------------------------------------------------------------------------------------------"
			   "\n ID AVISO | NUMERO DE RUBRO  |TEXTO AVISO      | ID CLIENTE  | NOMBRE      | APELLIDO  |ESTADO"
			   "\n-----------------------------------------------------------------------------------------------");
		for(i=0; i<limite;i++)
		{
			for(j=0;j<limCliente; j++)
			{
				if(pArray[i].idClienteAnuncio == pArrayCliente[j].idCliente && pArray[i].isEmpty == FALSE)
				{

					printf("\n %d     \t  %d     \t  %s   \t %d     \t %s    \t %s ", pArray[i].idPublicidad,pArray[i].numeroRubro,pArray[i].textoAviso,pArray[i].idClienteAnuncio,pArrayCliente[j].nombre,pArrayCliente[j].apellido);
					if(pArray[i].isState == ACTIVA){
						printf("\t   | ACTIVO \n");
					}else{
						printf("\t   | PAUSADO \n");
					}
					retorno=0;
					break;
				}

			}
		}
	}
	return retorno;
}
/*
 * brief bajaPublicidadCliente:
 * \param publicidad pArray, direccion de memoria donde se guardan todos los datos
 * \param int limite, es la longitud del array
 * \param Cliente* pArrayCliente,direccion de memoria donde se guardan todos los datos
 * \param int limCliente, es la longitud del array cliente
 * \return retorno 0 (EXITO) si se pudo pausar publicacion, 1 (ERROR) si no
 */
int pub_bajaPublicidadCliente(Publicidad* pArray,int limP,Cliente* pArrayCliente,int limC)
{
	int retorno=-1;
	int idCliente;
	int respuesta;
	int indice;
	if(pArray !=NULL && limP >0 && pArrayCliente !=NULL && limC >0  &&
		utn_getNumero("\n------INGRESE ID DEL CLIENTE A DAR DE BAJA-------\n", "\nID INVALIDO\n", &idCliente, 2, 0,limC)==0)
	{
		indice = cli_findClienteById(pArrayCliente, limC,idCliente);
		if(indice >=0 )
		{
			pub_printAvisoCliente(pArray, limP, idCliente);
			utn_getNumero("\n-----¿DESEA CONFIRMAR ELIMINACION?  SI[1] / NO[2] --------\n", "\nDATO INVALIDO\n",&respuesta,2,1,2);
			if(respuesta ==1){
					pub_removePublicidad(pArray, limP,idCliente);
					cli_removeCliente(pArrayCliente, limC, idCliente);
					retorno=0;
			}
		}
	}
	return retorno;
}
