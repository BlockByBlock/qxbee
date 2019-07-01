#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include "QXbee.h"

#define MAX_BUFFER_SIZE = 255

namespace QXbee {

struct FrameImplementation;
/*!
 * \class The QXbee Frame
 * \brief Implicity shared data class
 */
class Frame : public QXbee
{
public:

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

  /*! Constructor */
  Frame() = default;

  /*! Virtual Destructor */
  virtual ~Frame();

  /*! Copy Constructor */
  Frame(const Frame &other);

  /*!
   * \brief Sort data into respective field in specific frame
   * \param Data which does not include delimiter, frame length
   */
  virtual void sortData(const QByteArray& data);

private:
  QSharedDataPointer<FrameImplementation> d_ptr;

};

}
#endif // QXBEE_FRAME_H

