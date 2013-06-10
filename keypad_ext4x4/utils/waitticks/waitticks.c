/** @addtogroup waitticks_MODULE
*
* @{
* @file waitticks.h
* @brief La definicion de las funciones del waittick.
*
* @version v2.0
* @date   	2012-11-23
*
* @note gpl2 license  2012, joseba.alza
*
* @par VERSION HISTORY
* @note Version : 1
* @note Date : 2012-11-22
* @note Revised by : 	joseba.alza@alumni.eps.mondragon.edu
* @note Description : version inicial sin comentarios y sin estructura de carpetas adecuadas.
*
* @}
*/

#include "waitticks.h"
#define BUCLE 10

static unsigned int contador;

unsigned int ticks=0;
unsigned int ticksOld=0;
unsigned int uticks=0;

void initWaitTick(void) {
	SysTickPeriodSet(20000000); // periodo=0,25 seg Programamos el timer para que cuente 2.000.000 -> 2 millones a 8 Mhz, interrumpe cada 0,25 seg.
	SysTickIntEnable(); // Habilitar para que provoque interrupciones
	SysTickEnable();
	IntMasterEnable();

}

void waitTick(void)
{
 /* while(ticksOld==ticks); //estamos en el while hasta que la interrupción incremente ticks. Incrementerá y se despertará en el prog. principal.
  ticksOld++;*/
contador = 0 ;
while (contador <BUCLE){

}
}


/*
 * En startup.c hay que definir esta función como extern, para que sepa que la implementamos nosotros.
 *
 */

void SysTick_Handler(void) {
	/*uticks=(uticks+1)% CYCLES;
	  if(uticks==0) ticks++;
*/
	contador++;
}
