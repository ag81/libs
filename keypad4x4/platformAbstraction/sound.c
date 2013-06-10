/** @addtogroup sound_MODULE
*
* @{
* @file sound.c
* @brief La implementacion de las funciones de sonido de PWM.
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

#define SONIDO_C
/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/
#include "hw_types.h"
#include "hw_pwm.h"
#include "hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "sound.h"
#include "utils/waitticks/waitticks.h"
/*********************************************************************
** 																	**
** EXPORTED VARIABLES 												**
** 																	**
*********************************************************************/
#define FRECUENCIA_SILENCIO 40000
#define FRECUENCIA_APERTURA 400
#define FRECUENCIA_CIERRE 600
#define FRECUENCIA_LLEGADA_PISO 200


/*********************************************************************
** 																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/

/**
 * @brief  Inicializacaión del PWM.
 *
 * @return     -
 *
 * Se inicializa el clock del PWM, y luego los pines correspondientes.
 * Se apaga el generador para configurar su contador, y se vuelve a encender.
 * Se especifica el volumen y se activa la salida del PWM.
*/
void PWM_Init(){

	//clock pwm
	SysCtlPWMClockSet(SYSCTL_PWMDIV_8);

	//Configuramos los pines 0 y 1 del puerto G como PWM
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM);
	GPIOPinTypePWM(GPIO_PORTG_BASE, GPIO_PIN_0);
	GPIOPinTypePWM(GPIO_PORTG_BASE, GPIO_PIN_1);

	// Apagamos el  PWM generator
	PWMOutputState(PWM_BASE,  PWM_OUT_1_BIT, false);
	PWMGenDisable(PWM_BASE, PWM_GEN_0);

	// Configuracion, contador up/down.
	PWMGenConfigure(PWM_BASE, PWM_GEN_0,
	PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_SYNC);

	// Activamos pwm
	PWMGenEnable(PWM_BASE, PWM_GEN_0);

	//Especificamos la ganancia.Volumen.
	HWREG(PWM_BASE + PWM_GEN_0_OFFSET + PWM_O_X_CMPB) = 10;
	PWMSyncUpdate(PWM_BASE, PWM_GEN_0_BIT);

	//Activamos la salida del pwm
	PWMOutputState(PWM_BASE, PWM_OUT_1_BIT, true);
}


/**
 * @brief  Reproducir una nota con el PWM para apertura de puertas.
 *
 * @return     -
 *
 * Se activa el PWM con la frecuencia seleccionada.
*/
void Sonido_Apertura_ON(){
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0,(SysCtlClockGet() /(FRECUENCIA_APERTURA * 8)));
	PWMSyncUpdate(PWM_BASE, PWM_GEN_0_BIT);

}

/**
 * @brief  Reproducir una frecuencia con el PWM para silenciar.
 *
 * @return     -
 *
 * Se silencia la frecuencia antes marcada.
*/
void Sonido_OFF(){

	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0,(SysCtlClockGet() /(FRECUENCIA_SILENCIO * 8)));
	PWMSyncUpdate(PWM_BASE, PWM_GEN_0_BIT);
}

/**
 * @brief  Reproducir una nota con el PWM para cierre de puertas.
 *
 * @return     -
 *
 * Se activa el PWM con la frecuencia seleccionada.
*/
void Sonido_Cierre_ON(){
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0,(SysCtlClockGet() /(FRECUENCIA_CIERRE * 8)));
	PWMSyncUpdate(PWM_BASE, PWM_GEN_0_BIT);

}

/**
 * @brief  Reproducir una nota con el PWM para llegada al piso.
 *
 * @return     -
 *
 * Se activa el PWM con la frecuencia seleccionada y se desactiva después de interrupción.
*/
void Sonido_LLegada_Piso(){
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0,(SysCtlClockGet() /(FRECUENCIA_LLEGADA_PISO * 8)));
	PWMSyncUpdate(PWM_BASE, PWM_GEN_0_BIT);
	waitTick();
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0,(SysCtlClockGet() /(FRECUENCIA_SILENCIO * 8)));
	PWMSyncUpdate(PWM_BASE, PWM_GEN_0_BIT);
}
/*********************************************************************
** 																	**
** EOF 																**
** 																	**
**********************************************************************/







