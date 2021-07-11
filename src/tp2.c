#include "tp2.h"
#include "macros.h"
#include "led.h"
#include "teclas.h"
#include "secuencias.h"

int main( void )
{

   struct Secuencia_t control;
   /*const gpioMap_t leds[] = {LED1, LED2, LED3, LEDR, LEDG, LEDB};
   const tick_t tiempos[] = {1000, 500, 2000 ,3000, 500, 500};*/
   const gpioMap_t leds[] = {LED1, OSCURIDAD};
   const tick_t tiempos[] = {500, 500};
   const int8_t count = _countof(leds);

   boardInit();
   activarSecuencia(&control, &leds, &tiempos, count);

   while( true ) {
	   /*actualizarSecuencia(&control);
	   if(leerTecla(TEC1)) {
		   ascendenteSecuencia(&control);
	   }
	   if(leerTecla(TEC4)) {
		   descendenteSecuencia(&control);
	   }*/
	   actualizarSecuencia(&control);
   }

   return 0;
}
