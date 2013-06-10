/** @addtogroup uart_MODULE
*
* @{
* @file plat_uart.c
* @brief La implementación de las funciones para interactuar con el UART.
*
* @version v2.0
* @date   	2012-12-16
*
* @note gpl2 license  2012, joseba.alza
*
* @par VERSION HISTORY
* @note Version : 1
* @note Date : 2012-11-22
* @note Revised by : 	joseb.alza@alumni.eps.mondragon.edu
* @note Description : version inicial sin comentarios y sin estructura de carpetas adecuadas.
*
* @}
*/

#define PLAT_UART_C

/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/

#include "plat_uart.h"

/*********************************************************************
** 																	**
** GLOBAL VARIABLES 												**
** 																	**
*********************************************************************/
unsigned char g_ucKeypadSwitches;
char c, str[MAX_COLUMNS];
 int i, refresh=0,nChars=0;
/*********************************************************************
** 																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/
/**
 * @brief  Se inicializan los elementos para usar el UART
 * @param void
 * @return void
 *
 */
void UART_init() {

	 SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |SYSCTL_XTAL_8MHZ);
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	 GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	 UARTDisable(UART0_BASE);
	 UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), BAUD_RATE,
	 		              (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_TWO |UART_CONFIG_PAR_EVEN));
	 UARTEnable(UART0_BASE);


	// UARTSend((unsigned char *)"\n\r.Ascensor.\n\r",(unsigned long) sizeof("\n\r.Ascensor.\n\r"));
	 void UARTRec();

}

/**
 * @brief  Se envia la cadena de texto mediante UART
 * @param pucBuffer puntero a la cadena de texto a enviar
 * @param ulCount cantidad de caracteres a enviar
 * @return void
 * @details Envia el numero de caracteres indicados en el segundo parametro (hasta 16)
 */
void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount) {

	//
    // Loop while there are more characters to send.
    //
    while(ulCount--)
    {
        //
        // Write the next character to the UART.
        //
        UARTCharPutNonBlocking(UART0_BASE, *pucBuffer++);
    }
}

void UARTRec() {

	//
    // Loop while there are more characters to send.
    //
      //
        // Write the next character to the UART.
        //
	 if(UARTCharsAvail(UART0_BASE))
		  //{
		 	// ;
		 	 {		g_ucKeypadSwitches = (char)UARTCharGetNonBlocking(UART0_BASE);
		 		    c = g_ucKeypadSwitches;
		 		    if(nChars==MAX_COLUMNS-1) for(i=0;i<nChars-1;i++) str[i]=str[i+1];
		 		    else nChars++;
		 		    str[nChars-1]=c;

		 		    //consolePrintStr(16,2, str);
		 		   // refreshConsoleLine(2);
		 		    //c=toupper(c);
		 		    //UARTCharPutNonBlocking(UART0_BASE, c);
		 		  }
		 		  else if(refresh)
		 		  {
		 			refresh=0;
		 		    //consolePrintStr(16,2, str);
		 		    //refreshConsoleLine(2);
		 		  }
}
/*********************************************************************
** 																	**
** EOF 																**
** 																	**
**********************************************************************/







