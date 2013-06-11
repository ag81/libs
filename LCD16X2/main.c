#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "lcd44780_LP.h"

int main(void) {

	SysCtlClockSet(
			SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
			| SYSCTL_OSC_MAIN); // 400MHz / 2 / 5 (SYSCTL_SYSDIV_5) = 40MHz

	initLCD();
	LCDCommand(0x0c);
	LCDWriteText("Hello World!", 0, 0);
	LCDWriteText("3..2..1..", 1, 0);
	LCDWriteText("Launch Started!", 2, 0);
	LCDWriteText("Stellar Quality!", 3, 0);

	while (1) {

	}
}

