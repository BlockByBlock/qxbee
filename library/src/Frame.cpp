#include "../include/Frame.h"

namespace QXbee {

Frame::Frame(const QByteArray& input)
{
  populateFrame(input);
}

Frame::Frame(const Frame& other)
  :QSharedData(other){}

void Frame::populateFrame(const QByteArray &input)
{
  // to prevent accessing null index using QByteArray::at()
  int accessLimit = input.length();

  // get index of start delimiter in input (in int)
  if( input.contains(EscapeByte::StartDelimiter) )
  {
    indexDelimiter = input.indexOf(EscapeByte::StartDelimiter);
    hasDelimiter = true;
  }

  // get frame length from input (in decimal - quint8)
  if( accessLimit >= indexDelimiter + 2 )
    frameLen = input.at( indexDelimiter + 1 ) |  input.at( indexDelimiter + 2 );

  // get frame type from input (in decimal - quint8)
  if( accessLimit >= indexDelimiter + 3 )
  {
    quint8 type = input.at( indexDelimiter + 3);
    if(type > 0)
    {
      frameType = type;
      //d_ptr->createFrameType( d_ptr->frameType() );
    }
  }

  // get payload and load into framedata
  if( accessLimit >=  indexDelimiter + frameLen  )
  {
    QByteArray data = input.mid(indexDelimiter + 3, frameLen);
    isComplete = true;
  }
  else
  {
    isComplete = false;
  }
}

bool Frame::getComplete() const
{
  return isComplete;
}

}
