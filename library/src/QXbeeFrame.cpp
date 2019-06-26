#include "../include/QXbeeFrame.h"

namespace QXbee {

QXbeeFrame::QXbeeFrame(){}

QXbeeFrame::~QXbeeFrame(){}

void QXbeeFrame::clear()
{}

void QXbeeFrame::setFrameType(QXbeeFrameData::ApiFrameType)
{}

quint16 QXbeeFrame::getDataLen() const
{
  return quint16();
}

void QXbeeFrame::setDataLen(quint16)
{
}

void QXbeeFrame::processData(QByteArray data)
{
  if(data.contains(EscapeByte::StartDelimiter))
  {
    return;
  }
  else
  {
    return;
  }
}

}
