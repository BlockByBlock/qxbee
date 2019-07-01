#include "../include/QXbee.h"

namespace QXbee {

QXbee::QXbee():d_ptr(new QXbeePrivate){}

QXbee::QXbee(const QByteArray &ba):d_ptr(new QXbeePrivate){ consume(ba); }

QXbee::QXbee(const QString &string):d_ptr(new QXbeePrivate){ consume(string.toLatin1()); }

QXbee::~QXbee(){}

QXbee::QXbee(const QXbee &other):d_ptr(other.d_ptr){}

QXbee::QXbee(QXbee&& other)
{
  if(other.d_ptr->hasDelimiter)
  {
    d_ptr->hasDelimiter = true;
    d_ptr->indexDelimiter = other.d_ptr->indexDelimiter;
  }

  if(other.d_ptr->frameLen > 0)
    d_ptr->frameLen = other.d_ptr->frameLen;

  if(other.d_ptr->frameType > 0)
    d_ptr->frameType = other.d_ptr->frameType;

  d_ptr->buffer.push_back(other.d_ptr->buffer);
}

QXbee& QXbee::operator = (const QXbee& other)
{
  d_ptr = other.d_ptr;  // This gracefully handles self assignment
  return *this;
}

QXbee& QXbee::operator = (QXbee&& other)
{
  if(this != &other)
  {
    if(other.d_ptr->hasDelimiter)
    {
      d_ptr->hasDelimiter = true;
      d_ptr->indexDelimiter = other.d_ptr->indexDelimiter;
    }

    if(other.d_ptr->frameLen > 0)
      d_ptr->frameLen = other.d_ptr->frameLen;

    if(other.d_ptr->frameType > 0)
      d_ptr->frameType = other.d_ptr->frameType;

    d_ptr->buffer.push_back(other.d_ptr->buffer);
  }

  return *this;
}

bool QXbee::consume(const QByteArray& input)
{
  // keep a copy as buffer
  d_ptr->buffer.push_back(input);

  // to prevent accessing null index using QByteArray::at()
  int accessLimit = input.length();

  // get index of start delimiter in input (in int)
  if( input.contains(QXbeePrivate::EscapeByte::StartDelimiter) )
  {
    d_ptr->indexDelimiter = input.indexOf(QXbeePrivate::EscapeByte::StartDelimiter);
    d_ptr->hasDelimiter = true;
  }

  // get frame length from input (in decimal - quint8)
  if( accessLimit >= d_ptr->indexDelimiter + 2 )
    d_ptr->frameLen = input.at( d_ptr->indexDelimiter + 1 ) |  input.at( d_ptr->indexDelimiter + 2 );

  // get frame type from input (in decimal - quint8)
  if( accessLimit >= d_ptr->indexDelimiter + 3 )
  {
    quint8 type = input.at( d_ptr->indexDelimiter + 3);
    if(type > 0)
    {
      d_ptr->frameType = type;
      //d_ptr->createFrameType( d_ptr->frameType() );
    }
  }

  // get payload and load into framedata
  if( accessLimit >=  d_ptr->indexDelimiter + d_ptr->frameLen  )
  {
    QByteArray data = input.mid(d_ptr->indexDelimiter + 3, d_ptr->frameLen);
    d_ptr->isComplete = true;
  }
  else
  {
    d_ptr->isComplete = false;
  }

  bool result = isComplete();
  return result;
}

bool QXbee::isComplete()
{
  return d_ptr->isComplete;
}

QByteArray QXbee::toByteArray()
{
  // temp return
  return QByteArray();
}


}
