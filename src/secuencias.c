/** @file secuencias.c
 *  @brief Archivo con definiciones de funciones para el
 *  módulo de secuencias de LEDs para la placa EDU-CIAA
 *
 *  @author Gonzalo N. Vaca <vacagonzalo@gmail.com>
 *  @author Luis I. Minchala <ismael.minchala@ucuenca.edu.ec>
 */

#include "secuencias.h"
#include "led.h"

void activarSecuencia(struct Secuencia_t* psecuencia, gpioMap_t *leds, tick_t *tiempos){
	psecuencia->leds = leds;
	psecuencia->tiempos = tiempos;
	psecuencia->len = _countof(leds);
	psecuencia->pos = 0;
	psecuencia->sentido = false;
	delayInit(&psecuencia->myDelay, psecuencia->tiempos[psecuencia->pos]);
	apagarLeds();
	encenderLed(psecuencia->leds[psecuencia->pos]);
}

void actualizarSecuencia(struct Secuencia_t* psecuencia){
	if ( delayRead(&psecuencia->myDelay) ){
		apagarLeds();
		if (psecuencia->pos < psecuencia->len){
			++psecuencia->pos;
		} else{
			psecuencia->pos = 0;
		}
		encenderLed(psecuencia->leds[psecuencia->pos]);
		delayWrite(&psecuencia->myDelay, psecuencia->tiempos[psecuencia->pos]);
	}
}
