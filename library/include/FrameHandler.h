#ifndef QXBEE_FRAME_HANDLER_H
#define QXBEE_FRAME_HANDLER_H

#include "QXbee.h"
#include "QXbeeFrame.h"

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
   * @param QXbeeFrame pointer
   */
  static void processData(const QByteArray& input, QXbeeFrame* data);
};

}
#endif // QXBEE_FRAME_HANDLER_H

