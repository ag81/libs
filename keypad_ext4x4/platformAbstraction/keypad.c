/** @addtogroup keypad_MODULE
*
* @{
* @file keypad.c
* @brief La implementación de las funciones para interactuar con el keypad.
*
* @version v2.0
* @date   	2012-12-15
*
* @note gpl2 license  2012, mikel alza
*
* @par VERSION HISTORY
* @note Version : 1
* @note Date : 2012-11-22
* @note Revised by : joseb.alza@alumni.eps.mondragon.edu
* @note Description : version inicial sin comentarios y sin estructura de carpetas adecuadas.
*
* @}
*/

#define KEYPAD_C
#define MAX_COLUMNS_ 4
/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/

#include "keypad.h"
//#include "plat_uart.h"
/*********************************************************************
** 																	**
** GLOBAL VARIABLES 												**
** 																	**
*********************************************************************/

unsigned char g_ucKeypadSwitches;
unsigned char g_ucKeypadSwitches_extern;
char c_, str_[MAX_COLUMNS_];
 int i_, refresh_=0,nChars_=0;



/*********************************************************************
** 																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/
/**
 * @brief  Inicializacaión del Keypad.
 *
 * @return     -
 *
 * Se inicializa el clock del GPIOE, para habilitar el keypad, y luego los pines correspondientes.
 *
*/

void KEYPAD_init(){

	//Activamos pines del puerto F (botón select)
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOInput( GPIO_PORTF_BASE, GPIO_PIN_1);
	GPIOPadConfigSet( GPIO_PORTF_BASE, GPIO_PIN_1 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);


	//Activamos pines del puerto E (botón select)

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinTypeGPIOInput( GPIO_PORTE_BASE, GPIO_PIN_0);
	GPIOPadConfigSet( GPIO_PORTE_BASE, GPIO_PIN_0 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput( GPIO_PORTE_BASE, GPIO_PIN_1);
	GPIOPadConfigSet( GPIO_PORTE_BASE, GPIO_PIN_1 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput( GPIO_PORTE_BASE, GPIO_PIN_2);
	GPIOPadConfigSet( GPIO_PORTE_BASE, GPIO_PIN_2 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput( GPIO_PORTE_BASE, GPIO_PIN_3);
	GPIOPadConfigSet( GPIO_PORTE_BASE, GPIO_PIN_3 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);



	//Activamos pines del puerto C (botones up, down, right, left)

	// Activacion: 0-3 pines OUTput 4-7 pines INput

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	//GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_7);
	//GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_7 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_6);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_6 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_5);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_5 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_4);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_3);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_3 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_2);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_2 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_1);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_1 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_0);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_0 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);


	// Activacion: 0-3 pines INput 4-7 pines OUTput

	/*SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_7);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_7 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_6);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_6 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_5);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_5 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOOutput( GPIO_PORTB_BASE, GPIO_PIN_4);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_3);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_3 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_2);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_2 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_1);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_1 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput( GPIO_PORTB_BASE, GPIO_PIN_0);
	GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_0 , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU);*/
}
/**
 * @brief  Leer Switches del keypad
 *
 * @return     -
 *
 * Se lee el keypad y se guarda el valor del PIN pulsado.
*/

void ELEVATOR_readSwitches(){

	unsigned long pressed_data;


	//0-3 Pin irakurri

	pressed_data = (GPIOPinRead( GPIO_PORTE_BASE , (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) )|
		    	   (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_1) << 3));


	g_ucKeypadSwitches = pressed_data;

}

void readExternKeypad(){

	unsigned long pressed_data=0;


	//0-3 Pin irakurri

	pressed_data = (GPIOPinRead( GPIO_PORTB_BASE , (GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 ) ));

		    	   //(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_1) << 3));


	g_ucKeypadSwitches_extern = pressed_data;

}
/*********************************************************************
** 																	**
** EOF 																**
** 																	**
**********************************************************************/







