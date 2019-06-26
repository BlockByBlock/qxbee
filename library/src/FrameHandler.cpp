#include "include/FrameHandler.h"
#include "include/QXbeeFrame.h"

namespace QXbee {

FrameHandler::FrameHandler(){}

FrameHandler::~FrameHandler()
{}

QXbeeFrameData::ApiFrameType FrameHandler::getType()
{
  QXbeeFrameData::ApiFrameType frameType(QXbeeFrameData::ApiFrameType::NoApi);
  return frameType;
}

void FrameHandler::processData(const QByteArray& input, QXbeeFrameData* data)
{
  int accessLimit = input.length();

  // get index of start delimiter in input
  if( input.contains(QXbeeFrame::EscapeByte::StartDelimiter) )
  {
    data->indexDelimiter = input.indexOf(QXbeeFrame::EscapeByte::StartDelimiter);
  }

  // get frame length from input
  if( accessLimit >= (data->indexDelimiter + 2) )
  {
    data->frameLen = (input.at( data->indexDelimiter + 1 ) << 8) |  input.at( data->indexDelimiter + 2 ) ;
  }

}

}
