#include "include/FrameHandler.h"

namespace QXbee {

FrameHandler::FrameHandler(){}

FrameHandler::~FrameHandler()
{}

void FrameHandler::processInput(const QByteArray& input, QXbeeFrame* frame)
{
  int accessLimit = input.length();

  // get index of start delimiter in input
  if( input.contains(QXbeeFrame::EscapeByte::StartDelimiter) )
    frame->setIndexDelimiter( input.indexOf(QXbeeFrame::EscapeByte::StartDelimiter) );

  // get frame length from input (in decimal)
  if( accessLimit >= (frame->indexDelimiter() + 2) )
    frame->setFrameLen( input.at( frame->indexDelimiter() + 1 ) |  input.at( frame->indexDelimiter() + 2 ) );

  // get frame type from input (in decimal)
  if ( accessLimit >= (frame->indexDelimiter() + 3))
  {
    quint8 type = input.at( frame->indexDelimiter() + 3);
    if(type > 0)
    {
      frame->setFrameType(type);
      constructFrame(frame);
    }
  }

}

void FrameHandler::constructFrame(QXbeeFrame* frame)
{
  QXbeeFrame::createFrameType( frame->frameType() );
}

}
