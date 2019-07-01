#ifndef QXBEE_PRIVATE_H
#define QXBEE_PRIVATE_H

#include <QSharedData>

namespace QXbee {

/*!
 * \struct The QXbee Private Struct
 * \brief Hold data members of QXbee in PIMPL method
 */
class QXbeePrivate: public QSharedData
{
public:
  /*! Bytes that need to be escaped*/
  enum EscapeByte {
    StartDelimiter = 0x7E,
    Escape = 0x7D
    //XON = 0x11,
    //XOFF = 0x13
  };

  // Constructor that initializes q-ptr
  //QXbeePrivate(QXbee *q): q_ptr(q){}
  //QSharedDataPointer<QXbee> q_ptr;

  QXbeePrivate()
    :
      hasDelimiter(false),
      indexDelimiter(0),
      frameLen(0),
      isComplete(false),
      frameType(0){}

  bool          hasDelimiter;
  int           indexDelimiter;
  quint8        frameLen;
  bool          isComplete;
  QByteArray    buffer;
  quint8        frameType;
};

}

#endif // QXBEE_PRIVATE_H

