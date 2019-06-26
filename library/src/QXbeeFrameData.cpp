#include "../include/QXbeeFrameData.h"

namespace QXbee {

QXbeeFrameData::QXbeeFrameData()
  :
    frameType(ApiFrameType::NoApi),
    frameLen(0),
    data(Q_NULLPTR)
{}

QXbeeFrameData::~QXbeeFrameData(){}

QXbeeFrameData::QXbeeFrameData(const QXbeeFrameData &other)
  : QSharedData(other),
    frameType(other.frameType),
    frameLen(other.frameLen),
    data(other.data)
{}

}
