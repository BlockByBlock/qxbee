#include "../../include/Frames/ReceiveFrame.h"

namespace QXbee {

void ReceiveFrame::sortFields(const QByteArray& data)
{
  // Fixed Length allocation
  // Access Limit has been checked at Frame.cpp
  destAdd64 = data.mid(1, 8);
  hash.insert("destinationAddress64", destAdd64);

  destAdd16 = data.mid(9, 2);
  hash.insert("destinationAddress16", destAdd16);

  option = data.mid(11, 1);
  hash.insert("option", option);

  // Make a copy
  QByteArray copy(data);
  payload = copy.remove(0, 12);
  hash.insert("payload", payload);
}

}
