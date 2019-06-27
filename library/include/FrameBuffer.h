#ifndef QXBEE_FRAME_BUFFER_H
#define QXBEE_FRAME_BUFFER_H

#include <QSharedData>

#define MAX_BUFFER_SIZE = 255

namespace QXbee {

/*!
 * \class The FrameBuffer class
 * \brief For storing frames
 */
class FrameBuffer: public QSharedData
{
public:
  /**
   * @brief FrameBuffer Constructor
   */
  FrameBuffer();

  /** Destructor */
  ~FrameBuffer();

  /**
   * @brief Store as buffer for uses
   * @param Data to be stored into the buffer
   */
  void store(const QByteArray data);

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
  QByteArray buffer;
  quint32    droppedFrames;
};

}
#endif // QXBEE_FRAME_BUFFER_H
