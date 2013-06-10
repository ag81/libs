/** @addtogroup keypad_MODULE
*
* @{
* @file keypad.h
* @brief La definicion de las funciones para interactuar con el keypad.
*
* @version v2.0
* @date   	2012-12-15
*
* @note gpl2 license  2012,joseba.alza
*
* @par VERSION HISTORY
* @note Version : 1
* @note Date : 2012-11-22
* @note Revised by : 	joseb.alza@alumni.eps.mondragon.edu
* @note Description : version inicial sin comentarios y sin estructura de carpetas adecuadas.
*
* @}
*/

/*****************************************************************************
** 																			**
** MODULES USED 															**
** 																			**
****************************************************************************/

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

/*****************************************************************************
** 																			**
** DEFINITIONS AND MACROS 													**
** 																			**
******************************************************************************/
#ifndef KEYPAD_H_INCLUDED
#define KEYPAD_H_INCLUDED


#define PISO_0 0xe    //1110
#define PISO_1 0x7    //1101
#define PISO_2 0xd    //1011
#define PISO_3 0xb    //0111

#define KEY_UP 0x1e     //11110
#define KEY_DOWN 0x1d   //11101
#define KEY_LEFT 0x1b   //11011
#define KEY_RIGHT 0x17  //10111

#define KEY_SELECT 15    //01111

#define PISO_00 0x30   //1110
#define PC_1 0x31    //1101
#define PISO_22 0x32   //1011
#define PISO_33 0x33    //0111


/*****************************************************************************
** 																			**
** PROTOTYPES OF GLOBAL FUNCTIONS											**
** 																			**
******************************************************************************/
void KEYPAD_init();
void ELEVATOR_readSwitches();

/*****************************************************************************
**	 																		**
** TYPEDEFS AND STRUCTURES 													**
** 																			**
*****************************************************************************/
#ifndef KEYPAD_C
#define PUB_KEYPAD extern
#else
#define PUB_KEYPAD
#endif
/*****************************************************************************
** 																			**
** EOF 																		**
** 																			**
******************************************************************************/
#endif
