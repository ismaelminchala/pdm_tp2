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
struct Secuencia_t {
	const gpioMap_t *leds;
	const tick_t *tiempos;
	int8_t pos;
	tick_t clk;
};

/** @brief Función que actualiza el estado de secuencia
 *
 *  @param sec Secuancia a actualizar
 */
void activarSecuencia(struct Secuencia_t *sec);

#endif /* _SECUENCIAS_H_ */
