#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "keypad.h"
#include "miniconsola/console.h"

#define NUM_ELEMENTS = 4;

unsigned char g_ucKeypadSwitches = 0x00;
unsigned char g_ucKeypadSwitches_extern = 0x00;

int main(void)
{
	//unsigned long inputs[NUM_ELEMENTS];

	KEYPAD_init();
	initConsole();

//	consolePrintStr(0, 1,  "keypad_externo_froga_v2");
	refreshConsole();
    while(1)

    {
    	ELEVATOR_readSwitches();
    	GPIO_init();

    	//GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_PIN_0);
    	//GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);
    	//GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);
    	//GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 0);



    	/*pin[0]= GPIO_PIN_0;
    	pin[1]= GPIO_PIN_1;
    	pin[2]= GPIO_PIN_2;
    	pin[3]= GPIO_PIN_3;*/

    	int i=0;
    	for (i=0;i<4;i++){

    		if(i==0){
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_PIN_0);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 0);

    		readExternKeypad();
    		int wait=0;
    		for(wait=0;wait<600;wait++){
    		}

    		int column=0;
    		unsigned long dato=0;
    		dato=g_ucKeypadSwitches_extern;

    		   	 switch(dato) {
    		   			 case 0x11:   	 consolePrintStr(0, 6,  "1.SOLAIRUA");
    		   			  	 	 	 	 refreshConsole();
    		   			 	 	 	 	 break;
    		   			 case 0x21:
    		   				 	 	 	 consolePrintStr(0, 6,  "4.SOLAIRUA");
    		   			 	 	 	 	 refreshConsole();
    		   			 	 	 	 	 break;
    		  			 case 0x41:	   	 consolePrintStr(0, 6,  "7.SOLAIRUA");
    		   			 	 	 	 	 refreshConsole();
    		   			 	 	 	     break;
    		   			 default:
    		   			 	 	 	 	 break;
    		   	 }
    		}
    		if(i==1){

    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, GPIO_PIN_1);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 0);

    		readExternKeypad();
    		int column=0;
    	   	unsigned long dato=0;
    	   	dato=g_ucKeypadSwitches_extern;
   		    	 switch(dato) {
 		    			 case 0x12:   	 consolePrintStr(0, 6,  "2.SOLAIRUA");
 		    			 	 	 	 	 refreshConsole();
    		    		    			 break;
    		    		 case 0x22:	 	 consolePrintStr(0, 6,  "5.SOLAIRUA");
    		    		    		 	 refreshConsole();
    		    		    		 	 break;
    		    		 case 0x42:	   	 consolePrintStr(0, 6,  "8.SOLAIRUA");
    		    		    			 refreshConsole();
    		    		    			 break;
    		    		 default:
    		    			 	 	 	 break;
    		    		    			 }
    		}
    		if(i==1){

    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);
    		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 0);


    		readExternKeypad();
    		int column=0;
    		unsigned long dato=0;
    		dato=g_ucKeypadSwitches_extern;
    		  	 switch(dato) {
    		  	 	 	 case 0x14:   	 consolePrintStr(0, 6,  "3.SOLAIRUA");
    		 		     	 	 	 	 refreshConsole();
    		    		    			 break;
    		    		 case 0x24:	 	 consolePrintStr(0, 6,  "6.SOLAIRUA");
    		    		     		 	 refreshConsole();
    		    		     		 	 break;
    		    		 case 0x44:	   	 consolePrintStr(0, 6,  "9.SOLAIRUA");
    		    		     			 refreshConsole();
    		    		    			 break;
    		    		 default:
    		    		 	 	 	 	 break;
    		     }
    		}



    	}
    }
}

