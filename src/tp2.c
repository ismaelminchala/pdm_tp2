#include "tp2.h"
#include "macros.h"
#include "led.h"
#include "teclas.h"
#include "secuencias.h"

int main( void )
{
   boardInit();
   struct Secuencia_t control;
   const gpioMap_t leds[] = {LED1, LED2, LED3};
   const tick_t tiempos[] = {500, 200, 700};
   activarSecuencia(&control, &leds, &tiempos);

   while( true ) {
	   actualizarSecuencia(&control);
   }

   return 0;
}
