#ifndef XBEE_TRANSMIT_H
#define XBEE_TRANSMIT_H

#include "../QXbeeFrameData.h"

namespace QXbee {

/**
 * \struct The TransmitFrame class
 * \brief Frame type 0x10
 */
struct TransmitFrame
{
  QXbeeFrameData::ApiFrameType frameType;
  quint8                       frameId;
  quint64                      destAdd64;
  quint16                      destAdd16;
  quint8                       broadcastRadius;
  quint8                       option;
  QByteArray                   payload;

  TransmitFrame()
    :frameType(QXbeeFrameData::ApiFrameType::ZigbeeTransmitRequest){}
};

#endif //XBEE_TRANSMIT_H
}
