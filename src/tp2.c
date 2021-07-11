#include "tp2.h"
#include "macros.h"
#include "led.h"
#include "teclas.h"
#include "secuencias.h"

enum estados{normal, desconectado, alarma};

enum estados semaforoNormal(struct Secuencia_t *control);
enum estados semaforoDesconectado(struct Secuencia_t *control);
enum estados semaforoAlarma(struct Secuencia_t *control);

int main( void )
{

   struct Secuencia_t control;
   enum estados estado;
   estado = normal;
   const gpioMap_t ledsNormal[] = {LED3, LED1, LED2};
   const tick_t tiemposNormal[] = {3000, 500, 1000};
   const int8_t countNormal = _countof(ledsNormal);
   struct Secuencia_t controlNormal;
   activarSecuencia(&controlNormal, &ledsNormal, &tiemposNormal, countNormal);

   const gpioMap_t ledsDesconectado[] = {LED1, OSCURIDAD};
   const tick_t tiemposDesconectado[] = {500, 500};
   const int8_t countDesconectado = _countof(ledsDesconectado);
   struct Secuencia_t controlDesconectado;
   activarSecuencia(&controlDesconectado, &ledsDesconectado, &tiemposDesconectado, countDesconectado);

   const gpioMap_t ledsAlarma[] = {LED2, OSCURIDAD};
   const tick_t tiemposAlarma[] = {500, 500};
   const int8_t countAlarma = _countof(ledsAlarma);
   struct Secuencia_t controlAlarma;
   activarSecuencia(&controlAlarma, &ledsAlarma, &tiemposAlarma, countAlarma);

   boardInit();

   while( true ) {
	   switch ( estado ){
	   case normal:
		   estado = semaforoNormal(&controlNormal);
		   break;
	   case desconectado:
		   estado = semaforoDesconectado(&controlDesconectado);
		   break;
	   case alarma:
		   estado = semaforoAlarma(&controlAlarma);
		   break;
	   }

	   actualizarSecuencia(&control);
   }
   return 0;
}

enum estados semaforoNormal(struct Secuencia_t *control){
	enum estados estado = normal;
	if (leerTecla(TEC2)){
		estado = desconectado;
	}
	actualizarSecuencia(&control);
	return estado;
}

enum estados semaforoDesconectado(struct Secuencia_t *control){
	enum estados estado = desconectado;
	if (leerTecla(TEC2)){
		estado = alarma;
	}
	actualizarSecuencia(&control);
	return estado;
}

enum estados semaforoAlarma(struct Secuencia_t *control){
	enum estados estado = alarma;
	if (leerTecla(TEC2)){
		estado = normal;
	}
	actualizarSecuencia(&control);
	return estado;
}
