/** @file teclas.h
 *  @brief Prototipos de funciones para la lectura de teclas
 * 
 *  Este archivo contiene los prototipos de funciones que
 *  se utilizan para leer las cuatro teclas de la placa
 *  EDU-CIAA. Este archivo fue realizado en el marco de la
 *  especialización en sistemas embebidos de la Universidad
 *  de Buenos Aires
 * 
 *  @author Gonzalo N. Vaca <vacagonzalo@gmail.com>
 *  @author Luis I. Minchala <ismael.minchala@ucuenca.edu.ec>
 */

#ifndef _TECLAS_H_
#define _TECLAS_H_

#include "macros.h"

/** @brief Lee una tecla de la EDU-CIAA
 * 
 *  Si se ingresa una tecla válida de la placa EDU-CIAA, la función leerá el estado.
 *  Si el boton se encuentra presionado, se espera un retardo para descartar un
 *  accionamiento por ruido. Finalmente vuelve a leer el estado y reporta el valor.
 * 
 *  @param tecla la tecla a leer
 *  @return el estado de la tecla
 */
bool_t leerTecla(gpioMap_t tecla);

#endif /* _TECLAS_H_ */
