#ifndef QXBEE_H
#define QXBEE_H

#include <QSharedData>
#include <QSharedDataPointer>
#include "QXbee_global.h"
#include "QXbeePrivate.h"

namespace QXbee {

/*!
 * \class The QXbee class
 * \brief Construct/Process Xbee data to make it useful
 *
 * (Bridge design with Pimpl idiom)
 *
 *        QXbee - QXbeePrivate
 *          |
 *        Frame (Abstraction) - FrameImplementation
 *          |
 *          | (Inheritance)
 *          |
 *        RefinedFrame - ConcreteFrameImplementation
 *
 */
class QXBEESHARED_EXPORT QXbee
{
public:

  /*! Default Constructor */
  QXbee();

  /**
   * \brief Overloaded Constructor
   * \param QByteArray input
   */
  QXbee(const QByteArray& ba);

  /*!
   * \brief Overloaded Constructor
   * \param QString input
   */
  QXbee(const QString& string);

  /*! Implicit Destructor */
  ~QXbee();

  /*!
   * \brief Copy Constructor
   * \param QXbee object
  */
  QXbee(const QXbee& other);

  /*!
   * \brief Move Constructor (for rvalue)
   * \param QXbee Object
   * \note
   *    - isComplete is overwritten if true or other is true
   *    - indexDelimiter is overwritten if true
   *    - frameLen is overwritten if not zero
   *    - frameType is overwritten if not zero
   *    - buffer is combined and consume()
   *    - buffer is clear if consume() return true
   * \note use
   *    e.g. QXbee one(QXbee(input));
   */
  QXbee(QXbee&& other);

  /*!
   * \brief Copy Assignment Operator
   * \param QXbee Object
   * \return QXbee Object
   */
  QXbee& operator = (const QXbee &other);

  /*!
   * \brief Move Assignment Operator (for rvalue)
   * \param QXbee Object
   * \return QXbee Object
   * \note
   *    - isComplete is overwritten if true or other is true
   *    - indexDelimiter is overwritten if true
   *    - frameLen is overwritten if not zero
   *    - frameType is overwritten if not zero
   *    - buffer is combined and consume()
   *    - buffer is clear if consume() return true
   * \note use
   *    e.g. QXbee one = QXbee(input);
   */
  QXbee& operator = (QXbee&& other);

  /*!
   * \brief Process data into a frame
   * \param Serial input/output from Xbee
   * \return True if frame is completed
   */
  bool consume(const QByteArray& data);

  /*!
   * @brief Check if frame is completed
   * @return True if complete frame
   */
  bool isComplete();

  /*!
   * \brief Convert frame to QByteArray
   * \return Frame in QByteArray type
   */
  QByteArray toByteArray();

  /*!
   * \brief Clear buffer and count dropped frame
   */
  void clear();

  /*!
   * \brief isEmpty
   * \return True if buffer is empty
   */
  bool isEmpty();

protected:
  QXbee(QXbeePrivate& d_ptr);
  QSharedDataPointer<QXbeePrivate> d_ptr;

};

}
#endif // QXBEE_H
