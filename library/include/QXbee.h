#ifndef QXBEE_H
#define QXBEE_H

#include <QSharedDataPointer>
#include <QSharedPointer>
#include <QString>
#include "QXbee_global.h"
#include "QXbeeFrameData.h"

namespace QXbee {

struct QXbeePrivate;

/*!
 * \class The QXbee class
 * \brief Currently supporting API operation
 */
class QXBEESHARED_EXPORT QXbee
{
public:

  QXbee();
  QXbee(const QByteArray&);
  QXbee(const QString& string);
  ~QXbee();

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
  QSharedPointer<QXbeePrivate> d;
  QSharedDataPointer<QXbeeFrameData> d_frame;
};

}
#endif // QXBEE_H
