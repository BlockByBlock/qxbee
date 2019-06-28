#ifndef QXBEE_H
#define QXBEE_H

#include <QSharedDataPointer>
#include <QString>
#include "QXbee_global.h"
#include "QXbeeFrame.h"
#include "FrameBuffer.h"

namespace QXbee {

/*!
 * \class The QXbee class
 * \brief Construct/Process Xbee data to make it useful
 *
 *                    ----------QXbee-----------
 *                    |           |             |
 *             FrameHandler   QXbeeFrame    FrameBuffer
 *               (static)     (factory)       (cache)
 *                                |
 *                     (specific)FrameData
 *
 * FrameHandler - manipulate frame externally
 * QXbeeFrame - contains delimiter index, frame length
 *            - manipulate data internally
 * QXbeeFrameData - payload class which changes with frame type
 * FrameBuffer - store data for future uses
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

  /*! Destructor */
  ~QXbee();

  /*!
   * \brief Copy Constructor
   *   e.g. QXbee one("input");
   *        QXbee two(one);
   * \param QXbee object
  */
  QXbee(const QXbee& other);

  /*!
   * \brief Move Constructor
   *   e.g. QXbee one, two;
   *        one = std::move(two);
   *  \note Other buffer gets appended to current buffer
   *  \param QXbee Object
   */
  QXbee(QXbee&& other);

  /*!
   * \brief Copy Assignment Operator
   *   e.g. QXbee one, two;
   *        one = two;
   * \note Other buffer gets appended to current buffer
   * \param QXbee Object
   * \return QXbee Object
   */
  QXbee& operator = (const QXbee &other);

  /*!
   * \brief Move Assignment Operator
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

protected:
  void init(const QByteArray input);

private:
  QSharedDataPointer<QXbeeFrame>  frame;
  QSharedDataPointer<FrameBuffer> buffer;
};

}
#endif // QXBEE_H
