#ifndef QXBEE_FRAME_DATA_H
#define QXBEE_FRAME_DATA_H

#include <QSharedData>

namespace QXbee {

/**
 * \class The QXbee Frame Data
 * \brief Implicity shared data class
 */
class QXbeeFrameData: public QSharedData
{
public:
  /** List of frame types supported */
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

  /** Constructor */
  QXbeeFrameData();

  /** Destructor */
  ~QXbeeFrameData();

  /** Copy Constructor */
  QXbeeFrameData(const QXbeeFrameData &other);

  /** Index of start delimiter */
  int                          indexDelimiter;

  /** Api frame type */
  quint8                       frameType;

  /** Frame length */
  quint16                      frameLen;

  /** Frame data */
  QByteArray                   data;
};

}
#endif // QXBEE_FRAME_DATA_H

