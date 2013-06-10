#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "keypad.h"
#include "miniconsola/console.h"



unsigned char g_ucKeypadSwitches = 0x00;
unsigned char g_ucKeypadSwitches_extern = 0x00;

int main(void)
{
	KEYPAD_init();
	initConsole();

	consolePrintStr(0, 2,  "keypad_externo_froga_v2");
	refreshConsole();
    while(1)

    {
    	ELEVATOR_readSwitches();
    	GPIO_init();


    	int column=0;
    	unsigned long dato=0;

    	 switch(g_ucKeypadSwitches ) {
    			 case KEY_UP:    for(column=0;column<4;column++)
    			 	 	 	 	 {
    				 	 	 	 GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_PIN_0);
    				 	 	 	 readExternKeypad();
    				 	 	 	 dato= 0xf0 & g_ucKeypadSwitches_extern;
    			 	 	 	 	 }
    				 	 	 	 if(dato==0x10)
    				 	 	 	 {
    				 	 	 	 consolePrintStr(0, 1,  "1.SOLAIRUA");
    			 	 	 	 	 }
    				 	 	 	if(dato==0x20)
    				 	 	 	 {
    				 	 	 	 consolePrintStr(0, 1,  "4.SOLAIRUA");
    				 	 	 	 }
    				 	 	 	if(dato==0x30)
    				 	 	     {
    				 	 	 	 consolePrintStr(0, 1,  "5.SOLAIRUA");
    				 	 	 	 }
    			 	 	 	 	 refreshConsole();
    			 	 	 	 	 break;
    			 case KEY_DOWN:	 //g_gpio2= 10;
    			 	 	 	 	 consolePrintStr(0, 6,   "GPIO2 KEY_DOWN   : OK");
    			 	 	 	 	 refreshConsole();
    			 	 	 	 	 break;
    			 case KEY_LEFT:	  //g_gpio3= 10;
    			 	 	 	 	 consolePrintStr(0, 8,  "GPIO3 KEY_RIGHT  : OK");
    			 	 	 	 	 refreshConsole();
    			 	 	 	     break;
    			 case KEY_RIGHT: // g_gpio4= 10;
    				 	 	 	 consolePrintStr(0, 10, "GPIO4 KEY_LEFT   : OK");
    			  	  	  	  	 refreshConsole();
    			 break;
    			 }
    }
}
