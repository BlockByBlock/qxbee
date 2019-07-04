#include "../include/QXbee.h"

namespace QXbee {

QXbee::QXbee():d_ptr(new QXbeePrivate){}

QXbee::QXbee(const QByteArray &ba):d_ptr(new QXbeePrivate){ consume(ba); }

void QXbee::consume(const QByteArray& input)
{
  d_ptr->buffer.push_back(input);

  // sort input into frame data members
  d_ptr->frame = new Frame(d_ptr->buffer);
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
