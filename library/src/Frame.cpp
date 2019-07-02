#include "../include/Frame.h"
#include "../include/Frames/TransmitFrame.h"
#include "../include/Frames/ReceiveFrame.h"

namespace QXbee {

Frame::Frame(const QByteArray& input)
  :hasDelimiter(false),
   isComplete(false),
   indexDelimiter(0),
   frameType(0),
   frameLen(0),
   checksum(0),
   frameData(new FrameData(FrameData::NoApi))
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
      frameData.reset( constructFrameType(type) );
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

FrameData* Frame::constructFrameType(quint8 type)
{
  switch(type)
  {
    case 16:
      return new TransmitFrame;
    case 144:
      return new ReceiveFrame;
    default:
      return new FrameData(FrameData::NoApi);
  }
}

bool Frame::getComplete() const
{
  return isComplete;
}

}
