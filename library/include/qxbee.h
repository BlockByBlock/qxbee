#ifndef QXBEE_H
#define QXBEE_H

#include <QObject>
#include <QScopedPointer>
#include <QString>
#include "qxbee_global.h"

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

private:
  QScopedPointer<QXbeePrivate> d;

};

}
#endif // QXBEE_H
