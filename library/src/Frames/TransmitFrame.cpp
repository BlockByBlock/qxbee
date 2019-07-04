#include "../../include/Frames/TransmitFrame.h"

namespace QXbee {

void TransmitFrame::sortFields(const QByteArray &data)
{
  // Fixed Length allocation
  // Access Limit has been checked at Frame.cpp
  frameId = data.mid(1, 1);
  destAdd64 = data.mid(2, 8);
  destAdd16 = data.mid(10, 2);
  broadcastRadius = data.mid(12, 1);
  option = data.mid(13, 1);

  // Make a copy
  QByteArray copy(data);
  payload = copy.remove(0, 14);
}

}
