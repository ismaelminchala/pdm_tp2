#include "tp2.h"
#include "macros.h"
#include "led.h"
#include "teclas.h"
#include "secuencias.h"

enum estados{normal, desconectado, alarma};

/** @brief Activa la función de semáforo en operación normal.
 *
 * Esta función activa la secuencia de control de un semáforo simple.
 * Es decir, verde encendido t_verde, luego amarillo encendido
 * t_amarillo (se apaga el led verde) y finalmente el led rojo se
 * enciende un tiempo t_rojo (se apaga el led amarillo). La secuencia
 * se repite de forma indefinida.
 *
 *  @param control es un puntero que pasa por referencia el arreglo
 *  de leds, la posición más reciente de la secuencia, el sentido de
 *  la secuencia, los tiempos de encendido de cada led y la definición
 *  de una estructura de tiempo para el uso de un retardo no bloquente.
 */
enum estados semaforoNormal(struct Secuencia_t *control);

/** @brief Activa la función de semáforo desconectado.
 *
 * Esta función activa la secuencia de control de un semáforo desconectado.
 * El led de color amarillo titila (blink) de forma indefinida.
 *
 *  @param control es un puntero que pasa por referencia el arreglo
 *  de leds, la posición más reciente de la secuencia, el sentido de
 *  la secuencia, los tiempos de encendido de cada led y la definición
 *  de una estructura de tiempo para el uso de un retardo no bloquente.
 */
enum estados semaforoDesconectado(struct Secuencia_t *control);

/** @brief Activa la función de semáforo en modo alarma.
 *
 * Esta función activa la secuencia de control de un semáforo en modo alarma.
 * El led de color rojo titila (blink) de forma indefinida.
 *
 *  @param control es un puntero que pasa por referencia el arreglo
 *  de leds, la posición más reciente de la secuencia, el sentido de
 *  la secuencia, los tiempos de encendido de cada led y la definición
 *  de una estructura de tiempo para el uso de un retardo no bloquente.
 */
enum estados semaforoAlarma(struct Secuencia_t *control);

int main( void ){
   /******* + Definición de variables e inicialización de semáforo normal + *******/
   enum estados estado;
   estado = normal;
   const gpioMap_t ledsNormal[] = {LED3, LED1, LED2};
   const tick_t tiemposNormal[] = {3000, 500, 1000};
   const int8_t countNormal = _countof(ledsNormal);
   struct Secuencia_t controlNormal;
   activarSecuencia(&controlNormal, &ledsNormal, &tiemposNormal, countNormal);
   /*******************************************************************************/

   /**** + Definición de variables e inicialización de semáforo desconectado + ****/
   const gpioMap_t ledsDesconectado[] = {LED1, OSCURIDAD};
   const tick_t tiemposDesconectado[] = {500, 500};
   const int8_t countDesconectado = _countof(ledsDesconectado);
   struct Secuencia_t controlDesconectado;
   activarSecuencia(&controlDesconectado, &ledsDesconectado, &tiemposDesconectado, countDesconectado);
   /*******************************************************************************/

   /*** + Definición de variables e inicialización de semáforo en modo alarma + ***/
   const gpioMap_t ledsAlarma[] = {LED2, OSCURIDAD};
   const tick_t tiemposAlarma[] = {500, 500};
   const int8_t countAlarma = _countof(ledsAlarma);
   struct Secuencia_t controlAlarma;
   activarSecuencia(&controlAlarma, &ledsAlarma, &tiemposAlarma, countAlarma);
   /*******************************************************************************/

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
   }
   return 0;
}

enum estados semaforoNormal(struct Secuencia_t *control){
	enum estados estado = normal;
	if (leerTecla(TEC2)){
		estado = desconectado;
	}
	actualizarSecuencia(control);
	return estado;
}

enum estados semaforoDesconectado(struct Secuencia_t *control){
	enum estados estado = desconectado;
	if (leerTecla(TEC2)){
		estado = alarma;
	}
	actualizarSecuencia(control);
	return estado;
}

enum estados semaforoAlarma(struct Secuencia_t *control){
	enum estados estado = alarma;
	if (leerTecla(TEC2)){
		estado = normal;
	}
	actualizarSecuencia(control);
	return estado;
}
