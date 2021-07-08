/*
 * teclas.c
 *
 *  Created on: Jul 7, 2021
 *      Author: ismael
 */

#include "teclas.h"

bool_t leerTecla(gpioMap_t tecla){
	bool_t estadoTecla = gpioRead(tecla);
	if (!estadoTecla){
		delay(20);
		estadoTecla = gpioRead(tecla);
		return !estadoTecla;
	} else{
		return 0;
	}
}
