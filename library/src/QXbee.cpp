#include "../include/QXbee.h"

namespace QXbee {

QXbee::QXbee():d_ptr(new QXbeePrivate){}

QXbee::QXbee(const QByteArray &ba):d_ptr(new QXbeePrivate){ init(ba); }

QXbee::QXbee(const QString &string):d_ptr(new QXbeePrivate){ init(string.toLatin1()); }

QXbee::~QXbee(){}

QXbee& QXbee::operator = (const QXbee& other)
{
  d_ptr = other.d_ptr;  // This gracefully handles self assignment
  return *this;
}

QXbee& QXbee::operator = (QXbee&& other)
{
  if(this != &other)
  {
    if(d_ptr->frame->getComplete())
      d_ptr->buffer.clear();

    d_ptr->buffer.push_back(other.d_ptr->buffer);
    d_ptr->frame = new Frame(d_ptr->buffer);
  }

  return *this;
}

void QXbee::init(const QByteArray& input)
{
  // keep a copy as buffer
  d_ptr->buffer.push_back(input);

  // sort input into frame data members
  d_ptr->frame = new Frame(input);
}

bool QXbee::isComplete()
{
  return d_ptr->frame->getComplete();
}

QByteArray QXbee::payload()
{
  if(isComplete() && d_ptr->frame)
    return d_ptr->frame->extractPayload();
  else
    return QByteArray();
}

}
