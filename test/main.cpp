#include <QCoreApplication>
#include <QtTest/QtTest>
#include "testqxbee.h"

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);
  testqxbee::TestQXbee testQXbee;
  QTest::qExec(&testQXbee);

  return app.exec();
}
