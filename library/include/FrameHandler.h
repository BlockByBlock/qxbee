#ifndef QXBEE_FRAME_HANDLER_H
#define QXBEE_FRAME_HANDLER_H

#include "QXbee.h"
#include "QXbeeFrameData.h"

namespace QXbee {

/*!
 * \class The QXbeeFrameHandler class
 * \brief Process frame - to be inherited by specific frame handler
 */
class FrameHandler
{
public:
  /**
   * @brief FrameHandler Constructor
   * @param Api Frame Type
   */
  FrameHandler();

  /** Destructor */
  ~FrameHandler();

  /**
   * @brief Process the data to set delimiter, frameLen, frameTypr
   * @param raw input from serial i/o
   * @param QXbeeFrameData type
   */
  static void processData(const QByteArray& input, QXbeeFrameData* data);
};

}
#endif // QXBEE_FRAME_HANDLER_H

