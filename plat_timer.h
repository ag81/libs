

#ifndef __PLAT_TIMER_H__
#define __PLAT_TIMER_H__

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"

#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

void init_Timer0(int);
void enable_Timer_0(void);
void disable_Timer_0(void);

void init_Timer3(int);
void enable_Timer_3(void);




#endif
