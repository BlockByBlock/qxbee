#include "../../include/Frames/UnidentifiedFrame.h"

namespace QXbee {

void UnidentifiedFrame::sortFields(const QByteArray& data){ payload = data; }

}
