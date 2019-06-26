#include "include/FrameHandler.h"
#include "include/QXbeeFrame.h"

namespace QXbee {

FrameHandler::FrameHandler(){}

FrameHandler::~FrameHandler()
{}

void FrameHandler::processData(const QByteArray& input, QXbeeFrameData* data)
{
  int accessLimit = input.length();

  // get index of start delimiter in input
  if( input.contains(QXbeeFrame::EscapeByte::StartDelimiter) )
    data->indexDelimiter = input.indexOf(QXbeeFrame::EscapeByte::StartDelimiter);

  // get frame length from input (in decimal)
  if( accessLimit >= (data->indexDelimiter + 2) )
    data->frameLen = input.at( data->indexDelimiter + 1 ) |  input.at( data->indexDelimiter + 2 ) ;

  // get frame type from input (in decimal)
  if ( accessLimit >= (data->indexDelimiter + 3))
    data->frameType  = input.at( data->indexDelimiter + 3);

}

}
