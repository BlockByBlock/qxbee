#include "include/FrameHandler.h"

namespace QXbee {

FrameHandler::FrameHandler(QObject *parent)
  :QXbee(parent)
{}

FrameHandler::~FrameHandler()
{}

QXbeeFrameData::ApiFrameType FrameHandler::getType() const
{
  QXbeeFrameData::ApiFrameType frameType(QXbeeFrameData::ApiFrameType::NoApi);
  return frameType;
}

}
