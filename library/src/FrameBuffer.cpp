#include "include/FrameBuffer.h"

namespace QXbee {

struct FrameBufferPrivate
{
  QByteArray              buffer;
  quint32                 droppedFrames;
};

FrameBuffer::FrameBuffer()
  :d(new FrameBufferPrivate)
{
  d->droppedFrames = 0;
}

FrameBuffer::~FrameBuffer(){}

void FrameBuffer::store(const QByteArray data)
{
  d->buffer.push_back(data);
}

void FrameBuffer::clear()
{
  d->droppedFrames++;
}

quint32 FrameBuffer::droppedCounter()
{
  const quint32 dropped_frames = d->droppedFrames;
  d->droppedFrames = 0; //reset
  return dropped_frames;
}

}
