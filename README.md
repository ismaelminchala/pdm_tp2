# **PdM - Práctica no. 2**

**Universidad de Buenos Aires**

**Facultad de Ingeniería**

**Especialización en sistemas embebidos**
<h1>

**Autores:** Luis I. Minchala (ismael.minchala@ucuenca.edu.ec)

	 Gonzalo N. Vaca (vacagonzalo@gmail.com)


## Resumen

Este proyecto presenta, principalmente, la modularización en funciones, 
archivos y capas, un proyecto de controlador de secuencias arbitrarias de LEDs. 
Este proyecto está diseñado para la placa EDU-CIAA-NXP.


## Dependencias externas:
sAPI.h


## Módulos de software del sistema:
 - main.c, main.h
 - secuencias.c secuencias.h
 - led.c, led.h
 - teclas.c teclas.h

Las descripción de cada módulo de software es la siguiente:
 - main: ejecuta la lógica de alto nivel para desplegar secuencias de leds. En
         este caso en particular, se desarrollan secuencias asociadas a la 
         operación de un semáfo con tres modos de operación (normal, desconec-
         tado y alarma).
 - secuencias: este módulo implementa funciones que configuran, inician y 
               actualizan secuencias de leds de acuerdo a parámetros asociados
               a arreglos de LEDs y tiempos de encendido de cada LED del 
               arreglo.
 - led: este módulo implementa funciones asociadas al control de los LEDs de
        la placa EDU-CIAA.
 - teclas: este módulos implementa funciones asociadas a la lectura de los 
           estados de las teclas de la placa EDU-CIAA.

Los modos de operación de las secuencias de LEDs que implementa el módulo main
y que se asocia a un semáfo simple son:

 - Normal: secuencia de leds: rojo 3 s, amarillo 500 ms, verde 1s, rojo. 
 - Desconectado: led amarillo intermitente cada 500 ms.
 - Alarma: rojo intermitente cada 1 s
