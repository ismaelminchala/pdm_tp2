/** @file secuencias.h
 *  @brief Archivo con estructura de datos y prototipos para el
 *  módulo de secuencias de LEDs para la placa EDU-CIAA
 *
 *  @author Gonzalo N. Vaca <vacagonzalo@gmail.com>
 *  @author Luis I. Minchala <ismael.minchala@ucuenca.edu.ec>
 */

#ifndef _SECUENCIAS_H_
#define _SECUENCIAS_H_

#include "macros.h"

/** Estructura de secuencia de LEDs
 *
 */
struct Secuencia_t{
	gpioMap_t* leds;
	int32_t pos;
	bool_t  sentido;
	tick_t* tiempos;
	delay_t myDelay;
	int32_t len;
};

/** @brief Función que actualiza el estado de secuencia
 *
 *  @param psecuencia Estructura que contiene:
 *    - puntero para leds
 *    - posición del led activo
 *    - sentido de la secuencia
 *    - puntero a los tiempo de encendido de cada led
 */
void activarSecuencia(struct Secuencia_t* psecuencia, gpioMap_t *leds, tick_t *tiempos);

void actualizarSecuencia(struct Secuencia_t* psecuencia);


#endif /* _SECUENCIAS_H_ */
