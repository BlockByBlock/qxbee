#include "../include/QXbeeFrame.h"
#include "../include/Frames/TransmitFrame.h"
#include "../include/Frames/ReceiveFrame.h"

namespace QXbee {

QXbeeFrame::QXbeeFrame():d(new QXbeeFrameData){}

QXbeeFrame::~QXbeeFrame(){}

QXbeeFrame::QXbeeFrame(const QXbeeFrame &other):
  QSharedData(other),
  d(other.d)
{}

int QXbeeFrame::indexDelimiter(){ return d->indexDelimiter; }

void QXbeeFrame::setIndexDelimiter(int val){ d->indexDelimiter = val; }

quint16 QXbeeFrame::frameLen(){ return d->frameLen; }

void QXbeeFrame::setFrameLen(quint16 val){ d->frameLen = val; }

quint8 QXbeeFrame::frameType(){ return d->frameType; }

void QXbeeFrame::setFrameType(quint8 val){ d->frameType = val; }

bool QXbeeFrame::isComplete(){ return true; }

//bool QXbeeFrame::setFrame(quint8 frameType)
//{}

void QXbeeFrame::clear(){}

}
