#ifndef QXBEE_FRAME_DATA_H
#define QXBEE_FRAME_DATA_H

#include <QByteArray>

namespace QXbee {

/*!
 * \class The QXbee Frame Data Structure
 * \brief Specific data structure
 */
struct FrameData
{
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
 FrameData() = default;

 virtual ~FrameData() = default;

 /*!
  * \brief FrameData Constructor
  * \param ApiFrameType
  */
 FrameData(const FrameData::ApiFrameType type);

 /*!
  * \brief Sort data into data fields
  * \param Raw xbee input
  * \note this method should only be accessed from populateFrame() in Frame class
  *       for access safety
  */
 virtual void sortFields(const QByteArray& data) = 0;

 FrameData::ApiFrameType apiFrameType;
 QByteArray              payload;
};

}
#endif // QXBEE_FRAME_DATA_H

