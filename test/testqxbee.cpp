#include "testqxbee.h"
#include <../library/include/qxbee.h>

namespace testqxbee {

struct TestQXbeePrivate {
  QXbee::QXbee qxbee;
};

TestQXbee::TestQXbee(QObject *parent)
    :QObject(parent), d(new TestQXbeePrivate)
  {}

TestQXbee::~TestQXbee(){}

void TestQXbee::initTestCase(){}
void TestQXbee::cleanupTestCase(){}
void TestQXbee::init(){}
void TestQXbee::cleanup(){}
}
