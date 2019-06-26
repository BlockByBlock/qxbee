#ifndef XBEE_RECEIVE_H
#define XBEE_RECEIVE_H

#include "../QXbeeFrameData.h"

namespace QXbee {

/**
 * \struct The ReceiveFrame class
 * \brief Frame type 0x90
 */
struct ReceiveFrame
{
  QXbeeFrameData::ApiFrameType frameType;
  quint64                      destAdd64;
  quint16                      destAdd16;
  quint8                       option;
  QByteArray                   payload;

  ReceiveFrame()
    :frameType(QXbeeFrameData::ApiFrameType::ZigbeeReceivePacket){}
};

#endif //XBEE_RECEIVE_H
}
