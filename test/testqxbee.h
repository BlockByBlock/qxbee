#ifndef TEST_QXBEE_H
#define TEST_QXBEE_H

#include <QObject>
#include <QScopedPointer>
#include <QtTest/QTest>

namespace testqxbee {
struct TestQXbeePrivate;
class TestQXbee : public QObject
{
  Q_OBJECT
public:
  TestQXbee(QObject *parent=Q_NULLPTR);
  ~TestQXbee();

private slots:
  void initTestCase(); //called before the first test function is executed
  void cleanupTestCase(); //called after the last test function was executed
  void init(); //will be called before each test function is executed
  void cleanup(); //will be called after every test function

private:
  QScopedPointer<TestQXbeePrivate> d;
};
}
#endif  // TEST_QXBEE_H
