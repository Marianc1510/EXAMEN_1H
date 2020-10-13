/*
 * calculos.h
 *
 *  Created on: 29 sep. 2020
 *      Author: mariana
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int operandoSuma(float operador1, float operador2, float* pResultado);
int operandoResta(float operador1, float operador2, float* pResultado);
int operandoMultiplicar(float operador1, float operador2, float* pResultado);
int operandoDividir(float operador1, float operador2, float* pResultado);
int operandoFactoreo(float operando, float* pResultado);
int contadorArray(int array[], int len, int* pvalorContado);
int contadorArrayChar(char array[], char* pvalorContado);

#endif /* CALCULOS_H_ */
