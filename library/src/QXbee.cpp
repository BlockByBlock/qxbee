#include "../include/QXbee.h"

namespace QXbee {

QXbee::QXbee(const QByteArray &ba):d_ptr(new QXbeeFrame){ init(ba); }

QXbee::QXbee(const QString &string):d_ptr(new QXbeeFrame){ init(string.toLatin1()); }

QXbee::~QXbee(){}

QXbee::QXbee(const QXbee &other):d_ptr(other.d_ptr){}

QXbee::QXbee(QXbee&& other)
{
  if(this != &other)
  {
    if(other.d_ptr->frameType() != 0)
      d_ptr = other.d_ptr;

    /*
    // Other buffer gets appended to current buffer
    buffer->store(other.buffer->getBuffer());

    // process data upon assignment
    init(buffer->getBuffer());
    if(d_ptr->completeFlag())
      buffer->clear();
   */
  }
}

QXbee& QXbee::operator = (const QXbee& other)
{
  if(this != &other)
  {
    if(other.d_ptr->frameType() != 0)
      d_ptr = other.d_ptr;

    /*
    // Other buffer gets appended to current buffer
    buffer->store(other.buffer->getBuffer());

    // process data upon assignment
    init(buffer->getBuffer());
    if(d_ptr->completeFlag())
      buffer->clear();
   */
  }

  return *this;
}

QXbee& QXbee::operator = (QXbee&& other)
{
  if(this != &other)
  {
    if(other.d_ptr->frameType() != 0 || other.d_ptr->completeFlag())
      d_ptr = other.d_ptr;

    /*
    // Other buffer gets appended to current buffer
    buffer->store(other.buffer->getBuffer());

    // process data upon assignment
    init(buffer->getBuffer());
    if(d_ptr->completeFlag())
      buffer->clear();
   */
  }

  return *this;
}

bool QXbee::consume(QByteArray data)
{
  init(data);
  bool result = isComplete();
  return result;
}

bool QXbee::isComplete()
{
  return d_ptr->completeFlag();
}

QByteArray QXbee::toByteArray()
{
  // temp return
  return QByteArray();
}

void QXbee::init(const QByteArray input)
{
  store(input);
  processInput(input);
}

void QXbee::processInput(const QByteArray& input)
{
  // to prevent accessing null index using QByteArray::at()
  int accessLimit = input.length();

  // get index of start delimiter in input (in int)
  if( input.contains(QXbeeFrame::EscapeByte::StartDelimiter) )
    d_ptr->setIndexDelimiter( input.indexOf(QXbeeFrame::EscapeByte::StartDelimiter) );

  // get frame length from input (in decimal - quint8)
  if( accessLimit >= (d_ptr->indexDelimiter() + 2) )
    d_ptr->setFrameLen( input.at( d_ptr->indexDelimiter() + 1 ) |  input.at( d_ptr->indexDelimiter() + 2 ) );

  // get frame type from input (in decimal - quint8)
  if( accessLimit >= (d_ptr->indexDelimiter() + 3) )
  {
    quint8 type = input.at( d_ptr->indexDelimiter() + 3);
    if(type > 0)
    {
      d_ptr->setFrameType(type);
      d_ptr->createFrameType( d_ptr->frameType() );
    }
  }

  // get payload and load into framedata
  if( accessLimit >= ( d_ptr->indexDelimiter() + d_ptr->frameLen() ) )
  {
    QByteArray data = input.mid(d_ptr->indexDelimiter() + 3, d_ptr->frameLen());
    d_ptr->setCompleteFlag(true);
  }
  else
  {
    d_ptr->setCompleteFlag(false);
  }

}

}
