#ifndef MSGQUEUEPOOLCONFIG_H
#define MSGQUEUEPOOLCONFIG_H


const unsigned int receivedMsgIDs[IN_QUEUES]={0x102,0x202,0x301};
const unsigned int receivedMsgDataLen[IN_QUEUES]={4,4,4};
//const unsigned int transmitedMsgIDs[OUT_QUEUES]={TECHO};
unsigned int transmitedMsgIDs[OUT_QUEUES];
const unsigned int transmitedMsgDataLen[OUT_QUEUES]={4,4,4};
#define RECEIVE_MESSAGE_MASK    0xFFF
#define CAN_BITRATE             500000

#endif

/*
 *
 * #ifndef MSGQUEUEPOOLCONFIG_H
#define MSGQUEUEPOOLCONFIG_H

const unsigned int receivedMsgIDs[IN_QUEUES]={0x101,0x201,0x301};
const unsigned int receivedMsgDataLen[IN_QUEUES]={4,4,4};
const unsigned int transmitedMsgIDs[OUT_QUEUES]={0x102,0x202,0x302};
const unsigned int transmitedMsgDataLen[OUT_QUEUES]={4,4,4};
#define RECEIVE_MESSAGE_MASK    0xFFF
#define CAN_BITRATE             500000

#endif
 */
