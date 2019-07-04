#include <limits.h>

#include "../include/Frame.h"
#include "../include/Frames/UnidentifiedFrame.h"
#include "../include/Frames/TransmitFrame.h"
#include "../include/Frames/ReceiveFrame.h"

namespace QXbee {

Frame::Frame(QByteArray& input)
{
  populateFrame(input);
}


void Frame::populateFrame(QByteArray &input)
{
  // only proceed if there is delimiter
  if( input.contains(EscapeByte::StartDelimiter) )
  {
    // Will pick up the first delimiter even if there is multiple
    int indexDelimiter = input.indexOf(EscapeByte::StartDelimiter);
    hasDelimiter = true;


    // move delimiter to index 0 (in new copy)
    input = input.right( input.size() - indexDelimiter );

    // to prevent accessing null index using QByteArray::at()
    const int accessLimit = input.size();


    // get frame length from input (in decimal - quint8)
    // NOTE: Frame length consist of 2 bytes, only 1 is used
    if( accessLimit >= 3 )
      frameLen = input.at(2);


    // get frame type from input (in decimal - quint8)
    if( accessLimit >= 4 )
    {
      const quint8 type = input.at(3);
      if(type > 0)
      {
        frameType = type;
        frameData.reset( constructFrameType(type) );
      }
    }


    // get payload and load into framedata
    // +4 for delimiter, framelen and checksum
    if( accessLimit >= frameLen + 4 )
    {
      // checksum validation
      input = input.mid(3, frameLen + 1);
      if( validateChecksum(input) )
      {
        input.chop(1);  // remove checksum byte

        // proceed is length is correctt and frameData is not null
        if(input.length() == frameLen && frameData)
        {
          frameData->sortFields(input);
          isComplete = true;
        }
      }
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
  if(frameData)
    return frameData->payload;
  else
    return QByteArray();
}


QHash<QString, QByteArray> Frame::extractHash()
{
  if(frameData)
    return frameData->hash;
  else
    return QHash<QString, QByteArray>();
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

