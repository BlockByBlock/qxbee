#include "../include/QXbeeFrameData.h"

namespace QXbee {

QXbeeFrameData::QXbeeFrameData()
  :
    frameType(ApiFrameType::NoApi),
    data(Q_NULLPTR)
{}

QXbeeFrameData::~QXbeeFrameData(){}

QXbeeFrameData::QXbeeFrameData(const QXbeeFrameData &other)
  : QSharedData(other),
    frameType(other.frameType),
    data(other.data)
{}

}
