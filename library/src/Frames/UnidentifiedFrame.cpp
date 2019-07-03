#include "../../include/Frames/UnidentifiedFrame.h"

namespace QXbee {

UnidentifiedFrame::UnidentifiedFrame():FrameData(ApiFrameType::NoApi){}

void UnidentifiedFrame::sortFields(const QByteArray& data){ payload = data; }

}
