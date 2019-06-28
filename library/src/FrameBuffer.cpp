#include "include/FrameBuffer.h"

namespace QXbee {

FrameBuffer::FrameBuffer()
  :droppedFrames(0)
{
  buffer.clear();
}

FrameBuffer::~FrameBuffer(){}

void FrameBuffer::store(const QByteArray& data)
{
  buffer.push_back(data);
}

QByteArray FrameBuffer::getBuffer() const
{
  return buffer;
}

void FrameBuffer::clear()
{
  buffer.clear();
  droppedFrames++;
}

bool FrameBuffer::isEmpty()
{
  return buffer.isEmpty();
}

quint32 FrameBuffer::droppedCounter()
{
  const quint32 dropped_frames = droppedFrames;
  droppedFrames = 0; //reset
  return dropped_frames;
}

}
