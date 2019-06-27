#include "../include/QXbee.h"
#include "../include/FrameHandler.h"

namespace QXbee {

/*!
 * \brief Constructor: Construct an empty QXbee object
 */
QXbee::QXbee()
  :frame(new QXbeeFrame),
   buffer(new FrameBuffer)
{}

/*!
 * \brief Constructor: Construct a QXbee object from QByteArray
 * \param QByteArray
 */
QXbee::QXbee(const QByteArray &ba)
  :frame(new QXbeeFrame),
   buffer(new FrameBuffer)
{
  init(ba);
}

/*!
 * \brief Constructor: Construct a QXbee object from QString
 * \param QString
 */
QXbee::QXbee(const QString &string)
  :frame(new QXbeeFrame),
   buffer(new FrameBuffer)
{
  init(string.toLatin1());
}

QXbee::~QXbee(){}

QXbee::QXbee(const QXbee &other)
  :frame(other.frame),
   buffer(other.buffer)
{}

bool QXbee::consume(QByteArray data)
{
  init(data);
  bool result = isComplete();
  return result;
}

bool QXbee::isComplete()
{
  return frame->isComplete();
}

QByteArray QXbee::toByteArray()
{
  // temp return
  return QByteArray();
}

void QXbee::init(const QByteArray input)
{
  FrameHandler::processData(input, frame.data());
}

}
