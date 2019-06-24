#include "include/xbeeGenericPacket.h"
#include <limits.h>

namespace QXbee {

struct XbeeGenericPacketPrivate
{
  unsigned char startDelimiter;
  short frameLength;
  XbeeGenericPacket::ApiFrameType frameType;
  unsigned char frameId;
  unsigned char checksum;

  QByteArray frame;                 // delimiter, frame length, frame data, checksum
  QByteArray frameData;             // frame type, frame id, payload
  QByteArray frameDataWithChecksum; // frame data with checksum
  QByteArray payload;               // payload
};

XbeeGenericPacket::XbeeGenericPacket(QObject *parent)
  :QXbee(parent)
{}

XbeeGenericPacket::~XbeeGenericPacket(){}

short XbeeGenericPacket::frameLength(){ return d->frameLength; }

void XbeeGenericPacket::setFrameLength(short val){ d->frameLength = val; }

XbeeGenericPacket::ApiFrameType XbeeGenericPacket::frameType(){ return d->frameType; }

void XbeeGenericPacket::setFrameType(XbeeGenericPacket::ApiFrameType val){ d->frameType = val; }

unsigned char XbeeGenericPacket::checksum(){ return d->checksum; }

void XbeeGenericPacket::setChecksum(unsigned char val){ d->checksum = val; }

QByteArray XbeeGenericPacket::frame(){ return d->frame; }

QByteArray XbeeGenericPacket::frameData(){ return d->frameData; }

QByteArray XbeeGenericPacket::payload(){ return d->payload; }

/**
 * @brief Clear the frame
 */
void XbeeGenericPacket::clearFrame(){
  d->frame.clear();
  d->frameData.clear();
  d->payload.clear();

  d->frameLength = 0;
  d->frameType = ApiFrameType::NoApi;
  d->frameId = 0;
  d->checksum = 0;
}

QString XbeeGenericPacket::toString()
{
  return QString();
}

/**
 * @brief Calculate sum of bytes of input
 * @param
 *          frameData - frame type, frame id, payload
 *          frameDataWithChecksum - frameData with checksum
 *
 * @return Sum of input
 */
unsigned int XbeeGenericPacket::calculateSum(QByteArray data)
{
  unsigned int sum = 0;

  for(QByteArray::iterator iter = data.begin(); iter != data.end(); ++iter)
  {
    unsigned char eachByte = static_cast<unsigned char>(*iter);

    // if byte size is ambiguous
    if (eachByte == UCHAR_MAX)
      eachByte = 0xFF;
    else if (eachByte == UCHAR_MAX-1)
      eachByte = 0xFE;

    // add each byte to checksum
    sum+= eachByte;
  }

  return sum;
}

/**
 * @brief Calculate checksum
 * @param frameData - frame type, frame id, payload
 */
void XbeeGenericPacket::calculateChecksum(QByteArray)
{
  //unsigned beforeChecksum = (0xFF - calculateSum(frameData));
}

/**
 * @brief Verify checksum
 * @param frameData with checksum at the last byte
 * @return true if checksum is valid
 */
bool XbeeGenericPacket::verifyChecksum(QByteArray)
{
  //unsigned char validChecksum = 0xFF;
  return false;
}

}

