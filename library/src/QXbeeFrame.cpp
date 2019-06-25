#include "../include/QXbeeFrame.h"

namespace QXbee {

struct QXbeeFramePrivate
{
  QXbeeFrame::ApiFrameType frameType; // Api frame type
  quint16                  frameLen;  // Frame length
  QByteArray               data;      // Frame data
  bool                     allocData; // True if constructor allocates data
};

QXbeeFrame::QXbeeFrame():d(new QXbeeFramePrivate)
{
  d->allocData = false;
}

QXbeeFrame::QXbeeFrame(quint16 len):d(new QXbeeFramePrivate)
{
  d->frameLen = len;
  d->allocData = true;
}

QXbeeFrame::QXbeeFrame(ApiFrameType type, const QByteArray data, quint16 len)
  :d(new QXbeeFramePrivate)
{
  d->data.clear();
  setupFrame(type, data, len);
}

QXbeeFrame::~QXbeeFrame(){}

void QXbeeFrame::setupFrame(ApiFrameType type, QByteArray data, quint16 len)
{
  d->frameType = type;
  d->frameLen = len;
  d->data.clear();

  d->data = data;
  if(d->data.length() != d->frameLen)
  {
    // -1 to make space for escape byte
    d->data = data.chopped(d->frameLen - 1);
    d->data.push_back(EscapeByte::Escape);
  }

  d->allocData = true;
}

void QXbeeFrame::clear()
{
  d->frameLen = 0;
  d->data.clear();
}

void QXbeeFrame::setFrameType(ApiFrameType type)
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

}
