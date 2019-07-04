#ifndef XBEE_UNIDENTIFIED_FRAME_H
#define XBEE_UNIDENTIFIED_FRAME_H

#include "../Frame.h"

namespace QXbee {

/*!
 * \struct The TransmitFrame class
 * \brief Frame type 0x10
 */
struct UnidentifiedFrame: public FrameData
{
public:
  void sortFields(const QByteArray& data);
};

#endif //XBEE_UNIDENTIFIED_FRAME_H

}
