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

  /*! Constructor */
  QXbee();

  /**
   * \brief Overloaded Constructor
   * \param QByteArray input
   */
  QXbee(const QByteArray& ba);

  /*!
   * \brief Default
   */
  ~QXbee() = default;
  QXbee(const QXbee& other) = default;
  QXbee& operator = (const QXbee &other) = default;
  QXbee(QXbee&& other) = default;
  QXbee& operator = (QXbee&& other) = default;

  /*!
   * \brief Process data into a frame
   * \param Serial input/output from Xbee
   */
  void consume(const QByteArray& data);

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

private:
  QSharedDataPointer<QXbeePrivate> d_ptr;

};

}
#endif // QXBEE_H
