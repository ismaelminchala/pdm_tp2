#include "tp2.h"
#include "macros.h"
#include "led.h"
#include "teclas.h"

int main( void )
{
   boardInit();
   delay_t myDelay;
   delayInit(&myDelay, 500);
   bool_t state = false;

   while( true ) {
	   if( delayRead(&myDelay) ){
		   if (state){
			   encenderLed(LED1);
		   } else{
			   apagarLeds();
		   }
		   state = !state;
	   }
   }

   return 0;
}
