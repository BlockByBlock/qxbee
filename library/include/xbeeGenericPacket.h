#ifndef XBEEGENERICPACKET_H
#define XBEEGENERICPACKET_H

#include <QObject>
#include <QScopedPointer>
#include "../include/qxbee.h"

namespace QXbee {

/*!
 * \class The XbeeGenericPacket class
 * \brief The generic data frame structure of xbee
 */
struct XbeeGenericPacketPrivate;
class XbeeGenericPacket: public QXbee
{
  Q_OBJECT
public:
  // Data bytes that need to be escaped
  enum EscapeByte {
    StartDelimiter = 0x7E,
    Escape = 0x7D
    //XON = 0x11,
    //XOFF = 0x13
  };

  // Support API Data Frame Type
  enum ApiFrameType {
    NoApi                           = 0x00,
    AtCommand                       = 0x08,
    AtCommandQueueParameterValue    = 0x09,
    ZigbeeTransmitRequest           = 0x10,
    ExplicitAddressingCommand       = 0x11,
    RemoteCommandRequest            = 0x17,
    CreateSourceRoute               = 0x21,
    AtCommandResponse               = 0x88,
    ModemStatus                     = 0x8A,
    ZigbeeTransmitStatus            = 0x8B,
    ZigbeeReceivePacket             = 0x90,
    ZigbeeExplicitRxIndicator       = 0x91,
    ZigbeeIODataSampleRxIndicator   = 0x92,
    XbeeSensorReadIndicator         = 0x94,
    NodeIndentificationIndicator    = 0x95,
    RemoteCommandResponse           = 0x97,
    ExtendedModemStatus             = 0x98,
    OTAUpdateStatus                 = 0xA0,
    RouteRecordIndicator            = 0xA1,
    ManyToOneRouteRequestIndicator  = 0xA3
  };

  XbeeGenericPacket(QObject *parent=Q_NULLPTR);
  ~XbeeGenericPacket();

  short             frameLength();
  void              setFrameLength(short);
  ApiFrameType      frameType();
  void              setFrameType(ApiFrameType);
  unsigned char     checksum();
  void              setChecksum(unsigned char);
  QByteArray        frame();
  QByteArray        frameData();
  QByteArray        payload();

  void              constructFrame();
  void              clearFrame();
  QString           toString();

  bool              verifyChecksum(QByteArray);
  void              calculateChecksum(QByteArray);

protected:
  unsigned int      calculateSum(QByteArray);

private:
  QScopedPointer<XbeeGenericPacketPrivate> d;
};

#endif // XBEEGENERICPACKET_H
}
