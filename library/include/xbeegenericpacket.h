#ifndef XBEEGENERICPACKET_H
#define XBEEGENERICPACKET_H

#include <QObject>
#include <QScopedPointer>

namespace QXbee {

/*!
 * \class The XbeeGenericPacket class
 * \brief The generic data frame structure of xbee
 */
struct XbeeGenericPacketPrivate;
class XbeeGenericPacket: public QObject
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
    AtCommand  = 0x08,
    AtCommandQueueParameterValue = 0x09,
    ZigbeeTransmitRequest = 0x10,
    ExplicitAddressingCommand = 0x11,
    RemoteCommandRequest = 0x17,
    CreateSourceRoute = 0x21,
    AtCommandResponse = 0x88,
    ModemStatus = 0x8A,
    ZigbeeTransmitStatus = 0x8B,
    ZigbeeReceivePacket = 0x90,
    ZigbeeExplicitRxIndicator = 0x91,
    ZigbeeIODataSampleRxIndicator = 0x92,
    XbeeSensorReadIndicator = 0x94,
    NodeIndentificationIndicator = 0x95,
    RemoteCommandResponse = 0x97,
    ExtendedModemStatus = 0x98,
    OTAUpdateStatus = 0xA0,
    RouteRecordIndicator = 0xA1,
    ManyToOneRouteRequestIndicator = 0xA3
  };

  XbeeGenericPacket();
  ~XbeeGenericPacket();

  int frameLength();
  void setFrameLength();

private:
  QScopedPointer<XbeeGenericPacketPrivate> d;
};

#endif // XBEEGENERICPACKET_H
}
