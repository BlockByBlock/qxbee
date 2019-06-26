#include "../include/QXbee.h"
#include "../include/FrameHandler.h"
#include "../include/FrameBuffer.h"
#include "../include/QXbeeFrame.h"

namespace QXbee {

struct QXbeePrivate
{
  QXbeeFrame frame;
  FrameHandler handler;
  FrameBuffer buffer;
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
}

/*!
 * \brief Constructor: Construct a QXbee object from QString
 * \param QString
 */
QXbee::QXbee(const QString &string, QObject *parent)
  :QObject(parent), d(new QXbeePrivate)
{
}

QXbee::~QXbee(){}

bool QXbee::consume(QByteArray data)
{
  //temp return
  return true;
}

QByteArray QXbee::toByteArray()
{
  // temp return
  return QByteArray();
}

}
