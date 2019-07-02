#ifndef XBEE_RECEIVE_H
#define XBEE_RECEIVE_H

#include "../FrameData.h"

namespace QXbee {

/*!
 * \struct The ReceiveFrame class
 * \brief Frame type 0x90
 */
struct ReceiveFrame: public FrameData
{
  quint64                      destAdd64 {0};
  quint16                      destAdd16 {0};
  quint8                       option {0};
  QByteArray                   payload;

  ReceiveFrame():FrameData(ApiFrameType::ZigbeeReceivePacket){}
};

#endif //XBEE_RECEIVE_H
}
