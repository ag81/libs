#include "MsgQueuePool.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/can.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include <stdio.h>

#include "MsgQueuePoolConfig.h"

#define NADIE 0x221


typedef struct s_MsgQueue
{
  unsigned char value[8];
  tCANMsgObject msgObj;
  unsigned long ulObjId;
}MsgQueue;


void transmisionCAN(void);
void recepcionCAN(void);
int initMsgQueues(unsigned int id);

MsgQueue inMsgQueues[IN_QUEUES];
MsgQueue outMsgQueues[OUT_QUEUES];
long basePortCAN;


int initMsgQueuePool(unsigned long ulBase)
{
  basePortCAN=ulBase;
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
  GPIOPinConfigure(GPIO_PD0_CAN0RX);
  GPIOPinConfigure(GPIO_PD1_CAN0TX);
  GPIOPinTypeCAN(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
  CANBitRateSet(CAN0_BASE, SysCtlClockGet(), CAN_BITRATE);
  //CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
  //CANInit(CAN0_BASE);
  CANEnable(CAN0_BASE);
  initMsgQueues(0x000);
  return 1;
}

//int initMsgQueues(void)
//{
//  int i;
//
//  for(i=0;i<IN_QUEUES;i++)
//  {
//    inMsgQueues[i].msgObj.ulMsgID=receivedMsgIDs[i] ;
//	inMsgQueues[i].msgObj.ulMsgLen=receivedMsgDataLen[i];
//    inMsgQueues[i].msgObj.ulMsgIDMask=RECEIVE_MESSAGE_MASK;
//    inMsgQueues[i].msgObj.ulFlags=0;
//    inMsgQueues[i].ulObjId=i+1;
//    inMsgQueues[i].msgObj.pucMsgData=inMsgQueues[i].value;
//    CANMessageSet(CAN0_BASE, inMsgQueues[i].ulObjId, &inMsgQueues[i].msgObj, MSG_OBJ_TYPE_RX);
//  }
//  for(i=0;i<OUT_QUEUES;i++)
//  {
//	  outMsgQueues[i].msgObj.ulMsgID=id;
//	 //outMsgQueues[i].msgObj.ulMsgID=transmitedMsgIDs[i];
//     outMsgQueues[i].msgObj.ulMsgLen=transmitedMsgDataLen[i];
//     outMsgQueues[i].ulObjId=i+1+IN_QUEUES;
//     outMsgQueues[i].msgObj.pucMsgData=outMsgQueues[i].value;
//  }
//  return 1;
//}

int setMsgQvalue(unsigned int idMsgQ, const unsigned char *value, unsigned long len)
{
  int i;

  if((idMsgQ>=OUT_QUEUES)||(outMsgQueues[idMsgQ].msgObj.ulMsgLen!=len)) return INVALID_PARAMS;
  for(i=0;i<len;i++) outMsgQueues[idMsgQ].value[i]=value[i];
  return OK;
}

int getMsgQvalue(unsigned int idMsgQ, unsigned char *value, unsigned long len)
{
  int i;

  if((idMsgQ>=IN_QUEUES)||(inMsgQueues[idMsgQ].msgObj.ulMsgLen!=len)) return INVALID_PARAMS;
  for(i=0;i<len;i++) value[i]=inMsgQueues[idMsgQ].value[i];
  return OK;
}

void recepcionCAN(void)
{
  int i;
  unsigned long status;

  for(i=0;i<IN_QUEUES;i++)
  {
	  status=CANStatusGet(basePortCAN, CAN_STS_NEWDAT);
      if(status & (0x01<<(inMsgQueues[i].ulObjId-1)))
        CANMessageGet(basePortCAN, inMsgQueues[i].ulObjId, &inMsgQueues[i].msgObj, 0);
  }
}

void transmisionCAN(void)
{
  int i;


  for(i=0;i<OUT_QUEUES;i++)
  {
    CANMessageSet(basePortCAN, outMsgQueues[i].ulObjId, &outMsgQueues[i].msgObj, MSG_OBJ_TYPE_TX);
  }
}

void doCOM(void)
{
  transmisionCAN();
  recepcionCAN();
}
int initMsgQueues(unsigned int id)
{
  int i;

  for(i=0;i<IN_QUEUES;i++)
  {
    inMsgQueues[i].msgObj.ulMsgID=receivedMsgIDs[i] ;
	inMsgQueues[i].msgObj.ulMsgLen=receivedMsgDataLen[i];
    inMsgQueues[i].msgObj.ulMsgIDMask=RECEIVE_MESSAGE_MASK;
    inMsgQueues[i].msgObj.ulFlags=0;
    inMsgQueues[i].ulObjId=i+1;
    inMsgQueues[i].msgObj.pucMsgData=inMsgQueues[i].value;
    CANMessageSet(CAN0_BASE, inMsgQueues[i].ulObjId, &inMsgQueues[i].msgObj, MSG_OBJ_TYPE_RX);
  }
  for(i=0;i<OUT_QUEUES;i++)
  {
	 outMsgQueues[i].msgObj.ulMsgID=id;
	 //outMsgQueues[i].msgObj.ulMsgID=transmitedMsgIDs[i];
     outMsgQueues[i].msgObj.ulMsgLen=transmitedMsgDataLen[i];
     outMsgQueues[i].ulObjId=i+1+IN_QUEUES;
     outMsgQueues[i].msgObj.pucMsgData=outMsgQueues[i].value;
  }
  return 1;
}
