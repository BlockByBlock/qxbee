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
 *        QXbee - QXbeePrivate
 *                  |     |
 *        AbstractFrame  Buffer
 *                  |
 *         DerivedFrame
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
   * \brief Copy Constructor disabled
  */
  QXbee(const QXbee& other) = delete;

  /*!
   * \brief Move Constructor disabled
   */
  QXbee(QXbee&& other) = delete;

  /*!
   * \brief Copy Assignment Operator
   * \param QXbee Object
   * \return QXbee Object
   */
  QXbee& operator = (const QXbee &other);

  /*!
   * \brief Move Assignment Operator
   * \note See QXbeePrivate move assignment operator
   */
  QXbee& operator = (QXbee&& other);

  /*!
   * \brief Process data into a frame
   * \param Serial input/output from Xbee
   */
  void init(const QByteArray& data);

  /*!
   * @brief Check if frame is completed
   * @return True if complete frame
   */
  bool isComplete();

  /*!
   * \brief Extract payload from frame
   * \return payload in QByteArray
   */
  QByteArray payload();

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
  QSharedDataPointer<QXbeePrivate> d_ptr;

};

}
#endif // QXBEE_H
