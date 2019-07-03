#ifndef XBEE_TRANSMIT_FRAME_H
#define XBEE_TRANSMIT_FRAME_H

#include "../Frame.h"

namespace QXbee {

/*!
 * \struct The TransmitFrame class
 * \brief Frame type 0x10
 */
struct TransmitFrame: public FrameData
{
public:
  QByteArray                   frameId;
  QByteArray                   destAdd64;
  QByteArray                   destAdd16;
  QByteArray                   broadcastRadius;
  QByteArray                   option;

  TransmitFrame();

  void sortFields(const QByteArray& data);
};

#endif //XBEE_TRANSMIT_FRAME_H
}
