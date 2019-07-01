#include "../include/Frame.h"

namespace QXbee {

Frame::~Frame(){}

Frame::Frame(const Frame &other)
  : QSharedData(other)
{}

void Frame::sortData(const QByteArray &data)
{
  _data = data;
}

}
