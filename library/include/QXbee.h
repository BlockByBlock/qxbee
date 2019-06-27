#ifndef QXBEE_H
#define QXBEE_H

#include <QSharedDataPointer>
#include <QString>
#include "QXbee_global.h"
#include "QXbeeFrame.h"
#include "FrameBuffer.h"

namespace QXbee {

/*!
 * \class The QXbee class
 * \brief Currently supporting API operation
 */
class QXBEESHARED_EXPORT QXbee
{
public:

  /** Default Constructor */
  QXbee();

  /**
   * @brief Overloaded Constructor
   * @param QByteArray input
   */
  QXbee(const QByteArray& ba);

  /**
   * @brief Overloaded Constructor
   * @param QString input
   */
  QXbee(const QString& string);

  /** Destructor */
  ~QXbee();

  /** Copy Constructor */
  QXbee(const QXbee &other);

  /**
   * @brief Process data into a frame
   * @param Serial input/output from Xbee
   * @return True if frame is completed
   */
  bool consume(QByteArray data);

  /**
   * @brief Check if frame is completed
   * @return True if complete frame
   */
  bool isComplete();

  /**
   * @brief Convert frame to QByteArray
   * @return Frame in QByteArray type
   */
  QByteArray toByteArray();

protected:
  void init(const QByteArray input);

private:
  QSharedDataPointer<QXbeeFrame>  frame;
  QSharedDataPointer<FrameBuffer> buffer;
};

}
#endif // QXBEE_H
