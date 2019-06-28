#include "../include/QXbee.h"
#include "../include/FrameHandler.h"

namespace QXbee {

QXbee::QXbee():frame(new QXbeeFrame), buffer(new FrameBuffer){}

QXbee::QXbee(const QByteArray &ba)
  :frame(new QXbeeFrame), buffer(new FrameBuffer){ init(ba); }

QXbee::QXbee(const QString &string)
  :frame(new QXbeeFrame), buffer(new FrameBuffer){ init(string.toLatin1()); }

QXbee::~QXbee(){}

QXbee::QXbee(const QXbee &other):frame(other.frame), buffer(other.buffer){}

QXbee::QXbee(QXbee&& other)
{
  if(this != &other)
  {
    if(other.frame->frameType() != 0)
      frame = other.frame;

    // Other buffer gets appended to current buffer
    buffer->store(other.buffer->getBuffer());

    // process data upon assignment
    init(buffer->getBuffer());
    if(frame->completeFlag())
      buffer->clear();
  }
}

QXbee& QXbee::operator = (const QXbee& other)
{
  if(this != &other)
  {
    if(other.frame->frameType() != 0)
      frame = other.frame;

    // Other buffer gets appended to current buffer
    buffer->store(other.buffer->getBuffer());

    // process data upon assignment
    init(buffer->getBuffer());
    if(frame->completeFlag())
      buffer->clear();
  }

  return *this;
}

QXbee& QXbee::operator = (QXbee&& other)
{
  if(this != &other)
  {
    if(other.frame->frameType() != 0)
      frame = other.frame;

    // Other buffer gets appended to current buffer
    buffer->store(other.buffer->getBuffer());

    // process data upon assignment
    init(buffer->getBuffer());
    if(frame->completeFlag())
      buffer->clear();
  }

  return *this;
}

bool QXbee::consume(QByteArray data)
{
  init(data);
  bool result = isComplete();
  return result;
}

bool QXbee::isComplete()
{
  return frame->completeFlag();
}

QByteArray QXbee::toByteArray()
{
  // temp return
  return QByteArray();
}

void QXbee::init(const QByteArray input)
{
  buffer->store(input);
  FrameHandler::processInput(input, frame.data());
}

}
