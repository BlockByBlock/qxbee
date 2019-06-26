#ifndef QXBEE_H
#define QXBEE_H

#include <QObject>
#include <QSharedDataPointer>
#include <QScopedPointer>
#include <QString>
#include "QXbee_global.h"
#include "QXbeeFrameData.h"

namespace QXbee {

struct QXbeePrivate;

/*!
 * \class The QXbee class
 * \brief Currently supporting API operation
 */
class QXBEESHARED_EXPORT QXbee : public QObject
{
  Q_OBJECT
public:

  QXbee(QObject *parent=Q_NULLPTR);
  QXbee(const QByteArray&, QObject *parent=Q_NULLPTR);
  QXbee(const QString& string, QObject *parent=Q_NULLPTR);

  ~QXbee();

  /**
   * @brief Process data into a frame
   * @param Serial input/output from Xbee
   * @return True if frame is completed
   */
  bool consume(QByteArray data);

  /**
   * @brief Convert frame to QByteArray
   * @return Frame in QByteArray type
   */
  QByteArray toByteArray();

private:
  QSharedDataPointer<QXbeeFrameData> data;
  QScopedPointer<QXbeePrivate> d;

};

}
#endif // QXBEE_H
