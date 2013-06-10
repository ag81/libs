/** @addtogroup sound_MODULE
*
* @{
* @file sound.h
* @brief La definicion de las funciones de sonido de PWM.
*
* @version v2.0
* @date   	2012-12-15
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

/*****************************************************************************
** 																			**
** DEFINITIONS AND MACROS 													**
** 																			**
******************************************************************************/
#ifndef SONIDO_H
#define SONIDO_H
/*****************************************************************************
** 																			**
** PROTOTYPES OF GLOBAL FUNCTIONS											**
** 																			**
******************************************************************************/
void PWM_Init();
void Sonido_Apertura_ON();
void Sonido_Cierre_ON();
void Sonido_OFF();
void Sonido_LLegada_Piso();
/*****************************************************************************
**	 																		**
** TYPEDEFS AND STRUCTURES 													**
** 																			**
*****************************************************************************/
#ifndef SONIDO_C
#define PUB_SONIDO extern
#else
#define PUB_SONIDO
#endif
/*****************************************************************************
** 																			**
** EOF 																		**
** 																			**
******************************************************************************/
#endif
