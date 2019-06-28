#include "include/FrameHandler.h"

namespace QXbee {

FrameHandler::FrameHandler(){}

FrameHandler::~FrameHandler()
{}

void FrameHandler::processInput(const QByteArray& input, QXbeeFrame* frame)
{
  // to prevent accessing null index using QByteArray::at()
  int accessLimit = input.length();

  // get index of start delimiter in input (in int)
  if( input.contains(QXbeeFrame::EscapeByte::StartDelimiter) )
    frame->setIndexDelimiter( input.indexOf(QXbeeFrame::EscapeByte::StartDelimiter) );

  // get frame length from input (in decimal - quint8)
  if( accessLimit >= (frame->indexDelimiter() + 2) )
    frame->setFrameLen( input.at( frame->indexDelimiter() + 1 ) |  input.at( frame->indexDelimiter() + 2 ) );

  // get frame type from input (in decimal - quint8)
  if( accessLimit >= (frame->indexDelimiter() + 3) )
  {
    quint8 type = input.at( frame->indexDelimiter() + 3);
    if(type > 0)
    {
      frame->setFrameType(type);
      constructFrame(frame);
    }
  }

  // get payload and load into framedata
  if( accessLimit >= ( frame->indexDelimiter() + frame->frameLen() ) )
  {
    QByteArray data = input.mid(frame->indexDelimiter() + 3, frame->frameLen());
    frame->setCompleteFlag(true);   
  }
  else
  {
    frame->setCompleteFlag(false);
  }

}

void FrameHandler::constructFrame(QXbeeFrame* frame)
{
  QXbeeFrame::createFrameType( frame->frameType() );
}

}
