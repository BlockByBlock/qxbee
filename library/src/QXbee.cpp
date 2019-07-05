#include "../include/QXbee.h"

namespace QXbee {

QXbee::QXbee():d_ptr(new QXbeePrivate){}

QXbee::QXbee(const QByteArray &ba):d_ptr(new QXbeePrivate){ consume(ba); }

void QXbee::consume(const QByteArray& input)
{
  d_ptr->buffer.push_back(input);

  // sort input into frame data members
  d_ptr->frame.reset( new Frame(d_ptr->buffer) );

  if( isComplete() || d_ptr->buffer.size() > 255 )
    d_ptr->buffer.clear();
}

QByteArray QXbee::produce(const quint8 type, const QByteArray& data)
{
  return d_ptr->frame->wrapPayload(type, data);
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

QHash<QString, QByteArray> QXbee::hash()
{
  if(isComplete() && d_ptr->frame)
    return d_ptr->frame->extractHash();
  else
    return QHash<QString, QByteArray>();
}

}
