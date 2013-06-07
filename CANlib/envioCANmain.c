#include <stdio.h>
#include <string.h>
#include <inc/hw_memmap.h>
#include <inc/hw_types.h>
#include <driverlib/interrupt.h>
#include <driverlib/sysctl.h>
#include <driverlib/systick.h>
#include <consolaLCD/console.h>
#include "MsgQueuePool.h"
#include <platformAbstraction/keypad.h>
#include <platformAbstraction/LEDs.h>


void inicializar(void);
void waitClockTick(void);
void sendCAN(unsigned int id, int dato);


volatile unsigned long intCount = 0;
volatile unsigned long sentCount = 0;
volatile unsigned long recvCount=0;
volatile unsigned long rMsgCount=0;
volatile unsigned long ticks=0, ticksOld=0;
unsigned char stop= 0;


extern unsigned int helb;


#define TECHO 0x203
#define CABINA 0x202
#define A 0x324
#define B 0x233


int main(void)
{
  char str[32];

  unsigned int salida, entrada;
  int i;
  inicializar();
  consolePrintStr(0,1,"VELOCIDAD");
  refreshConsole();
  while(1)
  {
	sendCAN(TECHO,7);

	sendCAN(CABINA,15);

	sendCAN(A,1);

	sendCAN(B,4);

  }

}



void inicializar()
{
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);
  initConsole();
  SysTickPeriodSet(SysCtlClockGet());
  initMsgQueuePool(CAN0_BASE);
  GPIO_init();
  KEYPAD_init();
  SysTickIntEnable();
  SysTickEnable();
  IntMasterEnable();
}

void waitClockTick(void)
{
  while(ticksOld==ticks);
  ticksOld++;
}


void __attribute((interrupt)) sysTickIntHandler(void)
{
  ticks++;
}
void sendCAN(unsigned int helb, int dato){
    	initMsgQueues(helb);
      	setMsgQvalue(0, (unsigned char *)&dato, sizeof(dato));
    	transmisionCAN();
}
