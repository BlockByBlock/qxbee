#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QSharedData>

#define MAX_BUFFER_SIZE = 255

namespace QXbee {

/*!
 * \class The QXbee Frame
 * \brief Implicity shared data class
 */
class Frame : public QSharedData
{
public:
  /*! Bytes that need to be escaped*/
  enum EscapeByte {
    StartDelimiter = 0x7E,
    Escape = 0x7D
    //XON = 0x11,
    //XOFF = 0x13
  };

  /*! List of frame types supported */
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
  /*! Default Constructor */
  Frame() = default;

  /*! Explicit Constructor */
  explicit Frame(const QByteArray& input);

  /*! Virtual Destructor */
  virtual ~Frame() = default;

  /*! Copy Constructor */
  Frame(const Frame &other);

  /*!
   * \brief Populate frame data structures with input
   * \param Raw input from Xbee
   */
  void populateFrame(const QByteArray& input);

  /*!
   * \brief Get frame complete status
   * \return True if frame is completed
   */
  bool getComplete() const;

private:

  bool          hasDelimiter;
  bool          isComplete;
  int           indexDelimiter;
  quint8        frameType;
  quint8        frameLen;
  quint8        checksum;
};

}
#endif // QXBEE_FRAME_H

