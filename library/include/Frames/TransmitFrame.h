#ifndef XBEE_TRANSMIT_H
#define XBEE_TRANSMIT_H

#include "../QXbeeFrameData.h"

namespace QXbee {

/*!
 * \class The TransmitFrame class
 * \brief Frame type 0x10
 */
class TransmitFrame: public QXbeeFrameData
{
public:
  quint8                       frameId;
  quint64                      destAdd64;
  quint16                      destAdd16;
  quint8                       broadcastRadius;
  quint8                       option;
  QByteArray                   payload;
  QXbeeFrameData::ApiFrameType frameType;

  TransmitFrame();

  void insertData(const QByteArray& data);
};

#endif //XBEE_TRANSMIT_H
}
