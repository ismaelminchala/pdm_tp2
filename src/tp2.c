#include "tp2.h"
#include "macros.h"

int main( void )
{
   boardInit();

   while( true ) {
      gpioToggle(LED);
      delay(500);
   }

   return 0;
}
