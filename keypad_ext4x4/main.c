#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "miniconsola/console.h"
#include "keypad_4x4.h"

#define NUM_ELEMENTS = 4;

unsigned char g_ucKeypadSwitches = 0x00;

char c, str[MAX_COLUMNS];

int main(void)
{
	//unsigned long inputs[NUM_ELEMENTS];

	// Inicializaciones
	GPIO_init();
	initConsole();
	Init_keypad_4x4();
	initConsole();
	refreshConsole();



	consolePrintStr(0, 1,  "keypad_externo_froga_v2");
	refreshConsole();
    while(1)

    {

    c = kbd_getc();
    sprintf (str,"%c",c);
    consolePrintStr(0,6,str);
    refreshConsoleLine(6);




}
}
