#include "../include/qxbee.h"
#include "../include/xbeeGenericPacket.h"

namespace QXbee {

struct QXbeePrivate
{
  QByteArray buffer;                  // For holding data pass into QXbee initially
  XbeeGenericPacket genericPacket;    // For constructing a generic xbee frame
};

/*!
 * \brief Constructor: Construct an empty QXbee object
 */
QXbee::QXbee(QObject *parent)
  :QObject(parent), d(new QXbeePrivate)
{}

/*!
 * \brief Constructor: Construct a QXbee object from QByteArray
 * \param QByteArray
 */
QXbee::QXbee(const QByteArray &ba, QObject *parent)
  :QObject(parent), d(new QXbeePrivate)
{
  d->buffer = ba;
}

/*!
 * \brief Constructor: Construct a QXbee object from QString
 * \param QString
 */
QXbee::QXbee(const QString &string, QObject *parent)
  :QObject(parent), d(new QXbeePrivate)
{
  d->buffer = string.toLatin1();
}

QXbee::~QXbee(){}

}
