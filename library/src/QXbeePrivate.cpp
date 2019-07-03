#include "../include/QXbeePrivate.h"

namespace QXbee {

QXbeePrivate::QXbeePrivate():frame(new Frame){}

QXbeePrivate::QXbeePrivate(const QXbeePrivate& other)
  :QSharedData(other), frame(other.frame), buffer(other.buffer){}

}
