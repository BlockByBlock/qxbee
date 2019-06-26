#include "include/FrameBuffer.h"

namespace QXbee {

struct FrameBufferPrivate
{
  quint32                 droppedFrames;
};

FrameBuffer::FrameBuffer(QObject *parent)
  :QXbee(parent), d(new FrameBufferPrivate)
{
  d->droppedFrames = 0;
}

FrameBuffer::~FrameBuffer(){}

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
