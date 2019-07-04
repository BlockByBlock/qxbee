#ifndef XBEE_RECEIVE_FRAME_H
#define XBEE_RECEIVE_FRAME_H

#include "../FrameData.h"

namespace QXbee {

/*!
 * \struct The ReceiveFrame class
 * \brief Frame type 0x90
 */
struct ReceiveFrame: public FrameData
{
  QByteArray                   destAdd64;
  QByteArray                   destAdd16;
  QByteArray                   option;

  void sortFields(const QByteArray& data);
};

#endif //XBEE_RECEIVE_FRAME_H
}
