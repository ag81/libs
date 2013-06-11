#include "keypad_4x4.h"




char const KEYS[4][4] = {{'1','4','7','F'},
                         {'2','5','8','0'},
                         {'3','6','9','E'},
                         {'A','B','C','D'}};

//#define kbd_port_b   GPIO_PORTB_BASE




void Init_keypad_4x4()

{

SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0| GPIO_PIN_1| GPIO_PIN_2| GPIO_PIN_3);
GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_4| GPIO_PIN_5| GPIO_PIN_6);
GPIOPadConfigSet( GPIO_PORTB_BASE, GPIO_PIN_0 |GPIO_PIN_1 |GPIO_PIN_2 |GPIO_PIN_3 |GPIO_PIN_4 |GPIO_PIN_5  |GPIO_PIN_6   , GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPD);


}

char kbd_getc()
{
   char tecla=0;
   int f,c,i,j;
   unsigned long dato  ;
   //char str[16];

   for(f=0x01, i=0; i<4 ; f<<=1, i++)
   {
	  GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 , f);
	  	  for(c=0x10, j=0; j<3; c<<=1, j++)
	  	  {
	  		dato = GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6);
	  		 //SysCtlDelay((10e-3)*CLKSPEED/3);
	  		dato = dato;
	  		if (dato == c )
	  			{
	  			 tecla=KEYS[i][j];
	  			}
		  }
   }
   return tecla;
}
