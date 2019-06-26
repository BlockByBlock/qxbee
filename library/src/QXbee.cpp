#include "../include/QXbee.h"
#include "../include/FrameHandler.h"
#include "../include/FrameBuffer.h"
#include "../include/QXbeeFrame.h"

namespace QXbee {

struct QXbeePrivate
{
  QXbeeFrame  frame;
  FrameBuffer buffer;
};

/*!
 * \brief Constructor: Construct an empty QXbee object
 */
QXbee::QXbee():d(new QXbeePrivate)
{}

/*!
 * \brief Constructor: Construct a QXbee object from QByteArray
 * \param QByteArray
 */
QXbee::QXbee(const QByteArray &ba)
  :d(new QXbeePrivate), d_frame(new QXbeeFrameData)
{
  init(ba);
}

/*!
 * \brief Constructor: Construct a QXbee object from QString
 * \param QString
 */
QXbee::QXbee(const QString &string)
  :d(new QXbeePrivate), d_frame(new QXbeeFrameData)
{
  init(string.toLatin1());
}

QXbee::~QXbee(){}

bool QXbee::consume(QByteArray data)
{
  init(data);
  bool result = isComplete();
  return result;
}

bool QXbee::isComplete()
{
  return d->frame.isComplete();
}

QByteArray QXbee::toByteArray()
{
  // temp return
  return QByteArray();
}

void QXbee::init(const QByteArray input)
{
  d->buffer.store(input);
  FrameHandler::processData(input, d_frame.data());
}

}
