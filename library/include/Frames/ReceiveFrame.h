#ifndef XBEE_RECEIVE_H
#define XBEE_RECEIVE_H

#include "../Frame.h"

namespace QXbee {

/*!
 * \class The ReceiveFrame class
 * \brief Frame type 0x90
 */
class ReceiveFrame: public QXbeeFrameData
{
public:
  quint64                      destAdd64;
  quint16                      destAdd16;
  quint8                       option;
  QByteArray                   payload;
  QXbeeFrameData::ApiFrameType frameType;

  ReceiveFrame();

  void insertData(const QByteArray& data);
};

#endif //XBEE_RECEIVE_H
}
