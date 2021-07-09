#include "teclas.h"

bool_t leerTecla(gpioMap_t tecla)
{
	bool_t estadoTecla = gpioRead(tecla);
	if (!estadoTecla)
	{
		return !gpioRead(tecla;
	}
	else
	{
		return false;
	}
}
