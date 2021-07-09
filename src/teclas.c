/** @file teclas.c
 *  @brief Implementación de funciones públicas para la lectura de teclas
 * 
 *  Este archivo contiene las definiciones de funciones que
 *  se utilizan para leer las cuatro teclas de la placa
 *  EDU-CIAA. Además, contiene las funciones privadas del módulo.
 *  El archivo realizado en el marco de la especialización en sistemas
 *  embebidos de la Universidad de Buenos Aires
 * 
 *  @author Gonzalo N. Vaca <vacagonzalo@gmail.com>
 *  @author Luis I. Minchala <ismael.minchala@ucuenca.edu.ec>
 */

#include "teclas.h"

/** @brief Función que evalua si la tecla es válida
 * 
 *  La función compara el argumento contra una lista de
 *  teclas que corresponden a la placa EDU-CIAA
 * 
 *  @param tecla valor de tecla a evaluar
 *  @return la validez de la tecla ingresada
 */
bool_t isValidTecla(gpioMap_t tecla);

bool_t leerTecla(gpioMap_t tecla)
{
	if (!isValidTecla(tecla))
	{
		return false;
	}
	if (!gpioRead(tecla))
	{
		delay(20);
		return !gpioRead(tecla);
	}
	else
	{
		return false;
	}
}

bool_t isValidTecla(gpioMap_t tecla)
{
	return ((tecla == TEC1) ||
			(tecla == TEC2) ||
			(tecla == TEC3) ||
			(tecla == TEC4) );
}
