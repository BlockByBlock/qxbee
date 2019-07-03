#include <limits.h>

#include "../include/Frame.h"
#include "../include/Frames/UnidentifiedFrame.h"
#include "../include/Frames/TransmitFrame.h"
#include "../include/Frames/ReceiveFrame.h"

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
  const int accessLimit = input.length();

  // get index of start delimiter in input (in int)
  // only proceed if there is delimiter
  if( input.contains(EscapeByte::StartDelimiter) )
  {
    indexDelimiter = input.indexOf(EscapeByte::StartDelimiter);
    hasDelimiter = true;


    // get frame length from input (in decimal - quint8)
    if( accessLimit >= indexDelimiter + 2 )
      frameLen = (input.at( indexDelimiter + 1 ) << 8) |  input.at( indexDelimiter + 2 );


    // get frame type from input (in decimal - quint8)
    if( accessLimit >= indexDelimiter + 3 )
    {
      const quint8 type = input.at( indexDelimiter + 3);
      if(type > 0)
      {
        frameType = type;
        frameData.reset( constructFrameType(type) );
      }
    }


    // get payload and load into framedata
    // accessLimit is checked in this method
    if( accessLimit >=  indexDelimiter + frameLen  )
    {
      QByteArray data = input.mid(indexDelimiter + 3, frameLen);
      // proceed if frameData is not null
      if(frameData)
        frameData->sortFields(data);
    }


    // Validate Checksum (if checksum is available)
    // 2 is for frame length size
    if( accessLimit >= (indexDelimiter + 3 + frameLen) )
    {
      // +1 for frameLen to include checksum within
      const QByteArray validatorInput = input.mid(indexDelimiter + 3, frameLen + 1);

      if( validateChecksum(validatorInput) )
        isComplete = true;
      else
        isComplete = false;
    }


  } // End of if loop (has delimiter)

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
      return new UnidentifiedFrame;
  }
}


bool Frame::getComplete() const
{
  return isComplete;
}


QByteArray Frame::extractPayload()
{
  return frameData->payload;
}


bool Frame::validateChecksum(const QByteArray& data)
{
  unsigned int sum = 0x00;
  for(unsigned int byte: data)
  {
    if ( byte == UINT_MAX)
      byte = 0xFF;
    else if ( byte == UINT_MAX-1)
      byte = 0xFE;

    sum += byte;
  }

  QByteArray hexChecksum = QByteArray::fromHex(QByteArray::number(sum, 16));
  QByteArray checksum = hexChecksum.right(1);

  if(checksum == QByteArray::fromHex("FF"))
    return true;
  else
    return false;
}


QByteArray Frame::calculateChecksum(const QByteArray& data)
{
  unsigned int sum = 0x00;
  for(unsigned int byte: data)
  {
    if ( byte == UINT_MAX)
      byte = 0xFF;
    else if ( byte == UINT_MAX-1)
      byte = 0xFE;

    sum += byte;
  }

  unsigned preChecksum = (0xFF - sum);
  QByteArray hexChecksum = QByteArray::fromHex(QByteArray::number(preChecksum, 16));
  QByteArray checksum = hexChecksum.right(1);

  return checksum;
}

}

