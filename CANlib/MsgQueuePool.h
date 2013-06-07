#ifndef MSGQUEUEPOOL_H
#define MSGQUEUEPOOL_H

#include "MsgQueuePoolDescr.h"

#define INVALID_PARAMS 1
#define OK 0

int initMsgQueuePool(unsigned long ulBas);
int setMsgQvalue(unsigned int idMsgQ, const unsigned char *value, unsigned long len);
int getMsgQvalue(unsigned int idMsgQ, unsigned char *value, unsigned long len);
void doCOM(void);

#endif
