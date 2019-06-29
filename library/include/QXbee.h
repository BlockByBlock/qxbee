#ifndef QXBEE_H
#define QXBEE_H

#include <QSharedDataPointer>
#include <QString>
#include "QXbee_global.h"
#include "QXbeeFrame.h"

#define MAX_BUFFER_SIZE = 255

namespace QXbee {

/*!
 * \class The QXbee class
 * \brief Construct/Process Xbee data to make it useful
 *
 *        QXbee
 *          |
 *       QXbeeFrame
 *       (factory)
 *          |
 *  (specific)FrameData
 *
 * QXbeeFrame - contains delimiter index, frame length
 *            - manipulate data internally
 * QXbeeFrameData - payload class which changes with frame type
 *
 */
class QXBEESHARED_EXPORT QXbee
{
public:

  /*! Default Constructor */
  QXbee() = default;

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
   *   e.g. QXbee one("input");
   *        QXbee two(one);
   * \note Other frame is moved if not 0
   * \note Other frame is moved if completed
   * \note Other buffer gets appended to current buffer
   * \param QXbee object
  */
  QXbee(const QXbee& other);

  /*!
   * \brief Move Constructor
   *   e.g. QXbee one(QXbee two);
   * \note Other frame is moved if not 0
   * \note Other frame is moved if completed
   * \note Other buffer gets appended to current buffer
   * \param QXbee Object
   */
  QXbee(QXbee&& other);

  /*!
   * \brief Copy Assignment Operator
   *   e.g. QXbee one, two;
   *        one = two;
   * \note Other frame is moved if not 0
   * \note Other frame is moved if completed
   * \note Other buffer gets appended to current buffer
   * \param QXbee Object
   * \return QXbee Object
   */
  QXbee& operator = (const QXbee &other);

  /*!
   * \brief Move Assignment Operator
   *   e.g. QXbee one;
   *        one = rvalue;
   * \note Other frame is moved if not 0
   * \note Other frame is moved if completed
   * \note Other buffer gets appended to current buffer
   * \param QXbee Object
   * \return QXbee Object
   */
  QXbee& operator = (QXbee&& other);

  /*!
   * \brief Process data into a frame
   * \param Serial input/output from Xbee
   * \return True if frame is completed
   */
  bool consume(QByteArray data);

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

  /**
   * @brief Process the data to set delimiter, frameLen, frameTypr
   * @param raw input from serial i/o
   * @param QXbeeFrame pointer
   */
  void processInput(const QByteArray& input);

  /*!
   * \brief Store as buffer for uses
   * \param Data to be stored into the buffer
   */
  void store(const QByteArray& data);

  /*!
   * \brief Get Buffer
   * \return buffer
   */
  QByteArray getBuffer() const;

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
  void init(const QByteArray input);
  QXbee(QXbeeFrame& d_ptr);
  QSharedDataPointer<QXbeeFrame> d_ptr;

};

}
#endif // QXBEE_H
