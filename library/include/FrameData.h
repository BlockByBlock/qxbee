#ifndef QXBEE_FRAME_DATA_H
#define QXBEE_FRAME_DATA_H

#define MAX_BUFFER_SIZE = 255

#include "Frame.h"

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

 /*!
  * \brief FrameData Constructor
  * \param ApiFrameType
  */
 FrameData(const FrameData::ApiFrameType type)
  :apiFrameType(type){}

 FrameData::ApiFrameType apiFrameType;
};

}
#endif // QXBEE_FRAME_DATA_H

