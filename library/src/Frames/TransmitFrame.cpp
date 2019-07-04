#include "../../include/Frames/TransmitFrame.h"

namespace QXbee {

void TransmitFrame::sortFields(const QByteArray &data)
{
  // Fixed Length allocation
  // Access Limit has been checked at Frame.cpp
  frameId = data.mid(1, 1);
  hash.insert("frameId", frameId);

  destAdd64 = data.mid(2, 8);
  hash.insert("destinationAddress64", destAdd64);

  destAdd16 = data.mid(10, 2);
  hash.insert("destinationAddress16", destAdd16);

  broadcastRadius = data.mid(12, 1);
  hash.insert("broadcastRadius", broadcastRadius);

  option = data.mid(13, 1);
  hash.insert("option", option);

  // Make a copy
  QByteArray copy(data);
  payload = copy.remove(0, 14);
  hash.insert("payload", payload);
}

}
