#ifndef QXBEE_H
#define QXBEE_H

#include <QScopedPointer>
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
  QScopedPointer<QXbeePrivate> d_ptr;
  Q_DISABLE_COPY(QXbee)
};

}
#endif // QXBEE_H
