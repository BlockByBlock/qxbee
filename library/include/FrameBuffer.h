#ifndef QXBEE_FRAME_BUFFER_H
#define QXBEE_FRAME_BUFFER_H

#include <QScopedPointer>
#include "QXbee.h"

#define MAX_BUFFER_SIZE = 255

namespace QXbee {

struct FrameBufferPrivate;

/*!
 * \class The FrameBuffer class
 * \brief For storing frames
 */
class FrameBuffer: public QXbee
{
public:
  /**
   * @brief FrameBuffer Constructor
   */
  FrameBuffer(QObject *parent=Q_NULLPTR);

  /** Destructor */
  ~FrameBuffer();

  /**
   * @brief Clear buffer and count dropped frame
   */
  void clear();

  /**
   * @brief Keep track of dropped frames since last call
   * @return number of dropped frames
   */
  quint32 droppedCounter();

private:
  QScopedPointer<FrameBufferPrivate> d;
};

}
#endif // QXBEE_FRAME_BUFFER_H
