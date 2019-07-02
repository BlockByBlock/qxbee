#ifndef XBEE_TRANSMIT_H
#define XBEE_TRANSMIT_H

#include "../Frame.h"

namespace QXbee {

/*!
 * \struct The TransmitFrame class
 * \brief Frame type 0x10
 */
struct TransmitFrame: public FrameData
{
public:
  quint8                       frameId {0};
  quint64                      destAdd64 {0};
  quint16                      destAdd16 {0};
  quint8                       broadcastRadius {0};
  quint8                       option {0};
  QByteArray                   payload;

  TransmitFrame():FrameData(ApiFrameType::ZigbeeTransmitRequest){}
};

#endif //XBEE_TRANSMIT_H
}
