#include "../../include/Frames/ReceiveFrame.h"

namespace QXbee {

ReceiveFrame::ReceiveFrame():FrameData(ApiFrameType::ZigbeeReceivePacket){}

void ReceiveFrame::sortFields(const QByteArray& data)
{
  // Fixed Length allocation
  // Access Limit has been checked at Frame.cpp
  destAdd64 = data.mid(1, 8);
  destAdd16 = data.mid(9, 2);
  option = data.mid(11, 1);

  // Make a copy
  QByteArray copy(data);
  payload = copy.remove(0, 12);
}

}
