#include "../../include/Frames/TransmitFrame.h"

namespace QXbee {

TransmitFrame::TransmitFrame()
  :frameType(QXbeeFrameData::ApiFrameType::ZigbeeTransmitRequest){}

}
