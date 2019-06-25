#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QtGlobal>
#include <QSharedDataPointer>

namespace QXbee {

struct QXbeeFramePrivate;
/**
 * \class The QXbee Frame Types
 * \brief The generic data frame structure of xbee
 */
class QXbeeFrame
{
public:
  /** Bytes that need to be escaped*/
  enum EscapeByte {
    StartDelimiter = 0x7E,
    Escape = 0x7D
    //XON = 0x11,
    //XOFF = 0x13
  };

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

  /** Default constructor */
  QXbeeFrame();

  /**
   * @brief Overloaded Constructor
   * @param Take in length (len) of the frame
   */
  QXbeeFrame(quint16 len);

  /**
   * @brief Overloaded Constructor
   * @param Frame type
   * @param QByteArray of frame
   * @param Length of the frame
   */
  QXbeeFrame(ApiFrameType type, const QByteArray data, quint16 len);

  /** Destructor */
  ~QXbeeFrame();

  /** Clear this frame data */
  void clear();

  /**
   * @brief Set Frame Type
   * @param Frame type
   */
  void setFrameType(ApiFrameType type);

  /**
   * @brief Get Data Length
   * @return Length of frame
   */
  quint16 getDataLen() const;

  /**
   * @brief Set Data Length
   * @param Length to be set to frame
   */
  void setDataLen(quint16 len);

protected:
  /**
   * @brief Setup Frame
   * @param Frame type
   * @param QByteArray of frame
   * @param Length of the frame
   */
  void setupFrame(ApiFrameType type, QByteArray data, quint16 len);

private:
  QSharedDataPointer<QXbeeFramePrivate> d;
};

}

#endif // QXBEE_FRAME_H

