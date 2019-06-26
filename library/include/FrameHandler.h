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
   * @brief Get the type of frames handled by this handler
   * @return The frame type handled by the handler
   */
  static QXbeeFrameData::ApiFrameType getType();

  static void processData(const QByteArray& input, QXbeeFrameData* data);
};

}
#endif // QXBEE_FRAME_HANDLER_H

