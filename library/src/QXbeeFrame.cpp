#include "../include/QXbeeFrame.h"

#include "../include/Frames/TransmitFrame.h"
#include "../include/Frames/ReceiveFrame.h"

namespace QXbee {

QXbeeFrame::QXbeeFrame():
  _indexDelimiter(0),
  _frameLen(0),
  d(new QXbeeFrameData){}

QXbeeFrame::~QXbeeFrame(){}

QXbeeFrame::QXbeeFrame(const QXbeeFrame &other):
  QSharedData(other),
  _indexDelimiter(other._indexDelimiter),
  _frameLen(other._frameLen),
  d(other.d)
{}

int QXbeeFrame::indexDelimiter() const { return _indexDelimiter; }

void QXbeeFrame::setIndexDelimiter(int val){ _indexDelimiter = val; }

quint16 QXbeeFrame::frameLen() const { return _frameLen; }

void QXbeeFrame::setFrameLen(quint16 val){ _frameLen = val; }

quint8 QXbeeFrame::frameType() const { return d->frameType; }

void QXbeeFrame::setFrameType(quint8 val){ d->frameType = val; }

bool QXbeeFrame::completeFlag() const { return _completeFlag; }

void QXbeeFrame::setCompleteFlag(bool val){ _completeFlag = val; }

void QXbeeFrame::clearData()
{
  _indexDelimiter = 0;
  _frameLen = 0;
  _completeFlag = false;
}

QXbeeFrameData* QXbeeFrame::createFrameType(quint8 type)
{
  switch(type)
  {
    case 16:
      return new TransmitFrame;
    case 144:
      return new ReceiveFrame;
    default:
      return new QXbeeFrameData;
  }
}

//QXbeeFrameData* QXbeeFrame::setFrameType(ApiFrameType type){}

}
