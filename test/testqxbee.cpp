#include "testqxbee.h"
#include <include/QXbee.h>

#include <QDebug>

namespace testqxbee {

struct TestQXbeePrivate {

  QXbee::QXbee qxbee;

  QByteArray transmitPacket;
  QByteArray transmitStatus;
  QByteArray receivePacket;
  QByteArray packetToProduce;
};

TestQXbee::TestQXbee(QObject *parent)
    :QObject(parent), d(new TestQXbeePrivate)
  {}

TestQXbee::~TestQXbee(){}

void TestQXbee::initTestCase()
{
  /// ----- Test Case One -----
  /// Sending a JSON packet over broadcast with
  /// expect status reply and receive packet reply
  d->transmitPacket =
      QByteArray::fromHex("7E004D1001000000000000FFFFFFFE00007B226964223A223078636261333231222C22746F706963223A226374726C222C226E616D65223A226C696768745F6C766C222C2276616C7565223A2230227DB7");
  d->transmitStatus =
      QByteArray::fromHex("7E00078B01FFFE00000076");
  d->receivePacket =
      QByteArray::fromHex("7E0072900013A2004187F3E7D053017B226964223A223078303031633030346633373431353030613230333433333437222C226E616D65223A22222C2274696D65223A22313937302D30312D30315430323A32303A33355A222C22746F706963223A22696E666F222C2276616C7565223A2230227D1D");
  d->packetToProduce =
      QByteArray::fromHex("1001000000000000FFFFFFFE00007B226964223A223078636261333231222C22746F706963223A226374726C222C226E616D65223A226C696768745F6C766C222C2276616C7565223A2230227D");
}

void TestQXbee::cleanupTestCase(){}

void TestQXbee::init(){}

void TestQXbee::test()
{
  // Complete receive package
  d->qxbee.consume(d->receivePacket);

  // produce transmit package
  d->packetToProduce =
      QByteArray::fromHex("01000000000000FFFFFFFE00007B202020226964223A2270795A5468586F34314B222C0A2020202022746F706963223A226374726C222C0A20202020226E616D65223A226C696768745F6C766C222C0A202020202276616C7565223A2230220A7D");
  QByteArray completeFrame = d->qxbee.produce(16, d->packetToProduce);
  d->qxbee.consume(completeFrame);
}

void TestQXbee::cleanup(){}
}
