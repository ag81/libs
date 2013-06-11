#ifndef KEYPAD_4X4_H_
#define KEYPAD_4X4_H_

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/uart.h"
#include "miniconsola/console.h"
#include "driverlib/gpio.h"
#include <stdio.h>
#include <ctype.h>

#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"




#define CLKSPEED 8000000

#define BAUD_RATE 9600

//funciones de inicializar y leer la tecla pulsada
void Init_keypad_4x4();
char kbd_getc();


#endif
