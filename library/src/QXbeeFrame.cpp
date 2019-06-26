#include "../include/QXbeeFrame.h"

namespace QXbee {

QXbeeFrame::QXbeeFrame(QObject *parent)
  :QXbee(parent), d(new QXbeeFrameData){}

QXbeeFrame::~QXbeeFrame(){}

QXbeeFrame::QXbeeFrame(const QXbeeFrame &other):d(other.d){}

void QXbeeFrame::clear()
{
  d->frameLen = 0;
  d->data.clear();
}

void QXbeeFrame::setFrameType(QXbeeFrameData::ApiFrameType type)
{
  d->frameType = type;
}

quint16 QXbeeFrame::getDataLen() const
{
  return d->frameLen;
}

void QXbeeFrame::setDataLen(quint16 len)
{
  d->frameLen = len;
}

void QXbeeFrame::processData(QByteArray data)
{
  if(data.contains(EscapeByte::StartDelimiter))
  {

  }
  else
  {

  }
}

}
