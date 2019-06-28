#include "../include/QXbeeFrameData.h"

namespace QXbee {

QXbeeFrameData::QXbeeFrameData()
  :
    frameType(ApiFrameType::NoApi),
    dataByteArray(Q_NULLPTR)
{}

QXbeeFrameData::~QXbeeFrameData(){}

QXbeeFrameData::QXbeeFrameData(const QXbeeFrameData &other)
  : QSharedData(other),
    frameType(other.frameType),
    dataByteArray(other.dataByteArray)
{}

void QXbeeFrameData::sortData(const QByteArray &data)
{
  dataByteArray = data;
}

}
